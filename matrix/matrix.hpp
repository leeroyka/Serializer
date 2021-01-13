#include "../matrix/abstract_matrix.hpp"
class Matrix : public AbstractMatrix {
public:
    Matrix(int row, int columns);
    void print() final;
    void transpose();
};