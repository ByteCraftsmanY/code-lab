package LowLevelDesign.A6_DesignParkingLot;

public class ParkingSpot {
    private int id;
    private Vehicle vehicle;
    private boolean isEmpty;

    public ParkingSpot(int id) {
        this.id = id;
        this.isEmpty = true;
    }

    public int getId() {
        return this.id;
    }

    public void parkVehicle(Vehicle vehicle) {
        this.vehicle = vehicle;
        this.isEmpty = false;
    }

    public void removeVehicle() {
        this.vehicle = null;
        this.isEmpty = true;
    }

    public boolean isEmpty() {
        return this.isEmpty;
    }

    public Vehicle getVehicle() {
        return this.vehicle;
    }
}

class TwoWheelerParkingSpot extends ParkingSpot {
    public TwoWheelerParkingSpot(int id) {
        super(id);
    }

    public int getPrice() {
        return 10;
    }
}

class FourWheelerParkingSpot extends ParkingSpot {
    public FourWheelerParkingSpot(int id) {
        super(id);
    }

    public int getPrice() {
        return 20;
    }
}