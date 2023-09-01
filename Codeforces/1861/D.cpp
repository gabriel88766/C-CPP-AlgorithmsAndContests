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
        vector<int> v(n+1), pl(n+1,0), pr(n+1,0);
        for(int i=1;i<=n;i++) cin >> v[i];
        int ans = 0;
        for(int i=1;i<n;i++) if(v[i+1] <= v[i]) ans++; //only positive
        for(int i=1;i<n;i++){
            if(v[i+1] >= v[i]) pl[i+1]++;
            pl[i+1] += pl[i];
        }
        for(int i=n;i>1;i--){
            if(v[i-1] >= v[i]) pr[i-1]++;
            pr[i-1] += pr[i];
        }
        for(int i=2;i<=n;i++){
            ans = min(ans, pl[i-1] + 1 + pr[i]);
        }
        cout << ans << "\n";
    }
}
