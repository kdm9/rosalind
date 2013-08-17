#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

#include "kmlib.h"


int main(int argc, char *argv[]) {
	if (argc != 3) { printf("HAMM <seq_1> <seq_2>\n"); exit(EXIT_FAILURE); }
	int ham = 0;

	char *seq1 = argv[1];
	char *seq2 = argv[2];

	ham = calc_hamming(seq1, seq2);
	printf("%i\n", ham);

	return EXIT_SUCCESS;
}
