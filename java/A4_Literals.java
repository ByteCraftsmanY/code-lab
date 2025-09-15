/**
 * Literals.java
 * 
 * A comprehensive demonstration of Java literals - the values assigned to variables.
 * Shows different types of literals with practical examples.
 * 
 * @author Your Name
 * @version 1.0
 */

/**
 * Literals are the values that are assigned to the variables.
 * 
 * Java supports various literal types:
 * 1. Integer Literals (decimal, binary, octal, hexadecimal)
 * 2. Floating Point Literals (float, double)
 * 3. Character Literals (char, unicode)
 * 4. String Literals
 * 5. Boolean Literals (true, false)
 * 6. Null Literals
 */
public class A4_Literals {

    public static void main(String[] args) {

        // ===== INTEGER LITERALS =====
        System.out.println("🔢 1. INTEGER LITERALS");
        System.out.println("=".repeat(50));

        /*
         * Integer literals support multiple bases:
         * - Decimal: default (e.g., 10)
         * - Binary: prefix with '0b' or '0B' (e.g., 0b1010)
         * - Octal: prefix with '0' (e.g., 012)
         * - Hexadecimal: prefix with '0x' or '0X' (e.g., 0x1a)
         */

        int decimal = 10; // decimal literal
        int binary = 0b1010; // binary literal (10 in decimal)
        int octal = 012; // octal literal (10 in decimal)
        int hex = 0x1a; // hexadecimal literal (26 in decimal)

        System.out.println("Decimal: " + decimal);
        System.out.println("Binary 0b1010: " + binary);
        System.out.println("Octal 012: " + octal);
        System.out.println("Hex 0x1a: " + hex);

        // ===== BYTE, SHORT, INT, LONG LITERALS =====
        System.out.println("\n🔢 2. INTEGER TYPE LITERALS");
        System.out.println("=".repeat(50));

        /*
         * Java uses int by default for integer literals.
         * Long literals require 'L' or 'l' suffix.
         * Underscores can be used for readability in large numbers.
         */

        byte byteVal = 127; // byte literal
        short shortVal = 32767; // short literal
        int intVal = 2147483647; // int literal
        long longVal = 9223372036854775807L; // long literal
        int readableInt = 1_000_000; // underscore for readability

        System.out.println("Byte: " + byteVal);
        System.out.println("Short: " + shortVal);
        System.out.println("Int: " + intVal);
        System.out.println("Long: " + longVal);
        System.out.println("Readable Int: " + readableInt);

        // ===== FLOATING POINT LITERALS =====
        System.out.println("\n🔢 3. FLOATING POINT LITERALS");
        System.out.println("=".repeat(50));

        /*
         * Java uses double by default for floating point literals.
         * Float literals require 'f' or 'F' suffix.
         * Scientific notation uses 'e' or 'E' (e.g., 1.5e3 = 1500.0).
         * Double literals can have optional 'd' or 'D' suffix.
         */

        float floatVal = 10.5f; // float literal
        double doubleVal = 10.5; // double literal (default)
        double doubleVal2 = 10.5d; // double literal (default)
        double doubleVal3 = 10.5D; // double literal (default)
        double scientific = 1.5e3; // scientific notation (1500.0)

        System.out.println("Float: " + floatVal);
        System.out.println("Double: " + doubleVal);
        System.out.println("Double 10.5d: " + doubleVal2);
        System.out.println("Double 10.5D: " + doubleVal3);
        System.out.println("Scientific 1.5e3: " + scientific);

        // ===== CHARACTER LITERALS =====
        System.out.println("\n🔤 4. CHARACTER LITERALS");
        System.out.println("=".repeat(50));

        char charVal = 'a'; // character literal
        char unicodeChar = '\u0061'; // unicode literal (also 'a')

        System.out.println("Char: " + charVal);
        System.out.println("Unicode \\u0061: " + unicodeChar);

        // ===== STRING LITERALS =====
        System.out.println("\n📝 5. STRING LITERALS");
        System.out.println("=".repeat(50));

        String str1 = "Hello"; // string literal
        String str2 = "World"; // string literal

        System.out.println("String 1: " + str1);
        System.out.println("String 2: " + str2);

        // ===== BOOLEAN LITERALS =====
        System.out.println("\n✅ 6. BOOLEAN LITERALS");
        System.out.println("=".repeat(50));

        boolean trueVal = true; // boolean literal
        boolean falseVal = false; // boolean literal

        System.out.println("True: " + trueVal);
        System.out.println("False: " + falseVal);

        // ===== NULL LITERALS =====
        System.out.println("\n❌ 7. NULL LITERALS");
        System.out.println("=".repeat(50));

        Object nullObj = null; // null literal
        System.out.println("Null object: " + nullObj);
    }

}
