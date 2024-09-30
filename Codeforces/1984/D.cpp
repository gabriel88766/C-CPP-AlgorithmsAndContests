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
        string s;
        cin >> s;
        int n = s.size();
        vector<int> v;
        for(int i=0;i<n;i++){
            if(s[i] != 'a') v.push_back(i);
        }
        if(v.size() == 0) cout << n-1 << "\n";
        else{
            ll ans = 0;
            vector<int> ch;
            for(int j=1;j<=v.size();j++){
                if(!(v.size() % j)){
                    ch.push_back(j);
                }
            }
            for(auto d : ch){
                auto s0 = s.substr(v[0], v[0+d-1] - v[0] + 1);
                bool ok = true;
                for(int j=d; j<v.size();j+=d){
                    if(s.substr(v[j], v[j+d-1] - v[j] + 1) != s0) ok = false;
                }
                if(ok){
                    int pr = v[0];
                    int su = n - v.back() - 1;
                    int ps = INF_INT;
                    for(int j=d;j<v.size();j+=d){
                        ps = min(ps, v[j] - v[j-1] - 1);
                    }
                    for(int i=0;i<=pr;i++){
                        int ms = min(ps - i, su);
                        if(ms >= 0) ans += ms + 1;
                        else break;
                    }
                }
            }
            cout << ans << "\n";
        }
    }
}
