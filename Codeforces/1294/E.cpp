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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int> (m));
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> v[i][j];
    int ans = 0;
    for(int j=0;j<m;j++){
        //analyse collumn j+1, m+j+1, ...
        vector<int> cnt(n, 0); //shift between 0 and n-1
        for(int i=0;i<n;i++){
            int r = (v[i][j]) % m;
            int q = (v[i][j]) / m;
            if(r != ((j+1)%m)) continue;
            if(j == (m-1)) q--;
            if(q >= n) continue;
            int sh = (n + i - q) % n;
            cnt[sh]++;
        }
        int minv = INF_INT;
        for(int i=0;i<=(n-1);i++) minv = min(minv, n-cnt[i]+i);
        ans += minv;

    }
    cout << ans << "\n";
}
