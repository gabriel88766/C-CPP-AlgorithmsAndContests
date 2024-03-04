#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const ll primes[] = {1000000007, 1000000009, 1000000021, 1000000033, 1000000087};
const int qtMOD = 5;
vector<ll> docong(const string &str){
    vector<ll> ansv;
    for(int j=0;j<qtMOD;j++){
        ll ans = 0;
        for(int i=0;i<str.size();i++){
            ans *= 10;
            ans += str[i] - '0';
            ans %= primes[j];
        }
        ansv.push_back(ans);
    }
    return ansv;
}

vector<ll> multicong(vector<ll> &cong1, vector<ll> &cong2){
    vector<ll> ans;
    for(int j=0;j<qtMOD;j++){
        ll cur = cong1[j] * cong2[j];
        cur %= primes[j];
        ans.push_back(cur);
    }
    return ans;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<vector<ll>> congs;
    map<vector<ll>, ll> mp;
    for(int i=0;i<n;i++){
        string str;
        cin >> str;
        auto cong = docong(str);
        mp[cong]++;
        congs.push_back(cong);
    }
    ll ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            auto mtc = multicong(congs[i], congs[j]);
            if(mp.count(mtc)) ans += mp[mtc];
        }
    }
    cout << ans << "\n";
    

}
