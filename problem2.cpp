#include<bits/stdc++.h>
using namespace std;

char str[100];
bool isAllDigit(){
    for(int i=0; str[i];i++){
        if(str[i]<'0'||str[i]>'9') return 0;
    }
    return 1;
}

bool floot_number(){
    int countDot = 0, countNext=0;
    for(int i=0; str[i];i++){
        
        if(str[i]>'0'&& str[i]<'9' || str[i] =='.'){
            //cout<<str[i]<<endl;

            if(str[i]=='.'){
                countDot = countDot+1;
                //cout<<str[i+3]<<endl;
                i++;
                while(str[i]){
                    //cout<<countNext<<endl;
                    countNext = countNext+1;
                    i++;
                }
                
            }
            
            
        }
        else{
            return 0;
        }
    }
    if(countDot>1){
        return 0;
    }
    if(countNext>2){
        
        return 0;
    }
    return 1;
}

bool double_number(){
    int countDot = 0, countNext=0;
    for(int i=0; str[i];i++){
        if(str[i]>'0'&& str[i]<'9' || str[i] =='.'){

            if(str[i]=='.'){
                countDot = countDot+1;
                //cout<<str[i+3]<<endl;
                i++;
                while(str[i]){
                    //cout<<countNext<<endl;
                    if(str[i]=='.'){
                        countDot = countDot+1;
                    }
                    countNext = countNext+1;
                    i++;
                }
                
            }
            
            
        }
        else{
            return 0;
        }
    }
    if(countDot>1){
        return 0;
    }
    if(countNext>2){
        
        return 1;
    }
    return 1;
}

bool Boolean_number(){
    for(int i=0;str[i];i++){
        if(str[i]!='1'&& str[i]!='0'){
            return 0;
        }
    }
    return 1;
}

int main(){
    freopen("input2.txt","r",stdin);

    cin>>str;
    cout<<"Input is:"<<str<<endl;
    int ln = strlen(str);

    // if(isother()){
    //     cout<<"not ok"<<endl;
    //     puts("Undefined");
    // }

    if((str[0]>='i'&&str[0]<='n')||(str[0]>='I'&&str[0]<='N')){
        puts("Integer Variable");
    }
    else if(str[0]=='c' && str[1]=='h' && str[2]=='_'){
        cout<<"Character variable"<<endl;
    }
    else if(str[0]=='b' && str[1]=='n' && str[2]=='_'){
        cout<<"Boolean variable"<<endl;
    }
    else if(isAllDigit() && Boolean_number()){
        cout<<"Binary Number"<<endl;
    }
    else if(isAllDigit()&&(str[0]>='1'&&str[0]<='9')&&ln<=4){
        puts("Short Integer");
    }
    else if(isAllDigit()&&(str[0]>='1'&&str[0]<='9')){
        puts("Long Integer");
    }
    else if(str[0]>='a' && str[0]<='h' || str[0]>='A' && str[0]<='H' || str[0]>='o' && str[0]<='z' || str[0]>='O' && str[0]<='Z'){
        cout<<"FLoat Variable"<<endl;
    }
    else if(floot_number()){
        cout<<"Float Number"<<endl;
        
    }
    else if(double_number()){
        cout<<"Double Number"<<endl;
    }
    
    else{
        //cout<<"ok"<<endl;
        puts("Undefined");
    }

    return 0;
}