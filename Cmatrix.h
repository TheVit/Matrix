#pragma once
#include <ctime>
class Cmatrix
{
private:
	typedef  int value_type;
	typedef vector<value_type> row_type;
	typedef vector< row_type> matrix_type;
	typedef unsigned int size_type;
	matrix_type A;
public:
	Cmatrix(size_type M = size_type(), size_type N = size_type(), value_type value = value_type())
	{
		A.resize(M, row_type(N, value));
	};
	
	size_type row_size(void) const { return A[0].size(); }
	size_type column_size(void) const { return A.size(); }

	row_type& operator[](size_type i) { return A[i]; }//перегрузка оператора индексирования для модификации элемента
	const row_type& operator[](size_type i) const { return A[i]; }//перегрузка оператора индексирования для доступа к эелементу
	virtual ~Cmatrix() {};

	void add_row(size_type N, const value_type& value)
	{
		A.push_back(vector<value_type>(N, value));
	}
	void add_column(const value_type& value)
	{
		for (size_type i = 0; i < A.size(); ++i)
			A[i].push_back(value);
	}
	friend ostream& operator<<(ostream& out, const Cmatrix& A)
	{
		for (int i = 0;i < A.row_size();++i)
		{
			for (int j = 0;j < A.column_size();++j)
				out << A[i][j] << "\t";
			out << endl;
		}
		return out;
	}
	// перегрузка оператора + для сложения матриц
	Cmatrix Cmatrix::operator+(const Cmatrix & rhs)
	{
		size_t rhsColSize = rhs.column_size();
		size_t rhsRowSize = rhs.row_size();
		if (this->column_size() == rhsColSize && this->row_size() == rhsRowSize)
		{
			Cmatrix resultMatrix(rhsRowSize, rhsColSize, 0);
			for (size_t i = 0; i < rhs.row_size(); i++) 
			{
				for (size_t j = 0; j < rhs.column_size(); j++)
				{
					resultMatrix[i][j] = (*this)[i][j] + rhs[i][j];
				}
			}
			return resultMatrix;
		}
		return Cmatrix();
	}
	// перегрузка оператора - для вычитания матриц
	Cmatrix Cmatrix::operator-(const Cmatrix & rhs)
	{
		size_t rhsColSize = rhs.column_size();
		size_t rhsRowSize = rhs.row_size();
		if (this->column_size() == rhsColSize && this->row_size() == rhsRowSize) 
		{
			Cmatrix resultMatrix(rhsRowSize, rhsColSize, 0);
			for (size_t i = 0; i < rhs.row_size(); i++)
			{
				for (size_t j = 0; j < rhs.column_size(); j++)
				{
					resultMatrix[i][j] = (*this)[i][j] - rhs[i][j];
				}
			}
			return resultMatrix;
		}
		return Cmatrix();
	}
	// перегрузка оператора * для умножения матриц
	Cmatrix Cmatrix::operator*(const Cmatrix & rhs)
	{
		size_t rhsColSize = rhs.column_size();
		size_t rhsRowSize = rhs.row_size();
		value_type tmp = 0;
		if (this->column_size() == rhsRowSize && this->row_size() == rhsColSize)
		{
			Cmatrix resultMatrix(rhsRowSize, rhsColSize, 0);
			for (size_t i = 0; i < rhs.row_size(); i++)
			{
				for (size_t l = 0; l < rhs.row_size(); l++)
				{
					tmp = 0;
					for (size_t j = 0; j < rhs.column_size(); j++)
					{
						tmp += (*this)[i][j] * rhs[j][l];
					}
					resultMatrix[i][l] = tmp;
				}
			}
			return resultMatrix;
		}
		return Cmatrix();
	}
	// заполнение матрицы рандомными числами в диапазоне от a до b
	void srand(Cmatrix &A, size_type a, size_type b)
	{
		int kol = b - a;
		for (size_t i = 0; i < A.row_size(); i++)
		{
			for (size_t j = 0; j < A.column_size(); j++)
				A[i][j] = rand() % kol + a;

		}
	}
};

