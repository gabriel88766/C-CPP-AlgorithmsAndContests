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
    int n;
    cin >> n;
    vector<int> p(n+1);
    for(int i=1;i<=n;i++) cin >> p[i];
    vector<vector<int>> ans;
    for(int i=1;i<=n;i++){
        if(i != p[i]){
            vector<int> prm;
            prm.push_back(p[i]);
            while(prm.back() != i){
                prm.push_back(p[prm.back()]);
            }
            reverse(prm.begin(), prm.end());
            ans.push_back(prm);
            // cout << prm.size() << "\n";
            // for(auto x : prm) cout << x << " ";
            // cout << "\n";
            for(auto x : prm) p[x] = x;
        }
    }
    cout << ans.size() << "\n";
    for(auto vec : ans){
        cout << vec.size() << "\n";
        for(auto x : vec) cout << x << " ";
        cout << "\n";
    }
}
