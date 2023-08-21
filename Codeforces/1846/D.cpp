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
    cout << fixed << setprecision(10);
    while(t--){
        int n;
        double d, h;
        double S = 0;
        cin >> n >> d >> h;
        vector<double> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        for(int i=0;i<(n-1);i++){
            double b = 0;
            if(v[i+1]-v[i] < h-0.001){
                b = (1.-(v[i+1]-v[i])/h)*d;
            }
            S += (d*h)/2 * (1-(b*b)/(d*d));
        }
        S += (d*h)/2;
        cout << S << "\n";
    }
}
