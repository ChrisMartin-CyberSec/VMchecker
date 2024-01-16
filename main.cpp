#include <iostream>
#include "checkVM.h"


int main()
{
    checkVM VM;

    if (VM.isVM())
    {
        std::string MicrosoftHV = "@Microsoft Hv";              // Microsoft Hypervisor triggers the ECX 31st bit on CPUID function ID 1
        VM.get_vendorID(VM.vendorID);

        if (VM.vendorID.find("Microsoft") != std::string::npos)
        {
            std::cout << "[+] NOT IN A VM: " << VM.vendorID << std::endl;
            return 0;
        }
    }

    std::cout << "[!] VM DETECTED: " << std::endl << VM.vendorID << std::endl;

    return 0;
};
