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
        vector<vector<int>> v(k+1), st(k+1);
        for(int i=1;i<=k;i++) v[i].push_back(0);
        for(int i=1;i<=n;i++){
            int x;
            cin >> x;
            v[x].push_back(i);
        }
        int ans = INF_INT;
        for(int i=1;i<=k;i++){
            v[i].push_back(n+1);
            for(int j=1;j<v[i].size();j++){
                st[i].push_back(v[i][j] - v[i][j-1] - 1);
            }
            sort(st[i].begin(), st[i].end(), greater<int>());
            int cur = 0;
            if(st[i].size() > 1) cur = st[i][1];
            cur = max(cur, st[i][0]/2);
            ans = min(ans, cur);
        }
        cout << ans << "\n";
    }
}
