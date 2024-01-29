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
    int n;
    cin >> n;
    vector<int> v1(2*n+1, 0), v2(2*n+1, 0);
    for(int i=1;i<=n;i++){
        int a, b;
        cin >> a >> b;
        if(a > b) swap(a, b);
        v1[a] = i;
        v2[b] = i;
    }
    stack<int> st;
    bool ok = false;
    for(int i=1;i<=2*n;i++){
        if(v1[i]) st.push(v1[i]);
        if(v2[i]){
            if(st.top() == v2[i]) st.pop();
            else{
                ok = true;
                break;
            }
        }
    }
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}
