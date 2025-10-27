#include <iostream>
#include <windows.h>

using namespace std;

struct Producto
{
    int codigo;
    char descripcion[100];
    char tipo[50];
    float costo;
    float iva;
};
struct Nodo
{
    Producto producto;
    Nodo *siguiente;
};

void cargarPILA(Nodo *&, Producto);
void quitarPILA(Nodo *&, Producto &);
void imprimirPILA(Nodo *);

int main(){
    string op;
    Nodo *pila = NULL;
    do
    {
        Producto p;
        cout<<"Ingrese el codigo del producto:"<<endl;
        cin>>p.codigo;
        cin.ignore();

        cout<<"Ingrese la descripcion del producto:"<<endl;
        cin>>p.descripcion;
        cin.ignore();

        cout<<"Ingrese el tipo del producto:"<<endl;
        cin>>p.tipo;
        cin.ignore();

        cout<<"Ingrese el costo del producto:"<<endl;
        cin>>p.costo;
        cin.ignore();

        
        p.iva = p.costo * 0.10;

        cargarPILA(pila, p);

        cout<<"Desea cargar otro elemento ? (s/n):"<<endl;
        cin>>op;
        cin.ignore();

        
    } while(op == "S" || op == "s");
    system("pause");
    cout<<"La pila cargada es:"<<endl;
    imprimirPILA(pila);
    return 0;
}

void cargarPILA(Nodo *&pila, Producto p){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->producto = p;
    nuevo_nodo->siguiente = pila;
    pila = nuevo_nodo;
    cout<<"el producto se encargo correctamente."<<endl;
}

void quitarPILA(Nodo *&pila, Producto &p){
    if (pila != NULL)
    {
        Nodo *aux = pila;
        p = aux->producto;
        pila = aux->siguiente;
        delete aux;
    }
}


void imprimirPILA(Nodo *pila){
    Nodo *aux = pila;
    while (aux != NULL)
    {
        Producto p = aux->producto;
        cout<<"Codigo: "<<p.codigo<<",Descripcion: "<<p.descripcion<<",tipo: "<<p.tipo<<",costo:"<<p.costo<<",IVA: "<<p.iva<<endl;
        aux = aux->siguiente;
    }

}
