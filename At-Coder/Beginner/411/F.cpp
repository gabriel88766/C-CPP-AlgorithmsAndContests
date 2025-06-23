#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int n, m;
const int N = 3e5+3;   
int p[N];
set<int> adj[N];

void init(){
    for(int i=1;i<N;i++) {p[i] = i;}
}

int get(int a){ 
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b) return;
    if(adj[a].size() < adj[b].size()) swap(a, b);
    m--;
    adj[a].erase(b);//check
    adj[b].erase(a);
    for(auto x : adj[b]){
        if(adj[a].count(x)){
            adj[x].erase(b);
            m--;
        }else{
            adj[x].erase(b);
            adj[x].insert(a);
            adj[a].insert(x);
        }
    }
    p[b] = a;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> n >> m;
    init();
    vector<pair<int, int>> edg(m+1);
    for(int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        edg[i] = {a, b};
        adj[a].insert(b);
        adj[b].insert(a);
    }
    int q;
    cin >> q;
    for(int i=1;i<=q;i++){
        int x;
        cin >> x;
        unite(edg[x].first, edg[x].second);
        cout << m << "\n";
    }
}
