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
    ll n, k;
    cin >> n >> k;
    if(n >= 2*k){
        vector<vector<int>> vin(n+1);
        vector<vector<int>> vout(n+1);
        vector<int> lout(n+1);
        vector<int> ans(n+1);
        vector<bool> used(n+1);
        for(int i=1;i<=n;i++){
            int i1 = -1, o1 = -1, i2 = -1, o2 = -1;
            if(abs(i-1) >= k){
                i1 = 1;
                o1 = i - k;
                vin[i1].push_back(i);
                vout[o1+1].push_back(i);
            }
            if(abs(n-i) >= k){
                //j - i >= k; j = i + k
                i2 = i + k;
                o2 = n;
                vin[i2].push_back(i);
            }else{
                lout[o1] = i;
            }
        }
        set<int> s;
        for(int i=1;i<=n;i++){
            for(auto x : vin[i]){
                if(!used[x]) s.insert(x);
            }
            for(auto x : vout[i]){
                s.erase(x);
            }
            if(lout[i] && used[lout[i]] == false){
                used[lout[i]] = true;
                ans[i] = lout[i];
                s.erase(lout[i]);
            }else{
                int now = *s.begin();
                ans[i] = now;
                s.erase(*s.begin());
                used[now] = true;
            }
        }
        for(int i=1;i<=n;i++) cout << ans[i] << " ";
        cout << "\n";

    }else cout << "-1\n";
}    
