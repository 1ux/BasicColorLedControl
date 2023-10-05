set xzeroaxis
set yzeroaxis
set xrange [0:4]
set yrange [0:80]
set datafile separator ","
set xlabel "Voltage (V)" font "Arial,15"
set ylabel "Current (mA)" font "Arial,15"
set key left top font "Arial,15"

plot "red_LED_Characteristic.txt" using 1:2 title "red LED characteristic" with linespoints smooth bezier lc rgb "red", \
     "green_LED_Characteristic.txt" using 1:2 title "green LED characteristic" with linespoints smooth bezier lc rgb "green", \
     "blue_LED_Characteristic.txt" using 1:2 title "blue LED characteristic" with linespoints smooth bezier lc rgb "blue"
pause -1
