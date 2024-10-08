#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+3;   
ll p[N], sz[N];

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
    init();
    int n;
    cin >> n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    vector<pair<int,int>> vp;
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        vp.push_back({a, b});
    }
    ll amin = 0, amax = 0;
    sort(vp.begin(), vp.end(), [&](pair<int,int> u, pair<int,int> x){
        return max(v[u.first], v[u.second]) < max(v[x.first], v[x.second]);
    }); 
    for(auto x : vp){
        ll cur = max(v[x.first], v[x.second]);
        amax += sz[get(x.first)] * sz[get(x.second)] * cur;
        unite(x.first, x.second);
    }
    init();
    sort(vp.begin(), vp.end(), [&](pair<int,int> u, pair<int,int> x){
        return min(v[u.first], v[u.second]) > min(v[x.first], v[x.second]);
    });
    for(auto x : vp){
        ll cur = min(v[x.first], v[x.second]);
        amin += sz[get(x.first)] * sz[get(x.second)] * cur;
        unite(x.first, x.second);
    }
    cout << amax - amin << "\n";
}
