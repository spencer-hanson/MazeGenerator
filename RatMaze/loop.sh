#!/bin/bash
for i in $(seq 1 2000);
do
	#echo "Run #$i"
	./Debug/RatMaze $i
	if [ $? -eq 139 ]; then
		echo "Crash at #$i"
	fi
done
