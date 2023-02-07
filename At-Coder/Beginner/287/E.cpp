#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 500005; 
int cntn = 0;
int trie[N][26];
int cnt[N];

int add(int node, char c){
    c -= 'a';
    if(trie[node][c]){
        cnt[trie[node][c]]++;
        return trie[node][c];
    }
    else{
        cnt[++cntn] = 1;
        return trie[node][c] = cntn;
    }
}

//example add string
void add(string s){
    int curn = 0;
    for(auto c : s) curn = add(curn, c);
}

int glcp(string s){
    int ans = 0;
    int cur = 0;
    for(auto c : s){
        cur = trie[cur][c-'a'];
        if(cnt[cur] > 1) ans++;
        else break;
    }
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n;
    cin >> n;
    vector<string> v;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        v.push_back(s);
        add(s);
    }
    for(int i=0;i<n;i++){
        cout << glcp(v[i]) << "\n";
    }
}
