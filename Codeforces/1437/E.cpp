#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int v[500005];
vector<int> b;

int LIS(int a, int b){ // ]a,b[
    vector<int> dp(b-a+1, INF_INT);
    dp[0] = v[a];
    int ans = 0;
    for(int i=a+1;i<b;i++){
        if(v[i] > v[b] || v[i] < v[a]) continue;
        int ind = upper_bound(dp.begin(), dp.end(), v[i]) - dp.begin();
        dp[ind] = v[i];
        ans = max(ans, ind);
    }
    int ttn = b-a-1;
    return ttn - ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    cin >> n >> k;
    v[0] = -INF_INT;
    v[n+1] = INF_INT;
    for(int i=1;i<=n;i++){
        cin >> v[i];
        v[i] -= i;
    }
    for(int i=0;i<k;i++){
        int aux;
        cin >> aux;
        b.push_back(aux);
    }
    int ans = 0;
    if(k == 0){
        //LIS
        ans = LIS(0, n+1);
    }else{
        //bounded LIS to b0, LIS from b.back()
        bool ok = true;
        for(int i=1;i<b.size();i++){
            if(v[b[i]] < v[b[i-1]]){
                ok = false;
                break;
            }
            ans += LIS(b[i-1], b[i]);
        }
        if(!ok){
            ans = -1;
        }else{
            ans += LIS(0, b[0]);
            ans += LIS(b.back(), n+1);
        }
    }
    cout << ans << "\n";
}
