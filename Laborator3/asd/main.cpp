#include <iostream>
#include <string.h>


using namespace std;

class Coada;

class Nod
{
    char info;
    Nod *next;
public:
    Nod();
    friend class Coada;
    // friend Coada operator+ (Coada q,Coada c);
    // friend Coada operator- (Coada q,Coada c);
    friend Coada operator-(Coada c);
    friend Coada operator--(Coada c);
    friend istream &operator>> (istream &in, Coada &q);
    friend ostream &operator<< (ostream &out, Coada &q);
    ~Nod(){ delete next; };
};

class Coada
{
    Nod *prim;
    Nod *ultim;
public:
    Coada();
    Coada(const Coada&);
    void pop();
    void push(char);
    int isEmpty();
    int operator!=(Coada c);
    Coada operator+ (Coada c);
    Coada operator- (Coada c);
    Coada operator= (const Coada&);
    Coada operator--(int i);
    friend Coada operator-(Coada c);
    friend Coada operator--(Coada c);
    friend istream &operator>> (istream &in, Coada &q);
    friend ostream &operator<< (ostream &out, Coada &q);
    ~Coada(){ delete prim; delete ultim; };
};

class nr_ob
{
    int nr;
    Coada *v;
public:
    void modcoada(int, Coada);
    void addcoada(int,char);
    void removecoada(int);
    void citire(int);
    void afisare(int);
    Coada retcoada(int);
    int citireNrob();
    friend Coada operator-(Coada c);
    friend Coada operator--(Coada c);
    friend istream &operator>> (istream &in, Coada &q);
    friend ostream &operator<< (ostream &out, Coada &q);
    friend class Coada;
    ~nr_ob(){ delete []v; }
};

void nr_ob::modcoada(int indexcoada, Coada t)
{
    v[indexcoada] = t;
}

Coada nr_ob::retcoada(int indexcoada)
{
    return v[indexcoada];
}

void nr_ob::addcoada(int indexcoada,char val)
{
    v[indexcoada].push(val);
}

void nr_ob::removecoada(int indexcoada)
{
    v[indexcoada].pop();
}

int nr_ob::citireNrob()
{
    cin>>nr;
    v = new Coada[nr+1];
    return nr;
}

void nr_ob::citire(int indexcoada)
{
    cin >> v[indexcoada];
}

void nr_ob::afisare(int indexcoada)
{
    cout << v[indexcoada];
}

Nod::Nod()
{
    next = NULL;
    info = 0;
}

int Coada::operator!=(Coada c)
{
    Nod *cq = this->prim, *cc = c.prim;
    while (cq != NULL && cc != NULL)
    {
        if(cq->info != cc->info)
        {
            return 0;
        }
        cq = cq->next;
        cc = cc->next;
    }
    if ((cq == NULL && cc != NULL) || (cq != NULL && cc == NULL))
    {
        return 0;
    }
    return 1;
}

Coada operator-(Coada c)
{
    Coada q;
    Nod *temp = c.prim;
    while (temp != NULL)
    {
        if (temp->info >= 'a' && temp->info <= 'z')
        {
            q.push(temp->info-32);
        }
        else
        {
            q.push(temp->info+32);
        }
        temp = temp->next;
    }
    return q;
}

Coada Coada::operator--(int i)
{
    Coada q;
    Nod *temp = this->prim;
    while(temp != NULL)
    {
        q.push(temp->info-1);
        temp = temp->next;
    }
    return q;
}

Coada operator--(Coada c)
{
    Coada q;
    Nod *temp = c.prim;
    while (temp != NULL)
    {
        q.push(temp->info-1);
        temp = temp->next;
    }
    return q;
}

Coada Coada::operator+(Coada c)
{
    Coada temp;
    Nod *crt = this->prim;
    Nod *current = c.prim;
    while (crt != NULL)
    {
        temp.push(crt->info);
        crt = crt->next;
    }
    while (current != NULL)
    {

        temp.push(current->info);
        current = current->next;
    }
    return temp;
}

Coada Coada::operator-(Coada c)
{
    Coada temp;
    Nod *ctemp = this->prim, *cc = c.prim;
    while (ctemp != NULL && cc != NULL)
    {
        if (ctemp->info > cc->info)
        {
                temp.push(ctemp->info);
        }
        else
        {
                temp.push(cc->info);
        }
        ctemp = ctemp->next;
        cc = cc->next;
    }
    return temp;
}

Coada::Coada()
{
    prim = ultim = NULL;
}

Coada::Coada(const Coada &p)
{
    //prim = ultim = NULL;
    int cont = 0;
    Nod *temp = p.prim;
    Nod *temp_this;

    while(temp != NULL)
    {
        temp_this = new Nod;
        temp_this->info = temp->info;

        if(cont == 0)
        {
            prim = ultim = temp_this;
            cont++;
        }
        else
        {
            ultim->next = temp_this;
            ultim = temp_this;
        }
        temp = temp->next;
    }
}

Coada Coada::operator=(const Coada &p)
{
    while(!this->isEmpty())
    {
        this->pop();
    }
    Nod *temp = p.prim;
    while(temp != NULL)
    {
        this->push(temp->info);
        temp = temp->next;
    }

    return *this;
}

int Coada::isEmpty()
{
    return (this->prim == NULL);
}

void Coada::push(char c)
{
    Nod * current = new Nod;
    current->info = c;
    if (isEmpty())
    {
        prim = ultim = current;
    }
    else
    {
        ultim->next = current;
        ultim = current;
    }
    current->next = NULL;
}

void Coada::pop()
{
    if(isEmpty())
    {
        cout<<"Coada este goala";
        return;
    }
    Nod *temp = prim;
    prim = prim->next;
    delete temp;
}

istream &operator>> (istream &in, Coada &q)
{
    char val;
    in>>val;
    while (val != '~')
    {
        q.push(val);
        in>>val;
    }
    return in;
}

ostream &operator<< (ostream &out, Coada &q)
{
    while (!q.isEmpty())
    {
        out<<q.prim->info<<endl;
        q.pop();
    }
    return out;
}

int main()
{
    nr_ob a;
    int i,n;
    cout << "Introduceti numarul de cozi: ";
    n = a.citireNrob();
    cout << endl << "ATENTIE! ORICE COADA SE VA INCHEIA CU CARACTERUL ~" << endl;
    for( i = 1; i <= n; i++)
    {
        cout << "Introduceti elementele cozii numarul: " << i <<endl;
        a.citire(i);
    }
    int r=1;
    cout << "Meniu:"<<endl;
    cout << "1-Concatenati 2 cozi;"<<endl;
    cout << "2-Faceti diferenta intre 2 cozi;"<<endl;
    cout << "3-Afisati si goliti o coada anume;"<<endl;
    cout << "4-Schimbati caracterele mici in caractere mari sau invers intr-o coada"<<endl;
    cout << "5-Decrementati o coada"<<endl;
    cout << "6-Verificati daca 2 cozi sunt identice"<<endl;
    cout << "0-Iesiti din program;"<<endl;
    while (r)
    {
        cout << "Alegeti comanda: ";
        cin >> r;
        int x,y;
        if( r == 1 )
        {
            cout << "Introduceti indecsii cozilor de concatenat: ";
            cin >> x >> y;
            Coada t;
            t = a.retcoada(x) + a.retcoada(y);
            cout << t << endl;
        }
        else if( r == 2 )
        {
            cout << "Introduceti indecsii cozilor de scazut: ";
            cin >> x >> y;
            Coada t;
            t = a.retcoada(x) - a.retcoada(y);
            cout << t;
            cout << endl;
        }
        else if( r == 3 )
        {
            cout << "Introduceti indexul cozii de afisat si golit: ";
            cin >> x;
            cout << endl;
            a.afisare(x);
            cout << endl;
        }
        if( r == 4 )
        {
            cout << "Introduceti indexul cozii de modificat: ";
            cin >> x;
            Coada t;
            t = -a.retcoada(x);
            a.modcoada(x,t);
            cout << t << endl;
        }
        if( r == 5 )
        {
            cout << "Introduceti indexul cozii de decrementat: ";
            cin >> x;
            Coada t;
            t = --a.retcoada(x);
            a.modcoada(x,t);
            cout << t << endl;
        }
        if( r == 6 )
        {
            cout << "Introduceti indecsii cozilor de comparat: ";
            cin >> x >> y;
            int t;
            t = a.retcoada(x) != a.retcoada(y);
            if (t == 1)
            {
                cout << "Cozile sunt egale" << endl;
            }
            else
                cout << "Cozile nu sunt egale" << endl;
        }
        else if( r == 0 )
        {
            break;
        }
    }
    string sir;
    cout << "Doriti sa afisati si celelalte cozi? (da/nu)";
    cin >> sir;
    if ( sir=="da" )
    {
        for(i=1;i<=n;i++)
        {
            a.afisare(i);
        }
    }
    /*
    Coada p,k;
    p.push('c');
    p.push('c');
    p.push('c');
    p.push('c');
    k.push('c');
    k.push('c');
    k.push('c');
    k.push('c');

    //p = --p;
    //p = p--;
    int i = k != p;
    cout << i;
    //cout << k << endl << p;
    */
    return 0;
}
