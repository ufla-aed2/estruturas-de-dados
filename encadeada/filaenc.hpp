/**
 * \file filaenc.hpp
 * \author Prof. Paulo Afonso (pauloa.junior@dcc.ufla.br)
 * \date Janeiro, 2017
 * \brief Interface do TAD FilaEnc
 * 
 * Disponibiliza as funções necessárias para manipulação da estrutura de dados Fila.
 */
 
#ifndef FILAENC_HPP
#define FILAENC_HPP

/** 
 * \struct FilaEnc
 * \brief Declaração opaca da estrutura de uma fila.
 * 
 * Isso significa que os detalhes de implementação desta estrutura estão escondidos do usuário do TAD. 
 * A definição da estrutura FilaEnc encontra-se no arquivo \file FilaEnc.cpp.
 */
struct FilaEnc;

/** 
 * \struct Noh
 * \brief Declaração opaca da estrutura de um nó da fila.
 * 
 * Isso significa que os detalhes de implementação desta estrutura estão escondidos do usuário do TAD. 
 * A definição da estrutura Noh encontra-se no arquivo \file filaenc.cpp.
 */
struct Noh;

/** 
 * \brief Cria dinamicamente uma fila vazia e retorna o endereço onde ela se encontra alocada.
 * 
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include "filaenc.hpp"

 * int main() {
 *     FilaEnc *f = criar_fila();
 *     return EXIT_SUCCESS;
 * }  
 * \endcode
 * 
 * \return O endereço de memória da fila alocada dinamicamente.
 */
FilaEnc* criar_fila();

/** 
 * \brief Libera o espaço de memória anteriormente reservado para a fila.
 *  
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include "filaenc.hpp"
 * 
 * int main() {
 *     FilaEnc *f = criar_fila();
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
void liberar_fila(FilaEnc* f);

/** 
 * \brief Verifica se a fila está vazia. 
 * 
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include<iostream>
 * #include "filaenc.hpp"
 * 
 * using namespace std;
 *
 * int main() {
 *     FilaEnc *f = criar_fila();
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
bool estah_vazia(FilaEnc* f);

/** 
 * \brief Insere um novo elemento no final da fila.  
 *
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include<iostream>
 * #include "filaenc.hpp"
 * 
 * using namespace std;
 *
 * int main() {
 *     FilaEnc *f = criar_fila();
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
 * \warning O programa será abortado, caso o ponteiro \p *f seja igual a \p NULL.
 */
void inserir(FilaEnc* f, int item);

/** 
 * \brief Remove e retorna o elemento do início da fila. 
 * 
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include<iostream>
 * #include "filaenc.hpp"
 * 
 * using namespace std;
 *
 * int main() {
 *     FilaEnc *f = criar_fila();
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
 * \warning O programa será abortado, caso o ponteiro \p *f seja igual a \p NULL ou
 * 			caso a fila esteja vazia.
 */
int remover(FilaEnc* f);

/** 
 * \brief Apenas retorna o elemento do início da fila. 
 * 
 * Exemplo de uso:
 * \code {.cpp}
 * #include<cstdlib>
 * #include<iostream>
 * #include "filaenc.hpp"
 * 
 * using namespace std;
 *
 * int main() {
 *     FilaEnc *f = criar_fila();
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
 * \warning O programa será abortado, caso o ponteiro \p *f seja igual a \p NULL ou
 * 			caso a fila esteja vazia.
 */
int obter_inicio(FilaEnc* f);

#endif
