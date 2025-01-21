#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;   
int p[N], sz[N];

void init(int n){
    for(int i=1;i<=n;i++) {p[i] = i; sz[i] = 1;}
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
    int t;
    cin >> t;
    while(t--){
        int n, m1, m2;
        cin >> n >> m1 >> m2;
        init(n);
        vector<pair<int,int>> g, g2;
        for(int i=0;i<m1;i++){
            int a, b;
            cin >> a >> b;
            g.push_back({a, b});
        }
        for(int i=0;i<m2;i++){
            int a, b;
            cin >> a >> b;
            unite(a, b);
        }
        set<int> cmp;
        for(int i=1;i<=n;i++) cmp.insert(get(i));
        int ans = 0;
        for(auto &[a, b] : g){
            if(get(a) == get(b)) g2.push_back({a, b});
            else ans++;
        }
        init(n);
        set<int> cmp2;
        for(auto &[a,b] : g2) unite(a, b);
        for(int i=1;i<=n;i++){
            cmp2.insert(get(i));
        }
        ans += cmp2.size() - cmp.size();
        cout << ans << "\n";
    }
}
