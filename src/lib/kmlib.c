/*
 * =====================================================================================
 *
 *       Filename:  kmlib.c
 *
 *    Description:  A series of functions used in bioinformatic tasks
 *
 *        Version:  1.0
 *        Created:  11/08/13 21:34:38
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin Murray
 *
 * =====================================================================================
 */
#include "kmlib.h"

inline int calc_hamming(const char *seq1, const char *seq2) {
	int ham = 0;
	int seqlen = 0;
	int iii = 0;

	if (strlen(seq1) == strlen(seq2)) return -1;
	seqlen = strlen(seq1);

	for (iii; iii < seqlen; iii++) {
		if (seq1[iii] != seq2[iii]) {
 			ham++;
		}
 	}
	return ham;
}


inline void revcomp(char **outseq, char *seq) {
	int seqlen = strlen(seq);
	if (seq[seqlen - 1] == '\n') {
		seq[seqlen - 1] = '\0';
		seqlen = strlen(seq);
	}

	int iii = 0;
	for (iii; iii < seqlen; iii++) {
		int outpos = seqlen - iii - 1;
		if (seq[iii] == 'a' || seq[iii] == 'A') (*outseq)[outpos] = 'T';
		if (seq[iii] == 'c' || seq[iii] == 'C') (*outseq)[outpos] = 'G';
		if (seq[iii] == 'g' || seq[iii] == 'G') (*outseq)[outpos] = 'C';
		if (seq[iii] == 't' || seq[iii] == 'T') (*outseq)[outpos] = 'A';
		/*printf("seq at %i %c, out %i %c\n", iii, seq[iii], outpos, (*outseq)[outpos]);*/
	}
}
