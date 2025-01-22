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
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> v(n+1);
        for(int i=1;i<=n;i++) cin >> v[i];
        ll sum = 0;
        priority_queue<int> p1;
        for(int i=l;i<=r;i++){
            sum += v[i];
            p1.push(v[i]);
        }
        auto cp = p1;
        priority_queue<int, vector<int>, greater<int>> p2;
        for(int i=1;i<l;i++){
            p2.push(v[i]);
        }
        ll s1 = 0, s2 = 0;
        while(p1.size() && p2.size() && p2.top() < p1.top()){
            s1 += p1.top() - p2.top();
            p1.pop();
            p2.pop();
        }
        while(p2.size()) p2.pop();
        for(int i=r+1;i<=n;i++){
            p2.push(v[i]);
        }
        p1 = cp;
        while(p1.size() && p2.size() && p2.top() < p1.top()){
            s2 += p1.top() - p2.top();
            p1.pop();
            p2.pop();
        }
        sum -= max(s1, s2);
        cout << sum << "\n";
        
    }
}
