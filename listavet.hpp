/**
 * \file listavet.hpp
 * \author Prof. Paulo Afonso (pauloa.junior@dcc.ufla.br)
 * \date Outubro, 2016
 * \brief Interface do TAD ListaVet
 * 
 * Disponibiliza as funções necessárias para manipulação da estrutura de dados Lista.
 */
 
#ifndef LISTAVET_HPP
#define LISTAVET_HPP

/**
 * \def TAM_MAX 
 * \brief Define a quantidade máxima de elementos suportada pela lista.
 * \hideinitializer
 */
#define TAM_MAX 100 

/** 
 * \struct ListaVet
 * \brief Declaração opaca da estrutura da lista.
 * 
 * Isso significa que os detalhes de implementação desta estrutura estão escondidos do usuário do TAD. 
 * A definição da estrutura ListaVet encontra-se no arquivo \file listavet.cpp.
 */
struct ListaVet;

/** 
 * \brief Cria dinamicamente uma lista vazia e retorna o endereço onde ela se encontra alocada.
 * 
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include "listavet.hpp"

 * int main() {
 *     ListaVet *li = criar_lista();
 *     return EXIT_SUCCESS;
 * }  
 * \endcode
 * 
 * \return O endereço de memória da lista alocada dinamicamente.
 */
ListaVet* criar_lista();

/** 
 * \brief Libera o espaço de memória anteriormente reservado para a lista.
 *  
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include "listavet.hpp"
 * 
 * int main() {
 *     ListaVet *li = criar_lista();
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
void liberar_lista(ListaVet* li);

/** 
 * \brief Verifica se a lista está vazia. 
 * 
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include<iostream>
 * #include "listavet.hpp"
 * 
 * using namespace std;
 *
 * int main() {
 *     ListaVet *li = criar_lista();
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
bool estah_vazia(ListaVet* li);

/** 
 * \brief Verifica se a lista está cheia. 
 * 
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include<iostream>
 * #include "listavet.hpp"
 * 
 * using namespace std;
 *
 * int main() {
 *     ListaVet *li = criar_lista();
 *     if (!estah_cheia(li)) {
 *         cout << "Deu certo!" << endl;
 *     }
 *     liberar_lista(li);
 *     return EXIT_SUCCESS;
 * }  
 * \endcode
 * 
 * Saída esperada: 
 * \code {.unparsed}
 *     Deu certo!
 * \endcode 
 * 
 * \pre O ponteiro \p *li deve ser diferente de \p NULL.
 * 
 * \param *li representa um ponteiro para a lista cuja situação será consultada.
 * 
 * \return \p true, se a lista estiver cheia e \p false, caso contrário.
 * 
 * \warning O programa será abortado, caso o ponteiro \p *li seja igual a \p NULL.
*/
bool estah_cheia(ListaVet* li);

/** 
 * \brief Insere um novo elemento na lista.  
 * 
 * Tecnicamente falando, esta função insere um novo elemento em uma determinada posição de uma lista
 * previamente instanciada. A posição informada deve estar no intervalo [0, tamanho_da_lista]. 
 * A posição 0 indica que o elemento deve ser inserido no início da lista e a posição "tamanho_da_lista"
 * indica que o elemento será inserido no final da lista. 
 *
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include<iostream>
 * #include "listavet.hpp"
 * 
 * using namespace std;
 *
 * int main() {
 *     ListaVet *li = criar_lista();
 *     inserir(li, 2, 0);
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
 * \pre A lista não deve estar cheia.
 * \pre A posição \p pos deve ser Válida.
 *  
 * \param *li representa um ponteiro para a lista onde o elemento será inserido.
 * \param item representa o item a ser inserido na lista.
 * \param pos representa a posição onde o \p item deve ser inserido na lista. 
 * 
 * \return void
 * 
 * \warning O programa será abortado: 
 * 			1. caso o ponteiro \p *li seja igual a \p NULL; 
 * 			2. caso a lista esteja cheia; ou
 * 			3. caso a posição informada não INválida.
 */
void inserir(ListaVet* li, int item, int pos);

/** 
 * \brief Remove e retorna um elemento da lista.
 * 
 * Tecnicamente falando, esta função remove e retorna o elemento de uma determinada posição de uma lista
 * previamente instanciada. A posição informada deve estar no intervalo [0, tamanho_da_lista - 1]. 
 * A posição 0 indica que o elemento deve ser removido do início da lista e a posição "tamanho_da_lista - 1"
 * indica que o elemento será removido do final da lista.
 * 
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include<iostream>
 * #include "listavet.hpp"
 * 
 * using namespace std;
 *
 * int main() {
 *     ListaVet *li = criar_lista();
 *     inserir(li, 3, 0);
 *     inserir(li, 2, 0);
 *     inserir(li, 1, 0);
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
 * \pre A posição \p pos deve ser Válida.
 * 
 * \param *li representa um ponteiro para a lista de onde o elemento será removido.
 * \param pos representa a posição de onde o elemento deve ser removido da lista. 
 * 
 * \return O elemento removido da lista.
 * 
 * \warning O programa será abortado: 
 * 			1. caso o ponteiro \p *li seja igual a \p NULL; 
 * 			2. caso a lista esteja vazia; ou
 * 			3. caso a posição informada seja INválida.
 */
int remover(ListaVet* li, int pos);

/** 
 * \brief Retorna um elemento da lista.
 * 
 * Tecnicamente falando, esta função retorna (mas sem remover) o elemento de uma determinada posição de uma lista
 * previamente instanciada. A posição informada deve estar no intervalo [0, tamanho_da_lista - 1]. 
 * A posição 0 indica que o elemento deve ser obtido do início da lista e a posição "tamanho_da_lista - 1"
 * indica que o elemento será obtido do final da lista.
 * 
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include<iostream>
 * #include "listavet.hpp"
 * 
 * using namespace std;
 *
 * int main() {
 *     ListaVet *li = criar_lista();
 *     inserir(li, 3, 0);
 *     inserir(li, 2, 0);
 *     inserir(li, 1, 0);
 *     while (!estah_vazia(li)) {
 *         cout << obter(li, 0) << endl;
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
 * \pre A posição \p pos deve ser Válida.
 * 
 * \param *li representa um ponteiro para a lista de onde o elemento será obtido.
 * \param pos representa a posição de onde o elemento deve ser obtido da lista. 
 * 
 * \return O elemento obtido da lista.
 * 
 * \warning O programa será abortado: 
 * 			1. caso o ponteiro \p *li seja igual a \p NULL; 
 * 			2. caso a lista esteja vazia; ou
 * 			3. caso a posição informada seja INválida.
 */
int obter(ListaVet* li, int pos);

/** 
 * \brief Retorna a quantidade de elementos da lista.
 * 
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include<iostream>
 * #include "listavet.hpp"
 * 
 * using namespace std;
 *
 * int main() {
 *     ListaVet *li = criar_lista();
 *     cout << obter_tamanho(li) << endl;
 *     inserir(li, 3, 0);
 *     inserir(li, 2, 0);
 *     inserir(li, 1, 0);
 *     cout << obter_tamanho(li) << endl;
 *     liberar_lista(li);
 *     return EXIT_SUCCESS;
 * }  
 * \endcode
 * 
 * Saída esperada:
 * 
 * \code {.unparsed}
 *     0
 *     3
 * \endcode
 * 
 * \pre O ponteiro \p *li deve ser diferente de \p NULL.
 * 
 * \param *li representa um ponteiro para a lista de onde o elemento será obtido.
 * 
 * \return A quantidade de elementos da lista.
 * 
 * \warning O programa será abortado caso o ponteiro \p *li seja igual a \p NULL.
 */
int obter_tamanho(ListaVet* li);


#endif
