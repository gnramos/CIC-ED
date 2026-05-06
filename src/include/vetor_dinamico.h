/**      @file: vetor_dinamico.h
 *     @author: Guilherme N. Ramos (gnramos@unb.br)
 * @disciplina: CIC0090 Estruturas de Dados
 *
 * Interface para o uso de um vetor dinâmico.
 */

#ifndef UNB_CIC_ED_VETOR_DINAMICO_H
#define UNB_CIC_ED_VETOR_DINAMICO_H

/**
 * Registro para implementação de um vetor dinâmico.
 */
typedef struct {
	int *dados;		///< Vetor a ser alocado para armazenar os dados.
	int n;			///< Quantidade de elementos armazenados no vetor.
	int alocado;	///< Quantidade total de elementos que podem ser armazenados no vetor.
} vetor_dinamico;

/**
 * Alias para ponteiro para um @ref vetor_dinamico.
 */
typedef vetor_dinamico *p_vd;

 int vd_busca(p_vd vd, int x);
 int vd_busca_binaria(p_vd vd, int x);
p_vd vd_cria(int tam);
void vd_destroi(p_vd *vd);
void vd_insere(p_vd vd, int x);
void vd_insere_ord(p_vd vd, int x);
void vd_print(p_vd vd);
void vd_remove(p_vd vd, int i);
void vd_remove_ord(p_vd vd, int i);

#endif // UNB_CIC_ED_VETOR_DINAMICO_H