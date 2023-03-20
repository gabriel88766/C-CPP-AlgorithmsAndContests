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
    vector<pair<int,pair<int,int>>> vp;
    vector<int> a, b;
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        int aux;
        cin >> aux;
        vp.push_back({aux, {i, 0}});
    }
    for(int i=1;i<=m;i++){
        int aux;
        cin >> aux;
        vp.push_back({aux, {i, 1}});
    }
    sort(vp.begin(), vp.end());
    for(int i=0;i<vp.size();i++){
        if(vp[i].second.second == 0) a.push_back(i+1);
        else b.push_back(i+1);
    }
    for(auto x : a) cout << x << " ";
    cout << "\n";
    for(auto x : b) cout << x << " ";
}
