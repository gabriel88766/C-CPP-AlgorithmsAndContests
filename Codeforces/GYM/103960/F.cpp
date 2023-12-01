#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

string ch(string s, char c){
    for(int i=0;i<s.size();i++){
        if(s[i] == '*') s[i] = c;
    }
    return s;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    map<string, int> mp;
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    string ans;
    int qtmax = 0;
    for(int i=0;i<n;i++){
        cin >> v[i];
        mp[v[i]]++;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<26;j++){
            char c = 'a' + j;
            string acc = ch(v[i], c);
            int cur = 0;
            for(int k=0;k<m;k++){
                char oldc = acc[k];
                acc[k] = '*';
                if(mp.count(acc)) cur += mp[acc];
                acc[k] = oldc;
            }
            if(cur > qtmax){
                qtmax = cur;
                ans = acc;
            }else if(cur == qtmax && acc < ans){
                qtmax = cur;
                ans = acc;
            }
        }
    }
    cout << ans << " " << qtmax << "\n";
}
