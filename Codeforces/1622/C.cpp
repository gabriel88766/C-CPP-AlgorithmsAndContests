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
        int n;
        ll k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin >> a[i];
        sort(a.begin(), a.end());
        ll cs = 0;
        for(auto x : a) cs += x;
        if(cs <= k) cout << "0\n";
        else{
            vector<ll> cd;
            for(int i=n-1;i>=0;i--) cd.push_back(a[i] - a[0]);
            ll md = cs - k;
            ll ans = md; //all moves -1
            ll aux = 0;
            for(int i=0;i<n-1;i++){
                aux += cd[i];
                ll mv = i+1;
                if(aux < md){
                    mv += (md-aux+i+1)/(i+2);
                }
                ans = min(ans, mv);
            }
            cout << ans << "\n";
        }
    }
}
