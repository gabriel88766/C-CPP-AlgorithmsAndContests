#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

ll myAbs(ll a){
    return a >= 0 ? a : -a;
}

ll myGcd(ll a, ll b){
    if(a < 0 || b < 0) return myGcd(myAbs(a), myAbs(b));
    if(a < b) return myGcd(b, a);
    if(b == 0) return a;
    else return myGcd(b, a - (a/b) * b);
}
ll myLcm(ll a, ll b){
    if(a < 0 || b < 0) return myLcm(myAbs(a), myAbs(b));
    if(a == 0 || b == 0) return 0;
    return (a * (b / myGcd(a, b)));
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll ans = 1;
    for(ll i=1;i<=20;i++) ans = myLcm(ans, i); 
    cout << ans << endl;

}
