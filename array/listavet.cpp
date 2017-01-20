#include <assert.h> /**< Necessário para uso da macro "assert". */
#include <cstdlib> /**< Necessário para uso do NULL. */
#include "listavet.hpp"

using namespace std;

struct ListaVet {
	int itens[TAM_MAX]; /**< Vetor que armazena os elementos da lista. */        
	int ultimo; /**< Variável que indica a próxima posição vazia da lista. */
};

ListaVet* criar_lista() {
	/* 
	 * Caso não seja possível alocar o espaço solicitado, o próprio operador "new"
	 * irá lançar uma exceção abortando a execução do programa.
	 */
	ListaVet* lista = new ListaVet;
    
	lista->ultimo = 0;
	return lista;
}

void liberar_lista(ListaVet* lista) {
	/* 
	 * Macro da biblioteca \file assert.h. Aborta a execução do programa e envia uma mensagem 
	 * de erro para a saída de erro padrão, caso a expressão entre parênteses seja avaliada 
	 * como false.
	 */
	assert(lista != NULL);
	
	delete lista;		
}

bool estah_cheia(ListaVet* lista) {
	assert(lista != NULL);	
    
	return (lista->ultimo == TAM_MAX);
}

bool estah_vazia(ListaVet* lista) {
	assert(lista != NULL);	
	
	return (lista->ultimo == 0);
}

void inserir(ListaVet* lista, int item, int pos) {
	assert(lista != NULL);
	assert(!estah_cheia(lista)); 
	
	/* Garante que a posição passada por parâmetro seja válida. */
	assert((pos >= 0) && (pos <= lista->ultimo));   
    
	/* Laço responsável por deslocar os elementos da lista uma posição para a direita. */
    for(int i = lista->ultimo; i > pos; i--)  {
        lista->itens[i] = lista->itens[i - 1];
    }
    
    lista->itens[pos] = item;
    lista->ultimo++;
}

int remover(ListaVet* lista, int pos) {
	assert(lista != NULL);
	assert(!estah_vazia(lista)); 
	
	/* Garante que a posição passada por parâmetro seja válida. */
	assert((pos >= 0) && (pos < lista->ultimo));      
        
	int item = lista->itens[pos];
    
    /* Laço responsável por deslocar os elementos da lista uma posição para a esquerda. */
    for(int i = pos; i < (lista->ultimo - 1); i++)  {
        lista->itens[i] = lista->itens[i + 1];
    }
    
    lista->ultimo--;
    return item;   
}

int obter(ListaVet* lista, int pos) {
	assert(lista != NULL);
	assert(!estah_vazia(lista));    
    
    /* Garante que a posição passada por parâmetro seja válida. */
	assert((pos >= 0) && (pos < lista->ultimo));      
    
	return lista->itens[pos];
}

int obter_tamanho(ListaVet* lista) {
	assert(lista != NULL);
	
	return lista->ultimo;
}
