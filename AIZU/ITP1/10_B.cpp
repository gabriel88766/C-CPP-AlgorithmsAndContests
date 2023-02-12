#include<bits/stdc++.h>

using namespace std;
const double PI = acos(-1.);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin);
    double a,b, c;
    cin >> a >> b >> c;
    double d = sqrt(a*a+b*b-2*a*b*cos(c*PI/180.));
    cout << setprecision(12) << fixed;
    cout << a*b*sin(c*PI/180.)/2 << "\n";
    cout << a+b+d << "\n";
    cout << b*sin(c*PI/180.) << "\n";

}

