#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;
int cnt[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("out", "w", stdout); //test input
    int ma, mb, w;
    cin >> ma >> mb >> w;
    map<pair<int, int>, vector<int>> mp;
    for(int a=1;a<=mb;a++){
        int n = a;
        string s = to_string(a);
        if(s.back() == '0') s.pop_back();
        reverse(s.begin(), s.end());
        int d = stoi(s);
        int g = gcd(d, n);
        d /= g;
        n /= g;
        mp[{d, n}].push_back(a);
    }
    int ttcnt = 0;
    ll pb = mb;
    pair<ll, ll> ans = {INF_INT, INF_INT};
    for(int a=1;a<=ma;a++){
        int n = a;
        string s = to_string(a);
        if(s.back() == '0') s.pop_back();
        reverse(s.begin(), s.end());
        int d = stoi(s);
        int g = gcd(d, n);
        d /= g;
        n /= g;
        if(mp.count({n,d})){
            for(auto x : mp[{n, d}]){
                if(x > pb) break;
                cnt[x]++;
                ttcnt++;
            }
        }
        // cout << ttcnt << " ";
        while(ttcnt >= w && ttcnt - w >= cnt[pb]){
            ttcnt -= cnt[pb--];
        }
        // cout << ttcnt << "\n";
        if(ttcnt >= w){
            // cout << a << " " << pb << "\n";
            if(pb * a <= ans.first * ans.second){
                ans = {a, pb};
            }
        }
    }
    if(ans.first == INF_INT) cout << "-1\n";
    else cout << ans.first << " " << ans.second << "\n";
}
