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
        cin >> n;
        vector<int> w(n), p(n);
        ll ttp = 0;
        vector<int> sub;
        for(int i=0;i<n;i++){
            cin >> w[i] >> p[i];
            ttp += p[i];
            sub.push_back(w[i] + p[i]);
        }
        sort(sub.begin(), sub.end());
        int ans = 0;
        for(auto x : sub){
            if(ttp >= x){
                ttp -= x;
                ans++;
            }
        }
        cout << ans << "\n";
    }
}
