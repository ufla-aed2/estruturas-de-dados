/**
 * \file listadenc.hpp
 * \author Prof. Paulo Afonso (pauloa.junior@dcc.ufla.br)
 * \date Fevereiro, 2017
 * \brief Interface do TAD ListaDEnc
 * 
 * Disponibiliza as funções necessárias para manipulação da estrutura de dados Lista Duplamente Encadeada.
 */
 
#ifndef LISTADENC_HPP
#define LISTADENC_HPP

/** 
 * \struct ListaDEnc
 * \brief Declaração opaca da estrutura de uma lista.
 * 
 * Isso significa que os detalhes de implementação desta estrutura estão escondidos do usuário do TAD. 
 * A definição da estrutura ListaDEnc encontra-se no arquivo \file listadenc.cpp.
 */
struct ListaDEnc;

/** 
 * \struct DNoh
 * \brief Declaração opaca da estrutura de um nó da lista.
 * 
 * Isso significa que os detalhes de implementação desta estrutura estão escondidos do usuário do TAD. 
 * A definição da estrutura Noh encontra-se no arquivo \file listadenc.cpp.
 */
struct DNoh;

/** 
 * \brief Cria dinamicamente uma lista vazia e retorna o endereço onde ela se encontra alocada.
 * 
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include "listadenc.hpp"

 * int main() {
 *     ListaDEnc *li = criar_listad();
 *     return EXIT_SUCCESS;
 * }  
 * \endcode
 * 
 * \return O endereço de memória da lista alocada dinamicamente.
 */
ListaDEnc* criar_listad();

/** 
 * \brief Libera o espaço de memória anteriormente reservado para a lista.
 *  
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include "listadenc.hpp"
 * 
 * int main() {
 *     ListaDEnc *li = criar_listad();
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
void liberar_lista(ListaDEnc* li);

/** 
 * \brief Verifica se a lista está vazia. 
 * 
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include<iostream>
 * #include "listadenc.hpp"
 * 
 * using namespace std;
 *
 * int main() {
 *     ListaDEnc *li = criar_listad();
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
bool estah_vazia(ListaDEnc* li);

/** 
 * \brief Insere um novo elemento em uma posição pré-determinada da lista.  
 *
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include<iostream>
 * #include "listadenc.hpp"
 * 
 * using namespace std;
 *
 * int main() {
 *     ListaDEnc *li = criar_listad();
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
void inserir(ListaDEnc* li, int item, int pos);

/** 
 * \brief Insere um novo elemento no início da lista.  
 *
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include<iostream>
 * #include "listadenc.hpp"
 * 
 * using namespace std;
 *
 * int main() {
 *     ListaDEnc *li = criar_listad();
 *     inserir_no_inicio(f, 2);
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
 * 
 * \return void
 * 
 * \warning O programa será abortado, caso o ponteiro \p *li seja igual a \p NULL.
 */
void inserir_no_inicio(ListaDEnc* li, int item);

/** 
 * \brief Insere um novo elemento no final da lista.  
 *
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include<iostream>
 * #include "listadenc.hpp"
 * 
 * using namespace std;
 *
 * int main() {
 *     ListaDEnc *li = criar_listad();
 *     inserir_no_fim(f, 2);
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
 * 
 * \return void
 * 
 * \warning O programa será abortado, caso o ponteiro \p *li seja igual a \p NULL.
 */
void inserir_no_fim(ListaDEnc* li, int item);

/** 
 * \brief Remove e retorna o elemento de uma posição pré-determinada da lista. 
 * 
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include<iostream>
 * #include "listadenc.hpp"
 * 
 * using namespace std;
 *
 * int main() {
 *     ListaDEnc *li = criar_listad();
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
int remover(ListaDEnc* li, int pos);

/** 
 * \brief Remove e retorna o elemento do início da lista. 
 * 
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include<iostream>
 * #include "listadenc.hpp"
 * 
 * using namespace std;
 *
 * int main() {
 *     ListaDEnc *li = criar_listad();
 *     inserir(f, 1, 0);
 *     inserir(f, 3, 1);
 *     inserir(f, 2, 1);
 *     while (!estah_vazia(li)) {
 *         cout << remover_inicio(li) << endl;
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
 * 
 * \return O elemento removido da posição \p pos da lista.
 * 
 * \warning O programa será abortado, caso o ponteiro \p *li seja igual a \p NULL ou
 * 			caso a lista esteja vazia.
 */
int remover_inicio(ListaDEnc* li);

/** 
 * \brief Remove e retorna o elemento do fim da lista. 
 * 
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include<iostream>
 * #include "listadenc.hpp"
 * 
 * using namespace std;
 *
 * int main() {
 *     ListaDEnc *li = criar_listad();
 *     inserir(f, 1, 0);
 *     inserir(f, 3, 1);
 *     inserir(f, 2, 1);
 *     while (!estah_vazia(li)) {
 *         cout << remover_fim(li) << endl;
 *     }
 *     liberar_lista(li);
 *     return EXIT_SUCCESS;
 * }  
 * \endcode
 * 
 * Saída esperada:
 * 
 * \code {.unparsed}
 *     3
 *     2
 *     1
 * \endcode
 * 
 * \pre O ponteiro \p *li deve ser diferente de \p NULL.
 * \pre A lista não deve estar vazia.
 * 
 * \param *li representa um ponteiro para a lista de onde o elemento será removido.
 * 
 * \return O elemento removido da posição \p pos da lista.
 * 
 * \warning O programa será abortado, caso o ponteiro \p *li seja igual a \p NULL ou
 * 			caso a lista esteja vazia.
 */
int remover_fim(ListaDEnc* li);

/** 
 * \brief Apenas retorna o elemento de uma posição pré-determinada da lista. 
 * 
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include<iostream>
 * #include "listadenc.hpp"
 * 
 * using namespace std;
 *
 * int main() {
 *     ListaDEnc *li = criar_listad();
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
int obter_elemento(ListaDEnc* li, int pos);

/** 
 * \brief Apenas retorna o elemento do início da lista. 
 * 
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include<iostream>
 * #include "listadenc.hpp"
 * 
 * using namespace std;
 *
 * int main() {
 *     ListaDEnc *li = criar_listad();
 *     inserir(f, 1, 0);
 *     inserir(f, 3, 1);
 *     inserir(f, 2, 1);
 *     while (!estah_vazia(li)) {
 *         cout << obter_inicio(li) << endl;
 *         remover_inicio(li);
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
 * 
 * \return O elemento da posição \p pos da lista.
 *
 * \warning O programa será abortado, caso o ponteiro \p *li seja igual a \p NULL ou
 * 			caso a lista esteja vazia.
 */
int obter_inicio(ListaDEnc* li);

/** 
 * \brief Apenas retorna o elemento do fim da lista. 
 * 
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include<iostream>
 * #include "listadenc.hpp"
 * 
 * using namespace std;
 *
 * int main() {
 *     ListaDEnc *li = criar_listad();
 *     inserir(f, 1, 0);
 *     inserir(f, 3, 1);
 *     inserir(f, 2, 1);
 *     while (!estah_vazia(li)) {
 *         cout << obter_fim(li) << endl;
 *         remover_inicio(li);
 *     }
 *     liberar_lista(li);
 *     return EXIT_SUCCESS;
 * }  
 * \endcode
 * 
 * Saída esperada:
 * 
 * \code {.unparsed}
 *     3
 *     2
 *     1
 * \endcode
 * 
 * \pre O ponteiro \p *li deve ser diferente de \p NULL.
 * \pre A lista não deve estar vazia.
 * \param *li representa um ponteiro para a lista de onde o elemento será obtido.
 * 
 * \return O elemento da posição \p pos da lista.
 *
 * \warning O programa será abortado, caso o ponteiro \p *li seja igual a \p NULL ou
 * 			caso a lista esteja vazia.
 */
int obter_fim(ListaDEnc* li);

/** 
 * \brief Retorna a quantidade de elementos da lista. 
 * 
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include<iostream>
 * #include "listadenc.hpp"
 * 
 * using namespace std;
 *
 * int main() {
 *     ListaDEnc *li = criar_listad();
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
int obter_tamanho(ListaDEnc* li);

#endif
