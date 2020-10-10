#include <bits/stdc++.h>

using namespace std;

int main(){
bool lastChar=true;
string s;
cin >>s;
int lastletter=-1;
for(int i=0;i<s.size();i++){
    if(s[i]!='/') lastletter=i;
}
for(int i=0;i<s.size();i++){
    if(s[i]=='/'){
        if(lastChar) cout << "/", lastChar = false;
    }else{
        cout << s[i];
        lastChar=true;
    }
    if(i==lastletter) break;
}
}
