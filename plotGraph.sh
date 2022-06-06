#!/bin/bash

make all

./pendol 0 1 1 0 1    0 600000 100 > points.txt
./pendol 0 1 1 0 1.75 0 600000 100 > points2.txt
./pendol 0 1 1 0 2    0 600000 100 > points3.txt
./pendol 0 1 1 0 2.25 0 600000 100 > points4.txt

gnuplot -persist <<-EOFMarker
    set yrange [-3:3]
    set xrange [-3.5:3.5]
    unset key
    plot "points.txt" u 2:3, "points2.txt" u 2:3, "points3.txt" u 2:3, "points4.txt" u 2:3  
EOFMarker

make clean
make cleanP
