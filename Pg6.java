import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class Phone extends JFrame implements ActionListener{

    //JButton bt = new JButton("submit");
        JTextField input = new JTextField();
        JButton cbtn;
    Phone(){
        setSize(400,400);
        setLayout(new GridLayout(5,5));
        input.addActionListener(this);
        add(input);
        input.setEditable(false);
        String[] buttons = {"1","2","3","4","5","6","7","8","9","CLEAR","0","CALL"};

        for(String s: buttons){
            JButton b = new JButton(s);
            b.addActionListener(this);
            add(b);
            if(s=="CALL"){
                cbtn = b;
            }
        }
    }

    public void actionPerformed(ActionEvent e){
        String cmd = e.getActionCommand();

        if(cmd=="CLEAR"){
            input.setText("");
        }else if(cmd == "CALL"){
            cbtn.setText("HANG UP");
        }else if(cmd =="HANG UP"){
            cbtn.setText("CALL");
        }else{
            input.setText(input.getText()+cmd);
        }
    }
}


public class Pg6{
    public static void main(String[] args){
        Phone p = new Phone();
        p.setVisible(true);
    }
}