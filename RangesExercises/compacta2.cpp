#include <iostream>
#include <iterator>


using namespace std;
int* compacta (int *first, int *last);

int main(){
int vetor [] = { 1 , 0, -2, -3, 4, 5, 6, 7, 8, 9};


std::cout << "Vetor sem compacta: "<<std::endl;

for(auto i = std::begin(vetor) ; i != std::end(vetor) ; ++i){
	std::cout << *i << "  ";
}
std::cout <<endl;


std::cout << "Vetor depois do compacta: " << endl;

auto new_l = compacta(std::begin(vetor), std::end(vetor));
auto size = std::distance(std::begin(vetor), new_l);
std::cout << "O tamanho do vetor eh: " << size << std::endl;

for(auto i = std::begin(vetor) ; i != new_l ; ++i){
	std::cout << *i << "  ";
}
std::cout <<endl;

	return 0;
}


int* compacta (int *first, int *last){
auto slow = first;


for (auto fast = first ; fast != last; ++fast){
	if(*fast > 0){
		swap(*slow, *fast);
		++slow;
	}
}

return slow;

}