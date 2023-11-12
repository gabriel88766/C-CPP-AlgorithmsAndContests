#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


const int N = 2e5+3;   
int p[N], sz[N];
map<int,ll> mp[N];

void init(){
    for(int i=1;i<N;i++) {p[i] = i; sz[i] = 1; mp[i][i] = 0;}
}

int get(int a){ 
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void unite(int a, int b, int c){
    int xa = get(a);
    int xb = get(b);
    if(mp[xa].size() < mp[xb].size()){
         swap(xa,xb);
         swap(a, b);
         c = -c;
    }
    p[xb] = xa;
    mp[xa][xb] = mp[xa][a] + c - mp[xb][b]; 
    for(auto x : mp[xb]){
        mp[xa][x.first] = mp[xa][xb] + x.second;
    }
}

ll query(int a, int b){
    int u = get(a);
    return mp[u][b] - mp[u][a];
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    set<int> s;
    init();
    for(int i=1;i<=q;i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(get(a) != get(b)){
            unite(a, b, c);
            s.insert(i);
        }else{
            if(query(a, b) == c) s.insert(i);
        }
    }
    for(auto x : s) cout << x << " ";
}
