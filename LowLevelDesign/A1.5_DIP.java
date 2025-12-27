package LowLevelDesign;

/*
 * The Core Concept
 * 1. High-level modules should not depend on low-level modules. Both should
 * depend on abstractions. 2. Abstractions should not depend on details. Details
 * should depend on abstractions.
 * 
 * In simple terms: "Depend on interfaces, not concrete classes."
 */

/*
 * The Violation (The "Hard-Wired" Approach)
 * Imagine you are building a MacBook. 
 * The MacBook has a Keyboard. If you hard-code a specific keyboard into the MacBook, you can never change it.
 */

// Low-level module
class WiredKeyboard {
    public void type() {
        System.out.println("Typing on wired keyboard...");
    }
}

// High-level module
class MacBook {
    private final WiredKeyboard keyboard; // VIOLATION: Dependent on a concrete class

    public MacBook() {
        this.keyboard = new WiredKeyboard(); // VIOLATION: Hard-coded instantiation
    }
}

/*
 * Why is this bad?
 * 
 * Rigid: If you want to use a BluetoothKeyboard, you have to modify the MacBook
 * class.
 * 
 * Untestable: You cannot easily "mock" the keyboard to test the MacBook in
 * isolation.
 */

/*
 * The Solution (Applying DIP)
 * We introduce an abstraction (Interface) between the MacBook and the Keyboard.
 */

// 1. The Abstraction
interface Keyboard {
    void type();
}

// 2. Concrete Details (Low-level)
class WiredKeyboard implements Keyboard {
    public void type() {
        System.out.println("Wired typing...");
    }
}

class BluetoothKeyboard implements Keyboard {
    public void type() {
        System.out.println("Bluetooth typing...");
    }
}

// 3. High-level Module (DIP compliant)
class MacBook {
    private final Keyboard keyboard;

    // Dependency Injection: We pass the abstraction in!
    public MacBook(Keyboard keyboard) {
        this.keyboard = keyboard;
    }

    public void use() {
        keyboard.type();
    }
}

// example:
/*
 * The Problem: Hard-coded Connections
 * Imagine you have a PasswordReminder class. To send a reminder, it needs to
 * fetch a user from a database.
 */
// Low-level module
class MySQLDatabase {
    public String getEmail(String user) {
        return "user@example.com";
    }
}

// High-level module
class PasswordReminder {
    // VIOLATION: Hard-coded to a specific DB
    private MySQLDatabase db = new MySQLDatabase();

    public void remind(String user) {
        String email = db.getEmail(user);
        System.out.println("Sending reminder to " + email);
    }
}

/*
 * Why this is a "Solid" fail:
 * Rigidity: If your company switches to MongoDB, you have to rewrite the
 * PasswordReminder class.
 * 
 * Testing: You can't test PasswordReminder without having a real MySQL database
 * running.
 */

/*
 * The Refactored Solution (DIP)
 * To fix this, we make both the high-level and low-level modules depend on an
 * interface.
 */

// 1. The Abstraction
interface Database {
    String getEmail(String user);
}

// 2. Concrete implementations (Low-level)
class MySQLDatabase implements Database {
    public String getEmail(String user) {
        return "mysql_user@mail.com";
    }
}

class MongoDatabase implements Database {
    public String getEmail(String user) {
        return "mongo_user@mail.com";
    }
}

// 3. High-level module
class PasswordReminder {
    private final Database db;

    // Dependency Injection: Pass the interface in!
    public PasswordReminder(Database db) {
        this.db = db;
    }

    public void remind(String user) {
        String email = db.getEmail(user);
        System.out.println("Sending mail to: " + email);
    }
}