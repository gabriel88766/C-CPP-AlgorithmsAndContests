#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Point{
    ll x, y;
    Point(){}
    Point(ll x, ll y) { this->x = x; this->y = y;}
    ll cross(Point p){ return x*p.y - y*p.x;}
};

auto find_quadrant = [](const Point &p) {
    if(p.x > 0 && p.y >= 0) return 0; //[0, 90)
    else if(p.x <= 0 && p.y > 0) return 1;//[90, 180)
    else if(p.x < 0 && p.y <= 0) return 2;//[180, 270]
    else return 3;//[270, 360)
};

auto compare = [](Point &p1, Point &p2){
    int q1 = find_quadrant(p1), q2 = find_quadrant(p2);
    if(q1 != q2) return q1 < q2;
    else return p1.cross(p2) > 0;
};

auto equals = [](Point &p1, Point &p2){
    return find_quadrant(p1) == find_quadrant(p2) && p1.cross(p2) == 0;
};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    vector<pair<Point, int>> vp(n);
    for(int i=1;i<=n;i++){
        cin >> vp[i-1].first.x >> vp[i-1].first.y;
        vp[i-1].second = i;
    }
    sort(vp.begin(), vp.end(), [](pair<Point, int> a, pair<Point, int> b){
        if(equals(a.first, b.first)) return a.second < b.second;
        else return compare(a.first, b.first);
    });
    vector<int> pl(n+1);
    for(int i=0;i<n;i++) pl[vp[i].second] = i;
    for(int i=1;i<=q;i++){
        int a, b;
        cin >> a >> b;
        int p1 = pl[a], p2 = pl[b];
        if(equals(vp[p1].first, vp[p2].first)){
            if(p1 < p2) swap(p1, p2);
        }


        if(p1 >= p2){
            for(int jmp=n/2;jmp>=1;jmp>>=1){
                while(p1 + jmp < n && equals(vp[p1].first, vp[p1 + jmp].first)) p1 += jmp;
                while(p2 - jmp >= 0 && equals(vp[p2].first, vp[p2 - jmp].first)) p2 -= jmp;
            }
            cout << p1 - p2 + 1 << "\n";
        }else{
            //p1 < p2
            for(int jmp=n/2;jmp>=1;jmp>>=1){
                while(p1 + jmp < n && equals(vp[p1].first, vp[p1 + jmp].first)) p1 += jmp;
                while(p2 - jmp >= 0 && equals(vp[p2].first, vp[p2 - jmp].first)) p2 -= jmp;
            }
            if(p1 >= p2) cout << n << "\n";
            else cout << n - (p2 - p1 - 1) << "\n";
            
        }
    }
}
