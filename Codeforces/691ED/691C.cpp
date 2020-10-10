#include<bits/stdc++.h>

#define INF 0x3f3f3f3f
#define par pair< pair<int, int>, int>
#define st first
#define nd second
#define mp(x,y) make_pair(x,y)
#define sti pair<string,int>
#define MOD 1e9+7

using namespace std;

int findpoint(string s){
int po =-1;
for(int i = 0;i<s.size();i++){
    if(s[i]=='.') po = i;
}
return po;
}
int lastnonnull(string s){
int cont=0;
int i=0;
while(s.size()!=i){
    if(s[i]>'0' && s[i]<='9'){
        cont =i;
    }
    i++;
}
return cont;
}

string numbers(string s,int k){
    int i=0;
    while(s[i]=='0' || s[i]=='.') i++;
    string ret="";
    ret+=s[i];
    if(i!=k)
    ret+='.';
    i++;
    while(i<=k){
        if(s[i]!='.')
            ret+=s[i];
        i++;
    }
    return ret;
}

void elsenumbers(string s,int n){
    string num="";
    int cont=-1;
    int i=0;
    int goback;
    bool flag = true;
    while(s[i]=='0') i++;
    while(i!=s.size()){
        cont++;
        if(cont == 1 && i<=n) { num+='.'; }
        if(i<=n){
            num+=s[i];
        }
        i++;
    }
    if(cont==0){ cout << num;}
    else
    cout << num << "E" << cont;
}

int untilpoint(string s){
    int cont = 0,i=0;
    bool flag = true;
    while(s[i]=='0' && i<s.size()) i++;
    if(i==s.size()) return 0;
    if(s[i]=='.'){
        cont--;
        i++;
        while(s[i]=='0') i++,cont--;
    }else{
        while(s[i]!='.') cont++,i++;
        cont --;
    }

    return cont;
}
int main(){
ios_base::sync_with_stdio(0), cin.tie(0);
string num;
string numbs;
int k;
cin >> num;
int n = findpoint(num);
if(n!=-1){
    k=lastnonnull(num);
    numbs = numbers(num,k);
    cout << numbs;
    if(untilpoint(num)!=0)
    cout << "E" << untilpoint(num);
}else{
    k = lastnonnull(num);
    elsenumbers(num,k);
}


}
