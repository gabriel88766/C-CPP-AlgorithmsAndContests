#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    vector<string> v;
    v.push_back("");
    int n, q;
    cin >> n >> q;
    vector<int> p(n+1, 0);
    vector<int> adj(q+1);
    for(int i=1;i<=q;i++){
        int tq, x;
        string s;
        cin >> tq;
        if(tq == 1){
            cin >> x;
            p[x] = p[0];
        }else if(tq == 2){
            cin >> x >> s;
            int pos = v.size();
            int par = p[x];
            v.push_back(s);
            adj[pos] = par;
            p[x] = pos;
        }else{
            cin >> x;
            p[0] = p[x];
        }
    }
    vector<string> ans;
    int pos = p[0];
    while(pos != 0){
        ans.push_back(v[pos]);
        pos = adj[pos];
    }
    reverse(ans.begin(), ans.end());
    for(auto x : ans) cout << x;
    cout << "\n";
}
