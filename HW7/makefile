period_amplitude.txt: periodo.py prove.exe
	python periodo.py fileOut.txt

prove.exe: main.o slopes.o functions.o
	cc -lm main.o slopes.o functions.o -o prove.exe
	./prove.exe
	gnuplot graphics.gp
	

main.o: main.c
	cc -c main.c

slopes.o: slopes.c
	cc -c slopes.c

functions.o: functions.c
	cc -c functions.c

all: period_amplitude.txt
