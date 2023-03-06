#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i].first;
        v[i].second = i+1;
    }
    
    int qt1= 0;
    for(int i=0;i<n;i++) if(v[i].first == 1) qt1++;
    if(qt1 == n) cout << "0\n";
    else if(qt1 != 0) cout << "-1\n";
    else{
        vector<pair<int,int>> ans;
        for(int i=0; i<30;i++){
            bool fini = true;
            sort(v.begin(), v.end());
            for(int j=1;j<n;j++){
                if(v[j].first != v[0].first){
                    fini = false;
                    v[j].first = (v[j].first / v[0].first) + (v[j].first % v[0].first ? 1 : 0);
                    ans.push_back({v[j].second, v[0].second});
                }
            }
            if(fini) break;
        }
        cout << ans.size() << "\n";
        for(int i=0;i<ans.size();i++) cout << ans[i].first << " " << ans[i].second << "\n";        
    }

}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
