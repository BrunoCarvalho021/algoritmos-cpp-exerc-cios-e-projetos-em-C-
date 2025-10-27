#include <iostream>
#include <windows.h>
using namespace std;

struct Nodo
{
    int dato;
    Nodo *siguiente;
};

bool colavacia(Nodo *);
void cargarcola(Nodo *&, Nodo*&, int);
void quitarcola(Nodo *&, Nodo *&, int &);

int main(){
    char op;
    int n;
    Nodo *frente = NULL;
    Nodo *fin = NULL;

    Nodo *frentepar = NULL;
    Nodo *finpar = NULL;

    Nodo *frenteimpar = NULL;
    Nodo *finimpar = NULL;

    do
    {
        cout<<"Ingrese un numero:"<<endl;
        cin>>n;
        cargarcola(frente, fin, n);
        cout<<"Desea agregar mas ? (s/n):"<<endl;
        cin>>op;
    } while(op == 's' || op =='S');

    while (!colavacia(frente))
    {
        quitarcola(frente, fin, n);
        if (n %2 == 0)
        {
            cargarcola(frentepar, finpar, n);
        }else
        {
            cargarcola(frenteimpar, finimpar, n);
        }
    }
    system("cls");

    cout<<"\nLos numeros pares:"<<endl;
    while (!colavacia(frentepar))
    {
        quitarcola(frentepar, finpar, n);
        cout<<n<<"  ";
    }

    cout<<"\nLos numeros impares:"<<endl;
    while (!colavacia(frenteimpar))
    {
        quitarcola(frenteimpar, finimpar, n);
        cout<<n<<"  ";
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

void cargarcola(Nodo *&frente, Nodo*&fin, int n){
    Nodo *nodo = new Nodo();
    nodo->dato = n;
    nodo->siguiente = NULL;
    if (frente == NULL)
    {
        frente = nodo;
    }else
    {
        fin->siguiente = nodo;
    }
    fin = nodo;
    cout<<"El numero "<<n<<" se encargo correctamente."<<endl;
}

void quitarcola(Nodo *&frente, Nodo *&fin, int &n){
    Nodo *aux = frente;
    n = aux->dato;
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