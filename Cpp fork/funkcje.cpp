#include "funkcje.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include "funkcje.h"



using namespace std;

int rozmiarpliku(char* arg)
{			
			ifstream plik;
			int dlugosc;
			plik.open(arg,ios::binary | ios::in);
			if(plik.good()==true)
			{
			plik.seekg(0,ios::end);
			dlugosc=plik.tellg();
			}
			cout<<"Dlugosc pliku:"<<dlugosc<<endl;
			return dlugosc;
}
void iloscarg(int nr)
{
	cout<<"liczba argumetow:"<<nr<<endl;
}
void nazwapliku(string nazwa)
{
	cout<<"Nazwa pliku:"<<nazwa<<endl;
}
