package LowLevelDesign.A6_DesignParkingLot;

interface ParkingStrategy {
    ParkingSpot findParkingSpot(Vehicle vehicle);
}

class NearToEntranceParkingStrategy implements ParkingStrategy {
    @Override
    public ParkingSpot findParkingSpot(Vehicle vehicle) {
        return null;
    }
}

class NearToEntracneAndElevatorParkingStrategy implements ParkingStrategy {
    @Override
    public ParkingSpot findParkingSpot(Vehicle vehicle) {
        return null;
    }
}

class NearToExitParkingStrategy implements ParkingStrategy {
    @Override
    public ParkingSpot findParkingSpot(Vehicle vehicle) {
        return null;
    }
}