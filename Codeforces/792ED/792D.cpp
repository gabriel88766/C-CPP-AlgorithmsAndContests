#include <bits/stdc++.h>

using namespace std;

long long int pow2[63];

void init(){
long long int k=1;
for(int i=0;i<63;i++){
    pow2[i]=k;
    k*=2;
}

}

int main(){
ios_base::sync_with_stdio(0),cin.tie(0);
init();
string s;
long long int bit,aux,n,q,k,cont=0,cur;
cin >> n >> q;
k = n+1;
k/=2;
while(k!=1) k/=2,cont++;
while(q--){
        cin >> cur >> s;
        aux = cur;
        bit = 0;
        while(!(aux%2)) aux/=2,bit++;

        for(int i=0;i<s.size();i++){
            if(s[i]=='U' && bit < cont){
                cur&=(~pow2[bit]);
                cur|=pow2[++bit];
            }
            if(s[i]=='L' && bit >0){
                cur&=(~pow2[bit]);
                cur|=pow2[--bit];
            }
            if(s[i]=='R' && bit > 0) cur|=pow2[--bit];
        }
        cout << cur << endl;
}

}


