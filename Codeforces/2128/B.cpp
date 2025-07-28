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
        int n;
        cin >> n;
        deque<int> dq(n);
        for(int i=0;i<n;i++) cin >> dq[i];
        bool inc = true;
        string ans;
        auto func = [&](int a, int b, int s){
            if(s == 1) return a > b;
            else return a < b;
        };

        while(dq.size() >= 2){
            int k = dq.size();
            int s;
            if(inc){
                inc = false; 
                s = 1;
            }else{
                inc = true;
                s = 0;
            }
            if(func(dq[0], dq[k-1], s)){ //0
                ans += 'L';
                ans += 'R';
                dq.pop_front();
                dq.pop_back();
            }else{
                ans += 'R';
                ans += 'L';
                dq.pop_back();
                dq.pop_front();
            }
        }
        if(dq.size() == 1){
            ans += 'L';
        }
        cout << ans << "\n";
    }
}
