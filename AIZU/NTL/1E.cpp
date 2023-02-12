#include <bits/stdc++.h>

typedef long long int ll;
using namespace std;

ll gcd_euclid(ll a, ll b, ll &x, ll &y){ //solves ax+by = g where g = gcd(a,b)
    if(b == 0){ //meaning 1 * a - 0 * 0 = a, (gcd)
        x = 1; y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd_euclid(b, a % b, x1, y1); //if b > a then this step reverses it
    x = y1;
    y = x1 - y1 * (a/b); 
    return d;
}

int main(){
    ll a, b, x, y, g;
    cin >> a >> b;
    g = gcd_euclid(a, b, x, y);
    while((abs(x-b/g) + abs(y + a/g)) <= (abs(x) + abs(y))) x-=b/g, y+=a/g;
    while((abs(x+b/g) + abs(y - a/g)) < (abs(x) + abs(y))) x+=b/g, y-=a/g;
    cout << x << " " << y << "\n";
}