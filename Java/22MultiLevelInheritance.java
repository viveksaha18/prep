// Multi-Level Inheritance
class GrandParent {
    void GrandParent() {
        System.out.println("Hi, I am Grand Parent");
    }
}
class Parent extends GrandParent {
    void Parent() {
        System.out.println("Hi, I am Parent");
    }
}
class Child extends Parent {
    void Child() {
        System.out.println("Hi, I am Child");
    }
}
public class Main {
    public static void main(String[] args) {
        Child ch = new Child();
        ch.GrandParent();
        ch.Parent();
        ch.Child();
    }
}