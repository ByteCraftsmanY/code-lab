package LowLevelDesign;

/*
 * The Liskov Substitution Principle (LSP) is the "L" in SOLID. It was
 * introduced
 * by Barbara Liskov and it sounds more intimidating than it actually is.
 * 
 * The Rule:
 * "Subtypes must be substitutable for their base types."
 * 
 * In simpler terms: If you have a Parent class and a Child class, you should be
 * able to pass an object of the Child class to any method that expects the
 * Parent class, and the program should still work correctly without the method
 * knowing the difference.
 */

// 1. The Classic Violation: The Square-Rectangle Problem
// This is the most famous example used in interviews to explain why inheritance
// can be tricky.

// The "Logical" Setup (Bad Code)
// In geometry, a Square is a Rectangle. So, naturally, you might want to use
// inheritance.

// Parent Class
class Rectangle {
    protected int width;
    protected int height;

    public void setWidth(int width) {
        this.width = width;
    }

    public void setHeight(int height) {
        this.height = height;
    }

    public int getArea() {
        return width * height;
    }
}

// Child Class
class Square extends Rectangle {
    @Override
    public void setWidth(int width) {
        this.width = width;
        this.height = width; // Force sides to be equal
    }

    @Override
    public void setHeight(int height) {
        this.width = height;
        this.height = height; // Force sides to be equal
    }
}

/*
 * 
 * Why this violates LSP:
 * If a developer writes a function that expects a Rectangle, they assume that
 * changing the width won't change the height.
 * 
 * public void resizeRectangle(Rectangle r) {
 * r.setWidth(5);
 * r.setHeight(10);
 * 
 * // For a real Rectangle, area should be 50.
 * // But if 'r' is a Square, the area will be 100!
 * System.out.println("Expected area: 50, Actual area: " + r.getArea());
 * }
 * 
 * The Square class breaks the behavior promised by the Rectangle class.
 * Therefore, Square is not a valid substitution for Rectangle.
 */

/*
 * 2. The Solution: Break the Inheritance
 * If a subclass cannot fulfill the "contract" of the parent class, you should
 * either:
 * 
 * Use a common Interface that only contains shared behavior.
 * 
 * Use Composition instead of Inheritance.
 */

public interface Shape {
    int getArea();
}

public class Rectangle implements Shape {
    private int width, height;

    // Constructor, getters, setters
    public int getArea() {
        return width * height;
    }
}

public class Square implements Shape {
    private int side;

    // Constructor, getters, setters
    public int getArea() {
        return side * side;
    }
}
// Now, the resize logic wouldn't be part of the general Shape interface,
// avoiding the confusion entirely.

// 3. Another Common Example: The "Bird" Problem
// Consider a Bird class with a fly() method.

public class Bird {
    public void fly() {
        System.out.println("Flying...");
    }
}

public class Ostrich extends Bird {
    @Override
    public void fly() {
        throw new UnsupportedOperationException("Ostriches can't fly!");
    }
}

/*
 * // Why this is an LSP Violation:
 * // If you have a list of birds and try to make them all fly, your program
 * will crash when it hits the Ostrich.
 * 
 * 
 * public void makeBirdsFly(List<Bird> birds) {
 * for (Bird b : birds) {
 * b.fly(); // CRASH!
 * }
 * }
 * 
 * 
 * /*The Fix: Separate the behaviors. Not all Birds fly, so fly() shouldn't be
 * in the base Bird class. You could have a FlyingBird subclass or a Flyable
 * interface.
 * 
 */

/*
 * Interview Questions on LSP
 * "How do you spot an LSP violation in code?"
 * 
 * Answer: Look for if (object instanceof ChildClass), empty method overrides,
 * or methods that throw UnsupportedOperationException. These are signs that the
 * child class isn't fully compatible with the parent's contract.
 * 
 * "Does LSP mean we shouldn't use inheritance?"
 * 
 * Answer: No, it means inheritance should be based on behavior, not just shared
 * attributes. A child must be able to do everything the parent can do, exactly
 * the way the parent promised.
 */

// Example

// The Problem: The "No-Withdraw" Account
// Imagine you have a base class for accounts.

public abstract class Account {
    protected double balance;

    public void deposit(double amount) {
        balance += amount;
    }

    // Every account is expected to be able to withdraw, right?
    public abstract void withdraw(double amount);
}
// Now, you are asked to add a FixedDepositAccount. In this account type, the
// money is locked for a year. You cannot withdraw it.

// The LSP Violation (Bad Code)

public class FixedDepositAccount extends Account {
    @Override
    public void withdraw(double amount) {
        // VIOLATION: We are breaking the behavior promised by the Parent
        throw new UnsupportedOperationException("Withdrawals not allowed for Fixed Deposits!");
    }
}
/*
 * Why this is a disaster in LLD: If a developer writes a BankingService that
 * processes a list of accounts and calls .withdraw(), the whole system will
 * crash when it hits a FixedDepositAccount. The subtype is not substitutable
 * for the base type.
 * 
 * The Solution: Correcting the Hierarchy
 * To fix this, we need to realize that "Withdrawal" is not a universal property
 * of all accounts. We should split our interfaces based on behavior.
 */

// 1. Base class for common logic
public abstract class Account {
    protected double balance;

    public void deposit(double amount) {
        balance += amount;
    }

    public double getBalance() {
        return balance;
    }
}

// 2. Specific interface for the "Withdraw" capability
public interface Withdrawable {
    void withdraw(double amount);
}

// 3. Regular Account implements both
public class SavingsAccount extends Account implements Withdrawable {
    @Override
    public void withdraw(double amount) {
        balance -= amount;
        System.out.println("Withdrawn from Savings");
    }
}

// 4. Fixed Deposit ONLY extends Account
public class FixedDepositAccount extends Account {
    // It only has deposit and getBalance.
    // It doesn't even HAVE a withdraw method to call!
}
// The "Test" of LSP
// Now look at how the service changes. It prevents bugs at compile-time instead
// of crashing at run-time.

public class BankingService {
    // This method is now "Type Safe" - it only accepts accounts that CAN withdraw
    public void processWithdrawal(Withdrawable account, double amount) {
        account.withdraw(amount);
    }
}
/*
 * Key Takeaway for LSP:
 * If you find yourself writing a method in a child class that:
 * 
 * Throws an UnsupportedOperationException.
 * 
 * Has an empty implementation (does nothing).
 * 
 * Returns null or a "dummy" value because it shouldn't be called.
 * 
 * ...then you are likely violating LSP.
 */

// Example: Imagine a class ReadOnlyFile and a class WritableFile. If
// WritableFile inherits from ReadOnlyFile, but ReadOnlyFile has a save() method
// that throws an error, is that an LSP violation?

// 1. Common base for all files
public abstract class File {
    protected String path;

    public String getPath() {
        return path;
    }
}

// 2. Interface for reading
public interface Readable {
    String read();
}

// 3. Interface for writing
public interface Writable {
    void write(String data);
}

// 4. Implementations
public class ReadOnlyFile extends File implements Readable {
    public String read() {
        return "Content of read-only file";
    }
}

public class ReadWriteFile extends File implements Readable, Writable {
    public String read() {
        return "Content of read-write file";
    }

    public void write(String data) {
        System.out.println("Writing to file...");
    }
}

// Example:
/*
 * The Problem: The "Smart Media Player"
 * You are building a Media Player library. You start with a base class
 * VideoPlayer.
 */

// Parent Class
public class VideoPlayer {
    public void playVideo() {
        System.out.println("Playing video...");
    }

    public void adjustVolume(int level) {
        System.out.println("Volume set to " + level);
    }
}
// Now, your manager asks you to support Subtitle Files (like .srt files). Since
// a subtitle file is a type of media, you decide to extend VideoPlayer.

// The "Dirty" Implementation
public class SubtitleFile extends VideoPlayer {
    @Override
    public void playVideo() {
        // VIOLATION: A subtitle file is just text, it has no video stream!
        throw new UnsupportedOperationException("Cannot play video on a subtitle file!");
    }

    // It still inherits adjustVolume, which makes no sense for text.
}

/*
 * That is a great approach. Let's solidify Liskov Substitution Principle (LSP)
 * with a classic "Media Player" problem. This often comes up in interviews when
 * discussing inheritance hierarchies.
 * 
 * The Problem: The "Smart Media Player"
 * You are building a Media Player library. You start with a base class
 * VideoPlayer.
 * 
 * Java
 * 
 * // Parent Class
 * public class VideoPlayer {
 * public void playVideo() {
 * System.out.println("Playing video...");
 * }
 * 
 * public void adjustVolume(int level) {
 * System.out.println("Volume set to " + level);
 * }
 * }
 * Now, your manager asks you to support Subtitle Files (like .srt files). Since
 * a subtitle file is a type of media, you decide to extend VideoPlayer.
 * 
 * The "Dirty" Implementation
 * Java
 * 
 * public class SubtitleFile extends VideoPlayer {
 * 
 * @Override
 * public void playVideo() {
 * // VIOLATION: A subtitle file is just text, it has no video stream!
 * throw new
 * UnsupportedOperationException("Cannot play video on a subtitle file!");
 * }
 * 
 * // It still inherits adjustVolume, which makes no sense for text.
 * }
 * The Challenge
 * Imagine a VideoManager class that takes a list of VideoPlayer objects and
 * tries to play them all.
 */
public class VideoManager {
    public void playAll(List<VideoPlayer> players) {
        for (VideoPlayer p : players) {
            p.playVideo(); // This will CRASH when it hits a SubtitleFile
        }
    }
}

// The Refactored Solution (LSP Compliant)
/*
 * 1. Common Base Class (The "What")
 * We create a base class that contains only what is truly common to all media
 * files.
 */
public abstract class MediaFile {
    private String fileName;

    public MediaFile(String fileName) {
        this.fileName = fileName;
    }

    public String getFileName() {
        return fileName;
    }
}

// 2. Specific Interface (The "Behavior")
// Instead of forcing everyone to play video, we create an interface for things
// that can play video.
public interface Playable {
    void play();
}

// 3. Concrete Implementations
// Now, each class only implements what it actually supports.
// A Video can play and has volume
public class VideoFile extends MediaFile implements Playable {
    public VideoFile(String name) {
        super(name);
    }

    @Override
    public void play() {
        System.out.println("Playing video: " + getFileName());
    }
}

// A Subtitle cannot play video, so it DOES NOT implement Playable
public class SubtitleFile extends MediaFile {
    public SubtitleFile(String name) {
        super(name);
    }

    public String getCaption() {
        return "Hello World subtitles...";
    }
}

/*
 * The Resulting Service
 * The VideoManager (now more accurately a PlaybackService) will now only accept
 * objects that satisfy the Playable contract.
 */
public class PlaybackService {
    // This method is now safe. You CANNOT pass a SubtitleFile here.
    // The compiler will stop you!
    public void startPlayback(List<Playable> mediaList) {
        for (Playable m : mediaList) {
            m.play();
        }
    }
}

// example:
// The Problem: The "Free Trial" Customer
// You are designing a Loyalty Program for an E-commerce store. You have a base
// class for Customer.

public class Customer {
    protected double totalSpend = 0;

    public void addLoyaltyPoints(double amount) {
        // Standard rule: 10% of spend becomes points
        this.totalSpend += amount;
        System.out.println("Points added! Total spend: " + totalSpend);
    }
}

/*
 * Now, the business introduces a GuestCustomer (or "Free Trial" user). These
 * users are allowed to browse and buy, but they are not allowed to accumulate
 * loyalty points.
 * 
 * The "Dirty" Implementation (LSP Violation)
 */
public class GuestCustomer extends Customer {
    @Override
    public void addLoyaltyPoints(double amount) {
        // VIOLATION: Doing nothing or throwing an error
        // because Guests don't have accounts to store points.
        throw new UnsupportedOperationException("Guests cannot have loyalty points!");
    }
}

// The Scenario
// Imagine a PointsProcessor that processes a batch of orders at the end of the
// day:

public class PointsProcessor {
    public void processAll(List<Customer> customers, double orderAmount) {
        for (Customer c : customers) {
            c.addLoyaltyPoints(orderAmount); // CRASHES when it hits a Guest
        }
    }
}

// Your solution refined
abstract class Customer {
    protected double totalSpent = 0;

    public void makePurchase(double amount) {
        this.totalSpent += amount;
    }
}

interface Rewardable {
    void addLoyaltyPoints(double amount);
}

class FreeTierCustomer extends Customer {
    // Only has purchase logic
}

class RegisteredCustomer extends Customer implements Rewardable {
    private double points = 0;

    @Override
    public void addLoyaltyPoints(double amount) {
        this.points += (amount * 0.1); // 10% points logic
        System.out.println("Points added for Registered Customer!");
    }
}

// The Service that respects LSP
class LoyaltyService {
    public void processPoints(List<Rewardable> rewardableCustomers, double amount) {
        for (Rewardable r : rewardableCustomers) {
            r.addLoyaltyPoints(amount); // Guaranteed not to crash!
        }
    }
}