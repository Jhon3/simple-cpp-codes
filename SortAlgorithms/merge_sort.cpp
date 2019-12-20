/*!
 * This program implements the mergesort algorithm
 *
 * @date: April, 4th, 2017
 *
 */

#include <iostream>     // cout, endl
#include <algorithm>

/// Displays on the screen (std::cout) the content of a range of integers.

void print( int * first_, int * last_ )
{
    std::cout << "[ ";
    while( first_ < last_ )
    {
        std::cout << *first_ << " ";
        first_++;
    }
    std::cout << "]";
}

/*!
 * Combina os elementos de um _range_ `a` com os elemento de um _range_ `b`
 * em um _range_ de saída `c`.
 *
 * \note
 * Os _ranges_ de entrada, `a` e `b`, devem estar em ordem **não decrescente**.
 *
 * \note
 * Assume que: sizeof(c) >= sizeof(a) + sizeof(b).
 */
void merge( int *first_a, int *last_a,
            int *first_b, int *last_b,
            int *first_c )


{   
    while(first_a != last_a){

        if(first_b == last_b){
            //copia o resto de a para c.
            std::copy( first_a, last_a, first_c);
            return;
        }

        if (*first_a <= *first_b){
                *first_c = *first_a;
                first_a++;
        }
        else{
                *first_c = *first_b;
                first_b++;
        }

        first_c++;
    }
    //copia o resto de b para c.
     std::copy( first_b, last_b, first_c);
}



void merge_sort (int *first, int *last)
{
   
   //calcular o tamanho do vetor

    auto n = std::distance(first,last);

    if (n < 2) return; //vetor com 1 elemento ja esta ordenado!

    auto len_left = n/2; // tamanho do vetor esquerdo.
    auto len_right = n - n/2; //tamanho do vetor da direita.

    int *L = new int [len_left];
    int *R = new int [len_right];

    std::copy( first, first + len_left, L); // copiar a primeira parte para left.
    std::copy(first + len_left, last, R); //copiar o que sobrou para right.

    //leap of faith
    merge_sort(L, L + len_left);
    merge_sort(R, R + len_right);
    merge(L, L+len_left, R, R+len_right, first); // mesclar L com R no vetor original. 

    delete [] L;
    delete [] R;
}



int main( void )
{
    int A[] = { 1, 1, 3, 5, 5, 7,  9, 11, 11, 13 }; // Size = 10.
    int B[] = { 2, 2, 4, 6, 8, 8, 10, 10, 12, 12, 14, 16, 16, 18, 20 }; // Size = 15.
    int C[25]; // Size of A + Size of B.

    int D[10] = {4, 6, 7, 9, 10, 1, 2, 3, 5, 6};

    int E[] = { 2, 3, 6, 8, 10 }; // Size = 5.
    int F[] = { 1, 4, 5, 7, 9}; // Size = 5.
    int G[10]; // Size of E + Size of F.

    std::cout << ">>> Array A:\n";
    print( std::begin(A), std::end(A) );
    std::cout << std::endl;

    std::cout << ">>> Array B:\n";
    print( std::begin(B), std::end(B) );
    std::cout << std::endl;


    merge(std::begin(A), std::end(A), std::begin(B), std::end(B), std:: begin(C));

    std::cout << ">>> Array C:\n";
    print( std::begin(C), std::end(C) );
    std::cout << std::endl;


    merge(std::begin(E), std::end(E), std::begin(F), std::end(F), std:: begin(G));

    std::cout << ">>> Array G:\n";
    print( std::begin(G), std::end(G) );
    std::cout << std::endl;



    std::cout <<">>>Array D original: \n";
    print( std::begin(D), std::end(D));
    std::cout << std::endl;

    merge_sort(std::begin(D), std::end(D));

    std::cout <<">>>Array D ordenado: \n";
    print( std::begin(D), std::end(D));
    std::cout << std::endl;

    return 0;
}
