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
        ll n;
        string s;
        cin >> n >> s;
        s = ' ' + s;
        vector<ll> pr(n+1, 0), su(n+1, 0), ps(n+1, 0), ss(n+1, 0);
        vector<ll> pi, si;
        for(int i=1;i<=n;i++){
            pr[i] = pr[i-1];
            ps[i] = ps[i-1];
            ss[i] = ss[i-1];
            if(s[i] == '>'){
                pi.push_back(i);
                pr[i]++;
                ps[i] += i;
            }else{
                si.push_back(i);
                su[i]++;
                ss[i] += i;
            }
        }
        for(int i=n-1;i>=1;i--){
            su[i] += su[i+1];
        }

        for(ll i=1;i<=n;i++){
            ll ans = 0;
            if(su[i] > pr[i-1]){
                //pr[i-1]+1 -> and <-
                ans = i + ((pr[i-1] * i) - ps[i-1])*2;
                int j = lower_bound(si.begin(), si.end(), i) - si.begin();
                ans += 2*(ss[si[j+pr[i-1]]] - ss[i-1] - (pr[i-1] + 1)*i);
            }else{
                ans = 2*(ss[n] - ss[i-1] - su[i] * i) + n - i + 1;
                int j = prev(lower_bound(pi.begin(), pi.end(), i)) - pi.begin();
                if(su[i]) ans += (su[i] * i - (ps[i-1] - ps[pi[j-su[i]+1]-1]))*2;
            }
            cout << ans << " ";
        }
        cout << "\n";

    }
}
