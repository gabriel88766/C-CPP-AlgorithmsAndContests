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
        deque<int> dq;
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            dq.push_back(x);
        }
        int cur = 0;
        vector<int> ans;
        while(dq.size()){
            if(cur % 2){
                ans.push_back(dq.back());
                dq.pop_back();
            }else{
                ans.push_back(dq.front());
                dq.pop_front();
            }
            cur++;
        }
        for(auto x : ans) cout << x << " ";
        cout << "\n";
    }
}
