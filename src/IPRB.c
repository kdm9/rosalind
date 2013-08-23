#include <stdlib.h>
#include <stdio.h>

#include <gmp.h>
#include "kmlib.h"

int main(int argc, char *argv[]) {
	if (argc != 4) {fprintf(stderr, "USAGE: IPRB AA Aa aa\n"); exit(EXIT_FAILURE);}

	unsigned long int AA, Aa, aa;
	AA = atoi(argv[1]);
	Aa = atoi(argv[2]);
	aa = atoi(argv[3]);
	unsigned long int popn = AA + Aa + aa;

	mpf_t prob_dominant;
	mpf_init(prob_dominant);

	mpz_t qty_z;
	mpz_init_set_ui(qty_z, 0);

	mpf_t qty_f;
	mpf_init(qty_f);

	mpf_t multiplicate;
	mpf_init(multiplicate);


	/******************************* ones ***************************/
	/* AA */

	/* n_AA choose 2 ways to get 100% AA progeny from 2 AAs */
	mpz_bin_uiui(qty_z, AA, 2);

	/* Juggle around to get a probability, and add to overall prob */
	mpf_set_z(qty_f, qty_z);
	mpf_add(prob_dominant, prob_dominant, qty_f);


	/* AA X Aa will give 100% A phenotype, as will AA x aa */
	mpf_set_ui(qty_f, (AA * Aa) + (AA * aa));
	mpf_add(prob_dominant, prob_dominant, qty_f);

	/* clean up */
	mpz_set_ui(qty_z, 0);
	mpf_set_d(qty_f, 0.0);


	/*************************** three quarters ********************/

	/* Aa x Aa is only way to get 75% progeny w/ the A phenotype */
	mpz_bin_uiui(qty_z, Aa, 2);

	/* Juggle around to get a probability, and add to overall prob */
	mpf_set_z(qty_f, qty_z);
	/* times by 0.75 */
	mpf_set_d(multiplicate, 0.75);
	mpf_mul(qty_f, qty_f, multiplicate);

	mpf_add(prob_dominant, prob_dominant, qty_f);

	/* clean up */
	mpz_set_ui(qty_z, 0);
	mpf_set_d(qty_f, 0.0);


	/**************************** halves ***************************/

	/* Aa x aa is only way to get 50% A progeny */
	mpf_set_ui(qty_f, Aa * aa);

	/* times by 0.5 */
	mpf_set_d(multiplicate, 0.5);
	mpf_mul(qty_f, qty_f, multiplicate);

	mpf_add(prob_dominant, prob_dominant, qty_f);


	/*************************** output *****************************/

	mpz_bin_uiui(qty_z, popn, 2);
	mpf_set_z(qty_f, qty_z);

 	mpf_div(prob_dominant, prob_dominant, qty_f);
	gmp_printf("%Ff\n", prob_dominant);

	return EXIT_SUCCESS;
}
