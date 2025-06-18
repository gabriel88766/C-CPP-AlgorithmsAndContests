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
        ll n, s, x;
        cin >> n >> s >> x;
        queue<ll> q;
        q.push(0);
        ll ps = 0;
        map<ll, ll> mp;
        ll ans = 0;
        for(int i=1;i<=n;i++){
            ll cv;
            cin >> cv;
            ps += cv;
            if(cv > x){
                mp.clear();
                while(q.size()) q.pop();
                q.push(ps);
            }else if(cv == x){
                while(q.size()){
                    mp[q.front()]++;
                    q.pop();
                }
                q.push(ps);
            }else q.push(ps);
            if(mp.count(ps - s)) ans += mp[ps - s];
        }
        cout << ans << "\n";
    }
}
