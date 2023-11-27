gen:
	gcc -Wall -O3 generator.c -o generator

dbg:
	gcc -Wall -g generator.c -o generator

clean:
	rm generator