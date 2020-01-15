/**
* @file list.h
* @author Jhonattan Carlos Barbosa Cabral
* @author Daniel Marx Pinto Carvalho
* @date 06 Junho 2017
* @brief Arquivo contendo os métodos da classe MyBidirectionalIterator e
*        as declarações dos métodos da classe list.
*/


/* Includes. */
#include <iostream>  //<! cout, endl
#include <iterator>  //<! bidirectional_iterator_tag
#include <cassert>   //<! assert()
#include <algorithm> //<! copy
#include <cstddef>   //<! std::ptrdiff_t

#ifndef _LIST_H_
#define _LIST_H_

namespace ls 
{
template <typename T>
    class list;
template <typename T>
    class MyBidirectionalIterator
    {

    //<! Alias.
    public:
        using self_type = MyBidirectionalIterator;  
        using value_type = T;
        using pointer = T *;
        using reference = T &;
        using difference_type = std::ptrdiff_t;
        using iterator_category = std::bidirectional_iterator_tag; 

    //<! Membros privados.
    private:
        T * m_ptr; 

    public:

        /**
        * @brief Construtor padrão do Interador.
        */
        MyBidirectionalIterator( T * ptr_ = nullptr )
            : m_ptr ( ptr_ )
        { /* empty */ }

        //<! Métodos especiais.
        ~MyBidirectionalIterator() = default;
        MyBidirectionalIterator( const self_type & ) = default;
        self_type & operator=( const self_type & ) = default;


        /**
        * @brief Retorna a informação contido no nó apontado pelo iterador.
        * @return Retorna informação do nó.
        */
        typename T::value_type & operator*()
        {
            assert( m_ptr != nullptr );
            return m_ptr->data;
        }

        /**
        * @brief Aponta para o nó seguinte.
        * @return Retorna novo nó apontada.
        */
        self_type operator++()
        {
            m_ptr = m_ptr->next;
            return *this;
        }


        /**
        * @brief Aponta para o nó seguinte e retorna o nó antigo.
        * @return Retorna o nó antigo.
        */
        self_type operator++(int)
        {
            self_type temp = *this;
            m_ptr = m_ptr->next;
            return temp;
        }


        /**
        * @brief Aponta para o nó anterior.
        * @return Retorna o novo nó.
        */
        self_type operator--()
        {
            m_ptr = m_ptr->prev;
            return *this;
        }


        /**
        * @brief Aponta para o nó anterior e retorna o nó que estava sendo apontado antes.
        * @return Retorna o nó antigo.
        */
        self_type operator--(int)
        {
            self_type temp = *this;
            m_ptr = m_ptr->prev;
            return temp;
        }


        /**
        * @brief Compara se um nó é igual ao outro.
        * @return Retorna true caso os nós sejam iguais, retorna false caso contrário.
        */        
        bool operator==( const self_type & rhs_ ) const
        {
            return m_ptr == rhs_.m_ptr;
        }


        /**
        * @brief Compara se um nó não é igual ao outro.
        * @return Retorna true caso os nós sejam diferentes, retorna false caso contrário.
        */ 
        bool operator!=( const self_type & rhs_ ) const
        {
            return m_ptr != rhs_.m_ptr;
        }


        /**
        * @brief Faz com que eu tenha acesso diretamente ao nó.
        * @return Retorna um dos campos do nó.
        */        
        pointer operator->( void ) const
        {
            assert( m_ptr );
            return m_ptr;
        }

    
        /**
        * @brief Função friend para que a classe iterator possa compartilhar seus métodos
        *        privados com a classe list.
        */
        friend class list< typename T::value_type>;
};

    template < typename T > 
    	class list
    	{
        	struct node_t
        	{
        		//<! Alias
        		typedef T value_type;

            	value_type data; // Tipo de informação armazenada no container  
            	node_t * next;
            	node_t * prev;
            
            	//<! T() Construtor padrão desse dado.
            	node_t ( const T & d_ = T(), node_t * n_ = nullptr, node_t * p_ = nullptr )
                	: data ( d_ )
                	, next ( n_ )
                	, prev ( p_ )
            	{ /*empty*/ }
        	};


        	public:
            	using iterator = MyBidirectionalIterator<node_t>;
            	using const_iterator = MyBidirectionalIterator<const node_t>;

        	//<! Membros privados.
        	private:
            	size_t m_len;
            	node_t * m_head;
            	node_t * m_tail;
            
        	public:

//1 - ESPECIAL MEMBERS -----------------------------------------------

            /**
            * @brief Construtor.
            */
        	list();

            /**
            * @brief Construtor cópia.
            * @param clone_ outra lista para ser copiada.
            */
        	list( const list & clone_ );

            /**
            * @brief Destrutor.
            */
        	~list();


//2 - ITERATORS ------------------------------------------------------
            /**
            * @brief Verifica qual o iterador que aponta para o primeiro nó da lista.
            * @return Retorna um interador apontando para o primeiro nó da lista.
            */
        	iterator begin() const;


            /**
            * @brief Verifica qual o iterador constante que aponta para o primeiro nó da lista.
            * @return Retorna um interador constante apontando para o primeiro nó da lista.
            */            
        	const_iterator cbegin() const;


            /**
            * @brief Verifica qual o iterador que aponta para o final da lista.
            * @return Retorna um interador apontando para o final da lista.
            */
        	iterator end() const;


            /**
            * @brief Verifica qual o iterador constante que aponta para o final da lista.
            * @return Retorna um interador constante apontando para o final da lista.
            */
        	const_iterator cend() const;

//3 - CAPACITY -------------------------------------------------------
            /**
            * @brief Verifica o tamanho da lista.
            * @return Retorna o tamanho da lista
            */
        	size_t size( void ) const;
        

            /**
            * @brief Verifica se a lista esta vazia.
            * @return Retorna true caso a lista esteja vazia, retorna false caso contrário.
            */        
        	size_t empty( void ) const;

//4 - MODIFIERS --------------------------------------------------------
            /**
            * @brief Método para ajudar a debugar, imprime toda a lista.
            */ 
        	void print( );
            

            /**
            * @brief Esvazia a lista.
            */
        	void clear();


            /**
            * @brief Adiciona um elemento no começo da lista.
            * @param value_ Elemento que será adicionado.
            */
        	bool push_front( const T & value_ );


            /**
            * @brief Adiciona um elemento no final da lista.
            * @param value_ Elemento que será adicionado.
            */
        	bool push_back(const T & value_ );


            /**
            * @brief Remove o primeiro elemento da lista.
            */
        	bool pop_front();


            /**
            * @brief Remove o ultimo elemento da lista.
            */
        	bool pop_back();


            /**
            * @brief Substitui todos os valores da lista por um outro único valor.
            * @param value_ Valor que substituirá todos os outros.
            */
        	void assign (const T & value_);
        

            /**
            * @brief Substitui os elementos da lista por alguns elementos inicializados.
            * @param list Lista de elementos que substituirão os elementos da lista atual.
            */
        	void assign_list(std::initializer_list<T> list);
        

            /**
            * @brief Substitui os elementos da lista pelos elementos de um determinado range de outra lista.
            * @param first inicio do range.
            * @param last fim do range.
            */
        	template<typename Inputltr>
        	void assign_range(Inputltr first, Inputltr last);


            /**
            * @brief Adiciona um elemento em uma determinada posição da lista.
            * @param pos Interador para posição onde será inserido novo elemento.
            * @param value Valor a ser inserido.
            */
        	iterator insert( iterator it_, const T & value_ );


            /**
            * @brief Insere um range de elemento em uma determinada posição..
            * @param pos Interador para posição onde começará a inserção de novos elementos.
            * @param fist inicio do range.
            * @param last fim do range.
            */
	    	template <class Inputltr>
        	iterator insert_range(iterator it, Inputltr first, Inputltr last);
        

            /**
            * @brief Insere uma lista de elementos em uma determinada posição.
            * @param pos Interador para posição onde começará a inserção de novos elementos.
            * @param list Lista inicializada de elementos que serão inseridos.
            */
        	iterator insert_list(iterator it, std::initializer_list<T>list);


            /**
            * @brief Remove um elemento da lista.
            * @param pos Interador para posição do elemento que será removido.
            */
		    iterator erase( iterator it_ );


            /**
            * @brief Remove um faixa de elementos da lista.
            * @param first Interador para posição do primeiro elemento que será removido.
            * @param last Interador para posição do último elemento que será removido.
            */
        	iterator erase_range( iterator first, iterator last );


            /**
            * @brief Busca um determinado elemento na lista. 
            * @param value Elemento buscado.
            * @return retorno Iterador para a posição do elemento buscado na lista.
            */
        	const_iterator find(const T & value) const;
	
//5 - ELEMENT ACESS	-------------------------------------------------------
            /**
            * @brief Retorna a referência para o primeiro nó da lista.
            * @return Referencia para o primeiro nó da lista.
            */
        	const T & front( void ) const;


            /**
            * @brief Retorna a referência para o ultimo nó da lista.
            * @return Referencia para o ultimo nó da lista.
            */
        	const T & back( void ) const;

//6 - OPERATORS	-----------------------------------------------------------
            /**
            * @brief Verifica se duas listas são iguais.
            * @param other Lista de comparação.
            * @return True caso as duas listas sejam iguais e False caso contrários.
            */
        	bool operator==(const ls::list<T> & other) const;        	


            /**
            * @brief Verifica se duas listas são diferentes.
            * @param other Lista de comparação.
            * @return True caso as duas listas sejam diferentes e False caso contrários.
            */
        	bool operator!=(const list<T> & other) const;

        };
}

#include "list.inl"
#endif