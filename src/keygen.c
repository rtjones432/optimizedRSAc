#include "keygen.h"

void usage() {
	printf("\nUsage: keygen [arg]\n");
    printf("Args:\n");
	printf("-l\tSpecify key length\n");
	exit(0);
}

void write_to_file(mpz_t n, mpz_t e, mpz_t d) {
    FILE *fptr;
    fptr = fopen(PUBLIC_KEY_FILE, "w");
    mpz_out_str(fptr, 16, e);
    fprintf(fptr, "\n");
    mpz_out_str(fptr, 16, n);
    fclose(fptr);

    fptr = fopen(PRIVATE_KEY_FILE, "w");
    mpz_out_str(fptr, 16, d);
    fprintf(fptr, "\n");
    mpz_out_str(fptr, 16, n);
    fclose(fptr);
}

void keygen(mpz_t n, mpz_t e, mpz_t d, unsigned int bit_length) {
    mpz_t p, q, r;
    mpz_init(p);
    mpz_init(q);
    mpz_init(r);

    gmp_randstate_t state;
    gmp_randinit_default(state);
    gmp_randseed_ui(state, clock());

    do {
        mpz_urandomb(p, state, bit_length);
    } while (mpz_probab_prime_p(p, 50) < 1);

    do {
        mpz_urandomb(q, state, bit_length);
    } while (mpz_probab_prime_p(q, 50) < 1);

    mpz_mul(n, p, q);

    do {
        mpz_urandomb(e, state, bit_length);
    } while (mpz_probab_prime_p(e, 50) < 1);

    mpz_sub_ui(p, p, 1);
    mpz_sub_ui(q, q, 1);

    mpz_mul(r, p, q);
    mpz_invert(d, e, r);
}

int main(int argc, char *argv[]) {
    unsigned long bit_length = DEFAULT_BIT_LENGTH;

    int op = 0;
    while ((op = getopt(argc, argv, "l:")) != -1) {
        switch (op) {
            case 'l':
                bit_length = atoi(optarg);
                break;
            default:
                usage();
        }
    }

    mpz_t n, e, d;
    mpz_init(n);
    mpz_init(e);
    mpz_init(d);

    keygen(n, e, d, bit_length);
    write_to_file(n, e, d);

    printf("[!] Done.\n");

    return 0;
}
