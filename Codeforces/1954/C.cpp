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
        string a, b;
        cin >> a >> b;
        bool dif = false;
        bool alow = false;
        for(int i=0;i<a.size();i++){
            if(a[i] == b[i]) continue;
            else{
                if(dif){
                    if(alow){
                        if(a[i] < b[i]) swap(a[i], b[i]);
                    }else{
                        if(a[i] > b[i]) swap(a[i], b[i]);
                    }
                }else{
                    dif = true;
                    if(a[i] < b[i]) alow = true;
                    else alow = false;
                }
            }
        }
        cout << a << "\n" << b << "\n";
    }
}
