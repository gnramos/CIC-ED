/* Material da disciplina CIC0090 Estruturas de Dados.
 *
 * @author Guilherme N. Ramos (gnramos@unb.br)
 *
 * Baseado no material do Prof. Rafael C. S. Schouery
 * https://www.ic.unicamp.br/~rafael/mc202.html
 */

#include <assert.h>
#include <stdlib.h>

#include "vetor_estatico.h"

#define MAX 10

void test_ve_busca() {
	assert(ve_busca(NULL, 0, 0) == -1);

	int ve[MAX];

	assert(ve_busca(ve, -1, 0) == -1);

	ve_preenche_crescente(ve, MAX);
	for (int x = 0; x < MAX; x++)
		assert(ve_busca(ve, MAX, x) == x);

	ve_preenche_decrescente(ve, MAX);
	for (int x = 0; x < MAX; x++)
		assert(ve_busca(ve, MAX, x) != -1);
}

void test_ve_busca_binaria() {
	assert(ve_busca_binaria(NULL, 0, 0) == -1);

	int ve[MAX];

	assert(ve_busca_binaria(ve, -1, 0) == -1);
	assert(ve_busca_binaria(ve, 0, 0) == -1);

	ve_preenche_crescente(ve, MAX);
	for (int x = 0; x < MAX; x++)
		assert(ve_busca_binaria(ve, MAX, x) != -1);
}

void test_ve_preenche_crescente() {
	int ve[MAX];

	ve_preenche_crescente(ve, MAX);
	for (int i = 1; i < MAX; i++)
		assert(ve[i] >= ve[i - 1]);
}


void test_ve_preenche_decrescente() {
	int ve[MAX];

	ve_preenche_decrescente(ve, MAX);
	for (int i = 1; i < MAX; i++)
		assert(ve[i] <= ve[i - 1]);
}

int main() {
	test_ve_busca();
	test_ve_busca_binaria();
	test_ve_preenche_crescente();
	test_ve_preenche_decrescente();

	return 0;
}