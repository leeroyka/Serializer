#include <iostream>
#include <vector>
#include <memory>
#include <random>
typedef std::vector<std::vector<int>> vectorMatrix;
class AbstractMatrix {
protected:
    std::unique_ptr<vectorMatrix> m_matrix;   
public:
    AbstractMatrix(int row, int columns);
    virtual void print() {}
    virtual void transpose() {}
};
class Matrix : public AbstractMatrix {
public:
    Matrix(int row, int columns);
    void print();
    void transpose();
};