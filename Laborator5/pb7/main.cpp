#include <iostream>

using namespace std;

void inter(int st, int mij, int dr, int n, int *v)
{
 int i = st, j = mij+1, *w, k=0;
 w = new int [n];
 while (i <= mij && j <= dr)
    {
     if (v[i] < v[j])
        w[k++] = v[i++];
     else
        w[k++] = v[j++];
    }
 for (int l = i; l <= mij; l++)
    w[k++] = v[l];
 for (int l = j; l <= dr; l++)
    w[k++] = v[l];
 for (int a = st; a <= dr; a++)
    v[a] = w[a-st];
 delete []w;
}

void merge_sort(int st, int dr, int n, int *v)
{
 if (st < dr)
    {
     int mij = st + (dr - st)/2;
     merge_sort(st, mij, n, v);
     merge_sort(mij+1, dr, n, v);
     inter(st, mij, dr, n, v);
    }
}

int main()
{
 int n,m,i,*v;
 cout << "Dati numarul elementelor primei secvente: ";
 cin >> n;
 cout << "Dati numarul elementelor celei de-a doua secvente: ";
 cin >> m;
 v = new int [n+m+1];
 cout << "Cititi elementele primei secvente:" << endl;
 for (i = 1; i <= n; i++)
    {
     cout << "v[" << i << "]=";
     cin >> v[i];
    }
 cout << "Cititi elementele celei de-a doua secvente: " << endl;
 for (i = n+1; i <= n+m; i++)
    {
     cout << "v[" << i << "]=";
     cin >> v[i];
    }
 int dim = n+m;
 merge_sort(1,dim,dim,v);
 cout << "Vectorul sortat este: ";
 for (i = 1; i <= n+m; i++)
    cout << v[i] << " ";
 delete []v;
    return 0;
}
