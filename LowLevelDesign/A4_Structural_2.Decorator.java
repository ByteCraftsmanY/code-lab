package LowLevelDesign;


/*
    The Decorator Design Pattern is a structural pattern that allows you to dynamically add 
    new behaviors to an object without changing its implementation or affecting other objects
    of the same class.

    Think of it as "wrapping" an object in several layers of functionality.

*/

/*
    1. Simple Definition
    Imagine you are ordering a Coffee.
        You start with a Plain Coffee ($10).
        You want to add Milk (+$2).
        You want to add Sugar (+$1).
        You want to add Whipped Cream (+$3).
    Instead of creating 100 different classes like CoffeeWithMilk, CoffeeWithSugarAndCream, etc.,
    you just "decorate" the base coffee with wrappers.
 */

/*
2. The Problem: Class Explosion
    If you use inheritance to add features, your class hierarchy becomes unmanageable.
    If you have 5 toppings, you would need $2^5$ (32) subclasses to cover every possible combination!
    
    Decorator solves this by using Composition instead of Inheritance.
 */

// 3. Java Implementation
// Step 1: The Interface

interface Coffee {
    String getDescription();

    double getCost();
}

// Step 2: The Concrete Component
class PlainCoffee implements Coffee {
    public String getDescription() {
        return "Plain Coffee";
    }

    public double getCost() {
        return 10.0;
    }
}

// Step 3: The Abstract Decorator

// This is the "wrapper" that implements the same interface as the object it is
// wrapping.

abstract class CoffeeDecorator implements Coffee {
    protected Coffee decoratedCoffee;

    public CoffeeDecorator(Coffee coffee) {
        this.decoratedCoffee = coffee;
    }

    public String getDescription() {
        return decoratedCoffee.getDescription();
    }

    public double getCost() {
        return decoratedCoffee.getCost();
    }
}

// Step 4: Concrete Decorators
class MilkDecorator extends CoffeeDecorator {
    public MilkDecorator(Coffee coffee) {
        super(coffee);
    }

    public String getDescription() {
        return decoratedCoffee.getDescription() + ", Milk";
    }

    public double getCost() {
        return decoratedCoffee.getCost() + 2.0;
    }
}

class SugarDecorator extends CoffeeDecorator {
    public SugarDecorator(Coffee coffee) {
        super(coffee);
    }

    public String getDescription() {
        return decoratedCoffee.getDescription() + ", Sugar";
    }

    public double getCost() {
        return decoratedCoffee.getCost() + 1.0;
    }
}

// 4. How to use it
// You can keep wrapping the object as much as you like!
class Main {
    public static void main(String[] args) {
        // I want a coffee with milk and sugar
        Coffee myOrder = new PlainCoffee();
        myOrder = new MilkDecorator(myOrder);
        myOrder = new SugarDecorator(myOrder);

        System.out.println("Order: " + myOrder.getDescription());
        System.out.println("Total Cost: $" + myOrder.getCost());
    }
}
