#include <iostream>

using namespace std;

struct Node
{
    int casos;
    int id;
};

class heap
{
    private:
        Node* hp;
        int sizehp;
        int size;
        int c_total;
    public:
        heap();
        Node inserirElemento(int id, int C, int* aux);
        Node deletarElemento(int id, int* aux);
        int decrementarRaiz(int* aux);
        int atualizarCasos(int id, int c, int* aux);
        int distribuicao(int pay, int* aux);
        int obtemTotal();
        void printarHeap(int* aux, int j);
};

int max(int a, int b)
{
    if(a>=b){
        return a;
    }else
    {
        return b;
    }
}

void bubbleup(Node* heap, int i, int* aux)
{

    Node temp;

    while (i > 0 && (heap[i].casos > heap[(i-1)/2].casos||(heap[i].casos == heap[(i-1)/2].casos && heap[i].id > heap[(i-1)/2].id)))
    {
        aux[heap[i].id] = (i-1)/2;
        aux[heap[(i-1)/2].id] = i;

        temp = heap[i];
        heap[i] = heap[(i-1)/2];
        heap[(i-1)/2] = temp;
        i = (i-1)/2;
    }
}

void bubbledown(Node* heap, int i, int heapsize, int* aux)
{

    Node temp;
    int flag = 1, flagd = 1; //flag: se casos pai == max(casos filho) e id pai > id max filho, nao troca
                             //flagd: se !E filho esquerda e !E filho direita, nao troca
    int j = 0;
    int cmax;

    //definindo o maior filho (se nao tiver mais filhos, nao vai ter troca)
    if (2*i+1 < heapsize && 2*i+2 < heapsize)
    {
        cmax = max(heap[2*i+1].casos,heap[2*i+2].casos);
    }else if (2*i+1 < heapsize)
    {
        cmax = heap[2*i+1].casos;
    }else if (2*i+2 < heapsize)
    {
        cmax = heap[2*i+2].casos;
    }else{
        flagd = 0;
    }
    
    while ((2*i+1 < heapsize || 2*i+2 < heapsize) && heap[i].casos <= cmax && flag==1 && flagd==1)
    {

        if(heap[i].casos == cmax){

            if (cmax == heap[2*i+1].casos && (2*i+2 < heapsize && cmax == heap[2*i+2].casos))
            {
                if (heap[2*i+1].id > heap[2*i+2].id)
                {
                    if (heap[i].id > heap[2*i+1].id)
                    {
                        flag = 0;
                    }
                }else
                {
                    if (heap[i].id > heap[2*i+2].id)
                    {
                        flag = 0;
                    }
                }
            }else if(cmax == heap[2*i+1].casos)
            {
                if (heap[i].id > heap[2*i+1].id)
                {
                    flag = 0;
                }
                
            }else if(cmax == heap[2*i+2].casos)
            {
                if (heap[i].id > heap[2*i+2].id)
                {
                    flag = 0;
                }   
            }
        }

        if (cmax == heap[2*i+1].casos && (2*i+2 < heapsize && cmax == heap[2*i+2].casos))
        {
            if (heap[2*i+1].id > heap[2*i+2].id)
            {
                j = 2*i+1;
            }else
            {
                j = 2*i+2;
            }
            
        }else if(cmax == heap[2*i+1].casos)
        {
            j = 2*i+1;
            
        }else if(cmax == heap[2*i+2].casos)
        {
            j = 2*i+2;
            
        }

        if (flag == 1)
        {
            aux[heap[i].id] = j;
            aux[heap[j].id] = i;

            temp = heap[i];
            heap[i] = heap[j];
            heap[j] = temp;
            i = j;

            if (2*i+1 < heapsize && 2*i+2 < heapsize)
            {
                cmax = max(heap[2*i+1].casos,heap[2*i+2].casos);
            }else if (2*i+1 < heapsize)
            {
                cmax = heap[2*i+1].casos;
            }else if (2*i+2 < heapsize)
            {
                cmax = heap[2*i+2].casos;
            }else
            {
                flagd = 0;
            }
        }
    }
}

Node heap::inserirElemento(int id, int C, int* aux)
{
    if (this->size==this->sizehp)
    {
        this->hp = (Node *) realloc(this->hp,2*this->sizehp*sizeof(Node));
        if (this->hp == nullptr){exit(1);}

        this->sizehp = 2*this->sizehp;
        for (int i = this->size; i < 2*this->size ; i++)
        {
            this->hp[i].casos = -1;
            this->hp[i].id = -1;
        }
        
    }

    this->hp[this->size].id = id;
    this->hp[this->size].casos = C;
    this->c_total += C;
    this->size += 1;

    aux[this->hp[this->size-1].id] = this->size-1;

    bubbleup(this->hp,this->size-1,aux);

    return this->hp[0];
}

Node heap::deletarElemento(int id, int*aux)
{
    Node ax;
    int n = this->hp[this->size-1].id;

    ax = this->hp[aux[id]];
    this->c_total -= ax.casos;
    this->hp[aux[id]] = this->hp[this->size-1];
    
    ax.casos = -1;
    ax.id = -1;
    this->hp[this->size-1] = ax;
    this->size -= 1;

    aux[n] = aux[id];

    if (aux[id] != 0 && this->hp[aux[id]].casos >= this->hp[(aux[id]-1)/2].casos)
    {
        if (this->hp[aux[id]].casos == this->hp[(aux[id]-1)/2].casos)
        {
            if (this->hp[aux[id]].id > this->hp[(aux[id]-1)/2].id)
            {
                bubbleup(this->hp,aux[id],aux);
            }else
            {
                bubbledown(this->hp,aux[id],this->size, aux);
            }  
        }else
        {
            bubbleup(this->hp,aux[id],aux);
        }
    }else
    {
        bubbledown(this->hp,aux[id],this->size, aux);
    }

    aux[id] = -1;

    return this->hp[0];
}

int heap::decrementarRaiz(int* aux)
{
    if (this->size>0 && this->hp[0].casos>0)
    {
        this->hp[0].casos -= 1;
        this->c_total -= 1;
        bubbledown(this->hp,0,this->size, aux);

        return 1;
    }else
    {
        return 0;
    }
}

int heap::atualizarCasos(int id, int C, int* aux)
{
    int cnew;

    if (C > 0)
    {
        this->hp[aux[id]].casos += C;
        cnew = this->hp[aux[id]].casos;
        
        this->c_total += C;
        bubbleup(this->hp, aux[id], aux);
    }else
    {
        if(this->hp[aux[id]].casos>=(-1*C))
        {
            this->hp[aux[id]].casos += C;
            cnew = this->hp[aux[id]].casos;
            this->c_total += C;
            bubbledown(this->hp, aux[id], this->size, aux);
        }else
        {
            this->c_total -= this->hp[aux[id]].casos;
            this->hp[aux[id]].casos = 0;
            cnew = this->hp[aux[id]].casos;
            bubbledown(this->hp, aux[id], this->size, aux);
        }
    }

    return cnew;
}

int heap::distribuicao(int pay, int* aux)
{
    int p = 0;

    for (int i = 0; i < pay; i++)
    {
        if(this->decrementarRaiz(aux)==1)
        {
            p += 1;
        }else
        {
            i = pay;
        };
    }
    
    return p;
}

int heap::obtemTotal()
{
    return this->c_total;
}

void heap::printarHeap(int* aux, int j)
{
    for (int i = 0; i < this->sizehp; i++)
    {
        cout<<i<<" "<<this->hp[i].casos<<" "<<this->hp[i].id<<"||";
    }
    cout<<endl;
    cout<<"HeapSize: "<<this->size<<" VectorSize: "<<this->sizehp<<" Casos: "<<this->c_total<<endl;

    for (int i = 0; i < j; i++)
    {
        cout<<i<<" "<<aux[i]<<"||";
    }
    cout<<endl;
}


heap::heap()
{
    this->hp = (Node *) malloc(1*sizeof(Node));
    if (this->hp == nullptr){exit(1);}

    this->hp[0].id = -1;
    this->hp[0].casos = -1;
    this->sizehp = 1;
    this->size = 0;
    this->c_total = 0;
}

int main()
{
    heap arvore;
    int qnt_elementos, casos, i;
    int *aux = nullptr;
    string comando;

    int h, c, r;
    int p, cnew;
    Node node_aux;

    cin>>qnt_elementos;

    for (i = 0; i < qnt_elementos; i++)
    {
        aux = (int *) realloc(aux,(i+1)*sizeof(int));
        if (aux == nullptr){exit(1);}
        cin>>casos;
        node_aux = arvore.inserirElemento(i,casos,aux);
    }

    cin>>comando;
    
    while (comando.compare("END") != 0)
    {
        if (comando.compare("NEW") == 0)
        {
            cin>>h;
            cin>>c;
            
            aux = (int *) realloc(aux,(i+1)*sizeof(int));
            if (aux == nullptr){exit(1);}
            
            i++;

            node_aux = arvore.inserirElemento(h, c, aux);

            cout<<node_aux.id<<" "<<node_aux.casos<<endl;
        }else if(comando.compare("DEL") == 0)
        {
            cin>>h;
            node_aux = arvore.deletarElemento(h, aux);

            cout<<node_aux.id<<" "<<node_aux.casos<<endl;
        }else if(comando.compare("IN") == 0)
        {
            cin>>h;
            cin>>c;
            cnew = arvore.atualizarCasos(h, c, aux);

            cout<<cnew<<endl;
        }else if(comando.compare("OUT") == 0)
        {
            cin>>h;
            cin>>c;
            c *= -1;
            cnew = arvore.atualizarCasos(h, c, aux);

            cout<<cnew<<endl;
        }else if(comando.compare("PAY") == 0)
        {
            cin>>r;
            p = arvore.distribuicao(r, aux);
            
            cout<<p<<endl;
        }else if (comando.compare("PRINT")==0)
        {
            arvore.printarHeap(aux,i);
        }
        
        cin >> comando;
    }
    
    cout<<arvore.obtemTotal()<<endl;

    free(aux);

    return 0;
}