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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v(n, vector<int>(m));
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> v[i][j];
        int lo = 1, hi = n, mid;
        while(lo != hi){
            mid = lo + (hi - lo + 1)/2;
            vector<vector<int>> x(n, vector<int>(m));
            for(int i=0;i<m;i++) x[0][i] = (v[0][i] >= mid ? 1 : 0);
            bool ok = false;
            for(int i=1;i<n;i++){
                for(int j=0;j<m;j++){
                    if(v[i][j] >= mid) x[i][j] = x[i-1][j]+1;
                    else x[i][j] = 0;
                }
                int len = 0, maxlen = 0;
                for(int j=0;j<m;j++){
                    if(x[i][j] >= mid) len++;
                    else len = 0;
                    maxlen = max(len, maxlen);
                }
                if(maxlen >= mid){
                    ok = true;
                    break;
                }
            }
            if(ok) lo = mid;
            else hi = mid-1;
        }
        cout << lo << "\n";
    }
}
