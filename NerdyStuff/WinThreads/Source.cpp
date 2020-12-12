#include <windows.h>
#include <iostream>
#include <SerialPort.hpp>

const char* portName = "COM5";

//Declare a global object
SerialPort* arduino;

DWORD WINAPI thread_writer(LPVOID lpParameter)
{
	unsigned int& count = *((unsigned int*)lpParameter);
	unsigned int& exit_flag = *(((unsigned int*)lpParameter)+1);
	while (exit_flag != 1)
	{
		Sleep(1000);
		std::cout << "Writer: " << count <<'\n';
		char c = count + '0';
		arduino->writeSerialPort((char*)&c, 1);
	}
	std::cout << "Writer is dying...\n";
	return 0;
}

DWORD WINAPI thread_reader(LPVOID lpParameter)
{
	unsigned int& count = *((unsigned int*)lpParameter);
	unsigned int& exit_flag = *(((unsigned int*)lpParameter) + 1);
	char c;
	while (exit_flag != 1)
	{
		int res = arduino->readSerialPort(&c, 1);
		if (res != 0)
			std::cout << "Arduino: " << c << '\n';
	}
	std::cout << "Reader is dying...\n";
	return 0;
}

int main(int argc, char* argv[])
{
	//unsigned int myCounter = 0;
	arduino = new SerialPort(portName);
	if (!arduino->isConnected())
	{
		std::cout << "Failed to open serial port\n";
		return 1;
	}
	unsigned int params[2] = { 0, 0 };
	DWORD reader_id, writer_id;
	HANDLE handle_writer = CreateThread(0, 0, thread_writer, params, 0, &writer_id);
	HANDLE handle_reader = CreateThread(0, 0, thread_reader, params, 0, &reader_id);
	while (params[0] != 666) {
		std::cin >> params[0];
	}
	params[1] = 1;
	//while (WaitForSingleObject(handle_writer, 0) && WaitForSingleObject(handle_reader, 0));

	WaitForSingleObject(handle_writer, 5000);
	WaitForSingleObject(handle_reader, 5000);

	CloseHandle(handle_writer);
	CloseHandle(handle_reader);
	arduino->closeSerial();
	return 0;
}