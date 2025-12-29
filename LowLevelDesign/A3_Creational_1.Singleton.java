package LowLevelDesign;

/*
 * Creational Design Patterns are all about how objects are created.
 * 
 * In simple terms, instead of you manually typing new MyClass() all over your
 * code,
 * these patterns provide various methods to instantiate objects.
 * This makes your system more flexible and prevents your code
 * from becoming "tightly coupled" to specific classes.
 */

/*
 * The Singleton Design Pattern is a creational pattern that ensures a class has
 * only one instance and provides a global point of access to it.
 * 
 * 1. Simple Definition
 * Imagine the Government of a country. There can be many people, but there is
 * only one official Government. Whenever a citizen needs to interact with the
 * government, they are all talking to the same single entity.
 * 
 * In coding, we use this for things that should only exist once, like a
 * Database Connection Pool, a Logging Service, or a Configuration Manager.
 */

/*
 * The Singleton Design Pattern is a creational pattern that ensures a class has
 * only one instance and provides a global point of access to it.
 * 
 * 1. Simple Definition
 * Imagine the Government of a country. There can be many people, but there is
 * only one official Government. Whenever a citizen needs to interact with the
 * government, they are all talking to the same single entity.
 * 
 * In coding, we use this for things that should only exist once, like a
 * Database Connection Pool, a Logging Service, or a Configuration Manager.
 * 
 * 2. The Problem
 * If you create a new Database Connection every time a user clicks a button,
 * your application will quickly run out of memory or crash the database. You
 * need a way to ensure that every part of your app shares the exact same
 * connection object.
 */

/*
 * 3. How to Implement (The "Rules")
 * To make a class a Singleton, you must:
 * 
 * Make the Constructor private (so no one can use new).
 * 
 * Create a Private Static variable to hold the one instance.
 * 
 * Provide a Public Static method (usually getInstance()) to return that
 * instance.
 */

class DatabaseConnection {
    // 1. Private static variable to hold the single instance
    private static volatile DatabaseConnection instance;
    private String connectionString;

    // 2. Private constructor prevents anyone from using "new DatabaseConnection()"
    private DatabaseConnection() {
        this.connectionString = "jdbc:mysql://localhost:3306/my_db";
        System.out.println("Connecting to Database...");
    }

    // 3. Public static method to give access to the instance
    public static DatabaseConnection getInstance() {
        if (instance == null) { // First check
            synchronized (DatabaseConnection.class) {
                if (instance == null) { // Second check (Double-checked locking)
                    instance = new DatabaseConnection();
                }
            }
        }
        return instance;
    }

    public void query(String sql) {
        System.out.println("Executing: " + sql);
    }
}

// 4. Java Implementation (Thread-Safe)
// This is the "Lazy Initialization" version with "Double-Checked Locking" to
// ensure it works perfectly even if multiple users try to access it at the
// exact same time.

public class Main {
    public static void main(String[] args) {
        // DatabaseConnection db = new DatabaseConnection(); // ❌ This would throw a
        // Compile Error

        DatabaseConnection db1 = DatabaseConnection.getInstance();
        DatabaseConnection db2 = DatabaseConnection.getInstance();

        // Both variables point to the exact same memory address
        System.out.println(db1 == db2); // ✅ Output: true
    }
}

// Singleton: "I need only ONE instance of this."