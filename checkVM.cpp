#include <iostream>
#include "checkVM.h"


bool checkVM::isVM()
{
	int isVM{};					// initialize isVM to zero
    
	__asm
	{
		xor		eax, eax		// clear out EAX and ECX registers
		xor		ecx, ecx
		inc		eax
		cpuid
		bt		ecx, 0x1f		// bit test of 31st bit in ECX (hypervisor bit)
		setc		isVM			
	}

    return inVM;
}

void checkVM::get_vendorID(std::string& vendor)
{
    int registers[4] = { 0 };

    __cpuid(&registers[0], 0x40000000);     // set function_id (EAX) to 0x40000000, which populates Vendor ID into EBX, ECX, EDX 

    vendor = std::string((const char*)&registers, 16);
}
