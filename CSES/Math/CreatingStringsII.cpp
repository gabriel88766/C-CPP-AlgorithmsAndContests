#include <bits/stdc++.h>
typedef long long int ll;
const ll MAX_LL = 0x3f3f3f3f3f3f3f3f;
const int MAX_INT = 0x3f3f3f3f;
using namespace std;

ll MOD = 1e9+7;
ll fact[1000005];

ll binpow(ll a, ll b, ll m){
    a %= m;
    ll ans = 1;
    while(b > 0){
        if(b & 1) 
            ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}

ll divmod(ll a, ll b, ll m){
    return (a * binpow(b, m-2, m)) % m;
}

int mp[26];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    ll n, a, b, ans = 1;
    string s;
    cin >> s;
    fact[0] = 1;
    for(int i=1;i<=1000000;i++){
        fact[i] = (i * fact[i-1]) % MOD;
    }
    for(int i=0;i<s.size();i++){
        mp[s[i]-'a']++;
    }
    int curpermsz = s.size();
    for(int i=0;i<26;i++){
        if(mp[i]){
            ans = (ans * divmod(divmod(fact[curpermsz], fact[curpermsz - mp[i]], MOD), fact[mp[i]], MOD)) % MOD;
            curpermsz -= mp[i];
        }
    }
    cout << ans;
}
