#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>

using namespace std;

class Fecha
{
	public:
		string aaaa;
		string mm;
		string dd;
	Fecha(string a, string m, string d)
	{
		aaaa = a;
		mm = m;
		dd = d;
	}
	Fecha()
	{
		aaaa = "";
		mm = "";
		dd = "";
	}
	public:
		void imprimirFecha();
};
bool formato(string &fecha)
{
	if(fecha.length() < 10) return false;
	if( !(fecha[4] == '/' && fecha[7] == '/')) return false;
	for(int i = 0; i < 10; i++)
	{
		if(i == 4 || i == 7) continue;
		if(fecha[i] < '0' || fecha[i] > '9') return false;
	}
	return true;
}

int toNum(string a)
{
	int sum = 0;
	for(int i = 0; i < a.length(); i++)
	{
		sum += ((a[i]-'0')*pow(10,a.length()-i-1));
	}
	return sum;
}
bool fechaValida(Fecha &f1)
{
	int aaaa = toNum(f1.aaaa);
	int mm = toNum(f1.mm);
	int dd = toNum(f1.dd);

	//if(aaaa < 0 || aaaa > 2017) return false;
	if(mm < 0 || mm > 12) return false;
	if(dd < 0 || dd > 31) return false;
	return true;
}
string leerFecha()
{
	string fecha = "";
	cout << "Ingresa una  fecha" << endl;
	cin >> fecha;

	while(fecha.length() != 10 )
	{
		cout << "Fecha no valida\n Ingrese el formato aaaa/mm/dd" << endl;
		cin >> fecha;

		if(!formato(fecha)) fecha = "";
	}
	return fecha;
}

class Persona
{
	public:
		int id_cliente;
		string nombre;
		string ap_paterno;
		string ap_materno;
		Fecha fecha_alta;
		int credito;
		int deuda;

	Persona()
	{
		fecha_alta = Fecha();
	}
	public:
		bool find(vector <Persona> datos,int id)
		{
			for(int i = 0; i < datos.size(); i++)
				if(datos[i].id_cliente == id) return true;
			return false;

		}
		void registrar(vector <Persona> &datos)
		{	
			do{
				cout << "Ingresa un id de cliente nuevo" << '\n';
				cin >> id_cliente;
			}while(find(datos,id_cliente));

			cout << "Ingresa un nombre" << '\n';
			cin.get();
			getline(cin,nombre);//cin >> nombre;


			cout << "Ingresa appellido paterno" << '\n';
			cin >> ap_paterno;

			cout << "Ingresa apellido materno" << '\n';
			cin >> ap_materno;

			cout << "Ingresa una fecha en el formato aaaa/mm/dd" << '\n';

			do
			{
				string fecha = leerFecha();

				fecha_alta.aaaa = fecha.substr(0,4);
				fecha_alta.mm = fecha.substr(5,2);
				fecha_alta.dd = fecha.substr(8,2);

				if(!fechaValida(fecha_alta))
				{
					cout << "Fecha fuera de rango, Ingresa nuevamente" << endl;
				} else break;	
			}while(true);
			
		
			do
			{
				cout << "Ingresa la cantidad de credito positivo" << '\n';
				cin >> credito;
			}while(credito < 0);
			do{
				cout << "Ingresa la deuda positiva" << '\n';
				cin >> deuda;
			}while(deuda < 0);
		}

		void mostrarDatos()
		{
			cout << "Id cliente: " << id_cliente << '\n';
			cout << "Nombre: " << nombre << endl;
			cout << "Apellido Paterno: " << ap_paterno<< '\n';
			cout << "Apellido materno: " << ap_materno << '\n';
			cout << fecha_alta.aaaa << "/" << fecha_alta.mm << "/" << fecha_alta.dd << '\n';
			cout << credito << '\n';
			cout << deuda << '\n';
			cout << "--------------------------------------------------------------" << endl;
		}
};	

class Archivo
{
	string nombre;
	string ruta;
	public:
		vector <Persona> datos;
	public:
		Archivo(string nom, string rut)
		{
			nombre = nom;
			rut = ruta;
		}

	vector <Persona> getDatos() { return datos;}

	void mostrarRegistro(int id)
	{
		int cont = 0;
		for(int i = 0; i < datos.size(); i++)
			if(datos[i].id_cliente == id){
				datos[i].mostrarDatos(), cont++;
				break;
			}

		if(cont == 0) cout << "----------Registro no encontrado----------" << endl;
	}
	void mostrarRegistro(string nombre)
	{
		int cont = 0;
		for(int i = 0; i < datos.size(); i++)
			if(datos[i].nombre == nombre)
				datos[i].mostrarDatos(), cont++;
		if(cont == 0) cout << "----------Registro no encontrado----------" << endl;

	}
	void update(Persona persona)
	{
		datos.push_back(persona);
	}
	void cargarDatos()
	{
		//set <Persona>::iterator it;
		Persona aux;

		ifstream fin;
		fin.open(nombre.c_str());
		while(fin >> aux.id_cliente)
		{
			fin.get();
			getline(fin,aux.nombre);//fin >> aux.nombre;
			fin >> aux.ap_paterno;

			fin >> aux.ap_materno;

			fin >> aux.fecha_alta.aaaa;
			fin >> aux.fecha_alta.mm;
			fin >> aux.fecha_alta.dd;
			fin >> aux.credito;
			fin >> aux.deuda;

			datos.push_back(aux);
		}
		fin.close();
	}
	void eliminar(int id)
	{
		vector <Persona> datos2;
		for(int i = 0; i < datos.size(); i++)
		{
			if(datos[i].id_cliente == id) continue;
			datos2.push_back(datos[i]);
		}
		datos.resize(0);
		ofstream fout;
		fout.open (nombre.c_str(),  ios::trunc);
		fout.close();
		for(int i = 0; i < datos2.size(); i++)
		{
			guardarDatos(datos2[i]);
			datos.push_back(datos2[i]);
		}
		datos2.resize(0);
		cout << "Registro eliminado satisfactoriamente---" << endl;
	}
	void guardarDatos(Persona persona)
	{
		ofstream fout;
		cargarDatos();
		fout.open (nombre.c_str(),  ios::app);

		fout << persona.id_cliente << '\n' << persona.nombre << '\n' << persona.ap_paterno << '\n'
		 << persona.ap_materno << '\n' << persona.fecha_alta.aaaa << '\n'
		  << persona.fecha_alta.mm << '\n' << persona.fecha_alta.dd << '\n';
		fout << persona.credito << '\n' << persona.deuda << '\n';
		fout.close();
	}
};


inline void Fecha::imprimirFecha()
{
	cout << aaaa << "/" << mm << "/" << dd << '\n';
}

void menu()
{
	Archivo archivo1 = Archivo("data.txt","");
	archivo1.cargarDatos();

	vector <Persona> personas = archivo1.getDatos();
	Persona p1;
	
	int op;
	do {
		
		cout << "--------------REGISTROS-----------" << '\n';
		cout << "Opciones:\n \n1)Agregar\n2)Modificar\n3)Borrar\n4)Mostrar" << '\n';
		cout << "5)salir" << '\n';
		cin >> op;
		switch(op)
		{	
			case 1:
				p1.registrar(archivo1.datos);
				archivo1.guardarDatos(p1);
				personas.push_back(p1);
				archivo1.update(p1);
			break;
			case 3:
				int id_borrar;

				cout << "Ingrese un id a eliminar" << endl;
				cin >> id_borrar;

				archivo1.eliminar(id_borrar);

			break;
			case 4:
				cout << "DATOS" << endl;
				int mult;
				do
				{
					cout << "Seleccione una opcion:\n 1)Mostrar todos los datos\n 2)Mostrar por id\n 3)Mostrar por nombre" << endl;
					cout << "4) Salir " << endl;
					cin >> mult;
					switch(mult)
					{
						case 1:
							personas = archivo1.getDatos();	
							for(int i = 0; i < personas.size(); i++)
								personas[i].mostrarDatos();	
						break;

						case 2:
							int id;
							cout << "Ingrese ID  a buscar" << endl;
							cin >> id;
							archivo1.mostrarRegistro(id);
						break;
						case 3:
							string nombre;
							cout << "Ingrese nombre  a buscar" << endl;
							cin >> nombre;
							archivo1.mostrarRegistro(nombre);

						break;
					}
					
				}while(mult == 1 || mult == 2 || mult == 3);
			break;
		}


	}while(op != 5);
}
int main()
{
	menu();

	return 0;
}