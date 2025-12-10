#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;
vector<ll> sum[N];
ll s[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    ll ans = 0;
    for(int i=0;i<n;i++) cin >> s[i];
    for(int i=1;i<n;i++){
        sum[i].push_back(s[0]);
        for(int j=i;j<n;j+=i){
            if(j == i) sum[i].push_back(s[j]);
            else sum[i].push_back(sum[i].back() + s[j]);
        }
    }
    for(int i=1;i<n;i++){
        ll cur = 0;
        int cnt = 0;
        for(int j=n-1;j >= 0; j -= i){
            cur += s[j];
            if(j <= i) break;
            if(j % i != 0 || cnt * i < j){
                //then no overlap
                assert(cnt < sum[i].size());
                ans = max(ans, cur + sum[i][cnt]);
            }
            cnt++;
        }
    }
    cout << ans << "\n";
}
