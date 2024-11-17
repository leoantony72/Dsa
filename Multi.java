import java.util.*;

class Oe extends Thread{
    int limit = 10;
    public void run(){
        Thread t = Thread.currentThread();
        if(t.getName()=="Odd"){
            for (int i = 1; i <= limit; i += 2) {
               System.out.println("Odd: " + i);
            }
        }else{
            for (int i = 2; i <= limit; i += 2) {
               System.out.println("Even: " + i);
            }
        }
    }
}

public class Multi{
    public static void main(String[] args){
        Oe o = new Oe();
        Oe e = new Oe();
        o.setName("Odd");
        e.setName("Even");

        o.start();

        try{
            o.join(); //waits for the ODD thread to finish (must be in a try catch)
        }catch(InterruptedException ee){
            System.out.println("something went wrong!!");
        }
        e.start();

    }
}