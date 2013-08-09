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
	FILE *fh = fopen(argv[1], "r");
	char seq[1001];
	register int a=0, c=0, g=0, t=0;

	size_t seqlen = fread(seq, 1, 1000, fh);

	size_t iii = 0;
	for (iii; iii <  strlen(seq); iii++) {
		if ( seq[iii] == 'a' || seq[iii] ==  'A') ++a;
		if ( seq[iii] == 'c' || seq[iii] == 'C') ++c;
		if ( seq[iii] == 'g' || seq[iii] == 'G') ++g;
		if ( seq[iii] == 't' || seq[iii] == 'T') ++t;
	}

	printf("%i %i %i %i\n", a, c, g, t);
	fclose(fh);

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
