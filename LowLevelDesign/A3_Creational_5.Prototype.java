package LowLevelDesign;

/*The Prototype Design Pattern is a creational pattern that allows you to create new objects by cloning an existing one instead of creating them from scratch using new.*/

/*

1. Simple Definition
Imagine you are a Biologist who needs to study a specific cell. Instead of trying to "build" a new cell molecule by molecule, you take an existing cell and let it divide (clone). You then have an exact copy that you can modify slightly if needed.

In software, we use this when creating an object is expensive (e.g., it requires a heavy database query or complex math) and we already have a similar object in memory.
 */

/*
2. The Problem
If you try to copy an object manually from outside the class, you might run into issues:

Private Fields: You can't see or copy private data.

Tight Coupling: You have to know the specific class of the object you are copying.

Complexity: If the object is a complex "Shape," you have to figure out if it's a Circle or a Square before you can replicate it.
 */
/*3. Case Study: Game Registry
In a game, you might have a "Monster" object with complex textures and stats. Creating 100 monsters via new is slow. Instead, you create one Prototype Monster and clone it 99 times.
*/
// Step 1: The Prototype Interface

// Java provides a Cloneable interface, but creating our own is clearer for LLD
interface Prototype {
    Prototype clone();
}
// Step 2: Concrete Prototype

class Monster implements Prototype {
    private String type;
    private int health;
    private String texture; // Imagine this is a heavy 50MB file

    public Monster(String type, int health, String texture) {
        this.type = type;
        this.health = health;
        this.texture = texture;
    }

    // Copy Constructor logic for cloning
    public Monster(Monster source) {
        this.type = source.type;
        this.health = source.health;
        this.texture = source.texture;
    }

    @Override
    public Prototype clone() {
        return new Monster(this);
    }

    @Override
    public String toString() {
        return "Monster [" + type + ", Health=" + health + "]";
    }
}
// Step 3: Using the Prototype

public class Main {
    public static void main(String[] args) {
        Monster prototypeOrc = new Monster("Orc", 100, "orc_skin.png");

        // Fast creation through cloning
        Monster orc1 = (Monster) prototypeOrc.clone();
        Monster orc2 = (Monster) prototypeOrc.clone();

        System.out.println(orc1);
        System.out.println(orc2);
    }
}

/*
Key Benefits
- Performance: Faster than using `new` for complex objects.
- Avoids Subclassing: You don't need a "Factory" for every type of object.
- Convenience: You can store a "Registry" of pre-configured objects and just clone them when needed.

## Shallow vs. Deep Copy (Crucial Interview Topic)
- Shallow Copy: Copies the object, but nested objects (like a List) still point to the same memory address as the original.
- Deep Copy: Copies everything, including creating new copies of any nested objects.
*/