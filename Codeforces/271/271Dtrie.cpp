#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;
const int N = 1505*1505;

int cntn = 0;
int adj[N][26];
char val[N];
char isGood[256];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    string s, g;
    int cnt=0, k, curn;
    cin >> s >> g >> k;
    for(int i=0;i<26;i++){
        isGood[i+'a'] = g[i] - '0';
    }
    for(int i=0;i<s.size();i++){
        cnt = curn = 0;
        for(int j=i;j<s.size();j++){
            if(isGood[s[j]]){//nothing to do
            }else if(cnt < k){
                cnt++;
            }else break;
            
            if(adj[curn][s[j]-'a']) curn = adj[curn][s[j]-'a'];
            else curn = adj[curn][s[j]-'a'] = ++cntn;
        }
    }
    cout << cntn;
}