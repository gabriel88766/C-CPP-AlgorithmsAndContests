#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.);
double EPS = 1e-6; 
using namespace std;

typedef double float_type; //floating point type

template<typename T>
bool ge(T a, T b){
    if(std::is_floating_point<T>::value){
        return a + EPS >= b;
    }else{
        return a >= b;
    }
    
}
template<typename T>
bool le(T a, T b){
    if(std::is_floating_point<T>::value){
        return a - EPS <= b;
    }else{
        return a <= b;
    }
}

template<typename T>
bool eq(T a, T b){
    return ge(a,b) && le(a,b);
}

template<typename T>
struct Point{
    T x, y;
    Point(){}
    Point(T x, T y) { this->x = x; this->y = y;}
    Point operator -() {return Point(-x, -y);}
    Point operator -(Point p) { return Point(x - p.x, y - p.y);}
    Point operator +(Point p) { return Point(x + p.x, y + p.y);}
    Point operator *(T d){ return Point(x * d, y * d);}
    Point operator /(T d){ return Point(x/d, y/d);} //integer division, maybe not what you want.
    bool operator ==(Point p){
        if(std::is_floating_point<T>::value){
            return eq(x, p.x) && eq(y, p.y);
        }else{
            return x == p.x && y == p.y;
        }
    }
    float_type abs() {return sqrt(x*x+y*y); } //remove sqrt and use long long for more precision 
    float_type dist(Point p){ return (*this-p).abs();} //long long too
    // returns arg ∈ [0, 2π)
    float_type arg() { 
        float_type ang = atan2l(y, x);
        if(ang < 0) ang += 2*PI;
        return ang;
    }
    T abs2() {return x*x + y*y;} //for integers
    T dist2(Point p) {return (*this-p).abs2(); } //integers too
    Point rot_dg(float_type g){// g degrees, don't use if type is long long
        static_assert(std::is_floating_point<T>::value);
        g *= PI/180;
        return Point(x * cos(g) - y * sin(g), x * sin(g) + y * cos(g)); 
    }
    Point rot(float_type rad){// rad is [0, 2pi], don't use if type is long long
        static_assert(std::is_floating_point<T>::value);
        return Point(x * cos(rad) - y * sin(rad), x * sin(rad) + y * cos(rad)); 
    }
    Point rot90(){ 
        return Point(-y, x);
    }
    T cross(Point p){ return x*p.y - y*p.x;}
    T dot(Point p){ return x*p.x + y*p.y;}
};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<Point<double>> a(n), b(n);
    for(int i=0;i<n;i++){
        cin >> a[i].x >> a[i].y;
    }
    for(int i=0;i<n;i++){
        cin >> b[i].x >> b[i].y;
    }
    if(n == 1){
        cout << "Yes\n";
        return 0;
    }
    bool ok = false;
    for(int i=0;i<n;i++){
        auto cx = a;
        auto dx = b;
        for(int j=0;j<n;j++){
            cx[j] = cx[j] - a[0];
            dx[j] = dx[j] - b[i];
        }
        //matched a[0] with b[i];
        //now match a[1] with b[j];
        for(int j=0;j<n;j++){
            if(eq(dx[j].abs(), cx[1].abs())){
                double dif = dx[j].arg() - cx[1].arg();
                auto ex = cx;
                for(int k=0;k<n;k++){
                    ex[k] = ex[k].rot(dif);
                }
                //check if ex == dx
                bool cok = true;
                for(int u=0;u<n;u++){
                    bool ccok = false;
                    for(int v=0;v<n;v++){
                        if(ex[u] == dx[v]) ccok = true;
                    }
                    if(!ccok){
                        cok = false;
                        break;
                    }
                }
                if(cok){
                    ok = true;
                    break;
                }
            }
        }
        if(ok) break;
    }
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}
