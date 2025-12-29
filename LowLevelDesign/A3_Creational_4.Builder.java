package LowLevelDesign;

/*
 * The Builder Design Pattern is a creational pattern used to construct complex
 * objects step-by-step. It allows you to produce different types and
 * representations of an object using the same construction code.
 */

/*
 * Simple Definition
 *      Imagine you are at Subway.
 * 
 *          You don't just ask for a "Sandwich" and get a random one.
 * 
 *          Instead, the employee follows a process:
 *              Choose bread.
 *              Choose protein.
 *              Choose cheese.
 *              Add veggies.
 * 
 *          Some people want cheese, others don't. Some want 5 types of veggies, others
 *      want none.
 * 
 * The Builder Pattern prevents you from having a "Monster Constructor" with 20
 * parameters where half of them are null.
 */

// 2. The Problem: "The Telescoping Constructor"
// Without a builder, if your object has many optional fields, your class looks like this:

// ❌ BAD: Hard to read, hard to maintain, easy to mix up parameters
/*
    public User(String name) { ... }
    public User(String name, String email) { ... }
    public User(String name, String email, int age) { ... }
    public User(String name, String email, int age, String phone) { ... }
*/

// When you call new User("Alice", null, 0, "555-0123"), it’s hard to tell what the 0 or null represents.

// 3. The Solution: Builder Pattern

// ✅ GOOD: Clear, readable, and maintainable
public class User {
    private final String name;
    private final String email;
    private final int age;
    private final String phone;

    public static class Builder {
        private String name;
        private String email;
        private int age;
        private String phone;

        public Builder(String name) {
            this.name = name;
        }

        public Builder email(String email) {
            this.email = email;
            return this;
        }

        public Builder age(int age) {
            this.age = age;
            return this;
        }

        public Builder phone(String phone) {
            this.phone = phone;
            return this;
        }

        public User build() {
            return new User(this);
        }
    }

    private User(Builder builder) {
        this.name = builder.name;
        this.email = builder.email;
        this.age = builder.age;
        this.phone = builder.phone;
    }

    @Override
    public String toString() {
        return String.format("User{Name: %s, Age: %d, Email: %s, Phone: %s", this.name, this.age, this.email, this.phone);
    }
}

class TestUser {
    public static void main(String[] args) {
        User user = new User.Builder("John Doe")
                .email("john.doe@example.com")
                .age(30)
                .phone("123-456-7890")
                .build();

        System.out.println(user);
    }
}