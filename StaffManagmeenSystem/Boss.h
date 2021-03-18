#include "Employee.h"

class Boss :public Employee
{
public:

	Boss(string name, int employee_id, int depart_id);

	virtual string getDepartmentName();

	virtual void showInfo();

};

