#include <iostream>
#include <windows.h>

int main()
{
    NTSTATUS(WINAPI * RtlGetVersion)(LPOSVERSIONINFOEXW);
    OSVERSIONINFOEXW osInfo;

    *(FARPROC*)&RtlGetVersion = GetProcAddress(GetModuleHandleA("ntdll"), "RtlGetVersion");

    if (NULL != RtlGetVersion)
    {
        osInfo.dwOSVersionInfoSize = sizeof(osInfo);
        RtlGetVersion(&osInfo);
    }

    std::cout << "Operating System: Windows ";

    if (osInfo.dwMajorVersion == 10 && osInfo.dwMinorVersion == 0)
        std::cout << "10 ";
    if (osInfo.dwMajorVersion == 6 && osInfo.dwMinorVersion == 3)
        std::cout << "8.1 ";
    if (osInfo.dwMajorVersion == 6 && osInfo.dwMinorVersion == 2)
        std::cout << "8 ";
    if (osInfo.dwMajorVersion == 6 && osInfo.dwMinorVersion == 1)
        std::cout << "7 ";
    if (osInfo.dwMajorVersion == 6 && osInfo.dwMinorVersion == 0)
        std::cout << "Vista ";
    if (osInfo.dwMajorVersion == 5 && osInfo.dwMinorVersion == 1)
        std::cout << "XP ";
    if (osInfo.dwMajorVersion == 5 && osInfo.dwMinorVersion == 0)
        std::cout << "2000 ";


    SYSTEM_INFO Inf;
    GetNativeSystemInfo(&Inf);
    if (Inf.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_INTEL)
        std::cout << "x32 ";
    else
        std::cout << "x64 ";


    std::cout << "(Build " << osInfo.dwBuildNumber << "), ";


    std::cout << "Service Pack " << osInfo.wServicePackMajor << "." << osInfo.wServicePackMinor;

    return 0;
}
