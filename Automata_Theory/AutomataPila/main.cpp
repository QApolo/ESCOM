#include <bits/stdc++.h>

using namespace std;

#define EPS '&'
bool epsFound;
void inicio();

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

string S(char c)
{
	string cad;
	cad.push_back(c);
	return cad;
}

bool compare(Delta d1, Delta d2)
{
	return d1.y > d2.y;
}
class APila
{
	public:
		stack <char> pila;
		set <string> estados;
		set <char> alfabeto;
		set <string> alfabetoPila;
		vector <Salida> funcion;
		string q0;
		char z0;
		set <string> finales;

		string path;

	
	public:
		APila(set <string> _estados, set <char> _alfabeto, set <string> _alfabetoPila, vector <Salida> _funcion, string _q0,char _z0,set <string> _finales)
		{
			estados = _estados;
			alfabeto = _alfabeto;
			alfabetoPila = _alfabetoPila;
			funcion = _funcion;
			q0 = _q0;
			z0 = _z0;
			finales = _finales;
			path = "";
			pila.push(z0);
		}
		APila()
		{

		}

	vector <Delta> mapa(char a, string qi, char tope)
	{
		vector <Delta> deltas;
		Terna actual;

		vector <Delta> nuevo;

		for(int i = 0; i < funcion.size(); i++)
		{
			actual = funcion[i].terna;
			if(actual.q == qi)
			{
				//cout <<"       :"<< actual.q <<" " << actual.a << " "<<tope << endl; //mover
				if(actual.a == a || actual.a == EPS)
				{
					if(actual.a == EPS)
					{
						epsFound = true;
						for(int k = 0; k < funcion[i].salida.size(); k++)
							nuevo.push_back(funcion[i].salida[k]);
						//return funcion[i].salida;
					}
					if(tope == actual.X)
					{
						for(int k = 0; k < funcion[i].salida.size(); k++)
							nuevo.push_back(funcion[i].salida[k]);
						//return funcion[i].salida;
					}
				}
			}
		}
		return nuevo;
	}
	bool verificar(string cadena, int index, string qi, string camino, stack <char> copiaPila)
	{
		if(finales.find(qi) == finales.end() && index == cadena.size()) cout << "NO aceptada " << endl;
		stack <char> cppila;
		epsFound = false;
		if(index < cadena.length())
		cout <<index << " "<<"["<< cadena[index] << " "<< qi << " " << copiaPila.top() << endl;
		if(finales.find(qi) != finales.end()){
			cout << path << endl;
			exit(0);
			return true;
		}
		
		if(index < cadena.length()) 
		{
			path = camino;
			
			//salir;
			
			vector <Delta> delta1 = mapa(cadena[index],qi,copiaPila.top());
			sort(delta1.begin(), delta1.end(), compare);
			for(int j = 0; j < delta1.size(); j++)
			{
				cppila = copiaPila;
				if(!cppila.empty())
				{
					cppila.pop();

					for(int k = delta1[j].y.size()-1; k >= 0; k--)
					{
						if(delta1[j].y[k] == EPS) 
						{
							if(!cppila.empty()) cppila.pop();
						}
						else
							cppila.push(delta1[j].y[k]);
					}
				}
				if(epsFound){//si se encontró epsilon no se consume simbolo
					//cout << "eps" << endl;
					 verificar(cadena, index, delta1[j].q, camino+"["+S(cadena[index]), cppila);
					}
				else{
					//cout << "no eps" << endl;
					verificar(cadena, index+1, delta1[j].q, camino+"["+S(cadena[index+1]), cppila);
					
				}
			}
		}
		
		return false;
	}


};

void inicio()
{
	int Q, A, P, N, R, F, C;
	string cadena;
	set <string> estados;
	set <char> alfabeto;
	set <string> alfabetoPila;
	string q, elem;
	set <string> finales;
	char a;
	string q0;
	char z0;
	APila AP;

	vector <Salida> funcion;
	Salida elemS;

	cin >> Q;
	for(int i = 0; i < Q; i++)	
	{
		cin >> q;
	}

	cin >> A;
	for(int i = 0; i < A; i++)
	{
		cin >> a;
		cin.get();
		alfabeto.insert(a);
	}
	cin >> P;
	for(int i = 0; i < P; i++)
	{
		cin >> elem;
		alfabetoPila.insert(elem);
	}

	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> elemS.terna.q;
		cin >> elemS.terna.a;
		cin >> elemS.terna.X;

		//cout << "-> "<< elemS.terna.q <<" " << elemS.terna.a <<" " << elemS.terna.X << endl;
		cin >> R;
		for(int i = 0; i < R; i++)
		{
			Delta delta;
			cin >> delta.q;
			cin >> delta.y;
			elemS.salida.push_back(delta);
		}
		funcion.push_back(elemS);
	}
	cin >> q0;
	cin >> z0;
	cin >> F;
	for(int i = 0; i < F; i++)
	{
		cin >> elem;
		finales.insert(elem);
	}

	AP = APila(estados, alfabeto, alfabetoPila, funcion, q0, z0,finales);
	cin >> C;
	for(int i = 0; i < C; i++)
	{
		cin >> cadena;
		bool result = AP.verificar(cadena, 0, AP.q0,"", AP.pila);
		cout << cadena << endl;

		if(!result) cout << "No ";
		if(result)
		{	
			cout << "Aceptada" << endl;
			cout << AP.path << endl;
		}
		cout << endl;
	}
}
int main()
{
	inicio();
	return 0;
}