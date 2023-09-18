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
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int div = n/k;
        int r = n - div*k;
        int xorv = 0;
        for(int i=0;i<div;i++){
            cout << "? " << 1+i*k << "\n";
            cout.flush();
            int x;
            cin >> x;
            xorv ^= x;
        }
        //now from div*k+1 to n (r numbers, r even.)
        r /= 2;
        if(r){
            cout << "? " << div*k+1-(k-r) << "\n";
            cout.flush();
            int x;
            cin >> x;
            xorv ^= x;
            cout << "? " << div*k+1-(k-2*r) << "\n";
            cout.flush();
            cin >> x;
            xorv ^= x;
        }
        cout << "! " << xorv << "\n";
        cout.flush();
    }
}
