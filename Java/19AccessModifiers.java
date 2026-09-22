// Access Modifiers
class Student {
    public String name;
    private double salary;
    protected int age = 30;
    public void study() {
        System.out.println("Start");
    }
    public double getSalary(double newSalary) {
        this.salary = newSalary;
        return salary;
    }
}
class Student1 extends Student {
    void student() {
        System.out.println("HI, I am Vivek");
    }
}

public class Main {
    public static void main(String[] args) {
        System.out.println("Hello World");
        Student obj = new Student();
        obj.name = "Vivek";
        System.out.println("Name :"+ obj.name);
        obj.study();
        double s = obj.getSalary(50.000);
        System.out.println(s);
        Student1 st = new Student1();
        System.out.println(st.age);
    }
}