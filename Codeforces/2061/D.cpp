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
        int n, m;
        cin >> n >> m;
        priority_queue<int> p1, p2;
        ll s1 = 0, s2 = 0;
        for(int i=1;i<=n;i++){
            int x;
            cin >> x;
            s1 += x;
            p1.push(x);
        }
        for(int i=1;i<=m;i++){
            int x;
            cin >> x;
            s2 += x;
            p2.push(x);
        }
        if(s1 != s2){
            cout << "No\n";
            continue;
        }
        while(p1.size() && p2.size()){
            if(p2.size() > p1.size()) break;
            if(p2.top() == p1.top()){
                p1.pop();
                p2.pop();
            }else if(p1.top() > p2.top()) break;
            else{
                int hf = p2.top() / 2;
                int x = p2.top();
                p2.pop();
                p2.push(hf);
                p2.push(x - hf);
            }
        }   
        if(p1.size() || p2.size()) cout << "No\n";
        else cout << "Yes\n";
    }
}
