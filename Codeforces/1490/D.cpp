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
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        vector<int> h(n+1);
        h[n] = -1;
        queue<tuple<int,int,int>> q;
        q.push({0, n-1, n});
        while(!q.empty()){
            auto [l, r, p] = q.front();
            q.pop();
            auto m = max_element(v.begin()+l, v.begin()+r+1) - v.begin();
            h[m] = h[p] + 1;
            if(l < m) q.push({l, m-1, m});
            if(m < r) q.push({m+1, r, m});
        }
        for(int i=0;i<n;i++) cout << h[i] << " ";
        cout << "\n";
    }
}
