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
        int n;
        ll a,b = 0,c=0,k;
        cin >> n >> k;
        a = 4*n;
        vector<ll> nums(n);
        for(int i=0;i<n;i++){
            cin >> nums[i];
            b += nums[i];
            c += nums[i]*nums[i];
        }
        c -= k;
        b *= 4;
        ll lo = -b/(2*a) + 1, hi, mid;
        hi = sqrtl(-c/a)+10;
        while(lo != hi){
            mid = lo + (hi-lo)/2;
            if(a*mid*mid + b*mid+c >= 0) hi = mid;
            else lo = mid + 1;
        }
        cout << lo << "\n";


    }
}
