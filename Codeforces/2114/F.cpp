#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dp[1000005];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int x, y, k;
        cin >> x >> y >> k;
        multiset<int> fx, fy, nc;
        for(int i=2;i*i<=x;i++){
            if(x % i == 0){
                while(x % i == 0){
                    fx.insert(i);
                    x /= i;
                    nc.insert(i);
                }
            }
        }
        if(x != 1){
            fx.insert(x);
            nc.insert(x);
        }
        for(int i=2;i*i<=y;i++){
            if(y % i == 0){
                while(y % i == 0){
                    fy.insert(i);
                    nc.insert(i);
                    y /= i;
                }
            }
        }
        if(y != 1){
            fy.insert(y);
            nc.insert(y);
        }
        for(auto &x : nc){
            if(fy.find(x) != fy.end() && fx.find(x) != fx.end()){
                fy.erase(fy.find(x));
                fx.erase(fx.find(x));
            }
        }
        if(fx.size() || fy.size()){
            //check if all primes lower than or equal to k
            bool ok = true;
            for(auto &x : fx) if(x > k) ok = false;
            for(auto &x : fy) if(x > k) ok = false;
            ll m1 = 1, m2 = 1;
            for(auto &x : fx) m1 *= x;
            for(auto &x : fy) m2 *= x;
            if(ok){
                //dp anyway
                int mx = max(m1, m2);
                dp[1] = 0;
                for(int i=2;i<=mx;i++) dp[i] = INF_INT;
                vector<ll> divs;
                for(int j=1;j*j<=m1;j++){
                    if(m1 % j == 0){
                        divs.push_back(j);
                        divs.push_back(m1/j);
                    }
                }
                for(int j=1;j*j<=m2;j++){
                    if(m2 % j == 0){
                        divs.push_back(j);
                        divs.push_back(m2/j);
                    }
                }
                sort(divs.begin(), divs.end());
                divs.resize(unique(divs.begin(), divs.end()) - divs.begin());
                for(auto &i : divs){
                    for(auto &j : divs){
                        if(j > k || i*j > mx) break;
                        dp[i*j] = min(dp[i*j], dp[i] + 1);
                    }
                }
                cout << dp[m1] + dp[m2] << "\n";
            }else cout << "-1\n";
        }else cout << "0\n";
    }
    // cout << tt << "\n";
}