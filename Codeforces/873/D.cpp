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
    if(!(k % 2)){
        cout << "-1\n";
        return 0;
    }
    queue<pair<int,int>> q;
    set<pair<int,int>> s;
    q.push({0, n});
    s.insert({0, n});
    int cur = 1;
    while(!q.empty() && k != cur){
        cur += 2;
        auto [l, r] = q.front();
        s.erase(q.front());
        q.pop();
        int m = (l + r) / 2;
        s.insert({l, m});
        s.insert({m, r});
        if(l != (m-1)) q.push({l, m});
        if(m != (r-1)) q.push({m, r});
    }
    vector<int> ans(n+1);
    if(k != cur) cout << "-1\n";
    else{
        int cur = n;
        for(auto [l, r] : s){
            int qt = r - l;
            int beg = cur - qt;
            int aux = beg;
            for(int i=l;i<r;i++){
                ans[i] = ++aux;
            }
            cur = beg;
        }
        for(int i=0;i<n;i++) cout << ans[i] << " ";
        cout << "\n";
    }
    
}
