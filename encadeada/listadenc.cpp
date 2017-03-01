#include <assert.h> /**< Necessário para uso da macro "assert" */
#include <cstdlib> /**< Necessário para uso do NULL */
#include "listadenc.hpp"

struct DNoh {
	int item; /**< Representa a informação a ser armazenada em cada nó da lista. */
	DNoh* ant; /**< É um ponteiro para o nó anterior. */
	DNoh* prox; /**< É um ponteiro para o próximo nó da lista. */
};

struct ListaDEnc {
    DNoh* inicio; /**< É um ponteiro para o início da lista. */
    DNoh* fim; /**< É um ponteiro para o fim da lista. */
    int tam; /**< Representa a quantidade de elementos da lista. */
};

ListaDEnc* criar_listad() {
    /* 
	 * Caso não seja possível alocar o espaço solicitado, o próprio operador "new"
	 * irá lançar uma exceção abortando a execução do programa.
	 */
	ListaDEnc* lista = new ListaDEnc;    
    
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tam = 0;
    return lista;
}

void liberar_lista(ListaDEnc* lista) {
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

bool estah_vazia(ListaDEnc* lista) {
    assert(lista != NULL);	
	
	return (lista->inicio == NULL);
}

/* 
* Função criada para ser usada apenas dentro do arquivo listadenc.cpp.
* Por isso, ela recebe a palavra-chave static, antes do tipo de retorno.
*/
static DNoh* criar_noh(int item, DNoh* ant, DNoh* prox) {
	DNoh* novo_noh = new DNoh;
	novo_noh->item = item;
	novo_noh->ant = ant;
	novo_noh->prox = prox;
	return novo_noh;
}


void inserir_no_inicio(ListaDEnc* lista, int item) {
	assert(lista != NULL);
	
	DNoh* novo_noh = criar_noh(item, NULL, lista->inicio);
	
    if (lista->inicio == NULL) {
		lista->fim = novo_noh;
    } else {         
        lista->inicio->ant = novo_noh;
    }
    lista->inicio = novo_noh;
    
    lista->tam++;
}

void inserir_no_fim(ListaDEnc* lista, int item) {
	assert(lista != NULL);
	
	DNoh* novo_noh = criar_noh(item, lista->fim, NULL);
	
    if (lista->fim == NULL) {
		lista->inicio = novo_noh;
    } else {         
        lista->fim->prox = novo_noh;
    }
    lista->fim = novo_noh;
    
    lista->tam++;
}


void inserir(ListaDEnc* lista, int item, int pos) {
    assert(lista != NULL);
	assert((pos >= 0) and (pos <= lista->tam));
	
    if (pos == 0) {		
       inserir_no_inicio(lista, item);
    } else if (pos == lista->tam) {
		inserir_no_fim(lista, item);
	} else {
		// Encontra o nó localizado na posição de inserção
        DNoh* aux = lista->inicio;
        for(int i = 0; i < pos; i++) {
            aux = aux->prox;
        }

        DNoh* novo_noh = criar_noh(item, aux->ant, aux);
        aux->ant->prox = novo_noh; 
        aux->ant = novo_noh;
        
        lista->tam++;
    }
}

int remover_inicio(ListaDEnc* lista) {
    assert(lista != NULL);
	assert(!estah_vazia(lista));
	
    DNoh* aux = lista->inicio;
    lista->inicio = lista->inicio->prox;
    
    if (lista->inicio == NULL) {
        lista->fim = NULL;
    } else {
        lista->inicio->ant = NULL;
    }
     
    int item = aux->item;
    delete aux;
    lista->tam--;
    
    return item; 
}

int remover_fim(ListaDEnc* lista) {
    assert(lista != NULL);
	assert(!estah_vazia(lista));
	
	DNoh* aux = lista->fim;
    lista->fim = lista->fim->ant;
    
    if (lista->fim == NULL) {
        lista->inicio = NULL;
    } else {
        lista->fim->prox = NULL;
    }
     
    int item = aux->item;
    delete aux;
    lista->tam--;
    
    return item; 
}

int remover(ListaDEnc* lista, int pos) {
    assert(lista != NULL);
	assert((pos >= 0) and (pos < lista->tam));
	assert(!estah_vazia(lista));
	
    if (pos == 0) {		
		return remover_inicio(lista);
    } else if (pos == lista->tam - 1) {
		return remover_fim(lista);
	} else {
		// Encontra o nó localizado na posição de remoção
        DNoh* aux = lista->inicio;
        for(int i = 0; i < pos; i++) {
            aux = aux->prox;
        }
        
        aux->ant->prox = aux->prox;
        aux->prox->ant = aux->ant;

		int item = aux->item;
		delete aux;
		lista->tam--;
    
		return item; 
    } 
}

int obter_inicio(ListaDEnc* lista) {
    assert(lista != NULL);
	assert(!estah_vazia(lista));
	
	return lista->inicio->item;
}

int obter_fim(ListaDEnc* lista) {
    assert(lista != NULL);
	assert(!estah_vazia(lista));
	
	return lista->fim->item;
}

int obter_elemento(ListaDEnc* lista, int pos) {
    assert(lista != NULL);
	assert((pos >= 0) and (pos < lista->tam));
	assert(!estah_vazia(lista));
	
	if (pos == 0) {		
		return obter_inicio(lista);
    } else if (pos == lista->tam - 1) {
		return obter_fim(lista);
	} else {
		// Encontra o nó localizado na posição de remoção
        DNoh* aux = lista->inicio;
        for(int i = 0; i < pos; i++) {
            aux = aux->prox;
        }
        
        return aux->item; 
    }
}

int obter_tamanho(ListaDEnc *lista) {
    assert(lista != NULL);

	return lista->tam;
}

