#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e6;
int trie[N][2];
int val[N];
int cnt = 0;

void clear(){
    for(int i=0;i<=cnt;i++){
        val[i] = trie[i][0] = trie[i][1] = 0;
    }
    cnt = 0;
}
void add(int n){
    int cur = 0;
    for(int j=16;j>=0;j--){
        int b = (1 << j) & n ? 1 : 0;
        if(!trie[cur][b]) trie[cur][b] = ++cnt;
        cur = trie[cur][b];
    }
    val[cur] = n;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int l, r, ans = 0;
        cin >> l >> r;
        int n = r-l+1;
        vector<int> v(n);
        vector<int> chk;
        for(int i=0;i<n;i++){
            int aux;
            cin >> aux;
            add(aux);
            chk.push_back(l ^ aux);
        }
        for(int x=0;x<n;x++){
            auto i = chk[x];
            // find i such that max i ^ some number from v is equal n-1
            int  c1 = 0, c2 = 0;
            for(int j=16;j>=0;j--){
                if(i & (1 << j)){
                    if(trie[c1][1]) c1 = trie[c1][1];
                    else c1 = trie[c1][0];
                    if(trie[c2][0]) c2 = trie[c2][0];
                    else c2 = trie[c2][1];
                }else{
                    if(trie[c1][0]) c1 = trie[c1][0];
                    else c1 = trie[c1][1];
                    if(trie[c2][1]) c2 = trie[c2][1];
                    else c2 = trie[c2][0];
                }
            }
            //cout << val[c1] << " " << val[c2] << " " << i << "\n";
            if((i ^ val[c1])  == l && (i ^ val[c2]) == r){
                ans = i;
                break;
            }
        }
        cout << ans << "\n";
        clear();
    }
}