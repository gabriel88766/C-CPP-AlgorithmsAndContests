#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    while(t--){
        int n, a = 0, b = 0;
        cin >> n;
        int curn = 1;
        while(n){
            if(n >= curn) n -= curn;
            else{
                if(curn % 4 == 1) a+= n;
                else if(curn % 4 == 2) b+= n;
                else if(curn % 4 == 3) b += n;
                else a+=n;
                break;
            }
            if(curn % 4 == 1) a+= curn;
            else if(curn % 4 == 2) b+= curn;
            else if(curn % 4 == 3) b += curn;
            else a+=curn;
            curn++;
        }
        cout << a << " " << b << "\n";


    }
}
