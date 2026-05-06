/**      @file: vetor_estatico.h
 *     @author: Guilherme N. Ramos (gnramos@unb.br)
 * @disciplina: CIC0090 Estruturas de Dados
 *
 * Interface para o uso de um vetor estático.
 */

#ifndef UNB_CIC_ED_VETOR_ESTATICO_H
#define UNB_CIC_ED_VETOR_ESTATICO_H

/**
 * Busca sequencial por um valor em um vetor estático.
 *
 * @param[in] ve ponteiro para o vetor estático
 * @param[in] n tamanho do vetor.
 * @param[in] x valor a ser buscado.
 * @param[out] i índice da primeira ocorrência de @x no vetor, se houver, -1 caso contrário.
 */
int ve_busca(int *ve, int n, int x);

/**
 * Busca binária por um valor em um vetor estático @b ordenado.
 *
 * @param[in] ve ponteiro para o vetor estático @b ordenado
 * @param[in] n tamanho do vetor.
 * @param[in] x valor a ser buscado.
 * @param[out] i índice da primeira ocorrência de @x no vetor, se houver, -1 caso contrário.
 */
int ve_busca_binaria(int *ve , int n, int x);

/**
 * Transforma o vetor em um @a heap.
 *
 * O @h heap é de mímino, ou seja, um elemento no índice @a i é menor ou igual
 * aos elementos nos índices 2i+1 e 2i+2.
 *
 * @param[in] ve ponteiro para o vetor estático
 * @param[in] n tamanho do vetor.
 */
void ve_heap_make(int *ve, int n);

/**
 * "Empurra" o elemento no índice @p parent para a frente no vetor.
 *
 * Garante, recursivamente, que o elemento no índice @a i (@p parent) é menor ou
 * igual aos elementos nos índices 2i+1 e 2i+2 (e assim sucessivamente).
 *
 * @param[in] ve ponteiro para o vetor estático @b ordenado
 * @param[in] n tamanho do vetor.
 * @param[in] parent índice do elemento a ser processado
 */
void ve_heap_push_down(int *ve, int n, int parent);

void ve_preenche_crescente(int *ve, int n);
void ve_preenche_decrescente(int *ve, int n);
void ve_print(int *ve, int n);

#endif /* UNB_CIC_ED_VETOR_ESTATICO_H */