#include <iostream>

using namespace std;

struct node
{
    int x, y;
    int id;
    int peso;
    node *next;
};


class grafo
{
private:
    node *g;
    int qnt_nos;
    int *d_k;
    int *d_k_1;
    int *f;
    int flag;

public:
    grafo(int qnt);
    void criarFase();
    void bellmanFord(int s);
    void printarCaminhoMin(int s, int d);
};

grafo::grafo(int qnt)
{
    this->g = (node *) malloc(qnt*sizeof(node));
    this->d_k = (int *) malloc(qnt*sizeof(int));
    this->d_k_1 = (int *) malloc(qnt*sizeof(int));
    this->f = (int *) malloc(qnt*sizeof(int));
    this->qnt_nos = qnt;
    this->flag = 0;
}

void grafo::criarFase()
{
    int x, y;

    for (int i = 0; i < this->qnt_nos; i++)
    {
        cin>>x;
        cin>>y;
        this->g[i].id = i;
        this->g[i].x = x;
        this->g[i].y = y;
        this->g[i].peso = -999;
        this->g[i].next = nullptr;
        this->d_k[i] = 9999;
        this->d_k_1[i] = 9999;
        this->f[i] = -1; 
    }
    
    int M, j;

    cin>>M;

    for (int i = 0; i < M; i++)
    {
        cin>>j;
        this->g[j].peso = -1;
    }
    
    int Dj, id;
    node *head;
    node *prox;

    for (int i = 0; i < (this->qnt_nos); i++)
    {
        cin>>Dj;
        
        head = new node;
        head->next = nullptr;

        prox = head;
        for (int j = 0; j < Dj; j++)
        {
            cin>>id;

            node *no;
            no = (node *) malloc(1*sizeof(node));

            no->next = nullptr;
            no->id = id;
            no->x = this->g[id].x;
            no->y = this->g[id].y;
            if (this->g[id].peso == -1)
            {
                no->peso = -1*((no->x-this->g[i].x)*(no->x-this->g[i].x) + (no->y-this->g[i].y)*(no->y-this->g[i].y));
            }else
            {
                no->peso = (no->x-this->g[i].x)*(no->x-this->g[i].x) + (no->y-this->g[i].y)*(no->y-this->g[i].y);
            }
            
            prox->next = no;
            prox = no;
        }
        this->g[i].next = head->next;
    }
}

int tam(int *antecessores, int id, int iter_max)
{
    int antecessor, qnt = 0;

    antecessor = id;
    qnt += 1;
    int contador=0;

    while (antecessor != -1 && contador<=iter_max)
    {
        antecessor = antecessores[antecessor];
        qnt += 1;
        contador += 1;
    }
    if (contador > iter_max)//loop
    {
        return -1;
    }
    
    
    return qnt;
}

void grafo::bellmanFord(int s)
{
    this->d_k_1[s] = 0;

    node *p;
    int id, peso, tam1, tam2;

    for (int i = 1; i < this->qnt_nos; i++)
    {
        this->d_k = this->d_k_1;
        for (int j = 0; j < this->qnt_nos; j++)
        {
            p = this->g[j].next;
            while (p != nullptr)
            {
                id = p->id;
                peso = p->peso;
                if (this->d_k_1[j] + peso < this->d_k[id])
                {
                    this->d_k[id] = this->d_k_1[j] + peso;
                    this->f[id] = j;
                }else if (this->d_k_1[j] + peso == this->d_k[id])
                {
                    tam1 = tam(this->f,j, this->qnt_nos);
                    tam2 = tam(this->f,this->f[id],this->qnt_nos);
                    
                    if (tam1<=tam2&&tam1!=-1&&tam2!=-1)
                    {   
                        if (tam1<tam2)
                        {
                            this->d_k[id] = this->d_k_1[j] + peso;
                            this->f[id] = j;
                        }else
                        {
                            if (j<f[id])
                            {
                                this->d_k[id] = this->d_k_1[j] + peso;
                                this->f[id] = j;
                            }
                        }
                    }
                    
                }
                
                p = p->next;
            }
        }
        this->d_k_1 = this->d_k;   
    }
    for (int j = 0; j < this->qnt_nos; j++)
    {
        p = this->g[j].next;
        while (p != nullptr)
        {
            id = p->id;
            peso = p->peso;
            if (this->d_k_1[j] + peso < this->d_k[id])
            {
                this->flag = 1;
            }
            p = p->next;
        }
        
    }
    
}

void grafo::printarCaminhoMin(int s, int d)
{
    this->bellmanFord(s);
    int gasto, antecessor, tam_caminho = 0;
    int caminho[this->qnt_nos];

    if (this->flag == 1)
    {
        cout<<"LOOP"<<endl;
    }else
    {
        gasto = this->d_k[d];
        antecessor = d;
        caminho[tam_caminho] = antecessor;
        tam_caminho += 1;

        while (antecessor != s)
        {
            antecessor = this->f[antecessor];
            caminho[tam_caminho] = antecessor;
            tam_caminho += 1;
        }
        
        cout<<gasto<<" ";

        for (int i = tam_caminho-1; i > 0; i--)
        {
            cout<<caminho[i]<<" ";
        }
        cout<<caminho[0]<<endl;
    }
}


int main()
{
    int T, N;
    
    cin>>T;

    for (int i = 0; i < T; i++)
    {
        cin>>N;
        grafo g = grafo(N);
        g.criarFase();

        g.printarCaminhoMin(0,N-1);
    }
    
    return 0;
}