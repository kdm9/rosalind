#include <stdlib.h>
#include <string.h>
#include <stdio.h>


#include "kmlib.h"


int main(int argc, char *argv[]) {
	if (argc != 3) { printf("REVC <in_file> <out_file>\n"); exit(EXIT_FAILURE);}

	FILE *fh = fopen(argv[1], "r");
	FILE *ofh = fopen(argv[2], "w");

	char seq[1001];
	char outseq[1001];

	fgets(seq, 1000, fh);

	revcomp(&outseq, seq);

	printf("seq is %s\n", seq);
	printf("seq is now %s\n", outseq);

	fputs(outseq, ofh);
	fclose(fh);
	fclose(ofh);
	return EXIT_SUCCESS;
}
