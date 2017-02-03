#include <assert.h> /**< Necessário para uso da macro "assert" */
#include <cstdlib> /**< Necessário para uso do NULL */
#include "listaenc.hpp"

struct Noh {
	int item; /**< Representa a informação a ser armazenada em cada nó da lista. */
	Noh* prox; /**< É um ponteiro para o próximo nó da lista. */
};

struct ListaEnc {
    Noh* inicio; /**< É um ponteiro para o início da lista. */
    int tam; /**< Representa a quantidade de elementos da lista. */
};

ListaEnc* criar_lista() {
    /* 
	 * Caso não seja possível alocar o espaço solicitado, o próprio operador "new"
	 * irá lançar uma exceção abortando a execução do programa.
	 */
	ListaEnc* lista = new ListaEnc;    
    
    lista->inicio = NULL;
    lista->tam = 0;
    return lista;
}

void liberar_lista(ListaEnc* lista) {
    /* 
	 * Macro da biblioteca \file assert.h. Aborta a execução do programa e envia uma mensagem 
	 * de erro para a saída de erro padrão, caso a expressão entre parênteses seja avaliada 
	 * como false.
	*/
	assert(lista != NULL);
	
	// Libera a memória alocada para cada nó da lista individualmente.
	while(lista->inicio != NULL) {
		remover(lista, 0);
	}	
	delete lista;		
}

bool estah_vazia(ListaEnc* lista) {
    assert(lista != NULL);	
	
	return (lista->inicio == NULL);
}

void inserir(ListaEnc* lista, int item, int pos) {
    assert(lista != NULL);
	assert((pos >=0) and (pos <= lista->tam));
	
    Noh* novo_noh = new Noh;
    novo_noh->item = item;
    
    if (pos == 0) {		
        novo_noh->prox = lista->inicio;
        lista->inicio = novo_noh;
    } else {
        // Encontra o nó anterior à posição de inserção
        Noh* aux = lista->inicio;
        for(int i = 0; i < pos - 1; i++) {
            aux = aux->prox;
        }

        // Adiciona o novo nó
        novo_noh->prox = aux->prox;
        aux->prox = novo_noh;
    }
    lista->tam++;
}

int remover(ListaEnc* lista, int pos) {
    assert(lista != NULL);
	assert(!estah_vazia(lista));    
    assert((pos >=0) and (pos < lista->tam));
    
    Noh *ant, *aux;
    aux = lista->inicio;
        
    if (pos == 0) {
        lista->inicio = aux->prox;
    } else {
        for(int i = 0; i < pos; i++) {
            ant = aux;
            aux = aux->prox;
        }
        
        // Atualiza o ponteiro "prox" do nó "ant"
        ant->prox = aux->prox;       
    }
    
    // Remove o nó "aux"
    int item = aux->item;
    delete aux;
    lista->tam--;
    return item; 
}

int obter_elemento(ListaEnc* lista, int pos) {
    assert(lista != NULL);
	assert(!estah_vazia(lista));    
    assert((pos >=0) and (pos < lista->tam));
    
    Noh* aux = lista->inicio;
    for(int i = 0; i < pos; i++) {
        aux = aux->prox;
    }    
    return aux->item; 
}

int obter_tamanho(ListaEnc *lista) {
    assert(lista != NULL);

	return lista->tam;
}

