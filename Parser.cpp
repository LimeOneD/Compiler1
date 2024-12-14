#include "Tokenizer.h"
typedef struct PTreeNode PTREE_NODE;

typedef enum ptreeType
{
    OP_P =1,
    ID_P =2
}PTREE_TYPE;

typedef struct OpNode
{
    OPERATION op_type;
    PTREE_NODE *left;
    PTREE_NODE *right;

}OP_NODE;

typedef struct IdNode
{
    double val;
}ID_NODE;

typedef union 
{
    OP_NODE op_node;
    ID_NODE id_node;
}NODE;

struct PTreeNode
{
    PTREE_TYPE type;
    NODE node;

};



PTREE_NODE * Parser(int &ind, vector<TOKEN> &Token)
{
    if(ind>=Token.size()) return NULL;
    PTREE_NODE *root = (PTREE_NODE*) malloc(sizeof(PTREE_NODE));
    int n=Token.size();
   
   
    
    switch(Token[ind].type)
    {
            case OP:
                root->type = OP_P;
                root->node.op_node.op_type = Token[ind].token_val.type;
                ind+=2;
                root->node.op_node.left = Parser(ind, Token);
                root->node.op_node.right = Parser(ind, Token);
                ind+=1;
                break;
            case ID:
                root->type = ID_P;
                root->node.id_node.val = Token[ind].token_val.data;
                ind++;
                break;
            default:
                cout<<"default";
    }

    return root;
        
    
}
void dfs(PTREE_NODE* root)
{
    if(root==NULL) return;
    cout<<root->type;
    if(root->type == OP_P)
    {
        dfs(root->node.op_node.left);
        dfs(root->node.op_node.right);
    }
}

int main(int argc , char **argv)
{
    string query = argv[1];

    vector<TOKEN> res = return_token(query);

    for(TOKEN t:res)
    {
        if(t.type == 1)
        {   
            cout<< t.type << " ";
            if(t.token_val.type == 1) cout << "SUM" ;

            else if(t.token_val.type == 2) cout << "DIFF";
            else if(t.token_val.type == 3 ) cout << "PROD";
            else cout<< "DIV";
            cout<< endl;
        }
        else if(t.type==2)
            cout<<t.type << " "<< t.token_val.data<<endl;
        else cout<<t.type<< " " << t.token_val.brac<<endl;
    }
    int ind=0; 

    PTREE_NODE *root = Parser(ind, res);
    dfs(root);
    return 0;
}



