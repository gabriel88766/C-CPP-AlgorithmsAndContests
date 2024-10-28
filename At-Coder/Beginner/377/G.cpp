#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 400005; //substrings of a string of len 1505

int cntn = 0;
int trie[N][26];
int need[N];

int add(int node, char c){
    c -= 'a';
    if(trie[node][c]) return trie[node][c];
    else return trie[node][c] = ++cntn;
}

//example add string
void add(string s){
    int curn = 0;
    int ms = s.size();
    for(auto c : s){
        curn = add(curn, c);
        --ms;
        need[curn] = min(need[curn], ms);
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    memset(need, 63, sizeof(need));
    need[0] = 0;
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        string cs; 
        cin >> cs;
        int cur = 0;
        int ans = cs.size();
        int aux = cs.size();
        for(int j=0;j<cs.size();j++){
            aux--;
            if(trie[cur][cs[j]-'a']){
                cur = trie[cur][cs[j]-'a'];
                ans = min(ans, aux + need[cur]);
            }else break;
        }
        cout << ans << "\n";
        add(cs);
    }
}
