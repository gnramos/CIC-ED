/* Material da disciplina CIC0090 Estruturas de Dados.
 *
 * @author Guilherme N. Ramos (gnramos@unb.br)
 *
 * Baseado no material do Prof. Rafael C. S. Schouery
 * https://www.ic.unicamp.br/~rafael/mc202.html
 */

#include <assert.h>
#include <stdlib.h>

#include "vetor_dinamico.h"
#include "vetor_estatico.h"

#define MAX 10

void test_vd_busca() {
	p_vd vd = NULL;

	assert(vd_busca(vd, 0) == -1);

	vd = vd_cria(MAX);
	for (int x = 0; x < MAX; x++) {
		vd_insere(vd, x);
		assert(vd_busca(vd, x) == x);
	}
	vd_destroi(&vd);

	vd = vd_cria(MAX);
	for (int x = MAX - 1; x >= 0; x--) {
		vd_insere(vd, x);
		assert(vd_busca(vd, x) == MAX - x - 1);
	}
	vd_destroi(&vd);
}

void test_vd_busca_binaria() {
	p_vd vd = NULL;

	assert(vd_busca_binaria(vd, 0) == -1);

	vd = vd_cria(MAX);
	for (int x = 0; x < MAX; x++) {
		vd_insere(vd, x);
		assert(vd_busca_binaria(vd, x) == x);
	}
	assert(vd_busca_binaria(vd, -MAX) == -1);
	assert(vd_busca_binaria(vd, MAX + 1) == -1);

	vd_destroi(&vd);
}

void test_vd_cria() {
	p_vd vd = NULL;

	for (int tam = 0; tam <= 2; tam++) {
		vd = vd_cria(tam);
		assert(vd != NULL);
		assert(vd->dados != NULL);
		assert(vd->n == 0);
		assert(vd->alocado == tam);
		vd_destroi(&vd);
	}

	for (int tam = 1; tam <= 1000; tam *= 10) {
		vd = vd_cria(tam);
		assert(vd != NULL);
		assert(vd->dados != NULL);
		assert(vd->n == 0);
		assert(vd->alocado == tam);
		vd_destroi(&vd);
	}

	vd = vd_cria(1000 * 1000 * 1000 * 1000 * 1000);
	assert(vd == NULL);
}

void test_vd_destroi() {
	p_vd vd = NULL;

	vd_destroi(NULL);

	vd = vd_cria(100);
	vd_destroi(&vd);
	assert(vd == NULL);
}

void test_vd_insere() {
	p_vd vd = NULL;
	vd_insere(vd, 0);

	vd = vd_cria(0);
	for (int x = 0; x < MAX; x++) {
		vd_insere(vd, x);
		assert(vd->n == x + 1);
		assert(vd->dados[x] == x);
	}
	vd_destroi(&vd);

	vd = vd_cria(0);
	for (int x = 0; x < MAX; x++) {
		vd_insere(vd, MAX - x);
		assert(vd->n == x + 1);
		assert(vd->dados[x] == MAX - x);
	}
	vd_destroi(&vd);
}

void test_vd_remove() {
	p_vd vd = NULL;
	vd_remove(vd, 0);

	vd = vd_cria(MAX);
	vd_remove(vd, -2);
	assert(vd->n == 0);
	vd_remove(vd, 2 * vd->alocado);
	assert(vd->n == 0);

	for (int x = 0; x < MAX; x++)
		vd_insere(vd, x);

	int n = vd->n;
	vd_remove(vd, n);
	assert(n == vd->n);

	while (vd->n > 0) {
		n = vd->dados[0];
		vd_remove(vd, 0);
		assert(vd_busca(vd, n) == -1);
	}

	for (int x = 0; x < MAX; x++)
		vd_insere(vd, x);

	while (vd->n > 0) {
		n = vd->dados[vd->n - 1];
		vd_remove(vd, vd->n - 1);
		assert(vd_busca(vd, n) == -1);
	}

	vd_destroi(&vd);
}

void assert_in_order(p_vd vd) {
	for (int i = 1; i < vd->n; i++)
		assert(vd->dados[i] >= vd->dados[i - 1]);
}

void test_vd_insere_ord() {
	p_vd vd = NULL;
	vd_insere(vd, 0);

	vd = vd_cria(0);
	for (int x = 0; x < MAX; x++) {
		vd_insere_ord(vd, x);
		assert_in_order(vd);
	}
	vd_destroi(&vd);

	vd = vd_cria(0);
	for (int x = MAX; x > 0; x--) {
		vd_insere_ord(vd, x);
		assert_in_order(vd);
	}
	vd_destroi(&vd);
}

void test_vd_remove_ord() {
	p_vd vd = NULL;
	vd_remove_ord(vd, 0);

	vd = vd_cria(MAX);
	vd_remove_ord(vd, -2);
	assert(vd->n == 0);
	vd_remove_ord(vd, 2 * vd->alocado);
	assert(vd->n == 0);

	for (int x = 0; x < MAX; x++)
		vd_insere_ord(vd, x);

	int n = vd->n;
	vd_remove_ord(vd, n);
	assert(n == vd->n);

	while (vd->n > 0) {
		n = vd->dados[0];
		vd_remove_ord(vd, 0);
		assert_in_order(vd);
		assert(vd_busca(vd, n) == -1);
	}

	for (int x = 0; x < MAX; x++)
		vd_insere_ord(vd, x);

	while (vd->n > 0) {
		n = vd->dados[vd->n - 1];
		vd_remove_ord(vd, vd->n - 1);
		assert_in_order(vd);
		assert(vd_busca(vd, n) == -1);
	}

	vd_destroi(&vd);
}

int main() {
	test_vd_busca();
	test_vd_busca_binaria();
	test_vd_cria();
	test_vd_destroi();
	test_vd_insere();
	test_vd_insere_ord();
	test_vd_remove();
	test_vd_remove_ord();

	return 0;
}