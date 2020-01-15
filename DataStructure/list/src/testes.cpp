/**
* @file testes.cpp
* @author Jhonattan Carlos Barbosa Cabral
* @author Daniel Marx Pinto Carvalho
* @date 06 Junho 2017
* @brief Arquivo contendo os testes da classe list.
*/

#include "testes.h"

void teste()
{
//-------------------------------------------------------------//
//<! Inicio dos testes.
    std::cout << "\t\t\t\t --Inicio dos testes--\n";
    std::cout << "-----------------------------------------------------------------------------------------\n";
//-------------------------------------------------------------//

//<! Iterator
//<! begin(), end(), cbegin(), cend();

	std::cout << "--Teste Iterator--\n";
    //begin() e end()
	ls::list<int> teste1;
	teste1.push_back(1);
	teste1.push_back(2);
	teste1.push_back(3);

	ls::list<int>::iterator it = teste1.begin();

    assert(*it == 1);
	std::cout << ">>>begin() aprovado. \n";

	it = teste1.end();
	assert(++it == nullptr);
	std::cout << ">>>end() aprovado. \n";

    // cbegin() e cend()
    {
        ls::list<const int> teste1;
        teste1.push_back(1);
        teste1.push_back(2);
        teste1.push_back(3);

    	ls::list<const int>::const_iterator cit = teste1.cbegin();

        assert(*cit == 1);
        std::cout << ">>>cbegin() aprovado. \n";

        cit = teste1.cend();
        assert(++cit == nullptr);
        std::cout << ">>>cend() aprovado. \n\n\n";
    }

//-------------------------------------------------------------//
//<! Capacity
//!<size(), empty();

	std::cout << "--Teste Capacity--\n";
	
	assert(teste1.size() == 3);
	std::cout << ">>>size() aprovado.\n";

	assert(teste1.empty() == 0);
	std::cout << ">>>empty() aprovado.\n\n\n";

//-------------------------------------------------------------//

//<! Modefier
	ls::list<int> teste2;
	teste2.push_back(1);
	teste2.push_back(2);
	teste2.push_back(3);
	std::cout << "--Teste Modefier-- \n";

//<! clear();
	teste1.clear();
	assert(teste1.size() == 0);
	std::cout << ">>>clear() aprovado.\n";

//<! push_back();
	assert(teste2.size() == 3);
	teste2.push_back(4);
	assert(teste2.front() == 1);
	assert(teste2.back() == 4);
	assert(teste2.size() == 4);
	std::cout << ">>>push_back() aprovado.\n";

//<! pop_back();
	assert(teste2.size() == 4);
	teste2.pop_back();
	assert(teste2.back() == 3);
	assert(teste2.size() == 3);
	std::cout << ">>>pop_back() aprovado.\n";

//<! push_front();
	assert(teste2.size() == 3);
	teste2.push_front(0);
	assert(teste2.front() == 0);
	assert(teste2.size() == 4);
	std::cout << ">>>push_front() aprovado.\n";

//<! pop_front();
	assert(teste2.size() == 4);
	teste2.pop_front();
	assert(teste2.front() == 1);
	assert(teste2.size() == 3);
	std::cout << ">>>pop_front() aprovado.\n";

//<! assign();
	teste2.assign(5);
	for(auto i = teste2.begin(); i != teste2.end(); ++i)
		assert(*i == 5);
	std::cout << ">>>assign() aprovado.\n";

//<! assign_list();
	teste2.assign_list({1, 2, 3, 4});
	assert(teste2.size() == 4);
	auto j = 1;
	
	for(auto i = teste2.begin(); i != teste2.end(); ++i)
	{
		assert(*i == j);
		++j;
	}
	std::cout << ">>>assign_list() aprovado.\n";

//<! assign_range();
    ls::list<int>aux;
    aux.assign_list({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    aux.assign_range(teste2.begin(), teste2.end());
    
    auto k = 1;
    for(auto i = teste2.begin(); i != teste2.end(); ++i)
    {
        assert(*i == k);
        ++k;
    }
    
    std::cout << ">>>assign_range() aprovado. \n";

//<! insert();
    ls::list<int>teste3;
    ls::list<int>compare1;
    teste3.assign_list({1, 2, 3, 4});
    compare1.assign_list({0, 1, 2, 3, 4, 5});

    ls::list<int>::iterator it2 = teste3.begin();

    auto result = teste3.insert(it2, 0);
    auto it_ = teste3.insert(std::next(teste3.end(), 0),  5);
    assert(teste3 == compare1);
    assert(*it_ == 5);
    std::cout << ">>>insert() aprovado. \n";

//!< insert_range();
    ls::list<int>teste6;
    ls::list<int>compare2;
    teste6.assign_list({6, 7, 8});
    compare2.assign_list({0, 1, 2, 3, 4, 5, 6, 7, 8});
    auto pont2 = teste3.insert_range(teste3.end(), teste6.begin(), teste6.end());
    assert(teste3 == compare2);
    assert(*pont2 == 8);
    assert(teste3.size() == 9);
    std::cout << ">>>insert_range() aprovado.\n";

//<! insert_list();
    ls::list<int>compare3;
    compare3.assign_list({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11});
    auto pont3 = teste3.insert_list(std::next(teste3.end(), 0) , {9, 10, 11});
    assert(teste3 == compare3);
    assert(*pont3 == 11);
    std::cout << ">>>insert_list() aprovado.\n";

//<! erase()
    ls::list<int>testeErase;
    testeErase.assign_list({1, 2, 3, 4, 5});

//<! Teste (1) - Apagando o primeiro elemento.
    ls::list<int>comp1;
    comp1.assign_list({2, 3, 4, 5});
    auto pontTeste1 = testeErase.erase(testeErase.begin());
    assert(*pontTeste1 == 2);
    assert(testeErase == comp1);
 
//<! Teste (2) - Apagando o segundo elemento.
    ls::list<int>comp2;
    comp2.assign_list({2, 4, 5});
    pontTeste1 = testeErase.erase(std::next(testeErase.begin(),1));

    assert(*pontTeste1 == 4);
    assert(testeErase == comp2);

//<! Teste (3) - Apagando o ultimo elemento.

    ls::list<int>comp3;
    comp3.assign_list({2, 4});
    auto pontTeste2 = testeErase.erase(--(testeErase.end()));
    assert(testeErase == comp3);

   	std::cout << ">>>erase() aprovado.\n";

//<! erase_range()
    ls::list<int>testeErase2;
    testeErase2.assign_list({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});

//<! Teste (1) - Apagando os 4 primeiros elementos.
    ls::list<int>comp4;
    comp4.assign_list({6, 7, 8, 9, 10});
    auto pontTeste3 = testeErase2.erase_range(testeErase2.begin(), std::next(testeErase2.begin(), 5) );
    assert(testeErase2 == comp4);
    assert(*pontTeste3 == 6);

//<! Teste (2) - Apaga todos os elementos restantes.
    pontTeste3 = testeErase2.erase_range( testeErase2.begin(), testeErase2.end() );
    assert(testeErase2.size() == 0);
    std::cout << ">>>erase_range() aprovado.\n";

//<! Find()
	ls::list<const int>find_l;
    find_l.assign_list({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});	
    for (auto i(0); i < 10; i++) 
	{
        assert(*find_l.find(i) == i);
	}
	std::cout << ">>>find() aprovado.\n\n\n";
    
//-------------------------------------------------------------//

	//-------------------------------------------------------------//
//<! Element acess
	std::cout << "--Teste Element acess--\n";

//<! front();
	ls::list<int>teste_;
	teste_.push_back(1);
	teste_.push_back(3);

	assert(teste_.front() == 1);
	std::cout << ">>>front() aprovado.\n";

//<! back();
	assert(teste_.back() == 3);
	std::cout << ">>>back() aprovado.\n\n\n";

//-------------------------------------------------------------//

//<! Operators
	std::cout << "--Teste Operators--\n";
//<! operator==()
	ls::list<int>testeOp1;
	ls::list<int>testeOp2;
	testeOp1.assign_list({1, 2, 3, 4});
	testeOp2.assign_list({1, 2, 3, 4});
	assert(testeOp1 == testeOp2);
	std::cout << ">>>operator==() aprovado.\n";

//<! operator==()
	testeOp2.push_back(5);
	assert(testeOp1 != testeOp2);
	std::cout << ">>>operator!=() aprovado.\n\n\n";

//-------------------------------------------------------------//
//<! Fim dos testes
    std::cout << "-----------------------------------------------------------------------------------------\n";
    std::cout << "\t\t\t\t --Fim dos testes--\n\n";
    std::cout << ">>> Para mais detalhes sobre os testes por favor consultar os arquivos testes.cpp e testes.h.\n";
 	
}