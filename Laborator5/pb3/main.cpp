#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

using namespace std;

//Folosim oartitionarea Lomuto

int partitionare(int *v, int st, int dr)
{
    int pivot = v[dr];
    int i = st;
    for (int j = st; j < dr ; j++)
        {
            if (v[j] <= pivot)
            {
             swap(v[i], v[j]);
             i++;
            }
        }
    swap(v[i], v[dr]);
    return i;
}

int partition_r(int *v, int st, int dr)
{
    srand(time(NULL));
    int random = st + rand()%(dr - st);
    swap(v[random], v[dr]);
    return partitionare(v, st, dr);
}

void quickSort(int *v, int st, int dr)
{
    if (st < dr)
      {
        int piv = partition_r(v, st, dr);
        quickSort(v, st, piv - 1);
        quickSort(v, piv + 1, dr);
      }
}

int main()
{
 int *v,n,i;
 cout << "Dati numarul de elemente: ";
 cin >> n;
 v = new int [n];
 cout << "Dati elementele vectorului: ";
 for (i = 0; i < n; i++)
         cin >> v[i];
 quickSort(v, 0, n-1);
 cout << "Vectorul sortat este: ";
 for (i = 0; i < n; i++)
    cout << v[i] << " ";
 delete []v;
    return 0;
}
