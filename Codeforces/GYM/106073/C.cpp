#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    deque<int> poly(n+1);
    for(int i=n;i>=0;i--) cin >> poly[i];
    int ans = 0;
    while(poly.front() == 0){
        poly.pop_front();
    }
    while(poly.size() != 1){
        ans++;
        deque<int> newpoly(poly.size());
        for(int i=0;i<poly.size();i++){
            newpoly[i] = poly[i];
            if(i != poly.size() - 1) newpoly[i] += poly[i+1];
        }
        poly = newpoly;
        // for(auto x : poly) cout << x << " ";
        // cout << "\n";
        for(int i=0;i<poly.size();i++) if(poly[i] == 2) poly[i] = 0;
        while(poly.front() == 0) poly.pop_front();
    }
    cout << 2*ans + n << "\n";
}
