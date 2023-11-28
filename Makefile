keygen:
	gcc -Wall -O3 keygen.c -lgmp -o keygen

gen:
	gcc -Wall -O3 generator.c -o generator

dbg:
	gcc -Wall -g generator.c -o generator

clean: clean_file
	rm -f generator keygen

clean_file:
	rm -f id_rsa id_rsa.pub