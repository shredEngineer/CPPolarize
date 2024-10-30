#ifndef MULTIVECTOR_H
#define MULTIVECTOR_H

#include <vector>
#include <string>
#include <sstream>
#include <iomanip> // for setting precision

class Multivector {
public:
    // Constructor accepting a vector of high-precision floats
    Multivector(const std::vector<long double>& components) : components_(components) {}

    // Function to get the dimension (size) of the array
    std::size_t dimension() const { return components_.size(); }

    // Access components by reference for modification
    long double& operator[](std::size_t index) { return components_[index]; }
    const long double& operator[](std::size_t index) const { return components_[index]; }

    // Method to get string representation of the vector, e.g., "[1.0, 0.0, ...]"
    std::string to_string() const {
        std::ostringstream oss;
        oss << "[";
        for (std::size_t i = 0; i < components_.size(); ++i) {
            oss << std::fixed << std::setprecision(1) << components_[i];
            if (i < components_.size() - 1) {
                oss << ", ";
            }
        }
        oss << "]";
        return oss.str();
    }

private:
    std::vector<long double> components_;
};

#endif // MULTIVECTOR_H
