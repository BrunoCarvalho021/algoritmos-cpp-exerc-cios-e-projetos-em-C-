#include <iostream>
#include <windows.h>
#include <ctime>
#include <cstdlib>
using namespace std;

struct Nodo
{
    string paciente;
    int numero;
    Nodo *siguiente;
};

bool colavacia(Nodo*);
void cargarcola(Nodo *&, Nodo *&, string, int);
void quitarcola(Nodo *&, Nodo *&, string &, int &);
int nrepitidos(bool usados[]);

int main(){
    srand(time(0));
    bool usados[1000] = {false};
    char op;
    int n;
    string nombre;
    Nodo *frente = NULL;
    Nodo *fin = NULL;
    do
    {
        cout<<"Ingrese el nombre del paciente:"<<endl;
        cin>>nombre;
        n = nrepitidos(usados);
        cout<<"El ticket del paciente es:"<<n<<endl;

        cargarcola(frente, fin, nombre, n);
        

        cout<<"Desea agregar mas paciente? (s/n):"<<endl;
        cin>>op;
    } while(op == 's' || op == 'S');
    system("pause");
    system("cls");
    cout<<"== Paciente Registrado =="<<endl;
    while (!colavacia(frente))
    {
        quitarcola(frente, fin, nombre, n);
        cout<<"Paciente: "<<nombre<< " Ticket N - "<<n<<endl;
        
    }
    return 0;
}

bool colavacia(Nodo*frente){
    if (frente == NULL)
    {
        return true;
    }else
    {
        return false;
    }
}

void cargarcola(Nodo *&frente, Nodo *&fin, string nombre, int n){
    Nodo *nodo = new Nodo();
    nodo->paciente = nombre;
    nodo->numero = n;
    nodo->siguiente = NULL;
    if (frente == NULL)
    {
        frente = nodo;
    }else
    {
        fin->siguiente = nodo;
    }
    fin = nodo;
    cout<<"El paciente "<<nombre<<" con el ticket "<<n<<" se encargo correctamente."<<endl;
}

void quitarcola(Nodo *&frente, Nodo *&fin, string &nombre, int &n){
    Nodo *aux = frente;
    nombre = aux->paciente;
    n = aux->numero;
    if (frente == fin)
    {
        frente = NULL;
        fin = NULL;
    }else
    {
        frente = aux->siguiente;
    }
    delete aux;
}

int nrepitidos(bool usados[]){
    int n;
    do
    {
        n = rand() % 1000;
        
    } while(usados[n]);
    usados[n] = true;
    return n;
}