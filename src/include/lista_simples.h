/**      @file: lista_simples.h
 *     @author: Guilherme N. Ramos (gnramos@unb.br)
 * @disciplina: CIC0090 Estruturas de Dados
 *
 * Interface para o uso de um vetor dinâmico.
 */

#ifndef UNB_CIC_ED_LISTA_SIMPLES_H
#define UNB_CIC_ED_LISTA_SIMPLES_H

/**
 * Registro para implementação de um elemento (nó) de uma lista ligada.
 */
typedef struct lst_no {
	int dado; 				///< Dado a ser armazenado no elemento.
	struct lst_no *prox;	///< Ponteiro para o próximo elemento da lista.
} lst_no;

/**
 * Alias para ponteiro para um @ref lst_no.
 */
typedef lst_no *lst;

/**
 * Busca por um valor em um vetor estático @b ordenado.
 *
 * @param[in] p_head ponteiro para uma lista
 * @param[in] x valor a ser buscado.
 * @param[out] p endereço do elemento com a primeira ocorrência de @x na lista, se houver, NULL caso contrário.
 */
lst *lst_busca(lst *p_head, int x);

/**
 * Cria um novo elemento de lista.
 *
 * @param[in] x valor a ser armazenado.
 * @param[in] prox ponteiro para o próximo elemento da lista.

 * @param[out] p endereço do elemento criado, se a memória foi alocada, NULL caso contrário.
 */
lst lst_cria(int x, lst prox);

/**
 * Esvazia a lista, liberando a memória de todos os elementos.
 *
 * Atualiza o conteúdo do ponteiro inicial para NULL.
 *
 * @param[in] p_head endereço do ponteiro inicial da lista.
 */
void lst_destroi(lst *p_head);

/**
 * Insere um valor no final da lista.
 *
 * @param[in] p_head endereço do ponteiro inicial da lista.
 * @param[in] x valor a ser armazenado.
 */
void lst_insere_final(lst *p_head, int x);

/**
 * Insere um valor no início da lista.
 *
 * @param[in] p_head endereço do ponteiro inicial da lista.
 * @param[in] x valor a ser armazenado.
 */
void lst_insere_inicio(lst *p_head, int x);

/**
 * Inverte a lista.
 *
 * @param[in] p_head endereço do ponteiro inicial da lista.
 */
void lst_inverte(lst *p_head);

/**
 * Retorna a quantidade de elementos da lista.
 *
 * @param[in] p_head endereço do ponteiro inicial da lista.
 */
int lst_len(lst head);

/**
 * Apresenta os elementos da lista na saída padrão.
 *
 * @param[in] p_head endereço do ponteiro inicial da lista.
 */
void lst_print(lst lst);

/**
 * Retorna um ponteiro para o último elemento da lista.
 *
 * @param[in] p_head endereço do ponteiro inicial da lista.
 */
lst *lst_ultimo(lst *p_head);

/**
 * Remove o elemento em uma posição específica.
 *
 * O elemento foi alocado dinamicamente e precisa ser destruído.
 *
 * @param[in] p_head endereço do ponteiro inicial da lista.
 * @param[in] i posição do elemento a ser removido.
 * @param[out] p endereço do elemento removido.
 */
lst lst_remove_posicao(lst *p_head, unsigned int i);

/**
 * Remove todos os elementos com o valor dado.
 *
 * Os elemento removidos são destruídos no processo.
 *
 * @param[in] p_head endereço do ponteiro inicial da lista.
 * @param[in] x valor dos elementos a serem removidos.
 */
void lst_remove_todos(lst *p_head, int x);

/**
 * Remove o elementos com a primeira ocorrência do valor dado.
 *
 * O elemento foi alocado dinamicamente e precisa ser destruído.
 *
 * @param[in] p_head endereço do ponteiro inicial da lista.
 * @param[in] x valor do elemento a ser removido.
 */

lst lst_remove_valor(lst *p_head, int x);

#endif // UNB_CIC_ED_LISTA_SIMPLES_H