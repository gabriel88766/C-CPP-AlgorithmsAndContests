#include<bits/stdc++.h>

#define INF 0x3f3f3f3f
#define par pair< pair<int, int>, int>
#define st first
#define nd second
#define mp(x,y) make_pair(x,y)
#define sti pair<string,int>

using namespace std;


int main(){
ios_base::sync_with_stdio(0), cin.tie(0);
string s,aux;
int q,l,r,k,modlr,sh,pos;
cin >> s;
aux = s;
cin >> q;
for(int i=0;i<q;i++){
    cin >> l >> r >> k;
    modlr = (r-l+1);
    sh = k%modlr;
    for(int j=0;j<modlr;j++){
        pos = l + j - 1  - sh;
        if(pos<(l-1)) pos+=modlr;
        aux[j]=s[pos];
    }
    for(int j=0;j<modlr;j++){
        s[l+j-1] = aux[j];
    }

}
cout << s;


}


