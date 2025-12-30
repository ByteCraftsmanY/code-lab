package LowLevelDesign;

import java.util.*;

/*
    The Flyweight Design Pattern is a structural pattern focused on memory optimization. 
    It is used when you need to create a massive number of similar objects 
    (thousands or millions) that would otherwise exhaust your RAM.
*/

/* 
    1. Simple Definition
        Imagine you are developing a Forest in a video game with 100,000 trees.
            - Each tree has a "Type" (Oak), a "Texture" (high-res image), and a "Position" (X, Y coordinates).
            - If you store the 5MB texture inside every single tree object, you would need 500GB of RAM just for trees!
            - The Flyweight solution: Store the 5MB texture once in a shared "Oak" object and have all 100,000 trees point to that same shared object. Only store the unique X, Y coordinates in each individual tree.
*/
/*
    2. Intrinsic vs. Extrinsic State
        - To use Flyweight, you must split your object's data into two parts:
            - Intrinsic State (Shared): Data that is constant across many objects (e.g., Tree Name, Color, Texture).
            - Extrinsic State (Unique): Data that varies and is unique to each instance (e.g., Coordinates X and Y).
*/

/*
    3. Java Implementation: A Counter-Strike Game
        Imagine a game where you have "Terrorists" and "Counter-Terrorists." 
        All terrorists use the same outfit and weapon type, but their location on the map is different.
*/

// Step 1: The Flyweight Interface
interface Player {
    void assignWeapon(String weapon);

    void mission(int x, int y); // Extrinsic state is passed as arguments
}

// Step 2: Concrete Flyweight (Shared Object)
class Terrorist implements Player {
    // Intrinsic State (Shared)
    private final String task;
    private String weapon;

    public Terrorist() {
        task = "Plant a bomb";
    }

    public void assignWeapon(String weapon) {
        this.weapon = weapon;
    }

    public void mission(int x, int y) {
        System.out.println("Terrorist with " + weapon + " at (" + x + "," + y + ") task: " + task);
    }
}

class CounterTerrorist implements Player {
    // Intrinsic State (Shared)
    private final String task;
    private String weapon;

    public CounterTerrorist() {
        task = "Defuse a bomb";
    }

    public void assignWeapon(String weapon) {
        this.weapon = weapon;
    }

    public void mission(int x, int y) {
        System.out.println("CounterTerrorist with " + weapon + " at (" + x + "," + y + ") task: " + task);
    }
}

// Step 3: The Flyweight Factory This ensures that objects are reused.
// If a "Terrorist" already exists, it returns the existing one.
class PlayerFactory {
    private static HashMap<String, Player> hm = new HashMap<>();

    public static Player getPlayer(String type) {
        Player p = null;
        if (hm.containsKey(type)) {
            p = hm.get(type);
        } else {
            switch (type) {
                case "Terrorist":
                    System.out.println("Creating Terrorist Object...");
                    p = new Terrorist();
                    break;
                case "CounterTerrorist":
                    System.out.println("Creating Counter-Terrorist Object...");
                    p = new CounterTerrorist();
                    break;
            }
            hm.put(type, p);
        }
        return p;
    }
}

// 4. How to use it
class Game {
    public static void main(String[] args) {
        // Even if we have 100 players, only 2 objects are actually created in memory
        for (int i = 0; i < 5; i++) {
            Player p = PlayerFactory.getPlayer("Terrorist");

            // We pass the unique (extrinsic) data during the method call
            p.assignWeapon("AK-47");
            p.mission(i * 10, i * 20);
        }
    }
}

// Reduces memory usage by sharing as much data as possible with similar
// objects. It is a way to use objects in large numbers when a simple repeated
// representation would use an unacceptable amount of memory.