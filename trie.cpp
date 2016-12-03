struct node
{
    bool isword;
    node *next[27];
    node()
    {
       isword=false;
       for(int i=0;i<26;i++)
       next[i]=NULL;
    }
}*root;


void insertnode(char *s, int len)
{
    node *curr=root;
    repc(i,0,len)
    {
       I id=s[i]-'a';
       if(curr->next[id]==NULL)
            curr->next[id]=new node();
       curr=curr->next[id];
    }
    curr->isword=1;
}

bool Q(char *s,int len)
{
    node *curr=root;
    repc(i,0,len)
    {
        int id=s[i]-'a';
        if(curr->next[id]==NULL) return false;
        curr=curr->next[id];
    }
    return curr->isword;
}

void del(node* curr)
{
    printf("deleting\n");
    repc(i,0,25)
    if(curr->next[i]) del(curr->next[i]);
    delete(curr);
}

void print_trie(node *curr)
{
    repc(i,0,25)
    {
        if(curr->next[i])
        {
            printf("%c",97+i);
            print_trie(curr->next[i]);
            pfn;
        }
    }
}
int main()
{
    root=new node();
    int n;
    pf("How many words:");
    S(n);
    char s[100];
    repc(i,1,n)
    {
        SC(s);
        insertnode(s,strlen(s)-1);
    }
    pf("How many query?:");
    S(n);
    while(n--)
    {

        SC(s);
        bool res=Q(s,strlen(s)-1);
        if(res) pf("Got it!!!\n");
        else pf("Sorry\n");
    }
    print_trie(root);
    del(root);
    //delete(root);
    return 0;
}

