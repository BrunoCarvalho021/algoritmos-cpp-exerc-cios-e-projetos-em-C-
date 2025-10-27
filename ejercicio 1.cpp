#include <iostream>
#include <windows.h>

using namespace std;

bool esprimo(int n){
    if (n < 2) return false;
    for (int i = 2; i*i <= n; i++)
    {
        if (n %i == 0)
        {
            return false;
        }
    }
    return true;
}

int main(){
    int lf, lc;
    int suma = 0, may = 0 , men = INT_MAX, digitos = 0;
    cout<<"Ingrese tamano de fila:"<<endl;
    cin>>lf;
    cout<<"Ingrese tamano de columna:"<<endl;
    cin>>lc;
    while (lc != lf)
    {
        cout<<"La cantidad de lc tiene que ser igual a lf."<<endl;
        cin>>lc;
    }
    int B[lf][lc];
    int DP[lf];
    cout<<"Cargar matriz:"<<endl;
    for (int f = 0; f < lf; f++)
    {
        for (int c = 0; c < lc; c++)
        {
            cout<<"Cargar ("<<f+1<<")("<<c+1<<") -> "<<endl;
            cin>>B[f][c];
            if (f == c)
            {
                DP[c] = B[f][c];
                suma += DP[c];
                if (DP[c] < men)
                {
                    men = DP[c];
                }else if (DP[c] > may)
                {
                    may = DP[c];
                }
                if (DP[c] >= 100)
                {
                    digitos++;
                }
            }
        }
        cout<<endl;
    }
    cout<<"La matriz cargada es:"<<endl;
    for (int f = 0; f < lf; f++)
    {
        for (int c = 0; c < lc; c++)
        {
            cout<<B[f][c]<<"  ";
        }
        cout<<endl;
    }
    cout<<"El vector DP es: "<<endl;
    for (int c = 0; c < lc; c++)
    {
        cout<<DP[c]<<"  ";
    }
    cout<<"La sumatoria del vector DP es: "<<suma<<endl;
    cout<<endl;
    cout<<"El mayor elemento del Vector DP es:"<<may<<endl;
    cout<<endl;
    cout<<"El menor elemento del Vector DP es:"<<men<<endl;
    cout<<endl;
    cout<<"Existen "<<digitos<<" numeros con mas de dos digitos."<<endl;
    cout<<endl;
    if (esprimo(suma))
    {
        cout<<suma<<" es primo."<<endl;
    }else
    {
        cout<<suma<<" No es primo."<<endl;
    }
    return 0;
}