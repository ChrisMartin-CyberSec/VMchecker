#include <iostream>
#include "checkVM.h"


int main()
{
    checkVM CPU;

    if (CPU.isVM())
    {
        std::string MicrosoftHV = "@Microsoft Hv";              // Microsoft Hypervisor triggers the ECX 31st bit on CPUID function ID 1
        CPU.get_vendorID(CPU.vendorID);

        if (CPU.vendorID.find("Microsoft") != std::string::npos)
        {
            std::cout << "[+] NOT IN A VM: " << CPU.vendorID << std::endl;
            return 0;
        }
    }

    std::cout << "[!] VM DETECTED: " << std::endl << CPU.vendorID << std::endl;

    return 0;
};
