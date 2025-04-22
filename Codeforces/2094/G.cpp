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
        int q;
        cin >> q;
        ll S = 0, Sr = 0, sz = 0, Sn = 0;
        deque<int> arr;
        bool rev = false;
        while(q--){
            int s;
            cin >> s;
            if(s == 1){
                if(rev){
                    Sr += Sn - sz * arr.front();
                    S += sz * arr.front() - Sn; 
                    arr.push_back(arr.front());
                    arr.pop_front();
                }else{
                    S += Sn - sz * arr.back();
                    Sr += sz * arr.back() - Sn; 
                    arr.push_front(arr.back());
                    arr.pop_back();
                }
            }else if(s == 2){
                if(rev) rev = false;
                else rev = true;
            }else{
                cin >> s;
                Sn += s;
                sz++;
                if(rev){
                    Sr += sz * s;
                    S += Sn;
                    arr.push_front(s);
                }else{
                    Sr += Sn;
                    S += sz * s;
                    arr.push_back(s);
                }
            }
            if(rev) cout << Sr << "\n";
            else cout << S << "\n";
        }
    }
}
