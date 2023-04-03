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
        char now;
        string s;
        cin >> n >> now >> s;
        s += s;
        if(now == 'g') cout << "0\n";
        else{
            stack<int>  st;
            int maxd = 0;
            for(int i=0;i<2*n;i++){
                if(s[i] == 'g'){
                    while(!st.empty()){
                        maxd = max(maxd, i-st.top());
                        st.pop();
                    }
                }else if(s[i] == now){
                    st.push(i);
                }
            }
            cout << maxd << "\n";
        }
    }
}
