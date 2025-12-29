package LowLevelDesign;

import java.util.ArrayList;
import java.util.List;

/*
    The Mediator Design Pattern is a behavioral pattern that reduces chaotic dependencies between objects. 
    It restricts direct communications between objects and forces them to collaborate only via a mediator object.
*/

/*
1. Simple Definition
    Imagine an Air Traffic Control (ATC) Tower.
        - If 50 pilots tried to talk to each other directly to decide who lands first, it would be a disaster (Tightly Coupled).
        - Instead, all pilots talk only to the Tower.
        - The Tower (the Mediator) decides the order and tells each pilot what to do. The pilots don't even need to know the other planes exist.
*/

class User1 {
    private String name;
    // BAD: Every user must know about every other user
    private List<User1> friends = new ArrayList<>();

    public User1(String name) {
        this.name = name;
    }

    public void addFriend(User1 friend) {
        this.friends.add(friend);
    }

    public void send(String msg) {
        System.out.println(this.name + " is sending: " + msg);
        // BAD: Logic for "who gets the message" is inside the User class
        for (User1 friend : friends) {
            friend.receive(msg);
        }
    }

    public void receive(String msg) {
        System.out.println(this.name + " received: " + msg);
    }
}

class BadChatExample {
    public static void main(String[] args) {
        User1 alice = new User1("Alice");
        User1 bob = new User1("Bob");
        User1 charlie = new User1("Charlie");

        // BAD: Manual "wiring" of every single relationship
        alice.addFriend(bob);
        alice.addFriend(charlie);

        bob.addFriend(alice);
        bob.addFriend(charlie);

        charlie.addFriend(alice);
        charlie.addFriend(bob);

        alice.send("Hello everyone!");
    }
}

/*
 * Why this code is "Bad" for LLD:
 * - Many-to-Many connections: If you have 100 users, each user object is
 * carrying
 * a list of 99 other objects. This consumes a lot of memory.
 * 
 * - Hard to Scale: If you want to add a "Group Admin" who can block messages,
 * you
 * have to go into the User class and add that logic. In the Mediator pattern,
 * you only change the ChatRoom class.
 * 
 * - Complexity: The User class is doing two things: representing a person AND
 * managing network/routing logic. This violates the Single Responsibility
 * Principle (SRP).
 */

/*
 * In a chat room:
 * 
 * Users don't send messages directly to each other's phones.
 * 
 * Users send a message to the Chat Room (Mediator).
 * 
 * The Chat Room decides who should receive the message (everyone, or a specific
 * person).
 */

// 1. The Mediator Interface
// This defines how users talk to the room.

interface ChatMediator {
    void sendMessage(String msg, User user);

    void addUser(User user);
}

// 2. The Component (User)
// The user only knows about the Mediator, not about other users.

abstract class User {
    protected ChatMediator mediator;
    protected String name;

    public User(ChatMediator med, String name) {
        this.mediator = med;
        this.name = name;
    }

    public abstract void send(String msg);

    public abstract void receive(String msg);
}

// 3. The Concrete Mediator
// This class holds the list of users and handles the distribution of messages.

class ChatRoom implements ChatMediator {
    private List<User> users;

    public ChatRoom() {
        this.users = new ArrayList<>();
    }

    @Override
    public void addUser(User user) {
        this.users.add(user);
    }

    @Override
    public void sendMessage(String msg, User sender) {
        for (User u : users) {
            // Message should not be received by the sender themselves
            if (u != sender) {
                u.receive(msg);
            }
        }
    }
}

// 4. Concrete Components
// Specific types of users (e.g., Free users, Premium users).

class ChatUser extends User {
    public ChatUser(ChatMediator med, String name) {
        super(med, name);
    }

    @Override
    public void send(String msg) {
        System.out.println(this.name + " is sending: " + msg);
        mediator.sendMessage(msg, this);
    }

    @Override
    public void receive(String msg) {
        System.out.println(this.name + " received: " + msg);
    }
}

// 5. Putting it all together

public class MediatorDemo {
    public static void main(String[] args) {
        ChatMediator WhatsApp = new ChatRoom();

        User user1 = new ChatUser(WhatsApp, "Alice");
        User user2 = new ChatUser(WhatsApp, "Bob");
        User user3 = new ChatUser(WhatsApp, "Charlie");

        WhatsApp.addUser(user1);
        WhatsApp.addUser(user2);
        WhatsApp.addUser(user3);

        user1.send("Hey everyone! How is the LLD study going?");
    }
}

/*
 * Why this is a "Mediator" and not just an "Observer"?
 * 
 * Observer: Usually a one-way broadcast (One Subject $\rightarrow$ many
 * Observers). The Observers don't usually talk back to change the state of
 * other Observers.
 * 
 * Mediator: A multi-way communication hub. Any user can initiate a message, and
 * the Mediator handles the complex "Who gets what" logic.
 */

/*
 * If you are asked to implement a Mediator in an interview:
 *  - Create a Mediator Interface (defines the communication).
 *  - Create an Abstract Component (holds a reference to the mediator).
 *  - Create a Concrete Mediator (manages the logic and list of components).
 *  - Ensure components never call each other directly; they only call
 *    mediator.notify() or mediator.send().
 */