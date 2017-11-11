#include <bits/stdc++.h>

using namespace std;

#define EPS '&'

struct Delta
{
	string q;
	string y;
};
typedef struct Delta Delta;
struct Terna
{
	string q;
	char a;
	char X;
};
typedef struct Terna Terna;

struct Salida
{	
	Terna terna;
	vector <Delta> salida;
};

typedef struct Salida Salida;
void inicio();
string S(char c);
bool compare(Delta d1, Delta d2);
void inicio();



