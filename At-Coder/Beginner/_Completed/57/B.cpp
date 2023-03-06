#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> s(n);
    vector<pair<int,int>> c(m);
    for(int i=0;i<n;i++) cin >> s[i].first >> s[i].second;
    for(int i=0;i<m;i++) cin >> c[i].first >> c[i].second;
    for(int i=0;i<n;i++){
        int ind = -1, mindist = INF_INT;
        for(int j=0;j<m;j++){
            int dist = abs(c[j].first - s[i].first) + abs(c[j].second - s[i].second);
            if(dist < mindist) mindist = dist, ind = j;
        }
        cout << ind+1 << "\n";
    }
}
