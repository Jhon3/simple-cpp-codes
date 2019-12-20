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

void insert(int A[], int &len, int N, int new_element){

	auto i = len -1;


	while(i >= 0 and new_element < A[i]){

		if(compare(new_element, A[i]) < 0){
			A[i+1] = A[i];
			i--;
		}		
	}
	A[i+1] = new_element;
	len++;
}




void insert_sort (int A[], int N){

	auto size_logic = 1;


	for( auto i = 1; i != N; ++i){
		auto key = A[i];

		insert(A, size_logic, N, key);
	}
}
int main(){

int A [] = {3, 4, 5, 1, 7, 10, 8, 2, 9, 6};

	std::cout << "A original"<<std::endl;
	print(std::begin(A), std::end(A));
	std::cout << std::endl;


	
	insert_sort(A, 10);
	std::cout << "A ordenado com o insert"<<std::endl;
	print(std::begin(A), std::end(A));
	std::cout<<std::endl;



	return 0;
}
