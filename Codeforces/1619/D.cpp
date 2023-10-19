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
        cin >> m >> n;
        vector<vector<int>> p(m, vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin >> p[i][j];
            }
        }
        int hi = INF_INT;
        for(int i=0;i<n;i++){
            int cur = 0;
            for(int j=0;j<m;j++){
                if(p[j][i] > cur){
                    cur = p[j][i];
                }
            }
            hi = min(hi, cur);
        }
        int lo = 1;
        while(lo != hi){
            int mid = lo + (hi - lo + 1) / 2;
            bool ok = false;
            for(int i=0;i<m;i++){
                int cnt = 0;
                for(int j=0;j<n;j++){
                    if(p[i][j] >= mid) cnt++;
                }
                if(cnt >= 2) ok = true;
            }
            if(ok) lo = mid;
            else hi = mid - 1;
        }
        cout << lo << "\n";
    }
}
