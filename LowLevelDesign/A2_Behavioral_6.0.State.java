package LowLevelDesign;

/*
    The State Design Pattern is a behavioral pattern that allows an object to 
    change its behavior when its internal state changes. 
    To the outside world, it looks like the object has changed its entire class.

1. Simple Definition
    Imagine a Document in an office app.

    If the state is Draft, the "Publish" button sends it to a manager.

    If the state is Moderation, the "Publish" button makes it public.

    If the state is Published, the "Publish" button does nothing.

    Instead of using a giant if-else or switch block inside the Document class to check the state, we turn each state into its own class.
*/

/*
    2. The Problem: "The Switch-Case Hell"
        Without the State pattern, your code becomes a mess of conditions. 
        If you add a new state (like "Truck"), you have to find and update every single method in your class.
*/

//  ❌ BAD WAY (Hard to maintain) | Violated Open/Closed Principle
class NavigationService {
    public int getEta(String mode) {
        if (mode.equals("Car"))
            return 10;
        else if (mode.equals("Walking"))
            return 60;
        return 0;
    }

    public String getDirections(String mode) {
        if (mode.equals("Car"))
            return "Follow the highway";
        else if (mode.equals("Walking"))
            return "Walk through the park";
        return "";
    }
}

/*
 * 2. The "After" (The Design Pattern Way)
 * This approach uses a State Interface. The NavigationService doesn't care how
 * the math works; it just asks the "current state" for the answer.
 */

// Step 1: The Interface
interface TransportState {
    int getEta();

    String getDirections();
}

// Step 2: Concrete States
class CarTransportState implements TransportState {
    @Override
    public int getEta() {
        return 10;
    }

    @Override
    public String getDirections() {
        return "Drive on the main road.";
    }
}

class WalkingTransportState implements TransportState {
    @Override
    public int getEta() {
        return 60;
    }

    @Override
    public String getDirections() {
        return "Use the pedestrian path.";
    }
}

class BikeTransportState implements TransportState {
    @Override
    public int getEta() {
        return 25;
    }

    @Override
    public String getDirections() {
        return "Use the dedicated bike lane.";
    }
}

// Step 3: The Context (The Service)
class NavigationService {
    private TransportState currentState;

    // We can inject the state via constructor or setter
    public NavigationService(TransportState initialState) {
        this.currentState = initialState;
    }

    public void setTransportMode(TransportState newState) {
        this.currentState = newState;
    }

    // These methods now have NO logic; they just delegate
    public void showRouteInfo() {
        System.out.println("ETA: " + currentState.getEta() + " mins");
        System.out.println("Directions: " + currentState.getDirections());
    }
}

// Step 4: Execution

public class Main {
    public static void main(String[] args) {
        // Start as a Car
        NavigationService nav = new NavigationService(new CarTransportState());
        nav.showRouteInfo();

        System.out.println("--- Switching to Walking ---");

        // Change state at runtime
        nav.setTransportMode(new WalkingTransportState());
        nav.showRouteInfo();
    }
}

/*
 * Final Documentation Note:
 *      In an interview, if they ask: "Is this State or Strategy?"
 *          Strategy Answer: "It's Strategy because the user manually chooses the mode."
 *          State Answer: "It's State if the application automatically switches from Car to Walking when it detects the user has parked and is moving slowly."
 */