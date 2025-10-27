#include <iostream>
#include <windows.h>
using namespace std;

struct Nodo
{
    int cedula, hijos, mes;
    string nombre;
    string apellido;
    string direccion;
    double salario, bonificacion, descuento, neto;
    Nodo *siguiente;

};

Nodo* repetido(Nodo *lista, int cedula, int mes){
    while (lista !=  NULL)
    {
        if (lista->cedula == cedula && lista->mes == mes)
        {
            return lista;
            
        }
        lista = lista->siguiente;
    }
    return NULL;
}

void mostrarmenu(){
    cout<<"============================"<<endl;
    cout<<"            MENU            "<<endl;
    cout<<"============================"<<endl;
    cout<<" [1] - cargar datos del funcionario"<<endl;
    cout<<" [2] -  Mostrar todos los registros cargados con un resumen del monto total en concepto de pago de salarios "<<endl;
    cout<<" [3] - Mostrar registros de pagos de un mes indicado, con un resumen del monto total en concepto de pago de salarios "<<endl;
    cout<<" [4] - Mostrar los pagos percibidos por un funcionario cualquiera indicando su numero de cedula "<<endl;
    cout<<" [5] - Mostrar registros de pago solicitando la cedula y mes de pago"<<endl;
    cout<<" [6] - Modificar un registro cargado"<<endl;
    cout<<" [7] - Buscar la cantidad de funcionarios sin hijos/as, con 1 hijo/a, con mas de 1 hijo/a"<<endl;
    cout<<" [8] - Eliminar un registro de la lista"<<endl;
    cout<<" [9] - Eliminar todos los elementos de la lista "<<endl;
    cout<<" [10] - Salir o Regresar"<<endl;
}

void cargarlista(Nodo *&lista, int ci , int hijo, int mess, string nome, string sobrenome, string endereco, double sl, double boni, double des, double slneto){
    Nodo *nodo = new Nodo();
    Nodo *aux1 = lista;
    Nodo *aux2 = NULL;
    nodo->cedula = ci;
    nodo->hijos = hijo;
    nodo->mes = mess;
    nodo->nombre = nome;
    nodo->apellido = sobrenome;
    nodo->direccion = endereco;
    nodo->salario = sl;
    nodo->bonificacion = boni;
    nodo->descuento = des;
    nodo->neto = slneto;
    while(aux1 != NULL){
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }
    if (lista == aux1)
    {
        lista = nodo;
    }else{
        aux2->siguiente = nodo;
    }
    nodo->siguiente = aux1;
}

void mostrarlista(Nodo *lista){
    double totalsalarios = 0;
    Nodo *aux = lista;
    if (aux != NULL)
    {
        cout<<"LA LISTA CARGADA ES:"<<endl;
        cout<<"==================================="<<endl;
        while (aux != NULL)
        {
            cout<<" Cedula: "<<aux->cedula<<" | Nombre: "<<aux->nombre<<" | Apellido: "<<aux->apellido<<endl;
            cout<<" Direccion: "<<aux->direccion<<" Hijos: "<<aux->hijos<<endl;
            cout<<" Mes: "<<aux->mes<<" | Salario Base: "<<aux->salario<<" | Bonificacion: "<<aux->bonificacion<<" | Descuento: "<<aux->descuento<<endl;
            cout<<"Sueldo Neto: "<<aux->neto;
            totalsalarios += aux->neto;
            aux = aux->siguiente;

        }
        cout<<"El total de salarios netos: "<<totalsalarios<<endl;
    }else
    {
        cout<<" LA LISTA ESTA VACIA"<<endl;
    }
}

void mostrarpormes(Nodo *lista, int mes){
    double total = 0;
    bool encontrado = false;
    Nodo *aux = lista;
    while (lista != NULL)
    {
        if (aux->mes == mes)
        {
            encontrado = true;
            cout<<" Cedula: "<<aux->cedula<<" | Nombre: "<<aux->nombre<<" | Apellido: "<<aux->apellido<<endl;
            cout<<"Sueldo Neto: "<<aux->neto;
            total += aux->neto;
        }
        aux = aux->siguiente;
    }
    if (encontrado)
    {
        cout<<"Total pagado en el mes "<<mes<<" : "<<total<<endl;
    }else
    {
        cout<<"No se encontra ningun pago "<<endl;
    }
}

void mostrarporcedula(Nodo *lista, int ci){
    double total = 0;
    bool encontrado = false;
    Nodo *aux = lista;
    while (lista != NULL)
    {
        if (aux->cedula == ci)
        {
            encontrado = true;
            cout<<" Mes: "<<aux->mes<<" | Sueldo Neto: "<<aux->neto<<endl;
            total += aux->neto;
        }
        aux = aux->siguiente;
    }
    if (encontrado)
    {
        cout<<"Total recebido por el funcionario  "<<total<<endl;
    }else
    {
        cout<<"funcionario no encontrado"<<endl;
    }
}

void mostrarpormes(Nodo *lista, int ci, int mes){
    double total = 0;
    bool encontrado = false;
    Nodo *aux = lista;
    while (lista != NULL)
    {
        if (aux->cedula == ci && aux->mes == mes)
        {
            encontrado = true;
            cout<<"Nombre: "<<aux->nombre<<" Apellido: "<<aux->apellido<<endl;
            cout<<"Sueldo Neto"<<aux->neto<<endl;
            total += aux->neto;
        }
        aux = aux->siguiente;
    }
    if (encontrado)
    {
        cout<<" funionario con saldo neto : "<<total<<endl;
    }else
    {
        cout<<"funcionario no encontrado"<<endl;
    }
}

void contadorhijos(Nodo *lista){
    int sin = 0, uno = 0, mas = 0;
    while (lista != NULL)
    {
        if(lista->hijos == 0) sin++;
        else if (lista->hijos == 1)
        {
            uno++;
        }else
        {
            mas++;
        }
        lista = lista->siguiente;
    }
    cout<<sin<<" sin hijos"<<endl;
    cout<<uno<<" con 1 hijo"<<endl;
    cout<<mas<<" con mas de 1 hijo"<<endl;
}

void modificarRegistro(Nodo *&lista, int ci, int mes){
    Nodo *aux = lista;
    while (aux != NULL)
    {
        if (aux->cedula == ci && aux->mes == mes)
        {
            cout<<"Ingrese nuevo salario base:"<<endl;
            cin>>aux->salario;
            aux->bonificacion = (aux->hijos >= 2) ? aux->salario * 0.10 : 0;
            aux->descuento = aux->salario * 0.10;
            aux->neto = aux->salario + aux->bonificacion - aux->descuento;
            cout<<" Registro modificado con suceso."<<endl;
            return;
        }
        aux = aux->siguiente;
    }
    cout<<"Registro no encontrado"<<endl;
}

void eliminarregistro(Nodo *lista, int ci, int mes){
    Nodo *aux1 = NULL;
    Nodo *aux2 = lista;
    while (aux1 != NULL && !(aux1->cedula == ci && aux1->mes == mes))
    {
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }
    if (aux1  == NULL)
    {
        cout<<"Registro no encontrado"<<endl;
        return;
    }
    if (aux2 == NULL)
    {
        lista = aux1->siguiente;
    }else
    {
        aux2->siguiente = aux1->siguiente;
        delete aux1;
        cout<<"Registro eliminado"<<endl;
    }
}

void eliminarlista(Nodo *&lista){
    Nodo *aux = lista;
    Nodo *auxb = NULL;
    if(aux == NULL)
    {
        cout<<"No hay nada que eliminar."<<endl;
    }else
    {
        while (aux != NULL)
        {
            aux = lista;
            if (aux != NULL)
            {
                lista = lista->siguiente;
                auxb = aux;
                delete auxb;
            }
        }
        delete aux;
        cout<<"Todos los elementos fueran eliminados."<<endl;
    }
}


int main(){
    int ci, hijo, mess, menu = 0;
    string nome, sobrenome, endereco;
    double sl, boni, des, slneto;
    char op;
    Nodo *lista = NULL;
    while (menu != 10)
    {
        system("cls");
        mostrarmenu();
        cin>>menu;
        while(menu < 1 || menu > 10 ){
            system("cls");
            cout<<"ERROR: INTENTE NUEVAMENTE"<<endl;
            cin>>menu;
        }
        system("cls");
        switch (menu)
        {
        case 1:
            cout<<"Cargar datos del funcionario"<<endl;
            do
            {
               cout<<"cedula:"<<endl;
               cin>>ci;
               cout<<"mes (1-6):"<<endl;
               cin>>mess;
               while(mess < 1 || mess > 6)
               {
                   cout<<"SOLAMENTE ENTRE ENERO (1) HASTA JUNIO (6). INTENTE NUEVAMENTE."<<endl;
                   cin>>mess;
               }
               if (repetido(lista,ci, mess))
               {
                 cout<<"YA EXISTE E REGISTRO DE LA CEDULA EN EL MES "<<mess<<"NO SE PUEDE AGREGAR."<<endl;
                 break;
               }
               cout<<"Ingrese cantidad de hijos:"<<endl;
               cin>>hijo;
               while(hijo < 0 || hijo > 5)
               {
                   cout<<"NUMERO MAXIMO DE HIJOS HASTA 5"<<endl;
                   cin>>hijo;
               }
               cin.ignore();
               cout<<"nombre:"<<endl;
               getline(cin, nome);
               cout<<"apellido:"<<endl;
               getline(cin, sobrenome);
               cout<<"direccion:"<<endl;
               getline(cin, endereco);
               cout<<"salario base:"<<endl;
               cin>>sl;
               if (hijo >= 2)
               {
                  boni = sl * 0.10;
               }else
               {
                  boni = 0;
               }
               des = sl * 0.10;
               slneto = (sl + boni) - des;

               cargarlista(lista,ci, hijo, mess, nome, sobrenome, endereco, sl, boni, des, slneto);

               cout<<"Desea agregar mas ? (s/n): "<<endl;
               cin>>op;

            }while(op == 's' || op == 'S');
            break;
        case 2:
            cout<<" [2] -  Mostrar todos los registros cargados con un resumen del monto total en concepto de pago de salarios "<<endl;
            mostrarlista(lista);
            system("pause");
            break;
        case 3:
            cout<<"mostrar por mes:"<<endl;
            cin>>mess;
            mostrarpormes(lista, mess);
            system("pause");
            break;
        case 4:
            cout<<"mostrar por cedula:"<<endl;
            cin>>ci;
            mostrarporcedula(lista, ci);
            system("pause");
            break;
        case 5:
            cout<<"cedula:"<<endl;
            cin>>ci;
            cout<<"mes:"<<endl;
            cin>>mess;
            mostrarpormes(lista, ci, mess);
            system("pause");
            break;
        case 6:
            cout<<"cedula:"<<endl;
            cin>>ci;
            cout<<"mes:"<<endl;
            cin>>mess;
            modificarRegistro(lista, ci, mess);
            system("pause");
            break;
        case 7:
            contadorhijos(lista);
            system("pause");
            break;
        case 8:
            cout<<"cedula:"<<endl;
            cin>>ci;
            cout<<"mes:"<<endl;
            cin>>mess;
            eliminarregistro(lista, ci, mess);
            system("pause");
            break;
        case 9:
            eliminarlista(lista);
            system("pause");
            break;
        case 10:
            cout<<"Saliendo....."<<endl;
            break;
        }
    }


    return 0;
}