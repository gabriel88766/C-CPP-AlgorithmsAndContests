#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b, d, r;
    double f;
    cin >> a >> b;
    d = a/b;
    r = a%b;
    f = ((double)a)/b;
    cout << d << " " << r << " " << setprecision(10) << fixed << f << "\n";
}