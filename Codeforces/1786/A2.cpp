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
        int n, a1 = 0, a2=0, b1 = 0, b2=0;
        cin >> n;
        int curn = 1, sum = 0;
        while(n){
            if(n >= curn) n -= curn;
            else{
                bool alice;
                if(curn % 4 == 1) alice = true;
                else if(curn % 4 == 2) alice = false;
                else if(curn % 4 == 3) alice = false;
                else alice = true;
                if(alice){
                    a1 += n/2, a2 += n/2;
                    if(n % 2){
                        if(sum % 2) a2++;
                        else a1++;
                    }
                }else{
                    b1 += n/2, b2 += n/2;
                    if(n % 2){
                        if(sum % 2) b2++;
                        else b1++;
                    }
                }
                break;
            }
            if(curn % 4 == 1){
                a1 += curn/2, a2 += curn/2;
                if(sum % 2) a2++;
                else a1++;
            }
            else if(curn % 4 == 2) b1 += curn/2, b2 += curn/2;
            else if(curn % 4 == 3){
                b1 += curn/2, b2 += curn/2;
                if(sum % 2) b2++;
                else b1++;
            }
            else a1 += curn/2, a2 += curn/2;
            sum += curn;
            curn++;
        }
        cout << a1 << " " << a2 << " " << b1 << " " << b2 << "\n";


    }
}
