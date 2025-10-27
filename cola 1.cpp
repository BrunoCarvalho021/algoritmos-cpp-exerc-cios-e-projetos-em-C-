#include <iostream>
#include <windows.h>
using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;
};

bool colavacia(Nodo *);
void cargarcola(Nodo *&, Nodo *&, int);
void quitarcola(Nodo *&, Nodo *&, int &);

int main(){
    string op;
    int n;
    Nodo *frente = NULL;
    Nodo *fin = NULL;
    do
    {
        cout<<"Ingrese un numero:"<<endl;
        cin>>n;

        cargarcola(frente, fin, n);
        
        cout<<"Desea agregar más ? (s/n):"<<endl;
        cin>>op;
    } while(op == "s" || op == "S");
    system("cls");
    cout<<"La cola cargada es:"<<endl;
    while (frente != NULL)
    {
        quitarcola(frente, fin, n);
        cout<<n;
        if (frente != NULL)
        {
            cout<<" , ";
        }else
        {
            cout<<" :: FIN"<<endl;
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