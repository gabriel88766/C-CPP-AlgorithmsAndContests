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
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> edg;
    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        edg.push_back({a, b, c});
    }
    int ans = (1 << 30) - 1;
    for(int j=29;j>=0;j--){
        int cur = ans ^ (1 << j);
        init(n);
        for(int i=0;i<m;i++){
            auto &[a, b, c] = edg[i];
            if((cur & c) == c) unite(a, b);
        }
        if(get(1) == get(n)) ans = cur;
    }
    cout << ans << "\n";

}
