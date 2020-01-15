/**
* @file iterator.h
* @author Jhonattan Carlos Barbosa Cabral
* @author Daniel Marx Pinto Carvalho
* @date 12 Maio 2017
* @brief Arquivo contendo as declarações da classe MyBidirectionalIterator.
*/

#ifndef _ITERATOR_H_
#define _ITERATOR_H_

/*! Includes */
#include <cstdlib> // size_t
#include <stdexcept> // out_of_range
#include <iostream> // cout, endl
#include <cassert>  // assert
#include <algorithm> // copy
#include <iterator>  // ostream_iterator

//<! Membros
template <typename T>
class MyBidirectionalIterator
{

    public:
        using self_type = MyBidirectionalIterator;  
        using value_type = T;
        using pointer = T *;
        using reference = T &;

        using difference_type = std::ptrdiff_t;
        using iterator_category = std::bidirectional_iterator_tag;

    private:
        T * m_ptr;

    //<! Métodos públicos
    public:

        /**
	    * @brief Construtor padrão do Interador
	    * @param ptr Pointeiro do interador
	    */
        MyBidirectionalIterator( T * ptr_ = nullptr )
            : m_ptr ( ptr_ )
        { /*empty */}

        //<! Special methods. Default versions.
        ~MyBidirectionalIterator() = default;
        MyBidirectionalIterator( const self_type & ) = default;
        self_type & operator=( const self_type & ) = default;

        /**
	    * @brief Retorna valor ao qual o interador está apontando
	    * @return Valor da posição apontada
	    */
        reference operator*()
        {
            assert( m_ptr != nullptr );
            return *m_ptr;
        }

        /**
	    * @brief Aponta para a posição seguinte da memória
	    * @return Nova posição apontada
	    */
        self_type operator++()
        {
            m_ptr++;
            return *this;
        }

        /**
	    * @brief Aponta para a posição seguinte da memória
	    * @return Antiga posição apontada
	    */
        self_type operator++(int)
        {
            self_type temp = *this;
            m_ptr++;
            return temp;
        }

        /**
	    * @brief Aponta para a posição anterior da memória
	    * @return Nova posição apontada
	    */
        self_type operator--()
        {
            m_ptr--;
            return *this;
        }

        /**
	    * @brief Aponta para a posição anterior da memória
	    * @return Antiga posição apontada
	    */
        self_type operator--(int)
        {
            self_type temp = *this;
            m_ptr--;
            return temp;
        }

        /**
	    * @brief Compara dois interadores
        * @param rhs Interador de comparação
	    * @return Vedadeiro (True) caso seja iguais e Falso (False), caso contrário
	    */
        bool operator==( const self_type & rhs_ ) const
        {
            return m_ptr == rhs_.m_ptr;
        }

        /**
	    * @brief Compara dois interadores
        * @param rhs Interador de comparação
	    * @return Vedadeiro (True) caso seja diferentes e Falso (False), caso contrário
	    */
        bool operator!=( const self_type & rhs_ ) const
        {
            return m_ptr != rhs_.m_ptr;
        }

        /**
	    * @brief Aponta para uma nova posição seguinte na memória
        * @param step Número de posições para avançar na memória
	    * @return Nova posição da memória sendo apontada
	    */
        self_type operator+=( difference_type step_ )
        {
             m_ptr += step_;
             return *this;
        } 

        /**
	    * @brief Aponta para uma nova posição anterior na memória
        * @param step Número de posições para retornar na memória
	    * @return Nova posição da memória sendo apontada
	    */
        self_type operator-=(  difference_type step_ )
        {
             m_ptr -= step_;
             return *this;
        }

        /**
	    * @brief Retorna distância entre dois interadores
        * @param rhs Interador de comparação
	    * @return Número de posições que um difere do outro
	    */
        difference_type operator-( const self_type & rhs_ ) const 
        {
            return m_ptr - rhs_.m_ptr;
        }


        /// it->method()
        pointer operator->( void ) const ;
};

#endif
