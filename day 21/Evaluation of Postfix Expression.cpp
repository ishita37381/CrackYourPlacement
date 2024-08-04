class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int calculate(int a,int b,char op){
        if(op=='+')return a+b;
        else if (op=='-')return a-b;
        else if ( op=='/')return a/b;
        else return a*b;
    }
    int evaluatePostfix(string S)
    {
        stack<int>s;
        for (int i=0;i<S.size();i++){
            if(isdigit(S[i]))s.push(S[i]-'0');
            else {
                int b=s.top();
                s.pop();
                int a=s.top();
                s.pop();
                s.push(calculate(a,b,S[i]));
            }
        }
        return s.top();
    }
};
