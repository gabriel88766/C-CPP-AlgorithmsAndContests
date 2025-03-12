#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<int> il[26];
int nxt[100005][26];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n;
    string s, t;
    cin >> n >> s >> t;
    for(int i=0;i<s.size();i++){
        il[s[i]-'a'].push_back(i);
    }
    for(int i=0;i<26;i++){
        int p = 0;
        for(int j=0;j<s.size();j++){
            nxt[j][i] = p;
            if(p < il[i].size() && il[i][p] == j) p++;
        }
    }
    ll lo = 0, hi = 1e18;
    while(lo != hi){
        ll mid = lo + (hi - lo + 1)/2;
        ll tt = 0, p = 0;
        for(auto &c : t){
            int lt = c - 'a';
            ll fid = nxt[p][lt];
            if(fid == il[lt].size()){
                fid = 0;
                tt++;
            }
            if(il[lt].size() >= 1){
                tt += mid / il[lt].size();
                ll r = mid % il[lt].size();
                ll did = fid + r - 1;
                if(did < 0){
                    tt -= 1;
                    did += il[lt].size();
                }
                if(did >= il[lt].size()){
                    tt += 1;
                    did -= il[lt].size();
                }
                p = il[lt][did];
                p++;
                if(p == s.size()){
                    p = 0;
                    tt++;
                }
            }else tt = n+1;
            if(mid == 7) cout << tt << " " << p << "\n";
            if(tt > n) break;
        }
        if(tt < n || (tt == n && p == 0)) lo = mid;
        else hi = mid - 1;
    }
    cout << lo << "\n";
}
