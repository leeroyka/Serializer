#include <memory>
#include <fstream>
#include <string>
#include "matrix.h"

class Serializer
{
public:
	static void Serialization(std::shared_ptr<AbstractMatrix> matrix, std::string path);
	static void Deserialization(std::shared_ptr<AbstractMatrix> matrix, std::string path);
};