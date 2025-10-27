#include <iostream>
#include <windows.h>
using namespace std;

struct Nodo
{
    int dato;
    Nodo *siguiente;
    Nodo *anterior;
};

void caragarlista(Nodo *&, Nodo *&, int);
void imprimirprimero(Nodo *);
void imprimirultimo(Nodo *);
void buscarelemento(Nodo *, int);
void modificarelemento(Nodo *, int);
void eliminarelemento(Nodo *&, Nodo *&, int);

int main(){
    Nodo *primero = NULL;
    Nodo *ultimo = NULL;
    int menu, valor;
    string op;
    while (menu != 7)
    {
        cout<<"Seleccione una opcion"<<endl;
        cout<<"1- Cargar elementos en la lista"<<endl;
        cout<<"2- Imprimir elementos de la lista primero"<<endl;
        cout<<"3- Imprimir elementos de la lista ultimo"<<endl;
        cout<<"4- busucar elementos de la lista"<<endl;
        cout<<"5- modificar elementos de la lista"<<endl;
        cout<<"6- eliminar elementos de la lista"<<endl;
        cout<<"7- Salir del programa"<<endl;
        cin>>menu;
        while (menu < 1 || menu > 7)
        {
            cout<<"ERROR: SOLAMENTE DE 1 AL 7"<<endl;
            cin>>menu;
        }
        switch (menu)
        {
        case 1:
            system("cls");
            do
            {
                cout<<"Ingrese un elemento:"<<endl;
                cin>>valor;
                caragarlista(primero, ultimo, valor);
                cout<<"Desea agregar mas ? (s/n)"<<endl;
                cin>>op;
            } while(op == "S" || op == "s");
            break;
        case 2:
            system("cls");
            cout<<"La lista por primero es "<<endl;
            imprimirprimero(primero);
            system("pause");
            break;
        case 3:
            system("cls");
            cout<<"La lista por ultimo es "<<endl;
            imprimirultimo(ultimo);
            system("pause");
            break;
        case 4:
            system("cls");
            cout<<"Cual elemento desea buscar ? "<<endl;
            cin>>valor;
            buscarelemento(primero, valor);
            system("pause");
            break;
        case 5:
            system("cls");
            cout<<"Cual elemento desea modificar ? "<<endl;
            cin>>valor;
            modificarelemento(primero, valor);
            system("pause");
            break;
        case 6:
            system("cls");
            cout<<"Cual elemento desea eliminar ? "<<endl;
            cin>>valor;
            eliminarelemento(primero, ultimo, valor);
            system("pause");
            break;                
        case 7:
            cout<<"Desea salir ? (1- si 2- no)"<<endl;
            cin>>menu;
            while (menu < 1 || menu > 2)
            {
                cout<<"Solamente de 1 a 2"<<endl;
                cin>>menu;
            }
            if (menu == 1)
            {
                cout<<"Gracias por utilizar este programa"<<endl;
                menu = 7;
            }else
            {
                menu = 0;
            }
            break;
        }
    }
    return 0;

}

void caragarlista(Nodo *&primero, Nodo *&ultimo, int n){
    Nodo *nodo = new Nodo();
    nodo->dato = n;
    if (primero == NULL)
    {
        primero = nodo;
        ultimo = nodo;
        primero->siguiente = primero;
        ultimo->anterior = ultimo;
    }else
    {
        ultimo->siguiente = nodo;
        nodo->siguiente = primero;
        nodo->anterior = ultimo;
        ultimo = nodo;
        primero->anterior = ultimo;
    }
}

void imprimirprimero(Nodo *primero){
    if (primero == NULL)
    {
        cout<<"La lista esta vacia"<<endl;
        return;
    }

    Nodo *actual = primero;
    do
    {
        cout<<actual->dato<<" ";
        actual = actual->siguiente;
    }while(actual != primero);
}

void imprimirultimo(Nodo *ultimo){
    if (ultimo == NULL)
    {
        cout<<"La lista vacia"<<endl;
        return;
    }

    Nodo *actual = ultimo;
    do
    {
        cout<<actual->dato<<" ";
        actual = actual->anterior;
    }while(actual != ultimo);
}

void buscarelemento(Nodo *primero, int n){
    if (primero == NULL)
    {
        cout<<"La lista estava vacia"<<endl;
        return;
    }
    Nodo *actual = primero;
    bool encontrado = false;
    do
    {
        if (actual->dato == n)
        {
            cout<<"El elemento "<<n<<" fue encontrado en la posicion "<<&n<<endl;
            encontrado = true;
            break;
        }else
        {
            actual = actual->siguiente;
        }
    }while(actual != primero);
    if (encontrado == false)
    {
        cout<<"El elemento "<<n<<" no se encontra en la lista"<<endl;
    }
}

void modificarelemento(Nodo *primero, int n){
    if (primero == NULL)
    {
        cout<<"La lista estava vacia"<<endl;
        return;
    }
    Nodo *actual = primero;
    bool encontrado = false;
    int nuevo;
    do
    {
        if (actual->dato == n)
        {
            cout<<"Ingrese el nuevo valor"<<endl;
            cin>>nuevo;
            actual->dato = nuevo;
            encontrado = true;
        }else
        {
            actual = actual->siguiente;
        }
    }while(actual != primero);
    if (!encontrado)
    {
        cout<<"El numero que desea modificar no se encontra en la lista"<<endl;
    }
}

void eliminarelemento(Nodo *&primero, Nodo *&ultimo, int n){
    if (primero == NULL)
    {
        cout<<"La lista estava vacia"<<endl;
        return;
    }
    Nodo *actual = primero;
    bool encontrado = true;
    do
    {
        if (actual->dato == n)
        {
            encontrado = true;
            if (actual == primero && actual == ultimo)
            {
                primero = ultimo = NULL;
            }else if (actual == primero)
            {
                primero = primero->siguiente;
                ultimo->siguiente = primero;
                primero->anterior = ultimo;
            }else if (actual == ultimo)
            {
                ultimo = ultimo->anterior;
                ultimo->siguiente = primero;
                primero->anterior = ultimo;
            }else
            {
                actual->anterior->siguiente = actual->siguiente;
                actual->siguiente->anterior = actual->anterior;
            }
            delete actual;
            cout<<" El elemento "<<n<<" fue eliminado correctamente"<<endl;
            break;
        }else
        {
            actual = actual->siguiente;
        }
    }while(actual != primero);
    if (!encontrado)
    {
        cout<<"El elemento que desea eliminar no se encontra en la lista"<<endl;
    }
}
