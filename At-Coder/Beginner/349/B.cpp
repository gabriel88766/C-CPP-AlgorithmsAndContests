#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int cnt[26];
int tt[101];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    string s;
    cin >>s;
    for(auto c : s){
        cnt[c-'a']++;
    }
    for(int i=0;i<26;i++){
        tt[cnt[i]]++;
    }
    bool ok = true;
    for(int i=0;i<26;i++){
        if(cnt[i] != 0 && tt[cnt[i]] != 2) ok = false; 
    }
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}
