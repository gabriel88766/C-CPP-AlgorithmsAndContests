#include <bits/stdc++.h>

using namespace std;

int main(){
ios_base::sync_with_stdio(0),cin.tie(0);
string s;
char rule1=true,rule2=true;
cin >> s;
if(s[0]<='z' && s[0] >= 'a'){
    rule1=false;
}else{
    rule2=false;
}
for(int i=1;i<s.size();i++){
    if(!(s[i] <='Z' && s[i]>='A')) rule1=false,rule2=false;
}
if(rule1){
    for(int i=0;i<s.size();i++){
        s[i] = (s[i]-'A') + 'a';
    }
}else if(rule2){
    s[0] = (s[0]-'a') + 'A';
    for(int i=1;i<s.size();i++){
        s[i] = (s[i]-'A') + 'a';
    }
}

cout << s;
}
