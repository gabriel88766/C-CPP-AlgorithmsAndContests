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
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    int y = 0;
    bool ok = true;
    for(int i=1;i<n;i++){
        if(abs(v[i] - v[i-1]) != 1){
            if(v[i] == v[i-1]){
                ok = false;
                y = INF_INT;
                break;
            }
            if(y){
                if(abs(v[i] - v[i-1]) != y){
                    ok = false;
                    break;
                }
            }else y = abs(v[i] - v[i-1]);
        }
    }
    if(y == 0){
        cout << "YES\n";
        cout << "1000000000 1000000000\n";
        return 0;
    }
    int x = 1000000000;
    for(int i=1;i<n;i++){
        if(abs(v[i] - v[i-1]) == 1){
            if((v[i]+y-1)/y != (v[i-1]+y-1)/y){
                ok = false;
                break;
            }
        }
    }
    if(!ok){
        cout << "NO\n";
    }else{
        cout << "YES\n";
        cout << x << " " << y << "\n";
    }
    
}
