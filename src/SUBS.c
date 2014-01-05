#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

size_t BUFFLEN = 1<<10;


int main(int argc, char *argv[]) {
	if (argc != 2) { printf("subs <in_file>\n"); exit(EXIT_FAILURE);}

	FILE *fh = fopen(argv[1], "r");

	char seq[BUFFLEN + 1];
	char needle[BUFFLEN + 1];
	char *iter;

	fgets(seq, BUFFLEN, fh);
	size_t seqlen = strlen(seq);
	printf("seq is %s\n", seq);
	seq[seqlen - 1] = '\0';

	fgets(needle, BUFFLEN, fh);
	size_t needlelen = strlen(needle);
	needle[needlelen - 1] = '\0';
	printf("needle is %s\n", needle);

    iter = strstr(seq, needle);
	while (iter != NULL) {
		size_t pos = iter - seq + 1;
		printf("%d ", pos);
		iter = strstr(iter + 1, needle);
	}
	printf("\n");

	fclose(fh);
	return EXIT_SUCCESS;
}
