/**
 * \file listaenc.hpp
 * \author Prof. Paulo Afonso (pauloa.junior@dcc.ufla.br)
 * \date Janeiro, 2017
 * \brief Interface do TAD ListaEnc
 * 
 * Disponibiliza as funções necessárias para manipulação da estrutura de dados Lista Simplesmente Encadeada.
 */
 
#ifndef LISTAENC_HPP
#define LISTAENC_HPP

/** 
 * \struct ListaEnc
 * \brief Declaração opaca da estrutura de uma lista.
 * 
 * Isso significa que os detalhes de implementação desta estrutura estão escondidos do usuário do TAD. 
 * A definição da estrutura ListaEnc encontra-se no arquivo \file ListaEnc.cpp.
 */
struct ListaEnc;

/** 
 * \struct Noh
 * \brief Declaração opaca da estrutura de um nó da lista.
 * 
 * Isso significa que os detalhes de implementação desta estrutura estão escondidos do usuário do TAD. 
 * A definição da estrutura Noh encontra-se no arquivo \file listaenc.cpp.
 */
struct Noh;

/** 
 * \brief Cria dinamicamente uma lista vazia e retorna o endereço onde ela se encontra alocada.
 * 
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include "listaenc.hpp"

 * int main() {
 *     ListaEnc *li = criar_lista();
 *     return EXIT_SUCCESS;
 * }  
 * \endcode
 * 
 * \return O endereço de memória da lista alocada dinamicamente.
 */
ListaEnc* criar_lista();

/** 
 * \brief Libera o espaço de memória anteriormente reservado para a lista.
 *  
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include "listaenc.hpp"
 * 
 * int main() {
 *     ListaEnc *li = criar_lista();
 *     liberar_lista(li);
 *     return EXIT_SUCCESS;
 * }  
 * \endcode
 * 
 * \pre O ponteiro \p *li deve ser diferente de \p NULL.
 * 
 * \param *li representa um ponteiro para a lista a ser liberada da memória.
 * 
 * \return void
 * 
 * \warning O programa será abortado, caso o ponteiro \p *li seja igual a \p NULL.
 */
void liberar_lista(ListaEnc* li);

/** 
 * \brief Verifica se a lista está vazia. 
 * 
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include<iostream>
 * #include "listaenc.hpp"
 * 
 * using namespace std;
 *
 * int main() {
 *     ListaEnc *li = criar_lista();
 *     if (estah_vazia(li)) {
 *         cout << "Deu certo!" << endl;
 *     }
 *     liberar_lista(li);
 *     return EXIT_SUCCESS;
 * }  
 * \endcode
 * 
 * Saída esperada: 
 * \code {.unparsed}
 * 		Deu certo!
 * \endcode 
 * 
 * \pre O ponteiro \p *li deve ser diferente de \p NULL.
 * 
 * \param *li representa um ponteiro para a lista cuja situação será consultada.
 * 
 * \return \p true, se a lista estiver vazia e \p false, caso contrário.
 * 
 * \warning O programa será abortado, caso o ponteiro \p *li seja igual a \p NULL.
*/
bool estah_vazia(ListaEnc* li);

/** 
 * \brief Insere um novo elemento em uma posição pré-determinada da lista.  
 *
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include<iostream>
 * #include "listaenc.hpp"
 * 
 * using namespace std;
 *
 * int main() {
 *     ListaEnc *li = criar_lista();
 *     inserir(f, 2, 0);
 *     inserir(f, 4, 1); 
 *     if (!estah_vazia(li)) {
 *         cout << "Deu certo!" << endl;
 *     }
 *     liberar_lista(li);
 *     return EXIT_SUCCESS;
 * }  
 * \endcode
 * 
 * Saída esperada: 
 * \code {.unparsed}
 * 		Deu certo!
 * \endcode
 * 
 * \pre O ponteiro \p *li deve ser diferente de \p NULL.
 *  
 * \param *li representa um ponteiro para a lista onde o elemento será inserido.
 * \param item representa o item a ser inserido na lista.
 * \param pos representa a posição onde o elemento será inserido na lista, 
 * 		  sendo 0 a posição inicial da lista e TAM a posição, onde TAM refere-se à qantidade de elementos da lista.
 * 
 * \return void
 * 
 * \warning O programa será abortado, caso o ponteiro \p *li seja igual a \p NULL.
 * \warning O programa será abortado, caso o valor do parâmetro \p pos seja menor do que 0 ou maior do que TAM, onde TAM refere-se à qantidade de elementos da lista.
 */
void inserir(ListaEnc* li, int item, int pos);

/** 
 * \brief Remove e retorna o elemento de uma posição pré-determinada da lista. 
 * 
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include<iostream>
 * #include "listaenc.hpp"
 * 
 * using namespace std;
 *
 * int main() {
 *     ListaEnc *li = criar_lista();
 *     inserir(f, 1, 0);
 *     inserir(f, 3, 1);
 *     inserir(f, 2, 1);
 *     while (!estah_vazia(li)) {
 *         cout << remover(li, 0) << endl;
 *     }
 *     liberar_lista(li);
 *     return EXIT_SUCCESS;
 * }  
 * \endcode
 * 
 * Saída esperada:
 * 
 * \code {.unparsed}
 *     1
 *     2
 *     3
 * \endcode
 * 
 * \pre O ponteiro \p *li deve ser diferente de \p NULL.
 * \pre A lista não deve estar vazia.
 * 
 * \param *li representa um ponteiro para a lista de onde o elemento será removido.
 * \param pos representa a posição do elemento a ser removido na lista, 
 * 		  sendo 0 a posição do primeiro elemento da lista e TAM - 1 a posição do último, onde TAM refere-se à qantidade de elementos da lista.
 * 
 * \return O elemento removido da posição \p pos da lista.
 * 
 * \warning O programa será abortado, caso o ponteiro \p *li seja igual a \p NULL ou
 * 			caso a lista esteja vazia.
 * \warning O programa será abortado, caso o valor do parâmetro \p pos seja menor do que 0 ou maior do que TAM - 1, onde TAM refere-se à qantidade de elementos da lista.
 */
int remover(ListaEnc* li, int pos);

/** 
 * \brief Apenas retorna o elemento de uma posição pré-determinada da lista. 
 * 
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include<iostream>
 * #include "listaenc.hpp"
 * 
 * using namespace std;
 *
 * int main() {
 *     ListaEnc *li = criar_lista();
 *     inserir(f, 1, 0);
 *     inserir(f, 3, 1);
 *     inserir(f, 2, 1);
 *     while (!estah_vazia(li)) {
 *         cout << obter_inicio(li, 0) << endl;
 *         remover(li, 0);
 *     }
 *     liberar_lista(li);
 *     return EXIT_SUCCESS;
 * }  
 * \endcode
 * 
 * Saída esperada:
 * 
 * \code {.unparsed}
 *     1
 *     2
 *     3
 * \endcode
 * 
 * \pre O ponteiro \p *li deve ser diferente de \p NULL.
 * \pre A lista não deve estar vazia.
 * \param *li representa um ponteiro para a lista de onde o elemento será obtido.
 * \param pos representa a posição do elemento a ser retornado na lista, 
 * 		  sendo 0 a posição do primeiro elemento da lista e TAM - 1 a posição do último, onde TAM refere-se à qantidade de elementos da lista.
 * 
 * \return O elemento da posição \p pos da lista.
 *
 * \warning O programa será abortado, caso o ponteiro \p *li seja igual a \p NULL ou
 * 			caso a lista esteja vazia.
 * \warning O programa será abortado, caso o valor do parâmetro \p pos seja menor do que 0 ou maior do que TAM - 1, onde TAM refere-se à qantidade de elementos da lista.
 */
int obter_elemento(ListaEnc* li, int pos);

/** 
 * \brief Retorna a quantidade de elementos da lista. 
 * 
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include<iostream>
 * #include "listaenc.hpp"
 * 
 * using namespace std;
 *
 * int main() {
 *     ListaEnc *li = criar_lista();
 *     inserir(f, 1, 0);
 *     inserir(f, 3, 1);
 *     inserir(f, 2, 1);
 *     cout << obter_tamanho(li) << endl;
 *     liberar_lista(li);
 *     return EXIT_SUCCESS;
 * }  
 * \endcode
 * 
 * Saída esperada:
 * 
 * \code {.unparsed}
 *     3
 * \endcode
 * 
 * \pre O ponteiro \p *li deve ser diferente de \p NULL.
 * \param *li representa um ponteiro para a lista cuja quantidade de elementos será obtida.
 * 
 * \return A quantidade de elementos existentes na lista.
 *
 * \warning O programa será abortado, caso o ponteiro \p *li seja igual a \p NULL ou
 * 			caso a lista esteja vazia.
 */
int obter_tamanho(ListaEnc* li);

#endif
