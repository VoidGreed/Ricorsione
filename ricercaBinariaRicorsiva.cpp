
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int ricerca_binaria_ricorsiva(int v[], int val, int testa, int coda)
{
    int pos_med;

    if (testa < coda)
    {
        pos_med = (coda+testa)/2;
        if (val == v[pos_med])
            return pos_med;
        else
        {
            if (v[pos_med] < val)
            {
                return ricerca_binaria_ricorsiva(v, val, pos_med + 1, coda);
            }
            else
                return ricerca_binaria_ricorsiva(v, val, testa, pos_med - 1);
        }
    }
    else if (v[testa] == val)
        return testa;
    else return -1;
}

void bubble_sort(int v[],int n)
{
    bool swap;
    do{
        int i = 0, lastswap = 0 ;
        swap = false;
        for (int j = n - 1; j > i; j--)
        {
            if (v[j] < v[j - 1])
            {
                int temp = v[j - 1];
                v[j - 1] = v[j];
                v[j] = temp;
                swap = true;
                lastswap = j;
            }
        }
        i = lastswap;
    
    } while (swap);
}
int main()
{
    int n = 0, val, pos, count = 0,testa,coda;
    srand(time(NULL));
    cout << "inserisci lunghezza vett ";
    cin >> n;
    int* v = new int[n];
    if (!v) { cout << "memoria non allocata"; }
    for (int i = 0; i < n; i++)
    {
        v[i] = rand();
    }
   
    bubble_sort( v, n);

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << endl;
    }
    cout << "inserisci val ";
    cin >> val;
    testa = 0;
    coda = n - 1;
    pos=ricerca_binaria_ricorsiva(v,val,testa,coda);

    cout << "Il valore si trova in posizione " << pos<<endl;
    delete[] v;

}