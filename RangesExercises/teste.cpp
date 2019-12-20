#include <iostream>
#include <iterator>

using namespace std;

void reverse (int *first, int *last);

int main(){
	int A []= { 1, 2, 3, 4, 5};
	
	reverse(std::begin(A), std::end(A));

	for(auto i = std::begin(A); i!= std::end(A); ++i){
		std::cout << *i << "  ";
	}

	std::cout <<std::endl;

	return 0;
}

void reverse (int *first, int *last){

	for(auto i=first; i!=last; ++i){
		std::swap(i, (last-i-1));
	
	}
}
	
	
