#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
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

vector<int> comp[N];
set<int> allc;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1), b(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];
    init();
    for(int i=1;i<=m;i++){
        int c, d;
        cin >> c >> d;
        unite(c, d);
    }
    for(int i=1;i<=n;i++){
        int cur = get(i);
        if(!allc.count(cur)){
            allc.insert(cur);
        }
        comp[cur].push_back(i);
    }
    bool ok = true;
    for(auto it = allc.begin(); it != allc.end(); ++it){
        int j = *it;
        ll sum1 = 0, sum2 = 0;
        for(int i=0;i<comp[j].size(); i++){
            int k = comp[j][i];
            sum1 += a[k];
            sum2 += b[k];
        }
        if(sum1 != sum2) ok = false;
    }
    if(ok) cout << "Yes\n";
    else cout << "No\n";
} 
