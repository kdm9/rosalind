#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <assert.h>

int
calc_hamming (const char *seq1, const char *seq2) {
	int ham;
	int seqlen;
	int iii = 0;
	assert(strlen(seq1) == strlen(seq2));

	seqlen = strlen(seq1);

	for (iii; iii < seqlen; iii++) {
		if (seq1[iii] != seq2[iii]) {
			/* printf("%c!=%c %i\n", seq1[iii], seq2[iii], ham);
 */			ham++;
		}
/* 		else {printf("%c==%c %i\n", seq1[iii], seq2[iii], ham);}
 */	}

	return ham;
}


int
main ( int argc, char *argv[] )
{
	if (argc != 3) { printf("HAMM <seq_1> <seq_2>\n"); exit(EXIT_FAILURE);}
	int ham = 0;

	char *seq1 = argv[1];
	char *seq2 = argv[2];

	ham = calc_hamming(seq1, seq2);
	printf("%i\n", ham);

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
