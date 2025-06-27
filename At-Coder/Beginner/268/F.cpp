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
    int n;
    cin >> n;
    ll ans = 0;
    vector<pair<ll, ll>> vx;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        ll cx = 0;
        ll cs = 0;
        for(auto &c : s){
            if(c == 'X') cx++;
            else cs += c-'0', ans += cx * (c - '0');
        }
        vx.push_back({cx, cs}); 
    }  
    //brute force testing;
    sort(vx.begin(), vx.end(), [&](pair<ll, ll> &a, pair<ll, ll> &b){
        return a.first * b.second < b.first * a.second;
    });
    ll aux = 0;
    for(auto [a, b] : vx){
        ans += a * aux;
        aux += b;
    }

    cout << ans << "\n";
}
