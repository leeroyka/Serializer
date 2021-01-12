
#include "serializer.h"

int main()
{
    std::shared_ptr<AbstractMatrix> abs(new Matrix(3, 4));
    abs->print();
    std::cout << std::endl;
    abs->transpose();
    abs->print();
    Serializer::Serialization(abs,"test");
    return 0;
}
