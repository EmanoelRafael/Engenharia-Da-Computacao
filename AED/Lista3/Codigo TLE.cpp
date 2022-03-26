#include <iostream>

using namespace std;
struct Node
{
    int val;
    Node *left;
    Node *right;
    int bf;
};

Node *rotateRight(Node *root)
{
    Node *l;
    Node *lr;

    l = root->left;
    lr = l->right;
    l->right = root;
    root->left = lr;

    return l;
}

Node *rotateLeft(Node *root)
{
    Node *r;
    Node *rl;

    r = root->right;
    rl = r->left;
    r->left = root;
    root->right = rl;

    return r;
}

Node *girarBST(Node *root, int *v, int i, int &l, int &r)
{
    Node *cur;
    cur = root;

    if(root->left == nullptr)
    {   
        while (cur->val != v[i])
        {
            cur = rotateLeft(cur);
            l++;
        }
    }else if (root->right == nullptr)
    {
        while (cur->val != v[i])
        {
            cur = rotateRight(cur);
            r++;
        }
    }
    
    return cur;
}

Node *ordenarBST(Node *root, int *v, int &i, int &l, int &r)
{
    root = girarBST(root,v,i, l, r);
    i++;
    
    if(root->left != nullptr)
    {
        root->left = ordenarBST(root->left, v, i, l, r);
    }
    if (root->right != nullptr)
    {
        root->right = ordenarBST(root->right,v, i, l, r);
    }
    
    return root;
}

Node *undoBST(Node *root, int &l)
{
    while (root->right != nullptr)
    {
        root = rotateLeft(root);
        l++;
    }
    
    if(root->left != nullptr)
    {
        root->left = undoBST(root->left, l);
    }
    
    return root;
}

int height(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    
    int hl;
    int hr;

    hl = height(root->left);
    hr = height(root->right);

    if (hl > hr)
    {
        return 1 + hl;
    }else
    {
        return 1 + hr;
    }

}

Node *bstInsert(Node *root,int val)
{
    if (root==nullptr)
    {
        Node *node;
        node = new Node;
        node->left = nullptr;
        node->right = nullptr;
        node->val = val;
        node->bf = 0;
        return node;
    }
    if (val < root->val)
    {
        root->left = bstInsert(root->left,val);

        return root;
    }
    if (val >= root->val)
    {
        root->right = bstInsert(root->right,val);

        return root;
    }  
}

Node *makeBST(int *vetor, int tam)
{
    Node *root = nullptr;

    for (int i = 0; i < tam; i++)
    {
        root = bstInsert(root,vetor[i]);
    }

    return root;
}

bool verificarAVL(Node *root, int *v,int &i)
{
    bool var = true;
    bool varl = true;
    bool varr = true;

    if (root == nullptr)
    {
        return var;
    }

    varl = verificarAVL(root->left, v, i);
    varr = verificarAVL(root->right, v, i);

    v[i] = root->val;
    i++;

    root->bf = height(root->right) - height(root->left);
    
    if (root->bf > 1 || root->bf < -1)
    {
        var = false;
    }

    if (varl&&varr&&var)
    {
        var = true;
    }else
    {
        var = false;
    }

    return var;
}

int main()
{   
    Node *bst;
    int *s = nullptr;
    int *t = nullptr;
    int l = 0;
    int r = 0;
    int i = 0;
    bool flag = true;

    int n;

    cin>>n;
    
    while (n != 0)
    {
        s = (int *) realloc(s,n*sizeof(int));
        if(s == nullptr) exit(1);
        t = (int *) realloc(t,n*sizeof(int));
        if(t == nullptr) exit(1);

        for (int i = 0; i < n; i++)
        {
            cin>>s[i];
        }
        for (int j = 0; j < n; j++)
        {
            cin>>t[j];
        }


        bst = makeBST(s,n);

        bst = undoBST(bst,l);

        bst = ordenarBST(bst,t,i,l,r);
        
        i = 0;

        flag = verificarAVL(bst, s, i);

        cout<< l << " " << r <<endl;

        for (int i = 0; i < n; i++)
        {
            cout<< s[i]; 
            if(i!=n-1)cout<< " ";
        }
        
        cout<<endl;

        if (flag)
        {
            cout<<"true"<<endl;
        }else
        {
            cout<<"false"<<endl;
        }
        
        cout<<endl;

        i = 0;
        l = 0;
        r = 0;
        flag = true;

        cin>>n;
    }
    
    
    return 0;
}