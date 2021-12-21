#include<iostream>
using namespace std;
int main()
{
    int len,i,j,cnt=0,temp1,temp2;
    string s;
    cout<<"Enter a string:"<<endl;
    freopen("input5.txt","r",stdin);
    getline(cin, s);
    len=s.length();
    if(len == 0){
        cout<<"Enter a valid string."<<endl;
        return 0;
    }
    if(s[0]=='*'||s[0]=='/'||s[len-1]=='+'||s[len-1]=='-'||s[len-1]=='*'||s[len-1]=='/'||s[len-1]=='(')
    {
        cout<<"Invalid"<<endl;
        return 0;
    }
    for(i=0;i<len;i++)
    {
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
        {
            if(s[i+1]=='+'||s[i+1]=='-'||s[i+1]=='*'||s[i+1]=='/'|| s[i+1]==')')
            {
                cout<<"Invalid"<<endl;
                return 0;

            }
        }
        if(s[i]==')')
        {
            temp1=i;
        }
        else if(s[i]=='('&&i+2<len)
        {
          temp2=i;
          if(s[i+1]==')')
              {
              cout<<"Invalid"<<endl;
              return 0;

              }
            else if(s[i+1]=='*'||s[i+1]=='/'){
                cout<<"invalid"<<endl;
                return 0;
            }
            else{
                for(j=i;j<len;j++)
                {
                    if(s[j]==')')
                    {
                        cnt++;
                    }
                }
            if(cnt==0)
            {
                cout<<"Invalid"<<endl;
                return 0;

            }
        }

        }
    }
    if(temp1!=temp2)
    {
        cout<<"Invalid"<<endl;
        return 0;
    }
    cout<<"valid"<<endl;
    return 0;


}