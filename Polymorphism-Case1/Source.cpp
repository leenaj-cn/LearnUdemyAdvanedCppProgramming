//make coffe and make lemon tea 
//with abstract drinking make process;


#include "Base.h"
#include "coffee.h"
#include "tea.h"

void Work(Base* drink)
{
	drink->MakeDrinking();
	delete drink;
}


int main()
{
	//method1
	Base* drink1 = new Coffee;
	Base* drink2 = new Tea;

	drink1->MakeDrinking();
	cout << "~~~~~~~~~~~~" << endl;
	drink2->MakeDrinking();

	delete drink1;
	delete drink2;

	//method2
	//Work(new Coffee);
	//cout << "~~~~~~~~~~~~" << endl;
	//Work(new Tea);


	system("pause");
	return 0;
}