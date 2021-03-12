#include <iostream>
using namespace std;

class myException {
public:
	virtual const char* what() const throw() {
		return "Somthing bad happened";
	}
};


class Test {
public:
	void goesWrong() {
		throw myException();
	}
};


int main()
{
	Test myTest;
	try {
		myTest.goesWrong();
	}
	catch (myException& e) {
		cout << "exception catched:" << e.what() << endl;
	}

		

	return 0;
}