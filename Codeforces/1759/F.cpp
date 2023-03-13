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
        ll n, p;
        cin >> n >> p;
        vector<ll> a(n);
        map<int,int> mp;
        for(int i=0;i<n;i++){
             cin >> a[i];
            mp[a[i]] = 1;
        }
        int minv = -INF_INT, maxv = INF_INT;
        for(int i=0;i<min(1000LL, p);i++){
            if(!mp.count(i)){
                minv = i;
                break;
            }
        }
        for(int i=p-1; i>= max(p-1000, 0LL); i--){
            if(!mp.count(i)){
                maxv = i;
                break;
            }
        }
        if(minv < 0) cout << "0\n";
        else{
            if(minv < a[n-1]){
                ll ans = p-a[n-1];
                if(n > 1){
                    for(int i=n-2;i>=0;i--){
                        if(i != 0){
                            if(a[i] != (p-1)){
                                mp[a[i]+1] = 1;
                                break;
                            }
                        }else{
                            if(a[i] == (p-1)){
                                mp[1] = 1;
                            }else{
                                mp[a[i]+1] = 1;
                            }
                        }
                    }
                }else mp[1] = 1;
                for(int i=a[n-1]; i>= max(0LL, a[n-1]-1000);i--){
                    if(!mp.count(i)){
                        ans += i;
                        break;
                    }
                }
                cout << ans << "\n";
            }else{  
                cout << maxv-a[n-1] << "\n";
            }
        }
    }
}
