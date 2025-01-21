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
        cin >> n;
        if(n == 10){
            cout << "1 1 2 3 1 2 2 4 4 4\n"; //11
            continue;
        }else if(n == 11){
            cout << "1 1 2 3 1 2 2 4 4 5 4\n"; //13
            continue;
        }
        vector<int> aux = {0, 0, 1, 2, 0, 1, 1};
        for(int i=1;i<=n;i++){
            int q = (i-1)/7;
            int r = (i-1) % 7;
            cout << 3*q + aux[r] + 1 << " ";
        }
        
        cout << "\n";
    }
}
