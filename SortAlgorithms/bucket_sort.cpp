#include <iostream>
#include <iterator>
#include <cmath> // floor and ceil
#include <algorithm>


using namespace std;
 


 typedef struct {

 	int balde [20];

 } Buckets;



int compare(int A, int B){
	if (A < B) return -1;
	else if (A == B) return 0;
	else return 1;
}



void bubble(int *first, int *last){
	bool troca = true;



	while (troca == true){
		troca = false;

		for (auto i = first; i != last; ++i){
			if(compare (*i, *(i+1)) > 0){
				swap(*i, *(i+1));
				troca = true;
			}
		}
	}
}



void bucket_sort(int a[], int n) {
	auto size = 10;
    int buckets[size];
    
    for(auto i = 0; i < size; ++i)
        buckets[i] = 0;
    
    for(auto i = 0; i < n; ++i)
        ++buckets[a[i]];
        
    for(auto i = 0, j = 0; j < size; ++j){
        for(auto k = buckets[j]; k > 0; --k){
            a[i++] = j;
        }
    }
}



void print(int *first, int *last){
	std::cout<<std::endl;

	std::cout << "[";
	for (auto i = first; i!=last; ++i){
		std::cout << *i << " ";
	}
	std::cout <<"]" << std::endl;
}




int main(){


	int A[] = {1, 3, 23, 4, 5, 7, 10, 60, 21, 20};
	int B[] = {30, 55, 9, 3, 4, 5, 2, 1, 10, 18};

	std::cout << "A original"<<std::endl;
	print(std::begin(A), std::end(A));
	std::cout << std::endl;


	bubble(std::begin(A), std::end(A));
	std::cout << "A ordenado com o bubble"<<std::endl;
	print(std::begin(A), std::end(A));
	std::cout<<std::endl;

	bucket_sort(B, 10);
	std::cout << "B ordenado com o bucket"<<std::endl;
	print(std::begin(B), std::end(B));
	std::cout<<std::endl;
}