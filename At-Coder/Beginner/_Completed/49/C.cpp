#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

string c[] = {"maerd$", "remaerd$", "resare$", "esare$"};
const int N = 1e5+3;
int cntn = 1;
int trie[N][26];

int add(int node, char c){
    if(c == '$'){
        for(int i=0;i<26;i++) trie[node][i] = 1;
        return 1;
    }
    c = c - 'a';
    if(trie[node][c]) return trie[node][c];
    else return trie[node][c] = ++cntn;
}

//example add string
void add(string s){
    int curn = 1;
    for(auto c : s) curn = add(curn, c);
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    for(int i=0;i<4;i++) add(c[i]);
    int cur  = 1;
    for(int i=0;i<s.size();i++){
        if(trie[cur][s[i]-'a'] == 1){
            cur = 1;
        }
        if(trie[cur][s[i]-'a']){
            cur = trie[cur][s[i]-'a'];
        }else{
            cout << "NO";
            return 0;   
        }
    }
    if(trie[cur][0] == 1) cout << "YES";
    else cout << "NO";
}
