#include <iostream>
#include <windows.h>

using namespace std;

int main(){
    int lf, lc;
    int perimetro = 0;
    cout<<"Ingrese el tamano de fila:"<<endl;
    cin>>lf;
    cout<<"Ingrese el tamano de columna:"<<endl;
    cin>>lc;
    int M[lf][lc];
    cout<<"Cargar la matriz:"<<endl;
    for (int f = 0; f < lf; f++)
    {
        for (int c = 0; c < lc; c++)
        {
            cout<<"Posicion ("<<f+1<<")("<<c+1<<") -> "<<endl;
            cin>>M[f][c];
        }
        cout<<endl;
    }

    cout<<"La matriz cargada es:"<<endl;
    for (int f = 0; f < lf; f++)
    {
        for (int c = 0; c < lc; c++)
        {
            cout<<M[f][c]<<"   ";
        }
        cout<<endl;
    }

    for (int c = 0; c < lc; c++)
    {
        perimetro += M[0][c];
        perimetro += M[lf - 1][c];
    }
    for (int f = 1; f < lf - 1; f++)
    {
        perimetro += M[f][0];
        perimetro += M[f][lc - 1];
    }

    cout<<"El perimetro es: "<<perimetro<<endl;
    return 0;
}   
