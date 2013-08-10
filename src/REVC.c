#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int
main ( int argc, char *argv[] )
{
	if (argc != 3) { printf("REVC <in_file> <out_file>\n"); exit(EXIT_FAILURE);}

	FILE *fh = fopen(argv[1], "r");
	FILE *ofh = fopen(argv[2], "w");

	char seq[1001];
	char outseq[1001];

	fgets(seq, 1000, fh);

	int seqlen = strlen(seq);
	if (seq[seqlen - 1] == '\n') {
		seq[seqlen - 1] = '\0';
		seqlen = strlen(seq);
	}

	int iii = 0;
	for (iii; iii < seqlen; iii++) {
		int outpos = seqlen - iii - 1;
		if (seq[iii] == 'a' || seq[iii] == 'A') outseq[outpos] = 'T';
		if (seq[iii] == 'c' || seq[iii] == 'C') outseq[outpos] = 'G';
		if (seq[iii] == 'g' || seq[iii] == 'G') outseq[outpos] = 'C';
		if (seq[iii] == 't' || seq[iii] == 'T') outseq[outpos] = 'A';
		/*printf("seq at %i %c, out %i %c\n", iii, seq[iii], outpos, outseq[outpos]);*/
	}

	printf("seq is %s\n", seq);
	printf("seq is now %s\n", outseq);

	fputs(outseq, ofh);
	fclose(fh);
	fclose(ofh);
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
