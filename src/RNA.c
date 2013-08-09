/*
 * =====================================================================================
 *
 *       Filename:  001_counting_dna_nucleotides.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/08/13 22:01:20
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>

#include <string.h>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  count each nt from argv[1]
 * =====================================================================================
 */
int
main ( int argc, char *argv[] )
{
	if (argc != 3) { printf("dna2rna <in_file> <out_file>\n"); exit(EXIT_FAILURE);}

	FILE *fh = fopen(argv[1], "r");
	FILE *ofh = fopen(argv[2], "w");

	char seq[1001];

	size_t seqlen = fgets(seq, 1000, fh);

	size_t iii = 0;
	for (iii; iii <  strlen(seq); iii++) {
		if (seq[iii] == 'T') seq[iii] = 'U';
		if (seq[iii] == 't') seq[iii] = 'u';
	}

	fputs(seq, ofh);

	fclose(fh);
	fclose(ofh);

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
