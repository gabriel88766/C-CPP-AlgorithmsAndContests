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
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        map<int, int> cnt;
        for(int i=0;i<m;i++){
            int aux;
            cin >> aux;
            cnt[aux]++;
        }
        map<int, int> cur;
        int cqt = 0;
        for(int i=0;i<m;i++){
            if(cur[v[i]] < cnt[v[i]]){
                cqt++;
            }
            cur[v[i]]++;
        }
        int ans = 0;
        if(cqt >= k) ans++;
        for(int i=m;i<n;i++){
            if(cur[v[i-m]] <= cnt[v[i-m]]) cqt--;
            cur[v[i-m]]--;
            if(cur[v[i]] < cnt[v[i]]) cqt++;
            cur[v[i]]++;
            if(cqt >= k) ans++;
        }
        cout << ans << "\n";
    }
}
