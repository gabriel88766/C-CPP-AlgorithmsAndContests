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
        vector<int> cnt(n+2);
        for(int i=1;i<=n;i++){
            int x;
            cin >> x;
            cnt[x]++;
        }
        int x = 1, c = 0;
        while(x < n){
            x *= 2;
            c++;
        }
        for(int i=1;i<=n;i++) cnt[i] += cnt[i-1];
        cnt[n+1] = INF_INT;
        int ans = INF_INT;
        for(int i=0;i<=c;i++){
            for(int j=0;j<=c;j++){
                auto ind = lower_bound(cnt.begin(), cnt.end(), (1 << i) + 1) - cnt.begin();
                ind--;
                ind = lower_bound(cnt.begin(), cnt.end(), (1 << j) + cnt[ind] + 1) - cnt.begin();
                ind--;
                int k = 1;
                while(k < (n - cnt[ind])) k *= 2;
                ans = min(ans, k + (1 << i) + (1 << j) - n);
            }
        }
        cout << ans << "\n";
    }
}
