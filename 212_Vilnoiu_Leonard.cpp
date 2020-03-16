#include <iostream>

using namespace std;

class Vector{

private:
    int v[100], n;
public:
        Vector(int n = 0){
            this->n=n;
        }
        void initnr(int nr,int val){
            int i;
            this->n=nr;
            for(i = 0; i < nr; i++)
                this->v[i] = val;
        }
        Vector(Vector& v){
            int i;
            for(i=0;i<n;i++)
                this->v[i]= v.v[i];
            this->n = v.n;
        }
        ~Vector(){
            n = 0;
        }
        Vector &operator =(Vector &a){
            int i;
            for(i=0;i<n;i++)
                this->v[i]= a.v[i];
            this->n = a.n;
        }
        int sumaelem(){
            int i,s=0;
            for(i=0;i<n;i++)
                s+=this->v[i];
            return s;
        }
        int maxpoz(){
            int vmax,poz,i;
            vmax=this->v[0];
            poz=0;
            for(i=1;i<n;i++)
                if(this->v[i]>vmax){
                    vmax=this->v[i];
                    poz=i;
                }
            return poz;
        }
        void sortare(){
            int i,j,aux;
            for(i=0;i<n-1;i++)
                for(j=i+1;j<n;j++)
                    if(this->v[i]>this->v[j])
                    {
                        aux=this->v[i];
                        this->v[i]=this->v[j];
                        this->v[j]=aux;
                    }
        }
        void afisare(ostream &out){
            for(int i=0;i<n;i++)
                out<<this->v[i]<<" ";
        }
        void citire(istream &f){
            for(int i=0;i<n;i++)
                f>>this->v[i];
        }
        friend istream &operator>>(istream &in, Vector &v){
            v.citire(in);
        }
        friend ostream &operator<<(ostream &out, Vector &v){
            v.afisare(out);
        }
        int operator[](int index){
            return this->v[index];
        }
        void setVal(int nr){
            n = nr;
        }
        int getVal(){
            return n;
        }

};


int main()
{
    int n, Optiune,val,nr;
    cout<<"Numarul de elemnte este: "<<endl;cin>>n;
    Vector a(n);
    cout<<"Vector citit pentru a evita selectarea optiunilor care apeleaza metodele inainte de a citi vectorul:"<<endl;cin>>a;
    cout<<"\nVectorul este: "<<a;
    cout<<"\n";
    cout<<"Optiunile sunt: "<<endl;
    cout<<"1. Citirea unui nou vector."<<endl;
    cout<<"2. Afisarea vectorului actual."<<endl;
    cout<<"3. Suma elementelor vectorului"<<endl;
    cout<<"4. Elementul de valoare maxima al vectorului si pozitia acestuia."<<endl;
    cout<<"5. Sortarea crescatoare a vectorului"<<endl;
    cout<<"6. Reinitializarea vectorului cu o valoare aleasa."<<endl;
    cout<<"0. Exit.";
    cout<<"\n";
    while(1){
        cout<<"Optiunea este numarul: "<<endl;cin>>Optiune;
        switch(Optiune){
        case 0:
            break;
        case 1:
            cout<<"Numarul de elemente: ";cin>>n;
            a.setVal(n);
            cout<<"Vectorul citit este: "<<endl;
            cin>>a;
            cout<<"Vectorul actual este: "<<a;
            cout<<"\n";
            break;
        case 2:
            cout<<"Vectorul actual este: "<<a;
            cout<<"\n";
            break;
        case 3:
            cout<<"Suma elementelor vectorului actual este: "<<a.sumaelem()<<endl;
            break;
        case 4:
            cout<<"Elementul de valoare maxima "<<a[a.maxpoz()]<<" se afla pe pozitia "<<a.maxpoz()<<" in vector."<<endl;
            break;
        case 5:
            a.sortare();
            cout<<"Vectorul dupa sortarea crescatoare este: "<<a;
            cout<<"\n";
            break;
        case 6:
            cout<<"Numarul de elemente: "<<endl;cin>>nr;
            cout<<"Valoarea elementelor: "<<endl;cin>>val;
            a.initnr(nr,val);
            cout<<"Vectorul reinitializat este: "<<a;
            cout<<"\n";
            break;
        }
        if(Optiune==0)
            break;
    }
}
