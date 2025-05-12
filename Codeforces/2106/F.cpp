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
        ll ans = 0;
        int n;
        string s;
        cin >> n >> s;
        int cnt = 0;
        vector<int> v;
        for(int i=0;i<n;i++){
            if(s[i] == '1'){
                v.push_back(cnt);
                cnt = 0;
            }else cnt++;
        }
        v.push_back(cnt);
        if(v.size() == 1){
            ans = 0;
            for(int i=1;i<n;i++) ans += i;
            cout << ans << "\n";
        }else{
            int p = 0;
            for(int i=0;i<n;i++){
                if(s[i] == '1'){
                    ll cur = 0;
                    cur += ((ll)(n-i)) * v[p];
                    cur += 1;
                    for(int j=1;j<v[p];j++) cur += j;
                    cur += ((ll)(i+1)) * v[p+1];
                    for(int j=1;j<v[p+1];j++) cur += j;
                    ans = max(ans, cur);
                    p++;
                }
            }
            cout << ans << "\n";
        }
    }
}
