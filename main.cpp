
#include "serializer.h"

int main()
{
    std::shared_ptr<AbstractMatrix> abs(new Matrix(3, 4));
    abs->print();
    std::cout << std::endl;
    abs->transpose();
    abs->print();
    Serializer::Serialization(abs,"e:\\data.bin");

    std::shared_ptr<AbstractMatrix> abs2(new Matrix(4, 3));

    Serializer::Deserialization(abs2, "e:\\data.bin");
    abs2->print();
    return 0;
}
