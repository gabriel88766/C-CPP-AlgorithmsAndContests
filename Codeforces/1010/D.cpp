#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+3;
vector<int> adj[N];
string tag[N];
int v[N];
bool change[N];

void dfs1(int u = 1){
    if(tag[u] == "IN") return;
    else if(tag[u] == "NOT"){
        int x = adj[u][0];
        dfs1(x);
        v[u] = v[x]^1;
    }else{
        for(auto x: adj[u]) dfs1(x);
        int x = adj[u][0];
        int y = adj[u][1];
        if(tag[u] == "XOR") v[u] = v[x] ^ v[y];
        else if(tag[u] == "AND") v[u] = v[x] & v[y];
        else v[u] = v[x] | v[y];
    }
}

void dfs2(int u = 1){
    if(tag[u] == "IN") change[u] = true;
    else if(tag[u] == "NOT"){
        dfs2(adj[u][0]);
    }else if(tag[u] == "OR"){
        if(v[adj[u][0]] && v[adj[u][1]]) return;
        else if(v[adj[u][0]]){
            dfs2(adj[u][0]);
        }else if(v[adj[u][1]]){
            dfs2(adj[u][1]);
        }else{
            dfs2(adj[u][0]);
            dfs2(adj[u][1]);
        }
    }else if(tag[u] == "XOR"){
        dfs2(adj[u][0]); dfs2(adj[u][1]);
    }else{ //and
        if(v[adj[u][0]] && v[adj[u][1]]){
            dfs2(adj[u][0]); dfs2(adj[u][1]);
        }else if(v[adj[u][0]]){
            dfs2(adj[u][1]);
        }else if(v[adj[u][1]]){
            dfs2(adj[u][0]);
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    vector<int> ch;
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        string s;
        int a, b;
        cin >> s >> a;
        if(s == "IN"){
            tag[i] = "IN";
            v[i] = a;
            ch.push_back(i);
        }else if(s == "NOT"){
            tag[i] = "NOT";
            adj[i].push_back(a);
        }else{
            tag[i] = s;
            cin >> b;
            adj[i].push_back(a);
            adj[i].push_back(b);
        }
    }
    dfs1();
    dfs2();
    for(auto x : ch){
        if(change[x]) cout << (v[1]^1);
        else cout << v[1];
    }
}
