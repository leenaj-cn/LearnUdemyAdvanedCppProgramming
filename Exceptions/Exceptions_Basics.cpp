#include <iostream>
using namespace std;

void mightGoWrong() {

	bool error1 = false;
	bool error2 = false;
	bool error3 = true;

	if (error1) {
		throw 8;
	}

	if (error2)
	{
		throw "this is wrong!";
	}

	if (error3)
	{
		throw string("this is antoher wrong!");
	}

}
int main() {
	try {
		mightGoWrong();
	}
	catch (int e) {
		cout << "error code:  " << e << endl;
	}
	catch (const char* e)
	{
		cout << "error code: " << e << endl;
	}
	catch (string e)
	{
		cout << "error code: " << e << endl;
	}

	
	return 0;

}
