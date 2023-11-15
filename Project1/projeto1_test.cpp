#include <iostream>
#include <list>
#include <vector>

int main() {
    int a, b, p;
    int n = 2;

    std::list<std::list<int>> *listTypeSlabs = new std::list<std::list<int>>[n + 1];

    // FIX nao da para ler as coisas como deve de ser

    for (int i = 1; i <= n; i++) {
        std::cin >> a >> b >> p;

        std::list<int> listSpecs = {a, b, p};

        listTypeSlabs[i].push_front(listSpecs);
    }

    for (int i = 1; i <= n; i++) {
        for (const auto &listSpecs : listTypeSlabs[i]) {
            for (const auto &valueInt : listSpecs) {
                std::cout << valueInt << " ";
            }
            std::cout << std::endl;
        }
    }

    return 0;
}