
// Ricorsione_prove.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int LinSearchRic(int n, int v[], int val,int count)
{
    int pos;
    if (v[0] == val)
    {
        return 0;
    }
    if (n == 1)
    {
        return -1;
    }
    count++;
    cout << count << endl;
    pos = LinSearchRic(n - 1, &v[1], val,count);
  
    if (pos >= 0)
        return (pos + 1);
    return -1;
}

int main()
{
    int n = 0,val,pos,count=0;
    srand( time (NULL));
    cout << "inserisci lunghezza vett ";
    cin >> n;
    int* v = new int[n];
    if (!v) { cout << "memoria non allocata"; }
    for (int i = 0; i < n; i++)
    {
        v[i] = rand() % 10;
    }

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << endl;
    }
    cout << "inserisci val ";
    cin >> val;
  
    pos = LinSearchRic(n, v, val,count);
    if (pos == -1)
    {
        cout << val << " NON TROVAT0" << endl;

    }
    else
    {

        cout << val << " si trova in posizione: " << pos << endl;

    }
    delete[] v;
   
}

