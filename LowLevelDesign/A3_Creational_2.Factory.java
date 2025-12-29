package LowLevelDesign;

/*
    The Factory Method Pattern is the most widely used creational pattern. 
    It provides an interface for creating objects in a superclass but 
    allows subclasses to alter the type of objects that will be created. 
*/

/*
    1. Simple Definition
        Imagine a Logistics Company.

        At first, they only have Trucks, so the code handles Truck objects.

        Later, they add Ships.

        Without a Factory, you'd have to change your entire codebase with if (type == "Ship") everywhere.

        With a Factory: You just ask the Factory for a "Transport" object. You don't care if it's a Truck or a Ship; you just care that it can deliver().
*/

/*
    2. The Problem: Tightly Coupled Creation
        If you use the new keyword directly in your business logic, you are "hard-coding" your dependency.
 */

// ❌ BAD: What if we want to add "PaypalPayment" tomorrow? 
// We have to change this class.
class Checkout {
    public void finish() {
        CreditCardPayment p = new CreditCardPayment();
        p.pay();
    }
}

// 3. Case Study: Notification System
// Suppose you want to send notifications via Email, SMS, or Push.

// Step 1: The Product Interface
interface Notification {
    void notifyUser();
}

// Step 2: Concrete Products
class EmailNotification implements Notification {
    public void notifyUser() {
        System.out.println("Sending an Email...");
    }
}

class SMSNotification implements Notification {
    public void notifyUser() {
        System.out.println("Sending an SMS...");
    }
}

// Step 3: The Factory This is the "Decision Maker."
class NotificationFactory {
    public Notification createNotification(String channel) {
        if (channel == null || channel.isEmpty())
            return null;

        switch (channel) {
            case "SMS":
                return new SMSNotification();
            case "EMAIL":
                return new EmailNotification();
            default:
                throw new IllegalArgumentException("Unknown channel");
        }
    }
}

// Step 4: Using the Factory
public class Main {
    public static void main(String[] args) {
        NotificationFactory factory = new NotificationFactory();

        // The client doesn't know about EmailNotification or SMSNotification classes
        Notification note = factory.createNotification("SMS");
        note.notifyUser();
    }
}

// Factory: "I need an object, but I don't want to know the exact class name."

// A factory class that decides which concrete class to instantiate.   