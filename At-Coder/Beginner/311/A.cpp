#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bool ok[3];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    string s;
    int n;
    cin >> n >> s;
    for(int i=0;i<n;i++){
        ok[s[i]-'A'] = true;
        bool allok = true;
        for(int j=0;j<3;j++) allok &= ok[j];
        if(allok){
            cout << i+1;
            return 0;
        }
    }
}
