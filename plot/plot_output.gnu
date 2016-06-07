set terminal wxt size 1300, 800
set multiplot layout 3, 1

set key outside

set datafile separator comma
set key autotitle columnhead

set y2range [-1:2]
set y2tics border
set title "Room Temperature and SPOT Status"
plot 'C:\Local\Local Workspace\VC++\Simple Building Simulator\Simple Building Simulator\output\simulation.csv' \
	using 0:1 with linespoints pt 7 lw 2 axes x1y2, \
	'' using 0:4 with linespoints pt 5 lw 2, \
	'' using 0:5 with linespoints pt 2 lw 2
	
set title "Weather and Occupancy (Room)"
set y2range [-1:1]
set y2tics border
plot 'C:\Local\Local Workspace\VC++\Simple Building Simulator\Simple Building Simulator\output\simulation.csv' \
	using 0:2 with linespoints pt 7 lw 2 axes x1y2, \
	'' using 0:10 with linespoints pt 5 lw 2
	
set title "PPV, Mixed Air Temperature and AHU Power"
set y2tics border
unset y2range
plot 'C:\Local\Local Workspace\VC++\Simple Building Simulator\Simple Building Simulator\output\simulation.csv' \
	using 0:8 with linespoints pt 7 lw 2, \
	'' using 0:9 with linespoints pt 5 lw 2 axes x1y2, \
	'' using 0:11 with linespoints pt 3 lw 2 title "P_{total}"

unset multiplot
pause mouse keypress '\n'