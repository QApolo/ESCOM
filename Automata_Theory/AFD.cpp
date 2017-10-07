#include <bits/stdc++.h>

using namespace std;

bool AFD(const string &S, int index, const set <string> &finales, string current_state, 
	map <string, map <char, string> > &transiciones);

void leerCadena(string &cad){ cin >> cad; }

void inicio(vector <char> &alfabeto, vector <string> &estados,
 string &q0,set <string> finales)
{
	string S, estado;
	char elem;
	map <string, map <char, string> > transiciones;

	for(int i = 0; i < estados.size(); i++)
	{
		string act_estado = estados[i];
		map <char, string> actual;
		for(int j = 0; j < alfabeto.size(); j++)
		{
			cin >> elem >> estado;
			actual[elem] = estado;	
		}	
		transiciones[act_estado] = actual;
	}

	cin >> S;
	bool res = AFD(S, 0, finales, q0, transiciones);
	cout << "res: " << res << endl;


}
bool AFD(const string &S, int index, const set <string> &finales, string current_state, 
	map <string, map <char, string> > &transiciones)
{
	if(current_state == "&") return false;
	if(index == S.length())
	{
		if(finales.find(current_state) == finales.end()) return false;
		else return true;
	}
	map <char, string> actual = transiciones[current_state];
	return AFD(S, index + 1, finales, actual[S[index]], transiciones);
}


void lectura()
{
	int A, Q;
	int i = 0;
	vector <char> alfabeto;
	vector <string> estados;
	string q0,S;

	cin >> A;
	alfabeto = vector <char>(A);
	while(cin >> alfabeto[i]&& i++ < A-1);

	cin >> Q;
	estados = vector <string>(Q);
	cin >> q0;

	string qfin = "";
	bool q0fin = false;
	for(i = 0; i < q0.length(); i++)
	{
		if(q0[i] != '*')
			qfin.push_back(q0[i]);
		else q0fin = true;
	}
	estados[0] = q0;

	set <string> finales;
	if(q0fin) finales.insert(qfin);
	for(i = 1; i < Q; i++)
	{
		cin >> estados[i];

		string final = "";
		bool found = false;
		for(int j = 0; j < estados[i].size(); j++)
		{
			if(estados[i][j] != '*')
				final.push_back(estados[i][j]);
			else found = true;
		}
		if(found)
		{
			finales.insert(final);
			estados[i] = final;
		}
	}

	inicio(alfabeto, estados, q0, finales);
}

int main()
{
	lectura();
	return 0;
}