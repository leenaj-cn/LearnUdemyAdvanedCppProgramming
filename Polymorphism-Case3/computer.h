#include "cpu.h"

class Computer
{
public:
	Computer(CPU* cpu, GPU* gpu, Memory* memory)
	{
		m_Cpu = cpu;
		m_Gpu = gpu;
		m_Memory = memory;
	}
	void Work()
	{
		m_Cpu->LogicProcessing();
		m_Gpu->Computing();
		m_Memory->Storage();
	}

	~Computer()
	{
		if (m_Cpu != NULL)
			delete m_Cpu;
		if (m_Gpu != NULL)
			delete m_Gpu;
		if (m_Memory != NULL)
			delete m_Memory;
	}

private:
	CPU* m_Cpu;
	GPU* m_Gpu;
	Memory* m_Memory;
};
