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
    int B[6][5];
    Nodo *pila = NULL;
    cout<<"Cargar la matriz:"<<endl;
    for (int f = 0; f < 6; f++)
    {
        if (f %2 == 0)
        {
            for (int c = 0; c < 5; c++)
            {
                cout<<"Posicion ("<<f+1<<")("<<c+1<<") -> "<<endl;
                cin>>B[f][c];
                cargarPILA(pila, B[f][c]);
            }
        }else
        {
            for (int c = 0; c < 5; c++)
            {
                if (pila != NULL)
                {
                    quitarPILA(pila, B[f][c]);
                }else
                {
                    cout<<"ERROR: LA PILA ESTA VACIA Y NO SE PUEDE LLENAR LA FILA."<<endl;
                    return 1;
                }
                
            }
        }
    }

    cout<<"\nLa matriz cargada es:"<<endl;
    for (int f = 0; f < 6; f++)
    {
       for (int c = 0; c < 5; c++)
       {
          cout<<B[f][c]<<"  ";
       }
       cout<<endl;
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

