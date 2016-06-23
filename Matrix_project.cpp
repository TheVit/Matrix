#include "stdafx.h"

int main()
{
	// инициализация матрицы 5 на 5 со значением 0
	Cmatrix A(5, 5, 0); 
	Cmatrix B(5, 5, 0);
	int a=1, b=6;
	// заполнение матрицы значениями в диапазоне от a до b
	A.srand(A, a, b); 
	B.srand(B, a, b);
	// вывод матриц на экран
	cout << "Matrix A:" << endl;
	cout << A << endl;
	// добавление строки и столбца в матрицу
	cout << "Add row 000, column 111:" << endl;
	A.add_row(5, 000);
	A.add_column(111);
	cout << "Matrix A:" << endl;
	cout << A << endl;

	cout << "Matrix B:" << endl;
	cout << B << endl;
	cout << "Add row 111, culumn 000:" << endl;
	B.add_row(5, 111);
	B.add_column(000);
	cout << "Matrix B:" << endl;
	cout << B << endl;
	//арифметические операции над матрицами
	cout << "A+B:" << endl;
	cout << A + B << endl;
	cout << "A-B:" << endl;
	cout << A - B << endl;
	cout << "A*B:" << endl;
	cout << A * B << endl;
	cout << "C=(A+B)*(A-B):" << endl;
	cout << (A + B)*(A - B) << endl;
	system("pause");
	return 0;
}
