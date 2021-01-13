#include "abstract_matrix.hpp"
AbstractMatrix::AbstractMatrix(int row, int columns)
{
	std::unique_ptr<vectorMatrix> tempMatrix(new vectorMatrix(row, std::vector<int>(columns))); // memory allocation for matrix
    m_matrix = std::move(tempMatrix);
}
std::ostream& operator<< (std::ostream& out, const AbstractMatrix& matrix)
{
	for (auto it = (*matrix.m_matrix).begin(); it != (*matrix.m_matrix).end(); ++it) { //Output matrix to stream
		for (auto it2 = (*it).begin(); it2 != (*it).end(); ++it2) {
			out << *it2;
			if (it2 != (*it).end() - 1)
				out << ' ';
		}
		out << '\n';
	}
	
	return out;
}
std::istream& operator>> (std::istream& in, AbstractMatrix& matrix)
{
	
	for (auto it = (*matrix.m_matrix).begin(); it != (*matrix.m_matrix).end(); ++it) { //Reading matrix from stream
		for (auto it2 = (*it).begin(); it2 != (*it).end(); ++it2) {
			in >> *it2;			
		}
	}
	return in;
}