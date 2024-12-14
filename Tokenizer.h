#include <vector>
#include <string>
#include <iostream>


using namespace std;

typedef enum Token_type
{
    OP=1,
    ID=2,
    LB=3,
    RB=4

}TOKEN_TYPE;

typedef enum Operation
{
    SUM = 1, 
    DIFF = 2, 
    PROD = 3, 
    DIV = 4
}OPERATION;


typedef union Tonek_value
{
    OPERATION type;
    double data;
    char brac;

}TOKEN_VAL;


typedef struct Token
{
    TOKEN_TYPE type;
    TOKEN_VAL token_val;

    Token(TOKEN_TYPE n, OPERATION op)
    {
        type = n;
        token_val.type = op;

    }
    Token(TOKEN_TYPE n, double val)
    {
        type= n;
        token_val.data = val;
    }
    Token(TOKEN_TYPE n, char brac)
    {
        type = n;
        token_val.brac = brac;
    }
    
}TOKEN;

vector<TOKEN> return_token(string stream);

