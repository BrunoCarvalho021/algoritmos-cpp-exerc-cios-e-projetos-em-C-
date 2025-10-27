#include <iostream>
#include <windows.h>
#include <ctime>
#include <cstdlib>
using namespace std;

struct Nodo
{
    int dato;
    Nodo *siguiente;
};

bool colavacia(Nodo *);
void cargarcola(Nodo *&, Nodo *&, int );
void quitarcola(Nodo *&, Nodo *&, int &);

int main(){
    srand(time(0));
    int n;
    cout<<"ingrese el tamano de los vectores:"<<endl;
    cin>>n;
    int A[n];
    int B[n];
    int C[n];
    cout<<"Cargar el vector A:"<<endl;
    for (int i = 0; i < n; i++)
    {
        A[i] = rand () % 200;
    }
    cout<<"Cargar el vector B:"<<endl;
    for (int i = 0; i < n; i++)
    {
        B[i] = rand () % 200;
    }
    cout<<"Cargar el vector C:"<<endl;
    for (int i = 0; i < n; i++)
    {
        C[i] = rand () % 200;
    }
    
    Nodo *frente = NULL;
    Nodo *fin = NULL;
    for (int i = 0; i < n; i++)
    {
        cargarcola(frente, fin, A[i]);
        cargarcola(frente, fin, C[i]);
        cargarcola(frente, fin, B[i]);
    }
    system("pause");
    system("cls");

    int D[n*3];
    
    int v, index = 0;
    while (!colavacia(frente))
    {
        quitarcola(frente, fin, v);
        D[index++] = v;
    }

    cout<<"El vector D es:"<<endl;
    for (int i = 0; i < n*3; i++)
    {
        cout<<D[i]<<"  ";
    }

    delete []A;
    delete []B;
    delete []C;
    delete []D;

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

void cargarcola(Nodo *&frente, Nodo *&fin, int n){
    Nodo *n_nodo = new Nodo();
    n_nodo->dato = n;
    n_nodo->siguiente = NULL;
    if (colavacia(frente))
    {
        frente = n_nodo;
    }else
    {
        fin->siguiente = n_nodo;
    }
    fin = n_nodo;
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
