#include <iostream>
#include <windows.h>

using namespace std;

int main(){
    int lf, lc, aux;
    cout<<"Ingrese el tamano de fila:"<<endl;
    cin>>lf;
    cout<<"Ingrese el tamano de columna:"<<endl;
    cin>>lc;
    while (lc != lf)
    {
        cout<<"ERROR : LF Y LC TIENE QUE SER IGUALES."<<endl;
        cin>>lc;
    }
    int B[lf][lc];
    int DS[lf];
    cout<<"Cargar la matriz:"<<endl;
    for (int f = 0; f < lf; f++)
    {
        for (int c = 0; c < lc; c++)
        {
            cout<<"Posicion ("<<f+1<<")("<<c+1<<") -> "<<endl;
            cin>>B[f][c];
            if (c == lf - f - 1 )
            {
                DS[f] = B[f][c];
            }
        }
        cout<<endl;
    }

    cout<<"La matriz cargada es:"<<endl;
    for (int f = 0; f < lf; f++)
    {
        for (int c = 0; c < lc; c++)
        {
            cout<<B[f][c]<<"   ";
        }
        cout<<endl;
    }

    // diagonal secundaria
    cout<<"La diagonal secundaria es:"<<endl;
    for (int f = 0; f < lf; f++)
    {
        cout<<DS[f]<<"  ";
    }

    //forma ascendetne
    for (int f = 0; f < lf - 1; f++)
    {
        for (int f = 0; f < lf - 1; f++)
        {
            if (DS[f] > DS[f+1])
            {
                aux = DS[f+1];
                DS[f+1] = DS[f];
                DS[f] = aux;
            }
            
        }
    }

    cout<<"\nLa diagonal secundaria en forma ascendente es:"<<endl;
    for (int f = 0; f < lf; f++)
    {
        cout<<DS[f]<<"   ";
    }

    //forma descendente
    for (int f = 0; f < lf - 1; f++)
    {
        for (int f = 0; f < lf - 1; f++)
        {
            if (DS[f] < DS[f+1])
            {
                aux = DS[f+1];
                DS[f+1] = DS[f];
                DS[f] = aux;
            }
            
        }
    }
    cout<<"\nLa diagonal secundaria en forma descendente es:"<<endl;
    for (int f = 0; f < lf; f++)
    {
        cout<<DS[f]<<"   ";
    }
    return 0;
}