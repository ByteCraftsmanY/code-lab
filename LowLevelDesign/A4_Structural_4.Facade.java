package LowLevelDesign;

/*
    The Facade Design Pattern is the "simplest" structural pattern because its entire purpose is to hide complexity. 
    It provides a single, simplified interface to a large body of code, such as a complex library or a set of subsystems.
*/

/*
    1. Simple Definition
    Imagine you want to order food from a restaurant.

    Without a Facade: You have to call the Chef to see if they have ingredients, call the Delivery Guy to see if he's free, and call the Accountant to process your payment.

    With a Facade (UberEats/Zomato): You just click "Place Order." The app (the Facade) talks to the kitchen, the driver, and the bank for you.

    In code, the Facade provides a "Help Desk" or a "Single Entry Point" so the client doesn't have to deal with 10 different classes.

*/

/*
    2. The Problem
        You are building a Home Theater System. To watch a movie, you have to:
            Turn on the Lights (Dim them).
            Turn on the Projector.
            Turn on the Sound System (Set volume).
            Turn on the Blu-Ray Player (Play).
        If you do this in your Main class, your code is messy and tightly coupled to 4 different systems.

*/

// 3. Java Implementation

// Step 1: The Complex Subsystems
class Lights {
    public void dim(int level) {
        System.out.println("Lights dimmed to " + level + "%");
    }
}

class Projector {
    public void on() {
        System.out.println("Projector is ON");
    }

    public void setInput(String input) {
        System.out.println("Projector input set to " + input);
    }
}

class SoundSystem {
    public void on() {
        System.out.println("Sound System is ON");
    }

    public void setVolume(int level) {
        System.out.println("Volume set to " + level);
    }
}

// Step 2: The Facade This class "wraps" all the complex subsystems into one
// easy method.

class HomeTheaterFacade {
    private Lights lights;
    private Projector projector;
    private SoundSystem amp;

    public HomeTheaterFacade(Lights l, Projector p, SoundSystem s) {
        this.lights = l;
        this.projector = p;
        this.amp = s;
    }

    public void watchMovie(String movie) {
        System.out.println("Get ready to watch a movie...");
        lights.dim(10);
        projector.on();
        projector.setInput("Blu-Ray");
        amp.on();
        amp.setVolume(20);
        System.out.println("Now playing: " + movie);
    }
}

// Step 3: Using the Facade

public class Main {
    public static void main(String[] args) {
        // Create components
        Lights lights = new Lights();
        Projector projector = new Projector();
        SoundSystem sound = new SoundSystem();

        // Use the Facade
        HomeTheaterFacade movieConsole = new HomeTheaterFacade(lights, projector, sound);
        movieConsole.watchMovie("Inception");
    }
}

/*
    ## Why use it?
    - Simplicity: Clients only need to learn one simple method instead of 20.
    - Loose Coupling: If you change the internal SoundSystem class, you only update the Facade, not the 100 places in your app that play movies.
    - Layering: You can create multiple facades for different levels of complexity.
*/