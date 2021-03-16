#include "cpu.h"
#include "computer.h"
#include "Intel.h"
#include "Lenovo.h"
#include "Samsung.h"

int main()
{
	//Intel
	CPU* intelCpu = new IntelCpu;
	GPU* intelGpu = new IntelGpu;
	Memory* intelMem = new IntelMemory;

	Computer* computer1 = new Computer(intelCpu, intelGpu, intelMem);
	computer1->Work();
	delete computer1;

	cout << "~~~~~~~~~~~~" << endl;
	//lenovo
	Computer* computer2 = new Computer(new LenovoCpu, new LenovoGpu, new LenovoMemory);
	computer2->Work();
	delete computer2;

	cout << "~~~~~~~~~~~~" << endl;
	//samsung
	Computer* computer3 = new Computer(new IntelCpu, new SamsungGpu, new LenovoMemory);
	computer3->Work();
	delete computer3;

	system("pause");
	return 0;
}