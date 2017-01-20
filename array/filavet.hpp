/**
 * \file filavet.hpp
 * \author Prof. Paulo Afonso (pauloa.junior@dcc.ufla.br)
 * \date Outubro, 2016
 * \brief Interface do TAD FilaVet
 * 
 * Disponibiliza as funções necessárias para manipulação da estrutura de dados Fila.
 */
 
#ifndef FILAVET_HPP
#define FILAVET_HPP

/**
 * \def TAM_MAX 
 * \brief Define a quantidade máxima de elementos suportada pela fila.
 * \hideinitializer
 */
#define TAM_MAX 100 

/** 
 * \struct FilaVet
 * \brief Declaração opaca da estrutura de uma fila.
 * 
 * Isso significa que os detalhes de implementação desta estrutura estão escondidos do usuário do TAD. 
 * A definição da estrutura FilaVet encontra-se no arquivo \file filavet.cpp.
 */
struct FilaVet;

/** 
 * \brief Cria dinamicamente uma fila vazia e retorna o endereço onde ela se encontra alocada.
 * 
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include "filavet.hpp"

 * int main() {
 *     FilaVet *f = criar_fila();
 *     return EXIT_SUCCESS;
 * }  
 * \endcode
 * 
 * \return O endereço de memória da fila alocada dinamicamente.
 */
FilaVet* criar_fila();

/** 
 * \brief Libera o espaço de memória anteriormente reservado para a fila.
 *  
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include "filavet.hpp"
 * 
 * int main() {
 *     FilaVet *f = criar_fila();
 *     liberar_fila(f);
 *     return EXIT_SUCCESS;
 * }  
 * \endcode
 * 
 * \pre O ponteiro \p *f deve ser diferente de \p NULL.
 * 
 * \param *f representa um ponteiro para a fila a ser liberada da memória.
 * 
 * \return void
 * 
 * \warning O programa será abortado, caso o ponteiro \p *f seja igual a \p NULL.
 */
void liberar_fila(FilaVet* f);

/** 
 * \brief Verifica se a fila está vazia. 
 * 
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include<iostream>
 * #include "filavet.hpp"
 * 
 * using namespace std;
 *
 * int main() {
 *     FilaVet *f = criar_fila();
 *     if (estah_vazia(f)) {
 *         cout << "Deu certo!" << endl;
 *     }
 *     liberar_fila(f);
 *     return EXIT_SUCCESS;
 * }  
 * \endcode
 * 
 * Saída esperada: 
 * \code {.unparsed}
 * 		Deu certo!
 * \endcode 
 * 
 * \pre O ponteiro \p *f deve ser diferente de \p NULL.
 * 
 * \param *f representa um ponteiro para a fila cuja situação será consultada.
 * 
 * \return \p true, se a fila estiver vazia e \p false, caso contrário.
 * 
 * \warning O programa será abortado, caso o ponteiro \p *f seja igual a \p NULL.
*/
bool estah_vazia(FilaVet* f);

/** 
 * \brief Verifica se a fila está cheia. 
 * 
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include<iostream>
 * #include "filavet.hpp"
 * 
 * using namespace std;
 *
 * int main() {
 *     FilaVet *f = criar_fila();
 *     if (!estah_cheia(f)) {
 *         cout << "Deu certo!" << endl;
 *     }
 *     liberar_fila(f);
 *     return EXIT_SUCCESS;
 * }  
 * \endcode
 * 
 * Saída esperada: 
 * \code {.unparsed}
 *     Deu certo!
 * \endcode 
 * 
 * \pre O ponteiro \p *f deve ser diferente de \p NULL.
 * 
 * \param *f representa um ponteiro para a fila cuja situação será consultada.
 * 
 * \return \p true, se a fila estiver cheia e \p false, caso contrário.
 * 
 * \warning O programa será abortado, caso o ponteiro \p *f seja igual a \p NULL.
*/
bool estah_cheia(FilaVet* f);

/** 
 * \brief Insere um novo elemento no final da fila.  
 *
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include<iostream>
 * #include "filavet.hpp"
 * 
 * using namespace std;
 *
 * int main() {
 *     FilaVet *f = criar_fila();
 *     inserir(f, 2);
 *     if (!estah_vazia(f)) {
 *         cout << "Deu certo!" << endl;
 *     }
 *     liberar_fila(f);
 *     return EXIT_SUCCESS;
 * }  
 * \endcode
 * 
 * Saída esperada: 
 * \code {.unparsed}
 * 		Deu certo!
 * \endcode
 * 
 * \pre O ponteiro \p *f deve ser diferente de \p NULL.
 * \pre A fila não deve estar cheia.
 *  
 * \param *f representa um ponteiro para a fila onde o elemento será inserido.
 * \param item representa o item a ser inserido na fila.
 * 
 * \return void
 * 
 * \warning O programa será abortado, caso o ponteiro \p *f seja igual a \p NULL, ou
 * 			caso a fila esteja cheia.
 */
void inserir(FilaVet* f, int item);

/** 
 * \brief Remove e retorna o elemento do início da fila. 
 * 
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include<iostream>
 * #include "filavet.hpp"
 * 
 * using namespace std;
 *
 * int main() {
 *     FilaVet *f = criar_fila();
 *     inserir(f, 1);
 *     inserir(f, 2);
 *     inserir(f, 3);
 *     while (!estah_vazia(f)) {
 *         cout << remover(f) << endl;
 *     }
 *     liberar_fila(f);
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
 * \pre O ponteiro \p *f deve ser diferente de \p NULL.
 * \pre A fila não deve estar vazia.
 * 
 * \param *f representa um ponteiro para a fila de onde o elemento será removido.
 * 
 * \return O elemento removido do início da fila.
 * 
 * \warning O programa será abortado, caso o ponteiro \p *f seja igual a \p NULL, ou
 * 			caso a fila esteja vazia.
 */
int remover(FilaVet* f);

/** 
 * \brief Apenas retorna o elemento do início da fila. 
 * 
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include<iostream>
 * #include "filavet.hpp"
 * 
 * using namespace std;
 *
 * int main() {
 *     FilaVet *f = criar_fila();
 *     inserir(f, 1);
 *     inserir(f, 2);
 *     inserir(f, 3);
 *     while (!estah_vazia(f)) {
 *         cout << obter_inicio(f) << endl;
 *         remover(f);
 *     }
 *     liberar_fila(f);
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
 * \pre O ponteiro \p *f deve ser diferente de \p NULL.
 * \pre A fila não deve estar vazia.
 
 * \param *f representa um ponteiro para a fila de onde o elemento será obtido.
 * 
 * \return O elemento do início da fila.
 *
 * \warning O programa será abortado, caso o ponteiro \p *f seja igual a \p NULL.
 */
int obter_inicio(FilaVet* f);

#endif
