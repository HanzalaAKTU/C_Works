all:   run

compile: clean  

	@gcc --ansi -std=c99 1901042706_part1.c -o homework1_1
	@gcc --ansi -std=c99 1901042706_part2.c -o homework1_2
	
run: compile

	./homework1_1 < input.txt > encrypted.txt
	./homework1_2 < encrypted.txt > decrypted.txt
	@echo

clean:

	@rm -f *.o
	@rm -f homework1_1
	@rm -f homework1_2
	@rm -f encrypted.txt
	@rm -f decrypted.txt
	