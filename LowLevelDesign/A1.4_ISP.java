package LowLevelDesign;
/*
    The Interface Segregation Principle (ISP) is the "I" in SOLID. 
    It focuses on how we design our interfaces to be lean and meaningful.

    The Core Concept
    "No client should be forced to depend on methods it does not use."

    In simpler terms: It is better to have many small, specific interfaces than one large, 
    general-purpose interface. When an interface is too "fat," it forces implementing classes 
    to write "dummy" code for methods they don't actually need. 
*/

/*
 * The Problem: The "Fat" Interface
 * Imagine you are designing software for a Smart Office. You create one big
 * interface for all devices.
 */
// BAD: This is a "Fat" interface
interface SmartDevice {
    void print();

    void scan();

    void fax();
}

/*
 * The Violation
 * Now, you try to implement a simple BasicPrinter.
 */

class BasicPrinter implements SmartDevice {
    @Override
    public void print() {
        System.out.println("Printing...");
    }

    @Override
    public void scan() {
        // ERROR: I can't scan!
        // I'm forced to provide a dummy implementation or throw an error.
    }

    @Override
    public void fax() {
        // ERROR: I can't fax!
    }
}

/*
 * The Fix
 * Instead of one "Fat" interface, we split them into Small, Focused interfaces.
 */
interface Printer {
    void print();
}

interface Scanner {
    void scan();
}

interface Fax {
    void fax();
}

// Now the BasicPrinter only implements what it needs
class BasicPrinter implements Printer {
    public void print() {
        System.out.println("Printing...");
    }
}

// A high-end machine can implement all of them
class AllInOneMachine implements Printer, Scanner, Fax {
    public void print() {
        /* ... */ }

    public void scan() {
        /* ... */ }

    public void fax() {
        /* ... */ }
}

// Example
// The "Worker" Interface
// Imagine an interface called Worker:

interface Worker {
    void work();

    void eat();
}

// Fix
interface Workable {
    void work();
}

interface Eatable {
    void eat();
}

class HumanWorker implements Workable, Eatable {
    public void work() {
        System.out.println("Working...");
    }

    public void eat() {
        System.out.println("Eating lunch...");
    }
}

class RobotWorker implements Workable {
    public void work() {
        System.out.println("Processing data...");
    }
    // Robot is no longer forced to "eat"!
}