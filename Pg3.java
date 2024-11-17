import java.util.*;

public class Complex{
    double real;
    double imag;
    Complex(double real, double imag){
        this.real = real;
        this.imag = imag;
    }

    Complex add(Complex other){
        double r = this.real + other.real;
        double i = this.imag + other.imag;

        return new Complex(r,i);
    }

    Complex sub(Complex other){
        double r = this.real - other.real;
        double i = this.imag - other.imag;

        return new Complex(r,i);
    }
}



public class Pg3{
    public static void main(){

    }
}