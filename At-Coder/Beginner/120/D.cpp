#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;   
int p[N], sz[N];

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
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    vector<pair<int, int>> vp;
    init();
    vector<ll> ans;
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        vp.push_back({a, b});
    }
    reverse(vp.begin(), vp.end());
    ll cans = n;
    cans *= (n-1);
    cans /= 2;
    for(auto &[a, b] : vp){
        ans.push_back(cans);
        if(get(a) != get(b)){
            cans -= sz[get(a)] * sz[get(b)];
            unite(a, b);
        }        
    }
    reverse(ans.begin(), ans.end());
    for(auto &x : ans) cout << x << "\n";
}
