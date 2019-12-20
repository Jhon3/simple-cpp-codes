#include <iostream>
#include <iterator>

using namespace std;


void print(int *first, int *last){
	std::cout<<std::endl;

	std::cout << "[";
	for (auto i = first; i!=last; ++i){
		std::cout << *i << " ";
	}
	std::cout <<"]" << std::endl;
}

int compare(int A, int B){
	if (A < B) return -1;
	else if (A == B) return 0;
	else return 1;
}




void selection_sort (int A[], int N){

	for(auto i = 0 ; i != N-1; ++i){
		auto menor = i;

		for(auto j = i+1; j != N; ++j){
			if (A[menor] > A[j]){
				menor = j;
			}
		}

		swap(A[menor], A[i]);
	}

	
	
}
int main(){

int A [] = {3, 4, 5, 1, 7, 10, 8, 2, 9, 6};

	std::cout << "A original"<<std::endl;
	print(std::begin(A), std::end(A));
	std::cout << std::endl;


	
	selection_sort(A, 10);
	std::cout << "A ordenado com o insert"<<std::endl;
	print(std::begin(A), std::end(A));
	std::cout<<std::endl;



	return 0;
}
