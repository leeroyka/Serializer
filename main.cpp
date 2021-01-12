#include "serializer/serializer.hpp"
int main()
{
    std::shared_ptr<AbstractMatrix> matrixFirst(new Matrix(3, 4));
    matrixFirst->print();
    matrixFirst->transpose();
    matrixFirst->print();
    Serializer::Serialization(matrixFirst,"e:\\data.bin");
    std::shared_ptr<AbstractMatrix> matrixSecond(new Matrix(4, 3));
    Serializer::Deserialization(matrixSecond, "e:\\data.bin");
    matrixSecond->print();
    return 0;
}
