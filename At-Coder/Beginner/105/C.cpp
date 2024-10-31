#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int ans[40];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    int c = 0;
    for(int j=0;j<40;j++){
        ll cur = 1LL << j;
        int cb = c;
        if(cur & n) cb++;
        if(j % 2){
            if(cb == -1 || cb == 0){
                ans[j] = cb;
                c = 0;
            }else{
                ans[j] = cb - 2;
                c = 1;
            }
        }else{
            if(cb == 0 || cb == 1){
                ans[j] = cb;
                c = 0;
            }else if(cb == -1){
                ans[j] = 1;
                c = -1;
            }else{
                //cb == 2
                ans[j] = 0;
                c = 1;
            }
        }
    }
    string s = "";
    for(int j=0;j<40;j++) s += (char)(abs(ans[j]) + '0');
    while(s.back() == '0') s.pop_back();
    reverse(s.begin(), s.end());
    if(s.size() == 0) s += '0';
    cout << s << "\n";
}
