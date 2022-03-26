#include <iostream>

using namespace std;

struct Item
{
    int n;
    int t;
};

struct Node
{
    Item item;
    struct Node *prox;
};

class Lista
{
    private:
        Node *head;

    public:
        Lista();
        Node *listPos(int pos);
        Node *listFind(Item val);
        Node *listInsert(Node *cur,Item val);
        Item listDelete(Node *cur);
        void printList();
        Node *returnHead();
};

class Fila
{
    private:
        Lista fila;
        Node *head;
        Node *tail;
    public:
        Fila();
        void enfileirar(Item val);
        Item desenfileirar();
        Node *returnhead();
};

class Pilha
{
    private:
        Lista pilha;
        Node *head;
    public:
        Pilha();
        void empilhar(Item val);
        Item desempilhar();
};

class ListaRotativa
{
    private:
        Lista listarotativa;
        int tam;
    public:
        ListaRotativa();
        void adicionar(Item val,Node *cur);
        Item retirar(Node *cur);
        Node *encontrar(Item val);
        void rotacionar();
        int retornarTam();
        Node *returnHead();
};

ListaRotativa::ListaRotativa()
{
    this->listarotativa = Lista();
    Node *head;
    head = this->listarotativa.returnHead();
    head->prox = head;
    this->tam = 0;
}

void ListaRotativa::adicionar(Item val,Node *cur)
{
    this->listarotativa.listInsert(cur,val);
    this->tam++;
}

Item ListaRotativa::retirar(Node *cur)
{
    Item val;
    val.n = -2;
    val.t = -1;
    if(cur->prox->item.n!=-1)
    {
        val = this->listarotativa.listDelete(cur);
        this->tam--;
    }
    return val;
}

Node *ListaRotativa::encontrar(Item val)
{
    Node *cur = this->listarotativa.listFind(val);

    return cur;
}

void ListaRotativa::rotacionar()
{
    Node *head;
    Node *ultimo;
    Node *penultimo;
    Item i;
    i.n = -1;
    i.t = -1;
    head = this->listarotativa.returnHead();
    ultimo = this->listarotativa.listFind(i);
    penultimo = this->listarotativa.listFind(ultimo->item);
    if(this->retornarTam()>1)
    {
        ultimo->prox = head->prox;
        penultimo->prox = head;
        head->prox = ultimo;
    }

}

int ListaRotativa::retornarTam()
{
    return this->tam;
}

Node *ListaRotativa::returnHead()
{
    return this->listarotativa.returnHead();
}

Pilha::Pilha()
{
    this->pilha = Lista();
    this->head = this->pilha.returnHead();
}

void Pilha::empilhar(Item val)
{
    this->head = this->pilha.listInsert(this->head,val);
}

Item Pilha::desempilhar()
{
    Item val;
    val = this->pilha.listDelete(this->head);
    return val;
}

Fila::Fila()
{
    this->fila = Lista();
    this->head = this->fila.returnHead();
    this->tail = this->fila.returnHead();
}

void Fila::enfileirar(Item valor)
{
    this->tail = this->fila.listInsert(this->tail,valor)->prox;
}

Item Fila::desenfileirar()
{
    Item val;
    val = this->fila.listDelete(this->head);
    return val;
}

Node *Fila::returnhead()
{
    return this->head;
}

Lista::Lista()
{
    this->head = new Node;
    this->head->prox = nullptr;
    this->head->item.n = -1;
    this->head->item.t = -1;
}

Node *Lista::listPos(int pos)
{
    Node *cur = this->head;
    int i = 0;
    while (i<pos&&cur->prox!=nullptr)
    {
        cur = cur->prox;
        i++;
    }
    return cur;
}

Node *Lista::listFind(Item val)
{
    Node *cur = this->head;
    while (cur->prox!=nullptr&&cur->prox->item.n!=val.n)
    {
        cur = cur->prox;
    }
    return cur;
}

Node *Lista::listInsert(Node *cur, Item val)
{
    Node *p = new Node;
    p->prox = cur->prox;
    cur->prox = p;
    p->item = val;

    return cur;
}

Item Lista::listDelete(Node *cur)
{
    Item val;
    val.n = 666;
    val.t = -1;
    Node *p;
    if(cur->prox!=nullptr&&cur!=nullptr)//para confirmar que o dado de entrada eh valido
    {
        val = cur->prox->item;
        p = cur->prox;
        cur->prox = cur->prox->prox;
    }
    delete(p);

    return val;
}

void Lista::printList()
{
    Node *p = this->head;
    cout<<"inicio"<<endl;
    int i = 0;
    while (p->prox!=nullptr&&i<100)
    {
        p = p->prox;
        cout<<"N: "<<p->item.n<<"T: "<<p->item.t<<endl;
        i++;
    }
    cout<<"fim"<<endl;
}

Node *Lista::returnHead()
{
    return this->head;
}

void loader(Fila &in,Item item)
{
    in.enfileirar(item);
}

Item unloader(Pilha &out)
{
    Item item;
    item = out.desempilhar();
    return item;
}

void scheduler(Fila &in, Pilha &out, ListaRotativa &ccw)
{
    Node *head;
    head = ccw.returnHead();
    Item item;
    if(head->prox->item.t==0)
    {
        item = ccw.retirar(head);
        out.empilhar(item);
    }
    if(in.returnhead()->prox!=nullptr)
    {
        item = in.desenfileirar();
        ccw.adicionar(item,head);
    }
}

Item processor(ListaRotativa &ccw,int k)
{
    Node *node;
    Item item;
    item.n = -1;
    item.t = -1;
    node = ccw.encontrar(item);
    if(node->item.n>=0)
    {
        node->item.t -= k;
        if(node->item.t < 0)
            node->item.t=0;
        item = node->item;
    }

    return item;
}

Item ciclo(Fila &in, Pilha &out, ListaRotativa &ccw, int k)
{
    Item item;

    scheduler(in,out,ccw);
    item = processor(ccw,k);
    ccw.rotacionar();

    return item;
}

int main()
{
    Fila I = Fila();
    Pilha O = Pilha();
    ListaRotativa W = ListaRotativa();

    int k,n=-1,t=-1;
    string comando;
    Item item;

    cin>>k;
    int i = 0;
    while (comando.compare("END")!=0)
    {   
        cin>>comando;
        if(comando.compare("LOAD")==0)
        {
            cin>>n;
            cin>>t;
            item.n = n;
            item.t = t;
            loader(I,item);
        }else if (comando.compare("PROC")==0)
        {
            /*processar dados*/
            item = ciclo(I,O,W,k);
            cout<<"PROC "<<item.n<<" "<<item.t<<endl;
        }else if(comando.compare("UNLD")==0)
        {
            /*descarregar dados*/
            item = unloader(O);
            cout<<"UNLD "<<item.n<<endl;
        }else if(comando.compare("END")!=0)
        {
            cout<<"entrada invalida"<<endl;
        }
    } 
    return 0;
}