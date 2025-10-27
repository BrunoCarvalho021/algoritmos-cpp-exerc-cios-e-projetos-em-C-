#include <iostream>
#include <windows.h>
using namespace std;

struct Nodo
{
    int dato;
    Nodo *siguiente;
};

void cargarlista(Nodo *&, Nodo *&, int);
void mostrarlista(Nodo *);
void bsucarelemento(Nodo *, int);
void modificarelemento(Nodo *, int);
void eliminarelemento(Nodo *&, Nodo *&, int);


int main(){
    Nodo *primero = NULL;
    Nodo *ultimo = NULL;
    char op;
    int valor, menu;
    while (menu != 6)
    {
        cout<<"SELECCIONAR UNA OPCION :"<<endl;
        cout<<"1- Cargar elementos en la lista"<<endl;
        cout<<"2- Mostrar elementos en la lista"<<endl;
        cout<<"3- Buscar elementos en la lista"<<endl;
        cout<<"4- Modificar elementos en la lista"<<endl;
        cout<<"5- Eliminar elementos en la lista"<<endl;
        cout<<"6- Salir del Programa"<<endl;
        cin>>menu;
        while (menu < 1 || menu > 6)
        {
            cout<<"ERROR : SELECCIONE UNA OPCION DE ACUERDO CON MENU DE 1 AL 6."<<endl;
            cin>>menu;
        }
        switch (menu)
        {
        case 1:
            system("cls");
            do
            {
                cout<<"Ingrese un elemento :"<<endl;
                cin>>valor;
                cargarlista(primero, ultimo, valor);
                cout<<"Desea agregar mas ? (s/n):"<<endl;
                cin>>op;
            } while(op == 's' || op == 'S');
            break;
        case 2:
            mostrarlista(primero);
            system("pause");
            break;
        case 3:
            cout<<"Cual elemento desea Buscar ? "<<endl;
            cin>>valor;
            bsucarelemento(primero, valor);
            system("pause");
            break;
        case 4:
            cout<<"Cual elemento desea modificar ? "<<endl;
            cin>>valor;
            modificarelemento(primero, valor);
            system("pause");
            break;
        case 5:
            cout<<"Cual elemento desea eliminar ? "<<endl;
            cin>>valor;
            eliminarelemento(primero, ultimo, valor);
            system("pause");
            break;
        case 6:
            cout<<"Desea Salir ? (1 - Si 2 - No) "<<endl;
            cin>>menu;
            while (menu < 1 || menu > 2)
            {
                cout<<"ERROR : SOLAMENTE 1 Y 2 "<<endl;
                cin>>menu;
            }
            if (menu == 1)
            {
                menu = 6;
                cout<<"Gracias por utilizar este programa."<<endl;
            }else
            {
                menu = 0;
            }
            break;
        }

    }    
    return 0;
}

void cargarlista(Nodo *&primero, Nodo *&ultimo, int n){
    Nodo *nodo = new Nodo();
    nodo->dato = n;
    if (primero == NULL)
    {
        primero = nodo;
        primero->siguiente = primero;
        ultimo = primero;
    }else
    {
        ultimo->siguiente = nodo;
        nodo->siguiente = primero;
        ultimo = nodo;
    }
}

void mostrarlista(Nodo *primero){
    Nodo *actual = new Nodo();
    actual = primero;
    if (actual != NULL)
    {
        do
        {
            cout<<actual->dato<<endl;
            actual = actual->siguiente;
        }while(actual != primero);
    }else
    {
        cout<<"No existe elementos en la lista"<<endl;
    }
}

void bsucarelemento(Nodo *primero, int n){
    Nodo *actual = new Nodo();
    actual = primero;
    bool encontrado = false;
    if (actual != NULL)
    {
        do
        {
            if (actual->dato == n)
            {
                cout<<"El elemento "<<n<<" fue encontrado."<<endl;
                encontrado = true;
            }else
            {
                actual = actual->siguiente;
            }
        }while(actual != primero && encontrado == false);
        if (encontrado = false)
        {
            cout<<"El elemento "<<n<<" no se encontra en la lista."<<endl;
        }
    }else
    {
        cout<<"No existe elementos en la lista"<<endl;
    }

}

void modificarelemento(Nodo *primero, int n){
    Nodo *actual = new Nodo();
    actual = primero;
    bool encontrado = false;
    int nuevo;
    if (actual != NULL)
    {
        do 
        {
            if (actual->dato == n)
            {
                cout<<"Ingrese un nuevo valor:"<<endl;
                cin>>nuevo;
                actual->dato = nuevo;
                cout<<"El cambio fue realizado con suceso"<<endl;
                encontrado = true;
            }else
            {
                actual = actual->siguiente;
            }
        }while(actual != primero && encontrado == false);
    }else
    {
        cout<<"No existe elementos en la lista"<<endl;
    }
}

void eliminarelemento(Nodo *&primero, Nodo *&ultimo, int n){
    Nodo *actual = new Nodo();
    Nodo *aux = new Nodo();
    Nodo *anterior = new Nodo();
    bool encontrado = false;
    anterior = NULL;
    actual = primero;
    if (actual != NULL)
    {
        do
        {
            if (actual->dato == n)
            {
                aux = actual;
                if (actual == primero)
                {
                    primero = primero->siguiente;
                    ultimo->siguiente = primero;
                }else if (actual == ultimo)
                {
                    anterior->siguiente = primero;
                    ultimo = anterior;
                }else
                {
                    anterior->siguiente = actual->siguiente;
                }
                cout<<"Elemento "<<n<<" eliminado con suceso"<<endl;
                encontrado = true;
            }else
            {
                anterior = actual;
                actual = actual->siguiente;
            }
        }while(actual != NULL && encontrado == false);
        if (encontrado = false)
        {
            cout<<"Elemento "<<n<<" no encontrado , No es posible eliminar."<<endl;
        }
    }else
    {
        cout<<"No existe elementos en la lista"<<endl;
    }
}