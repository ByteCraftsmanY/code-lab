/**
 * UserInput.java
 * 
 * A comprehensive Java program demonstrating user input using Scanner class.
 * Shows various input methods including binary number input with custom radix.
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
 * - useRadix() method for custom number base input
 * - Always close Scanner to free resources
 */
public class UserInput {

    /**
     * Main method demonstrating user input operations including binary input.
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

        /*
         * Example 1: Basic String Input (commented out)
         * 
         * // Prompt user for input
         * System.out.println("Enter your name: ");
         * 
         * // Check if input is available before reading
         * boolean isNextValueAvailable = sc.hasNext();
         * System.out.println("Is any input available: " + isNextValueAvailable);
         * 
         * // Read the input (next() reads until whitespace)
         * String name = sc.next();
         * System.out.println("Hello, " + name);
         */

        /*
         * Example 2: Binary Number Input using useRadix()
         * 
         * The useRadix method expects an integer value as its argument,
         * which sets the default radix (base) for number scanning operations in the
         * Scanner.
         * For example, useRadix(2) sets the radix to binary.
         */
        System.out.println("=== Binary Number Input Demo ===");
        sc.useRadix(2);
        System.out.println("Enter a binary value (e.g., 1010): ");

        int num = sc.nextInt();
        System.out.println(String.format("Value of binary input is: %d", num));

        // Reset radix to default (base 10) for future operations
        sc.useRadix(10);
        System.out.println("Radix reset to default (base 10)");

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
 * Configuration Methods:
 * - useRadix(int radix) - sets the default radix for number scanning
 * Examples: useRadix(2) for binary, useRadix(8) for octal, useRadix(16) for
 * hexadecimal
 * 
 * Validation Methods:
 * - hasNext() - checks if there is more input available
 * - hasNextInt() - checks if next input is an integer
 * - hasNextFloat() - checks if next input is a float
 * - hasNextDouble() - checks if next input is a double
 * - hasNextBoolean() - checks if next input is a boolean
 * - hasNextLine() - checks if there is more line input available
 * 
 * Utility Methods:
 * - close() - closes the scanner and frees resources
 * - reset() - resets the scanner to default state
 */