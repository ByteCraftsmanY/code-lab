package LowLevelDesign;

/*
 * SOLID Principles:
 * S: Single Responsibility Principle 
 * O: Open/Close Principle
 * L: Liskov Substitution Principle
 * I: Interface Segregation Principle
 * D: Dependency Inversion Principle
 */

/*
 * Single Responsibility Principle: A class should have only one reason to change
 * 
 */

// Here invoice class has multiple dependencies - if any logic changes, this class needs to be modified

class Marker {
    String name;
    int price;

    public Marker(String name, int price) {
        this.name = name;
        this.price = price;
    }
}

// Invoice has a marker
class Invoice {
    private Marker marker;
    private int quantity;

    public float calculatePrice() {
        return marker.price * (float) quantity;
    }

    public void printInvoice() {
    }

    public void saveToDB() {
    }

}

// Now we divided it into multiple classes

// Invoice class has only one responsibility: calculate price
// Easy to maintain
// Easy to understand
class Invoice2 {
    private Marker marker;
    private int quantity;

    public float calculatePrice() {
        return marker.price * (float) quantity;
    }

}

class InvoiceDao {
    private Invoice invoice;

    public InvoiceDao(Invoice invoice) {
        this.invoice = invoice;
    }

    public void save() {
        // Implementation for saving invoice
    }
}

class InvoicePrinter {
    private Invoice invoice;

    public InvoicePrinter(Invoice invoice) {
        this.invoice = invoice;
    }

    public void print() {
        // Implementation for printing invoice
    }
}

// Open Close Principle: Open for extension but close for modification

// We got the requirement to save the invoice to file
// So we need to modify the InvoiceDao class
// But we don't want to modify the InvoiceDao class
// So we need to create a new class

interface InvoiceDao2 {
    void save();
}

class DBInvoiceDao implements InvoiceDao2 {
    public void save() {
        // Implementation for saving to database
    }
}

class FileInvoiceDao implements InvoiceDao2 {
    public void save() {
        // Implementation for saving to file
    }
}

/*
 * Liskov Substitution Principle: If class B is a subtype of class A, then we
 * should be able to replace an object of class A with an object of class B
 * without breaking the application.
 * 
 * Subclass should extend the capability of parent class not narrow down it
 */
interface Bike {
    void turnOnEngine();

    void accelerate();
}

class MotorCycle implements Bike {
    private boolean isEngineOn;
    private int currentSpeed;

    public MotorCycle() {
        this.isEngineOn = false;
        this.currentSpeed = 0;
    }

    public void turnOnEngine() {
        this.isEngineOn = true;
    }

    public void accelerate() {
        this.currentSpeed += 10;
    }
}

// Here we are narrowing down the feature (turnOnEngine method)
// Current implementation will break
class Bicycle implements Bike {
    private boolean isOn;
    private int currentSpeed;

    public Bicycle() {
        this.isOn = false;
        this.currentSpeed = 0;
    }

    public void turnOnEngine() {
        throw new AssertionError("Engine not found");
    }

    public void accelerate() {
        this.currentSpeed += 1;
    }
}

/*
 * Interface Segregation Principle: Interface should be such, that client should
 * not implement unnecessary functions that they do not need
 * 
 */

interface RestaurantEmployee {
    void washDishes();

    void cookFood();

    void serveFood();
}

class Waiter implements RestaurantEmployee {
    public void washDishes() {
        // Not my responsibility
    }

    public void cookFood() {
        // Not my responsibility
    }

    public void serveFood() {
        System.out.println("Serving food");
    }
}

// Correct way

interface WaiterInterface {
    void serveFood();

    void takeOrder();
}

interface CookInterface {
    void cookFood();

    void decideMenu();
}

class Waiter2 implements WaiterInterface {
    public void serveFood() {
        // Implementation for serving food
    }

    public void takeOrder() {
        // Implementation for taking orders
    }
}

class Cook2 implements CookInterface {
    public void cookFood() {
        // Implementation for cooking food
    }

    public void decideMenu() {
        // Implementation for deciding menu
    }
}

/*
 * Dependency Inversion Principle: Class should depend on interface rather
 * than concrete classes
 * 
 */

interface Keyboard {
}

class WiredKeyboard implements Keyboard {
}

class WirelessKeyboard implements Keyboard {
}

interface Mouse {
}

class WiredMouse implements Mouse {
}

class WirelessMouse implements Mouse {
}

// Wrong approach - tightly coupled to concrete classes
class Macbook {
    private WiredKeyboard wiredKeyboard;
    private WiredMouse wiredMouse;

    public Macbook() {
        this.wiredKeyboard = new WiredKeyboard();
        this.wiredMouse = new WiredMouse();
    }
}

// Correct approach - depends on interfaces (dependency injection)
class Macbook2 {
    private Keyboard keyboard;
    private Mouse mouse;

    public Macbook2(Keyboard keyboard, Mouse mouse) {
        this.keyboard = keyboard;
        this.mouse = mouse;
    }
}

public class A1_SolidPrinciple {

}
