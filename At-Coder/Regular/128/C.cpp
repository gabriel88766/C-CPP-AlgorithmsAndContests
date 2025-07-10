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
    ll n, m, s;
    cin >> n >> m >> s;
    vector<ll> v(n+1), ps(n+1);
    for(int i=1;i<=n;i++){
        cin >> v[i];
        ps[i] = v[i] + ps[i-1];
    }
    double ans = 0;
    int r = n;
    while(r >= 1){
        int bl = r;
        double avg = v[r];
        for(int j=r-1;j>=1;j--){
            double cur = ps[r] - ps[j-1];
            cur /= (r - j + 1);
            if(cur > avg){
                avg = cur;
                bl = j;
            }
        }
        if(m * (r - bl + 1) >= s){
            double val = (double)s / (r - bl + 1);
            ans += val * (ps[r] - ps[bl-1]);
            break;
        }else{
            s -= m * (r - bl + 1);
            ans += m * (ps[r] - ps[bl - 1]);
        }
        r = bl - 1;
    }
    cout << fixed << setprecision(10) << ans << "\n";
}
