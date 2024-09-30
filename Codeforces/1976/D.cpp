#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


const int N = 200005, M = 20; // M >= log2(N)
ll sparse[N][M];
vector<int> v;

void build(){
    int n = v.size();
    for(int i=0;i<n;i++) sparse[i][0] = v[i];
    for(int j = 1; j < M; j++){
        for(int i = 0; i < n; i ++){
            if((i + (1 << (j-1))) < n) sparse[i][j] = max(sparse[i][j-1], sparse[i + (1 << (j-1))][j-1]);
            else sparse[i][j] = sparse[i][j-1];
        }
    }
}

ll query(int a, int b){
    if(a == b) return sparse[a][0]; //bug
    int pot = 32 - __builtin_clz(b - a) - 1; 
    return max(sparse[a][pot], sparse[b - (1 << pot) + 1][pot]);
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        s = " " + s;
        map<int, vector<int>> mp;
        mp[0].push_back(0);
        int c = 0;
        v.clear();
        v.push_back(0);
        for(int i=1;i<=n;i++){
            if(s[i] == ')') c--;
            else c++;
            v.push_back(c);
        }
        build();
        ll ans = 0;
        for(int i=1;i<=n;i++){
            if(s[i] == ')') c--;
            else c++;
            mp[c].push_back(i);
            auto &v = mp[c];
            int x = v.size() - 1;
            int bst = x;
            for(int j=i;j>=1;j>>=1){
                while(bst - j >= 0 && 2*c - query(v[bst-j], i) >= 0) bst -= j;
            }
            // cout << i << " " << x << " " << bst << " " << c << " - " << query(v[bst], i) << "\n";
            ans += x - bst;
        }
        cout << ans << "\n";
    }
}
