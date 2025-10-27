#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Nodo
{
    int dato;
    Nodo *siguiente;
};

void cargarPILA(Nodo *&, int);
void quitarPILA(Nodo *&, int &);

int main(){
    srand(time(0));
    string op;
    bool usados[201] = {false};
    int valor = 200;
    Nodo *pila = NULL;
    for (int i = 0; i < 200;)
    {
        valor = rand() % 200 + 1;
        if (!usados[valor])
        {
            cargarPILA(pila, valor);
            usados[valor] = true;
            i++;
        }
    }
    system("pause");
    system("cls");

    cout<<"Los ganadores son:"<<endl;
    quitarPILA(pila, valor);
    cout<<"1er premio (iphone x): boleta: "<<valor<<endl;
    quitarPILA(pila, valor);
    cout<<"2er premio (PlayStation 4): boleta: "<<valor<<endl;
    quitarPILA(pila, valor);
    cout<<"3er premio (Pendrivre de 1TB): boleta: "<<valor<<endl;
    quitarPILA(pila, valor);
    cout<<"3er premio (Pulsera Mi band3): boleta: "<<valor<<endl;
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

