#!/bin/bash
if [ ! -d "bin" ]; then
	mkdir bin
fi

if [ ! -d "bin/META-INF" ]; then
	mkdir bin/META-INF
fi

echo "Compiling..."
javac -s bin/ -d bin/ src/net/matrixstudios/mazegui/*

cd bin
cat > META-INF/MANIFEST.MF << "EOF"
Manifest-Version: 1.0
Created-By: Spencer Hanson
Main-Class: net.matrixstudios.mazegui.MazeGui
EOF
jar cmf META-INF/MANIFEST.MF MazeGUI.jar net/
mv MazeGUI.jar ../MazeGUI.jar

cd ..
echo "Run?"
read RUN
if [ $RUN == 'y' -o $RUN == 'Y' ]; then
	java -jar MazeGUI.jar ./MazeGen 64 1
fi
