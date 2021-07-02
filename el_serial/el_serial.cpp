#include "el_serial.h"

USBSERIAL::USBSERIAL(std::string portname)
{
    #ifdef _WIN32

    usbCom = CreateFileA(
        portname.c_str(),               //Port Name
        GENERIC_READ | GENERIC_WRITE,   //Read/Write
        0,                              //No Sharing
        NULL,                           //No Security
        OPEN_EXISTING,                  //Open Existing Port Only
        0,                              //Non Overlapped I/O
        NULL                            //Null for Comm Devices
    );
    if(usbCom == INVALID_HANDLE_VALUE) std::cout << "Error in opening serial port" << std::endl;
    else std::cout << "Opening serial port successful" << std::endl;

    #elif __linux__
    #error There is not support for class constructor for now.
    #endif
}


void USBSERIAL::PortClose()
{
    #ifdef _WIN32
    CloseHandle(usbCom);

    #elif __linux__
    #error There is not support for linux PortClose() for now.

    #endif
}

bool USBSERIAL::WriteToPort(const void* bytes, int num)
{
    #ifdef _WIN32
    unsigned long written_bytes = 0;
    bool Status = WriteFile(
        usbCom,                 // Handle to the Serial port
        bytes,                  // Data to be written to the port
        num,                    //No of bytes to write
        &written_bytes,         //Bytes written
        NULL
    );
    std::cout << "Written Bytes : " << written_bytes << std::endl;
    
    return Status;

    #elif __linux__
    #error There is not support for linux WriteToPort() for now. 

    #endif
}