#include "stdafx.h"

int main()
{
	// ������������� ������� 5 �� 5 �� ��������� 0
	Cmatrix A(5, 5, 0); 
	Cmatrix B(5, 5, 0);
	int a=1, b=6;
	// ���������� ������� ���������� � ��������� �� a �� b
	A.srand(A, a, b); 
	B.srand(B, a, b);
	// ����� ������ �� �����
	cout << "Matrix A:" << endl;
	cout << A << endl;
	// ���������� ������ � ������� � �������
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
	//�������������� �������� ��� ���������
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
