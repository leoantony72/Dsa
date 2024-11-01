// Online Java Compiler
// Use this editor to write, compile and run your Java code online
import java.util.Scanner;
class HelloWorld {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.println("enter a string:");
        String str = s.nextLine();
        System.out.println("enter the character: ");
        char c = s.next().charAt(0);
        int freq = 0;
        for(int i=0;i<str.length();i++){
            if(str.charAt(i)==c){
                freq++;
            }
        }
        System.out.println("Freq is "+freq);
    }
}
