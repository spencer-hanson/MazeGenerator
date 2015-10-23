package net.matrixstudios.mazegui;

import java.awt.Color;
import java.awt.Graphics;
import java.util.ArrayList;

import javax.swing.JPanel;

public class MazePanel extends JPanel {
	
	private ArrayList<char[]> maze;
	private int cellSize = 1;
	
	public MazePanel(ArrayList<char[]> maze, int cellSize) {
		this(maze);
		this.cellSize = cellSize;
	}

	public MazePanel(ArrayList<char[]> maze) {
		super();
		this.maze = maze;
	}
	
	public void setMaze(ArrayList<char[]> maze) {
		this.maze = maze;
	}
	
	@Override
	public void paint(Graphics g) {
		char currentCell = '$';
		for(int y = 0;y<maze.size();y++) {
			for(int x = 0;x<maze.get(y).length;x++) {
				currentCell = maze.get(y)[x];
				if(currentCell == '#') {
					g.setColor(Color.black);
				} else if(currentCell == '*') {
					g.setColor(Color.white);
				} else {
					g.setColor(Color.red);
				}
				g.fillRect(x * cellSize, y * cellSize, cellSize, cellSize);
			}
		}
	}

}
