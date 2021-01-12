#include "matrix.h"
AbstractMatrix::AbstractMatrix(int row, int columns)
{
	std::unique_ptr<vectorMatrix> tempMatrix(new vectorMatrix(row, std::vector<int>(columns)));
    m_matrix = std::move(tempMatrix);


}

Matrix::Matrix(int row, int columns) : AbstractMatrix(row,columns)
{      
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(-9,9);
	for (auto it = (*m_matrix).begin(); it != (*m_matrix).end(); ++it) {
		for (auto it2 = (*it).begin(); it2 != (*it).end(); ++it2) {
			*it2 = dist(mt);
		}
	}
}
std::ostream& operator<< (std::ostream& out, const AbstractMatrix& matrix)
{
	for (auto it = (*matrix.m_matrix).begin(); it != (*matrix.m_matrix).end(); ++it) {
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
	//try
	for (auto it = (*matrix.m_matrix).begin(); it != (*matrix.m_matrix).end(); ++it) {
		for (auto it2 = (*it).begin(); it2 != (*it).end(); ++it2) {
			in >> *it2;			
		}
	}
	return in;
}
void Matrix::print()
{
	for (auto it = (*m_matrix).begin(); it != (*m_matrix).end(); ++it) {
		for (auto it2 = (*it).begin(); it2 != (*it).end(); ++it2) {
			std::cout << *it2 << ' ';
		}
		std::cout << std::endl;
	}
}
void Matrix::transpose()
{
	int columns = m_matrix->size();
	int row = m_matrix->at(0).size();
	std::unique_ptr<vectorMatrix> tempMatrix(new vectorMatrix(row, std::vector<int>(columns)));
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			(*tempMatrix)[i][j] = (*m_matrix)[j][i];
		}
	}
	m_matrix.reset();
	m_matrix = std::move(tempMatrix);

}
