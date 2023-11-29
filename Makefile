all: keygen rsa_encrypt rsa_decrypt rsa_timing_test

keygen:
	mkdir -p cmd
	gcc -Wall -O3 src/keygen.c -lgmp -o cmd/keygen

rsa_encrypt:
	mkdir -p cmd
	gcc -Wall -O3 src/rsa_encrypt.c -lgmp -o cmd/rsa_encrypt

rsa_decrypt:
	mkdir -p cmd
	gcc -Wall -O3 src/rsa_decrypt.c -lgmp -o cmd/rsa_decrypt

rsa_timing_test:
	mkdir -p cmd
	gcc -Wall -O3 src/rsa_timing_test.c -lgmp -o cmd/rsa_timing_test

clean: clean_file
	rm -f cmd/keygen
	rm -f cmd/rsa_encrypt
	rm -f cmd/rsa_decrypt
	rm -f cmd/rsa_timing_test

clean_file:
	rm -f id_rsa id_rsa.pub
