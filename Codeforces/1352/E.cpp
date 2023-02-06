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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> ps(n+1, 0);
        for(int i=1;i<=n;i++){
            int aux;
            cin >> aux;
            ps[i] = ps[i-1] + aux;
        }
        int cnt = 0;
        for(int i=1;i<=n;i++){
            int cur = ps[i] - ps[i-1];
            int bp = 0, ep = 1;
            while(ep <= n){
                if(ps[ep] - ps[bp] == cur){
                    if(ep != (bp+1)){
                        cnt++;
                        break;
                    }else ep++;
                }else if(ps[ep] - ps[bp] < cur) ep++;
                else bp++;
            }
        }
        cout << cnt << "\n";
    }
}
