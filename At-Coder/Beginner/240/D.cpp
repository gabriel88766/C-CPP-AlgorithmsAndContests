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
    stack<pair<int,int>> st;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        if(st.empty()){
            st.push({x, 1});
        }else{
            if(st.top().first == x){
                st.push({x, st.top().second + 1});
            }else{
                st.push({x, 1});
            }
        }
        if(st.top().first == st.top().second){
            for(int i=0;i<x;i++) st.pop();
        }
        cout << st.size() << "\n";
    }
}
