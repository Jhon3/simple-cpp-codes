/**
* @file list.h
* @author Jhonattan Carlos Barbosa Cabral
* @author Daniel Marx Pinto Carvalho
* @date 06 Junho 2017
* @brief Arquivo contendo a implementação dos métodos da classe List.
*/


/* Includes */
#include "list.h"

//1 - ESPECIAL MEMBERS -----------------------------------------------

//<! Construtor.
template <typename T>
ls::list<T>::list( )
    : m_len ( 0 )
    , m_head ( new node_t() )
    , m_tail ( new node_t() )
{
    m_head->next = m_tail;
    m_tail->prev = m_head;
}

//<! Construtor cópia.
template <typename T>
ls::list<T>::list( const list & clone_ )
    : m_len ( 0 )
    , m_head ( new node_t() )
    , m_tail ( new node_t() )
{
    for( auto it( clone_.begin() ); it != clone_.end(); ++it )
    {
        push_back( *it );
    }
}

//<! Destrutor.
template <typename T>
ls::list<T>::~list()
{
    clear();
    delete m_head;
    delete m_tail;
}

//2 - ITERATORS ------------------------------------------------------

/*! Retorna referência para o primeiro nó da lista*/
template <typename T>
typename ls::list<T>::iterator ls::list<T>::begin() const
{
    return iterator( m_head->next );
}

/*! Retorna referência constante para o primeiro nó da lista*/
template <typename T>
typename ls::list<T>::const_iterator ls::list<T>::cbegin() const
{
    return const_iterator( m_head->next );
}

/*! Retorna referência para o fim da lista*/
template <typename T>
typename ls::list<T>::iterator ls::list<T>::end() const
{
    return iterator( m_tail );
}

/*! Retorna referência constante para o fim da lista*/
template <typename T>
typename ls::list<T>::const_iterator ls::list<T>::cend() const
{
    return const_iterator( m_tail );
}

//3 - CAPACITY -------------------------------------------------------

/*! Retorna o tamanho da lista*/
template <typename T>
size_t ls::list<T>::size( void ) const
{
    return m_len;
}

/*! Verifica se a lista está vazia. */
template <typename T>
size_t ls::list<T>::empty( void ) const
{
    return m_len == 0;
}

//4 - MODIFIERS --------------------------------------------------------

/*! Imprime a lista. */
template <typename T>
void ls::list<T>::print( )
{
    const node_t *work( m_head->next );

    std::cout << "[ ";
    while( work->next != nullptr )
    {
        // Mostra o conteudo do noh.
        std::cout << work->data << " ";

        // Avancar para o proximo noh.
        work = work->next;
    }
    std::cout << "]\n";
}

/* Esvazia a lista. !*/
template <typename T>
void ls::list<T>::clear()
{
    m_len = 0;
    node_t *trash;

    while(m_head->next != m_tail)
    {
        trash = m_head;
        m_head = m_head->next;
        delete trash;
    }
}

/*! Insere um elemento na frente. */
template <typename T>
bool ls::list<T>::push_front( const T & value_ )
{

    node_t *new_(nullptr);
    try 
    {
        new_ = new node_t( value_, m_head->next, m_head );
    }
    catch ( std::bad_alloc & e )
    {
        return false;
    }

    m_head->next->prev = new_;
    m_head->next = new_;
    m_len++;

    return true;
}

/*! Insere um elemento atrás. */
template <typename T>
bool ls::list<T>::push_back(const T & value_ )
{

    node_t *new_(nullptr);
    try {
        new_ = new node_t( value_, m_tail, m_tail->prev );
    }
    catch ( std::bad_alloc & e )
    {
        return false;
    }

    m_tail->prev->next = new_;
    m_tail->prev = new_;
    m_len++;

    return true;

}

/*! Remove o primeiro elemento. */
template <typename T>
bool ls::list<T>::pop_front()
{   
    if( empty() )
        return false;

    node_t *temp = m_head->next;
    temp->next->prev = m_head;
    m_head->next = temp->next;
    m_len--;

    delete temp;
    return true;
}

/*! Remove o ultimo elemento da lista. */
template <typename T>
bool ls::list<T>::pop_back()
{
    if( empty() )
        return false;

    node_t *temp = m_tail->prev;
    temp->prev->next = m_tail;
    m_tail->prev = temp->prev;
    m_len--;

    delete temp; 
    return true;
}

/*! Preenche a lista com um único elemento. */
template <typename T>
void ls::list<T>::assign(const T & value_)
{
    node_t *work(m_head->next);

    while(work != m_tail)
    {
        work->data = value_;

        work = work->next;
    }
}

/*! Substitui valores da lista por uma lista de valores. */
template <typename T>
void ls::list<T>::assign_list(std::initializer_list<T> list)
{

    this->clear();

    for(auto i = list.begin(); i != list.end(); ++i)
    {
        this->push_back(*i);	
    }

}

/*! Substitui valores da lista por uma lista de valores dada por um range. */
template <typename T>
template<typename Inputltr>
void ls::list<T>::assign_range(Inputltr first, Inputltr last)
{
    this->clear();

    for( auto i(first); i != last; ++i)
    {
        this->push_back(*i);
    }

}

/*! Insere um elemento em uma determinada posição. */
template <typename T>
typename ls::list<T>::iterator ls::list<T>::insert( iterator it_, const T & value_ )
{
    // (1) Aloca o novo nó.
    node_t *new_node = new node_t (value_ );

    //(2) conectar o novo nó a lista.
    new_node->next = it_.m_ptr;
    new_node->prev = it_->prev;

    //(3) fazer a lista reconhecer o nó.
    (it_->prev)->next = new_node; // o next do anterios aponta para o novo nó.
    it_->prev = new_node;

    //(4) incrementa o contador de elementos.
    m_len++;
    return iterator(new_node);

}

/*! Insere um range de elemento em uma determinada posição. */
template <typename T>
template <class Inputltr>
typename ls::list<T>::iterator ls::list<T>::insert_range(iterator it, Inputltr first, Inputltr last)
{

    node_t * work(last->prev);
    auto aux = it;


    while(work != first->prev)
    {
        insert(aux , work->data);
        work = work->prev;
        aux--;
    }

    return iterator(it.m_ptr->prev);
}

/*! Insere uma lista elemento em uma determinada posição. */
template <typename T>
typename ls::list<T>::iterator ls::list<T>::insert_list(iterator it, std::initializer_list<T>list)
{	
    ls::list<T> new_list; 
    new_list.assign_list(list);

    auto retorno = insert_range(it, new_list.begin(), new_list.end());

    return iterator(it.m_ptr->prev);
}

/*! Apaga o elemento de uma determinada posição. */
template <typename T>
typename ls::list<T>::iterator ls::list<T>::erase( iterator it_ )
{
    // Primeiro teste pra saber se a lista esta vazia.
    if(it_ == end()) return iterator (it_.m_ptr);

    auto before(it_->prev);
    auto after(it_->next);

    //(1) bypass o nó a ser movido.
    before-> next = after;
    after-> prev = before;

    //(2) remover o nó marcado.
    delete it_.m_ptr;

    //(3) diminui a quantidade de elementos.
    m_len--;

    return iterator( after );
}

/*! Apaga um range de elementos. */
template <typename T>
typename ls::list<T>::iterator ls::list<T>::erase_range( iterator first, iterator last )
{
    for (auto i = first; i != last; ++i)
    {
        this->erase(i);
    }

    return iterator(last.m_ptr);
}

template <typename T>
typename ls::list<T>::const_iterator ls::list<T>::find(const T & value) const 
{
    auto retorno = cbegin();

    while(retorno != cend())
    {
        if(*retorno == value) break;
        retorno++;	
    }

    return retorno;
}

//5 - ELEMENT ACESS	-------------------------------------------------------
/*! Retorna referencia para o primeiro elemento. */
template<typename T>
const T & ls::list<T>::front( void ) const
{
    return m_head->next->data;
}

/*! Retorna referencia para o primeiro elemento. */
template<typename T>
const T & ls::list<T>::back( void ) const
{
    return m_tail->prev->data;
}

//6 - OPERATORS	-----------------------------------------------------------
/*! Verifica se duas listas são iguais.*/
template<typename T>
bool ls::list<T>::operator==(const ls::list<T> & other) const
{
    
    if( other.size() != this->size())
        return false;

    else
    {
        auto i = 0;
        node_t * work(m_head->next);

        while(work != m_tail)
        {
            auto it = std::next(other.begin(), i);	
            if(work->data != *it)
            {
                return false;
            }

            work = work->next;
            i++;
        }
    }

    return true;
}        	

/*! Verifica se duas listas são dferentes. */
template<typename T>
bool ls::list<T>::operator!=(const list<T> & other) const
{

    if( other.size() != this->size())
        return true;
    
    auto i = 0;
    node_t * work(m_head->next);

    while(work != m_tail)
    {
        auto it = std::next(other.begin(), i);	
        if(work->data != *it)
        {
            return true;
        }

        work = work->next;
        i++;
    }

    return false;
} 