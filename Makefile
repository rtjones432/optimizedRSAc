all: keygen rsa_encrypt rsa_decrypt rsa_timing_test rsa_example

keygen:
	mkdir -p cmd
	gcc -Wall -O3 src/genkey.c src/keygen.c -lgmp -o cmd/genkey

rsa_encrypt:
	mkdir -p cmd
	gcc -Wall -g -O3 src/rsa_encrypt.c src/log_rsa.c -lgmp -o cmd/rsa_encrypt

rsa_decrypt:
	mkdir -p cmd
	gcc -Wall -O3 src/rsa_decrypt.c src/log_rsa.c -lgmp -o cmd/rsa_decrypt

rsa_timing_test:
	mkdir -p cmd
	gcc -g -Wall -O3 src/rsa_timing_test.c src/keygen.c src/lin_rsa.c src/log_rsa.c src/gmp_rsa.c -lgmp -o cmd/rsa_timing_test

rsa_example:
	mkdir -p cmd
	gcc -Wall -O3 src/rsa_example.c src/log_rsa.c -lgmp -o cmd/rsa_example

clean: clean_key clean_symbol
	rm -f cmd/genkey
	rm -f cmd/rsa_encrypt
	rm -f cmd/rsa_decrypt
	rm -f cmd/rsa_timing_test
	rm -f cmd/rsa_example

clean_key:
	rm -f id_rsa id_rsa.pub

clean_symbol:
	rm -rf cmd/*.dSYM
