#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;   
int p[N], sz[N];
ll sum[N];

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
    sum[a] += sum[b];
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n;
        ll c;
        cin >> n >> c;
        vector<ll> v(n+1);
        for(int i=1;i<=n;i++){
            p[i] = i;
            sz[i] = 1;
            cin >> v[i];
            sum[i] = v[i];
        }
        int cur = 1;
        for(ll i=2;i<=n;i++){
            if(sum[get(cur)] + sum[i] >= i*c){
                for(int j=cur;j<=i;j++){
                    unite(1, j);
                }
                cur = i;
            }
        }
        if(cur == n) cout << "Yes\n";
        else cout << "No\n";

    }
}
