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
        int n;
        cin >> n;
        vector<int > v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        int bp = 0, ep = n-1;
        vector<int > ans(n);
        sort(v.begin(), v.end());
        int cur = -1;
        for(int i=0;i<n;i++){
            if(v[i] > cur){
                cur = v[i];
                ans[bp++] = v[i];
            }else ans[ep--] = v[i];
        }
        for(int i=0;i<n;i++) cout << ans[i] << " ";
        cout << "\n";
    }
}