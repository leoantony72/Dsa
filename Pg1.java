import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class TextPS extends JFrame implements ActionListener{

        JButton button = new JButton("submit");
        JTextField f1 = new JTextField();
        JTextField prev = new JTextField();
        JTextField next = new JTextField();
    TextPS(){
        setSize(400,400);
        setTitle("prev and next");
        setLayout(new GridLayout(4,1));
        button.addActionListener(this);

        add(f1);
        add(prev);
        add(next);
        add(button);
    }

    public void actionPerformed(ActionEvent e){
        if(e.getSource()== button){
            String v = f1.getText();
            int vl = Integer.parseInt(v);
            prev.setText(String.valueOf(vl-1));
            next.setText(String.valueOf(vl+1));
        }
    }
}


public class Pg1{
    public static void main(String[] args){
        TextPS p = new TextPS();
        p.setVisible(true);
    }
}