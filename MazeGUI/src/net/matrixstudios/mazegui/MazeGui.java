package net.matrixstudios.mazegui;

import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.io.IOException;

import javax.swing.JFrame;

class MazeGui extends JFrame implements MouseListener {

	private MazeReader reader;
	private MazePanel panel;
	
	private void initComponents() {
		try {
			reader = new MazeReader("maze.txt");
			panel = new MazePanel(reader.getMaze());
			add(panel);
		} catch(IOException e) {
			e.printStackTrace();
			System.exit(-1);
		}
	}
	
	private void init() {
		initComponents();
		setSize(500, 600);
		setResizable(true);
		setLocationRelativeTo(null);
		addMouseListener(this);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setVisible(true);
	}

	public MazeGui() {
		super("Maze GUI");
		init();
	}

	public static void main(String[] args) {
		new MazeGui();
	}

	@Override
	public void mouseClicked(MouseEvent e) {
		try {
			Process p = Runtime.getRuntime().exec("./RatMaze");
			p.waitFor();
		} catch (Exception e1) {
			e1.printStackTrace();
		}
		reader.refreshMaze(panel);
		repaint();
		System.out.println("Refreshing");
	}

	@Override
	public void mouseEntered(MouseEvent e) { }

	@Override
	public void mouseExited(MouseEvent e) { }

	@Override
	public void mousePressed(MouseEvent e) { }

	@Override
	public void mouseReleased(MouseEvent arg0) { }

}
