#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

pair<int, int> findKth(int n, ll k){// O(n)
    for(int i=1;i<=n;i++){
        if(k <= n-i){
            return make_pair(i, i+k);
        }else k -= n - i;
    }
    return make_pair(-1, -1);
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n, l, r;
    cin >> n >> l >> r;
    auto [l1, r1] = findKth(n, l);
    auto [l2, r2] = findKth(n, r);
    vector<int> ans(n+1);
    for(int i=1;i<=n;i++) ans[i] = i;
    if(l1 == l2){
        for(int i=r1;i<=r2;i++) swap(ans[l1], ans[i]);
    }else{
        for(int i=r1;i<=n;i++) swap(ans[l1], ans[i]);
        //make rotations
        if(l2 != l1 + 1){
            vector<int> aux = ans;
            int x = 0;
            for(int i=l1+1;i<l2;i++){
                aux[i] = ans[n-x];
                x++;
            }
            int u = 0;
            for(int i=l1+1;i<=n-x;i++){
                aux[l2 + u] = ans[i];
                u++;
            }

            ans = aux;
        }
        //last swaps
        for(int i=l2+1;i<=r2;i++) swap(ans[l2], ans[i]);
    }
    for(int i=1;i<=n;i++) cout << ans[i] << " ";
    cout << "\n";
}
