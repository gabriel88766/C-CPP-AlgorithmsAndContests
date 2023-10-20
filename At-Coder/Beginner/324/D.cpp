#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<int> cur(10, 0);
int n;
void check(ll k){
    for(int i=0;i<10;i++) cur[i] = 0;
    int cnt = n;
    while(k){
        cur[k%10]++;
        k /= 10;
        cnt--;
    }
    if(cnt >= 0) cur[0] += cnt;
    else cur[0] = -1;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    
    cin >> n;
    string s;
    cin >> s;
    vector<int> v(10, 0);
    for(int i=0;i<n;i++){
        v[s[i]-'0']++;
    }
    ll ans = 0;
    for(ll i = 0; i*i <= 10000000000000LL; i++){
        ll k = i*i;
        check(k);
        if(cur == v) ans++;
    }
    cout << ans << "\n";
}
