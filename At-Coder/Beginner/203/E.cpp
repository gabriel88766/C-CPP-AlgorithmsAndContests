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
    int n, m;
    cin >> n >> m;
    set<int> s;
    s.insert(n);
    map<int, vector<int>> mp;
    for(int i=1;i<=m;i++){
        int x, y;
        cin >> x >> y;  
        mp[x].push_back(y);
    }
    for(auto [k, v]: mp){
        vector<int> inl, erl;
        for(auto x : v){
            if(s.count(x-1) || s.count(x+1)) inl.push_back(x);
            else erl.push_back(x);
        }
        for(auto x : inl) s.insert(x);
        for(auto x : erl) s.erase(x);
    }
    cout << s.size() << "\n";
}   
