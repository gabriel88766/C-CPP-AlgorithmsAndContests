#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct State{
    int a, b, msk;
};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int N, B, A, C;
    cin >> N >> B >> A;
    C = N-B-A;
    if(A > 10) A = 0;
    if(C > 10) C = 0;
    queue<State> st;
    int x = 0;
    if( B <= 10) x |= (1 << B);
    st.push({A,C, x});
    int ans = A+C;
    while(!st.empty()){
        auto u = st.front();
        ans = min(ans, u.a+u.b);
        st.pop();
        for(int i=1;i<=10;i++){
            if(u.msk & (1 << i)) continue;
            if(i <= u.a){
                State v = {u.a-i, u.b, u.msk | (1 << i)};
                st.push(v);
            }
            if(i <= u.b){
                State v = {u.a, u.b-i, u.msk | (1 << i)};
                st.push(v);
            }
        }
    }

    cout << ans;
}
