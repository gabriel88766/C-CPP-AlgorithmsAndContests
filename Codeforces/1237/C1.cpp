#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Point{
    int x, y, z;
};


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<Point> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i].x >> v[i].y >> v[i].z;
    set<int> ps; 
    for(int i=1;i<=n;i++) ps.insert(i);
    for(int i=1;i<=n/2;i++){
        int p1 = *ps.begin();
        ps.erase(ps.begin());
        int p2 = *ps.begin();
        for(auto x : ps){
            if(x == p2) continue;
            else{
                if(v[x].x < min(v[p1].x, v[p2].x) || v[x].x > max(v[p1].x, v[p2].x)) continue;
                if(v[x].y < min(v[p1].y, v[p2].y) || v[x].y > max(v[p1].y, v[p2].y)) continue;
                if(v[x].z < min(v[p1].z, v[p2].z) || v[x].z > max(v[p1].z, v[p2].z)) continue;
                p2 = x;
            }
        }
        ps.erase(p2);
        cout << p1 << " " << p2 << "\n";
    }
}
