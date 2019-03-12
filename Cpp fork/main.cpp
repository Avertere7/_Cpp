#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include "funkcje.h"

using namespace std;
int i=0;
int chpid;
int ppid;
string nazwa;
void registerHandler();
void signalHandler(int);
void signal_int(int);

typedef void(*wsk)(int,*wsk);

int main(int argc, char* argv[])
{
	nazwa=argv[1];
	iloscarg(argc);
	if(argv[]=NULL)
	{
		cout<<"Nie podano argumentu bład:0"<<endl;
		exit(0);
	}
	else if(access(argv[1], F_OK) !=-1)
	{
		ifstream plik;
		pid_t pid=fork();
		int status=0;
		if(pid==0)
		{
			chpid=getpid();
			ppid=getppid();
			printf("Moj pid to %d, pid mojego rodzica to %d \n",getpid(),getppid());
			rozmiarpliku(argv[1]);
			registerHandler();
		}
		else if(pid>0)
		{
			signal(SIGINT,signal_int);
		}
		wait(&status);
	}
	else
	{
		cout<<"Plik nie istnieje bład:1"<<endl;
		exit(0);
	}
return 0;
}
void signalHandler(int s)
{
	if(i==0)
	{
	cout<<"Przechwycono sygnal USR1"<<endl;
	cout<<"Nazwa pliku"<<nazwapliku(nazwa)<<endl;
	i++;
	}
	else
	{
		cout<<"Dlugosc pliku"<<rozmiarpliku(nazwa)<<endl;
		kill(ppid,SIGINT);
	}
}
void registerHandler()
{
		sigset_t iset;
        struct sigaction act;
        sigemptyset(&iset);
        act.sa_handler=&signalHandler;
        act.sa_mask=iset;
        act.sa_flags= 0;
        sigaction(SIGUSR1,&act,NULL);
}
void signal_int(int nr)
{
	kill(chpid,SIGINT);
}
