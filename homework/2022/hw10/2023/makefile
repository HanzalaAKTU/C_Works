all: clear clean compile run

compile:
	@echo "Compiling..."
	@gcc -o test main2.c -lm

run: compile
	@echo "Running the tests...."
	./test
	@echo
	@echo "Completed tests...."

clean:
	@echo "Removing compiled files..."
	@rm -f *.o
	@rm -f test
	
clear:
	@clear
