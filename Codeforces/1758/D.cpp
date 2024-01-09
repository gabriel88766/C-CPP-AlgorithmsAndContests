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
        vector<int> ans(n+1);
        ll sum = 0;
        for(int i=1;i<=n;i++){
            ans[i] = i;
            sum += i;
        }
        ans[n] += n-1;
        sum += n-1;
        ll sq = ans[n] - ans[1];
        sq *= sq;
        assert(sq >= sum);
        ll pls = (sq - sum)/n;
        for(int i=1;i<=n;i++) ans[i] += pls;
        sum += pls * n;
        assert(sq >= sum);
        ans[n-1] += sq - sum;
        assert(ans[n-1] < ans[n]);
        for(int i=1;i<=n;i++) cout << ans[i] << " ";
        cout << "\n";
    }
}
