package LowLevelDesign;

/*
    The Open/Closed Principle (OCP) is one of the five SOLID principles 
    of object-oriented design. It states:

    "Software entities (classes, modules, functions, etc.) 
    should be open for extension, but closed for modification."

    In plain English: You should be able to add new features to your code 
    without touching or changing the code you’ve already written and tested.
*/

/*
 * 1. The Violation (Before OCP)
 * In this example, the DiscountService class has to be modified every time a new type of customer is added. 
 * This is "Closed for Extension" and "Open for Modification"—the exact opposite of what we want.
 */
public class DiscountService {
    public double calculateDiscount(String customerType, double amount) {
        if (customerType.equalsIgnoreCase("STUDENT")) {
            return amount * 0.20; // 20% discount
        } else if (customerType.equalsIgnoreCase("VIP")) {
            return amount * 0.50; // 50% discount
        } else {
            return 0.0;
        }
    }
}

/*
 * 2. The Solution (After OCP)
 * To fix this, we create a DiscountStrategy interface. Now, the service doesn't
 * need to know the specifics of how a discount is calculated; it just knows
 * that a "Strategy" exists.
 * 
 */

// Step 1: Create the Interface
public interface DiscountStrategy {
    double apply(double amount);
}

// Step 2: Implement Concrete Classes
public class StudentDiscount implements DiscountStrategy {
    @Override
    public double apply(double amount) {
        return amount * 0.20;
    }
}

public class VipDiscount implements DiscountStrategy {
    @Override
    public double apply(double amount) {
        return amount * 0.50;
    }
}

// Step 3: The "Closed" Service
// The DiscountCalculator is now closed for modification. Even if you add 100
// new discount types, this code never changes.
public class DiscountCalculator {
    public double calculate(DiscountStrategy strategy, double amount) {
        // This code is now generic and robust
        return strategy.apply(amount);
    }
}

// Step 4: Extension (Adding "Senior Citizen" discount)
// Notice that we add this new feature without touching any of the existing
// logic:
public class SeniorDiscount implements DiscountStrategy {
    @Override
    public double apply(double amount) {
        return amount * 0.30;
    }
}

// Examples

// BAD: This class violates OCP and the Single Responsibility Principle.
public class NotificationSender {
    public void send(String type, String message, String userContact) {
        if (type.equalsIgnoreCase("EMAIL")) {
            // Logic for Email: Setting up SMTP, headers, etc.
            System.out.println("Connecting to SMTP server...");
            System.out.println("Sending Email: " + message);
        } else if (type.equalsIgnoreCase("SMS")) {
            // Logic for SMS: Integrating with Twilio or another gateway
            System.out.println("Connecting to SMS Gateway...");
            System.out.println("Sending SMS: " + message);
        } else if (type.equalsIgnoreCase("PUSH")) {
            // Logic for Push Notifications: Firebase/APNS
            System.out.println("Connecting to Firebase...");
            System.out.println("Sending Push: " + message);
        }
        // To add WhatsApp, we MUST modify this method.
        // If we break the Email logic while adding WhatsApp, the whole system fails.
    }
}

/*
 * 2. The Solution (After OCP)
 * 
 */
// 1. The Abstraction
public interface NotificationProvider {
    void send(String message, String contact);
}

// 2. The Implementation (Clean & Isolated)
public class EmailProvider implements NotificationProvider {
    @Override
    public void send(String message, String contact) {
        System.out.println("SMTP: Sending Email to " + contact);
    }
}

// 3. The Scalable Service
public class SmsProvider implements NotificationProvider {
    @Override
    public void send(String message, String contact) {
        System.out.println("Gateway: Sending SMS to " + contact);
    }
}

public class Main {
    public static void main(String[] args) {
        // If the user wants Email:
        NotificationService emailService = new NotificationService(new EmailProvider());
        emailService.execute("Hello!", "user@email.com");

        // If the user wants SMS:
        NotificationService smsService = new NotificationService(new SmsProvider());
        smsService.execute("Hello!", "555-0199");
    }
}

/*
 * One Small Interview "Pro-Tip"
 * In a real LLD interview, the interviewer might ask:
 * 
 * "What if I want to send a notification to BOTH Email and SMS at the same time?"
 * 
 * With your "Good Code," you can solve this using the Composite Pattern without
 * changing your NotificationService2 at all:
 */

class MultiNotificationProvider implements NotificationProvider {
    private List<NotificationProvider> providers;

    public MultiNotificationProvider(List<NotificationProvider> providers) {
        this.providers = providers;
    }

    @Override
    public void sendNotification(String msg) {
        for (NotificationProvider p : providers) {
            p.sendNotification(msg);
        }
    }
}