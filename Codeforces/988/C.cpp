#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int k;
    cin >> k;
    map<int, pair<int,int>> mp;
    pair<int,int> ans[2];
    bool ok = false;
    for(int j=1;j<=k;j++){
        if(ok){
            int n, aux;
            cin >> n;
            for(int i=0;i<n;i++) cin >> aux; 
        }else{
            int n;
            cin >> n;
            vector<int> v(n);
            for(int i=0;i<n;i++) cin >> v[i];
            int sum = 0;
            for(int i=0;i<n;i++) sum += v[i];
            for(int i=0;i<n;i++){
                int cs = sum - v[i];
                if(mp[cs] == make_pair(0, 0)) mp[cs] = {j, i+1};
                else{
                    if(mp[cs].first == j) continue;
                    else{
                        //hit!
                        ok = true;
                        ans[0] = mp[cs];
                        ans[1] = {j, i+1};
                        break;
                    }
                }
            }
        }
    }
    if(ok) cout << "YES\n" << ans[0].first << " " << ans[0].second << "\n" << ans[1].first << " " << ans[1].second << "\n";
    else cout << "NO";
    
}
