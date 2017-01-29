#include <assert.h> /**< Necessário para uso da macro "assert" */
#include <cstdlib> /**< Necessário para uso do NULL */
#include "filaenc.hpp"

struct Noh {
	int item; /**< Representa a informação a ser armazenada em cada nó da pilha. */
	Noh* prox; /**< É um ponteiro para o próximo nó da pilha. */
};

struct FilaEnc {
    Noh* inicio; /**< É um ponteiro para o início da fila. */
    Noh* fim; /**< É um ponteiro para o fim da fila. */
};

FilaEnc* criar_fila() {
	/* 
	 * Caso não seja possível alocar o espaço solicitado, o próprio operador "new"
	 * irá lançar uma exceção abortando a execução do programa.
	 */
	FilaEnc* fila = new FilaEnc;
    
	fila->inicio = NULL;
	fila->fim = NULL;
	return fila;
}

void liberar_fila(FilaEnc* fila) {
	/* 
	 * Macro da biblioteca \file assert.h. Aborta a execução do programa e envia uma mensagem 
	 * de erro para a saída de erro padrão, caso a expressão entre parênteses seja avaliada 
	 * como false.
	*/
	assert(fila != NULL);
	
	// Libera a memória alocada para cada nó da fila individualmente.
	while(fila->inicio != NULL) {
		remover(fila);
	}	
	delete fila;
}

bool estah_vazia(FilaEnc* fila) {
	assert(fila != NULL);	
	
	return (fila->inicio == NULL);
}

void inserir(FilaEnc* fila, int item) {
	assert(fila != NULL);
	
	Noh *novo_noh = new Noh;
	novo_noh->item = item;
	novo_noh->prox = NULL;
	
    if (fila->fim == NULL) {
        fila->inicio = novo_noh;
    } else {
        fila->fim->prox = novo_noh;
    } 
    fila->fim = novo_noh;
}

int remover(FilaEnc* fila) {
	assert(fila != NULL);
	assert(!estah_vazia(fila));    
        
	Noh* aux = fila->inicio;
    fila->inicio = aux->prox;
    int item = aux->item;
    if (fila->inicio == NULL) {
		fila->fim = NULL;
	}
    delete aux;
    return item;
}

int obter_inicio(FilaEnc* fila) {
	assert(fila != NULL);
	assert(!estah_vazia(fila));    
    
	return fila->inicio->item;
}
