#include <bits/stdc++.h>

const long double PI = acosl(-1);
using namespace std;
int main(){
    long double a,b,c,d,e,f,g,l1,l2,l3;
    a = 0.75;
    b = tanl(PI*54/180)/2;

    f = b/2;
    b*=b;
    c = a-b;

    c = sqrtl(c);

    d = sqrtl(2)/12;
    e = sqrtl(2)/6;
    f = (c*f*5)/3;
    cin >> l1 >> l2 >> l3;
    cout << setprecision(20) << d*(l1*l1*l1) + e*(l2*l2*l2) + f * (l3*l3*l3);


}
