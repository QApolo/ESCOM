#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
#define ESP 5
 
struct Par
{
    string qi;
    char e;
};
typedef struct Par Par;
 
struct Terna
{
    string qj;
    char e;
    int dir;
};
typedef struct Terna Terna; 
ifstream fin;

class TuringMachine
{   
    public:
 
        vector <string> estados;
        vector <char> sigma;
        vector <char> tau;
        map <int,Terna> delta;
        string q0;
        char B;
        set <string> finales;
        map <int,Par> claves;

    public:
        void leerEstados(const int &Q)
        {
            estados = vector <string>(Q);
            for(int i = 0; i < Q; i++)
                fin >> estados[i];
        }
        void leerSigmaExclusivo(const int &SE)
        {   
            sigma = vector<char>(SE);
            char b;
            for(int i = 0; i < SE; i++)
                fin >> sigma[i];
        }
        void leerTau(const int &T)
        {
            tau = vector<char>(T);
            char b;
            for(int i = 0; i < T; i++)
                fin >> tau[i] ;
        }
        void leerEstadoInicial(){ fin >> q0; }
        void leerCaracterBlanco(){ fin >> B; }
        void leerEstadosFinales(const int &F)
        {
            string q;
            for(int i = 0; i < F; i++) 
            {
                 fin >> q;
                 finales.insert(q);
            }
        }
        void leerDelta(int S)
        {
            Par par1;
            Terna terna1;

            for(int i = 0; i < S; i++)
            {
                fin >> par1.qi;
                fin >> par1.e;

                fin >> terna1.qj;
                fin >> terna1.e;
                fin >> terna1.dir;

                delta[i] = terna1;
                claves[i] = par1;
            }
        }
        Terna search(Par entrada)
        {
            Par par1;
            Terna terna;
            map <int,Par>::iterator it;
            int j = 0;
            for(it = claves.begin(); it != claves.end(); it++ )
            {
                par1 = (it->second);
                if(par1.qi == entrada.qi && par1.e == entrada.e) return delta[j];
                j++;
            }
            terna.qj = "";
            terna.e = 32;
            terna.dir = -1;
            return terna;
        }
        void ejecutar(string &w, int index, string estado)
        {
            system("cls");
             
            cout << w << endl;
            for(int i = 0; i < index; i++)
                cout << " ";
            cout << estado << endl;
           _sleep(2000);
           
            if(finales.find(estado) != finales.end())
            {
                cout << "ACEPTADA" << endl;
                return;
            }

            if(index >= w.length() || index < 0) return;
            Par entrada;
            entrada.qi = estado;
            entrada.e = w[index];
            Terna aux = search(entrada);
            if(aux.qj == "" && aux.e == 32 && aux.dir == -1)
            {
                if(finales.size()) cout << "No ACEPTADA" << endl;
                return;
            }
            else
            {
                w[index] = aux.e;
                ejecutar(w, index + aux.dir, aux.qj);
            }
        }
};
void agregarBlanco(int s, string &w, char B)
{
    int j = 0;
    string w2;
    w2.resize(2*s+w.length());
    for(int i = 0; i < (2*s+w.length()); i++)
    {
        if(i < s || i >= s+w.length())
            w2[i] = B;
        else 
            if(j < w.length())
                w2[i] = w[j++];
    }
    w = w2;
    cout << w;
}

void inicio()
{
    string filename;

    cout << "Ingresa el nombre del archivo" << endl;
    cin >> filename;   
    fin.open (filename,ifstream::in);

    TuringMachine tm1;
    int Q, SE, T, S, F;

    fin >> Q;
    tm1.leerEstados(Q);
    fin >> SE;
    tm1.leerSigmaExclusivo(SE);
    fin >> T;
    tm1.leerTau(T);
    tm1.leerEstadoInicial();
    tm1.leerCaracterBlanco();

    fin >> F;
    tm1.leerEstadosFinales(F);

    fin >> S;
    tm1.leerDelta(S);

    int cant;
    string w;
    bool res;
    cout << "Ingresa la cantidad de cadenas a evaluar" << endl;
    cin >> cant;
    for(int i = 0; i < cant; i++){
        cout << "Ingresa una cadena" << endl;
        cin >> w;
        agregarBlanco(ESP,w,tm1.B);
        tm1.ejecutar(w,ESP,tm1.q0);
    }
    fin.close();
}
int main()
{
    inicio();
    return 0;
}