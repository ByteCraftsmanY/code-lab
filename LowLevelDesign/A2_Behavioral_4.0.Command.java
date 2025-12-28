package LowLevelDesign;
/*  
 * 1. Simple Definition
 * The Command Pattern is a design where the Sender (the person pressing a button) does not talk directly to the Receiver (the Light or TV).
 * 
 * Instead, we put a Command Object in the middle. The Sender only knows how to trigger the command, and the command knows exactly which device to turn on or off.
 */

//2. The "Before" (Bad Code)
//In this version, the Button is "hard-wired" to a specific Light. 
// If you want to use the button for a Fan, you have to rewrite the Button class.

class Light {
    public void turnOn() {
        System.out.println("Light is On");
    }
}

class RemoteButton {
    private Light light; // Tightly coupled!

    public RemoteButton(Light light) {
        this.light = light;
    }

    public void press() {
        light.turnOn(); // This button ONLY works for lights.
    }
}

/*
 * 3. The "After" (Command Pattern)
 * We add an object (the Command) between the button and the device. Now the
 * button is "universal."
 */

// Step 1: The Command Interface

interface Command {
    void execute();
}

// Step 2: Concrete Commands (The "Slips of Paper")

class LightOnCommand implements Command {
    private Light light;

    public LightOnCommand(Light light) {
        this.light = light;
    }

    public void execute() {
        light.turnOn();
    }
}

class FanOnCommand implements Command {
    private Fan fan;

    public FanOnCommand(Fan fan) {
        this.fan = fan;
    }

    public void execute() {
        fan.start();
    }
}
// Step 3: The Sender (The Universal Button)

class RemoteButton {
    private Command cmd; // Decoupled!

    public void setCommand(Command cmd) {
        this.cmd = cmd;
    }

    public void press() {
        cmd.execute();
    }
}
/*
 * 4. Why this is better
 * Interchangeable: You can take the same button and "re-program" it from a
 * Light Button to a Fan Button just by giving it a different Command object.
 * 
 * Cleaner Code: The Button class never changes, no matter how many new devices
 * (TV, AC, Garage Door) you add to your house.
 * 
 * History: Because the Command is an object, you can save it in a List to see a
 * history of what buttons were pressed.
 */

public class Test {
    public static void main(String[] args) {
        Light light = new Light();
        RemoteButton remote = new RemoteButton();
        remote.setCommand(new LightOnCommand(light));
        remote.press();
        remote.setCommand(new FanOnCommand(new Fan()));
        remote.press();
    }
}
