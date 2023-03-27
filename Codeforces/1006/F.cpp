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
    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<ll>> v(n, vector<ll>(m));
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> v[i][j];
    ll ans = 0;
    if(n > 1 || m > 1){
        for(int i=0;i<min(n,m);i++){
            int L = i, R = m-i-1;
            int L2 = n-i-1, R2 = i;
            map<ll,int> mp;
            string s;
            for(int j=0;j<L;j++) s += 'L'; //down
            for(int j=0;j<R;j++) s += 'R'; //right
            do{
                int x = 0, y = 0;
                ll cur = 0;
                for(int i=0;i<s.size();i++){
                    cur ^= v[x][y];
                    if(s[i] == 'L') x++;
                    if(s[i] == 'R') y++;
                }
                mp[cur]++;
            }while(next_permutation(s.begin(), s.end()));
            s.clear();
            for(int j=0;j<L2;j++) s += 'L'; //down
            for(int j=0;j<R2;j++) s += 'R'; //right
            do{
                int x = L, y = R;
                ll cur = 0;
                for(int i=0;i<s.size();i++){
                    cur ^= v[x][y];
                    if(s[i] == 'L') x++;
                    if(s[i] == 'R') y++;
                }
                cur ^= v[x][y];
                if(mp.count(k^cur)) ans += mp[k^cur];
            }while(next_permutation(s.begin(), s.end()));
        }
        cout << ans << "\n";
    }else{
        ll cur = 0;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) cur ^= v[i][j];
        if(cur == k) cout << "1\n";
        else cout << "0\n";
    }

}
