#include <iostream>
#include <windows.h>

#define LEN 10

using namespace std;

DWORD WINAPI producer(PVOID param);
DWORD WINAPI consumer(PVOID param);

int buffer[LEN], in = 0, out = 0;
int productID = 0, ConsumeID = 0;
bool goContinue = true;

HANDLE mutex;
HANDLE full;
HANDLE empty;

void produce();
void consume();
void append();
void output();

int producer_consumer_main(){
	mutex = CreateMutex(NULL, FALSE, NULL);
	full = CreateSemaphore(NULL, 0, LEN , NULL);
	empty = CreateSemaphore(NULL, LEN, LEN, NULL);

	HANDLE hPro = CreateThread(NULL, 0, producer, NULL, 0, NULL); //生产者
	HANDLE hCom = CreateThread(NULL, 0, consumer, NULL, 0, NULL); //消费者

	while (goContinue){
		if (getchar()){
			goContinue = false;
		}
	}

	CloseHandle(hPro);
	CloseHandle(hCom);

	CloseHandle(mutex);
	CloseHandle(full);
	CloseHandle(empty);

	return 0;
}

DWORD WINAPI producer(PVOID param){
	while (goContinue){
		produce();
		WaitForSingleObject(empty,INFINITE);
		WaitForSingleObject(mutex, INFINITE);
		append();
		Sleep(1500);
		ReleaseMutex(mutex);
		ReleaseSemaphore(full, 1, NULL);
	}
	return 0;
}

DWORD WINAPI consumer(PVOID param){
	while (goContinue){
		WaitForSingleObject(full, INFINITE);
		WaitForSingleObject(mutex, INFINITE);
		output();
		Sleep(1500);
		ReleaseMutex(mutex);
		ReleaseSemaphore(empty, 1, NULL);
		consume();
	}
	return 0;
}

void produce(){
	cout << "Producing " << ++productID << endl;
}

void append(){
	cout << "Write in Buffer " << in;
	buffer[in] = productID;
	cout << " with " << productID << endl;
	in = (in + 1) % LEN;
}

void output(){
	ConsumeID = buffer[out];
	cout << "Read from Buffer " << out << " is " << ConsumeID << endl;
	out = (out + 1) % LEN;
}

void consume(){
	cout << "Consuming " << ConsumeID << endl;
}