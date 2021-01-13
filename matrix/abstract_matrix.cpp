#include "abstract_matrix.hpp"
AbstractMatrix::AbstractMatrix(int row, int columns)
{
	std::unique_ptr<vectorMatrix> tempMatrix(new vectorMatrix(row, std::vector<int>(columns))); // memory allocation for matrix
    m_matrix = std::move(tempMatrix);
}
std::ostream& operator<< (std::ostream& out, const AbstractMatrix& matrix)
{
	
	for (auto& it : *matrix.m_matrix) //Output matrix to stream
	{
		for (auto& it2 : it)
		{
			out << it2 << ' ';
		}
		out << '\n';
	}
	
	return out;
}
std::istream& operator>> (std::istream& in, AbstractMatrix& matrix)
{
	
	
	for (auto& it : *matrix.m_matrix) //Reading matrix from stream
	{
		for (auto& it2 : it)
		{
			in >> it2;
		}
	}
	return in;
}