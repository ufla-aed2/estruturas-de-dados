/**
 * \file filadvet.hpp
 * \author Prof. Paulo Afonso (pauloa.junior@dcc.ufla.br)
 * \date Outubro, 2016
 * \brief Interface do TAD FilaDVet
 * 
 * Disponibiliza as funções necessárias para manipulação da estrutura de dados Fila Dupla.
 */
 
#ifndef FILADVET_HPP
#define FILADVET_HPP

/**
 * \def TAM_MAX 
 * \brief Define a quantidade máxima de elementos suportada pela fila.
 * \hideinitializer
 */
#define TAM_MAX 100 

/** 
 * \struct FilaDVet
 * \brief Declaração opaca da estrutura de uma fila.
 * 
 * Isso significa que os detalhes de implementação desta estrutura estão escondidos do usuário do TAD. 
 * A definição da estrutura FilaDVet encontra-se no arquivo \file filadvet.cpp.
 */
struct FilaDVet;

/** 
 * \brief Cria dinamicamente uma fila vazia e retorna o endereço onde ela se encontra alocada.
 * 
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include "filadvet.hpp"

 * int main() {
 *     FilaDVet *f = criar_fila_d();
 *     return EXIT_SUCCESS;
 * }  
 * \endcode
 * 
 * \return O endereço de memória da fila alocada dinamicamente.
 */
FilaDVet* criar_fila_d();

/** 
 * \brief Libera o espaço de memória anteriormente reservado para a fila.
 *  
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include "filadvet.hpp"
 * 
 * int main() {
 *     FilaDVet *f = criar_fila_d();
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
void liberar_fila(FilaDVet* f);

/** 
 * \brief Verifica se a fila está vazia. 
 * 
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include<iostream>
 * #include "filadvet.hpp"
 * 
 * using namespace std;
 *
 * int main() {
 *     FilaDVet *f = criar_fila_d();
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
bool estah_vazia(FilaDVet* f);

/** 
 * \brief Verifica se a fila está cheia. 
 * 
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include<iostream>
 * #include "filadvet.hpp"
 * 
 * using namespace std;
 *
 * int main() {
 *     FilaDVet *f = criar_fila_d();
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
bool estah_cheia(FilaDVet* f);

/** 
 * \brief Insere um novo elemento no final da fila.  
 *
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include<iostream>
 * #include "filadvet.hpp"
 * 
 * using namespace std;
 *
 * int main() {
 *     FilaDVet *f = criar_fila_d();
 *     inserir_no_fim(f, 2);
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
void inserir_no_fim(FilaDVet* f, int item);

/** 
 * \brief Remove e retorna o elemento do início da fila. 
 * 
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include<iostream>
 * #include "filadvet.hpp"
 * 
 * using namespace std;
 *
 * int main() {
 *     FilaDVet *f = criar_fila_d();
 *     inserir_no_fim(f, 1);
 *     inserir_no_fim(f, 2);
 *     inserir_no_fim(f, 3);
 *     while (!estah_vazia(f)) {
 *         cout << remover_do_inicio(f) << endl;
 *     }
 *     liberar_fila(f);
 *     return EXIT_SUCCESS;
 * }  
 * \endcode
 * 
 * Saída esperada: 
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
int remover_do_inicio(FilaDVet* f);

/** 
 * \brief Apenas retorna o elemento do início da fila. 
 * 
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include<iostream>
 * #include "filadvet.hpp"
 * 
 * using namespace std;
 *
 * int main() {
 *     FilaDVet *f = criar_fila_d();
 *     inserir_no_fim(f, 1);
 *     inserir_no_fim(f, 2);
 *     inserir_no_fim(f, 3);
 *     while (!estah_vazia(f)) {
 *         cout << obter_inicio(f) << endl;
 *         remover_do_inicio(f);
 *     }
 *     liberar_fila(f);
 *     return EXIT_SUCCESS;
 * }  
 * \endcode
 * 
 * Saída esperada:  
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
int obter_inicio(FilaDVet* f);

/** 
 * \brief Insere um novo elemento no início da fila. Como se trata de uma fila dupla, essa operação é permitida.  
 *
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include<iostream>
 * #include "filadvet.hpp"
 * 
 * using namespace std;
 *
 * int main() {
 *     FilaDVet *f = criar_fila_d();
 *     inserir_no_inicio(f, 2);
 *     inserir_no_inicio(f, 3);
 *     if (!estah_vazia(f)) {
 *         cout << remover_do_inicio(f) << endl;
 *     }
 *     liberar_fila(f);
 *     return EXIT_SUCCESS;
 * }  
 * \endcode
 * 
 * Saída esperada: 
 * \code {.unparsed}
 * 		3
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
void inserir_no_inicio(FilaDVet* f, int item);

/** 
 * \brief Remove e retorna o elemento do fim da fila. Como se trata de uma fila dupla, essa operação é permitida.  
 * 
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include<iostream>
 * #include "filadvet.hpp"
 * 
 * using namespace std;
 *
 * int main() {
 *     FilaDVet *f = criar_fila_d();
 *     inserir_no_fim(f, 1);
 *     inserir_no_fim(f, 2);
 *     inserir_no_fim(f, 3);
 *     while (!estah_vazia(f)) {
 *         cout << remover_do_fim(f) << endl;
 *     }
 *     liberar_fila(f);
 *     return EXIT_SUCCESS;
 * }  
 * \endcode
 * 
 * Saída esperada: 
 * \code {.unparsed}
 *     3
 *     2
 *     1
 * \endcode
 * 
 * \pre O ponteiro \p *f deve ser diferente de \p NULL.
 * \pre A fila não deve estar vazia.
 * 
 * \param *f representa um ponteiro para a fila de onde o elemento será removido.
 * 
 * \return O elemento removido do fim da fila.
 * 
 * \warning O programa será abortado, caso o ponteiro \p *f seja igual a \p NULL, ou
 * 			caso a fila esteja vazia.
 */
int remover_do_fim(FilaDVet* f);

/** 
 * \brief Apenas retorna o elemento do fim da fila. Como se trata de uma fila dupla, essa operação é permitida.  
 * 
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include<iostream>
 * #include "filadvet.hpp"
 * 
 * using namespace std;
 *
 * int main() {
 *     FilaDVet *f = criar_fila_d();
 *     inserir_no_fim(f, 1);
 *     inserir_no_fim(f, 2);
 *     inserir_no_fim(f, 3);
 *     while (!estah_vazia(f)) {
 *         cout << obter_fim(f) << endl;
 *         remover_do_fim(f);
 *     }
 *     liberar_fila(f);
 *     return EXIT_SUCCESS;
 * }  
 * \endcode
 * 
 * Saída esperada: 
 * \code {.unparsed}
 *     3
 *     2
 *     1
 * \endcode
 * 
 * \pre O ponteiro \p *f deve ser diferente de \p NULL.
 * \pre A fila não deve estar vazia.
 
 * \param *f representa um ponteiro para a fila de onde o elemento será obtido.
 * 
 * \return O elemento do fim da fila.
 *
 * \warning O programa será abortado, caso o ponteiro \p *f seja igual a \p NULL.
 */
int obter_fim(FilaDVet* f);

#endif
