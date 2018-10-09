#include <bits/stdc++.h>

using namespace std;
vector <string> split(string s, char del)
{
	vector<string> splitted;

	string cur = "";
	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] != del)
			cur.push_back(s[i]);
		else
		{
			splitted.push_back(cur);
			cur = "";
		}
	}
	if(cur != "")
		splitted.push_back(cur);
	return splitted;
}


class Automata
{
	private:
		vector<string> Q;
		set<char> sigma;
		string q0;
		set<string> final;//vector<string> final;
		map<pair<string, char>, vector<string> > delta;
		vector <string> errores;
		string e_err = "e_err";

	public:
		vector <string> paths;
		bool valid;
		Automata(string nameFile)
		{
			ifstream fin (nameFile);
			string aux;
			fin >> aux;
			Q = split(aux, ',');

			fin >> aux;
			vector <string> sigma_vec;
			sigma_vec = split(aux,',');
			for(string s: sigma_vec)
				sigma.insert(s[0]);

			fin >> q0;

			fin >> aux;
			vector <string> final_vec;
			final_vec = split(aux, ',');
			for(string s: final_vec)
				final.insert(s);

			while(fin >> aux)
			{
				vector <string> trans = split(aux, ',');
				delta[make_pair(trans[0], trans[1][0])].push_back(trans[2]);
			}
			completarDelta();
			valid = false;
		}
		void completarDelta()
		{
			for(char s: sigma)
				delta[make_pair(e_err,s)].push_back(e_err);

			for(char s: sigma)
				for(string q: Q)
				{
					vector <string> estados = delta[make_pair(q,s)];
					if(estados.empty())
					{
						estados.push_back(e_err);
						delta[make_pair(q,s)] = estados;
					}
				}
		}
		void imprimirDelta()
		{
			map<pair<string, char>, vector<string> >::iterator it;
			for(it = delta.begin(); it != delta.end(); it++)
				for(string s: it->second)
					cout << "s(" << (it->first).first<<"," << (it->first).second << ") = " << s << endl;
		}
		void ejecutar(string cad)
		{
			ejecutar(cad, q0, 0,"","");
		}
		void ejecutar(string cad, string cur_s, int pos, string path,string error)
		{
			while(pos < cad.length() && sigma.find(cad[pos]) == sigma.end())
			{
				string aux;
				aux.push_back(cad[pos]);
				error += cur_s + "("+	aux + ") ";
				pos++;
			} 
			if(pos >= cad.length())
			{	
				if(final.find(cur_s) != final.end())
				{
					path += cur_s+"( )";
					paths.push_back(path);
					errores.push_back(error);
					valid = true;
					return;
				}
				
			}
			for(string s:delta[make_pair(cur_s,cad[pos])])
			{
				/*
				if(s == e_err && cur_s != s)
				{
					string aux;
					aux.push_back(cad[pos]);//errores.push_back("("+cur_s+","+aux+")="+e_err);
				}*/
				string ns;
				ns.push_back(cad[pos]);
				ejecutar(cad,s, pos + 1, path + cur_s +"("+ns+")" + "->",error);
			}
		}
		void imprimirErrores()
		{
			for(string err: errores)
				cout << err << endl;
		}
};

int main(int argc, char const *argv[])
{
	Automata auto1("input.txt");
	string cadena = "aaab*";
	cin >> cadena;

	auto1.imprimirDelta();
	cout << endl;

	auto1.ejecutar(cadena);//auto1.ejecutar(cadena, auto1.getInitialState(), 0,"","");
	cout << endl;
	if(!auto1.valid) cout << "NO ";
	cout <<"VALIDA: \n";
	for(string s: auto1.paths)//cout<< auto1.path << endl;
		cout << s << endl;
	cout << '\n'<< "ERRORES" << '\n';
	auto1.imprimirErrores();
	return 0;
}