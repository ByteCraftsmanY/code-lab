/**
 * UserInput.java
 * 
 * A simple Java program demonstrating user input using Scanner class.
 * 
 * @author Yogesh Vishwakarma
 * @version 1.0
 */

/*
 * Auto import - java.lang package is automatically imported
 */
import java.lang.*;

/*
 * utils package comes after version 5 of Java
 * Scanner class is used to take user input.
 */
import java.util.*;

/**
 * UserInput class demonstrates how to take user input in Java.
 * 
 * Key concepts:
 * - Scanner class is used for user input
 * - System.in is associated with keyboard input
 * - System.out is associated with monitor (display device)
 * - Always close Scanner to free resources
 */
public class UserInput {

    /**
     * Main method demonstrating user input operations.
     * 
     * @param args Command line arguments
     */
    public static void main(String[] args) {

        /*
         * Scanner class is used to take user input.
         * System.in is associated with keyboard.
         * System.out is associated with monitor (display device).
         */
        Scanner sc = new Scanner(System.in);

        // Prompt user for input
        System.out.println("Enter your name: ");

        // Check if input is available before reading
        boolean isNextValueAvailable = sc.hasNext();
        System.out.println("Is any input available: " + isNextValueAvailable);

        // Read the input (next() reads until whitespace)
        String name = sc.next();
        System.out.println("Hello, " + name);

        /*
         * close() method is used to close the scanner and free resources.
         * It's good practice to always close Scanner objects.
         */
        sc.close();
    }
}

/**
 * Scanner Class Methods Reference:
 * 
 * Input Methods:
 * - next() - reads string input until whitespace
 * - nextLine() - reads string input including spaces (entire line)
 * - nextInt() - reads integer input
 * - nextFloat() - reads float input
 * - nextDouble() - reads double input
 * - nextBoolean() - reads boolean input
 * 
 * Validation Methods:
 * - hasNext() - checks if there is more input available
 * - hasNextInt() - checks if next input is an integer
 * - hasNextFloat() - checks if next input is a float
 * - hasNextDouble() - checks if next input is a double
 * - hasNextBoolean() - checks if next input is a boolean
 * - hasNextLine() - checks if there is more line input available
 */