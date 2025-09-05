package LowLevelDesign;

import java.util.ArrayList;

/*
 * Liskov Substitution Principle (LSP) Example
 * 
 * LSP states: Objects of a superclass should be replaceable with objects of its subclasses
 * without breaking the application. Subclasses should extend the capability of parent class,
 * not narrow it down.
 */

// Base Vehicle class - violates LSP when Bicycle extends it
class Vehicle {
    public boolean hasEngine() {
        return true;
    }

    public int getNumberOfWheels() {
        return 2;
    }
}

class Bike extends Vehicle {
    @Override
    public int getNumberOfWheels() {
        return 2;
    }
}

class Car extends Vehicle {

    @Override
    public int getNumberOfWheels() {
        return 4;
    }
}

// LSP VIOLATION: Bicycle cannot have an engine, but Vehicle assumes all
// vehicles do
class Bicycle extends Vehicle {
    @Override
    public boolean hasEngine() {
        return false; // Bicycles don't have engines
    }
}

// Better approach: Separate base class without engine assumption
class Vehicle2 {
    public int getNumberOfWheels() {
        return 2;
    }
}

// Better approach: Separate class for vehicles with engines
class EngineVehicle extends Vehicle2 {
    public boolean hasEngine() {
        return true;
    }
}

class Bike2 extends EngineVehicle {
    @Override
    public int getNumberOfWheels() {
        return 2;
    }
}

class Car2 extends EngineVehicle {
    @Override
    public int getNumberOfWheels() {
        return 4;
    }
}

class A1_LSP {
    public static void main(String[] args) {
        System.out.println("=== LSP Violation Example ===");

        // This works but violates LSP - Bicycle doesn't truly have an engine
        ArrayList<Vehicle> vehicles = new ArrayList<>();
        vehicles.add(new Bike());
        vehicles.add(new Car());
        vehicles.add(new Bicycle());

        System.out.println("Vehicle wheels:");
        for (Vehicle vehicle : vehicles) {
            System.out.println("- " + vehicle.getClass().getSimpleName() +
                    ": " + vehicle.getNumberOfWheels() + " wheels, " +
                    "has engine: " + vehicle.hasEngine());
        }

        System.out.println("\n=== LSP Compliant Example ===");

        // This follows LSP - all EngineVehicles truly have engines
        ArrayList<EngineVehicle> engineVehicles = new ArrayList<>();
        engineVehicles.add(new Bike2());
        engineVehicles.add(new Car2());

        System.out.println("Engine vehicles:");
        for (EngineVehicle engineVehicle : engineVehicles) {
            System.out.println("- " + engineVehicle.getClass().getSimpleName() +
                    ": " + engineVehicle.getNumberOfWheels() + " wheels, " +
                    "has engine: " + engineVehicle.hasEngine());
        }
    }
}
