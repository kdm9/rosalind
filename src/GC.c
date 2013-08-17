#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <zlib.h>

#include "kseq.h"

KSEQ_INIT(gzFile, gzread);


int main(int argc, char *argv[]) {
	gzFile infh;
	kseq_t *seq;

	if (argc != 2) { printf("GC <in_file>\n"); exit(EXIT_FAILURE);}

	infh = strcmp(argv[1], "-")? gzopen(argv[1], "r") : gzdopen(fileno(stdin), "r");

	seq = kseq_init(infh);

	while (kseq_read(seq) >= 0) {
		size_t seqlen = seq->seq.l;
		int at = 0, gc = 0;
		float gc_content;

		int iii = 0;
		/* printf("nm %s ln %i\n", seq->name.s, seqlen); */
		for (iii; iii < seqlen; iii++) {
			if (seq->seq.s[iii] == 'a' || seq->seq.s[iii] == 'A') at += 1;
			if (seq->seq.s[iii] == 'c' || seq->seq.s[iii] == 'C') gc += 1;
			if (seq->seq.s[iii] == 'g' || seq->seq.s[iii] == 'G') gc += 1;
			if (seq->seq.s[iii] == 't' || seq->seq.s[iii] == 'T') at += 1;
			/* printf("s %i %c. gc %i at %i\n", iii, seq->seq.s[iii], at, gc); */
		}

		gc_content = (float) gc / (float) (at + gc) * 100.0;
		printf("%s\n%f\n", seq->name.s, gc_content);
	}

	gzclose(infh);
	kseq_destroy(seq);
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
