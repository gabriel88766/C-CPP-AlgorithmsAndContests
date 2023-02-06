
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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> ans(n);
        vector<pair<int,int>> vp;
        for(int i=0;i<n;i++){
            int aux;
            cin >> aux;
            vp.push_back({aux, i});
        }
        sort(vp.begin(), vp.end());
        for(int i=0;i<(n-1);i++){
            ans[vp[i].second] = vp[i].first - vp[n-1].first;
        }
        ans[vp[n-1].second] = vp[n-1].first - vp[n-2].first;
        for(int i=0;i<n; i++) cout << ans[i] << " ";
        cout << "\n";
    }
}
