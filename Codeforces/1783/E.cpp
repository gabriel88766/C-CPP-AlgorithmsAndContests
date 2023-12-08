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
        vector<int> a(n+1), b(n+1), ps(n+1, 0);
        for(int i=1;i<=n;i++) cin >> a[i];
        for(int i=1;i<=n;i++) cin >> b[i];
        for(int i=1;i<=n;i++){
            if(a[i] > b[i]){
                ps[b[i]]++;
                ps[a[i]]--;
            }
        }
        for(int i=1;i<=n;i++) ps[i] += ps[i-1];
        vector<int> ans;
        for(int i=1;i<=n;i++){
            bool ok = true;
            for(int j=i;j<=n;j+=i){
                if(ps[j]) ok = false;
            }
            if(ok) ans.push_back(i);
        }
        cout << ans.size() << "\n";
        for(auto x : ans) cout << x << " ";
        cout << "\n";
    }
}
