#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void Swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;

	return;
}

int main()
{
	cout << "case5: swap template" << endl;
	int swa = 2;
	int swb = 3;
	cout << "before: " << swa << " " << swb << endl;
	Swap(swa, swb);
	cout << "after: " << swa << " " << swb << endl << endl;

	cout << "case4: bubble sort" << endl;
	int N = 9;
	int array[9] = { 4,2,8,0,5,7,1,3,9 };
	for (int i = 0; i < N; i++)
		cout << array[i] << " ";
	cout << endl;

	for (int i = 0; i < 9-1; i++)
	{
		for (int j = 0; j < N-1-i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(array[j], array[j + 1]);
				//int temp = array[j];
				//array[j] = array[j + 1];
				//array[j + 1] = temp;
			}
				
		}

	}
	for (int i = 0; i < N; i++)
		cout << array[i] << " ";
	cout << endl;

	cout << "case3: " << endl;
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << j << "x" << i <<"="<< i * j << " ";
		}
		cout << endl;
	}

	cout << "case2: " << endl;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}

	cout << "case1: " << endl;
	int DaffodilNumber[] = { 0 };
	int cycles = 0;
	for (int number = 100; number < 1000; number++)
	{
		int ones = number % 10;
		int tens = number / 10 % 10;
		int hundreds = number / 100;

		int onesNumber3 = ones * ones * ones;
		int tensNumber3 = tens * tens * tens;
		int hundredsNumber3 = hundreds * hundreds * hundreds;

		if ((onesNumber3 + tensNumber3 + hundredsNumber3) == number)
		{
			cout << number << " is a Daffodil Number" << endl;
			DaffodilNumber[cycles] = number;
			cycles++;
		}
	}
	cout << "cycles=" << cycles << endl;
	for (int i = 0; i < cycles; i++)
		cout << DaffodilNumber[i] << " ";

	cout << endl;
	system("pause");
	return 0;
}