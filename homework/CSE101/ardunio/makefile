all: clear clean compile run

compile: ardunioProject.c
	@echo "Compiling..."
	@gcc -o test ardunioProject.c -lm

run:
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
