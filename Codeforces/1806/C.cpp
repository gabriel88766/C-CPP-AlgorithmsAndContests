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
        vector<int> v(2*n);
        for(int i=0;i<2*n;i++) cin >> v[i];
        ll ans = 0;
        if(n == 1){
            ans = abs(v[0]-v[1]);
        }else if(n == 2){
            vector<int> p1 = {-1,-1,-1,2};
            ll cur = 0;
            for(int i=0;i<4;i++) cur += abs(v[i]-2);
            ans = cur;
            cur = 0;
            for(int i=0;i<4;i++) cur += abs(v[i]);
            ans = min(cur, ans);
            do{
                cur = 0;
                for(int i=0;i<4;i++) cur += abs(v[i]-p1[i]);
                ans = min(ans, cur);
            }while(next_permutation(p1.begin(), p1.end()));
        }else if(n % 2){
            for(int i=0;i<2*n;i++) ans += abs(v[i]);
        }else{
            for(int i=0;i<2*n;i++) ans += abs(v[i]);
            ll sum = 0;
            for(int i=0;i<2*n;i++) sum += abs(v[i]+1);
            for(int i=0;i<2*n;i++){
                ll cur = sum - abs(v[i]+1);
                cur += abs(v[i]-n);
                ans = min(ans, cur);
            }
        }
        cout << ans << "\n";
    }
    
}
