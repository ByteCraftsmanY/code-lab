package LowLevelDesign.A6_DesignParkingLot;

import java.util.ArrayList;
import java.util.List;

class ParkingSpotManager {
    private ParkingStrategy parkingStrategy;
    private List<ParkingSpot> parkingSpots;

    public ParkingSpotManager(List<ParkingSpot> parkingSpots, ParkingStrategy parkingStrategy) {
        this.parkingStrategy = parkingStrategy;
        this.parkingSpots = parkingSpots;
    }

    public ParkingSpot findParkingSpot(Vehicle vehicle) {
        return parkingStrategy.findParkingSpot(vehicle);
    }

    public void addParkingSpot(ParkingSpot parkingSpot) {
        this.parkingSpots.add(parkingSpot);
    }

    public void removeParkingSpot(ParkingSpot parkingSpot) {
        this.parkingSpots.remove(parkingSpot);
    }

    public ParkingSpot parkVehicle(Vehicle vehicle) {
        ParkingSpot parkingSpot = findParkingSpot(vehicle);
        if (parkingSpot != null) {
            parkingSpot.parkVehicle(vehicle);
        }
        return parkingSpot;
    }

    public void removeVehicle(Vehicle vehicle) {
        ParkingSpot parkingSpot = findParkingSpot(vehicle);
        if (parkingSpot != null) {
            parkingSpot.removeVehicle();
        }
    }
}

class TwoWheelerParkingSpotManager extends ParkingSpotManager {
    public TwoWheelerParkingSpotManager(List<ParkingSpot> parkingSpots, ParkingStrategy parkingStrategy) {
        super(parkingSpots, parkingStrategy);
    }
}

class FourWheelerParkingSpotManager extends ParkingSpotManager {
    public FourWheelerParkingSpotManager(List<ParkingSpot> parkingSpots, ParkingStrategy parkingStrategy) {
        super(parkingSpots, parkingStrategy);
    }
}

class ParkingSpotManagerFactory {
    public static ParkingSpotManager getParkingSpotManager(VehicleType vehicleType) {
        return switch (vehicleType) {
            case TWO_WHEELER ->
                new TwoWheelerParkingSpotManager(new ArrayList<>(), new NearToEntranceParkingStrategy());
            case FOUR_WHEELER ->
                new FourWheelerParkingSpotManager(new ArrayList<>(), new NearToEntranceParkingStrategy());
        };
    }
}