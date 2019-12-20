#include <iostream>
#include <iterator>
using namespace std;

int compact(int *B, int *first, int *last);

int main(){
int L;
int A[] = {2, 8, 2, -7, -3, 10, 1, 0, 3, -7};


std::cout << "Vetor antes do compacta:"<<std::endl;
for(auto i = std::begin(A); i!=std::end(A); ++i){
	std::cout << *i << "  ";
}
std::cout<<std::endl;


L = compact(A, std::begin(A), std::end(A));


std::cout << "Vetor depois do compacta:"<<std::endl;
for(auto i=0; i<L; ++i){
	std::cout <<A[i] << "  ";
}
std::cout<<std::endl;

std::cout<< "Tamanho do vetor >>>> " << L << std::endl;
	return 0;

}
int compact(int *B, int *first, int *last){

	int size = 0;

	for(auto i = first; i!= last; ++i){
		if (*i > 0) {
			size++;
		}
	}
	for(auto i = 0; i!= size; /*empty*/){
		for(auto j= first; j!= last; ++j){
			if(*j > 0){
				B[i] = *j;
				++i;
			}
		}
	}
	
	return size;
}