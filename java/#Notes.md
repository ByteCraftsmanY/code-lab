# Java Development Notes

## Compilation and Execution Commands

### 1. Compiling Java Files
```bash
javac <filename.java>
```
- **Purpose**: Compiles Java source code into bytecode
- **Output**: Generates `.class` files (bytecode)
- **Example**: `javac HelloWorld.java` → generates `HelloWorld.class`

### 2. Executing Java Programs
```bash
java <class_file_name_without_extension>
```
- **Purpose**: Executes the compiled bytecode using JVM
- **Note**: Don't include `.class` extension
- **Example**: `java HelloWorld` (not `java HelloWorld.class`)

### 3. Exploring Class Methods
```bash
javap <path_to_class>
```
- **Purpose**: Disassembles class files and shows available methods, fields, and constructors
- **Example**: `javap java.lang.String` - shows all methods available in String class
- **Useful for**: Understanding built-in class capabilities

## Complete Workflow Example

```bash
# Step 1: Compile the Java file
javac HelloWorld.java

# Step 2: Execute the compiled program
java HelloWorld

# Step 3: Explore String class methods (optional)
javap java.lang.String
```

## Additional javap Options

```bash
# Show all members (public, private, protected)
javap -p java.lang.String

# Show verbose information
javap -v java.lang.String

# Show only public members (default)
javap java.lang.String
```

## Project Structure Best Practices

```
java/
├── bin/                    # Compiled .class files
├── #input.txt             # Input test data
├── #output.txt            # Output test data
├── HelloWorld.java        # Source files
└── UserInput.java
```

## Compilation with Custom Output Directory

```bash
# Compile to specific directory
javac -d java/bin java/*.java

# Run from specific classpath
java -cp java/bin HelloWorld
```

## Common Issues and Solutions

1. **ClassNotFoundException**: Make sure you're using the correct class name (case-sensitive)
2. **Compilation Errors**: Check syntax and imports
3. **File Not Found**: Ensure you're in the correct directory
4. **Permission Issues**: Make sure files are readable/writable

## Useful Commands for Development

```bash
# List all .class files
ls *.class

# Remove all compiled files
rm *.class

# Compile multiple files
javac *.java

# Run with command line arguments
java HelloWorld arg1 arg2
```
