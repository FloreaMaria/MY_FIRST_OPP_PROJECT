#include <bits/stdc++.h>

using namespace std;


class nod
{

    char info;
    nod *next;

public:

    nod();
    nod(char info, nod *next);
    ~nod() = default;

    char getinfo()
    {
        return this -> info;
    }
    nod *getnext()
    {
        return this -> next;
    }

    void SetNext(nod* const&);

};

nod::nod()
{
    this -> next = NULL;
    this -> info = 0;
    ///cout << "S-a apelat constructorul clasei nod" << "\n";
}

nod::nod(char info, nod *next)
{
    this -> info = info;
    this -> next = next;
}

void nod::SetNext(nod* const& a)
{
    this -> next = a;
}


class Coada_de_caractere
{
    nod *n1;    /// primul element al cozii
    nod *n2;    /// ultimul element al cozii
public:

    Coada_de_caractere();
    ~Coada_de_caractere();
    Coada_de_caractere(const Coada_de_caractere & );


    void Push(char x);
    void Pop();
    int IsEmpty();
    void Afisare();
    void Afisare_Metoda();
    static void Metoda();

    /// getteri

    nod *getn1() const
    {
        return this -> n1;
    }
    nod *getn2() const
    {
        return this -> n2;
    }

    friend ostream& operator << (ostream&,  Coada_de_caractere&);
    friend istream& operator >> (istream&, Coada_de_caractere&);
    friend Coada_de_caractere operator + (const Coada_de_caractere&, const Coada_de_caractere&);
    friend Coada_de_caractere operator - (const Coada_de_caractere&, const Coada_de_caractere&);

};


Coada_de_caractere::Coada_de_caractere()
{
    this -> n1 = NULL;
    this -> n2 = NULL;

    ///cout << "S-a apelat constructorul fara parametri al cozii" << "\n";
}


Coada_de_caractere::~Coada_de_caractere()
{
    if(n1 != NULL)

    {
        while(n1 != NULL)
        {
            nod *temp = n1;
            n1 = n1 -> getnext();
            delete temp;
        }
    }

    ///std::cout << "S-a apelat destructorul cozii" << "\n";

}



Coada_de_caractere::Coada_de_caractere(const Coada_de_caractere &Coada)
{

    if(Coada.n1 == NULL)
    {
        n1 = NULL;
        n2 = NULL;
    }
    else
    {
        n1 = NULL;
        char num;
        nod *temp;
        temp = Coada.getn1();
        while(temp != NULL)
        {
            num = temp -> getinfo();
            Push(num);
            temp = temp -> getnext();

        }
        n2 = Coada.getn2();
    }
    ///cout<<"se copiaza\n\n";

}

ostream& operator << (ostream& c,  Coada_de_caractere& A)
{
    nod *x = A.getn1();
    if(x == NULL)
    {
        c << "Nu sunt elemente in coada \n\n";
        return c;
    }
    c << "Afisarea si stergerea din memorie a cozii caracter cu caracter : \n\n";

    while(x != NULL)
    {
        c << x -> getinfo() <<"  ->  S-a distrus acest nod \n";
        x = x -> getnext();
        A.Pop();

    }
    return c;

}

istream& operator >> (istream& f, Coada_de_caractere& A)
{

    char x;
    int numar_caractere;

    cout << "\n" << "Introduceti numarul de caractere ale cozii:  ";

    f >> numar_caractere;

    cout << "\nIntroduceti caracterele in coada: \n";

    while(numar_caractere != 0)
    {
        f >> x;
        A.Push(x);
        numar_caractere --;
    }
    return f;
}


Coada_de_caractere operator +(const Coada_de_caractere& A, const  Coada_de_caractere& B)
{
    /**
        metoda publica pentru concatenarea a doua cozi de caractere,
        obtinand o alta coada de caractere, implementata prin supraincarcarea operatorului +;
    */

    nod *x;
    nod *y;
    x = A.getn1();
    y = B.getn1();

    Coada_de_caractere C;

    for(nod *i = x; i != NULL; i = i -> getnext())
        C.Push(i -> getinfo());

    for(nod*i = y; i != NULL; i = i -> getnext())
        C.Push( i -> getinfo());
    return C;

}


Coada_de_caractere operator -(const Coada_de_caractere& A, const Coada_de_caractere& B)
{
    /**
        metoda publica, realizata prin supraincarcarea operatorului -,
        care sa considere doua cozi și sa elimine, concomitent,
        elementele din ambele cozi adaugand caracterul ce are codul ASCII mai mare într-o noua coada,
        ca în exemplul de mai jos:

        Coada_de_caractere C1,C2;
        C1 = {E,X,A,M,E,N}; C2 = {P,O,O,L,A,B,O,R,A,T,O,R}	C1 - C2 = {P,X,O,M,E,N}.

    */

    Coada_de_caractere C;
    nod *x, *y;

    x = A.getn1();
    y = B.getn1();

    int x1, y1;

    while(x != NULL && y != NULL)
    {
        x1 = x -> getinfo();
        y1 = y -> getinfo();

        if(x1 > y1)
            C.Push(x -> getinfo());
        else
            C.Push(y -> getinfo());

        x = x -> getnext();
        y = y -> getnext();
    }
    return C;
}


void Coada_de_caractere::Push(char x)
{
    nod *nnou = new nod(x, NULL);

    if (n1 == NULL)
    {
        n1 = nnou;
        n2 = nnou;
    }
    else
    {
        n2 -> SetNext(nnou);
        n2 = nnou;
    }
}


void Coada_de_caractere::Pop()
{
    if (n1 != NULL)
    {
        nod *aux = n1 -> getnext();
        delete n1;
        n1 = aux;
    }
}


int Coada_de_caractere::IsEmpty()
{
    if (n1 == NULL)
        return 0;
    return 1;
}


void Coada_de_caractere::Afisare()
{

    if (n1 == NULL)
        cout << "Coada nu are elemente de afisat\n";
    else
    {
        cout << "Elementele cozii sunt: ";

        for (nod *x = n1; x != NULL; x = x -> getnext())
        {
            cout << x -> getinfo();
        }
        cout << "\n";

    }
}
void Coada_de_caractere::Afisare_Metoda()
{
    if( n1 == NULL)
        cout << "Coada este vida \n";
    else
    {
        for (nod *x = n1; x != NULL; x = x -> getnext())
        {
            cout << x -> getinfo();
        }
        cout << "\n";
    }
}

void Coada_de_caractere::Metoda()
{
    int n;
    cout << "< Introduceti datele a n obiecte >\n\n";
    cout << "Numarul de obiecte ale clasei: ";

    cin >> n;
    cout << "\n";

    vector <Coada_de_caractere> A;
    cout << "Introduceti " << n <<" obiecte: " << "\n";

    for(int i = 1; i <= n; i++)
    {
        Coada_de_caractere C;
        cin >> C;
        A.push_back(C);
    }
    cout << "Cele " << n <<" obiecte sunt : \n";
    for(auto it: A)
    {
        it.Afisare_Metoda();

    }
}

int main()
{
    Coada_de_caractere::Metoda();

    /**Coada_de_caractere C;
    C.Push('A');
    C.Push('B');
    C.Push('C');
    C.Push('D');

    if(C.IsEmpty() == 0)
        cout << "Coada este vida\n\n";
    else
        cout << "Coada nu este vida\n\n";

    C.Pop();
    C.Pop();
    C.Afisare();
    C.Push('B');
    C.Afisare();
    C.Pop();
    C.Pop();

    if(C.IsEmpty() == 0)
        cout << "Coada este vida\n\n";
    else
        cout << "Coada nu este vida\n\n";

    */
    cout << "\n\n" << "< Ilustrarea supraincarcarii operatorilor > \n\n";

    cout << "\n\n" << "Supraincarcarea operatorului '+' : \n\n";


    cout << "Coada A : \n";
    Coada_de_caractere A;
    cin >> A;

    cout << "Coada B : \n";
    Coada_de_caractere B;
    cin >> B;

    Coada_de_caractere N = (A + B);
    N.Afisare();
    cout << "\n" << N << "\n\n";

    cout << "Supraincarcarea operatorului '-' :\n\n";

    cout << "Coada A : \n";
    Coada_de_caractere First;
    cin >> First;

    cout << "Coada B : \n";
    Coada_de_caractere Second;
    cin >> Second;

    Coada_de_caractere M = (First - Second);
    M.Afisare();
    cout << "\n" << M << "\n\n";


    return 0;

}
