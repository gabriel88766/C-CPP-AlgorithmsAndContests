#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> xx[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(), v.end());
    for(int i=0;i<n;i++){
        int d = v[i], cnt = 0;
        while(d > 0){
            xx[d].push_back(cnt);
            d >>= 1;
            cnt++;
        }
    }
    int ans = INF_INT;
    for(int i=1;i<N;i++){
        if(xx[i].size() >= k){
            int cur = 0;
            for(int j=0;j<k;j++) cur += xx[i][j];
            ans = min(ans, cur);
        }
    }
    cout << ans << "\n";
}
