#include <iostream>

using namespace std;

void shellsort(int *v, int n)
{
 int gap, i, temp, j;
 for (gap = n/2; gap > 0; gap /= 2)
    {
     for (i = gap; i < n; i++)
        {
         temp = v[i];
         for (j = i; j >= gap && v[j-gap] > temp; j -= gap)
            v[j] = v[j - gap];
         v[j] = temp;
        }
    }
}

int main()
{int i,n,*v;
 cout << "Dati numarul de elemente: ";
 cin >> n;
 v = new int [n];
 for (i = 0; i < n; i++)
    {
        cout << "v[" << i << "]=";
        cin >> v[i];
    }
 cout << "Vectorul inainte de sortare: ";
 for (i = 0; i < n; i++)
    cout << v[i] << " ";
 shellsort(v,n);
 cout << endl << "Vectorul dupa sortare: ";
 for (i = 0; i < n; i++)
    cout << v[i] << " ";
 delete []v;
       return 0;
}

