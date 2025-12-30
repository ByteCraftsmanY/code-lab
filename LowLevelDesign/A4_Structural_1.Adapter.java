package LowLevelDesign;

/*
 * The Adapter Design Pattern is a structural pattern that allows objects with
 * incompatible interfaces to collaborate. It acts as a wrapper that converts
 * the interface of one class into an interface that a client expects.
 */

/*
 * 1. Simple Definition
 * Imagine you are traveling from the US to Europe.
 * 
 * Your laptop has a US plug (three flat prongs).
 * 
 * The wall socket is a European outlet (two round holes).
 * 
 * They are incompatible. You don't buy a new laptop or rewire the building; you
 * use a Power Adapter.
 * 
 * In code, the Adapter sits between two different interfaces and translates the
 * calls so they can work together.
 */

/*
 * A classic and very common example of the Adapter Pattern in the software
 * world is integrating a Third-Party Payment Gateway.
 * 
 * Imagine your e-commerce app expects all payment processors to follow a
 * specific internal interface, but you want to add Stripe, which has its own
 * unique method names and logic.
 */

/*
 * 1. The Scenario
 * Your System: Expects a method called makePayment(double amount).
 * 
 * Stripe SDK: Uses a method called charge(int amountInCents).
 */

// 2. Java Implementation
// Step 1: Your Internal Interface
// This is what your existing code uses.

interface PaymentProcessor {
    void makePayment(double amount);
}
// Step 2: The Incompatible Third-Party (Adaptee)
// You cannot change this code because it belongs to Stripe.

class StripeSDK {
    public void charge(int amountInCents) {
        System.out.println("Stripe: Charging $" + (amountInCents / 100.0));
    }
}
// Step 3: The Adapter
// The Adapter implements your interface but internally calls the Stripe SDK. It
// also handles the data conversion (Dollars to Cents).

class StripeAdapter implements PaymentProcessor {
    private StripeSDK stripeSDK;

    public StripeAdapter(StripeSDK sdk) {
        this.stripeSDK = sdk;
    }

    @Override
    public void makePayment(double amount) {
        // Translate the request: Convert Dollars to Cents
        int cents = (int) (amount * 100);
        stripeSDK.charge(cents);
    }
}
// 3. Usage in your Application
// Now your Checkout service doesn't need to know Stripe exists. It just sees a
// PaymentProcessor.

public class CheckoutService {
    public static void main(String[] args) {
        // We want to use Stripe
        StripeSDK stripe = new StripeSDK();
        PaymentProcessor processor = new StripeAdapter(stripe);

        // Our app works in Dollars, but the Adapter handles the "translation"
        processor.makePayment(49.99);
    }
}

// Changes the **interface** of an object to make it compatible.
// The Adapter Pattern is a structural design pattern that allows objects with
// incompatible interfaces to work together.