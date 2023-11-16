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
    int lr = 0;
    int ans = 0;
    vector<pair<int,int>> v(m);
    for(int i=0;i<m;i++){
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end(), [&](pair<int,int> u, pair<int,int> v){
        if(u.second != v.second) return u.second < v.second;
        else return u.first < v.first;
    });
    for(int i=0;i<m;i++){
        if(v[i].first >= lr){
            lr = v[i].second;
            ans++;
        }
    }
    cout << ans << "\n";
}
