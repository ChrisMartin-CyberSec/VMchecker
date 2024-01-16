# VMchecker

### Checks if your process is running inside of a Virtual Machine.


> - [CPUID](https://learn.microsoft.com/en-us/cpp/intrinsics/cpuid-cpuidex?view=msvc-170) invocation is a common tactic used by malware developers to determine if their malware is being executed inside of a Virtual Machine.

> - The `__cpuid` function utilizes the value in `EAX` as its function ID and returns data in the `EAX`, `EBX`, `ECX`, and `EDX` registers.

> - For a listing of CPUID leaves, see the [Microsoft Documentation](https://learn.microsoft.com/en-us/virtualization/hyper-v-on-windows/tlfs/feature-discovery).



**Note:** Microsoft Hypervisor sets the 31st bit of the `ECX` register for the `__cpuid` functionID of 1 as "set". The [Microsoft Documentation](https://learn.microsoft.com/en-us/virtualization/hyper-v-on-windows/about/) states that `...with virtualization enabled, the host OS also runs on top of the Hyper-V virtualization layer, just as guest operating systems do.`

>**ECX 31st bit set on CPUID call with EAX=1 on Windows host machine**
(![image](https://github.com/ChrisMartin-CyberSec/VMchecker/assets/111389653/64514bc9-f87a-405b-8acd-c8788a838dc3)



>**ECX 31st bit set on CPUID call with EAX=1 on Windows guest machine (*VirtualBox*)**
![image](https://github.com/ChrisMartin-CyberSec/VMchecker/assets/111389653/c218ede4-e67b-4a6a-9b50-ac5cdcd81d96)

