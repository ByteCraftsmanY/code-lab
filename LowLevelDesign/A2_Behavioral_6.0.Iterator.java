package LowLevelDesign;

/*
 * The Iterator Design Pattern is a behavioral pattern that lets you access the
 * elements of a collection (like a List, Stack, or Tree) sequentially without
 * exposing the underlying complexity of how that collection is stored.
 * 
 * 1. Simple Definition
 * Imagine you have a Library. The books might be kept on shelves, in a basement
 * box, or on a digital server.
 * 
 * As a reader, you don't want to know where or how the books are stored. You
 * just want a way to say "Give me the next book" until you’ve seen them all.
 * The "Librarian" acts as the Iterator—they handle the logic of finding the
 * next item while you just focus on reading.
 * 
 * 2. The Problem: Tight Coupling
 * If you have a collection stored as a Binary Tree, and your client code uses a
 * for loop that specifically traverses a tree, what happens if you change that
 * tree to a LinkedList?
 * 
 * The Problem: Your client code breaks because it was tied to the structure of
 * the collection.
 * 
 * The Solution: Use an Iterator. The client only asks for next(), regardless of
 * whether the data is in a tree, list, or array.
 */

import java.util.*;

// Problem
class Book {
    private String title;
    private String author;

    public Book(String title, String author) {
        this.title = title;
        this.author = author;
    }

    public String getTitle() {
        return title;
    }

    public String getAuthor() {
        return author;
    }
}

class BookCollection {
    // if we change data type from list to any other such as set then current
    // implementation will be break
    private final List<Book> books;

    public BookCollection() {
        books = new ArrayList<>();
    }

    public void addBook(Book book) {
        books.add(book);
    }

    public List<Book> getBooks() {
        return books;
    }
}

class Library {
    private final BookCollection bookCollection;

    public Library(BookCollection bookCollection) {
        this.bookCollection = bookCollection;
    }

    public void printBooks() {
        // If we change collection container from list to set this will break
        List<Book> books = bookCollection.getBooks();
        for (int i = 0; i < books.size(); i++) {
            Book book = books.get(i);
            // for (Book book : bookCollection.getBooks()) {
            System.out.println(book.getTitle() + " by " + book.getAuthor());
        }
    }
}

class TestLibrary {
    public static void main(String[] args) {
        BookCollection bookCollection = new BookCollection();
        bookCollection.addBook(new Book("Book 1", "Author 1"));
        bookCollection.addBook(new Book("Book 2", "Author 2"));

        Library library = new Library(bookCollection);
        library.printBooks();
    }
}

// Solution
class Book2 implements Comparable<Book2> {
    private final String title, author;

    public Book2(String title, String author) {
        this.title = title;
        this.author = author;
    }

    public String getTitle() {
        return this.title;
    }

    public String getAuthor() {
        return this.author;
    }

    @Override
    public int compareTo(Book2 o) {
        return this.title.compareTo(o.getTitle());
    }

    @Override
    public String toString() {
        return "Book: " + this.title + " by " + this.author;
    }
}

class BookCollection2 implements Iterable<Book2> {
    private final Set<Book2> books;

    public BookCollection2() {
        this.books = new TreeSet<>();
    }

    public void addBook(Book2 book) {
        this.books.add(book);
    }

    @Override
    public Iterator<Book2> iterator() {
        // return new BookIterator();
        return books.iterator(); // no need to implement BookIterator class
    }

    // private class BookIterator implements Iterator<Book2> {
    // private int position = 0;
    //
    // @Override
    // public boolean hasNext() {
    // return position < books.size();
    // }
    //
    // @Override
    // public Book2 next() {
    // return books.get(position++);
    // }
    // }
}

class Library2 {
    private final BookCollection2 bookCollection;

    public Library2(BookCollection2 bookCollection) {
        this.bookCollection = bookCollection;
    }

    public void printBooks() {
        Iterator<Book2> itr = bookCollection.iterator();
        while (itr.hasNext()) {
            System.out.println(itr.next());
        }
    }
}

class TestLibrary2 {
    static void main() {
        BookCollection2 bookCollection2 = new BookCollection2();
        bookCollection2.addBook(new Book2("vd", "T1"));
        bookCollection2.addBook(new Book2("a", "T2"));

        Library2 lib = new Library2(bookCollection2);
        lib.printBooks();

    }
}