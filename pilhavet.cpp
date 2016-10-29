#include <assert.h> /**< Necessário para uso da macro "assert". */
#include <cstdlib> /**< Necessário para uso do NULL. */
#include "PilhaVet.hpp"

using namespace std;

struct PilhaVet {
	int itens[TAM_MAX]; /**< Vetor que armazena os elementos da pilha. */        
	int topo; /**< Variável que indica a próxima posição vazia da pilha. */
};

PilhaVet* criar_pilha() {
	/* 
	 * Caso não seja possível alocar o espaço solicitado, o próprio operador "new"
	 * irá lançar uma exceção abortando a execução do programa.
	 */
	PilhaVet* pilha = new PilhaVet;
    
	pilha->topo = 0;
	return pilha;
}

void liberar_pilha(PilhaVet* pilha) {
	/* 
	 * Macro da biblioteca \file assert.h. Aborta a execução do programa e envia uma mensagem 
	 * de erro para a saída de erro padrão, caso a expressão entre parênteses seja avaliada 
	 * como false.
	 */
	assert(pilha != NULL);
	
	delete pilha;		
}

bool estah_cheia(PilhaVet* pilha) {
	assert(pilha != NULL);	
    
	return (pilha->topo == TAM_MAX);
}

bool estah_vazia(PilhaVet* pilha) {
	assert(pilha != NULL);	
	
	return (pilha->topo == 0);
}

void empilhar(PilhaVet* pilha, int item) {
	assert(pilha != NULL);
	assert(!estah_cheia(pilha));    
    
	pilha->itens[pilha->topo] = item;
	pilha->topo++;
}

int desempilhar(PilhaVet* pilha) {
	assert(pilha != NULL);
	assert(!estah_vazia(pilha));    
        
	int item = pilha->itens[pilha->topo - 1];
	pilha->topo--;
	return item;    
}

int obter_topo(PilhaVet* pilha) {
	assert(pilha != NULL);
	assert(!estah_vazia(pilha));    
    
	return pilha->itens[pilha->topo - 1];
}
