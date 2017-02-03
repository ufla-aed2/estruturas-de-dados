#ifndef LISTAENC_HPP
#define LISTAENC_HPP

// declaração prévia da estrutura Noh, que representa
// cada elemento da lista
struct Noh;

// declaração prévia da estrutura de uma lista
struct ListaEnc;

ListaEnc* criarLista();
void liberarLista(ListaEnc* lista);
bool estahVazia(ListaEnc* lista);
void inserir(ListaEnc* lista, int item, int pos);
int remover(ListaEnc* lista, int pos);
int obterElemento(ListaEnc* lista, int pos);
int obterTamanho(ListaEnc *lista);

#endif // LISTAENC_HPP
