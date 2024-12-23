import java.util.Scanner;

class AgeOutOfRangeException1 extends Exception {
    public AgeOutOfRangeException1(int age) {
        System.out.println("You are older than the requested age (25 years), you are " + age + " years old.");
    }
}
class LowGpaException1 extends Exception {
    public LowGpaException1() {
        System.out.println( "Your GPA is not sufficient to apply for this job (2.5)");
    }
}
public class age {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        try{
            int age = sc.nextInt();
            if(age > 25)
                throw new AgeOutOfRangeException1(age);
        }
        catch(AgeOutOfRangeException1 e) {
            return;
        }
        try{
            double gpa = sc.nextDouble();
            if(gpa<2.5)
                throw new LowGpaException1();
        }
        catch (LowGpaException1 e){
            return;}
        System.out.println("Your application is accepted and is under study");
    }
}
