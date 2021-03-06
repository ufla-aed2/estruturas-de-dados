/**
 * \file pilhavet.hpp
 * \author Prof. Paulo Afonso (pauloa.junior@dcc.ufla.br)
 * \date Outubro, 2016
 * \brief Interface do TAD PilhaVet
 * 
 * Disponibiliza as funções necessárias para manipulação da estrutura de dados Pilha.
 */
 
#ifndef PILHAVET_HPP
#define PILHAVET_HPP

/**
 * \def TAM_MAX 
 * \brief Define a quantidade máxima de elementos suportada pela pilha.
 * \hideinitializer
 */
#define TAM_MAX 1000000 

/** 
 * \struct PilhaVet
 * \brief Declaração opaca da estrutura de uma pilha.
 * 
 * Isso significa que os detalhes de implementação desta estrutura estão escondidos do usuário do TAD. 
 * A definição da estrutura PilhaVet encontra-se no arquivo \file pilhavet.cpp.
 */
struct PilhaVet;

/** 
 * \brief Cria dinamicamente uma pilha vazia e retorna o endereço onde ela se encontra alocada.
 * 
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include "pilhavet.hpp"

 * int main() {
 *     PilhaVet *p = criar_pilha();
 *     return EXIT_SUCCESS;
 * }  
 * \endcode
 * 
 * \return O endereço de memória da pilha alocada dinamicamente.
 */
PilhaVet* criar_pilha();

/** 
 * \brief Libera o espaço de memória anteriormente reservado para a pilha.
 *  
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include "pilhavet.hpp"
 * 
 * int main() {
 *     PilhaVet *p = criar_pilha();
 *     liberar_pilha(p);
 *     return EXIT_SUCCESS;
 * }  
 * \endcode
 * 
 * \pre O ponteiro \p *p deve ser diferente de \p NULL.
 * 
 * \param *p representa um ponteiro para a pilha a ser liberada da memória.
 * 
 * \return void
 * 
 * \warning O programa será abortado, caso o ponteiro \p *p seja igual a \p NULL.
 */
void liberar_pilha(PilhaVet* p);

/** 
 * \brief Verifica se a pilha está vazia. 
 * 
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include<iostream>
 * #include "pilhavet.hpp"
 * 
 * using namespace std;
 *
 * int main() {
 *     PilhaVet *p = criar_pilha();
 *     if (estah_vazia(p)) {
 *         cout << "Deu certo!" << endl;
 *     }
 *     liberar_pilha(p);
 *     return EXIT_SUCCESS;
 * }  
 * \endcode
 * 
 * Saída esperada: 
 * \code {.unparsed}
 * 		Deu certo!
 * \endcode 
 * 
 * \pre O ponteiro \p *p deve ser diferente de \p NULL.
 * 
 * \param *p representa um ponteiro para a pilha cuja situação será consultada.
 * 
 * \return \p true, se a pilha estiver vazia e \p false, caso contrário.
 * 
 * \warning O programa será abortado, caso o ponteiro \p *p seja igual a \p NULL.
*/
bool estah_vazia(PilhaVet* p);

/** 
 * \brief Verifica se a pilha está cheia. 
 * 
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include<iostream>
 * #include "pilhavet.hpp"
 * 
 * using namespace std;
 *
 * int main() {
 *     PilhaVet *p = criar_pilha();
 *     if (!estah_cheia(p)) {
 *         cout << "Deu certo!" << endl;
 *     }
 *     liberar_pilha(p);
 *     return EXIT_SUCCESS;
 * }  
 * \endcode
 * 
 * Saída esperada: 
 * \code {.unparsed}
 *     Deu certo!
 * \endcode 
 * 
 * \pre O ponteiro \p *p deve ser diferente de \p NULL.
 * 
 * \param *p representa um ponteiro para a pilha cuja situação será consultada.
 * 
 * \return \p true, se a pilha estiver cheia e \p false, caso contrário.
 * 
 * \warning O programa será abortado, caso o ponteiro \p *p seja igual a \p NULL.
*/
bool estah_cheia(PilhaVet* p);

/** 
 * \brief Insere um novo elemento na pilha.  
 *
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include<iostream>
 * #include "pilhavet.hpp"
 * 
 * using namespace std;
 *
 * int main() {
 *     PilhaVet *p = criar_pilha();
 *     empilhar(p, 2);
 *     if (!estah_vazia(p)) {
 *         cout << "Deu certo!" << endl;
 *     }
 *     liberar_pilha(p);
 *     return EXIT_SUCCESS;
 * }  
 * \endcode
 * 
 * Saída esperada: 
 * \code {.unparsed}
 * 		Deu certo!
 * \endcode
 * 
 * \pre O ponteiro \p *p deve ser diferente de \p NULL.
 * \pre A pilha não deve estar cheia.
 *  
 * \param *p representa um ponteiro para a pilha onde o elemento será inserido.
 * \param item representa o item a ser inserido na pilha.
 * 
 * \return void
 * 
 * \warning O programa será abortado, caso o ponteiro \p *p seja igual a \p NULL, ou
 * 			caso a pilha esteja cheia.
 */
void empilhar(PilhaVet* p, int item);

/** 
 * \brief Remove e retorna o elemento do topo da pilha. 
 * 
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include<iostream>
 * #include "pilhavet.hpp"
 * 
 * using namespace std;
 *
 * int main() {
 *     PilhaVet *p = criar_pilha();
 *     empilhar(p, 1);
 *     empilhar(p, 2);
 *     empilhar(p, 3);
 *     while (!estah_vazia(p)) {
 *         cout << desempilhar(p) << endl;
 *     }
 *     liberar_pilha(p);
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
 * \pre O ponteiro \p *p deve ser diferente de \p NULL.
 * \pre A pilha não deve estar vazia.
 * 
 * \param *p representa um ponteiro para a pilha de onde o elemento será removido.
 * 
 * \return O elemento removido do topo da pilha.
 * 
 * \warning O programa será abortado, caso o ponteiro \p *p seja igual a \p NULL, ou
 * 			caso a pilha esteja vazia.
 */
int desempilhar(PilhaVet* p);

/** 
 * \brief Apenas retorna o elemento do topo da pilha. 
 * 
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include<iostream>
 * #include "pilhavet.hpp"
 * 
 * using namespace std;
 *
 * int main() {
 *     PilhaVet *p = criar_pilha();
 *     empilhar(p, 1);
 *     empilhar(p, 2);
 *     empilhar(p, 3);
 *     while (!estah_vazia(p)) {
 *         cout << obter_topo(p) << endl;
 *         desempilhar(p);
 *     }
 *     liberar_pilha(p);
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
 * \pre O ponteiro \p *p deve ser diferente de \p NULL.
 * \pre A pilha não deve estar vazia.
 
 * \param *p representa um ponteiro para a pilha de onde o elemento será obtido.
 * 
 * \return O elemento do topo da pilha.
 *
 * \warning O programa será abortado, caso o ponteiro \p *p seja igual a \p NULL ou 
 * 	    caso a pilha esteja vazia
 */
int obter_topo(PilhaVet* p);

#endif
