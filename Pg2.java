import java.util.*;


class Date{
    int dd;
    int mm;
    int yy;

    Date(){
        dd= 17;
        mm=11;
        yy=2024;
    }
    Date(int d, int m , int y){
        dd=d;
        mm=m;
        yy=y;
    }

    boolean isLeap(){
         if (yy % 4 == 0) {
            if (yy % 100 == 0) {
                return yy % 400 == 0;
            } else {
                return true;
            }
        } else {
            return false;
        }
    }

    void print(){
        System.out.println(dd+"//"+mm+"//"+yy);
    }
}

public class Pg2{
    public static void main(String[] args){
        Date d = new Date();
        Date d2 = new Date(3,5,1900);

        boolean a=d.isLeap();
        boolean b=d2.isLeap();

        System.out.println("d:"+a+" || b:"+b);
        d.print();
        d2.print();
    }
}