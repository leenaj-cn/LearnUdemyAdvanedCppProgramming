#include "Employee.h"

class GeneralEmployee :public Employee
{
public:

	GeneralEmployee(string name, int employee_id, int depart_id);

	virtual string getDepartmentName();

	virtual void showInfo();




};
