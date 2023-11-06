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
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    ll ans = INF_LL;
    //1 multiple
    ll lc = (a/gcd(a,b))*b;
    lc = (lc/gcd(lc,c))*c;
    for(int i=0;i<n;i++){
        if(!(v[i] % lc)) ans = 0;
        else ans = min(ans, lc-(v[i]%lc));
    }
    //2 multiples, 2 // 1 (ab, c) or (ac, b) or (bc, a)
    if(n >= 2){
        vector<vector<ll>> brute = {{(a/gcd(a,b))*b, c}, {(a/gcd(a,c))*c, b}, {(b/gcd(b,c))*c, a}};
        for(int i=0;i<3;i++){
            vector<pair<ll,ll>> m1, m2;
            ll lc = brute[i][0];
            ll num = brute[i][1];
            for(int j=0;j<n;j++){
                if(!(v[j]%lc)) m1.push_back({0, j});
                else m1.push_back({lc - v[j]%lc, j});
                if(!(v[j]%num)) m2.push_back({0, j});
                else m2.push_back({num - v[j]%num, j});
            }
            sort(m1.begin(), m1.end());
            sort(m2.begin(), m2.end());
            if(m1[0].second != m2[0].second) ans = min(ans, m1[0].first + m2[0].first);
            else{
                ans = min(ans, min(m1[0].first + m2[1].first, m1[1].first + m2[0].first));
            }
        }
    }
    //3multiples a,b,c
    if(n >= 3){
        vector<pair<ll,ll>> m1, m2, m3;
        for(int i=0;i<n;i++){
            if(!(v[i]%a)) m1.push_back({0, i});
            else m1.push_back({a - v[i]%a, i});
            if(!(v[i]%b)) m2.push_back({0, i});
            else m2.push_back({b - v[i]%b, i});
            if(!(v[i]%c)) m3.push_back({0, i});
            else m3.push_back({c - v[i]%c, i});
        }
        sort(m1.begin(), m1.end());
        sort(m2.begin(), m2.end());
        sort(m3.begin(), m3.end());
        vector<int> perm = {1,2,3};
        do{
            map<int,int> used;
            ll cur = 0;
            for(int i=0;i<3;i++){
                int nxt = perm[i];
                int p = 0;
                if(nxt == 1){
                    while(used.count(m1[p].second)) p++;
                    cur += m1[p].first;
                    used[m1[p].second] = 1;
                }else if(nxt == 2){
                    while(used.count(m2[p].second)) p++;
                    cur += m2[p].first;
                    used[m2[p].second] = 1;
                }else{
                    while(used.count(m3[p].second)) p++;
                    cur += m3[p].first;
                    used[m3[p].second] = 1;
                }
                
            }
            ans = min(ans, cur);
        }while(next_permutation(perm.begin(), perm.end()));
    }
    cout << ans << "\n";
}
