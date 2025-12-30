package LowLevelDesign;
/*
    The Abstract Factory Pattern is often called a "Factory of Factories." While the normal Factory pattern creates one type of object (e.g., a Notification), the Abstract Factory creates families of related objects without specifying their concrete classes.
*/

/*
    The Abstract Factory Pattern is a creational pattern that provides an interface for creating families of related or dependent objects without specifying their concrete classes.
*/

/*
    1. Simple Definition
        Imagine you are building a Furniture Store.

        You sell Chairs and Tables.

        Each type of furniture can be made of different materials: Wood, Plastic, Metal.

        Without an Abstract Factory, you'd have to create WoodChair, PlasticChair, WoodTable, PlasticTable, etc.

        With an Abstract Factory: You can create a "WoodFactory" and a "PlasticFactory". Each factory can create both Chairs and Tables.
*/

/*
    2. The Problem: Tightly Coupled Object Creation
        If you create objects directly in your business logic, you are "hard-coding" your dependencies.
 */

// ❌ BAD: What if we want to add "PlasticChair" tomorrow? 
// We have to change this class.
class BadFurnitureStore {
    public void sellFurniture() {
        // Direct instantiation - hard to switch to Plastic or other families
        WoodChair chair = new WoodChair();
        WoodTable table = new WoodTable();

        chair.sitOn();
        table.putOn();
    }
}
// 3. Case Study: Furniture Store
// abstract factory : creation of family of related object
// factory : creation of object

// Abstract Products
interface Chair {
    void sitOn();
}

interface Table {
    void putOn();
}

// Concrete Products for Wood Family
class WoodChair implements Chair {
    @Override
    public void sitOn() {
        System.out.println("Sitting on a Wood Chair");
    }
}

class WoodTable implements Table {
    @Override
    public void putOn() {
        System.out.println("Putting items on a Wood Table");
    }
}

// Concrete Products for Plastic Family
class PlasticChair implements Chair {
    @Override
    public void sitOn() {
        System.out.println("Sitting on a Plastic Chair");
    }
}

class PlasticTable implements Table {
    @Override
    public void putOn() {
        System.out.println("Putting items on a Plastic Table");
    }
}

// Abstract Factory
interface FurnitureFactory {
    Chair createChair();

    Table createTable();
}

// Concrete Factory 1: Wood Factory
class WoodFactory implements FurnitureFactory {
    @Override
    public Chair createChair() {
        return new WoodChair();
    }

    @Override
    public Table createTable() {
        return new WoodTable();
    }
}

// Concrete Factory 2: Plastic Factory
class PlasticFactory implements FurnitureFactory {
    @Override
    public Chair createChair() {
        return new PlasticChair();
    }

    @Override
    public Table createTable() {
        return new PlasticTable();
    }
}

// Client Code
class FurnitureStore {
    private Chair chair;
    private Table table;

    public FurnitureStore(FurnitureFactory factory) {
        this.chair = factory.createChair();
        this.table = factory.createTable();
    }

    public void useFurniture() {
        chair.sitOn();
        table.putOn();
    }
}

// ❌ BAD: Tightly Coupled GUI
// If we want to support Mac, we have to change this code!
class BadApplication {
    public void paint() {
        WindowsButton button = new WindowsButton();
        WindowsCheckbox checkbox = new WindowsCheckbox();

        button.paint();
        checkbox.paint();
    }
}

// 4. Case Study: Cross-Platform GUI
interface Button {
    void paint();
}

interface Checkbox {
    void paint();
}

// Concrete Products for Windows
class WindowsButton implements Button {
    public void paint() {
        System.out.println("Rendering a Windows Button");
    }
}

class WindowsCheckbox implements Checkbox {
    public void paint() {
        System.out.println("Rendering a Windows Checkbox");
    }
}

// Concrete Products for Mac
class MacButton implements Button {
    public void paint() {
        System.out.println("Rendering a Mac Button");
    }
}

class MacCheckbox implements Checkbox {
    public void paint() {
        System.out.println("Rendering a Mac Checkbox");
    }
}

// Abstract Factory
interface GUIFactory {
    Button createButton();

    Checkbox createCheckbox();
}

// Concrete Factory: Windows
class WindowsFactory implements GUIFactory {
    public Button createButton() {
        return new WindowsButton();
    }

    public Checkbox createCheckbox() {
        return new WindowsCheckbox();
    }
}

// Concrete Factory: Mac
class MacFactory implements GUIFactory {
    public Button createButton() {
        return new MacButton();
    }

    public Checkbox createCheckbox() {
        return new MacCheckbox();
    }
}

// Client
class Application {
    private Button button;
    private Checkbox checkbox;

    public Application(GUIFactory factory) {
        button = factory.createButton();
        checkbox = factory.createCheckbox();
    }

    public void paint() {
        button.paint();
        checkbox.paint();
    }
}

public class Main {
    public static void main(String[] args) {
        System.out.println("=== Wood Furniture Family ===");
        FurnitureFactory woodFactory = new WoodFactory();
        FurnitureStore woodStore = new FurnitureStore(woodFactory);
        woodStore.useFurniture();

        System.out.println("\n=== Plastic Furniture Family ===");
        FurnitureFactory plasticFactory = new PlasticFactory();
        FurnitureStore plasticStore = new FurnitureStore(plasticFactory);
        plasticStore.useFurniture();

        System.out.println("\n=== Windows GUI Family ===");
        GUIFactory winFactory = new WindowsFactory();
        Application winApp = new Application(winFactory);
        winApp.paint();

        System.out.println("\n=== Mac GUI Family ===");
        GUIFactory macFactory = new MacFactory();
        Application macApp = new Application(macFactory);
        macApp.paint();
    }
}
