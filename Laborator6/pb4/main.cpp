#include <iostream>
#include <fstream>
using namespace std;

int main()
{
 int n,*v,q,*inc,*sf;
 int i,j,ok;
 ifstream f;
 f.open("bitone.in");
 ofstream g;
 g.open("bitone.out");
 f >> n;
 while (n < 1 || n > 1000000)
    f >> n;
 v = new int[n+1];
 for (i = 1; i <= n; i++)
     {
      f >> v[i];
      while (v[i] < -2000000000 || v[i] > 2000000000)
        f >> v[i];
     }
 f >> q;
 while (q < 1 || q > 1000000)
    f >> q;
 inc = new int[q+1];
 sf = new int[q+1];
 for (i = 1; i <= q; i++)
    {
     f >> inc[i];
     f >> sf[i];
     while (inc[i] < 1 || inc[i] > sf[i])
        f >> inc[i];
     while (sf[i] < inc[i] || sf [i] > n)
        f >> sf[i];
    }
 for (i = 1; i <= q; i++)
    {
     int secv1[100],secv2[100],poz1[100],poz2[100];
     int k=1,p=1;
     int p1=1,p2=1;
     ok = 1;
     for(j=1;j<=100;j++)
        {
            secv1[i] = 0;
            secv2[i] = 0;
        }
     if (sf[i] - inc[i] > 2)
        {
         secv1[k++] = v[inc[i]];
         poz1[p1++] = inc[i];
         for (j = inc[i]+1; j <= sf[i]; j++)
                {
                 if (secv1[k-1] == v[j] && j!=sf[i])
                     {
                         secv1[k++] = v[j];
                         poz1[p1++] = j;
                     }
                 else
                    {
                     if(secv1[k-1] == v[j] && j == sf[i])
                        {
                         if(p==1)
                            {
                                secv2[p++] = v[j];
                                poz2[p2++] = j;
                            }
                         else
                            {
                             if(secv2[p-1] >= v[j])
                              {
                                secv2[p++] = v[j];
                                poz2[p2++] = j;
                              }
                             else
                                ok = 0;
                            }
                        }
                    }
                 if (secv1[k-1] != v[j] && j!=sf[i])
                        {
                         if(secv1[k-1] < v[j])
                             {
                                 secv1[k++] = v[j];
                                 poz1[p1++] = j;
                             }
                         else
                            {
                             if (secv2[p-1] >= v[j])
                                {
                                    secv2[p++] = v[j];
                                    poz2[p2++] = j;
                                }
                             else
                                ok = 0;
                            }
                        }
                 else
                    {
                     if (secv1[k-1] != v[j] && j == sf[i])
                        {
                         if(p==1)
                            {
                                secv2[p++] = v[j];
                                poz2[p2++] = j;
                            }
                         else
                            {
                             if(secv2[p-1] >= v[j])
                              {
                                secv2[p++] = v[j];
                                poz2[p2++] = j;
                              }
                             else
                                ok = 0;
                            }
                        }
                    }
                }
         p1--;
         p2--;
         for (j=1;j<p1;j++)
            if(poz1[j+1]-poz1[j]!=1)
                ok = 0;
         for (j=1;j<p2;j++)
            if(poz2[j+1]-poz2[j]!=1)
                ok = 0;
        }
     g << ok;
    }
 f.close();
 g.close();
 delete []v;
 delete []inc;
 delete []sf;
    return 0;
}
