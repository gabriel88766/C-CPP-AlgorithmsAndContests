#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3e5+4;
ll pot2[N], pot3[N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    set<int> av;
    for(int i=0;i<=N;i++) av.insert(i);

    for(int i=0;i<n;i++){
        cin >> v[i].first >> v[i].second;
    }
    pot2[0] = pot3[0] = 1;
    for(int i=1;i<N;i++){
        pot2[i] = (pot2[i-1]*2)%MOD;
        pot3[i] = (pot3[i-1]*3)%MOD;
    }

    ll ans = 0;
    for(int i=(n-1);i>=0;i--){
        auto it = av.lower_bound(v[i].first);
        stack<int> rml;
        ll cnt = 0;
        while(*it <= (v[i].second)){
            cnt++;
            rml.push(*it);
            ++it;
        }
        while(!rml.empty()) {av.erase(rml.top()); rml.pop();}
        ans = (ans + ((cnt * pot2[i == 0 ? n-i-1 : n-i])%MOD * pot3[i-1 > 0 ? i-1 : 0])) % MOD;
    }
    cout << ans;
}
