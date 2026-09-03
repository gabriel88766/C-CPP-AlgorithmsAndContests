#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int M = 2e5+3;   
int p[M], sz[M];

void init(){
    for(int i=1;i<M;i++) {p[i] = i; sz[i] = 1;}
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

const int N = 1e6 + 1;
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> is(N, 0);
    for(int i=1;i<=n;i++){
        cin >> v[i];
        is[v[i]] = i;
    }
    init();
    ll ans = 0;
    for(int i=N;i>=1;i--){
        int fv = -1;
        for(int j=i;j<=N;j+=i){
            if(is[j]){
                if(fv == -1) fv = is[j];
                else{
                    if(get(fv) != get(is[j])){
                        unite(fv, is[j]);
                        ans += i;
                    }
                }
            }
        }
    }
    cout << ans << "\n";
}   
