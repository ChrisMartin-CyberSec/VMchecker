# VMchecker

### Checks if your process is running inside of a Virtual Machine.

[CPUID](https://learn.microsoft.com/en-us/cpp/intrinsics/cpuid-cpuidex?view=msvc-170) invocation is a common tactic used by malware developers to determine if their malware is being executed inside of a Virtual Machine.

The `__cpuid` function utilizes the value in `EAX` as its function ID and returns data in the `EAX`, `EBX`, `ECX`, and `EDX` registers.

For a listing of CPUID leaves, see the [Microsoft Documentation](https://learn.microsoft.com/en-us/virtualization/hyper-v-on-windows/tlfs/feature-discovery).

**Note:** Microsoft Hypervisor sets the 31st bit of the `ECX` register for the CPUID functionID of 1 as "set". 


