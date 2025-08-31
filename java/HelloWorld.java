
/**
 * HelloWorld.java
 * 
 * A simple Java program demonstrating basic concepts and structure.
 * 
 * @author Yogesh Vishwakarma
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
 * - Everything is inside the class; there is nothing that can be outside the
 * class
 * - File name and class name should be the same for easy compilation
 * - Compiler will generate bytecode file name same as class name
 * - We can use different class name from file name, but it will generate
 * bytecode (java <class_name>) with that class name
 * - If we make class public then fileName and className equality should be
 * mandatory
 */
public class HelloWorld {

    /**
     * Main method - the entry point of the Java program.
     * 
     * We added 'public' so that JRE can access main method outside the class.
     * We added 'static' so that JRE can call main method without creating
     * an object of this class.
     * We can remove main method arguments - it will compile but not run as JRE(JVM)
     * requires main method signature in this exact format:
     * [public static void main(String[] args)] only
     * 
     * @param args Command line arguments (optional but must be passed)
     */
    public static void main(String[] args) {

        /*
         * System is a class name
         * out is a static object of System class
         * println is a method (as it contains parentheses)
         */
        System.out.println("Hello World");

        /*
         * Whatever arguments we are passing through command line after java
         * <class_name> command will be added in args array
         * Example: java <class_name> hello bye
         * Then we get args[0] = "hello", args[1] = "bye"
         */
    }
}