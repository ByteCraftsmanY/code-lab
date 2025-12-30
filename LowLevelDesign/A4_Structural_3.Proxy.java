package LowLevelDesign;

/*
    The Proxy Design Pattern is a structural pattern that provides 
    a placeholder or representative for another object.

    A proxy controls access to the original object, allowing you to perform 
    something either before or after the request reaches the original object.
*/

/*

    1. Simple Definition
        Imagine a Credit Card.

        The Credit Card is a Proxy for the cash in your bank account.

        Instead of carrying around a heavy bag of coins (the real object), you carry the card.

        When you swipe the card, it checks if you have enough money (security/control) and then executes the transaction.

    In code, the Proxy has the exact same interface as the real object, so the client doesn't even know they are talking to a "middleman."

*/

/*

    2. Common Types of Proxies
        Virtual Proxy (Lazy Loading): Creates a "lightweight" version of a heavy object. It only creates the real, "heavy" object when it is actually needed.

        Protection Proxy (Security): Checks if the user has the right permissions before allowing them to call a method on the real object.

        Remote Proxy: Represents an object that exists on a different server or in a different address space.

*/


/*

    That is a perfect example to illustrate a Virtual Proxy. In many apps, loading a high-resolution image from a disk or network is slow and memory-intensive. You don't want to load it unless the user actually scrolls to it or clicks "Show Image."

    The Proxy acts as a "stand-in" that shows a placeholder or just waits until the real image is needed.
*/


// 1. The Virtual Proxy Concept
// The Proxy will hold a reference to the RealImage but won't instantiate it until the display() method is called for the first time.

// Step 1: The Subject Interface
interface Image {
    void display();
}

// Step 2: The Real Object (Heavy)

class RealImage implements Image {
    private String fileName;

    public RealImage(String fileName) {
        this.fileName = fileName;
        loadFromDisk(); // Simulation of an expensive operation
    }

    private void loadFromDisk() {
        System.out.println("Loading " + fileName + " (High Res - 50MB)...");
    }

    @Override
    public void display() {
        System.out.println("Displaying " + fileName);
    }
}

// Step 3: The Proxy Object (Lightweight)
class ProxyImage implements Image {
    private RealImage realImage;
    private String fileName;

    public ProxyImage(String fileName) {
        this.fileName = fileName;
    }

    @Override
    public void display() {
        // Lazy Loading: Create the real object only when needed
        if (realImage == null) {
            realImage = new RealImage(fileName);
        }
        realImage.display();
    }
}

// Step 4: The Client Code
public class ImageProxyDemo {
    public static void main(String[] args) {
        Image image = new ProxyImage("vacation_photo_4K.jpg");

        // The image is NOT loaded yet! 
        System.out.println("Image object created. Waiting for user interaction...");

        // Image will be loaded from disk now
        image.display(); 

        // Second time, it won't load from disk again
        image.display(); 
    }
}