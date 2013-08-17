#include <stdlib.h>
#include <string.h>
#include <stdio.h>



int main(int argc, char *argv[]) {
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
}
