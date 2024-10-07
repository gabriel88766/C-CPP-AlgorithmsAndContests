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
    int t;
    cin >> t;
    while(t--){
        int n, m, q;
        cin >> n >> m >> q;
        vector<int> v(n+1), vm(m+1), pos(n+1);
        vector<set<int>> st(n+1);
        for(int i=1;i<=n;i++){
             cin >> v[i];
             pos[v[i]] = i;
        }
        bool ok = true;
        st[0].insert(0);
        for(int i=1;i<=m;i++){
            cin >> vm[i];
            st[pos[vm[i]]].insert(i);
        }
        set<int> wn;
        auto check = [&](int u){
            if(u > n) return false;
            else{
                if(st[u].size()){
                    if(!st[u-1].size() || *st[u-1].begin() > *st[u].begin()){
                        return true;
                    }else return false;
                }return false;
            }
        };
        for(int i=1;i<=n;i++){
            if(check(i)){
                wn.insert(i);
            }
        }
        if(wn.size()) cout << "TIDAK\n";
        else cout << "YA\n";
        for(int i=0;i<q;i++){
            int s, x;
            cin >> s >> x;
            st[pos[vm[s]]].erase(s);
            st[pos[x]].insert(s);

            if(check(pos[vm[s]])) wn.insert(pos[vm[s]]);
            else wn.erase(pos[vm[s]]);
            if(check(pos[vm[s]] + 1)) wn.insert(pos[vm[s]] + 1);
            else wn.erase(pos[vm[s]] + 1);
            if(check(pos[x])) wn.insert(pos[x]);
            else wn.erase(pos[x]);
            if(check(pos[x]+1)) wn.insert(pos[x]+1);
            else wn.erase(pos[x]+1);
            vm[s] = x;
            if(wn.size()) cout << "TIDAK\n";
            else cout << "YA\n";
        }
    }
}
