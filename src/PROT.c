/*
 * ============================================================================
 *
 *       Filename:  PROT.c
 *
 *    Description:  translate a sequence to protein
 *
 *        Version:  1.0 *        Created:  01/01/14 23:37:58
 *       Revision:  none
 *        License:  GPLv3+
 *       Compiler:  gcc
 *
 *         Author:  Kevin Murray, spam@kdmurray.id.au
 *                                [include word penguin in subject]
 *
 * ============================================================================
 */
#include <stdlib.h>

#include <kmlib.h>

int
main (int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "USAGE:\nPROT <seqfile>\n");
        return EXIT_FAILURE;
    }

    FILE *in_seq_fp;
    const char *in_seq_file_name = argv[1];
    char *in_seq = NULL;
    size_t in_seq_len = 0;
    char *out_seq = NULL;
    size_t out_seq_len = 0;
    int iii;

    in_seq_fp = fopen (in_seq_file_name, "r");
    if (in_seq_fp == NULL) {
        fprintf (stderr, "couldn't open file '%s'; %s\n",
                in_seq_file_name, strerror(errno));
        return(EXIT_FAILURE);
    }

    fseek(in_seq_fp, 0, SEEK_END);
    in_seq_len = ftell(in_seq_fp);
    fseek(in_seq_fp, 0, SEEK_SET);

    in_seq = calloc(in_seq_len + 1, sizeof(*in_seq));
    fread(in_seq, in_seq_len, sizeof(*in_seq), in_seq_fp);

    char *newline = strchr(in_seq, '\n');
    if (newline != NULL) {
        newline[0] = '\0';
    }
    printf("seq is:\n%s\n", in_seq);

    in_seq_len = strlen(in_seq);

    out_seq_len = in_seq_len / 3;
    out_seq = calloc(out_seq_len, sizeof(*out_seq));


    if (in_seq_len % 3 != 0) {
        printf("%i\n", in_seq_len);
        fprintf(stderr, "seq must be of codons (len % 3 == 0)\n");
        return EXIT_FAILURE;
    }


    for (iii = 0; iii < in_seq_len; iii += 3) {
        char *tmp = strndup(in_seq + iii, 3);
        out_seq[iii/3] = translate_codon(tmp);
        free(tmp);
    }
    printf("outseq:\n%s\n", out_seq);

    if (fclose(in_seq_fp) == EOF) {
        fprintf (stderr, "couldn't close file '%s'; %s\n",
                in_seq_file_name, strerror(errno));
        return(EXIT_FAILURE);
    }

    free(in_seq);
    free(out_seq);

    return EXIT_SUCCESS;
} /* ----------  end of function main  ---------- */
