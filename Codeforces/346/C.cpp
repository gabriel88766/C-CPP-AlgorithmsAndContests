#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+3;
int lst[N], dp[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, a, b;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    cin >> a >> b;
    memset(lst, 63, sizeof(lst));
    memset(dp, 63, sizeof(dp));
    dp[a - b] = 0;
    queue<int> q;
    q.push(a-b);
    for(auto x : v){
        int fx = ((b + x - 1) / x) * x;
        assert(fx >= b);
        for(int j = fx; j < a; j += x){
            lst[min(j + x - 1 - b, a - b)] = min(lst[min(j + x - 1 - b, a - b)], j - b);
        }
    }
    int px = a - b;
    while(q.size()){
        auto u = q.front();
        q.pop();
        if(u == 0) break;
        if(dp[u-1] > dp[u] + 1){
            dp[u-1] = dp[u] + 1;
            q.push(u - 1);
        }
        while(px >= u){
            if(lst[px] != INF_INT){
                auto v = lst[px];
                if(dp[v] > dp[u] + 1){
                    dp[v] = dp[u] + 1;
                    q.push(v);
                }
            }
            px--;
        }
    }
    cout << dp[0] << "\n";
}
