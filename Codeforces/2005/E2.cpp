#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1505*1505;
int  usd[N];
int oc[1505][1505];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    memset(usd, 0xFF, sizeof(usd));
    while(t--){
        int l, n, m;
        cin >> l >> n >> m;
        vector<int> a(l);
        for(int i=0;i<l;i++){
            cin >> a[i];
            usd[a[i]] = i;
        }
        reverse(a.begin(), a.end());
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int x;
                cin >> x;
                if(usd[x] == -1) continue;
                oc[usd[x]][i] = j;
            }
        }
        
        vector<pair<int,int>> bst;
        for(auto &x : a){
            vector<pair<int,int>> nst;
            int mx = 0, p = 0;
            for(int i=n;i>=1;i--){
                if(!oc[usd[x]][i]) continue;
                while(p < bst.size() && bst[p].first > i){
                    mx = max(mx, bst[p].second);
                    p++;
                }
                if(oc[usd[x]][i] >= mx) nst.push_back({i, oc[usd[x]][i]});
            }
            bst = nst;
        }
        if(bst.size()) cout << "T\n";
        else cout << "N\n";
        for(auto x : a) usd[x] = -1;
        for(int i=0;i<a.size();i++){
            for(int j=1;j<=n;j++){
                oc[i][j] = 0;
            }
        }
    }
}
