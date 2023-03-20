#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bool tryit(vector<int> &v, int x){
    for(int i=0;i<v.size();i++) v[i] ^= x;
    int cnt = 0;
    for(int i=0;i<v.size();i++) if(v[i] == 1) cnt++;
    if(cnt % 2) return false;
    stack<int> st;
    for(int i=0;i<v.size();i++){
        if(v[i] % 2){
            if(!st.empty()){
                int last = st.top();
                if((i-last) % 2) st.pop();
                else st.push(i);
            }else st.push(i);
        }
    }
    return st.empty();
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, aux;
    cin >> n;
    vector<int> v(n);
    cin >> v[0];

    if(v[0]%2) aux = 1;
    else aux = 0;
    v[0] = 0;
    for(int i=1;i<n;i++){
        cin >> v[i];
        v[i] %= 2;
        v[i] ^= aux;
    }
    if(tryit(v, 0) || tryit(v, 1)) cout << "YES\n";
    else cout << "NO\n";
}
