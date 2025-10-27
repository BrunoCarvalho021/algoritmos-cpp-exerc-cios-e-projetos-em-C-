#include <iostream>
#include <windows.h>
using namespace std;

struct Nodo{
    string alumno;
    int nota;
    Nodo *siguiente;
};

bool colavacia(Nodo *);
void cargarcola(Nodo *&, Nodo *&, string, int);
void quitarcola(Nodo *&, Nodo *&, string &, int &);

int main(){
    int n;
    char op;
    string nombre;
    Nodo *frente = NULL;
    Nodo *fin = NULL;
    cout<<"Cargar alumnos y notas:"<<endl;
    do
    {
        cout<<"Ingrese un alumno:"<<endl;
        cin>>nombre;
        cout<<"Ingrese la nota del alumno:"<<endl;
        cin>>n;
        cargarcola(frente, fin, nombre, n);

        cout<<"Desea agregar mas alumnos y notas? (s/n):"<<endl;
        cin>>op;
    } while(op == 's' || op == 'S');

    while (!colavacia(frente))
    {
        quitarcola(frente, fin, nombre, n);
        if (n < 6)
        {
            cout<<"-------------------------------"<<endl;
            cout<<"Alumno "<<nombre<<" nota "<<n<<" - REPROVADO"<<endl;
            cout<<"-------------------------------"<<endl;
        }else
        {
            cout<<"-------------------------------"<<endl;
            cout<<"Alumno "<<nombre<<" nota "<<n<<" - APROVADO"<<endl;
            cout<<"-------------------------------"<<endl;
        }
        
    }
    return 0;
}

bool colavacia(Nodo *frente){
    if (frente == NULL)
    {
        return true;
    }else
    {
        return false;
    }
}

void cargarcola(Nodo *&frente, Nodo *&fin, string nombre, int n){
    Nodo *n_nodo = new Nodo();
    n_nodo->alumno = nombre;
    n_nodo->nota = n;
    n_nodo->siguiente = NULL;
    if (frente == NULL)
    {
        frente = n_nodo;
    }else
    {
        fin->siguiente = n_nodo;
    }
    fin = n_nodo;
    cout<<"El alumno "<<nombre<<" con la nota "<<n<<" se encargo correctamente."<<endl;
} 

void quitarcola(Nodo *&frente, Nodo *&fin, string &nombre, int &n){
    Nodo *aux = frente;
    nombre = aux->alumno;
    n = aux->nota;
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



