//Public libs
#include <iostream>
#include <string>

#ifdef  _WIN32
#include <windows.h>
#elif __linux__
#error There is not support for linux libraries for now.
#endif

typedef unsigned char El_Byte;

class USBSERIAL
{
    private:
    #ifdef _WIN32
    static HANDLE usbCom;
    #elif __linux__
    #endif


    public:
    USBSERIAL(std::string portname);

    void PortClose();

    bool WriteToPort(const void* bytes, int num);
};