package LowLevelDesign;

import java.util.Stack;

/*
    Behavioral Design Pattern: How objects communicate or interact with each other

    Momento Pattern: The Memento Pattern allows an object to save its internal state so it can be restored later, without exposing its internal structure (Encapsulation).
*/

/*
    1. The Core Problem
        Imagine you are building a Text Editor. You want an "Undo" feature.
        If the Editor class handles its own history, it becomes too bulky (violating SRP).
        If an external History class tries to save the editor's state, it would need access to the editor's private fields (violating Encapsulation).
        The Memento pattern solves this by creating a "snapshot" object that only the original creator can read. 
*/

/*
    2. Key Participants
        Originator: The object that has a state and knows how to save/restore itself.
        Memento: The immutable snapshot of the state.
        Caretaker: The object that keeps the track of history but never modifies the snapshots.
 */

// Immutable snapshot of the state
public class EditorMemento {
    private final String content;

    public EditorMemento(String content) {
        this.content = content;
    }

    // Only the Originator should really use this
    public String getContent() {
        return content;
    }
}

public class Editor {
    private String content;

    public void type(String text) {
        content = text;
    }

    public String getContent() {
        return content;
    }

    // Create a snapshot
    public EditorMemento save() {
        return new EditorMemento(content);
    }

    // Restore from a snapshot
    public void restore(EditorMemento memento) {
        content = memento.getContent();
    }
}

public class History {
    private final Stack<EditorMemento> states = new Stack<>();

    public void push(EditorMemento memento) {
        states.push(memento);
    }

    public EditorMemento pop() {
        if (!states.isEmpty()) {
            return states.pop();
        }
        return null;
    }
}

public class Main {
    public static void main(String[] args) {
        Editor editor = new Editor();
        History history = new History();

        editor.type("Version 1");
        history.push(editor.save()); // Save state

        editor.type("Version 2");
        history.push(editor.save()); // Save state

        editor.type("Version 3 (Unwanted)");

        // Undo!
        editor.restore(history.pop()); // Back to Version 2
        editor.restore(history.pop()); // Back to Version 1

        System.out.println(editor.getContent()); // Output: Version 1
    }
}

/*
 * Key Benefits
 * - Undo/Redo: Perfect for implementing history in editors, games, or forms.
 * - SRP: The Originator doesn't need to manage history logic.
 * - Encapsulation: History management doesn't need to know the private fields
 * of the Editor.
 */


/*


class Editor {
    // if we add some kind of state manager here that will violate SRP
    private String content;

    public void setContent(String content) {
        this.content = content;
    }

    public String getContent() {
        return this.content;
    }

    public EditorMomento save() {
        return new EditorMomento(this.content);
    }

    public void restore(EditorMomento momento) {
        this.content = momento.getContent();
    }
}

class EditorMomento {
    private final String content;

    public EditorMomento(String content) {
        this.content = content;
    }

    public String getContent() {
        return this.content;
    }
}

class History {
    private Stack<EditorMomento> st = new Stack<>();

    public void saveState(Editor editor) {
        this.st.push(editor.save());
    }

    public void restoreState(Editor editor) {
        if (this.st.empty()) {
            return;
        }
        this.st.pop();
        editor.restore(this.st.peek());
    }
}

class main {
    static void main() {
        Editor editor = new Editor();
        History history = new History();

        editor.setContent("Hello");
        history.saveState(editor);

        editor.setContent("Bye");
        history.saveState(editor);

        System.out.println(editor.getContent());
        history.restoreState(editor);
        System.out.println(editor.getContent());

    }
}


*/