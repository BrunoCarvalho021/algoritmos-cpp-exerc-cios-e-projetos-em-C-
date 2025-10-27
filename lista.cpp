#include <iostream>
#include <windows.h>
using namespace std;

struct Nodo
{
    int dato;
    Nodo *siguiente;
};

void cargarlista(Nodo *&, int);
void mostrarlista(Nodo *);
bool buscarnodo(Nodo *,int)
bool modificarelemento(Nodo *,int);
void eliminarelemento(Nodo*&, int);
void vaciar(Nodo *&);

void menu(int opcion){
    system("cls");
    cout<<"================================"<<endl;
    if (opcion == 1)
    {
        cout<<"              MENU            "<<endl;
    }else
    {
        cout<<"              ERROR           "<<endl;
        cout<<" SOLO PUEDE VALORES DE 1 AL 7 "<<endl;
    }
    cout<<"================================"<<endl;
    cout<<"[1]. Cargar Elementos"<<endl;
    cout<<"[2]. Imprimir Lista"<<endl;
    cout<<"[3]. Buscar Elementos"<<endl;
    cout<<"[4]. Modificar Elementos"<<endl;
    cout<<"[5]. Eliminar Elementos"<<endl;
    cout<<"[6]. Vaciar Lista"<<endl;
    cout<<"[7]. Salir del Programa"<<endl;
    cout<<"======================="<<endl;
    cout<<"Ingrese un numero:"<<endl;

}

int main(){
    string op;
    Nodo *lista = NULL;
    int menu = 0, n;
    while (menu != 7)
    {
        menu(1);
        cin>>menu;
        while (menu < 1 || menu > 7)
        {
            menu(0);
            cin>>menu;
        }
        system("cls");
        switch (menu)
        {
        case 1:
            do
            {
                system("cls");
                cout<<"[1]. Cargar Elementos"<<endl;
                cout<<"ingrese un numero:"<<endl;
                cin>>n;
                cargarlista(lista, n);
                cout<<"Desea continuar? (s/n)"<<endl;
                cin>>op;
            } while(op == "S" || "s");
            break;
        case 2:
            cout<<"[2]. Imprimir Lista"<<endl;
            mostrarlista(lista,n);
            break;
        case 3:
            cout<<"[3]. Buscar Elementos"<<endl;
            cout<<"ingrese el nro a buscar"<<endl;
            cin>>n;
            if (lista != NULL)
            {
                if (buscarnodo(lista, n))
                {
                    cout<<"elemento encontrado"<<endl;
                }else
                {
                    cout<<"no existe el elemento buscado"<<endl;
                }
            }else
            {
                cout<<"no hay elementos en la lista"<<endl;
            }
            break;
        case 4:
            cout<<"[4]. Modificar Elementos"<<endl;
            cout<<"ingrese un numero:"<<endl;
            cin>>n;
            modificarelemento(lista, n);
            break;
        case 5:
            cout<<"[5]. Eliminar Elementos"<<endl;
            cout<<"ingrese un dato:"<<endl;
            cin>>n;
            eliminarelemento(lista, n);
            break;
        case 6:
            cout<<"[6]. Vaciar Lista"<<endl;
            vaciar(lista);
            break;
        case 7:
            cout<<"[7]. Fin del Programa"<<endl;
            cout<<"gracias por utilizar el programa"<<endl;
            break;
        }
        system("pause");

    }
    return 0;
}


void cargarlista(Nodo *&lista, int n){
    Nodo *nodo = new Nodo();
    Nodo *aux1 = lista;
    Nodo *aux2 = NULL;
    nodo->dato = n;
    while (aux1 != 1)
    {
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }
    if (lista == aux1)
    {
        lista = nodo;
    }else
    {
        aux2->siguiente = nodo;
    }
    nodo->siguiente = aux1;
}

void mostrarlista(Nodo *lista){
    Nodo *ver = lista;
    if (ver != NULL)
    {
        while (ver != NULL)
        {
            cout<<ver->siguiente;
            if (ver != NULL)
            {
                cout<<",";
            }else
            {
                cout<<" :: FIN "<<endl;
            }
        }
    }else
    {
        cout<<"No hay elementos en la lsita"<<endl;
    }
}

bool buscarnodo(Nodo *lista, int n){
    Nodo *buscar = lista;
    bool encontro = false;
    while (buscar != NULL && encontro == false)
    {
        if (buscar->datoo == n)
        {
            encontro = true;
        }else
        {
            buscar = buscar->siguiente;
        }
    }
    return encontro;
}

bool modificarelemento(Nodo *lista,int n){
    Nodo *buscar = lista;
    bool encontro = false;
    int cambio;
    while (buscar != NULL && encontro == false)
    {
        if (buscar->datoo == n)
        {
            encontro = true;
        }else
        {
            buscar = buscar->siguiente;
        }
    }
    if (encontro == true)
    {
        cout<<"ingrese un nuevo valor"<<endl;
        cin>>cambio;
        buscar->dato = cambio;
        cout<<"El dato fue modificado correctamente"<<endl;
    }else
    {
        cout<<"El elemento buscado no existe."<<endl;
    }
}

void eliminarelemento(Nodo *&lista, int n){
    Nodo *auxb = lista;
    Nodo *antes = NULL;
    bool encontro = false;
    while (auxb  != NULL && encontro == false)
    {
        if (auxb->dato == n)
        {
            encontro = true;
        }else
        {
            antes = auxb;
            auxb = aux->siguiente;
        }
    }
    if (auxb == NULL)
    {
        cout<<"NO EXISTE EL ELEMENTO."<<endl;
    }else
    {
        if (antes == NULL)
        {
            lista = auxb->siguiente;
            delete auxb;
        }else
        {
            antes->siguiente = auxb->siguiente;
            delete auxb;
        }
        cout<<"elemento eliminado correctamente."<<endl;
    }
}

void vaciar(Nodo *&lista){
    Nodo *auxb = lista;
    Nodo *antes = NULL;
    bool encontro = false;
    while (auxb  != NULL && encontro == false)
    {
        if (auxb->dato == n)
        {
            encontro = true;
        }else
        {
            antes = auxb;
            auxb = aux->siguiente;
        }
    }
    if (auxb == NULL)
    {
        cout<<"NO EXISTE EL ELEMENTO."<<endl;
    }else
    {
        if (antes == NULL)
        {
            lista = auxb->siguiente;
            delete auxb;
        }else
        {
            antes->siguiente = auxb->siguiente;
            delete auxb;
        }
        cout<<"elemento eliminado correctamente."<<endl;
    }
}