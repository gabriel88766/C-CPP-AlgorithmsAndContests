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
    vector<int> alln;
    vector<bool> comp(200101, false);
    for(int i=2;i<=200100;i++){
        if(!comp[i]){
            for(ll j=i; j <= 200100; j *= i){
                alln.push_back(j);
            }
            for(int j=2*i;j<=200100;j+=i) comp[j] = true;
        }
    }
    sort(alln.begin(), alln.end());
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n+1);
        vector<vector<int>> idx(n+1);
        for(int i=1;i<=n;i++){
            cin >> v[i];
            idx[v[i]].push_back(i);
        }
        vector<int> ans;
        for(auto x : alln){
            //check if suitable
            vector<int> sq;
            sq.push_back(0);
            sq.push_back(n+1);
            for(int j = x; j <= n; j += x){
                for(auto id : idx[j]){
                    sq.push_back(id);
                }
            }
            sort(sq.begin(), sq.end());
            sq.resize(unique(sq.begin(), sq.end()) - sq.begin());
            bool ok = false;
            for(int j = 1; j < sq.size(); j++){
                int l = sq[j-1] + 1;
                int r = sq[j-1] - 1;
                if(r >= l){
                    //need to find all divs in [l, r]
                    
                }
            }
            if(ok) ans.push_back(x);
            if(x > n) break;
        }
        cout << ans.size() << "\n";
        for(auto x : ans) cout << x << " ";
        cout << "\n";
    }
}
