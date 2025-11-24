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
    // freopen("defining_prizes_validation_input.txt", "r", stdin); //test input
    // freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        int n, m;
        cin >> n >> m;
        priority_queue<pair<int, int>> pq;
        map<int, int> mpa;
        for(int j = 0; j < n; j++){
            int x;
            cin >> x;
            mpa[x]++;
        }
        for(int j = 0; j < m; j++){
            int x;
            cin >> x;
            pq.push({x, 1});
        }
        vector<int> qts;
        for(auto [k, v] : mpa){
            qts.push_back(v);
        }
        reverse(qts.begin(), qts.end());
        int ans = 0;
        for(int j=0; j < qts.size();j++){
            int cur = ans + qts[j];
            auto [nx, ux] = pq.top();
            
        }
        cout << "Case #" << i << ": " << ans << "\n";
    }
}
