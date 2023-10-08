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
        int n, m, k;
        cin >> n >> m >> k;
        if(n % m){
            int big = n % m;
            int bb = 1;
            int ttb = big * (n/m + 1);
            int tts = n - ttb;
            for(int i=0;i<k;i++){
                for(int j=0;j < big; j++){
                    cout << n/m+1 << " ";
                    for(int i=0;i<n/m+1;i++){
                        cout << bb++ << " ";
                        if(bb > n) bb = 1;
                    }
                    cout << "\n";
                }
                int p = bb;
                for(int j=big; j < m; j++){
                    cout << n/m << " ";
                    for(int i=0;i<n/m;i++){
                        cout << p++ << " ";
                        if(p > n) p = 1;
                    }
                    cout << "\n";
                }
            }
        }else{
            for(int i=0;i<k;i++){
                for(int j=0;j<m;j++){
                    cout << n/m << " ";
                    for(int l=1;l<=n/m;l++){
                        cout << l + j*(n/m) << " ";
                    }
                    cout << "\n";
                }
            }
        }
        cout << "\n";
    }
}
