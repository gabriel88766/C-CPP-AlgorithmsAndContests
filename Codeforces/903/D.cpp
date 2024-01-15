#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


map<int, ll> mp;

string decimal_string(__int128 x){
    if(x == 0) return "0";
    string ans;
    bool neg = false;
    if(x < 0){
        neg = true;
        x = -x;
    }
    while(x){
        ans += '0' + (x % 10);
        x /= 10;
    }
    reverse(ans.begin(), ans.end());
    if(neg) ans = "-" + ans;
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    __int128 ans = 0;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    __int128 sum = 0;
    for(int i=n-1;i>=0;i--){
        sum += v[i];
        ans += sum - v[i] * (n-i);
        if(mp.count(v[i]+1)) ans -= mp[v[i]+1];
        if(mp.count(v[i]-1)) ans += mp[v[i]-1];
        mp[v[i]]++;
    }
    cout << decimal_string(ans) << "\n";
}
