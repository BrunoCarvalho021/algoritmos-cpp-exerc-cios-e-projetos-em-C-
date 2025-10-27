#include <iostream>
#include <windows.h>
using namespace std;

struct Nodo
{
    int dato;
    Nodo *siguiente;
    Nodo *anterior;
};

void insertarnodo(Nodo *&, Nodo *&, int);
void mostrarPRIMERO(Nodo *);
void mostrarULTIMO(Nodo *);
void buscarelemento(Nodo *, int);
void modificarnodo(Nodo *, int);
void eliminarelemento(Nodo *, Nodo *, int);

int main(){
    Nodo *primero = NULL;
    Nodo *ultimo = NULL;
    int valor, menu;
    char op;
    while (menu != 7)
    {
        system("cls");
        cout<<"SELECCIONE UN ELEMENTO DEL MENU:"<<endl;
        cout<<"1. inserta el elemento a lista double"<<endl;
        cout<<"2. mostrar elementos del primero al ultimo"<<endl;
        cout<<"3. mostrar elementos del ultimo al primero"<<endl;
        cout<<"4. buscar elemento en la lista"<<endl;
        cout<<"5. modificar elementos en la lista"<<endl;
        cout<<"6. eliminar elementos en la lista"<<endl;
        cout<<"7. salir del programa"<<endl;
        cin>>menu;
        while (menu < 1 || menu > 7)
        {
            cout<<"Solamente de 1 al 7."<<endl;
            cin>>menu;
        }
        switch (menu)
        {
        case 1:
            cout<<"inserta el elemento a lista double"<<endl;
            do{
                cout<<"Ingrese un elemento : "<<endl;
                cin>>valor;

                insertarnodo(primero, ultimo, valor);
                
                cout<<"Desea ingresar mas ? (s/n):"<<endl;
                cin>>op;

            }while(op == 's' || op == 'S');
            break;
        case 2:
            cout<<"mostrar elementos del primero al ultimo"<<endl;
            mostrarPRIMERO(primero);
            system("pause");
            break;
        case 3:
            cout<<"mostrar elementos del ultimo al primero"<<endl;
            mostrarULTIMO(ultimo);
            system("pause");
            break;
        case 4:
            cout<<"Buscar elemento en la lista"<<endl;
            cout<<"Cual elemento desea buscar ? "<<endl;
            cin>>valor;
            buscarelemento(primero, valor);
            system("pause");
            break;
        case 5:
            cout<<"modificar elementos en la lista"<<endl;
            cout<<"Ingrese el valor que desea cambiar ? "<<endl;
            cin>>valor;
            modificarnodo(primero, valor);
            system("pause");
            break;
        case 6:
            cout<<"eliminar elementos en la lista"<<endl;
            cout<<"Ingrese el valor que desea eliminar ? "<<endl;
            cin>>valor;
            eliminarelemento(primero, ultimo, valor);
            system("pause");
            break;
        case 7:
            cout<<"Saliendo........"<<endl;
            break;
        }
    }
    return 0;
}


void insertarnodo(Nodo *&primero, Nodo *&ultimo, int n){
    Nodo *nodo = new Nodo();
    nodo->dato = n;
    if (primero == NULL)
    {
        primero = nodo;
        primero->siguiente = NULL;
        primero->anterior = NULL;
        ultimo = primero;
    }else
    {
        ultimo->siguiente = nodo;
        nodo->siguiente = NULL;
        nodo->anterior = ultimo;
        ultimo = nodo;
    }
}

void mostrarPRIMERO(Nodo *primero){
    Nodo *actual = new Nodo();
    actual = primero;
    if (actual != NULL)
    {
        while (actual != NULL)
        {
            cout<<actual->dato<<endl;
            actual = actual->siguiente;
        }
    }else
    {
        cout<<"No existe elementos en la lista."<<endl;
    }
}

void mostrarULTIMO(Nodo *ultimo){
    Nodo *actual = new Nodo();
    actual = ultimo;
    if (actual != NULL)
    {
        while (actual != NULL)
        {
            cout<<actual->dato<<endl;
            actual = actual->anterior;
        }
    }else
    {
        cout<<"No existe elementos en la lista."<<endl;
    }
}
void buscarelemento(Nodo *primero, int n){
    Nodo *actual = new Nodo();
    actual = primero;
    bool encontro = false;
    if (actual != NULL)
    {
        while (actual != NULL && encontro == false)
        {
            if (actual->dato == n)
            {
                cout<<"Elemento "<<n<<" encontrado"<<endl;
                cout<<"Encontrado en la posicion "<<actual<<endl;
                encontro = true;
            }else
            {
                actual = actual->siguiente;
            }
        }
        if (encontro == false)
        {
          cout<<"No existe el elementos en la lista"<<endl;
        }
    }else
    {
        cout<<"No existe elementos en la lista"<<endl;
    }
    
}

void modificarnodo(Nodo *primero, int n){
    Nodo *actual = new Nodo();
    actual = primero;
    int valor;
    bool encontro = false;
    if (actual != NULL)
    {
        while (actual != NULL && encontro == false)
        {
            if (actual->dato == n)
            {
                cout<<"Elemento "<<n<<" encontrado"<<endl;
                cout<<"Ingrese el valor para modificar:"<<endl;
                cin>>valor;
                actual->dato = valor;
                encontro = true;
            }else
            {
                actual = actual->siguiente;
            }
        }
        if (encontro == false)
        {
          cout<<"No existe el elementos en la lista"<<endl;
        }
    }else
    {
        cout<<"No existe elementos en la lista"<<endl;
    }
}

void eliminarelemento(Nodo *primero, Nodo *ultimo, int n){
    Nodo *actual = new Nodo();
    Nodo *aux = new Nodo();
    Nodo *anterior = new Nodo();
    bool encontro = false;
    actual = primero;
    anterior = NULL;
    if (actual != NULL)
    {
        while (actual != NULL && encontro == false)
        {
            if (actual->dato == n)
            {
                if (actual == primero)
                {
                    aux = primero;
                    primero = primero->siguiente;
                    primero->anterior = NULL;
                }else if (actual == ultimo)
                {
                    anterior->siguiente = NULL;
                    ultimo = anterior;
                    
                }else
                {
                    aux = actual;
                    anterior->siguiente = actual->siguiente;
                    actual->siguiente->anterior = anterior;
                }
                delete aux;
                cout<<"El elemento "<<n<<" fue eliminado correctamente"<<endl;
                encontro = true;
            }else
            {
                anterior = actual;
                actual = actual->siguiente;
            }
        }
        if (encontro == false)
        {
            cout<<"No se encontro ese elemento para eliminar"<<endl;
        }
    }else
    {
        cout<<"No existe elementos para eliminar"<<endl;
    }
}