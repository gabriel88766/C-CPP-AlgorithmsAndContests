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
    string s;
    cin >> s;
    deque<char> dq;
    for(auto c : s) dq.push_back(c);
    int fr = 1;
    int q;
    cin >> q;
    for(int i=1;i<=q;i++){
        int tq;
        cin >> tq;
        if(tq == 1){
            fr ^= 1;
        }else{
            int f;
            char c;
            cin >> f >> c;
            f--;
            if((f ^ fr)) dq.push_front(c);
            else dq.push_back(c);
        }
    }
    if(!fr){
        reverse(dq.begin(), dq.end());
    }
    for(auto c : dq) cout << c;
    cout << "\n";
}
