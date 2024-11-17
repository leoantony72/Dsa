import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class Prime extends JFrame implements ActionListener{

    JTextField input = new JTextField();
    JTextField output = new JTextField();
    JButton bt = new JButton("submit");
    Prime(){
        setSize(400,400);
        setLayout(new GridLayout(3,1));
        bt.addActionListener(this);
        add(bt);
        add(input);
        add(output);
    }

    public static boolean isPrime(int num) {
        if (num <= 1) {
            return false;
        }

        for (int i = 2; i <= Math.sqrt(num); i++) {
            if (num % i == 0) {
                return false;
            }
        }

        return true;
    }

    public void actionPerformed(ActionEvent e){
        if(e.getSource()==bt){
            String val = input.getText();
            int ival = Integer.parseInt(val);

            if(isPrime(ival)){
                output.setText("true");
            }else{
                output.setText("false");

            }
        }
    }
}


public class Pg5{
    public static void main(String[] args){
        Prime p = new Prime();
        p.setVisible(true);
    }
}