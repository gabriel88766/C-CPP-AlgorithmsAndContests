#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;   
int p[N], sz[N];

int cmp;
void init(int n){
    cmp = n;
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
    cmp--;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        init(n);
        vector<vector<pair<int,int>>> vp(11);
        for(int i=0;i<m;i++){
            int a, d, k;
            cin >> a >> d >> k;
            vp[d].push_back({a, k});
        }
        for(int d=1;d<=10;d++){
            vector<int> tt(n+1, 0);
            for(auto [a, k] : vp[d]){
                tt[a] = max(tt[a], k);
            }
            for(int i=1;i<=n-d;i++){
                if(tt[i]){
                    unite(i, i+d);
                    tt[i+d] = max(tt[i+d], tt[i] - 1);
                }
            }
        }





        cout << cmp << "\n";
    }
}
