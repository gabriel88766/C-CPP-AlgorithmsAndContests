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
        string s;
        cin >> n >> s;
        reverse(s.begin(), s.end());
        int p = 1, cur = 0;
        vector<ll> ans(n+1, -1);
        ans[0] = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '1') cur++;
            else{
                ans[p] = ans[p-1] + cur;
                p++;
            }
        } 
        for(int i=1;i<=n;i++) cout << ans[i] << " ";
        cout << "\n";
    }
}
