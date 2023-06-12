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
        string s;
        cin >> n >> s;
        int cur=0, maxv = 0;
        for(auto x : s){
            if(x == '0') cur++;
            else cur--;
            maxv = max(maxv, abs(cur));
        }
        queue<int> q1, q2;
        vector<int> v;
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '0'){
                if(q2.empty()){
                    q1.push(++cnt);
                    v.push_back(cnt);
                }else{
                    v.push_back(q2.front());
                    q1.push(q2.front());
                    q2.pop();
                }
            }else{
                if(q1.empty()){
                    q2.push(++cnt);
                    v.push_back(cnt);
                }else{
                    v.push_back(q1.front());
                    q2.push(q1.front());
                    q1.pop();
                }
            }
        }
        cout << cnt << "\n";
        for(auto x : v) cout << x << " ";
        cout << "\n";
    }
}
