#include <iostream>
#include "checkVM.h"


bool checkVM::isVM()
{
    int inVM = 0;
    __asm
    {
        xor eax, eax        // clear out the registers
        xor ebx, ebx
        xor ecx, ecx
        xor edx, edx
        inc     eax         // set EAX to 1
        cpuid
        bt      ecx, 0x1f   // 31st bit of ECX is the "hypervisor present" bit
        jc      VMfound
        VMfound :
        mov     edx, 0x1
            mov     inVM, edx
            NopInstr :
        nop
    }

    return inVM;
}

void checkVM::get_vendorID(std::string& vendor)
{
    int registers[4] = { 0 };

    __cpuid(&registers[0], 0x40000000);     // set function_id (EAX) to 0x40000000, which populates Vendor ID into EBX, ECX, EDX 

    vendor = std::string((const char*)&registers, 16);
}
