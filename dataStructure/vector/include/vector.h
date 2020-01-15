/**
* @file vector.h
* @author Jhonattan Carlos Barbosa Cabral
* @author Daniel Marx Pinto Carvalho
* @date 12 Maio 2017
* @brief Arquivo contendo as declarações da classe Vector.
*/	

#ifndef _VECTOR_H_
#define _VECTOR_H_

/*! Includes */
#include "iterator.h"

namespace ls {
    
    //<! Membros
    template <typename T>
    class vector
    {
        public:

        using iterator = MyBidirectionalIterator<T>;
        using const_iterator = MyBidirectionalIterator<const T>;

        private:
            //<! Defatul size for the vector.
            static constexpr size_t DEFAULT_SIZE{ 100 };

            size_t m_len;  //!< Logical length.
            size_t m_size; //!< Actual size of the array.
            T *m_data;   //!< Dynamic storage area.
        
        //<! Métodos públicos
        public:

//1 - ESPECIAL MEMBERS -----------------------------------------------

    /**
	 * @brief Construtor padrão do Vector
	 * @param sz_ Tamanho físico do vector
	 */
        explicit vector( size_t sz_= DEFAULT_SIZE );

    /**
	 * @brief Construtor cópia do Vector
	 * @param &other O outro vector para ser copiado
	 */
        vector( const vector &other ); 

    /**
	 * @brief Construtor 'para mover' do vector
	 * @param &other O outro vector para ser movido
	 */
        vector( vector &&other ); 

    /**
	 * @brief Destrutor do vector
	 */
        ~vector( );

//2 - ITERATORS ------------------------------------------------------

    /**
	* @brief Retorna um interador para o primeiro elemento do vector
	* @return Um interador apontando para o primeiro elemento do vector
	*/
        iterator begin( void ) const;

    /**
	* @brief Retorna um interador para o último elemento do vector
	* @return Um interador apontando para o último elemento do vector
	*/
        iterator end( void ) const;

    /**
	* @brief Retorna um interador constante para o primeiro elemento do vector
	* @return Um interador constante apontando para o primeiro elemento do vector
	*/
        const_iterator cbegin( void ) const;

    /**
	* @brief Retorna um interador constante para o último elemento do vector
	* @return Um interador constante apontando para o último elemento do vector
	*/
        const_iterator cend( void ) const;

//3 - CAPACITY -------------------------------------------------------

    /**
	* @brief Retorna o tamanho físico do vector
	* @return Tamanho físico do vector
	*/
        size_t capacity( void ) const;

    /**
	* @brief Retorna o tamanho lógico do vector
	* @return Tamanho lógico do vector
	*/
        size_t size( void ) const;

    /**
	* @brief Indica se o vector está vazio
	* @return Verdadeiro (True) caso tamanho lógico do vector for 0, e Falso (False) caso contrário
	*/
        bool empty( void ) const;

    /**
	* @brief Indica se o vector está cheio
	* @return Verdadeiro (True), tamanho lógico do vector for igual ao físico e Falso (False) caso contrário
	*/
        bool full( void ) const;

//4 - MODIFIERS --------------------------------------------------------

    /**
	* @brief Imprime conteúdo do vector 
	*/
        void print( void ) const;

    /**
	* @brief Esvazia o vector
	*/
        void clear( void );

    /**
	* @brief Adiciona elemento ao final do vector
	* @param value_ Valor do elemento a ser adicionado
	*/
        void push_back( const T & value_);

    /**
	* @brief Remove o último elemento do vector
	*/
        T pop_back( void );
        
    /**
	* @brief Adiciona elemento ao começo do vector
	* @param value_ Valor do elemento a ser adicionado
	*/
        void push_front(const T & value_);

    /**
	* @brief Remove o primeiro elemento do vector
	*/
        T pop_front( void );

    /**
	* @brief Iguala tamanho físico do vector ao se tamanho lógico
	*/
        void shrink_to_fit( void );

    /**
	* @brief Substitui todos os valores do vector por um outro único valor
	* @param value_ Valor que substituirá todos os outros
	*/
        void assign (const T & value_);

    /**
	* @brief Modifica capacidade de armazenamento do vector
	* @param new_cap Nova capacidade do vector
	*/
        void reserve (size_t new_cap);

    /**
	* @brief Substitui valores do vector outros de uma lista
	* @param list Lista de elementos que substituirão os atuais do vector
	*/
        void assign_list(std::initializer_list<T> list);

    /**
	* @brief Substitui valores do vector outros de um vector
	* @param first Interador apontando para o início do vector contendo os elementos substitutos
    * @param last Interador apontando para o fim do vector contendo os elementos substitutos
	*/
        template<typename Inputltr>
        void assign_range(Inputltr first, Inputltr last);

    /**
	* @brief Adiciona elemento a uma posição do vector, sem perca de valores atuais do vector.
	* @param pos Interador para posição onde será inserido novo elemento
    * @param value Valor a ser inserido
	*/
        iterator insert(iterator pos, const T &value);

    /**
	* @brief Insere uma lista de elementos a uma faixa de valores do vector, sem perca de valores atuais do vector.
	* @param pos Interador para posição onde começará a inserção de novos elementos.
    * @param fist Interador para a primeiro elemento da lista a ser inserido
    * @param last Interador para a último elemento da lista a ser inserido
	*/
        template <typename Inputltr>
        iterator insert_range(iterator pos, Inputltr first, Inputltr last);

    /**
	* @brief Insere uma lista de elementos a uma faixa de valores do vector, sem perca de valores atuais do vector.
	* @param pos Interador para posição onde começará a inserção de novos elementos.
    * @param list Lista a ser inserido
	*/
        iterator insert_list(const_iterator pos, std::initializer_list<T>list);

    /**
	* @brief Remove um elemento do vector
	* @param pos Interador para posição do elemento que será removido
    */
        iterator erase( iterator pos );

    /**
	* @brief Remove um faixa de valores do vector
	* @param first Interador para posição do primeiro elemento que será removido
    * @param last Interador para posição do último elemento que será removido
    */
        iterator erase( iterator first, iterator last );


//5 - ELEMENT ACESS -------------------------------------------------------
        
    /**
	* @brief Retorna a referência para o primeiro elemento do vector
	* @return Primeiro elemento do vector
    */
        const T & front( void ) const;

    /**
	* @brief Retorna a referência para o último elemento do vector
	* @return Último elemento do vector
    */
        const T & back( void ) const;
        
    /**
	* @brief Retorna a referência da posição do vector especificada entre colchetes 
    * @param pos Número da posição a ser removida
	* @return Valor da posição especificada
    */
        T & operator[]( size_t pos) const;

    /**
	* @brief Retorna a referência da posição do vector especificada, checando se a posição requerida é válida
    * @param pos Número da posição a ser removida
	* @return Valor da posição especificada ou exeção caso posição não seja válida
    */
        T & at ( size_t pos ) const;

//6 - OPERATORS	-----------------------------------------------------------

    /**
	* @brief Compara dois vectors
    * @param other Vector de comparação
	* @return Verdadeiro (True) caso os dois vectores sejam iguais e Falso(False) caso contrários
    */
        bool operator==(const ls::vector<T> & other) const;

    /**
	* @brief Compara dois vectors
    * @param other Vector de comparação
	* @return Verdadeiro (True) caso os dois vectores sejam diferentes e Falso(False) caso contrários
    */
        bool operator!=(const ls::vector<T> & other) const;
	
    };
}

/*! Includes */
#include "vector.inl"
#endif
