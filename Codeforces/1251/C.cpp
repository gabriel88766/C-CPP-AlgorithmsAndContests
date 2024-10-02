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
        string num;
        cin >> num;
        string od = "", ev = "";
        for(auto c : num){
            int d = c - '0';
            if(d % 2) od += c;
            else ev += c;
        }
        string ans = "";
        int p0 = 0, p1 = 0;
        while(p0 < od.size() && p1 < ev.size()){
            if(od[p0] < ev[p1]){
                ans += od[p0];
                p0++;
            }else{
                ans += ev[p1];
                p1++;
            }
        }
        while(p0 < od.size()) ans += od[p0++];
        while(p1 < ev.size()) ans += ev[p1++];
        cout << ans << "\n";
    }
}
