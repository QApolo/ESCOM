#include <bits/stdc++.h>
using namespace std;

int Max_level;
int nivel = 1;
unsigned long long bolas;
vector <int> pilas;

void iniciarSimulacion();

void leer_datos()
{
	cout << "Ingrese la cantidad de bolas" << endl;
	cin >> bolas;
	cout << "Ingrese maximo nivel" << endl;
	cin >> Max_level;
	pilas = vector <int>(Max_level+1,0);
}


void consumirBolas()
{
	srand(time(NULL));
	while(bolas)
	{
		iniciarSimulacion();
		bolas --;
	}
}
int formula(int n)
{
	return (n-1)*n/2 +1 ;
}
void iniciarSimulacion()
{
	int current_position = 1;
	nivel = 1;

	int left_corner = formula(nivel);
	
	while(nivel < Max_level)
	{
		int status = rand() % 2 + 1;
		if(status == 1) //mover izquierda
			current_position += nivel ;
		else //mover derecha;
			current_position += nivel + 1;
		nivel ++;
	}
	left_corner = formula(nivel);
	pilas[current_position - left_corner] ++;

}

void printPilas()
{
	for(int i = 0; i < pilas.size() -1 ; i++)
		cout << pilas[i] << " ";
	cout << endl;
	for(int i = 0; i < pilas.size() - 1; i++)
	{
		for(int j = 0; j < pilas[i]; j++)
			cout << "*";
		if(pilas[i] == 0) cout << "x";
		cout << endl;
	}
	cout << endl;
}

int main()
{

	leer_datos();
	consumirBolas();
	cout << "Pilas " << endl;
	printPilas();
	return 0;
}