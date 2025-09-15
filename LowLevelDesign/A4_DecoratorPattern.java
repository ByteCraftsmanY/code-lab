package LowLevelDesign;

// https://youtu.be/w6a9MXUwcfY?si=6xFtaDGU2cLk0O0H

/*
 * DECORATOR DESIGN PATTERN
 * =======================
 * 
 * Definition: The Decorator pattern allows behavior to be added to an individual object,
 * either statically or dynamically, without affecting the behavior of other objects
 * from the same class. It provides a flexible alternative to subclassing for extending functionality.
 * 
 * Key Concepts:
 * - Wraps an object to provide new behavior
 * - Maintains the same interface as the original object
 * - Allows multiple decorators to be stacked
 * - Follows the Open/Closed Principle (open for extension, closed for modification)
 * 
 * When to Use:
 * - When you need to add responsibilities to objects dynamically and transparently
 * - When extension by subclassing is impractical (too many combinations)
 * - When you want to add features without modifying existing code
 * - When you need to add/remove features at runtime
 * 
 * Benefits:
 * - More flexible than static inheritance
 * - Responsibilities can be added/removed at runtime
 * - Mix and match features easily
 * - Avoids feature-laden classes high up in the hierarchy
 * - Follows Single Responsibility Principle (each decorator has one responsibility)
 * 
 * Real-world Examples:
 * - Java I/O streams (BufferedReader, FileReader, etc.)
 * - GUI components (Scrollable, Borderable, etc.)
 * - Coffee shop orders (base coffee + milk + sugar + whipped cream)
 * - Text formatting (bold, italic, underline)
 */

// =============================================================================
// DECORATOR PATTERN EXAMPLE: Pizza Ordering System
// =============================================================================

// Component Interface: Defines the interface for objects that can have responsibilities
// added to them dynamically
abstract class BasePizza {
    public abstract int cost();

    public abstract String getDescription();
}

// Concrete Component 1: Basic veg pizza (no toppings)
class VegPizza extends BasePizza {
    @Override
    public int cost() {
        return 100;
    }

    @Override
    public String getDescription() {
        return "Veg Pizza";
    }
}

// Concrete Component 2: Basic non-veg pizza (no toppings)
class NonVegPizza extends BasePizza {
    @Override
    public int cost() {
        return 200;
    }

    @Override
    public String getDescription() {
        return "Non-Veg Pizza";
    }
}

// Decorator Abstract Class: Maintains a reference to a Component object and
// defines an interface that conforms to Component's interface
abstract class ToppingDecorator extends BasePizza {
    protected BasePizza basePizza;

    public ToppingDecorator(BasePizza basePizza) {
        this.basePizza = basePizza;
    }

    @Override
    public abstract int cost();

    @Override
    public abstract String getDescription();
}

// Concrete Decorator 1: Adds mushroom topping
class Mushroom extends ToppingDecorator {
    public Mushroom(BasePizza basePizza) {
        super(basePizza);
    }

    @Override
    public int cost() {
        return basePizza.cost() + 10;
    }

    @Override
    public String getDescription() {
        return basePizza.getDescription() + " + Mushroom";
    }
}

// Concrete Decorator 2: Adds cheese topping
class Cheese extends ToppingDecorator {
    public Cheese(BasePizza basePizza) {
        super(basePizza);
    }

    @Override
    public int cost() {
        return basePizza.cost() + 20;
    }

    @Override
    public String getDescription() {
        return basePizza.getDescription() + " + Cheese";
    }
}

// Concrete Decorator 3: Adds extra cheese topping
class ExtraCheese extends ToppingDecorator {
    public ExtraCheese(BasePizza basePizza) {
        super(basePizza);
    }

    @Override
    public int cost() {
        return basePizza.cost() + 30;
    }

    @Override
    public String getDescription() {
        return basePizza.getDescription() + " + Extra Cheese";
    }
}

// Concrete Decorator 4: Adds jalapeño topping
class Jalapeno extends ToppingDecorator {
    public Jalapeno(BasePizza basePizza) {
        super(basePizza);
    }

    @Override
    public int cost() {
        return basePizza.cost() + 15;
    }

    @Override
    public String getDescription() {
        return basePizza.getDescription() + " + Jalapeño";
    }
}

// Concrete Decorator 5: Adds olive topping
class Olive extends ToppingDecorator {
    public Olive(BasePizza basePizza) {
        super(basePizza);
    }

    @Override
    public int cost() {
        return basePizza.cost() + 12;
    }

    @Override
    public String getDescription() {
        return basePizza.getDescription() + " + Olive";
    }
}

public class A4_DecoratorPattern {
    public static void main(String[] args) {
        System.out.println("=== DECORATOR PATTERN DEMONSTRATION ===\n");

        // =============================================================================
        // BASIC DECORATOR USAGE
        // =============================================================================
        System.out.println("1. BASIC DECORATOR USAGE:");
        System.out.println("=".repeat(50));

        // Start with a basic veg pizza and add toppings
        BasePizza pizza1 = new VegPizza();
        System.out.println("Base: " + pizza1.getDescription() + " - Cost: $" + pizza1.cost());

        // Add mushroom
        pizza1 = new Mushroom(pizza1);
        System.out.println("After adding Mushroom: " + pizza1.getDescription() + " - Cost: $" + pizza1.cost());

        // Add cheese
        pizza1 = new Cheese(pizza1);
        System.out.println("After adding Cheese: " + pizza1.getDescription() + " - Cost: $" + pizza1.cost());

        System.out.println("\n" + "=".repeat(50));

        // =============================================================================
        // MULTIPLE DECORATORS STACKING
        // =============================================================================
        System.out.println("\n2. MULTIPLE DECORATORS STACKING:");
        System.out.println("=".repeat(50));

        // Create a complex pizza with multiple toppings
        BasePizza pizza2 = new NonVegPizza();
        pizza2 = new Cheese(pizza2);
        pizza2 = new ExtraCheese(pizza2);
        pizza2 = new Mushroom(pizza2);
        pizza2 = new Jalapeno(pizza2);
        pizza2 = new Olive(pizza2);

        System.out.println("Complex Pizza: " + pizza2.getDescription());
        System.out.println("Total Cost: $" + pizza2.cost());

        System.out.println("\n" + "=".repeat(50));

        // =============================================================================
        // DIFFERENT COMBINATIONS DEMONSTRATION
        // =============================================================================
        System.out.println("\n3. DIFFERENT COMBINATIONS:");
        System.out.println("=".repeat(50));

        // Combination 1: Veg pizza with cheese and olives
        BasePizza combo1 = new VegPizza();
        combo1 = new Cheese(combo1);
        combo1 = new Olive(combo1);
        System.out.println("Combo 1: " + combo1.getDescription() + " - Cost: $" + combo1.cost());

        // Combination 2: Non-veg pizza with extra cheese and jalapeños
        BasePizza combo2 = new NonVegPizza();
        combo2 = new ExtraCheese(combo2);
        combo2 = new Jalapeno(combo2);
        System.out.println("Combo 2: " + combo2.getDescription() + " - Cost: $" + combo2.cost());

        // Combination 3: Veg pizza with all toppings
        BasePizza combo3 = new VegPizza();
        combo3 = new Mushroom(combo3);
        combo3 = new Cheese(combo3);
        combo3 = new ExtraCheese(combo3);
        combo3 = new Jalapeno(combo3);
        combo3 = new Olive(combo3);
        System.out.println("Combo 3: " + combo3.getDescription() + " - Cost: $" + combo3.cost());

        System.out.println("\n" + "=".repeat(50));

        // =============================================================================
        // REAL-WORLD SCENARIO: PIZZA ORDERING SYSTEM
        // =============================================================================
        System.out.println("\n4. REAL-WORLD SCENARIO - Pizza Ordering System:");
        System.out.println("=".repeat(50));

        System.out.println("\nCustomer 1: I want a veg pizza with cheese and mushrooms");
        BasePizza order1 = new VegPizza();
        order1 = new Cheese(order1);
        order1 = new Mushroom(order1);
        System.out.println("Order: " + order1.getDescription());
        System.out.println("Total: $" + order1.cost());

        System.out.println("\nCustomer 2: I want a non-veg pizza with extra cheese and jalapeños");
        BasePizza order2 = new NonVegPizza();
        order2 = new ExtraCheese(order2);
        order2 = new Jalapeno(order2);
        System.out.println("Order: " + order2.getDescription());
        System.out.println("Total: $" + order2.cost());

        System.out.println("\nCustomer 3: I want to add olives to my previous order");
        order2 = new Olive(order2);
        System.out.println("Updated Order: " + order2.getDescription());
        System.out.println("New Total: $" + order2.cost());

        System.out.println("\n=== DECORATOR PATTERN BENEFITS DEMONSTRATED ===");
        System.out.println("✓ Dynamic feature addition at runtime");
        System.out.println("✓ Multiple decorators can be stacked");
        System.out.println("✓ No modification of existing classes");
        System.out.println("✓ Flexible combinations of features");
        System.out.println("✓ Follows Open/Closed Principle");
        System.out.println("✓ Each decorator has single responsibility");
    }
}

/*
 * Decorator Pattern: Base Object has some feature and we want to add more
 * feature to it
 * without changing the base object
 * we can add more feature to it by creating a new class that extends the base
 * object
 * and adds the new feature
 * this is a structural design pattern
 * this is a way to add new feature to an object dynamically
 * 
 * new object is also an object we can create another new object with same
 * feature and add more feature to it
 */