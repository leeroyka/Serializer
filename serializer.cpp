#include "serializer.h"

void Serializer::Serialization(std::shared_ptr<AbstractMatrix> matrix, std::string path)
{
	std::ofstream fout;
	fout.open(path);
	fout << *matrix;
	fout.close();
}
void Serializer::Deserialization(std::shared_ptr<AbstractMatrix> matrix, std::string path)
{
	std::ifstream fin(path);
	if (!fin.is_open())
		std::cout << "File not found ;c \n";
	else
	{
		fin >> *matrix;
		fin.close();
	}
}