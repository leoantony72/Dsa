import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class SimpleCalculatorTest extends JFrame implements ActionListener {
    private JTextField display;
    private String operator;
    private double num1, num2, result;

    public SimpleCalculatorTest() 
    {
        // Set up the frame
        setTitle("Simple Calculator");
        setSize(400, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new GridLayout(4, 4));

        // Create display
        display = new JTextField();
        display.setEditable(false);
        add(display);

        // Buttons
		String[] buttons = {"7", "8", "9", "/", "4", "5", "6", "*", "1", "2", "3", "-", "0", "C", "=", "+"};

        for (String s : buttons) 
        {
            JButton b = new JButton(s);
            b.addActionListener(this);
            add(b);
        }
    }

     public void actionPerformed(ActionEvent e) 
    {
        String command = e.getActionCommand();

        if (command.charAt(0) >= '0' && command.charAt(0) <= '9') 
        {
            display.setText(display.getText() + command);
        } 
        else if (command.equals("C")) 
        {
            display.setText("");
            num1 = num2 = result = 0;
            operator = "";
        } else if (command.equals("=")) 
        {
            num2 = Double.parseDouble(display.getText());
            switch (operator) 
            {
                case "+":
                    result = num1 + num2;
                    break;
                case "-":
                    result = num1 - num2;
                    break;
                case "*":
                    result = num1 * num2;
                    break;
                case "/":
                    result = num1 / num2;
                    break;
            }
            display.setText(String.valueOf(result));
        } else 
        {
            if (!operator.isEmpty()) return; // Prevent double operators
            operator = command;
            num1 = Double.parseDouble(display.getText());
            display.setText("");
        }
    }
}
public class Calculator1
{
    public static void main(String[] args) 
    { 
         SimpleCalculatorTest calculator = new SimpleCalculatorTest();
         calculator.setVisible(true);
    }
}