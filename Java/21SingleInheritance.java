// Single Inheritance
class Parent {
    void parent() {
        System.out.println("Hi, I am Parent");
    }
}
class Child extends Parent {
    void child() {
        System.out.println("Hi, I am Child");
    }
}
public class Main {
    public static void main(String[] args) {
        Child ch = new Child();
        ch.parent();
        ch.child();
    }
}