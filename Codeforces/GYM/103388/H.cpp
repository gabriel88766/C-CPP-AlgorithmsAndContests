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
    vector<vector<pair<int,int>>> v(k+1);
    for(int i=1;i<=n;i++){
        int num, c;
        cin >> num >> c;
        v[c].push_back({num, i});
    }
    bool ok = true;
    for(int i=1;i<=k;i++){
        set<int> s1, s2;
        for(auto [num, j] : v[i]){
            s1.insert(num);
            s2.insert(j);
        }
        if(s1 != s2) ok = false;
    }


    if(ok) cout << "Y\n";
    else cout << "N\n";
}
