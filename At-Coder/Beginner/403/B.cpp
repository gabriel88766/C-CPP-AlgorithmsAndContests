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
    string a, b;
    cin >> a >> b;
    for(int i=0;i<a.size();i++){
        bool cok = true;
        for(int j=0;j<b.size();j++){
            if(i+j < a.size() && (a[i+j] == '?' || a[i+j] == b[j]));
            else cok = false;
        }
        if(cok){
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
}
