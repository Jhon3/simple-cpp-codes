LIST
======

### O PROJETO
O objetivo do projeto é implementar a classe list ultilizando lista duplamente encadeada.

## SOBRE A LISTA DUPLAMENTE ENCADEADA
Numa lista cada elemento, ou nó, é composto normalmente por uma variável que guarda a informação(Objeto, inteiro, cadeia de caractéres, etc) e dois ponteiros (referências a endereços de memória) que permitem a ligação entre os vários nós desta lista. Este tipo de lista é conhecido por "Duplamente ligada" ou "Duplamente encadeada" exatamente pelo fato de possuir duas váriaveis de controle (ponteiros) ao contrário da lista simplesmente ligada que possui somente um, o qual aponta para o próximo elemento da lista.

A função destas variáveis é guardar o endereço de memória do nó anterior e do nó posterior, identificados normalmente como "prev" ou "previous" e "next". Com estas estruturas podemos realizar diversas tarefas que seriam impossiveis ou muito dispendiosas com uma lista simplesmente encadeada.

No modelo mais simples deste tipo de lista, ao criar a lista o primeiro nó tem seu ponteiro "previous" apontando sempre para nulo e o último nó com seu "next" apontando para nulo.

### COMPILAR E EXECUTAR

**Para compilar use:**	
[Opção 1] $ -Wall -std=c++11 ./src/*.cpp -o ./bin/main -I ./include		
[Opção 2] $ make	

**Para executar use:**		
[Opção 1] $ ./bin/main	
[Opção 2] $ make run

### POSSÍVEIS ERROS
Foram feitos inúmeros testes a fim de evitar erros, porém ainda pode haver algum erro que não tenha sido previsto antes.

### AUTORES
**Jhonattan Carlos Barbosa Cabral.** 	
Graduando em Tecnologia da Informação. 
Instituto Metrópole Digital (IMD).
Universidade Federal do Rio Grande do Norte (UFRN).

**Daniel Marx Pinto Carvalho**		
Graduando em Tecnologia da Informação. 
Instituto Metrópole Digital (IMD).
Universidade Federal do Rio Grande do Norte (UFRN).

**Natal, 06 de junho de 2017.**

### REFERÊNCIAS
-[Cppreference](http://en.cppreference.com/w/)	
-[Wikipédia](https://pt.wikipedia.org/wiki/Lista_duplamente_ligada)
-[Makefile genérico](https://gist.github.com/maurizzzio/de8908f67923091982c8c8136a063ea6)
