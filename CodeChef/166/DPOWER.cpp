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
        vector<pair<int,int>> vp;
        for(int i=1;i<=n;i++){
            int x;
            cin >> x;
            vp.push_back({x, i});
        }
        sort(vp.begin(), vp.end(), greater<pair<int,int>>());
        int ans = 1;
        for(int i=1;i<n;i++){
            if(abs(vp[i].second - vp[i-1].second) != 1) ans++;
        }
        cout << ans << "\n";
    }
}
