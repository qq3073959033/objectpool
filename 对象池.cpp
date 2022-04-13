#include <chrono>
#include <iostream>
#include <thread>
// #include "memorymanager.h"
#include "objectpool.h"
using namespace std;
class A : public ObjectPoolBase<class A,2000>
{
public:
public:
	int a[3];
};

class B : public ObjectPoolBase<class B, 2000>
{
public:
public:	
	int a[30];
};

void testFunc()
{
	A* parr[1000];
	B* pbrr[1000];
	for (int i = 0; i < 1000; ++i)
	{
 		parr[i] = new A;
		// pbrr[i] = new B;
	}
	for (int i = 0; i < 1000; ++i)
	{
		delete	parr[i];
		// delete pbrr[i];
	}
}

int main()
{
	/*thread th[4];
	for (int i = 0; i < 4; ++i)
	{
		th[i] = thread(testFunc);
	}
	for (int i = 0; i < 4; ++i)
	{
		th[i].join();
	}*/
	A* parr[2000];
	B* pbrr[2000];
	for (int i = 0; i < 2000; ++i)
	{
		parr[i] = new A;
		pbrr[i] = new B;
	}
	for (int i = 0; i < 2000; ++i)
	{
		delete parr[i];
		delete pbrr[i];
	}
	// this_thread::sleep_for(std::chrono::seconds(10000));
}
