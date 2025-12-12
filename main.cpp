#include <iostream>
#include "algorithms/AlgorithmFactory.h"
#include "base/Solution.h"

int main() {
    auto& f = AlgorithmFactory::instance();
    auto cats = f.listCategories();

    std::cout << "Categories:\n";
    for (int i = 0; i < cats.size(); ++i)
        std::cout << i << ": " << cats[i] << "\n";

    int c;
    std::cout << "Choose category: ";
    std::cin >> c;

    auto algos = f.listAlgorithms(cats[c]);

    std::cout << "Algorithms:\n";
    for (int i = 0; i < algos.size(); ++i)
        std::cout << i << ": " << algos[i] << "\n";

    int a;
    std::cout << "Choose algorithm: ";
    std::cin >> a;

    auto algo = f.create(algos[a]);

    InputData input;
    input.arr = {5, 1, 4, 2, 8};

    algo->loadInput(input);
    algo->solve();
}
