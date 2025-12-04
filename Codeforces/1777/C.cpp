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
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin >> a[i];
        sort(a.begin(), a.end());
        a.resize(unique(a.begin(), a.end()) - a.begin());
        int p = 0, s = 0;
        int ans = INF_INT;
        vector<int> cnt(m+1, 0);
        for(int i=0;i<a.size();i++){
            while(s != m && p < a.size()){
                for(int j=1;j*j <= a[p]; j++){
                    if(a[p] % j == 0){
                        if(j <= m){
                            if(cnt[j] == 0) s++;
                            cnt[j]++;
                        }
                        if(j*j != a[p] && a[p]/j <= m){
                            if(cnt[a[p]/j] == 0) s++;
                            cnt[a[p]/j]++;
                        }
                    }
                }
                p++;
            }
            if(s == m){
                ans = min(ans, a[p-1] - a[i]);
            }
            for(int j=1;j*j <= a[i]; j++){
                if(a[i] % j == 0){
                    if(j <= m){
                        cnt[j]--;
                        if(cnt[j] == 0) s--;
                    }
                    if(j*j != a[i] && a[i]/j <= m){
                        cnt[a[i]/j]--;
                        if(cnt[a[i]/j] == 0) s--;
                    }
                }
            }
        }
        if(ans == INF_INT) cout << "-1\n";
        else cout << ans << "\n";
    }
}
