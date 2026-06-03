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
        int n, m;
        cin >> n >> m;
        ll lc = 1;
        vector<bool> mk(n+m+1);
        for(int i=1;i<=n;i++){
            ll x;
            cin >> x;
            if(lc <= n + m && lc % x != 0) lc = lcm(lc, x);
            mk[x] = true;
        }
        for(int i=1;i<=n+m;i++){
            if(mk[i]){
                for(int j=i;j<=n+m;j+=i){
                    mk[j] = true;
                }
            }
        }
        int q1 = 0, q2 = 0, q3 = 0;
        for(int i=1;i<=m;i++){
            bool alice = true, bob = true;
            ll x;
            cin >> x;
            if(x % lc == 0) bob = false;
            if(!mk[x]) alice = false;
            if(alice && bob) q1++;
            else if(alice) q2++;
            else if(bob) q3++;
            else assert(false);
        }
        if(q2 > q3) cout << "Alice\n";
        else if(q2 < q3) cout << "Bob\n";
        else if(q1 % 2) cout << "Alice\n";
        else cout << "Bob\n";
    }
}
