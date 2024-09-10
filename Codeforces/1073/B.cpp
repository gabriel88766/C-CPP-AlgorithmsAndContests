#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+1;
int inb[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    stack<int> st;
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    for(int i=n-1;i>=0;i--) st.push(v[i]);
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        if(!inb[x]){
            int cnt = 0;
            while(st.size() && (inb[x] == 0)){
                auto u = st.top();
                st.pop();
                inb[u] = 1;
                cnt++;
            }
            cout << cnt << " ";
        }else cout << "0 ";
    }
    cout << "\n";
}
