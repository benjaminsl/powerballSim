all:
	gcc -Wall main.c options.c calc.c output.c -o powerballSim

test:
	clear
	gcc -Wall main.c options.c calc.c output.c -o powerballSim
	./powerballSim

clean:
	rm powerballSim
