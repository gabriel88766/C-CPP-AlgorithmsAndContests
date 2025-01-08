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
        vector<bool> used(n+1, false);
        vector<int> ans(n, 1);
        int p = 0;
        for(int j=0;j<n;j++){
            int x;
            cin >> x;
            if(!used[x]){
                ans[p++] = x;
                used[x] = true;
            }
        }
        for(int j=1;j<=n;j++){
            if(!used[j]) ans[p++] = j;
        }
        for(int i=0;i<n;i++) cout << ans[i] << " ";
        cout << "\n";
    }
}
