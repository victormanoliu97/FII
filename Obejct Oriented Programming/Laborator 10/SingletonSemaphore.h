#include <iostream>
#include <thread>

using namespace std;

class SingletonSemaphore
{
private:
	static SingletonSemaphore* instance;

	static int count;

	static bool access;

	const static int treshold = 5;

	
public:
	static SingletonSemaphore* getInstance()
	{
		if (count == treshold)
		{
			return NULL;
		}

		if (instance == NULL)
		{
			instance = new SingletonSemaphore();
		}

		count++;

		return instance;
	}

	bool GetAcces() const
	{
		return access;
	}

	void toggle()
	{
		if (access == true)
		{
			access = true;
		}
		else
		{
			access = false;
		}
	}
};

int SingletonSemaphore::count = 0;
SingletonSemaphore* SingletonSemaphore::instance = NULL;
bool SingletonSemaphore::access = true;

void task1()
{
	SingletonSemaphore* semaphore = SingletonSemaphore::getInstance();

	if (semaphore == NULL)
	{
		return;
	}

	int writes = 5;

	while (writes > 0)
	{
		_sleep(rand() % 1000);

		while (!semaphore->GetAcces())
		{
			;
		}

		semaphore->toggle();

		cout << "culoare : rosie" << endl;
		semaphore->toggle();
		cout << endl;

		writes--;
	}
}


void task2()
{
	SingletonSemaphore* semaphore = SingletonSemaphore::getInstance();

	if (semaphore == NULL)
	{
		return;
	}

	int writes = 5;

	while (writes > 0)
	{
		_sleep(rand() % 1000);

		while (!semaphore->GetAcces())
		{
			;
		}

		semaphore->toggle();

		cout << "culoare : galbena" << endl;
		semaphore->toggle();
		cout << endl;

		writes--;
	}
}

void task3()
{
	SingletonSemaphore* semaphore = SingletonSemaphore::getInstance();

	if (semaphore == NULL)
	{
		return;
	}

	int writes = 5;

	while (writes > 0)
	{
		_sleep(rand() % 1000);

		while (!semaphore->GetAcces())
		{
			;
		}

		semaphore->toggle();

		cout << "culoare: verde" << endl;
		semaphore->toggle();
		cout << endl;

		writes--;
	}
}
