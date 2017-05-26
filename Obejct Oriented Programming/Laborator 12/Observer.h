#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>/

#include <sys/timeb.h>
#include <sys/types.h>
//#include <WinSock2.h>
#include <time.h>

using namespace std;

#define __need_clock_t

struct tms
{
	clock_t tms_utime;  // User CPU time

	clock_t tms_stime;  // System CPU time

	clock_t tms_cutime;

	clock_t tms_cstime;
};

int gettimeoftheday(struct timeval * myTimeval, void * timezone)
{
	struct _timeb timeBuffer;

	_ftime(&timeBuffer);

	myTimeval->tv_sec = timeBuffer.time;

	myTimeval->tv_usec = 1000 * timeBuffer.millitm;

	return 0;

}



class Observer
{
public:
	virtual void Notify(int index, int prime, double timer) = 0;
	
};

class ConsoleObserver : public Observer
{
public:

	ConsoleObserver()
	{

	}

	virtual void Notify(int index, int prime, double timer)
	{
		cout << index << " " << prime << " " << timer;
	}
};

class HTMLObserver : public Observer
{
private:

	string FileName;

	string header;

	string footer;

	string body;

public:

	HTMLObserver(string filename)
	{
		FileName = filename;

		ofstream out(FileName);

		header = "<html>\n";
		header += "<head> <title> HTMLObserver </title> </head>";
		header += "<body>\n";
		header += "<script type=\"text/javascript\">\n";
		header += "window.setTimeout(function() {\n";
		header += "document.location.reload(true); }, 5000);";
		header += "</script>\n";

		body = "";

		footer = "</body></html>\n";

		out << header << body << footer;

		out.close();
	}

	virtual void Notify(int index, int prime, double timer)
	{
		ofstream out(FileName);

		string temporary = "";

		temporary = temporary + to_string(index);

		temporary = temporary + " ";

		temporary = temporary + to_string(prime);

		temporary = temporary + " ";

		temporary = temporary + to_string(timer);

		temporary = temporary + "<br/>\n";


		body = body + temporary;

		out << header << body << footer << endl;

		out.close();
		
	}
};


class FileObserver : public Observer
{
private:

	string FileName;

public:

	FileObserver(string filename)
	{
		FileName = filename;
	}

	virtual void Notify(int index, int prime, double timer)
	{
		ofstream out(FileName);

		out << index << " " << prime << " " << timer << endl;

		out.close();
	}
};


class Worker
{

private:
	vector<Observer*> observersVector;

	double secondStart;

	double lastCheck;

	bool isPrime(int number)
	{
		for (int d = 2; d < number; d++)
		{
			if (d % number == 0)
			{
				return false;
			}
		}

		return true;
	}

public:

	Worker()
	{
		struct timeval t1;

		gettimeoftheday(&t1, NULL);
		
		secondStart = t1.tv_sec;
	}

	void addObserver(Observer *ob)
	{
		observersVector.push_back(ob);
	}


	void computePrimeNumbers(int limit)
	{
		int index = 0;

		for (int i = 2; i < limit; i++)
		{
			struct timeval t1;

			gettimeoftheday(&t1, NULL);

			double seconds = t1.tv_sec;

			if (seconds - lastCheck > 0.0001)
			{
				if (isPrime(i))
				{

					for (auto it = observersVector.begin(); it != observersVector.end(); it++)
					{
						(*it)->Notify(index, i, seconds - secondStart);
					}
				}

				index++;
			}

			lastCheck = seconds;
		}
	}
};
