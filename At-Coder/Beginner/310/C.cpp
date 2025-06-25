#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1002*1002; //substrings of a string of len 1505

int cntn = 0;
int trie[N][26];
bool isn[N];

int add(int node, char c){
    c -= 'a';
    if(trie[node][c]) return trie[node][c];
    else return trie[node][c] = ++cntn;
}

//example add string
bool add(string s){
    int curn = 0;
    for(auto c : s) curn = add(curn, c);
    bool alr = isn[curn];
    isn[curn] = true;
    return alr;
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    ll ans = 0;
    string s;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> s;
        bool cn = add(s);
        if(!cn) ans++;
        reverse(s.begin(), s.end());
        add(s);
    }
    cout << ans << "\n";
}
