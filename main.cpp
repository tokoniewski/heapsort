/* 
 * File:   main.cpp
 * Author: admin
 *
 * Created on 27 wrzesień 2019, 20:41
 */

//#include <cstdlib>
#include <iostream>
#include <stdlib.h>

#define LOGMAKEHEAP 0
#define LOGSORTHEAP 0
#define LOGDATAPRINT 1

using namespace std;

std::ostream& bold_on(std::ostream& os)
{
    return os << "\e[1m";
}

std::ostream& bold_off(std::ostream& os)
{
    return os << "\e[0m";
}

const int DATASIZE = 7;
int mydata[DATASIZE];

void printdata(int heapborder = 0)
{       
    if (LOGDATAPRINT == 0)
        return;
	for (int i = 0; i < DATASIZE; i++)
	{
		if (i == heapborder)
			cout << bold_on << "| " << bold_off;
		cout << mydata[i] << " ";
	}
	cout << "\n";
}

void inline swap(int* top, int* bot)
{
	int tmp = *top;
	*top = *bot;
	*bot = tmp;
}

int main()
{
	cout << "| ";
	int tmp = 10;
	for (int i = 0; i < DATASIZE; i++)
	{
		//tmp += rand() % 5 + 1;
		//mydata[i] = tmp;
		tmp = rand() % (DATASIZE * 10) + 1;
		mydata[i] = tmp + 10;                
		cout << mydata[i] << " ";
	}
        cout << "\n";
	if (LOGMAKEHEAP) cout << "\e[1m MAKE HEAP \e[0m" << endl;
	for (int i = 1; i < DATASIZE; i++)
	{
		int bot = i + 1;
		int top = bot / 2;
		if (LOGMAKEHEAP) cout << bold_on << i << ") " << bold_off;
		do
		{
			if (LOGMAKEHEAP) cout << top << ":" << bot << ". ";
			if (mydata[bot - 1] > mydata[top - 1])
			{
				swap(mydata[bot - 1], mydata[top - 1]);
				if (LOGMAKEHEAP) cout << endl;
				printdata();
			}
			else
				break;
			bot /= 2;
			top = bot / 2;
		} while (bot > 1);
		if (LOGMAKEHEAP) cout << endl;
	}
	if (LOGSORTHEAP) cout << "\e[1m SORT HEAP \e[0m" << endl;
	for (int i = DATASIZE - 1; i > 1; i--)
	{
		swap(mydata[i], mydata[0]);
		if (LOGSORTHEAP) cout << bold_on << i << ")  -------------------------" << bold_off << endl;
		printdata(i);
		int bot = 1 + 1;
		int top = bot / 2;
		if (LOGSORTHEAP) cout << i << ") ";
		while (bot < i)
		{
			if (LOGSORTHEAP) cout << top << ":" << bot << ". ";
			if (mydata[bot - 1] >= mydata[bot])
			{
				if (mydata[bot - 1] > mydata[top - 1])
				{
					swap(mydata[bot - 1], mydata[top - 1]);
					if (LOGSORTHEAP) cout << endl;
					printdata(i);
				}
			}
			else
			{

					if (mydata[bot] > mydata[top - 1])
					{
						swap(mydata[bot], mydata[top - 1]);
						if (LOGSORTHEAP) cout << endl;
						bot++;
						printdata(i);
					}
					else
						break;
			}
			top = bot;
			bot *= 2;
		} 
		if (LOGSORTHEAP) cout << endl;
	}
        if (mydata[0] > mydata[1])
                swap(mydata[1], mydata[0]);
	printdata(0);
	if (LOGSORTHEAP) cout << endl;
        return 0;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

