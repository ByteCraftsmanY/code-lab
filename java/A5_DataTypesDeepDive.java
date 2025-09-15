public class A5_DataTypesDeepDive {
    public static void main(String[] args) {

        /*
         * ===========================================
         * INTEGRAL DATA TYPES IN JAVA
         * ===========================================
         * 
         * Integral data types are used to store whole numbers without decimal points.
         * They include: byte, short, int, and long.
         * 
         * Historical Context:
         * - When Java was introduced, 32-bit was the standard for all platforms
         * - 32-bit processors were commonly available at that time
         * - byte and short were available to support backward software compatibility
         * for programs written in 16-bit or similar architectures
         * - 64-bit was not available in those days, but long was introduced for future
         * use
         * 
         * Performance Considerations:
         * - Although byte and short may over-utilize CPU cycles, they help reduce
         * memory usage
         * - int and long are used to store larger numbers efficiently
         * - int is 32-bit and long is 64-bit
         * 
         * Default Behavior:
         * - int is the default data type for whole numbers
         * - long is the default data type for large whole numbers
         */

        /*
         * ===========================================
         * SIGNED INTEGER REPRESENTATION
         * ===========================================
         * 
         * Integer numbers are stored with a sign bit:
         * - 0 means positive
         * - 1 means negative
         * 
         * Negative numbers are stored in 2's complement form.
         * 
         * Example:
         * +5 = 00000000000000000000000000000101
         * -5 = 11111111111111111111111111111011
         * 
         * 2's Complement Form:
         * This is a mathematical way to represent negative numbers in binary.
         * It is calculated by:
         * 1. Inverting all the bits (1 becomes 0, 0 becomes 1)
         * 2. Adding 1 to the result
         * 
         * Benefits:
         * - Allows simple addition/subtraction operations
         * - Eliminates the need for separate negative number handling
         */

        // Demonstrate integer representation
        System.out.println("===========================================");
        System.out.println("INTEGER REPRESENTATION DEMONSTRATION");
        System.out.println("===========================================");

        int positiveNumber = 5;
        int negativeNumber = -5;

        System.out.println(String.format("Positive Number: %+d", positiveNumber));
        System.out.println(String.format("Binary Representation: %32s",
                String.format("%32s", Integer.toBinaryString(positiveNumber)).replace(' ', '0')));

        System.out.println();

        System.out.println(String.format("Negative Number: %d", negativeNumber));
        System.out.println(String.format("Binary Representation: %s",
                Integer.toBinaryString(negativeNumber)));

        System.out.println();

        // Show range of int data type
        System.out.println("===========================================");
        System.out.println("INT DATA TYPE RANGE");
        System.out.println("===========================================");
        System.out.println("Minimum value: " + Integer.MIN_VALUE);
        System.out.println("Maximum value: " + Integer.MAX_VALUE);
        System.out.println("Size in bits: " + Integer.SIZE);
        System.out.println("===========================================");

        /*
         * ===========================================
         * FLOATING-POINT DATA TYPES
         * ===========================================
         * 
         * Float and double are used to store decimal numbers.
         * They are stored in IEEE 754 floating-point format, not in binary form.
         * 
         * IEEE 754 Format:
         * - Sign bit (1 bit): 0 for positive, 1 for negative
         * - Exponent (8 bits for float, 11 bits for double)
         * - Mantissa (23 bits for float, 52 bits for double)
         * 
         * Scientific Notation:
         * 3.14 = 3.14 × 10^0 = 314 × 10^(-2) | 314e-2
         * Where 314 is the mantissa and -2 is the exponent
         */

        // Demonstrate float and double representation
        System.out.println("===========================================");
        System.out.println("FLOAT AND DOUBLE REPRESENTATION DEMONSTRATION");
        System.out.println("===========================================");

        float floatNumber = 3.14f;
        double doubleNumber = 3.14;

        System.out.println(String.format("Float Number: %f", floatNumber));
        System.out.println(String.format("Float in Hex: %s", Float.toHexString(floatNumber)));
        System.out
                .println(String.format("Float bits: %s", Integer.toBinaryString(Float.floatToRawIntBits(floatNumber))));

        System.out.println();

        System.out.println(String.format("Double Number: %f", doubleNumber));
        System.out.println(String.format("Double in Hex: %s", Double.toHexString(doubleNumber)));
        System.out.println(
                String.format("Double bits: %s", Long.toBinaryString(Double.doubleToRawLongBits(doubleNumber))));

        /*
         * ===========================================
         * CHARACTER DATA TYPE
         * ===========================================
         * 
         * char in Java is a 16-bit Unicode character.
         * Unicode is an international standard for character encoding.
         * 
         * ASCII vs Unicode:
         * - ASCII: 7-bit encoding (0-127), covers basic English characters
         * - Unicode: 16-bit encoding, covers characters from all world languages
         * 
         * ASCII Ranges:
         * - A-Z: 65-90
         * - a-z: 97-122
         * - 0-9: 48-57
         * - Special characters: 32-47, 58-64, 91-96, 123-127
         * 
         * Unicode includes ASCII as a subset and extends to support:
         * - European languages
         * - Asian languages (Chinese, Japanese, Korean)
         * - Middle Eastern languages
         * - Mathematical symbols
         * - Emojis and special characters
         * 
         * Reference: https://home.unicode.org/
         */

        // Demonstrate unicode representation of char
        System.out.println("===========================================");
        System.out.println("CHAR REPRESENTATION DEMONSTRATION");
        System.out.println("===========================================");

        char char1 = 'A';
        char char2 = 'B';
        char char3 = '中'; // Chinese character

        System.out.println(String.format("Char1: %c (ASCII: %d)", char1, (int) char1));
        System.out.println(String.format("Binary Representation: %16s",
                String.format("%16s", Integer.toBinaryString(char1)).replace(' ', '0')));

        System.out.println();

        System.out.println(String.format("Char2: %c (ASCII: %d)", char2, (int) char2));
        System.out.println(String.format("Binary Representation: %16s",
                String.format("%16s", Integer.toBinaryString(char2)).replace(' ', '0')));

        System.out.println();

        System.out.println(String.format("Char3: %c (Unicode: %d)", char3, (int) char3));
        System.out.println(String.format("Binary Representation: %16s",
                String.format("%16s", Integer.toBinaryString(char3)).replace(' ', '0')));

        /*
         * ===========================================
         * BOOLEAN DATA TYPE
         * ===========================================
         * 
         * boolean is used to store true or false values.
         * 
         * Important Notes:
         * - In Java, boolean is NOT a 1-bit data type
         * - The actual size depends on the JVM implementation
         * - Typically, boolean values are stored as 8-bit values (1 byte)
         * - true is typically represented as 1, false as 0
         * - However, the internal representation is JVM-specific
         * 
         * Boolean values cannot be directly converted to binary strings
         * using Integer.toBinaryString() as they are not integers.
         */

        // Demonstrate boolean data type
        System.out.println("===========================================");
        System.out.println("BOOLEAN DATA TYPE DEMONSTRATION");
        System.out.println("===========================================");

        boolean boolean1 = true;
        boolean boolean2 = false;

        System.out.println(String.format("Boolean1: %b", boolean1));
        System.out.println(String.format("Boolean1 as int: %d", boolean1 ? 1 : 0));

        System.out.println();

        System.out.println(String.format("Boolean2: %b", boolean2));
        System.out.println(String.format("Boolean2 as int: %d", boolean2 ? 1 : 0));

        System.out.println();

        // Demonstrate data type sizes
        System.out.println("===========================================");
        System.out.println("DATA TYPE SIZES AND RANGES");
        System.out.println("===========================================");
        System.out.println("byte:  " + Byte.SIZE + " bits, Range: " + Byte.MIN_VALUE + " to " + Byte.MAX_VALUE);
        System.out.println("short: " + Short.SIZE + " bits, Range: " + Short.MIN_VALUE + " to " + Short.MAX_VALUE);
        System.out
                .println("int:   " + Integer.SIZE + " bits, Range: " + Integer.MIN_VALUE + " to " + Integer.MAX_VALUE);
        System.out.println("long:  " + Long.SIZE + " bits, Range: " + Long.MIN_VALUE + " to " + Long.MAX_VALUE);
        System.out.println("float: " + Float.SIZE + " bits");
        System.out.println("double: " + Double.SIZE + " bits");
        System.out.println("char:  " + Character.SIZE + " bits");
        System.out.println("===========================================");
    }
}
