#include <iostream>
#include <string.h>

using namespace std;

class node
{
public:
    char info;
    node *next;
    friend class Queue;
};
class Queue
{
public:
    char aux;
    node *prim;
    node *ultim;
    int dim_max;
    int cnt;
    Queue(int maximuml)
    {
        prim=NULL;
        ultim=NULL;
        dim_max=maximuml;
        cnt=0;
    }
    virtual ~Queue()
    {
        delete []prim;
        delete []ultim;
    }
    void print()
    {
        node *temp;
        temp=prim;
        while(temp!=NULL)
        {
            cout<<temp->info<<" ";
            temp=temp->next;
        }
    }
    virtual void push(char x)
    {
        if(cnt==dim_max)
            cout<<"Coada plina!\n";
        else
        {
            node *np=new node;
            np->info=x;
            np->next=NULL;
            if(prim==NULL)
            {
                prim=ultim=np;
                ultim->next=NULL;
                cnt++;
            }
            else
            {
                ultim->next=np;
                ultim=np;
                ultim->next=NULL;
                cnt++;
            }
        }
    }
    void pop()
    {
        node *p;
        char x;
        if(prim==NULL)
            cout<<"Coada goala!\n";
        else
        {
            p=prim;
            x=p->info;
            prim=prim->next;
            cnt--;
        }
    }
    friend ostream &operator<<(ostream &output,Queue &Q);
    friend istream &operator>>(istream &input,Queue &Q);
    Queue operator=(const Queue &Q);
};
ostream &operator<<(ostream &output,Queue &Q)
{
    node *temp;
    temp=Q.prim;
    while(temp!=NULL)
    {
        cout<<temp->info<<" ";
        temp=temp->next;
    }
    while(Q.prim!=NULL)
    {
        Q.prim=Q.prim->next;
        Q.cnt--;
    }
}
istream &operator>>(istream &input,Queue &Q)
{
    input>>Q.aux;
    Q.push(Q.aux);
    return input;
}
Queue Queue::operator=(const Queue &Q)
{
    node *temp;
    delete []prim;
    prim=ultim=NULL;
    for(temp=Q.prim; temp!=NULL; temp=temp->next)
        this->push(temp->info);
    return (*this);
}
class Deque: public Queue
{
public:
    Deque(int maximum,int maxi):Queue(maximum)
    {
        prim=NULL;
        ultim=NULL;
        dim_max=maxi;
        cnt=0;
    }
    ~Deque()
    {
       delete []prim;
       delete []ultim;
    }
    void push(char x,int ok)
    {
        if(ok==1)
        {
            node *np=new node;
            np->info=x;
            if(prim==NULL)
            {
                prim=np;
                ultim=np;
                cnt++;
            }
            np->next=prim;
            prim=np;
            cnt++;
        }
        if(ok==2)
        {
            node *np=new node;
            np->info=x;
            np->next=NULL;
            if(prim==NULL)
            {
                prim=ultim=np;
                ultim->next=NULL;
                cnt++;
            }
            else
            {
                ultim->next=np;
                ultim=np;
                ultim->next=NULL;
                cnt++;
            }
        }

    }
    void pop(int ok)
    {
        if(ok==1)
        {
            node *p;
            char x;
            if(prim==NULL)
                cout<<"Coada goala!\n";
            else
            {
                p=prim;
                x=p->info;
                prim=prim->next;
                cnt--;
            }
        }
        if(ok==2)
        {
            node *temp=new node;
            node *p2=new node;
            p2=prim;
            if(prim==ultim)
            {
                cout<<"Lista goala!\n";
                prim=NULL;
                ultim=NULL;
            }
            while(p2->next!=ultim)
            {
                p2=p2->next;
            }
            temp=ultim;
            ultim=p2;
            p2->next=NULL;
        }
    }
    friend istream &operator>>(istream &input,Deque &D);
   Deque operator=(const Deque &D);
};
Deque Deque::operator=(const Deque &D)
{
    node *temp;
    delete []prim;
    prim=ultim=NULL;
    for(temp=D.prim; temp!=NULL; temp=temp->next)
        this->push(temp->info,1);
    return (*this);
}
istream &operator>>(istream &input,Deque &D)
{
    int ok;
    input>>D.aux;
    input>>ok;
    D.push(D.aux,ok);
    return input;
}
int main()
{
    Deque D1(555,11);
    int n;
    cout<<"Cate obiecte sa fie?\n";
    cin>>n;
    cout<<"1 pentru inceput!\n2 pentru sfarsit!\n";
    cout<<"Prima data litera, iar dupa flag-ul!";
    for(int i=0;i<n;i++)
        cin>>D1;
    cout<<"***Am dat pop la inceput si la final***\n";
    D1.pop(1);
    D1.pop(2);
    D1.print();
}
