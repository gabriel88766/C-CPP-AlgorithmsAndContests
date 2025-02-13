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
        vector<int> v(n+1);
        for(int i=1;i<=n;i++) cin >> v[i];
        int ans = 0;
        multiset<int> ms;
        ll ps = 0;
        for(int i=m+1;i<=n;i++){
            ps += v[i];
            if(v[i] < 0) ms.insert(v[i]);
            if(ps < 0){
                int x = *ms.begin();
                ms.erase(ms.begin());
                ps += 2*abs(x);
                ans++;
            }
        }
        ps = 0;
        ms.clear();
        for(int i=m;i>=2;i--){
            ps += v[i];
            if(v[i] > 0) ms.insert(v[i]);
            if(ps > 0){
                int x = *prev(ms.end());
                ms.erase(prev(ms.end()));
                ps -= 2*abs(x);
                ans++;
            }
        }
        



        cout << ans << "\n";
    }
}
