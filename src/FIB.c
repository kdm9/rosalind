#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

int
main ( int argc, char *argv[] )
{
	if (argc != 3) {fprintf(stderr, "USAGE: FIB n k\n"); exit(EXIT_FAILURE);}

	uint64_t n, k;

	n = atoi(argv[1]); /* number of generations, n in the syntax of the problem statement*/
	k = atoi(argv[2]); /* number of kin per generation */

	uint64_t last = 1;
	uint64_t second_last = 1;
	uint64_t iii = 0;
	for (iii; iii < (n - 2); iii++) {
		uint64_t popn = 0;
		popn = last + (k * second_last);
		printf("-2 %u\t-1 %u\t0 %u\tn %u\n", second_last, last, popn, iii+3);
		second_last = last;
		last = popn;
	}
	printf("%u\n", last);

	return EXIT_SUCCESS;
}
