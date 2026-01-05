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
        int n, x, y;
        cin >> n >> x >> y;
        string s;
        cin >> s;
        vector<int> p(n);
        for(int i=0;i<n;i++){
            cin >> p[i];
        }
        bool h0 = false, h1 = false;
        for(auto c : s){
            if(c == '0') h0 = true;
            if(c == '1') h1 = true;
        }
        bool ok = true;
        ll sum = 0;
        for(int i=0;i<n;i++) sum += p[i];
        if(sum > x + y) ok = false;
        if(ok){
            if(h0 && h1){
                int alx = 0, aly = 0, txy = 0, tyx = 0;
                for(int i=0;i<n;i++){
                    if(s[i] == '0'){
                        alx += p[i];
                        txy += (p[i] - 1) / 2;
                    }else{
                        aly += p[i];
                        tyx += (p[i] - 1) / 2;
                    }
                }
                if(alx > x){
                    assert(aly <= y);
                    if(txy < alx-x) ok = false;
                }
                if(aly > y){
                    if(tyx < aly - y) ok = false;
                }
            }else{
                if(h1){
                    //swap to 0
                    swap(x, y);
                }
                if(x < y + n) ok = false;
                int alx = 0,  txy = 0;
                for(int i=0;i<n;i++){
                    alx += p[i];
                    txy += (p[i] - 1) / 2;
                }
                if(txy < alx - x) ok = false;
            }
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
