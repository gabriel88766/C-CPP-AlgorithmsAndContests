#include <bits/stdc++.h>
 
using namespace std;
const int N = 1e6+3;
int table[N];
vector<int> cmp[N];
int par[N], sz[N]; //
 
int find(int a) { return par[a] == a ? a : par[a] = find(par[a]); }
 
void unite(int a, int b) {
  if ((a = find(a)) == (b = find(b))) return;
  if (sz[a] < sz[b]) swap(a, b);
  par[b] = a; sz[a] += sz[b];
}
 
void init(){
    for(int i=1;i<N;i++){
        sz[i] = 1;
        par[i] = i;
    }
}
 
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    init();
    int cont = 0;
    int n, m;
    cin >> n >> m;
    vector<int> v(n+2);
    vector<int> ans(n+2);
    for(int i=1;i<=n;i++){
        cin >> v[i];
    }
    for(int j = 1;j<=m;j++){
        int a,b;
        cin >> a >> b;
        unite(a,b);
    }
    for(int i=1;i<=n;i++){
        int aux = find(i);
        if(!table[aux]){
            table[aux] = ++cont;
        }
        cmp[table[aux]].push_back(i);
    }
 
    for(int i=1;i<=cont;i++){
        vector<int> aux;
        for(int j=0;j<cmp[i].size();j++){
            aux.push_back(v[cmp[i][j]]);
        }
        sort(aux.begin(),aux.end(),greater<int>());
        for(int j=0;j<cmp[i].size();j++){
            ans[cmp[i][j]] = aux[j];
        }
    }
    for(int i=1;i<=n;i++) cout << ans[i] << " ";
}