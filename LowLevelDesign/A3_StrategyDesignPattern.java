package LowLevelDesign;

/*
 * STRATEGY DESIGN PATTERN
 * =====================
 * 
 * Definition: The Strategy pattern defines a family of algorithms, encapsulates each one,
 * and makes them interchangeable. Strategy lets the algorithm vary independently from
 * clients that use it.
 * 
 * When to Use:
 * - When you have multiple ways to perform a task
 * - When you want to avoid code duplication in child classes
 * - When you want to switch algorithms at runtime
 * - When you have many conditional statements for different behaviors
 * 
 * Benefits:
 * - Eliminates code duplication
 * - Makes algorithms interchangeable at runtime
 * - Follows Open/Closed Principle (open for extension, closed for modification)
 * - Improves code maintainability and testability
 */

// =============================================================================
// PROBLEM: Without Strategy Pattern (Code Duplication)
// =============================================================================

// Problem: SportsBike and OffRoadBike have same logic but it's not in parent class
// This leads to code duplication and violates DRY principle
class Vehicle {
    public void drive() {
        System.out.println("Normal drive");
    }
}

class SportsBike extends Vehicle {
    public void drive() {
        System.out.println("Special drive"); // DUPLICATED CODE!
    }
}

class PassengerCar extends Vehicle {
    // Uses parent's normal drive - no duplication here
}

class OffRoadBike extends Vehicle {
    public void drive() {
        System.out.println("Special drive"); // DUPLICATED CODE!
    }
}

// =============================================================================
// SOLUTION: With Strategy Pattern
// =============================================================================

// Strategy Interface: Defines the contract for all drive strategies
interface DriveStrategy {
    void drive();

    String getStrategyName(); // Additional method for better demonstration
}

// Concrete Strategy 1: Normal driving behavior
class NormalDriveStrategy implements DriveStrategy {
    public void drive() {
        System.out.println("Normal drive - Smooth and steady");
    }

    public String getStrategyName() {
        return "Normal Drive";
    }
}

// Concrete Strategy 2: Special driving behavior
class SpecialDriveStrategy implements DriveStrategy {
    public void drive() {
        System.out.println("Special drive - Fast and aggressive");
    }

    public String getStrategyName() {
        return "Special Drive";
    }
}

// Concrete Strategy 3: Eco-friendly driving behavior
class EcoDriveStrategy implements DriveStrategy {
    public void drive() {
        System.out.println("Eco drive - Fuel efficient and gentle");
    }

    public String getStrategyName() {
        return "Eco Drive";
    }
}

// Concrete Strategy 4: Off-road driving behavior
class OffRoadDriveStrategy implements DriveStrategy {
    public void drive() {
        System.out.println("Off-road drive - Rough terrain handling");
    }

    public String getStrategyName() {
        return "Off-Road Drive";
    }
}

// Context Class: Uses a strategy to perform driving
class Vehicle2 {
    private DriveStrategy driveStrategy;
    private String vehicleName;

    // Constructor injection of strategy (set at creation time)
    public Vehicle2(DriveStrategy driveStrategy, String vehicleName) {
        this.driveStrategy = driveStrategy;
        this.vehicleName = vehicleName;
    }

    // Delegate driving to the strategy object
    public void drive() {
        System.out.print(vehicleName + " using " + driveStrategy.getStrategyName() + ": ");
        driveStrategy.drive();
    }

    // Method to change strategy at runtime (Strategy pattern benefit)
    public void setDriveStrategy(DriveStrategy newStrategy) {
        this.driveStrategy = newStrategy;
        System.out.println(vehicleName + " switched to " + newStrategy.getStrategyName());
    }

    public String getVehicleName() {
        return vehicleName;
    }
}

// Concrete Vehicle Classes: Each uses appropriate strategy at creation
class SportsBike2 extends Vehicle2 {
    public SportsBike2() {
        super(new SpecialDriveStrategy(), "Sports Bike");
    }
}

class OffRoadBike2 extends Vehicle2 {
    public OffRoadBike2() {
        super(new OffRoadDriveStrategy(), "Off-Road Bike");
    }
}

class PassengerCar2 extends Vehicle2 {
    public PassengerCar2() {
        super(new NormalDriveStrategy(), "Passenger Car");
    }
}

class HybridCar2 extends Vehicle2 {
    public HybridCar2() {
        super(new EcoDriveStrategy(), "Hybrid Car");
    }
}

public class A3_StrategyDesignPattern {
    public static void main(String[] args) {
        System.out.println("=== STRATEGY DESIGN PATTERN DEMONSTRATION ===\n");

        // Example 1: Different vehicles with different strategies
        System.out.println("1. Different vehicles with their default strategies:");
        Vehicle2 sportsBike = new SportsBike2();
        sportsBike.drive();

        Vehicle2 offRoadBike = new OffRoadBike2();
        offRoadBike.drive();

        Vehicle2 passengerCar = new PassengerCar2();
        passengerCar.drive();

        Vehicle2 hybridCar = new HybridCar2();
        hybridCar.drive();

        System.out.println("\n" + "=".repeat(50));

        // Example 2: Runtime strategy switching (Key benefit of Strategy pattern)
        System.out.println("\n2. Runtime strategy switching:");
        Vehicle2 vehicle = new PassengerCar2();
        vehicle.drive(); // Normal drive initially

        // Switch to eco mode for fuel saving
        vehicle.setDriveStrategy(new EcoDriveStrategy());
        vehicle.drive();

        // Switch to special mode for highway
        vehicle.setDriveStrategy(new SpecialDriveStrategy());
        vehicle.drive();

        System.out.println("\n" + "=".repeat(50));

        // Example 3: Demonstrating flexibility
        System.out.println("\n3. Same vehicle type with different strategies:");
        Vehicle2 bike1 = new Vehicle2(new NormalDriveStrategy(), "City Bike");
        Vehicle2 bike2 = new Vehicle2(new SpecialDriveStrategy(), "Racing Bike");
        Vehicle2 bike3 = new Vehicle2(new EcoDriveStrategy(), "Electric Bike");

        bike1.drive();
        bike2.drive();
        bike3.drive();

        System.out.println("\n" + "=".repeat(50));

        // Example 4: Real-world scenario simulation
        System.out.println("\n4. Real-world scenario - Adaptive driving:");
        Vehicle2 smartCar = new Vehicle2(new NormalDriveStrategy(), "Smart Car");

        System.out.println("Starting journey in city traffic...");
        smartCar.drive();

        System.out.println("Entering highway...");
        smartCar.setDriveStrategy(new SpecialDriveStrategy());
        smartCar.drive();

        System.out.println("Approaching fuel station, switching to eco mode...");
        smartCar.setDriveStrategy(new EcoDriveStrategy());
        smartCar.drive();

        System.out.println("\n=== BENEFITS DEMONSTRATED ===");
        System.out.println("✓ No code duplication");
        System.out.println("✓ Runtime strategy switching");
        System.out.println("✓ Easy to add new strategies");
        System.out.println("✓ Follows Open/Closed Principle");
        System.out.println("✓ Improved maintainability");
    }
}

/*
 * Conclution: When we see two child class has same logic but that is not
 * present in parent class.
 * we use design pattern to avoid code duplication.
 */