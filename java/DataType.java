/**
 * DataType.java
 * 
 * A comprehensive demonstration of Java primitive data types.
 * Shows size, range, and default values for each data type.
 * 
 * @author Yogesh Vishwakarma
 * @version 1.0
 */

/*
 * Auto import - java.lang package is automatically imported
 */
import java.lang.*;

/**
 * DataType class demonstrates all primitive data types in Java.
 * 
 * Key concepts:
 * - Java has 8 primitive data types
 * - Each type has specific size, range, and default value
 * - Java supports Unicode characters (unlike C++ which only supports ASCII)
 * - Boolean in Java is true/false (not 0/1 like in C++)
 */
public class DataType {

    /**
     * Main method demonstrating primitive data type declarations.
     * 
     * @param args Command line arguments
     */
    public static void main(String[] args) {

        /*
         * FUNDAMENTAL CONCEPTS OF DATA IN PROGRAMMING:
         * 
         * 1. Data is the core ingredient of any program
         * - Programs are designed to process, manipulate, and transform data
         * - Without data, programs would have no purpose or functionality
         * 
         * 2. Program resides in memory (RAM)
         * - When a program runs, it loads into computer memory
         * - Memory provides fast access to data and instructions
         * - Different memory locations store different types of information
         * 
         * 3. Program operates on data
         * - Programs read, process, calculate, and output data
         * - Data flows through the program from input to output
         * - Operations include arithmetic, logical, and comparison operations
         * 
         * 4. Data stores in variables
         * - Variables are named memory locations that hold data
         * - Each variable has a specific name and can store one value at a time
         * - Variables act as containers for different types of data
         * 
         * 5. Variables have their types
         * - Data types define what kind of data a variable can store
         * - Types determine the size, range, and operations allowed on the data
         * - Java is a strongly-typed language (type safety is enforced)
         * 
         * 6. Types are defined below
         * - Java provides 8 primitive data types for basic operations
         * - Each type has specific characteristics and use cases
         * - Understanding types is crucial for efficient programming
         */
        System.out.println("=== Java Primitive Data Types ===");
        System.out.println("Understanding the foundation of data storage in Java\n");

        /*
         * PRIMITIVE DATA TYPES OVERVIEW:
         * 
         * Primitive data types are the core part of the Java compiler and runtime
         * system.
         * They are the most basic data types built directly into the Java language.
         * 
         * Key Characteristics:
         * - They represent simple values such as numbers, characters, and boolean
         * values
         * - Java has exactly 8 primitive data types: byte, short, int, long, float,
         * double, char, and boolean
         * - These types are NOT objects (unlike String, which is an object)
         * - They store their values directly in memory, providing efficient memory
         * usage and fast access
         * - They have fixed sizes and ranges, making them predictable and reliable
         * - They are the building blocks for more complex data structures
         * 
         * Categories:
         * 1. Integer Types: byte, short, int, long (whole numbers)
         * 2. Floating-Point Types: float, double (decimal numbers)
         * 3. Character Type: char (single characters)
         * 4. Boolean Type: boolean (true/false values)
         * 
         * Why Primitives Matter:
         * - Performance: Direct memory access without object overhead
         * - Memory Efficiency: Fixed, predictable memory usage
         * - Simplicity: Easy to understand and use
         * - Foundation: Basis for all other data structures in Java
         */

        // ===== INTEGER DATA TYPES =====
        System.out.println("\n1. Integer Data Types:");

        /*
         * Byte data type
         * 
         * Definition: Byte is the smallest integer data type in Java, representing
         * 8-bit signed integers.
         * 
         * Characteristics:
         * - Size: 1 byte (8 bits)
         * - Range: -128 to 127 (2^7 to 2^7-1)
         * - Default value: 0
         * - Wrapper class: Byte
         * - Memory efficient for small numbers
         * - Commonly used for file I/O operations and network protocols
         * 
         * Use cases: File handling, network programming, memory-constrained
         * applications
         * All methods command: "javap java.lang.Byte"
         */
        byte b;
        System.out.println(String.format("Byte:\n\tMinValue: %d\n\tMaxValue: %d\n\tSize: %d bytes\n",
                Byte.MIN_VALUE, Byte.MAX_VALUE, Byte.SIZE));

        /*
         * Short data type
         * 
         * Definition: Short is a 16-bit signed integer data type, larger than byte but
         * smaller than int.
         * 
         * Characteristics:
         * - Size: 2 bytes (16 bits)
         * - Range: -32,768 to 32,767 (2^15 to 2^15-1)
         * - Default value: 0
         * - Wrapper class: Short
         * - Memory efficient for medium-range integers
         * - Less commonly used in modern Java applications
         * 
         * Use cases: Legacy systems, memory optimization, arrays with known small
         * ranges
         * All methods command: "javap java.lang.Short"
         */
        short s;
        System.out.println(String.format("Short:\n\tMinValue: %d\n\tMaxValue: %d\n\tSize: %d bytes\n",
                Short.MIN_VALUE, Short.MAX_VALUE, Short.SIZE));

        /*
         * Integer data type
         * 
         * Definition: Integer is the most commonly used integer data type in Java,
         * representing 32-bit signed integers.
         * 
         * Characteristics:
         * - Size: 4 bytes (32 bits)
         * - Range: -2,147,483,648 to 2,147,483,647 (2^31 to 2^31-1)
         * - Default value: 0
         * - Wrapper class: Integer
         * - Default choice for most integer operations
         * - Optimized by JVM for performance
         * - Used in array indexing, loops, and mathematical operations
         * 
         * Use cases: General-purpose integer operations, array indices, counters,
         * mathematical calculations
         * All methods command: "javap java.lang.Integer"
         */
        int i;
        System.out.println(String.format("Integer:\n\tMinValue: %d\n\tMaxValue: %d\n\tSize: %d bytes\n",
                Integer.MIN_VALUE, Integer.MAX_VALUE, Integer.SIZE));

        /*
         * Long data type
         * 
         * Definition: Long is the largest integer data type in Java, representing
         * 64-bit signed integers.
         * 
         * Characteristics:
         * - Size: 8 bytes (64 bits)
         * - Range: -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 (2^63 to
         * 2^63-1)
         * - Default value: 0L (note the 'L' suffix)
         * - Wrapper class: Long
         * - Used for very large numbers beyond int range
         * - Requires 'L' or 'l' suffix for literals
         * - Essential for timestamps, large calculations, and scientific computing
         * 
         * Use cases: Timestamps, large mathematical calculations, scientific computing,
         * database IDs
         * All methods command: "javap java.lang.Long"
         */
        long l;
        System.out.println(String.format("Long:\n\tMinValue: %d\n\tMaxValue: %d\n\tSize: %d bytes\n",
                Long.MIN_VALUE, Long.MAX_VALUE, Long.SIZE));

        // ===== FLOATING POINT DATA TYPES =====
        System.out.println("\n2. Floating Point Data Types:");

        /*
         * Float data type
         * 
         * Definition: Float is a single-precision 32-bit floating-point data type
         * following IEEE 754 standard.
         * 
         * Characteristics:
         * - Size: 4 bytes (32 bits)
         * - Precision: ~7 decimal digits
         * - Default value: 0.0f (note the 'f' suffix)
         * - Wrapper class: Float
         * - Single-precision floating-point
         * - Requires 'f' or 'F' suffix for literals
         * - Less precise than double but uses less memory
         * - Can represent very large and very small numbers
         * 
         * Use cases: Graphics programming, scientific calculations where memory is
         * limited, embedded systems
         * All methods command: "javap java.lang.Float"
         */
        float f;
        System.out.println(String.format("Float:\n\tMinValue: %e\n\tMaxValue: %e\n\tSize: %d bytes\n",
                Float.MIN_VALUE, Float.MAX_VALUE, Float.SIZE));

        /*
         * Double data type
         * 
         * Definition: Double is a double-precision 64-bit floating-point data type
         * following IEEE 754 standard.
         * 
         * Characteristics:
         * - Size: 8 bytes (64 bits)
         * - Precision: ~15 decimal digits
         * - Default value: 0.0d (or just 0.0, 'd' is optional)
         * - Wrapper class: Double
         * - Double-precision floating-point
         * - Default choice for decimal numbers in Java
         * - Higher precision than float
         * - Used by default for floating-point literals
         * 
         * Use cases: Financial calculations, scientific computing, general decimal
         * arithmetic, default choice for decimals
         * All methods command: "javap java.lang.Double"
         */
        double d;
        System.out.println(String.format("Double:\n\tMinValue: %e\n\tMaxValue: %e\n\tSize: %d bytes\n",
                Double.MIN_VALUE, Double.MAX_VALUE, Double.SIZE));

        // ===== CHARACTER DATA TYPE =====
        System.out.println("\n3. Character Data Type:");

        /*
         * Character data type
         * 
         * Definition: Character is a 16-bit Unicode character data type that can
         * represent any character from the Unicode character set.
         * 
         * Characteristics:
         * - Size: 2 bytes (16 bits)
         * - Range: 0 to 65,535 (Unicode code points)
         * - Default value: '\u0000' (null character)
         * - Wrapper class: Character
         * - Supports international characters (Hebrew, Japanese, Chinese, Arabic, etc.)
         * - Unicode is a superset of ASCII
         * - Unlike C++ which only supports ASCII (0-127)
         * - Can represent emojis, mathematical symbols, and special characters
         * 
         * Use cases: Text processing, internationalization, user interface development,
         * string manipulation
         * All methods command: "javap java.lang.Character"
         */
        char c;
        System.out.println(String.format("Character:\n\tMinValue: %d\n\tMaxValue: %d\n\tSize: %d bytes\n",
                (int) Character.MIN_VALUE, (int) Character.MAX_VALUE, Character.SIZE));
        System.out.println("   - Supports international characters (Hebrew, Japanese, etc.)");
        System.out.println("   - Unicode is a superset of ASCII");

        // ===== BOOLEAN DATA TYPE =====
        System.out.println("\n4. Boolean Data Type:");

        /*
         * Boolean data type
         * 
         * Definition: Boolean is a logical data type that can only hold two values:
         * true or false.
         * 
         * Characteristics:
         * - Size: Not precisely defined (typically 1 bit, but JVM dependent)
         * - Values: true or false (keywords, not numbers)
         * - Default value: false
         * - Wrapper class: Boolean
         * - Unlike C++ which uses 0/1 for boolean values
         * - Used for conditional statements and logical operations
         * - Cannot be converted to/from integers like in C/C++
         * - Essential for control flow and decision making
         * 
         * Use cases: Conditional statements, loops, logical operations, flags, decision
         * making
         * All methods command: "javap java.lang.Boolean"
         */
        boolean bool;
        System.out.println("Boolean:");
        System.out.println("\tValues: true or false (not 0/1 like C++)");
        System.out.println("\tSize: JVM dependent (typically 1 bit)");
        System.out.println("\tDefault value: false");

        System.out.println("\n=== All primitive data types declared successfully! ===");

        /*
         * SUMMARY AND BEST PRACTICES:
         * 
         * 1. Choosing the Right Data Type:
         * - Use 'int' for most integer operations (default choice)
         * - Use 'long' for very large numbers or timestamps
         * - Use 'double' for most decimal calculations (default choice)
         * - Use 'float' only when memory is critical
         * - Use 'byte' and 'short' for memory optimization in large arrays
         * - Use 'char' for single characters and Unicode support
         * - Use 'boolean' for logical operations and conditions
         * 
         * 2. Memory Considerations:
         * - Primitives use less memory than objects
         * - Choose the smallest type that fits your data range
         * - Consider memory usage in large collections
         * 
         * 3. Performance Tips:
         * - Primitives are faster than wrapper classes
         * - Use primitives in loops and calculations
         * - Avoid unnecessary boxing/unboxing operations
         * 
         * 4. Type Safety:
         * - Java enforces type checking at compile time
         * - Cannot assign incompatible types
         * - Use explicit casting when necessary
         */

        System.out.println("\n📚 LEARNING RESOURCES:");
        System.out.println("💡 Tip: Use 'javap java.lang.<WrapperClass>' to explore methods for each data type!");
        System.out.println("🔍 Example commands:");
        System.out.println("   javap java.lang.Integer");
        System.out.println("   javap java.lang.Double");
        System.out.println("   javap java.lang.Character");
        System.out.println("\n🎯 Next Steps: Learn about wrapper classes, type casting, and data type conversions!");
    }
}
