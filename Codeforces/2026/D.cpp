#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3e5+3;
ll aux[N];
pair<int, int> findKth(int n, ll k){// O(log n)
    int i = 0;
    for(int j=n/2;j>=1;j>>=1){
        while(i + j <= n && aux[i+j] < k) i += j;
    }
    k -= aux[i];
    i += 1;
    int j = i + k - 1;
    return make_pair(i, j);
}
/* 
auto [l1, r1] = findKth(n, l);
auto [l2, r2] = findKth(n, r);
*/


ll v[N], sum[N], ps[N], ps2[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n;
    for(int i=1;i<=n;i++) aux[i] = aux[i-1] + n - i + 1;
    for(int i=1;i<=n;i++){
        cin >> v[i];
        sum[i] = (n-i+1) * v[i]; 
        ps2[i] = ps2[i-1] + v[i];
    }
    for(int i=n-1;i>=1;i--){
        sum[i] += sum[i+1];
    }
    for(int i=1;i<=n;i++) ps[i] = ps[i-1] + sum[i];
    auto sumit = [&](int i, int j){
        if(j < i) return 0LL;
        ll ans = sum[i] - sum[j+1];
        int dif = n - j;
        ans -= dif * (ps2[j] - ps2[i-1]); 
        return ans;
    };
    cin >> q;
    for(int i=0;i<q;i++){
        ll l, r;
        cin >> l >> r;
        auto [l1, r1] = findKth(n, l);
        auto [l2, r2] = findKth(n, r);
        ll ans = 0;
        if(l1 == l2){
            ans = sumit(l1, r2) - sumit(l1, r1-1);
        }else{
            ans = sumit(l1, n) - sumit(l1, r1-1);
            ans += ps[l2-1] - ps[l1]; //maybe 0
            ans += sumit(l2, r2);
        }
        cout << ans << "\n";
        
    }


    

}
