package LowLevelDesign;

// VIOLATIONS EVERYWHERE!
public class StoreManager {

    // 1. Manages inventory
    public void addItemToInventory(String item) {
        System.out.println(item + " added to local array.");
    }

    // 2. Processes Payments (Currently only supports Cash)
    public void processPayment(double amount, String type) {
        if (type.equalsIgnoreCase("cash")) {
            System.out.println("Processing cash: " + amount);
        } else if (type.equalsIgnoreCase("credit")) {
            // If we want to add Credit, we have to modify this class (OCP Violation)
            System.out.println("Processing credit: " + amount);
        }
    }

    // 3. Generates Reports
    public void printDailyReport() {
        System.out.println("Printing report to console...");
    }

    // 4. Persistence (Hard-coded to MySQL)
    public void saveToDatabase() {
        System.out.println("Connecting to MySQL... Saving...");
    }
}

// Solution

// --- 1. DATA MODEL ---
class Transaction {
    private String id;
    private double amount;
    // Getters and setters...
}

// --- 2. SINGLE RESPONSIBILITY: INVENTORY ---
class InventoryManager {
    private final List<String> inventories = new ArrayList<>();

    public void addInventory(String item) {
        this.inventories.add(item);
        System.out.println("Inventory updated: " + item);
    }
}

// --- 3. OPEN/CLOSED & LSP: PAYMENTS ---
interface PaymentMethod {
    void pay(double amount);
}

class CreditCardPayment implements PaymentMethod {
    @Override
    public void pay(double amount) {
        System.out.println("Paid $" + amount + " via Credit Card.");
    }
}

class CashPayment implements PaymentMethod {
    @Override
    public void pay(double amount) {
        System.out.println("Paid $" + amount + " via Cash.");
    }
}

// Strategy Pattern wrapper for Payment
class PaymentProcesser {
    public void process(PaymentMethod method, double amount) {
        method.pay(amount);
    }
}

// --- 4. DEPENDENCY INVERSION: PERSISTENCE ---
interface DataStorage {
    void save(String data);
}

class MySQLDataStorage implements DataStorage {
    @Override
    public void save(String data) {
        System.out.println("Saved to MySQL: " + data);
    }
}

// --- 5. INTERFACE SEGREGATION: REPORTING ---
interface ReportPrinter {
    void print(String content);
}

class ConsoleReportPrinter implements ReportPrinter {
    @Override
    public void print(String content) {
        System.out.println("DISPLAYING REPORT: " + content);
    }
}

// --- 6. THE ORCHESTRATOR (CHECKOUT SERVICE) ---
class CheckoutService {
    private final DataStorage storage;
    private final PaymentProcesser processor;

    // DIP: We depend on abstractions (DataStorage), not concretions (MySQL)
    public CheckoutService(DataStorage storage, PaymentProcesser processor) {
        this.storage = storage;
        this.processor = processor;
    }

    public void checkout(PaymentMethod method, double amount) {
        processor.process(method, amount);
        storage.save("Transaction for amount: " + amount);
    }
}

// --- 7. FINAL COMPOSITION ---
class StoreManager {
    private final InventoryManager inventory;
    private final CheckoutService checkoutService;

    public StoreManager(InventoryManager inventory, CheckoutService checkoutService) {
        this.inventory = inventory;
        this.checkoutService = checkoutService;
    }

    public void performSale(String item, double price, PaymentMethod method) {
        inventory.addInventory(item);
        checkoutService.checkout(method, price);
    }
}

// --- EXECUTION ---
public class Main {
    public static void main(String[] args) {
        // Wiring everything up (Dependency Injection)
        DataStorage db = new MySQLDataStorage();
        PaymentProcesser processor = new PaymentProcesser();
        CheckoutService checkout = new CheckoutService(db, processor);
        InventoryManager inventory = new InventoryManager();

        StoreManager myStore = new StoreManager(inventory, checkout);

        // Making a sale
        myStore.performSale("MacBook Pro", 2499.99, new CreditCardPayment());
    }
}