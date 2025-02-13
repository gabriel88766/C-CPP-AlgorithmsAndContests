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
        vector<vector<int>> vx(k);
        for(int i=1;i<=n;i++){
            int x;
            cin >> x;
            vx[x%k].push_back(i);
        }
        bool ok = false;
        for(int i=0;i<k;i++){
            if(vx[i].size() == 1){
                if(!ok){
                    ok = true;
                    cout << "YES\n" << vx[i][0] << "\n";
                }
            }
        }
        if(!ok) cout << "NO\n";
    }
}
