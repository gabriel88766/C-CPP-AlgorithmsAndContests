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
    int n, k;
    cin >> n >> k;
    vector<int> p(n+1), q(n+1);
    for(int i=1;i<=n;i++) cin >> p[i];
    for(int i=1;i<=n;i++) cin >> q[i];
    set<int> s1, s2;
    vector<set<int>> vs;
    for(int i=1;i<=n;i++){
        s1.insert(p[i]);
        s2.insert(p[i]);
        s2.insert(q[i]);
        if(s1.size() == s2.size()){
            vs.push_back(s1);
            s1.clear();
            s2.clear();
        }
    }
    if(vs.size() >= k){
        vector<char> ans(n+1, 0);
        for(int i=0;i<k-1;i++){
            for(auto x : vs[i]){
                ans[x] = (char)('a' + i);
            }
        }
        for(int i=k-1;i<vs.size();i++){
            for(auto x : vs[i]){
                ans[x] = (char)('a' + k-1);
            }
        }
        cout << "YES\n";
        for(int i=1;i<=n;i++) cout << ans[i];
        cout << "\n";
    }else cout << "NO\n";
}
