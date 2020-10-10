#include <bits/stdc++.h>

using namespace std;

int main(){
ios_base::sync_with_stdio(0),cin.tie(0);
int cont=0;
string s1,s2;
cin >> s1 >> s2;

while(s1[cont]=='0') cont++;
s1 = s1.substr(cont,s1.size());

cont=0;
while(s2[cont]=='0') cont++;
s2 = s2.substr(cont,s2.size());

char sig;
if(s1.size()>s2.size()){
    sig = 1;
}else if(s1.size()<s2.size()){
    sig = -1;
}else{
    sig = 0;
    for(int i=0;i<s1.size();i++){
        if(s1[i]==s2[i]){
            continue;
        }else{
            if(s1[i]>s2[i]) sig = 1;
            else sig = -1;
            break;
        }
    }
}
if(sig == 1) cout << ">";
if(sig == 0) cout << "=";
if(sig == -1) cout << "<";


}
