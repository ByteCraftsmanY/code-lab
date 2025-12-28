package LowLevelDesign;

/*
 * The Template Method Pattern is a behavioral design pattern that defines the
 * skeleton of an algorithm in a base class but lets subclasses override
 * specific steps of the algorithm without changing its structure.
 */

/*
 * 1. Simple Definition
 *      Imagine you are following a Cooking Recipe. The recipe says:
 *          Boil water.
 *          Add main ingredient.
 *          Cook for 10 minutes.
 *          Serve in a bowl.
 *      The "Template" is the set of steps. You can change the "Main Ingredient"
 *      (Pasta vs. Rice), but you cannot change the order of the steps.
 */

// Example:
class JsonParser {
    public void openFile() {
        System.out.println("Opening file");
    }

    public void parse() {
        this.openFile();
        System.out.println("Parsing JSON file");
        this.closeFile();
    }

    public void closeFile() {
        System.out.println("Closing file");
    }
}

class CSVParser {
    public void openFile() {
        System.out.println("Opening file");
    }

    public void parse() {
        this.openFile();
        System.out.println("Parsing CSV file");
        this.closeFile();
    }

    public void closeFile() {
        System.out.println("Closing file");
    }
}

/*
 * Problem:
 * 1. open and close file is same for both classes.
 * 2. The code is duplicated in both classes.
 * 3. it may be possible that we forgot to open/close file
 * 
 * Solution:
 * 1. Create a base class with template method
 * 2. Create a sub class for each file type
 */

// Example:

abstract class Parser {
    public final void parse() {
        this.openFile();
        this.parseData();
        this.closeFile();
    }

    protected void openFile() {
        System.out.println("Opening file");
    }

    abstract protected void parseData();

    protected void closeFile() {
        System.out.println("Closing file");
    }
}

class JsonParser2 extends Parser {
    @Override
    protected void parseData() {
        System.out.println("Parsing JSON file");
    }
}

class CSVParser2 extends Parser {
    @Override
    protected void parseData() {
        System.out.println("Parsing CSV file");
    }
}

class TestTemplate {
    public static void main(String[] args) {
        Parser parser = new JsonParser2();
        parser.parse();

        parser = new CSVParser2();
        parser.parse();
    }
}