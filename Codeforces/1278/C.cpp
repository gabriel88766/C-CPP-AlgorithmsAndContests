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
        vector<int> v(2*n+1), ps(2*n+1);
        for(int i=1;i<=2*n;i++){
            cin >> v[i];
            if(v[i] == 1) ps[i] = ps[i-1] + 1;
            else ps[i] = ps[i-1] - 1;
            // cout << ps[i] << " ";
        }
        // cout << "\n";
        if(ps[2*n] == 0) cout << "0\n";
        else{
            int ans = 2*n;
            map<int,int> mp;
            for(int i=0;i<=n;i++){
                mp[ps[i]] = i;
            }
            for(int i=n;i<=2*n;i++){
                int goal = ps[i] - ps[2*n];
                if(mp.count(goal)) ans = min(ans, i - mp[goal]);
            }
            
            cout << ans << "\n";
        }
    }
}
