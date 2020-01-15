/**
 * @file vector.inl
 * @author Jhonattan Carlos Barbosa Cabral.
 * @author Daniel Marx Pinto Carvalho
 * @date 12 Maio 2017
 * @brief Arquivo com as implementações dos métodos da classe Vector
 */

/*! Includes */
#include "vector.h"

//1 - ESPECIAL MEMBERS -----------------------------------------------

/*! Construtor*/
template <typename T>
ls::vector<T>::vector( size_t sz_)
: m_len(0)
, m_size( sz_ )
, m_data(new T[sz_+1])
{/*empty*/}

/*! Copy Construtor*/
template <typename T>
ls::vector<T>::vector( const vector &other ) 
    : m_size(other.m_size)
    , m_len(other.m_len)
    , m_data(new T[other.m_size])
{
    for (auto i(0u); i < other.m_len; i++){
        push_back(other[i]);
    }
}

/*! Move Construtor*/
template <typename T>
ls::vector<T>::vector( vector&& other ) 
    : m_size(other.m_size)
    , m_len(other.m_len)
    , m_data(std::move(other.m_data))
{
    other.size = 0;
    other.len = 0;
}

/*! Destrutor */
template <typename T>
ls::vector<T>::~vector( )
{
    delete [] m_data;
}

//2 - ITERATORS ------------------------------------------------------

/*! Retorna referência para primeira posição do vector*/
template <typename T>
MyBidirectionalIterator<T> ls::vector<T>::begin( void ) const
{ 
	return iterator( &m_data[0] ) ; 
}

/*! Retorna referência para última posição do vector*/
template<typename T>
MyBidirectionalIterator<T>  ls::vector<T>::end( void ) const
{ 
	return iterator( &m_data[m_len] ) ; 
}

/*! Retorna referência constante para primeira posição do vector*/
template<typename T>
MyBidirectionalIterator<const T> ls::vector<T>::cbegin( void ) const
{ 
	return MyBidirectionalIterator<const T>( &m_data[0] ) ; 
}

/*! Retorna referência constante para última posição do vector*/
template<typename T>
MyBidirectionalIterator<const T> ls::vector<T>::cend( void ) const
{ 
	return MyBidirectionalIterator<const T>( &m_data[m_len] ) ; 
}

//3 - CAPACITY -------------------------------------------------------

/*! Retorna tamanho físico do vector*/
template<typename T>
size_t ls::vector<T>::capacity( void ) const
{
    return m_size;
}

/*! Retorna tamanho lógico do vector*/
template<typename T>
size_t ls::vector<T>::size( void ) const
{
    return m_len;
}

/*! Diz se o vector está vazio ou não*/
template<typename T>
bool ls::vector<T>::empty( void ) const
{
    return m_len == 0;
}

/*! Diz se o vector está cheio ou não*/
template<typename T>
bool ls::vector<T>::full( void ) const
{
    return m_len == m_size;
}

//4 - MODIFIERS --------------------------------------------------------

/*! Imprime valores do vector */
template<typename T>
void ls::vector<T>::print( void ) const
{
    std::cout << ">>> [ ";
    std::copy( &m_data[0], &m_data[m_len],
                std::ostream_iterator< T >(std::cout, " ") );
    std::cout << "], len: " << m_len << ", capacity: " << m_size << ".\n";
}

/*! Limpa valores do vector */
template<typename T>
void ls::vector<T>::clear( void )
{
    m_len = 0;
}

/*! Adiciona um elemento ao final do vector */
template<typename T>
void ls::vector<T>::push_back( const T & value_ )
{
    if ( full() )
        reserve (2 * m_size);

    m_data[m_len++] = value_;
}

/*! Remove o último elemento do vector */
template<typename T>
T ls::vector<T>::pop_back( void )
{
    if ( empty() )
        throw std::out_of_range("[pop_back()]: Cannot recover an element from an empty vector!");

    return m_data[--m_len];
}

/*! Adiciona um elemento ao começo do vector */
template<typename T>
void ls::vector<T>::push_front(const T & value_)
{ 	
    if ( full() )
        reserve (2 * m_size);

    std::copy(m_data, m_data+m_len, m_data+1);
    *m_data = value_;
    m_len++;
}

/*! Remove o primeiro elemento do vector */
template<typename T>
T ls::vector<T>::pop_front( void )
{

    auto aux = *m_data;

    std::copy(m_data, m_data+m_len, m_data-1);
    m_len --;

    return aux;
}

/*! Iguala tamanho físico ao tamanho lógico */
template<typename T>
void ls::vector<T>::shrink_to_fit( void )
{
    m_size = m_len;
}

/*! Preenche vector com um único valor */
template<typename T>
void ls::vector<T>::assign (const T & value_)
{
    for(auto i = 0u; i != m_len; ++i)
        *(m_data+i) = value_;
}

/*! Aumenta capacidade do vector */
template<typename T>
void ls::vector<T>::reserve (size_t new_cap)
{
    T *  temp = new T[new_cap];

    for( auto i = 0u ; i < m_size ; ++i)
    {
        temp[i] = m_data[i];
    }

    delete [] m_data;
    m_data = temp;
    m_size = new_cap;
}

/*! Substitui valores do vector por uma lista de valores */
template<typename T>
void ls::vector<T>::assign_list(std::initializer_list<T> list)
{
	this->clear();
    m_len =list.size();
    std::copy(list.begin(), list.end(), m_data);		
}

/*! Substitui valores do vector por uma lista de valores */
template<typename T>
template<typename Inputltr>
void ls::vector<T>::assign_range(Inputltr first, Inputltr last)
{
    this->clear();
    auto size_range = std::distance(first, last);
    m_len = size_range;
    std::copy(first, last, m_data);

}

/*! Insere um elemento entre os outros valores */
template<typename T>
MyBidirectionalIterator<T> ls::vector<T>::insert(MyBidirectionalIterator<T> pos, const T &value)
{
    if(full())
        reserve(2 * m_size);

    auto sum = (unsigned) std::distance(this->begin(), pos);

        std::copy(m_data+sum, m_data+m_len, m_data+sum+1); 
        *(m_data+sum) = value; 
        m_len++;

    return m_data+sum;
}

/*! Insere um lista de elementos entre os outros valores */
template<typename T>
template<typename Inputltr>
MyBidirectionalIterator<T> ls::vector<T>::insert_range(MyBidirectionalIterator<T> pos, 
                                            Inputltr first, Inputltr last)
{
    auto size_range = (unsigned) std::distance(first, last);

    if((m_size - m_len) < size_range)
        reserve(2 * m_size);

    auto sum = (unsigned) std::distance(this->begin(), pos);

    std::copy(m_data+sum, m_data+m_len, m_data+sum+size_range);
    std::copy(first, last, m_data+sum);
    m_len+=size_range;
    
    return first;
}

/*! Insere um lista de elementos entre os outros valores */
template<typename T>
MyBidirectionalIterator<T> ls::vector<T>::insert_list(MyBidirectionalIterator<const T> 
                                            pos, std::initializer_list<T>list)
{
    auto size_list = (unsigned) std::distance(list.begin(), list.end());

    if((m_size - m_len) < size_list)
        reserve(2 * m_size);

    auto sum = (unsigned) std::distance(this->cbegin(), pos);

    std::copy(m_data+sum, m_data+m_len, m_data+sum+size_list);
    std::copy(list.begin(), list.end(), m_data+sum);
    m_len+=size_list;
    
    return m_data+sum;
}

/*! Remove um dos elementos do vector */
template<typename T>
MyBidirectionalIterator<T> ls::vector<T>::erase( MyBidirectionalIterator<T> pos )
{   
    if ( this->empty() )
        throw std::out_of_range("[erase()]: Cannot erase an element from an empty vector!");

    //Salvar posição a ser retirada
    auto to_move = pos;

    if(pos != end())
        //Sobreescrever o valor da posição especificada
        std::move( ++pos, end(), to_move );

    //Diminui posição lógica do vector
    m_len--;

    return to_move; 

}

/*! Remove uma lista de elementos do vector */
template<typename T>
MyBidirectionalIterator<T> ls::vector<T>::erase( MyBidirectionalIterator<T> first, 
                                            MyBidirectionalIterator<T> last )
{   
    if ( this->empty() )
        throw std::out_of_range("[erase()]: Cannot erase an element from an empty vector!");
        
    //Quantidade de números a serem apagados
    auto size_range = std::distance(first, last);

    if(last != end())
        //Sobreescrever os valores do 'range' especificado
        std::move( last, end(), first );

    //Diminui posição lógica do vector
    m_len-=size_range;

    return first; 
}



//5 - ELEMENT ACESS	-------------------------------------------------------

/*! Retorna primeiro elemento */
template<typename T>
const T & ls::vector<T>::front( void ) const
{
    if ( empty() )
        throw std::out_of_range("[front()]: Cannot recover an element from an empty vector!");

    return m_data[0];
}

/*! Retorna último elemento */
template<typename T>
const T & ls::vector<T>::back( void ) const
{
    if ( empty() )
        throw std::out_of_range("[back()]: Cannot recover an element from an empty vector!");

    return m_data[m_len-1];
}

/*! Retorna elemento da posição especificada */
template<typename T>
T & ls::vector<T>::operator[]( size_t pos) const
{
    return m_data[pos];
}

/*! Retorna elemento da posição especificada, verifica se posição requerida é válida */
template<typename T>
T & ls::vector<T>::at( size_t pos ) const
{
    if(pos < -1 or pos > m_size)
        throw std::out_of_range("[at()]: Cannot recover an element out of range!");
    
    return m_data[pos];
}

//6 - OPERATORS	-----------------------------------------------------------

/*! Compara dois vectores (igualdade) */
template<typename T>
bool ls::vector<T>::operator==(const ls::vector<T> & other) const
{
    if( other.size() == m_len and other.capacity() == m_size){
        auto teste = 0;
        for(auto i = 0u; i != m_len; ++i){
            if(*(m_data+i) != *(other.m_data+i))
                teste++;
        }

        if(teste == 0)
            return true;	
    }
    return false;
}

/*! Compara dois vectores (diferença) */
template<typename T>
bool ls::vector<T>::operator!=(const ls::vector<T> & other) const
{
    if( other.size() == m_len and other.capacity() == m_size){
        auto teste = 0;
        for(auto i = 0u; i != m_len; ++i){
            if(*(m_data+i) != *(other.m_data+i))
                teste++;
        }

        if(teste == 0)
            return false;	
    }
    return true;
}

