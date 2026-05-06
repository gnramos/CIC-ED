/* Material da disciplina CIC0090 Estruturas de Dados.
 *
 * @author Guilherme N. Ramos (gnramos@unb.br)
 *
 * Baseado no material do Prof. Rafael C. S. Schouery
 * https://www.ic.unicamp.br/~rafael/mc202.html
 */

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "lista_simples.h"

#define MAX 10

lst cria(int tam) {
	lst head = NULL;
	for (int x = tam - 1; x >= 0; x--)
		lst_insere_inicio(&head, x);
	return head;
}

void test_lst_busca() {
	lst head = NULL, *p_aux;

	assert(lst_busca(&head, 0) == NULL);

	head = cria(MAX);
	for (int x = MAX - 1; x >= 0; x--) {
		p_aux = lst_busca(&head, x);
		assert(p_aux != NULL && *p_aux != NULL);
		assert((*p_aux)->dado == x);
	}
	lst_destroi(&head);
}

void test_lst_cria() {
	lst head = lst_cria(0, NULL);
	assert(head);
	assert(head->dado == 0);
	assert(head->prox == NULL);

	lst new_head = lst_cria(1, head);
	assert(new_head);
	assert(new_head->dado == 1);
	assert(new_head->prox == head);
	assert(new_head->prox->dado == head->dado);
	assert(new_head->prox->prox == head->prox);

	lst_destroi(&new_head);
}

void test_lst_destroi() {
	lst head = lst_cria(0, NULL);
	assert(head);
	lst_destroi(&head);
	assert(head == NULL);

	head = lst_cria(0, NULL);
	lst new_head = lst_cria(1, head);
	lst_destroi(&new_head);

	assert(new_head == NULL);
}

void test_lst_insere_inicio() {
	lst_insere_inicio(NULL, 0);

	lst head = NULL;
	lst_insere_inicio(&head, 0);
	assert(head);
	assert(head->dado == 0);
	assert(head->prox == NULL);
	lst zero = head;
	lst_insere_inicio(&head, 1);
	assert(head->dado == 1);
	assert(head->prox == zero);
	lst um = head;
	lst_insere_inicio(&head, 2);
	assert(head->dado == 2);
	assert(head->prox == um);
	lst_destroi(&head);
}

void test_lst_insere_final() {
	lst head = NULL;

	lst_insere_final(&head, 0);
	assert(head);
	assert(head->dado == 0);
	assert(head->prox == NULL);

	lst aux = head;
	lst_insere_final(&head, 1);
	assert(head == aux);
	assert(head->dado == 0);
	assert(head->prox != NULL);
	assert(head->prox->dado == 1);
	assert(head->prox->prox == NULL);
	lst_destroi(&head);
}

void test_lst_inverte() {
	lst head = NULL;
	lst_inverte(&head);

	head = lst_cria(0, NULL);
	lst_inverte(&head);
	assert(head);
	assert(head->dado == 0);
	assert(head->prox == NULL);

	head = lst_cria(1, head);
	lst_inverte(&head);
	int current = 0;
	for (lst aux = head; aux != NULL; aux = aux->prox)
		assert(aux->dado == current++);
	lst_destroi(&head);

	head = cria(MAX);
	lst_inverte(&head);
	current = MAX - 1;
	for (lst aux = head; aux != NULL; aux = aux->prox)
		assert(aux->dado == current--);
	lst_destroi(&head);
}

void test_lst_len() {
	lst head = NULL;
	for (int i = 0; i < MAX; i++) {
		assert(lst_len(head) == i);
		lst_insere_inicio(&head, i);
	}
	assert(lst_len(head) == MAX);
	lst_destroi(&head);
}

void test_lst_remove_posicao() {
	lst head = NULL, aux;
	assert(lst_remove_posicao(&head, 0) == NULL);

	head = cria(MAX);
	for (int i = 0; i < MAX; i++) {
		aux = lst_remove_posicao(&head, 0);
		assert(aux);
		assert(lst_len(head) == MAX - i - 1);
		assert(aux->dado == i);
		free(aux);
	}
	assert(head == NULL);

	head = cria(MAX);
	for (int i = MAX - 1; i >= 0; i--) {
		aux = lst_remove_posicao(&head, i);
		assert(aux);
		assert(lst_len(head) == i);
		assert(aux->dado == i);
		free(aux);
	}
	assert(head == NULL);

	srand(time(NULL));
	head = cria(MAX);
	for (int i = 0; i < MAX; i++) {
		aux = lst_remove_posicao(&head, rand() % lst_len(head));
		assert(aux);
		assert(lst_busca(&head, aux->dado) == NULL);
		free(aux);
	}
	assert(head == NULL);
}

void test_lst_remove_todos() {
	lst head = NULL;
	lst_remove_todos(&head, 0);

	head = cria(MAX);
	for (int i = 0; i < MAX; i++) {
		// lst_print(head);
		lst_remove_todos(&head, i);
		// lst_print(head);
		// printf("len %d %d \n", lst_len(head), MAX - i - 1);
		assert(lst_len(head) == MAX - i - 1);
		assert(lst_busca(&head, i) == NULL);
	}
	assert(head == NULL);

	for (int i = 0; i < MAX; i++)
		lst_insere_inicio(&head, 0);
	lst_remove_todos(&head, 0);
	assert(head == NULL);

	for (int i = 0; i < MAX; i++) {
		lst_insere_inicio(&head, 0);
		lst_insere_inicio(&head, 1);
	}
	lst_remove_todos(&head, 1);
	assert(lst_len(head) == MAX);
	assert(lst_busca(&head, 1) == NULL);
	lst_remove_todos(&head, 0);
	assert(head == NULL);
}

void test_lst_remove_valor() {
	lst head = NULL, aux;
	assert(lst_remove_valor(&head, 0) == NULL);

	head = cria(MAX);
	for (int i = 0; i < MAX; i++) {
		aux = lst_remove_valor(&head, i);
		assert(aux);
		assert(lst_len(head) == MAX - i - 1);
		assert(aux->dado == i);
		free(aux);
	}
	assert(head == NULL);

	head = cria(MAX);
	for (int i = MAX - 1; i >= 0; i--) {
		aux = lst_remove_valor(&head, i);
		assert(aux);
		assert(lst_len(head) == i);
		assert(aux->dado == i);
		free(aux);
	}
	assert(head == NULL);
}

void test_lst_ultimo() {
	lst head = NULL;
	assert(lst_ultimo(&head) == NULL);

	for (int i = 0; i < MAX; i++) {
		lst_insere_final(&head, i);
		assert((*lst_ultimo(&head))->dado == i);
	}
	lst_destroi(&head);
}


int main() {
	test_lst_busca();
	test_lst_cria();
	test_lst_destroi();
	test_lst_insere_inicio();
	test_lst_insere_final();
	test_lst_inverte();
	test_lst_len();
	test_lst_remove_posicao();
	test_lst_remove_todos();
	test_lst_remove_valor();
	test_lst_ultimo();

	return 0;
}