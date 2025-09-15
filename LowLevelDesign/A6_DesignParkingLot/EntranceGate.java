package LowLevelDesign.A6_DesignParkingLot;

public class EntranceGate {
    private ParkingSpotManagerFactory parkingSpotManagerFactory;
    private ParkingSpotManager parkingSpotManager;

    public EntranceGate(ParkingSpotManagerFactory parkingSpotManagerFactory) {
        this.parkingSpotManagerFactory = parkingSpotManagerFactory;
        this.parkingSpotManager = parkingSpotManagerFactory.getParkingSpotManager(VehicleType.TWO_WHEELER);
    }

    public ParkingSpot findParkingSpot(Vehicle vehicle) {
        return parkingSpotManager.findParkingSpot(vehicle);
    }

    public void bookSpot(Vehicle vehicle, ParkingSpot parkingSpot) {
        parkingSpotManager.parkVehicle(vehicle, parkingSpot);
    }
    
    public void generateTicket(Vehicle vehicle, ParkingSpot parkingSpot) {
        return parkingSpotManager.generateTicket(vehicle);
    }
}
