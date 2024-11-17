import java.util.*;


class Stack{
    int top=-1;
    int stackSize;
    int[] stackArray;

    Stack(int size){
        stackSize = size;
        stackArray = new int[size];
    }
    void push(int data){
        if(top==stackSize-1){
            System.out.println("queue full");
        }else{
        top++;
        stackArray[top]=data;
        }

    }

    int pop(){
        if(top==-1){
            System.out.println("queue empty");
            return 0;
        }else{

        int data = stackArray[top];
        top--;
        return data;
        }
    }
}

public class Pg4{
    public static void main(String[] args){
        int act=-1;
        Stack s = new Stack(20);
        Scanner ss = new Scanner(System.in);
        do{
            System.out.println("1.push\t2.pop\n");
            act = ss.nextInt();
            switch(act){
                case 1:{
                    int data = ss.nextInt();
                    s.push(data);
                };break;
                case 2:{
                    System.out.println("delted data is: "+s.pop());
                };break;
            }

        }while(act!=3);
    }
}