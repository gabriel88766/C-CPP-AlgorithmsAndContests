#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, k, b, s;
        cin >> n >> k >> b >> s;
        vector<ll> p(n+1), a(n+1);
        for(int i=1;i<=n;i++) cin >> p[i];
        for(int i=1;i<=n;i++) cin >> a[i];
        ll bb = 0, bs = 0;
        ll cs = 0;
        int cp = b;
        vector<bool> vis(n+1, false);
        for(int i=0;i<k;i++){
            if(vis[cp]) break;
            vis[cp] = true;
            bb = max(bb, a[cp]*(k-i) + cs);
            cs += a[cp];
            cp = p[cp];
            
        }
        cs = 0;
        cp = s;
        for(int i=1;i<=n;i++) vis[i] = false;
        for(int i=0;i<k;i++){
            if(vis[cp]) break;
            vis[cp] = true;
            bs = max(bs, a[cp]*(k-i) + cs);
            cs += a[cp];
            cp = p[cp];
            
        }
        if(bb == bs) cout << "Draw\n";
        else if(bb < bs) cout << "Sasha\n";
        else cout << "Bodya\n";
    }
}   