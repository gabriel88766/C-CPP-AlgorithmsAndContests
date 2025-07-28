#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<int> als;
int al[1 << 21];
bool spc[10];
int dp[5000], ndp[5000];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    string s;
    int x;
    cin >> s >> x;
    for(int i=1;i<(1 << x);i+=2){
        vector<int> sn;
        for(int j=0;j<x;j++){
            if(i & (1 << j)){
                sn.push_back(j);
            }
        }
        bool ok = true;
        for(int j=0;j<sn.size();j++){
            for(int k=j+1;k<sn.size();k++){
                if(x % (sn[k] - sn[j]) == 0){
                    ok = false;
                }
            }
        }
        if(ok){
            al[i] = als.size() + 1;
            als.push_back(i);
        }
    }
    //check among the allowed states all reachable from them
    //they are often allowed too, but need to be reduced.
    for(auto u : als){
        for(int j=1;j<=9;j++){
            int cs = u << j;
            cs &= ((1 << (x+1)) - 1);
            cs |= 1;
            if(al[cs]) continue; //state ok
            vector<int> sn;
            for(int j=0;j<=x;j++){
                if(cs & (1 << j)){
                    sn.push_back(j);
                }
            }
            for(int j=1;j<sn.size();j++){
                if(x % (sn[j] - sn[0]) == 0 && (x != (sn[j] - sn[0]))){
                    while(sn.size() != j) sn.pop_back();
                    break;
                }
            }
            int rs = 0;
            for(auto v : sn) rs |= (1 << v);
            if(rs & (1 << x)) continue;
            assert(al[rs]);
            al[cs] = al[rs];
        }
    }
    for(int i=0;i<als.size();i++) dp[i] = ndp[i] = -INF_INT;
    dp[0] = 0;
    for(int j=0;j<s.size();j++){
        for(int i=0;i<als.size();i++) ndp[i] = -INF_INT;
        for(int i=0;i<als.size();i++){
            if(dp[i] >= 0){
                int ns = als[i] << (s[j] - '0');
                ns &= ((1 << (x+1)) - 1);
                ns |= 1;
                if(al[ns]){
                    ndp[al[ns]-1] = max(ndp[al[ns]-1], dp[i] + 1);
                }
            }
        }
        for(int i=0;i<als.size();i++) dp[i] = max(ndp[i], dp[i]);
    }
    cout << s.size() - *max_element(dp, dp + 5000) << "\n";
}
