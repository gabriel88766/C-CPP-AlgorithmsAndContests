#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 4e5+3;   
int p[N], sz[N], qt[N];
ll sum[N], ps[N], mx[N];
ll cans = 0;

void init(){
    for(int i=1;i<N;i++) {p[i] = i; sz[i] = 1; mx[i] = i;}
}

int get(int a){ 
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a,b);
    cans -= ps[mx[a]] - ps[mx[a] - qt[a]];
    cans -= ps[mx[b]] - ps[mx[b] - qt[b]];
    mx[a] = max(mx[a], mx[b]);
    qt[a] += qt[b];
    cans += ps[mx[a]] - ps[mx[a] - qt[a]];
    p[b] = a;
    sz[a] += sz[b];
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int n, m, q;
    cin >> n >> m >> q;
    vector<pair<int,int>> qrs(q);
    vector<int> a(n), b(m);
    vector<ll> ans(q);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i];
    for(int i=0;i<q;i++){
        cin >> qrs[i].first;
        qrs[i].second = i;
    }
    sort(a.begin(), a.end());
    sort(qrs.begin(), qrs.end());
    vector<int> jn = {0};
    for(auto x : a) jn.push_back(x);
    for(auto x : b) jn.push_back(x);
    sort(jn.begin(), jn.end());
    for(int i=1;i<=n+m;i++) ps[i] = ps[i-1] + jn[i];
    vector<pair<int,int>> dif;
    int cp = n-1;
    for(int i=n+m;i>=1;i--){
        if(cp >= 0 && jn[i] == a[cp]){
            qt[i]++;
            cans += jn[i];
            cp--;
        }
        if(i != 1){
            int cd = jn[i] - jn[i-1];
            dif.push_back({cd, i-1});
        }
    }
    sort(dif.begin(), dif.end());
    cp = 0;
    for(auto [k, i] : qrs){
        while(cp < dif.size() && dif[cp].first <= k){
            //do update
            unite(dif[cp].second, dif[cp].second+1);
            cp++;
        }
        ans[i] = cans;
    }
    for(auto x : ans) cout << x << "\n";
}
