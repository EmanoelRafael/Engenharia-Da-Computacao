#include <iostream>

using namespace std;

struct elemento
{
    int c;
    string nome;
    int duracao;
    int t;
};

elemento *criarhashtable(int m)
{
    elemento *hashtable = nullptr;
    hashtable = (elemento *) malloc(m*sizeof(elemento));
    if(hashtable == nullptr)exit(1);

    for (int i = 0; i < m; i++)
    {
        hashtable[i].c = -1;
    }
    
    return hashtable;
}

int funcaoDispersao(int C, int i, int m)
{
    return ((C%m) + i)%m;
}

int criarChave(string nome)
{
    int c = 0;
    for(int i=0; i<nome.length();i++)
    {
        c += int(nome[i])*i;
    }
    return c;
}

int adicionar(elemento *hashtable,string nome, int duracao, int m, int &n)
{
    int c, indice, flag = 0, contador = 0;

    c = criarChave(nome);
    
    while (flag == 0)
    {
        indice = funcaoDispersao(c,contador,m);
        
        if (hashtable[indice].c == -1)
        {
            hashtable[indice].c = c;
            hashtable[indice].nome = nome;
            hashtable[indice].duracao = duracao;
            hashtable[indice].t = 0;

            flag = 1;
            n ++;
        }
        contador ++;
    }

    return indice;
    
}

elemento *rehashing(elemento *hashtable, int &m)
{
    int n = 0, novoM, indice;
    elemento *novaHashtable;

    novoM = 2*m + 1;

    novaHashtable = criarhashtable(novoM);

    for(int i=0; i < m; i++)
    {
        if (hashtable[i].c!=-1)
        {
            indice = adicionar(novaHashtable, hashtable[i].nome, hashtable[i].duracao, novoM, n);
            novaHashtable[indice].t = hashtable[i].t;
        }
    }

    m = novoM;

    return novaHashtable;
}

int play(elemento *hashtable, string nome, int m)
{
    int c, indice, contador, flag=0, t;

    c = criarChave(nome);
    
    while (flag == 0)
    {
        indice = funcaoDispersao(c, contador, m);
        if (hashtable[indice].nome == nome)
        {
            flag = 1;
            hashtable[indice].t += hashtable[indice].duracao;
            t = hashtable[indice].t;
        }
        contador ++;
    }
    
    return t;
}

int time(elemento *hashtable, string nome, int m)
{
    int c, indice, contador, flag=0, t;

    c = criarChave(nome);
    
    while (flag == 0)
    {
        indice = funcaoDispersao(c, contador, m);
        if (hashtable[indice].nome == nome)
        {
            flag = 1;
            t = hashtable[indice].t;
        }
        contador ++;
    }
    
    return t;
}


int main()
{
    int m, duracao, n=0, indice, t;
    float taxaocupacao;
    string comando, nome;
    elemento *hashtable=nullptr;
    
    cin >> m;
    cin >> comando;

    hashtable = criarhashtable(m);
    
    while (comando.compare("END")!=0)
    {
        if (comando.compare("ADD")==0)
        {
            cin>>nome;
            cin>>duracao;
            indice = adicionar(hashtable,nome,duracao,m,n);
            taxaocupacao = (n+0.0)/m;

            if (taxaocupacao>=0.5)
            {
                hashtable = rehashing(hashtable,m);
            }
            cout<<nome<<" "<< indice <<endl;

        }else if (comando.compare("PLAY")==0)
        {
            cin>>nome;
            t = play(hashtable,nome,m);
            cout<<nome<<" "<< t <<endl;
        }else if (comando.compare("TIME")==0)
        {
            cin>>nome;
            t = time(hashtable,nome,m);
            cout<<nome<<" "<< t <<endl;
        }
        
        cin >> comando;
    }

    return 0;
}
