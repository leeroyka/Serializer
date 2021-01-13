#include "matrix.hpp"

Matrix::Matrix(int row, int columns) : AbstractMatrix(row,columns)
{      
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(-9,9);  // generate random number [-9;9]
	for (auto& it : *m_matrix) //Fill matrix
	{
		for (auto &it2 : it)
		{
			it2 = dist(mt);
		}
	}
}

void Matrix::print()
{
	// Output design
	int numberRow = 0;
	std::cout << "  ";
	for (auto it2 : (*m_matrix)[0])
	{
		std::cout << ' ' << numberRow++ << ' ';
	}
	std::cout << std::endl;
	for (int i=0;i<(*m_matrix)[0].size() * 3+2;i++)
		std::cout << '-';
	std::cout << std::endl;
	numberRow = 0;
	// 

	for (auto it : *m_matrix)
	{
		std::cout << numberRow++ << '|';
		for (auto it2 : it)
		{
			if(it2>=0)
				std::cout << ' ';
			std::cout << it2 << ' ';
		}
		std::cout << std::endl;
	}

	std::cout << std::endl << std::endl;
}
void Matrix::transpose()
{
	int columns = m_matrix->size(); //getting sizes of transposed matrix
	int row = m_matrix->at(0).size();
	std::unique_ptr<vectorMatrix> tempMatrix(new vectorMatrix(row, std::vector<int>(columns))); //creation of a temporary matrix
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
