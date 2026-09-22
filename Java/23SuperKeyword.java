// super keyword
class Parent {
    int age = 45;
}
class Child extends Parent {
    int age = 12;
    void show(){
        System.out.println(age);
        System.out.println(super.age);
    }
}
public class Main {
    public static void main(String[] args) {
        Child ch = new Child();
        ch.show();
    }
}