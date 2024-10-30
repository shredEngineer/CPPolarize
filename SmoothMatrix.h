#ifndef SMOOTHMATRIX_H
#define SMOOTHMATRIX_H

#include "Multivector.h"
#include <vector>

class SmoothMatrix {
public:
    // Constructor for a SmoothMatrix that can store any number of Multivectors
    SmoothMatrix(const std::vector<Multivector>& multivectors) : multivectors_(multivectors) {}

    // Tick function to scale all components of each multivector by an interval
    void tick() {
        const long double interval = 2.0;
        for (auto& multivector : multivectors_) {
            for (std::size_t i = 0; i < multivector.dimension(); ++i) {
                multivector[i] *= interval;
            }
        }
    }

    // Method to add a new Multivector to the SmoothMatrix
    void addMultivector(const Multivector& mv) {
        multivectors_.push_back(mv);
    }

    // Access multivectors by index
    Multivector& operator[](std::size_t index) { return multivectors_[index]; }
    const Multivector& operator[](std::size_t index) const { return multivectors_[index]; }

    // Get number of multivectors
    std::size_t size() const { return multivectors_.size(); }

private:
    std::vector<Multivector> multivectors_;
};

#endif // SMOOTHMATRIX_H
