#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Point{
    double x, y;
    Point(){}
    Point(double x, double y){
        this->x = x, this->y=y;
    }
    Point operator+ (Point p){
        return Point(x+p.x, y+p.y);
    }
    Point operator- (Point p){
        return Point(x-p.x, y-p.y);
    }
    Point operator* (double d){
        return Point(x*d, y*d);
    }
    Point operator/ (double d){
        return Point(x/d, y/d);
    }
    Point rot(){
        return Point(-y, x);
    }
};

const double f = sqrt(3)/6;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Point P1(0.,0.), P2(100., 0.);
    vector<Point> ans;
    int n;
    cin >> n;
    ans.push_back(P1), ans.push_back(P2);
    for(int i=1;i<=n;i++){
        int sz = ans.size();
        vector<Point> aux(4*(sz-1)+1);
        int cur = 0;
        for(int i=0;i<(ans.size()-1);i++){
            aux[cur] = ans[i];
            aux[cur+1] = ans[i] + (ans[i+1] - ans[i])/3.;
            aux[cur+2] = ans[i] + (ans[i+1] - ans[i])/2. + (ans[i+1] - ans[i]).rot()*f;
            aux[cur+3] = ans[i] + ((ans[i+1] - ans[i])/3)*2.;
            cur+=4;
        }
        aux[cur] = ans[ans.size()-1];
        ans = aux;
    }
    for(int i=0;i<ans.size();i++) cout << setprecision(10) << fixed << ans[i].x << " " << ans[i].y << "\n";

}
