#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Point{
    int x, y, z, i;
    Point(){}
    Point(int a, int b, int c, int d){
        x = a;
        y = b;
        z = c;
        i = d;
    }
    bool operator< (const Point &p) const{
        if(x != p.x) return x < p.x;
        else if(y != p.y) return y < p.y;
        else if(z != p.z) return z < p.z;
        else return i < p.i;
    }
};

set<Point> v;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        Point p;
        cin >> p.x >> p.y >> p.z;
        p.i = i+1;
        v.insert(p);
    }
    for(int i=1;i<=n/2;i++){
        auto p1 = *v.begin();
        v.erase(v.begin());
        auto it = v.lower_bound({p1.x, -INF_INT, -INF_INT, -1});
        int cx, cy, cz;
        cx = it->x;
        auto it2 = v.lower_bound({cx, p1.y, -INF_INT, -1});
        if(it2 == v.begin()){
            cy = it2->y;
        }else if(it2 == v.end()){
            it2 = prev(it2);
            cy = it2->y;
        }else{
            if(it2->x == cx){
                cy = it2->y;
            }else{
                it2 = prev(it2);
                cy = it2->y;
            }
        }
        auto it3 = v.lower_bound({cx, cy, p1.z, -1});
        if(it3 == v.begin()){
            cz = it3->z;
        }else if(it3 == v.end()){
            it3 = prev(it3);
            cz = it3->z;
        }else{
            if(it3->x == cx && it3->y == cy){
                cz = it3->z;
            }else{
                it3 = prev(it3);
                cz = it3->z;
            }
        }
        auto p2 = *v.lower_bound({cx,cy,cz, -1});
        v.erase(p2);
        cout << p1.i << " " << p2.i << "\n";
    }
}
