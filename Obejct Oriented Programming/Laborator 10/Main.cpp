#include <iostream>
#include"SingletonSemaphore.h"

using namespace std;

int main()
{
	thread t1 = thread(task1);

	thread t2 = thread(task2);

	thread t3 = thread(task3);

	t1.join();

	t2.join();

	t3.join();

	return 0;
}