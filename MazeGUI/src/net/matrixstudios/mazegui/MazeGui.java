package net.matrixstudios.mazegui;

import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.io.IOException;

import javax.swing.JFrame;

class MazeGui extends JFrame implements MouseListener {

	private MazeReader reader;
	private MazePanel panel;

	private int mazeSize;
	private int cellSize;
	private String progExe;

	private void initComponents() {
		try {
			reader = new MazeReader("maze.txt");
			panel = new MazePanel(reader.getMaze(), cellSize);
			add(panel);
		} catch(IOException e) {
			e.printStackTrace();
			System.out.println("Make sure maze.txt is in the same working directory!");
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

	public MazeGui(String progExe, int size, int cellSize) {
		super("Maze GUI");
		println("Starting MazeGUI using: " + progExe + " with: " + size + "x" + size + " Maze, Cellsize:" + cellSize);

		this.progExe = progExe;
		this.mazeSize = size;
		this.cellSize = cellSize;

		init();
		refreshScreen();
	}

	public static void println(String str) {
		System.out.println(str);
	}

	public static void usage() {
		String name = "java -jar MazeGUI.jar";
		println("Invalid usage!");
		println("Usage: " + name + " <GenMaze Executable> [Maze Size] [Maze Cell Size]");
	}


	public static void main(String[] args) {
		String prog = "";
		int mazeSize = 0;
		int cellSize = 0;

		if(args.length < 3) {
			println("Incorrect commandline args!");
			usage();
			return;
		}

		try {
			prog = args[0];
			mazeSize = Integer.parseInt(args[1]);
			cellSize = Integer.parseInt(args[2]);
		} catch(NumberFormatException e) {
			println("Invalid input!");
			usage();
			return;
		} catch(Exception e) {
			e.printStackTrace();
			println("================");
			usage();
			return;
		}
		new MazeGui(prog, mazeSize, cellSize);
	}

	public void refreshScreen() {
		System.out.println("ReGenerating Maze...");

		try {
			Process p = Runtime.getRuntime().exec(progExe + " " + mazeSize + " -o maze.txt"); //64x64 save to maze.txt
			p.waitFor();
		} catch(Exception ex) {
			System.out.println("Error running executable!");
			ex.printStackTrace();
		}

		reader.refreshMaze(panel);
		repaint();
	}

	@Override
	public void mouseClicked(MouseEvent e) {
		refreshScreen();
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
