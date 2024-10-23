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
        vector<int> ex(n);
        for(int i=0;i<n;i++) cin >> ex[i];
        vector<string> str(n);
        for(int i=0;i<n;i++) cin >> str[i];
        vector<int> vm(m);
        for(int j=0;j<m;j++){
            int cm = 0;
            for(int i=0;i<n;i++){
                if(str[i][j] == '1') cm |= (1 << i);
            }
            vm[j] = cm;
        }
        int bm = -1;
        ll ba = 0;
        for(int msk=0;msk<(1 << n);msk++){
            //meaning, 0 is minimize, 1 is maximize
            ll ca = 0;
            for(int j=0;j<n;j++){
                if(msk & (1 << j)){
                    ca -= ex[j];
                }else{
                    ca += ex[j];
                }
            }
            //this solution will be 2^n  * m, can be improved?!
            vector<int> cnt(2*n+1);
            for(int j=0;j<m;j++){
                int aux = __builtin_popcount(vm[j] & msk); // sum it
                int aux2 = __builtin_popcount(vm[j] & (~msk)); //sub it
                // 0 is sum n, n is minus n
                cnt[aux-aux2 + n]++;
            }
            int p = 0;
            for(int j=0;j<m;j++){
                while(!cnt[p]) p++;
                ll fac = p - n;
                ca += fac * (j+1);
                cnt[p]--;
            }
            if(ca > ba){
                ba = ca;
                bm = msk;
            }
        }
        vector<int> cnt(2*n+1);
        map<int,vector<int>> mp;
        for(int j=0;j<m;j++){
            int aux = __builtin_popcount(vm[j] & bm); // sum it
            int aux2 = __builtin_popcount(vm[j] & (~bm)); //sub it
            // 0 is sum n, n is minus n
            mp[aux-aux2].push_back(j);
        }
        vector<int> ans(m);
        int cur = 0;
        for(auto [k, v] : mp){
            for(auto j : v){
                ans[j] = ++cur;
            }
        }
        for(int j=0;j<m;j++) cout << ans[j] << " ";
        cout << "\n";
    }
}   
