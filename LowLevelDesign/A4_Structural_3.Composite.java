package LowLevelDesign;

import java.util.ArrayList;
import java.util.List;

/*
    The Composite Design Pattern is a structural pattern used when you need to treat a single object and a group of objects in the same way.

    It is the go-to pattern for representing tree-like structures.

    1. Simple Definition
        Imagine a File System.

        You have Files.

           You have Folders.

        A Folder can contain Files AND other Folders.

    If you want to find the "Total Size," you don't want to write different logic for a file vs. a folder. You just want to call .getSize() on any item, and if it's a folder, it should automatically sum up the sizes of everything inside it.
*/

/*
    2. The Problem
        Without the Composite pattern, you would have to check the type of every object
        before performing an action: if (item is Folder) { loop through children } 
        else { get file size }. This makes your code complex and hard to maintain as 
        your tree grows.
*/

// Component
interface FileSystemComponent {
    void showDetails(String indent);
}

// Leaf
class File implements FileSystemComponent {
    private String name;

    public File(String name) {
        this.name = name;
    }

    @Override
    public void showDetails(String indent) {
        System.out.println(indent + "File: " + name);
    }
}

// Composite
class Directory implements FileSystemComponent {
    private String name;
    private List<FileSystemComponent> components;

    public Directory(String name) {
        this.name = name;
        this.components = new ArrayList<>();
    }

    public void addComponent(FileSystemComponent component) {
        components.add(component);
    }

    public void removeComponent(FileSystemComponent component) {
        components.remove(component);
    }

    @Override
    public void showDetails(String indent) {
        System.out.println(indent + "Directory: " + name);
        for (FileSystemComponent component : components) {
            component.showDetails(indent + "    ");
        }
    }
}

// Client
class CompositePatternTest {
    public static void main(String[] args) {
        // Create leaf nodes
        FileSystemComponent file1 = new File("File1.txt");
        FileSystemComponent file2 = new File("File2.txt");
        FileSystemComponent file3 = new File("Picture.png");

        // Create composite nodes
        Directory directory1 = new Directory("Documents");
        Directory directory2 = new Directory("Images");
        Directory rootDirectory = new Directory("Root");

        // Build the tree structure
        directory1.addComponent(file1);
        directory1.addComponent(file2);

        directory2.addComponent(file3);

        rootDirectory.addComponent(directory1);
        rootDirectory.addComponent(directory2);

        // Show details
        System.out.println("--- File System Tree ---");
        rootDirectory.showDetails("");
    }
}