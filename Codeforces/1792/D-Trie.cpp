#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 500005; //abuse of memory to certainly fit in the limits
int cntn = 0;
int trie[N][11];

int add(int node, int c){
    if(trie[node][c]) return trie[node][c];
    else return trie[node][c] = ++cntn;
}

//example add string
void add(vector<int> &v){
    int curn = 0;
    vector<int> pos(v.size());
    for(int i=1;i<=v.size();i++) pos[v[i-1]-1] = i;
    for(auto c : pos) curn = add(curn, c);
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v(n, vector<int> (m, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> v[i][j];
            }
            add(v[i]);
        }
        for(int i=0;i<n;i++){
            int cur = 0, cnt = 0;
            while(cnt < m && trie[cur][v[i][cnt]]){
                cur = trie[cur][v[i][cnt]];
                cnt++;
            }
            cout << cnt << " ";
        }
         cout << "\n";
        for(int i=0;i<=cntn;i++){
            for(int j=1;j<=10;j++){
                trie[i][j] = 0;
            }
        }
        cntn = 0;
    }
}
