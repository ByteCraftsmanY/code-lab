
/**
 * HelloWorld.java
 * 
 * A simple Java program demonstrating basic concepts and structure.
 * 
 * @author Your Name
 * @version 1.0
 */

/*
 * Auto import
 * If not imported, it will be imported by compiler automatically
 * So it will also work if we remove this import
 */
import java.lang.*;

/**
 * HelloWorld class demonstrates the basic structure of a Java program.
 * 
 * Key concepts:
 * - Everything is inside the class; there is nothing that can be outside the class
 * - File name and class name should be the same for easy compilation
 * - Compiler will generate bytecode file name same as class name
 * - We can use different class name from file name, but it will generate 
 *   bytecode (java <class_name>) with that class name
 */
public class HelloWorld {

    /**
     * Main method - the entry point of the Java program.
     * 
     * We added 'public' so that JRE can access main method outside the class.
     * We added 'static' so that JRE can call main method without creating 
     * an object of this class.
     * 
     * @param args Command line arguments (optional but must be passed)
     */
    public static void main(String[] args) {
        
        /*
         * System is a class name
         * out is an static object of System class
         * println is a method (as it contains parentheses)
         */
        System.out.println("Hello World");
    }
}