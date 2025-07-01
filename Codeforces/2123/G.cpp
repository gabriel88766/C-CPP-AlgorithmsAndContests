#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int mp[500005];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, m, q;
        cin >> n >> m >> q;
        vector<int> v(n+1);
        for(int i=1;i<=n;i++) cin >> v[i];
        vector<int> dv;
        for(int i=1;i*i<=m;i++){
            if(m % i == 0){
                if(i*i != m) dv.push_back(m/i);
                dv.push_back(i);
            }
        }
        sort(dv.begin(), dv.end());
        vector<vector<int>> vx(dv.size(), vector<int>(n+1));
        vector<int> cnt(dv.size());
        for(int i=0;i<dv.size();i++) mp[dv[i]] = i;
        for(int i=0;i<dv.size();i++){
            for(int j=1;j<=n;j++){
                vx[i][j] = v[j] % dv[i];
                if(vx[i][j] < vx[i][j-1]) cnt[i]++;
            }
        }
        for(int i=1;i<=q;i++){
            int tq, j, x;
            cin >> tq;
            if(tq == 1){
                cin >> j >> x;
                //update information about equiv g used below
                for(int i=0;i<dv.size();i++){
                    if(vx[i][j] < vx[i][j-1]) cnt[i]--;
                    if(j < n && vx[i][j+1] < vx[i][j]) cnt[i]--;
                    vx[i][j] = x % dv[i];
                    if(vx[i][j] < vx[i][j-1]) cnt[i]++;
                    if(j < n && vx[i][j+1] < vx[i][j]) cnt[i]++;
                }
            }else{
                cin >> x;
                int g = gcd(m, x);
                //well, I need to have some information stored about equiv g.
                //the equiv value mod g can't change, but I can change to (m/g) k + r for any k < g
                j = mp[g];
                // cout << g << " " << j << " " << cnt[j] << "\n";
                if(cnt[j] < m/g) cout << "YES\n";
                else cout << "NO\n";
                
            }
        }
    }
}
