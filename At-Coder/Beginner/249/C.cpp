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
    int n, k;
    cin >> n >> k;
    vector<string> vs(n);
    for(int i=0;i<n;i++) cin >> vs[i];
    int ans = 0;
    for(int i=1;i<(1 << n);i++){
        vector<int> cnt(26, 0);
        for(int j=0;j<n;j++){
            if(i & (1 << j)){
                for(auto c : vs[j]) cnt[c-'a']++;
            }
        }
        int cur = 0;
        for(int j=0;j<26;j++) if(cnt[j] == k) cur++;
        ans = max(ans, cur);
    }
    cout << ans << "\n";
}
