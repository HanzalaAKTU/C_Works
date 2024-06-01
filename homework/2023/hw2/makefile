all:  clean compile run

compile:
	@echo "Compiling..."
	@gcc -o test main.c -lm

run: compile
	@echo "Running the tests...."
	./test
	@echo
	@echo "Completed tests...."

clean:
	@echo "Removing compiled files..."
	@rm -f *.o
	@rm -f test
	
