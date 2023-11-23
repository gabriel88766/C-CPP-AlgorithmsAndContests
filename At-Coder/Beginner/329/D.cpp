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
    set<pair<int,int>> s;
    map<int,int> mp;
    for(int i=0;i<m;i++){
        int aux;
        cin >> aux;
        s.erase({mp[aux], -aux});
        mp[aux]++;
        s.insert({mp[aux], -aux});
        auto it = prev(s.end());
        cout << -(it->second) << "\n";
    }
}
