keygen:
	gcc -Wall -O3 cmd/keygen.c -lgmp -o cmd/keygen

clean: clean_file
	rm -f cmd/keygen

clean_file:
	rm -f id_rsa id_rsa.pub
