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
        vector<int> ans(n+1,0), v(n+1);
        vector<bool> used(n+1, false);
        for(int i=1;i<=n;i++){
            cin >> v[i];
            if(!used[v[i]]){
                ans[i] = v[i];
                used[v[i]] = true;
            }
        }
        int cur = 1;
        bool ok = true;
        for(int i=1;i<=n;i++){
            while(used[cur]) cur++;
            if(!ans[i]){
                ans[i] = cur;
                used[cur] = true;
                if(ans[i] > v[i]){
                    ok = false;
                    break;
                }
            }
        }
        if(!ok) cout << "-1\n";
        else{
            for(int i=1;i<=n;i++) cout << ans[i] << " ";
            cout << "\n";
        }
    }
}
