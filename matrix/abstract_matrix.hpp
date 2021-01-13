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
    virtual void print() = 0;
    virtual void transpose() = 0;
    friend std::ostream& operator<< (std::ostream& out, const AbstractMatrix& matrix);
    friend std::istream& operator>> (std::istream& in, AbstractMatrix& matrix);
};