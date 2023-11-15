# Base

## Introdução

-> A linha tem **dois** discos
-> A chapa é cortada verticalmente ou horizontalmente
-> Cada  uma das duas novas chapas produzidas volta a entrar ou sai, caso seja do tamanho que queremos ou nao preste
-> 

## Objetivo

Dada uma chapa de marmore o programa calcula o valo maximo obtido a partir das pecas do tamanho queridas pelo cliente
A linha recebe uma chapa retangular **X x Y** e tem acesso a uma lista com os **n** tipos de peca a serem produzidos. Cada tipo de peça **i € {1, 2, ..., n}** correspondente a um retangulo com dimensoes **a(i) x b(i)** e é vendido a um preço **p(i)**.

## Input
O ficheiro de entrada contrm as dimensoes da chapa e as dimensoes dos tipos de peças

1-> A primeira linha contem **X e Y** separados por um espaço em branca

2-> A segunda linha tem um **n** corresponde ao numero de pecas a serem produzidos

3-> Depois são **n linhas** com cada um dos tipos **i** de pecas a serem produzidas, cada linha é composta por **a(i) b(i) e p(i)** separados por um espaço


### Ideia de codigo

1-
```
int x, y;
std::cin >> x >> y;
```

2-
```
int n
std::cin >> n;
```

3-
```
int a, b, p;
int n = 2;

std::list<std::list<int>> *listTypeSlabs = new std::list<std::list<int>>[n + 1];

FIX nao da para ler as coisas como deve de ser

for (int i=1; i <= n; i++) {
    std::cin >> a >> b >> p;

    std::list<int> listSpecs = {a, b, p};

    listTypeSlabs[i].push_front(listSpecs);
}
```