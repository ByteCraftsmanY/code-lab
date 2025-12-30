package LowLevelDesign;

// https://youtu.be/7g9S371qzwM?si=VBsj6NQgdyx3-hHZ

/*
 * Factory Design Pattern: when we want to create object based on some condition
 * (conditional based object creation) 
 * if there are 100s classes and we want to create object based on some condition then we can use factory design pattern to avoid code duplication
 * 
 * factory is a source of truth for object creation
 */

// =============================================================================
// FACTORY PATTERN EXAMPLE: Shape Factory
// =============================================================================

// Product Interface: Defines the contract for all shapes
interface Shape {
    void draw();

    String getShapeType();
}

// Concrete Product 1: Circle implementation
class Circle implements Shape {
    @Override
    public void draw() {
        System.out.println("Drawing Circle");
    }

    @Override
    public String getShapeType() {
        return "Circle";
    }
}

// Concrete Product 2: Square implementation
class Square implements Shape {
    @Override
    public void draw() {
        System.out.println("Drawing Square");
    }

    @Override
    public String getShapeType() {
        return "Square";
    }
}

// Concrete Product 3: Rectangle implementation
class Rectangle implements Shape {
    @Override
    public void draw() {
        System.out.println("Drawing Rectangle");
    }

    @Override
    public String getShapeType() {
        return "Rectangle";
    }
}

// Factory Class: Creates shapes based on input type
class ShapeFactory {
    public Shape getShape(String shapeType) {
        if (shapeType == null) {
            return null;
        }

        switch (shapeType.toUpperCase()) {
            case "CIRCLE":
                return new Circle();
            case "SQUARE":
                return new Square();
            case "RECTANGLE":
                return new Rectangle();
            default:
                System.out.println("Unknown shape type: " + shapeType);
                return null;
        }
    }

    /*
     * Abstract Factory Design Pattern: its a factory of factories
     * 
     * needs when we have different type of products and we want to group related
     * item together seperetly
     * 
     * when we want more then 1 factory and each factory has its related product
     * 
     * when we want to create a family of related
     * objects without specifying their concrete classes
     */

    // Abstract Product: Vehicle interface
    interface Vehicle {
        void average();

        void start();

        String getVehicleType();
    }

    // Concrete Product: Luxury Car (Family 1)
    class LuxuryCar implements Vehicle {
        @Override
        public void average() {
            System.out.println("Luxury Car: 8 km/l average");
        }

        @Override
        public void start() {
            System.out.println("Luxury Car: Smooth engine start with premium sound");
        }

        @Override
        public String getVehicleType() {
            return "Luxury Car";
        }
    }

    // Concrete Product: Luxury Bike (Family 1)
    class LuxuryBike implements Vehicle {
        @Override
        public void average() {
            System.out.println("Luxury Bike: 25 km/l average");
        }

        @Override
        public void start() {
            System.out.println("Luxury Bike: Premium engine start");
        }

        @Override
        public String getVehicleType() {
            return "Luxury Bike";
        }
    }

    // Concrete Product: Economy Car (Family 2)
    class EconomyCar implements Vehicle {
        @Override
        public void average() {
            System.out.println("Economy Car: 15 km/l average");
        }

        @Override
        public void start() {
            System.out.println("Economy Car: Basic engine start");
        }

        @Override
        public String getVehicleType() {
            return "Economy Car";
        }
    }

    // Concrete Product: Economy Bike (Family 2)
    class EconomyBike implements Vehicle {
        @Override
        public void average() {
            System.out.println("Economy Bike: 50 km/l average");
        }

        @Override
        public void start() {
            System.out.println("Economy Bike: Simple engine start");
        }

        @Override
        public String getVehicleType() {
            return "Economy Bike";
        }
    }

    // Abstract Factory Interface: Creates families of vehicles
    interface VehicleFactory {
        Vehicle createCar();

        Vehicle createBike();

        String getFactoryType();
    }

    // Concrete Factory 1: Creates luxury vehicle family
    class LuxuryVehicleFactory implements VehicleFactory {
        @Override
        public Vehicle createCar() {
            return new LuxuryCar();
        }

        @Override
        public Vehicle createBike() {
            return new LuxuryBike();
        }

        @Override
        public String getFactoryType() {
            return "Luxury Vehicle Factory";
        }
    }

    // Concrete Factory 2: Creates economy vehicle family
    class EconomyVehicleFactory implements VehicleFactory {
        @Override
        public Vehicle createCar() {
            return new EconomyCar();
        }

        @Override
        public Vehicle createBike() {
            return new EconomyBike();
        }

        @Override
        public String getFactoryType() {
            return "Economy Vehicle Factory";
        }
    }

    // Factory of Factories: Creates the appropriate vehicle factory
    class VehicleFactoryProducer {
        public static VehicleFactory getVehicleFactory(String factoryType) {
            if (factoryType == null) {
                return null;
            }

            switch (factoryType.toUpperCase()) {
                case "LUXURY":
                    return new LuxuryVehicleFactory();
                case "ECONOMY":
                    return new EconomyVehicleFactory();
                default:
                    System.out.println("Unknown factory type: " + factoryType);
                    return null;
            }
        }
    }

public class A5_FactoryAndAbstractFactoryDesignPattern {
    public static void main(String[] args) {
        System.out.println("=== FACTORY & ABSTRACT FACTORY PATTERN DEMONSTRATION ===\n");

        // =============================================================================
        // FACTORY PATTERN DEMONSTRATION
        // =============================================================================
        System.out.println("1. FACTORY PATTERN - Shape Creation:");
        System.out.println("=".repeat(50));

        ShapeFactory shapeFactory = new ShapeFactory();

        // Create different shapes using factory
        String[] shapeTypes = { "CIRCLE", "SQUARE", "RECTANGLE", "TRIANGLE" };
        for (String shapeType : shapeTypes) {
            Shape shape = shapeFactory.getShape(shapeType);
            if (shape != null) {
                System.out.print("Created " + shape.getShapeType() + ": ");
                shape.draw();
            }
        }

        System.out.println("\n" + "=".repeat(50));

        // =============================================================================
        // ABSTRACT FACTORY PATTERN DEMONSTRATION
        // =============================================================================
        System.out.println("\n2. ABSTRACT FACTORY PATTERN - Vehicle Family Creation:");
        System.out.println("=".repeat(50));

        // Create luxury vehicle factory
        VehicleFactory luxuryFactory = VehicleFactoryProducer.getVehicleFactory("LUXURY");
        if (luxuryFactory != null) {
            System.out.println("\n" + luxuryFactory.getFactoryType() + ":");
            Vehicle luxuryCar = luxuryFactory.createCar();
            Vehicle luxuryBike = luxuryFactory.createBike();

            System.out.print("Luxury Car: ");
            luxuryCar.start();
            luxuryCar.average();

            System.out.print("Luxury Bike: ");
            luxuryBike.start();
            luxuryBike.average();
        }

        // Create economy vehicle factory
        VehicleFactory economyFactory = VehicleFactoryProducer.getVehicleFactory("ECONOMY");
        if (economyFactory != null) {
            System.out.println("\n" + economyFactory.getFactoryType() + ":");
            Vehicle economyCar = economyFactory.createCar();
            Vehicle economyBike = economyFactory.createBike();

            System.out.print("Economy Car: ");
            economyCar.start();
            economyCar.average();

            System.out.print("Economy Bike: ");
            economyBike.start();
            economyBike.average();
        }

        System.out.println("\n" + "=".repeat(50));

        // =============================================================================
        // REAL-WORLD SCENARIO DEMONSTRATION
        // =============================================================================
        System.out.println("\n3. REAL-WORLD SCENARIO - Vehicle Showroom:");
        System.out.println("=".repeat(50));

        // Customer wants luxury vehicles
        System.out.println("\nCustomer 1: I want luxury vehicles");
        VehicleFactory customer1Factory = VehicleFactoryProducer.getVehicleFactory("LUXURY");
        if (customer1Factory != null) {
            Vehicle customer1Car = customer1Factory.createCar();
            System.out.println("Showroom: Here's your " + customer1Car.getVehicleType());
            customer1Car.start();
            customer1Car.average();
        }

        // Customer wants economy vehicles
        System.out.println("\nCustomer 2: I want economy vehicles");
        VehicleFactory customer2Factory = VehicleFactoryProducer.getVehicleFactory("ECONOMY");
        if (customer2Factory != null) {
            Vehicle customer2Bike = customer2Factory.createBike();
            System.out.println("Showroom: Here's your " + customer2Bike.getVehicleType());
            customer2Bike.start();
            customer2Bike.average();
        }

        System.out.println("\n=== PATTERN BENEFITS DEMONSTRATED ===");
        System.out.println("✓ Factory Pattern: Centralized object creation");
        System.out.println("✓ Abstract Factory: Family of related objects");
        System.out.println("✓ Easy to add new products/families");
        System.out.println("✓ Decoupled object creation from usage");
        System.out.println("✓ Consistent product families");
    }
}
