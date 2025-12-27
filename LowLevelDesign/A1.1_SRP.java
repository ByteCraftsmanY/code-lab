package LowLevelDesign;

/*
 * The Single Responsibility Principle (SRP) is the first letter in SOLID. It
 * states:
 * 
 * "A class should have one, and only one, reason to change."
 * 
 * In other words, a class should do one thing and do it well. If a class has
 * multiple responsibilities, those responsibilities become coupled. A change to
 * one responsibility might unexpectedly break the code handling the other.
 */

/*
 * 1. The Violation (Bad Code)
 * Imagine an Employee class in a payroll system. It looks convenient at first,
 * but it's doing too much.
 */

// BAD: This class has three different reasons to change.
public class Employee {
    private String id;
    private String name;
    private double salary;

    // Reason 1: Changes in how salary is calculated (Business Logic)
    public double calculatePay() {
        // ... complex logic for taxes and bonuses
        return salary;
    }

    // Reason 2: Changes in the report format (Presentation Logic)
    public void printPerformanceReport() {
        System.out.println("Employee Name: " + name + " is doing great!");
    }

    // Reason 3: Changes in the database schema (Persistence Logic)
    public void saveToDatabase() {
        System.out.println("Saving employee " + id + " to MySQL...");
    }
}

/*
 * 2. The Solution (Good Code)
 * We split the "God Class" into three specialized classes. Each one now has
 * exactly one reason to change.
 */

/*
 * Step 1: The Core Entity
 * This class only holds data and very basic logic related to the employee
 * itself.
 */

public class Employee {
    private String id;
    private String name;
    private double salary;
    // Getters and Setters...
}

// Step 2: The Business Logic
public class PayrollService {
    public double calculatePay(Employee employee) {
        // Only handles tax, bonuses, and salary logic
        return employee.getSalary() * 0.8;
    }
}

// Step 3: The Persistence Logic
public class EmployeeRepository {
    public void save(Employee employee) {
        // Only handles database operations
        System.out.println("Saving to Database...");
    }
}

// Step 4: The Presentation Logic
public class EmployeeReportFormatter {
    public void formatReport(Employee employee) {
        // Only handles how information is displayed
        System.out.println("Formatting report for: " + employee.getName());
    }
}

// Examples

/*
 * 1. The Violation (Bad Code)
 * Imagine we are building an E-commerce system. Here is our initial
 * OrderManager class.
 */
public class OrderManager {
    private List<String> items = new ArrayList<>();

    // 1. Manage the items in the order
    public void addItem(String item) {
        items.add(item);
    }

    // 2. Calculate the total price including tax
    public double calculateTotal(double price) {
        double tax = price * 0.15;
        return price + tax;
    }

    // 3. Save the order to the database
    public void saveOrder() {
        System.out.println("Connecting to Database...");
        System.out.println("Executing: INSERT INTO orders...");
    }

    // 4. Send a confirmation email to the customer
    public void sendConfirmationEmail(String email) {
        System.out.println("Connecting to SMTP server...");
        System.out.println("Sending email to: " + email);
    }
}

// Solution

// 1. Core Entity - This class now has only one responsibility: maintaining the
// state of an order.
public class Order {
    private List<String> items = new ArrayList<>();

    public void addItem(String item) {
        items.add(item);
    }

    public List<String> getItems() {
        return items;
    }
}

// 2. The Business Logic (PriceCalculator) - If the tax rate changes from 15% to
// 10%, only this class changes.
public class PriceCalculator {
    public double calculateTotal(double price) {
        double tax = price * 0.15;
        return price + tax;
    }
}

// 3. The Persistence Layer (OrderRepository)
// If you switch from MySQL to MongoDB, only this class changes.
public class OrderRepository {
    public void save(Order order) {
        System.out.println("Saving order to Database...");
    }
}

// 4. The Communication Layer (NotificationService)
// If you decide to send WhatsApp messages instead of Emails, only this class
// changes.
public class NotificationService {
    public void sendConfirmationEmail(String email) {
        System.out.println("Sending email to: " + email);
    }
}

// Example

// bad code

class Invoice {
    private final double amount;

    public Invoice(double amount) {
        this.amount = amount;
    }

    public void generateInvoice() {
        System.out.printf("generating invoice for amount %f", this.amount);
    }

    public void saveInvoice() {
    }
}

// Good Code
// 1. THE ENTITY (Pure Data/State)
// Responsibility: Only manage invoice data.
class Invoice {
    private final double amount;

    public Invoice(double amount) {
        this.amount = amount;
    }

    public double getAmount() {
        return amount;
    }
}

// 2. THE PRESENTATION (SRP: Responsibility is Printing/Formatting)
class InvoicePrinter {
    public void print(Invoice invoice) {
        System.out.printf("Generating invoice for amount: %.2f%n", invoice.getAmount());
    }
}

// 3. THE PERSISTENCE (OCP + SRP: Responsibility is Saving)
interface InvoiceRepository {
    void save(Invoice invoice);
}

class DbInvoiceRepository implements InvoiceRepository {
    public void save(Invoice invoice) {
        System.out.println("Saving invoice to Database");
    }
}

// 4. THE EXECUTION
class TestInvoice {
    public void run() {
        Invoice invoice = new Invoice(12.32);

        // Print it
        InvoicePrinter printer = new InvoicePrinter();
        printer.print(invoice);

        // Save it (Using OCP)
        InvoiceRepository repo = new DbInvoiceRepository();
        repo.save(invoice);
    }
}