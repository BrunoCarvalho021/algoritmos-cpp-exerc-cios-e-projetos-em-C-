#include <iostream>
#include <windows.h>

using namespace std;

struct Nodo
{
    int dato;
    Nodo *siguiente;
};

void cargarPILA(Nodo *&, int);
void quitarPILA(Nodo *&, int &);

int main(){
    int n;
    cout<<"Ingrese el tamano del vector:"<<endl;
    cin>>n;
    int A[n];
    Nodo *pila = NULL;
    cout<<"Cargar vector:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<"Posicion ("<<i+1<<") -> "<<endl;
        cin>>A[i];
        cargarPILA(pila, A[i]);
    }

    cout<<"\nEl vector cargado es:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<A[i]<<"  ";
    }
    
    for (int i = 0; i < n; i++)
    {
        quitarPILA(pila, A[i]);
    }

    cout<<"\nEl vector invertido es:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<A[i]<<"  ";
    }
    
    return 0;
}

void cargarPILA(Nodo *&pila, int v){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = v;
    nuevo_nodo->siguiente = pila;
    pila = nuevo_nodo;
    cout<<"El valor" <<v<< "se cargo correctamente."<<endl;
}

void quitarPILA(Nodo *&pila, int &v){
    Nodo *aux = pila;
    v = aux->dato;
    pila = aux->siguiente;
    delete aux;
}

