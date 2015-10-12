package net.matrixstudios.mazegui;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class MazeReader {
	
	private BufferedReader reader;
	private ArrayList<char[]> lines;
	private String file;
	
	private char[] lineToArray(String line) {
		char[] lines = new char[line.length()];
		for(int i = 0;i<line.length();i++) {
			lines[i] = line.charAt(i);
		}
		return lines;
	}
	
	private void readMaze() throws IOException {
		String linetmp = "";
		while((linetmp = reader.readLine()) != null) {
				lines.add(lineToArray(linetmp));
			}
	}
	public MazeReader(String file) throws IOException {
		this.file = file;
		System.out.println("Reading file...");
		reader = new BufferedReader(new FileReader(file));
		lines = new ArrayList<char[]>(1024);
		readMaze();		
	}
	
	public ArrayList<char[]> getMaze() {
		return lines;
	}
	
	public void refreshMaze(MazePanel panel) {
		try {
			reader = new BufferedReader(new FileReader(file));
			lines = new ArrayList<char[]>(1024);
			readMaze();	
			panel.setMaze(getMaze());
		} catch(IOException e) {
			e.printStackTrace();
		}
	}
}
