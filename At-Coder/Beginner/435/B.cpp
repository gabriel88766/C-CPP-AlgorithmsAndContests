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
    int n;
    cin >> n;
    vector<ll> v(n+1), ps(n+1);
    for(int i=1;i<=n;i++){
        cin >> v[i];
        ps[i] = ps[i-1] + v[i];
    }
    int ans = 0;
    for(int l=1;l<=n;l++){
        for(int r=l;r<=n;r++){
            bool ok = true;
            for(int i=l;i<=r;i++){
                if((ps[r] - ps[l-1]) % v[i] == 0) ok = false;
            }
            if(ok) ans++;
        }
    }
    cout << ans << "\n";
}
