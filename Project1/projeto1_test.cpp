#include <iostream>
#include <list>
#include <vector>

int main() {
    int a, b, p;
    int n = 2;

    std::list<std::list<int>> *listTypeSlabs = new std::list<std::list<int>>[n + 1];

    for (int i=1; i <= n; i++) {
        std::cin >> a >> b >> p;

        std::list<int> listSpecs = {a, b, p};

        listTypeSlabs[i].push_front(listSpecs);
    }

    return 0;
}