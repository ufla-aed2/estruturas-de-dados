#include <assert.h> /**< Necessário para uso da macro "assert" */
#include <cstdlib> /**< Necessário para uso do NULL */
#include "filadvet.hpp"

using namespace std;

struct FilaDVet {
	int itens[TAM_MAX]; /**< Vetor que armazena os elementos da fila. */            
	int inicio; /**< Variável que indica a posição do primeiro elemento da fila. */
	int fim; /**< Variável que indica a próxima posição vazia da fila. */
};

/* 
 * Retorna o próximo valor do índice i, de forma circular. 
 * Ou seja, se i == TAM_MAX - 1, retorn 0. Caso contrário, retorna i + 1.
 * A palavra-chave "static" na assinatura desta função garante que ela só estará disponível
 * para uso dentro deste arquivo.
 */
static int incrementar(int i) {
	return ((i + 1) % TAM_MAX);
}

/* 
 * Retorna o decremento do índice i, de forma circular. 
 * Ou seja, se i == 0, retorna TAM_MAX - 1. Caso contrário, retorna i - 1.
 * A palavra-chave "static" na assinatura desta função garante que ela só estará disponível
 * para uso dentro deste arquivo.
 */
static int decrementar(int i) {
	return ((i - 1 + TAM_MAX) % TAM_MAX);
}


FilaDVet* criar_fila_d() {
	/* 
	 * Caso não seja possível alocar o espaço solicitado, o próprio operador "new"
	 * irá lançar uma exceção abortando a execução do programa.
	 */
	FilaDVet* fila = new FilaDVet;
    
	fila->inicio = 0;
	fila->fim = 0;
	return fila;
}

void liberar_fila(FilaDVet* fila) {
	/* 
	 * Macro da biblioteca \file assert.h. Aborta a execução do programa e envia uma mensagem 
	 * de erro para a saída de erro padrão, caso a expressão entre parênteses seja avaliada 
	 * como false.
	*/
	assert(fila != NULL);
	
	delete fila;		
}

bool estah_cheia(FilaDVet* fila) {
	assert(fila != NULL);	
    
    /* Para a fila ser considerada cheia, o incremento de seu índice fim deve ser igual ao seu índice inicio */ 
	return (incrementar(fila->fim) == fila->inicio);
}

bool estah_vazia(FilaDVet* fila) {
	assert(fila != NULL);	
	
	/* Para a fila ser considerada vazia, seus índices inicio e fim devem ser iguais */ 
	return (fila->inicio == fila->fim);
}

void inserir_no_fim(FilaDVet* fila, int item) {
	assert(fila != NULL);
	assert(!estah_cheia(fila));    
    
	fila->itens[fila->fim] = item;
	
	/* Atenção para o incremento circular do índice fim da fila */
    fila->fim = incrementar(fila->fim);
}

int remover_do_inicio(FilaDVet* fila) {
	assert(fila != NULL);
	assert(!estah_vazia(fila));    
        
	int item = fila->itens[fila->inicio];
    
    /* Atenção para o incremento circular do índice inicio da fila */
    fila->inicio = incrementar(fila->inicio);
    return item;    
}

int obter_inicio(FilaDVet* fila) {
	assert(fila != NULL);
	assert(!estah_vazia(fila));    
    
	return fila->itens[fila->inicio];
}

void inserir_no_inicio(FilaDVet* fila, int item) {
	assert(fila != NULL);
	assert(!estah_cheia(fila));    
    
	/* Atenção para o decremento circular do índice inicio da fila */
    fila->inicio = decrementar(fila->inicio);
	fila->itens[fila->inicio] = item;	
}

int remover_do_fim(FilaDVet* fila) {
	assert(fila != NULL);
	assert(!estah_vazia(fila));    
    
    int item = fila->itens[decrementar(fila->fim)];
    
    /* Atenção para o decremento circular do índice fim da fila */
    fila->fim = decrementar(fila->fim);
	
    return item;    
}

int obter_fim(FilaDVet* fila) {
	assert(fila != NULL);
	assert(!estah_vazia(fila));    
    
    /* Atenção: a posição indicada pelo índice fim da fila não contém um item válido! */
	return fila->itens[decrementar(fila->fim)];
}
