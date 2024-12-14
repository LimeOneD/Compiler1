#include "Tokenizer.h"

vector<TOKEN> return_token(string stream)
{
    vector<TOKEN> Tokens;
    int i=0;
    int n=stream.size();
    while(i<n)
    {
        
        if( stream[i]=='S')
        {

            i+=3;
            TOKEN T(OP, SUM);
            Tokens.push_back(T);
        }
        else if(stream[i] == 'D' && stream[i+1] == 'I' && stream[i+2]=='V')
        {
            i+=3;
            TOKEN T(OP, DIV);
            Tokens.push_back(T);

        }
        else if(stream[i] == 'D')
        {

            i+=4;
            TOKEN T(OP, DIFF);
            Tokens.push_back(T);
                
        }

        else if(stream[i] == 'P')
        {
            i+=4;
            TOKEN T(OP, PROD);
            Tokens.push_back(T);

        }
        else if(isdigit(stream[i]))
        {
            string digit="";
            while( i<n && isdigit(stream[i]))
            {
                digit+=stream[i];
                i++;
            }
            
            TOKEN T(ID, stod(digit));
            Tokens.push_back(T);
        }
    
        else if(stream[i] == '(')
        {
            i++;
            TOKEN T(LB, '(');
            Tokens.push_back(T);
        }
        else if(stream[i] == ')')
        {
            i++;
            TOKEN T(RB, ')');
            Tokens.push_back(T);
        }
        else if(stream[i]==' ' ||  stream[i] == ',')
        {
            i++;
        }
            

    }

    return Tokens;
}






