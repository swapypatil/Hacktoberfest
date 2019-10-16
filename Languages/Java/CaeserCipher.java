import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
public class CaeserCipher implements ActionListener {
	JTextField tf,tf1,tf2;
	JButton b;
	JFrame fr;
	JLabel l1,l2,l3;
	JPanel p;
	public encry(){
		
		p = new JPanel();
		fr = new JFrame("Encryption");
		fr.setVisible(true);
		fr.setSize(400,400);
		tf = new JTextField(30);
		tf1 = new JTextField(3);
		tf2 = new JTextField(30);
		l1 = new JLabel("Enter Text For Encryption");
		l2 = new JLabel("Enter Key");
		l3 = new JLabel("Encrypted Text");
		b = new JButton("Encrypt");
		p.setLayout(null);
		fr.add(p);
		p.add(l1);
		p.add(tf);
		p.add(l2);
		p.add(tf1);
		p.add(b);
		p.add(l3);
		p.add(tf2);
		l1.setBounds(60,60,200,40);
		tf.setBounds(220,60,200,40);
		l2.setBounds(60,120,150,40);
		tf1.setBounds(220,120,200,40);
		b.setBounds(220,180,100,40);
		l3.setBounds(60,240,200,40);
		tf2.setBounds(220,240,200,40);
		b.addActionListener(this);
	}	
		public void dis(){
			String ALPHABET = "abcdefghijklmnopqrstuvwxyz";
			String message = tf.getText();
			message = message.toLowerCase();
			String k= tf1.getText();
			String text = "";
			int key = Integer.parseInt(k);
			for (int i = 0; i < message.length(); i++)
			{	
				int charPosition = ALPHABET.indexOf(message.charAt(i));
				int keyVal = (key + charPosition) % 26;
				char replace = ALPHABET.charAt(keyVal);
				text += replace;
			}
			//return text;
				String abc = text;
				tf2.setText(abc);
		}
	public void actionPerformed(ActionEvent e){
			if(e.getSource() == b){
				dis();
			}

		}
	public static void main(String args[]){
		CaeserCipher en = new CaeserCipher();
	}
}