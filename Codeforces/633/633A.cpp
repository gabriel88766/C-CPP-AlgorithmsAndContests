//test
#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


int gcd_euclid(int a, int b, int &x, int &y){ //solves ax+by = g where g = gcd(a,b)
    if(b == 0){ //meaning 1 * a - 0 * 0 = a, (gcd)
        x = 1; y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd_euclid(b, a % b, x1, y1); //if b > a then this step reverses it
    x = y1;
    y = x1 - y1 * (a/b); 
    return d;
}

bool find_xy(int a, int b, int c, int &x, int &y){ //first solution for x > 0
    int g = gcd_euclid(abs(a), abs(b), x, y);
    if(c % g) return false;
    if(a < 0) x = -x;
    if(x < 0) x += b;
    x = (x * c/g)  % (b/g); //mulmod if risk of overflow
    y = (c - a*x) / (b/g);
    return true;
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int a, b, c, x, y;
    cin >> a >> b >> c;
    if(!find_xy(a,b,c,x,y)) cout << "No";
    else{
        if( y >= 0) cout << "Yes";
        else cout << "No";
    }
    
}   
