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
        ll cb = 0;
        ll n;
        cin >> n;
        ll ans = (n * (n+1))/2;
        vector<int> cn(11);
        vector<int> ls(11, -1);
        map<int, vector<int>> mp[11];
        for(int i=1;i<=10;i++) mp[i][0].push_back(0);
        for(int i=1;i<=n;i++){
            int x;
            cin >> x;
            ls[x] = i;
            for(int j=1;j<=10;j++){
                if(x >= j) cn[j]++;
                else cn[j]--;
                cb += lower_bound(mp[j][cn[j]].begin(), mp[j][cn[j]].end(), ls[j]) - mp[j][cn[j]].begin();
                mp[j][cn[j]].push_back(i);
            }
            
        }
        ans -= cb;
        cout << ans << "\n";
    }
}
