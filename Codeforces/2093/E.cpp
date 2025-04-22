#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
int v[N];
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
        int q0 = 0;
        for(int i=1;i<=n;i++){
            cin >> v[i];
            if(v[i] == 0) q0++;
        }
        if(q0 >= k){
            int lo = 0, hi = n+1;
            while(lo != hi){
                int tt = 0;
                int mid = lo + (hi - lo + 1)/2;
                vector<bool> us(mid+1, false);
                int ac = 0;
                for(int i=1;i<=n;i++){
                    if(v[i] <= mid && us[v[i]] == false){
                        ac++;
                        us[v[i]] = true;
                    }
                    if(ac == mid + 1){
                        tt++;
                        ac = 0;
                        for(int j=0;j<=mid;j++) us[j] = false;
                    }
                }
                if(tt >= k) lo = mid;
                else hi = mid - 1;
            }
            cout << lo+1 << "\n";
        }else cout << "0\n";
    }
}
