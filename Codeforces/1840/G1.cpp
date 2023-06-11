#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    map<ll, ll> mp;
    ll cur;
    cin >> cur;
    ll cnt = 0;
    do{
        mp[cur] = cnt;
        ll x = 1;
        cout << "+ " << x << "\n";
        cout.flush();
        cnt += x;
        cin >> cur;
        if(mp.count(cur)){
            cout <<"! " << cnt-mp[cur] << "\n";
            return 0;
        }
    }while(cnt != 999);
    do{
        mp[cur] = cnt;
        ll x = 1000;
        cout << "+ " << x << "\n";
        cout.flush();
        cnt += x;
        cin >> cur;
    }while(!mp.count(cur));
    cout << "! " << cnt - mp[cur] << "\n";
    cout.flush();
}
