#include "main.h"
#include <iostream>

int main() {
    // Create dynamic Multivectors of various dimensions
    Multivector mv1({1.0, 1.0, 1.0, 1.0});
    Multivector mv2({1.0, 1.0, -1.0, -1.0});
    Multivector mv3({-1.0, -1.0, 1.0, 1.0});
    Multivector mv4({-1.0, -1.0, -1.0, -1.0});
    Multivector mv5({-1.0, 0.0, 0.0}); // Different dimension example

    // Create a SmoothMatrix with these Multivectors
    SmoothMatrix matrix({mv1, mv2, mv3, mv4, mv5});

    // Display original values
    std::cout << "Original Multivectors:\n";
    for (std::size_t i = 0; i < matrix.size(); ++i) {
        std::cout << matrix[i].to_string() << std::endl;
    }

    // Apply tick to scale all components by 2
    matrix.tick();

    // Display scaled values
    std::cout << "\nScaled Multivectors (after tick):\n";
    for (std::size_t i = 0; i < matrix.size(); ++i) {
        std::cout << matrix[i].to_string() << std::endl;
    }

    return 0;
}
