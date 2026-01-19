#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int query(int a, int b){
    cout << "? " << a << " " << b << "\n";
    int ans;
    cout.flush();
    cin >> ans;
    return ans;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int cf = 0;
        int idx = -1;
        int p = -1;
        for(int i=n-1;i>=1;i--){
            int ans = query(i, i+1);
            if(cf == 0){
                if(ans == 1) continue;
                else{
                    cf = 1;
                    p = i+1;
                }
            }else if(cf == 1){
                if(ans == 0) continue;
                else{
                    idx = i;
                    break;
                }
            }
        }
        if(idx == -1){
            cout << "! -1\n";
            cout.flush();
        }else{
            vector<int> ansv;
            for(int i=1;i<idx;i++) ansv.push_back(i);
            vector<int> ord;
            ord.push_back(p);
            int p1 = p-1, p2 = p+1;
            while(p1 > idx && p2 <= n){
                int ans = query(p1, p2);
                if(ans == 1) ord.push_back(p1--);
                else ord.push_back(p2++);
            }
            while(p1 > idx) ord.push_back(p1--);
            while(p2 <= n) ord.push_back(p2++);
            int dn = -1;
            for(auto &x : ord){
                int ans = query(idx, x);
                if(ans == 1){
                    ansv.push_back(x);
                    x = idx;
                    break;
                }
            }
            for(auto x : ord){
               ansv.push_back(x);
            }
            cout << "! ";
            for(auto x : ansv) cout << x << " ";
            cout << "\n";
            cout.flush();
        }
    }
}
