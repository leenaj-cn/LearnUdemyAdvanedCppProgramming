#include <iostream>
using namespace std;

class CanGoWrong {
public:
	//this is a constructor 
	CanGoWrong() {
		char* myChar = new char[9999999999999999];
		
		delete[] myChar;
			
		}

};


int main()
{
	try {
		CanGoWrong wrong;
		//int* myarray = new int[9999999999999999];
	}
	catch(bad_alloc &e){
		cout << "catch bad_alloc: " << e.what() << endl;
	}
	catch (bad_cast &e) {
		cout << "catch bad_cast: " << e.what() << endl;
	}
	catch (bad_exception &e) {
		cout << "catch bad_exception: " << e.what() << endl;
	}



	cout << "still running" << endl;


	return 0;

}