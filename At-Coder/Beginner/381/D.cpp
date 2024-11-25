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
    vector<pair<int,int>> rle;
    int lc = -1, cnt = 0;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        if(x != lc){
            if(lc != -1) rle.emplace_back(lc, cnt);
            lc = x;
            cnt = 1;
        }else cnt++;
    }
    rle.emplace_back(lc, cnt);
    set<int> s;
    queue<int> ord;
    int cur = 0, ans = 0;
    for(auto [a, b] : rle){
        if(b == 1){
            //clean
            cur = 0;
            while(ord.size()) ord.pop();
            s.clear();
        }else if(b == 2){
            while(s.count(a)){
                cur -= 2;
                s.erase(ord.front());
                ord.pop();
            }
            s.insert(a);
            ord.push(a);
            cur += 2;
            ans = max(ans, cur);
        }else{
            if(!s.count(a)){
                ans = max(ans, cur + 2);
            }
            s.clear();
            while(ord.size()) ord.pop();
            s.insert(a);
            ord.push(a);
            cur = 2;
        }
    }
    cout << ans << "\n";
}
