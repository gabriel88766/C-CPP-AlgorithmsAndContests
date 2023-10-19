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
        int n, m;
        cin >> n >> m;
        vector<pair<pair<int,int>, int>> vp(m);
        for(int i=0;i<m;i++){
            cin >> vp[i].first.second >> vp[i].first.first;
            vp[i].second = i+1;
        }
        sort(vp.begin(), vp.end());
        int sum = 0;
        vector<pair<int,int>> ep;
        for(int i=0;i<2*n;i++){
            sum += vp[i].first.first;
            ep.push_back({vp[i].first.second, vp[i].second});
        }
        sort(ep.begin(), ep.end());
        cout << sum << "\n";
        for(int i=0;i<n;i++){
            cout << ep[i].second << " " << ep[2*n-i-1].second << "\n";
        }
    }
}
