#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;   
int p[N], sz[N];
set<int> s[N]; //black vertices

void init(){
    for(int i=1;i<N;i++) {p[i] = i; sz[i] = 1;}
}

int get(int a){ 
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a,b);
    p[b] = a;
    sz[a] += sz[b];
    for(auto x : s[b]) s[a].insert(x);
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int n, q;
    cin >> n >> q;
    for(int i=1;i<=q;i++){
        int tq;
        cin >> tq;
        if(tq == 1){
            int u, v;
            cin >> u >> v;
            unite(u, v);
        }else if(tq == 2){
            int v;
            cin >> v;
            if(s[get(v)].count(v)) s[get(v)].erase(v);
            else s[get(v)].insert(v);
        }else{
            int v;
            cin >> v;
            if(s[get(v)].size()) cout << "Yes\n";
            else cout << "No\n";
        }
    }
}
