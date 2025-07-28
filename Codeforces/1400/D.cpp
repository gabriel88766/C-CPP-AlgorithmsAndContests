#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3005;
ll cnt2[N][N];
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
        vector<int> v(n+1);
        vector<int> an;
        for(int i=1;i<=n;i++){
            cin >> v[i];
            an.push_back(v[i]);
        }
        sort(an.begin(), an.end());
        an.resize(unique(an.begin(), an.end()) - an.begin());
        ll ans = 0;
        for(int i=n;i>=1;i--){
            for(int j=1;j<i;j++){
                ans += cnt2[v[j]][v[i]];
            }
            for(int j=i+1;j<=n;j++){
                cnt2[v[i]][v[j]]++;
            }
        }
        cout << ans << "\n";
        for(auto x : an){
            for(auto y : an){
                cnt2[x][y] = 0;
            }
        }
    }
}
