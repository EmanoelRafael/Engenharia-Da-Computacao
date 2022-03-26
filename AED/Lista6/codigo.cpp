#include <iostream>


using namespace std;

struct produtos
{
    float preco;
    int flag;
};


void validaCompra(int soma, int qnt, int l, int m, int q, int i, int *r, produtos *p)
{
    soma += p[i].preco*p[i].flag;
    qnt += p[i].flag;

    int flag = 0;

    if (soma <= q && qnt >= m && p[i].flag == 1)
    {
        (*r)++;
        if(soma==q)flag=1;

    }else if (soma>q)
    {
        flag = 1;
    }

    if(flag==0&&i<l-1)
    {
        for (int k = 1; k >= 0; k--)
        {   
            p[i+1].flag = k;
            if(k==0||(p[i+1].preco+soma<=q))validaCompra(soma,qnt,l,m,q,i+1,r,p);
        }
    }
}


int main()
{
    int K, L, M, Q, R = 0;
    produtos *P = NULL;

    cin>>K;

    //int resultados[K];

    for (int i = 0; i < K; i++)
    {
        //Verifica caso
        cin>>L;

        P = (produtos *) realloc(P,L*sizeof(produtos));
        if(P==nullptr)exit(1);

        for (int j = 0; j < L; j++)
        {
            cin>>P[j].preco;
        }

        cin>>M;
        cin>>Q;
        
        R = 0;
        P[0].flag = 1;
        validaCompra(0,0,L,M,Q,0,&R,P);
        P[0].flag = 0;
        validaCompra(0,0,L,M,Q,0,&R,P);
        
        if (M==0)
        {
            R++; //possibilidade de nao comprar nenhum item
        }
        
        //resultados[i] = R;
        cout<<"caso "<<i<<": "<<R<<endl;
    }
    
    /*for (int i = 0; i < K; i++)
    {
        cout<<resultados[i]<<endl;
    }*/
    

    return 0;
}