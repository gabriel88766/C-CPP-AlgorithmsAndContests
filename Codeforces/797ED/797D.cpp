//This solution will probably gets a TLE!!

#include <bits/stdc++.h>

using namespace std;

const int N= 1e5+5;
int root;
int cont=0;
set<int> wrongs, rights; // Why?? world!
map<int,int> wrongsqt;
int p[N],l[N],r[N],v[N];

void init(){
    for(int i=0;i<N;i++){
        p[i]=-1;
    }
}


void bsearch_dfs(int index, int gethan, int lthan){
    if(index != -1){
        if(v[index]<gethan || v[index] > lthan) {cont++,wrongs.insert(v[index]),wrongsqt[v[index]]++;}
        else {
                rights.insert(v[index]);
        }
        bsearch_dfs(l[index], gethan, min(v[index],lthan));
        bsearch_dfs(r[index], max(gethan,v[index]),lthan);
    }
}

int main(){
ios_base::sync_with_stdio(0),cin.tie(0);
init();
int n,a,b,c;
cin >> n;
for(int i=1;i<=n;i++){
    cin >> a >> b >> c;
    l[i]=b;
    r[i]=c;
    if(b!=-1) p[b]=i;
    if(c!=-1) p[c]=i;
    v[i]=a;
}
for(int i=1;i<=n;i++){
    if(p[i]==-1){
        root = i;
        break;
    }
}
bsearch_dfs(root,0,0x3f3f3f3f);
for(auto it = rights.begin(); it != rights.end() ; it++){
    if(wrongs.count((*it))) cont-=wrongsqt[(*it)];
}


cout << cont;
}
