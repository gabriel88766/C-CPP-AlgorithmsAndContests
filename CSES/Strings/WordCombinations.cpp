#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 5005;
ll dp[N];
const int M = 1e6+5; //substrings of a string of len 1505

int cntn = 0;
int trie[M][26];
bool match[M];

int add(int node, char c){
    c -= 'a';
    if(trie[node][c]) return trie[node][c];
    else return trie[node][c] = ++cntn;
}

//example add string
void add(string s){
    int curn = 0;
    for(auto c : s) curn = add(curn, c);
    match[curn] = true;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in.txt", "r", stdin); //test input
    string s;
    int n;
    dp[0] = 1;
    cin >> s;
    cin >> n;
    
    for(int i=0;i<n;i++){
        string aux;
        cin >> aux;
        add(aux);
    }
    for(int i=0;i<s.size();i++){
        int cur = 0, j = i;
        while(j < s.size()){
            if(trie[cur][s[j]-'a'] != 0){
                cur = trie[cur][s[j]-'a'];
                j++;
                if(match[cur]) dp[j] = (dp[j] + dp[i]) % MOD;
            }else break;
        }
    }
    cout << dp[s.size()];

}
