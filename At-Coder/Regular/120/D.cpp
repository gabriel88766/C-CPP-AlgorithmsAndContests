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
    vector<pair<int, int>> vp;
    vector<bool> neg(2*n, false);
    for(int i=0;i<2*n;i++){
        int x;
        cin >> x;
        vp.push_back({x, i});
    }
    sort(vp.begin(), vp.end());
    for(int i=0;i<n;i++) neg[vp[i].second] = true;
    stack<bool> st;
    for(int i=0;i<2*n;i++){
        if(st.size() && st.top() != neg[i]){
            cout << ")";
            st.pop();
        }else{
            cout << "(";
            st.push(neg[i]);
        }
    }
    cout << "\n";
}
