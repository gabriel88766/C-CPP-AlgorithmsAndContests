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
ll cnt[N];

int add(int node, char c){
    c -= 'a';
    if(trie[node][c]){
        cnt[trie[node][c]]++;
    }else{
        trie[node][c] = ++cntn;
        cnt[trie[node][c]]++;
    }
    return trie[node][c];
}

//example add string
void add(string s){
    int curn = 0;
    for(auto c : s) curn = add(curn, c);
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n;
    cin >> n;
    vector<string> v(n);
    ll ans = 0;
    for(int i=0;i<n;i++){
        cin >> v[i];
        ans += 2*n * ((ll)(v[i].size()));
        add(v[i]);
    }
    for(int i=0;i<n;i++){  
        int curp = 0;
        for(int j=v[i].size()-1;j>=0;j--){
            if(trie[curp][v[i][j]-'a']){
                curp = trie[curp][v[i][j] - 'a'];
                ans -= 2 * cnt[curp];
            }else break;
        }
    }
    cout << ans << "\n";
}
