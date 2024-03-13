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
        int n, q;
        cin >> n >> q;
        vector<ll> v(n+1);
        for(int i=1;i<=n;i++) cin >> v[i];
        vector<ll> ps1(n+1), ps2(n+1);
        for(int i=1;i<=n;i++){
            ps1[i] = ps1[i-1];
            ps2[i] = ps2[i-1];
            if(v[i] == 1) ps1[i]++;
            ps2[i] += v[i];
        }
        for(int i=0;i<q;i++){
            int l, r;
            cin >> l >> r;
            if(l == r) cout << "NO\n";
            else{
                ll sum1 = ps2[r] - ps2[l-1];
                int qt1 = ps1[r] - ps1[l-1];
                ll sum2 = qt1 * 2 + (r-l+1-qt1);
                if(sum2 <= sum1) cout << "YES\n";
                else cout << "NO\n";
            }
        }
    }
}   
