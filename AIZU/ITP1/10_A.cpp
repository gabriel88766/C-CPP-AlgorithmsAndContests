#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin);
    double a,b,c,d;
    cin >> a >> b >> c >> d;
    cout << setprecision(10) << fixed << sqrt((a-c)*(a-c) + (b-d) * (b-d));

}

