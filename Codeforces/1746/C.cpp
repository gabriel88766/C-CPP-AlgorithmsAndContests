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
        vector<int> v(n+1), ans(n+1);
        for(int i=1;i<=n;i++) cin >> v[i];
        set<int> s;
        for(int i=1;i<=n;i++) s.insert(i);
        for(int i=n;i>=2;i--){
            if(v[i-1] > v[i]){
                auto it = s.upper_bound(v[i-1] - v[i]);
                assert(it != s.end());
                ans[*it] = i;
                s.erase(it);
            }
        }
        for(auto x : s){
            ans[x] = 1;
        }
        for(int i=1;i<=n;i++) cout << ans[i] << " ";
        cout << "\n";
    }
}
