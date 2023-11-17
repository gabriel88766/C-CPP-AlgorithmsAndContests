#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 316228;
int p[N]; // 0 if prime, 1 if not prime
vector<ll> pr;
void sieve(){
    for(ll i=2; i<N; i++){
        if(!p[i]){
            for(ll j = i*i; j < N; j += i){
                p[j] = 1; //marking all multiples of i as not prime
            }
            pr.push_back(i);
        }
    }
}
map<ll, ll> mp;
ll sz;

ll cntp(ll n){
    if(pr[sz-1] >= n){
        return upper_bound(pr.begin(), pr.end(), n) - pr.begin();
    }
    ll ans = n - 1;
    for(int i = 0; i < sz;i++){
        ll val = n/pr[i];
        //2 2
        if(val >= pr[i]){
            if(!mp.count(val)) mp[val] = cntp(val);
            ans -= mp[val] - i;
        }else break;
    }
    //cout << n << " " << ans << "\n";
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    sieve();
    sz = pr.size();
    ll n, ans = 0;
    cin >> n;
    //letsgo... 4 divisors. p1*p1*p1 or p1*p2
    for(ll i=2;i * i * i <= n; i++){
        if(!p[i]) ans++;
    }
    //count pairs p1 p2 lower than 320000
    for(int i = 0; i< pr.size();i++){ //i have too many seconds... hehe O(7e8)
        ll val = n/pr[i];
        if(val < pr[i]) break;
        if(!mp.count(val)) mp[val] = cntp(val);
        //cout << val << " " << mp[val] << "\n";
        ans += mp[val] - i - 1;
    }

    cout << ans << "\n";
}
