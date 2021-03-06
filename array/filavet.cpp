#include <assert.h> /**< Necessário para uso da macro "assert" */
#include <cstdlib> /**< Necessário para uso do NULL */
#include "filavet.hpp"

using namespace std;

struct FilaVet {
	int itens[TAM_MAX]; /**< Vetor que armazena os elementos da fila. */            
	int inicio; /**< Variável que indica a posição do primeiro elemento da fila. */
	int fim; /**< Variável que indica a próxima posição vazia da fila. */
};

FilaVet* criar_fila() {
	/* 
	 * Caso não seja possível alocar o espaço solicitado, o próprio operador "new"
	 * irá lançar uma exceção abortando a execução do programa.
	 */
	FilaVet* fila = new FilaVet;
    
	fila->inicio = 0;
	fila->fim = 0;
	return fila;
}

void liberar_fila(FilaVet* fila) {
	/* 
	 * Macro da biblioteca \file assert.h. Aborta a execução do programa e envia uma mensagem 
	 * de erro para a saída de erro padrão, caso a expressão entre parênteses seja avaliada 
	 * como false.
	*/
	assert(fila != NULL);
	
	delete fila;		
}

bool estah_cheia(FilaVet* fila) {
	assert(fila != NULL);	
    
	/* Retorna o próximo valor do índice fila->fim, de forma circular. 
	 * Ou seja, se fila->fim == TAM_MAX - 1, retorna 0. Caso contrário, retorna fila->fim + 1. 
	 */
    int novo_fim = (fila->fim + 1) % TAM_MAX;
    
    /* Para a fila ser considerada cheia, o incremento de seu índice fim deve ser igual ao seu índice inicio */ 
	return (novo_fim == fila->inicio);
}

bool estah_vazia(FilaVet* fila) {
	assert(fila != NULL);	
	
	/* Para a fila ser considerada vazia, seus índices inicio e fim devem ser iguais */ 
	return (fila->inicio == fila->fim);
}

void inserir(FilaVet* fila, int item) {
	assert(fila != NULL);
	assert(!estah_cheia(fila));    
    
	fila->itens[fila->fim] = item;
	
	/* Atenção para o incremento circular do índice fim da fila */
    fila->fim = (fila->fim + 1) % TAM_MAX;
}

int remover(FilaVet* fila) {
	assert(fila != NULL);
	assert(!estah_vazia(fila));    
        
	int item = fila->itens[fila->inicio];
    
    /* Atenção para o incremento circular do índice inicio da fila */
    fila->inicio = (fila->inicio + 1) % TAM_MAX;
    return item;    
}

int obter_inicio(FilaVet* fila) {
	assert(fila != NULL);
	assert(!estah_vazia(fila));    
    
	return fila->itens[fila->inicio];
}
