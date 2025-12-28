package LowLevelDesign;

/*
 * The Strategy Pattern is a behavioral design pattern that turns a set of
 * behaviors into objects and makes them interchangeable inside a primary
 * object. It is the gold standard for implementing the Open/Closed Principle,
 * as it allows you to switch algorithms at runtime without modifying the class
 * that uses them.
 */

// Bad Code
// Violating open/closed principle
class PaymentService {
    public void pay(double amount, String type) {
        if (type.equals("CreditCard")) {
            // Logic for Credit Card
        } else if (type.equals("PayPal")) {
            // Logic for PayPal
        }
        // This class grows forever and breaks OCP!
    }
}

// Good Code
// The "Strategy" Way (Refactored)

// Step 1: The Strategy Interface This defines the "contract" for all payment
// methods.
interface PaymentStrategy {
    void processPayment(double amount);
}

// Step 2: Concrete Strategies Each payment method is its own small, focused
// class.
class CreditCardPayment implements PaymentStrategy {
    @Override
    public void processPayment(double amount) {
        System.out.println("Paying " + amount + " using Credit Card.");
    }
}

class PayPalPayment implements PaymentStrategy {
    @Override
    public void processPayment(double amount) {
        System.out.println("Paying " + amount + " using PayPal.");
    }
}

// Step 3: The Context (The Payment Service) The service doesn't care how the
// payment is made; it just calls the strategy it was given.
class PaymentService {
    private PaymentStrategy strategy;

    // We "inject" the strategy we want to use
    public void setStrategy(PaymentStrategy strategy) {
        this.strategy = strategy;
    }

    public void executePayment(double amount) {
        strategy.processPayment(amount);
    }
}

/*
 * Why is this better?
 * Open/Closed Principle: To add a new payment method (like Apple Pay), you just
 * create a new class. You never touch the PaymentService code.
 * 
 * Clean Code: No more giant if-else or switch statements.
 * 
 * Swap at Runtime: You can change the payment method while the app is running
 * based on what the user clicks.
 */