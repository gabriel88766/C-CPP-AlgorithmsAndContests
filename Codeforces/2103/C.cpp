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
        int n, k;
        cin >> n >> k;
        vector<int> v(n+1), ps(n+1);
        for(int i=1;i<=n;i++){
            cin >> v[i];
            if(v[i] <= k) v[i] = 1;
            else v[i] = -1;
            ps[i] = ps[i-1] + v[i];
        }
        multiset<int> ms;
        for(int i=2;i<n;i++) ms.insert(ps[i]);
        bool ok = false;
        for(int i=1;i<n-1;i++){
            if(i >= 2) ms.erase(ms.find(ps[i]));
            int cs = ps[i] >= 0 ? 1 : 0;
            auto it = ms.lower_bound(ps[i]);
            if(it == ms.end()){
                if(ps[n] >= *ms.begin()) cs++;
            }else{
                cs++;
                if(ps[n] >= *it) cs++;
            }
            if(cs >= 2) ok = true;
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
