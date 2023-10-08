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
        ll n, m, k;
        cin >> n >> m >> k;
        deque<ll> u(n);
        deque<ll> v(m);
        for(int i=0;i<n;i++) cin >> u[i];
        for(int i=0;i<m;i++) cin >> v[i];
        
        vector<ll> ans(101, 0);
        for(int i=1;i<=100;i++){
            sort(u.begin(), u.end());
            sort(v.begin(), v.end());
            ll sum = 0;
            for(int j=0;j<u.size();j++) sum += u[j];
            ans[i-1] = sum;
            if(i % 2){
                int x = u[0]; 
                int y = v.back();
                if(x >= y) continue;
                u.pop_front();
                v.pop_back();
                u.push_back(y);
                v.push_back(x);
            }else{
                int x = v[0]; 
                int y = u.back();
                if(x >= y) continue;
                v.pop_front();
                u.pop_back();
                v.push_back(y);
                u.push_back(x);
            }
        }
        if(k < 80){
            cout << ans[k] << "\n";
        }else{
            k = 10 + (k % 2);
            cout << ans[k] << "\n";
        }
    }
}
