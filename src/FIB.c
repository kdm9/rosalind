#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>


#include <gmp.h>

int
main ( int argc, char *argv[] )
{
	if (argc != 3) {fprintf(stderr, "USAGE: FIB n k\n"); exit(EXIT_FAILURE);}

	int n, k;

	n = atoi(argv[1]); /* number of generations, n in the syntax of the problem statement*/
	k = atoi(argv[2]); /* number of kin per generation */

	mpz_t last;
	mpz_init_set_ui(last, 1);

	mpz_t second_last;
	mpz_init_set_ui(second_last, 1);

	mpz_t popn;
	mpz_init_set_ui(popn, 0);

	int iii = 0;
	for (iii; iii < (n - 2); iii++) {
		mpz_t offspring;
		mpz_init_set_ui(offspring, 0);

		mpz_mul_ui(offspring, second_last, k);
		mpz_add(popn, last, offspring);

		mpz_set(second_last, last);
		mpz_set(last, popn);
	}
	gmp_printf("%Zd\n", last);

	return EXIT_SUCCESS;
}
