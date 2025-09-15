package LowLevelDesign.A6_DesignParkingLot;

enum VehicleType {
    TWO_WHEELER,
    FOUR_WHEELER
}

public interface Vehicle {
    VehicleType getVehicleType();

    String getVehicleNumber();
}

class TwoWheelerVehicle implements Vehicle {
    private String vehicleNumber;

    public TwoWheelerVehicle(String vehicleNumber) {
        this.vehicleNumber = vehicleNumber;
    }

    @Override
    public VehicleType getVehicleType() {
        return VehicleType.TWO_WHEELER;
    }

    @Override
    public String getVehicleNumber() {
        return vehicleNumber;
    }
}

class FourWheelerVehicle implements Vehicle {
    private String vehicleNumber;

    public FourWheelerVehicle(String vehicleNumber) {
        this.vehicleNumber = vehicleNumber;
    }

    @Override
    public VehicleType getVehicleType() {
        return VehicleType.FOUR_WHEELER;
    }

    @Override
    public String getVehicleNumber() {
        return vehicleNumber;
    }
}