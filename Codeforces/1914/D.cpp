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
        vector<vector<pair<int,int>>> v(3, vector<pair<int,int>>(n));
        for(int i=0;i<3;i++){
            for(int j=0;j<n;j++){
                cin >> v[i][j].first;
                v[i][j].second = j;
            }
            sort(v[i].begin(), v[i].end(), greater<pair<int,int>>());
        }
        vector<int> perm = {0, 1, 2};
        int ans = 0;
        do{
            vector<int> used(n, false);
            int cur = 0;
            for(auto x : perm){
                int p = 0;
                while(used[v[x][p].second]) p++;
                used[v[x][p].second] = true;
                cur += v[x][p].first;
            }
            ans = max(ans, cur);
        }while(next_permutation(perm.begin(), perm.end()));
        cout << ans << "\n";
        
    }
}
