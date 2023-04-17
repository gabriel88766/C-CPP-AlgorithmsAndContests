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
    int a;
    int b[3];
    string s;
    cin >> s;
    a = s[0]-'0';
    for(int i=0;i<3;i++) b[i] = s[i+1]-'0';
    for(int i=0;i<8;i++){
        int sum = a;
        for(int j=0;j<3;j++){
            if(i & (1 << j)) sum += b[j];
            else sum -= b[j];
        }
        if(sum == 7){
            cout << a;
            for(int j=0;j<3;j++){
                if(i & (1 << j)) cout << "+";
                else cout << "-";
                cout << b[j];
            }
            cout << "=7";
            return 0;
        }
    }
}
