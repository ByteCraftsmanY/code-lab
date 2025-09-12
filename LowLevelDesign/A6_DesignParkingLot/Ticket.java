package LowLevelDesign.A6_DesignParkingLot;

public class Ticket {
    private String ticketNumber;
    private Vehicle vehicle;
    private ParkingSpot parkingSpot;
    private long entryTime;

    private long exitTime;
    private double price;
    private String status;
    private String paymentStatus;

    public Ticket(String ticketNumber, Vehicle vehicle, ParkingSpot parkingSpot, long entryTime) {
        this.ticketNumber = ticketNumber;
        this.vehicle = vehicle;
        this.parkingSpot = parkingSpot;
        this.entryTime = entryTime;
    }

    public String getTicketNumber() {
        return ticketNumber;
    }

    public Vehicle getVehicle() {
        return vehicle;
    }

    public ParkingSpot getParkingSpot() {
        return parkingSpot;
    }

    public long getEntryTime() {
        return entryTime;
    }

    public long getExitTime() {
        return exitTime;
    }

    public double getPrice() {
        return price;
    }

    public String getStatus() {
        return status;
    }

    public String getPaymentStatus() {
        return paymentStatus;
    }

    public void setExitTime(long exitTime) {
        this.exitTime = exitTime;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public void setStatus(String status) {
        this.status = status;
    }

    public void setPaymentStatus(String paymentStatus) {
        this.paymentStatus = paymentStatus;
    }
}
