#include<iostream>
#include<signal.h>
#include<unistd.h>


using namespace std;
void registerHandler;
void signalHandler;
bool wait=true;
main()
{
	cout<< "Moj pid:"<< getpid()<<endl;
	registerHandler();
	while(wait)
	{
		pause();
	}
	
	
}
