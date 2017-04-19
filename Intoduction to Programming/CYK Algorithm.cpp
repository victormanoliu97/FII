#include <iostream>
#include <string.h>
#include <string>

#define MAX_CARTONASE 100
#define MAX_SIR 15

template <class T>
class Vector
{
    T *elem;
    int count;
    int capacity;
    T end;

public:

    int size () 
    {
        return count;
    }

    void resize () 
    {
        T *new_elem = new T[capacity * 2];

        for (int i = 0; i < count; i++)
        {
            new_elem[i] = elem[i];
        }
        delete[] elem;

        elem = new_elem;

        capacity *= 2;
    }

    void push_back(const T& k) 
    {
        if (count + 1 >= capacity) 
        {
            resize ();
        }
        elem[count] = k;

        count++;
    }

    void pop_back () 
    {
        if (count == 0) 
        {
            return;
        }
        elem[--count] = 0;
    }

    T& operator[] (int i)
    {
        if (i < 0 || i >= count)
        {
            return end;
        } 
        return elem[i];
    }

    void insert (Vector<T>& v) 
    {
        for (int i = 0; i < v.size (); i++) 
        {
            push_back (v[i]);
        }
    }

    void rinsert (Vector<T>& v) 
    {
        for (int i = v.size () - 1; i >= 0; i--) 
        {
            push_back (v[i]);
        }
    }

    void clear () 
    {
        count = 0;
    }

    Vector<T>() 
    {
        capacity = 1;
        count = 0;
        elem = new T[capacity];
    }

    ~Vector<T>() 
    {
        delete[] elem;
    }

    bool empty () 
    {
        return (count == 0);
    }

    Vector<T>(const Vector<T> & v) 
    {
        count = v.count;
        capacity = v.capacity;

        elem = new T[capacity];
        for (unsigned int i = 0; i < count; i++)
            elem[i] = v.elem[i];
    }

    Vector<T>& operator = (const Vector<T> & v) 
    {
        delete[] elem;
        count = v.count;
        capacity = v.capacity;

        elem = new T[capacity];
        for (unsigned int i = 0; i < count; i++)
            elem[i] = v.elem[i];
        return *this;
    }
};


template<class T1, class T2>
struct Pair {
    T1 first;
    T2 second;

    Pair<T1, T2> () {}

    Pair<T1, T2> (T1 &x, T2 &y) {
        first = x;
        second = y;
    }
};

using namespace std;

typedef struct {
    char sus;
    char jos[3];
} cartonas;

struct mutare {
    cartonas nod;
    struct mutare *urmator;
};

typedef mutare* lista;

struct rezultat {
	bool sePoate;
	int nrMutari;
	lista mutari;
};


void addLant (Vector<int*> &reguli,
        Vector<Pair<char, Pair<int, Vector<int> > > > &lant_miscari,
        Vector<int> &mutari,
        int pasi,
        char litera) {

    Pair<char, Pair<int, Vector<int> > > pr;
    pr.first = litera;
    pr.second.first = pasi;
    pr.second.second.rinsert (mutari);
    lant_miscari.push_back (pr);

	for (int i = 0; i < reguli.size (); i++) {
		if (reguli[i][2] == 0 && reguli[i][1] == litera) {
            mutari.push_back (i);
			addLant (reguli, lant_miscari, mutari, pasi + 1, reguli[i][0]);
			mutari.pop_back ();
        }
	}
}

struct stare {
    char il, l;
    int pasi, red;
    int regula;
    int k;
    int st, dr;

    stare () {
    }

    stare (char il, char l, int pasi, int red, int regula, int k, int st, int dr) {
        this->il = il;
        this->l = l;
        this->pasi = pasi;
        this->regula = regula;
        this->k = k;
        this->red = red;
        this->st = st;
        this->dr = dr;
    }
};


int add (
        int litera,
        Vector<stare> &v,
        Vector<Pair<char, Pair<int, Vector<int> > > > &lant_miscari,
        int pas,
        int k,
        int st,
        int dr,
        int regula) {
    for (int i = 0; i < lant_miscari.size (); i++) {
        v.push_back (
        stare (litera,
        lant_miscari[i].first,
        pas + lant_miscari[i].second.first,
        i,
        regula,
        k,
        st, dr));
    }
}

void combinam (Vector<stare> &dest,
        Vector<stare> &v1,
        Vector<stare> &v2,
        int lg,
        Vector<Pair<char, Pair<int, Vector<int> > > > *lant_miscari,
        Vector<int*> &reguli) {

    for (int i = 0; i < v1.size (); i++) {
        for (int j = 0; j < v2.size (); j++) {
            int pas = v1[i].pasi + v2[j].pasi;
            for (int k = 0; k < reguli.size (); k++) {
                if (reguli[k][1] == v1[i].l && reguli[k][2] == v2[j].l) {
                    add (reguli[k][0], dest, lant_miscari[reguli[k][0]], pas + 1, lg, i, j, k);
                }
            }
        }
    }
}

void construieste (int st,
    int lg,
    int index,
    Vector<stare> v[][20],
    Vector<int*> &reguli,
    Vector<Pair<char, Pair<int, Vector<int> > > > *lant_miscari,
    Vector<int> &mutari
    ) {
    int i = v[st][lg][index].red;
    stare &s = v[st][lg][index];
    mutari.insert(lant_miscari[s.il][i].second.second);

    mutari.push_back(s.regula);

    if (s.k == -1) return;

    construieste (st, s.k, s.st, v, reguli, lant_miscari, mutari);
    construieste (st + s.k, lg - s.k, s.dr, v, reguli, lant_miscari, mutari);
}
// num este numarul de reguli din a
// regula[i][0] - cu ce incepe regula
// regula[i][1] - cu ce se termina 1
// regula[i][2] - cu ce se termina 2
// ex1: A->BC
// regula[i][0] = A
// regula[i][1] = B
// regula[i][2] = C
// ex2: A->C
// regula[i][0] = A
// regula[i][1] = C
// regula[i][2] = 0
int joaca (char literaInceput, std::string end, Vector<int*> reguli, Vector<int> &mutari) {
    Vector<Pair<char, Pair<int, Vector<int> > > > lant_miscari[256];
    Vector<stare> v[20][20];

    //adaugam regulile litera->litera si recursiv
    for (int i = 0; i < reguli.size (); i++) {
        char litera = reguli[i][0];
        if (lant_miscari[litera].empty ()) {
            Vector<int> v;
            addLant (reguli, lant_miscari[litera], v, 0, litera);
        }
    }

    char S = literaInceput;
    for (int i = 0; i < end.size (); i++) {
        for (int j = 0; j < reguli.size (); j++) {
            if (reguli[j][2] == 0 && reguli[j][1] == end[i]) {
                char litera = reguli[j][0];
                add (litera, v[i][1], lant_miscari[litera], 1, -1, 1, 1, j);
            }
        }
    }

    for (int lg = 2; lg <= end.size (); lg++) {
        for (int st = 0; st <= end.size () - lg; st++) {
            v[st][lg].clear ();
            for (int k = 1; k <= lg - 1; k++) {
                combinam (v[st][lg], v[st][k], v[st+k][lg-k], k, lant_miscari, reguli);
            }
        }
    }

    int MY_INT_MAX = (1<<31)-1;
    int lg = end.size (), minPas = MY_INT_MAX, index = -1;
    for (int i = 0; i < v[0][lg].size (); i++) {
        if (v[0][lg][i].l == S && v[0][lg][i].pasi < minPas) {
            index = i;
            minPas = v[0][lg][i].pasi;
        }
    }

    if (minPas == MY_INT_MAX)
        minPas = -1;
    else {
        mutari.clear ();
        construieste (0, lg, index, v, reguli, lant_miscari, mutari);
    }
    return minPas;
}

int* creeaza_regula (char x, char y, char z) {
    int *r = new int[3];
    r[0] = x;
    r[1] = y;
    r[2] = z;
    return r;
}

rezultat mutariJoc(cartonas vecCartonase[MAX_CARTONASE],
                unsigned int nCartonase,
                char literaStart,
                char sirFinal[MAX_SIR]) {

    Vector<int*> reguli;
    for (int i = 0; i < nCartonase; i++) {
        reguli.push_back (creeaza_regula(vecCartonase[i].sus,
                            vecCartonase[i].jos[0],
                            vecCartonase[i].jos[1]));
    }

    Vector<int> mutari;
    int nrm = joaca (literaStart, sirFinal, reguli, mutari);
    rezultat r;
    if (nrm == -1) {
        r.sePoate = false;
        r.nrMutari = 0;
        r.mutari = NULL;
    }
    else 
    {
        r.sePoate = true;

        r.nrMutari = nrm;

        r.mutari = new mutare();

        lista l = r.mutari;

        l->nod = vecCartonase[mutari[0]];
        
        l->urmator = NULL;

        for (int i = 1; i < mutari.size (); i++) 
        {
            l->urmator = new mutare();

            l = l->urmator;

            l->nod = vecCartonase[mutari[i]];

            l->urmator = NULL;
        }
    }
    return r;
}