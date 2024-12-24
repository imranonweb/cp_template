interface A {
    void show();
    int age = 21;
}
interface B {
    void print();

}
interface C extends A,B {
    void report();
}

 class D implements C {
        public void report() {
            System.out.println("I am D");
        }
        public void print() {
            System.out.println("i am c");
        }
        public void show() {
            System.out.println("my age is " + age);
        }
}
public class interface1 {
    public static void main(String[] args) {
        D obj = new D();
        obj.report();
        obj.print();
        obj.show();
    }
}
