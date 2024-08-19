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
        int a, b, n , m;
        cin >> a >> b >> n >> m;
        int lx = 1, rx = b, ly = 1, ry = a;
        set<pair<int,int>> ch1, ch2;
        for(int i=0;i<n;i++){
            int x, y;
            cin >> x >> y;
            ch1.insert({x, y});
            ch2.insert({y, x});
        }
        int pa = 0, pb = 0;
        for(int i=0;i<m;i++){
            char pos;
            int qt;
            int cur = 0;
            cin >> pos >> qt;
            if(pos == 'D'){
                ry -= qt;
                while(ch1.size() && prev(ch1.end())->first > ry){
                    auto [x, y] = *prev(ch1.end());
                    ch1.erase({x,y});
                    ch2.erase({y, x});
                    cur++;
                }
            }else if(pos == 'U'){
                ly += qt;
                while(ch1.size() && ch1.begin()->first < ly){
                    auto [x, y] = *ch1.begin();
                    ch1.erase({x,y});
                    ch2.erase({y, x});
                    cur++;
                }
            }else if(pos == 'L'){
                lx += qt;
                while(ch2.size() && ch2.begin()->first < lx){
                    auto [x, y] = *ch2.begin();
                    ch2.erase({x, y});
                    ch1.erase({y, x});
                    cur++;
                }
            }else{
                rx -= qt;
                while(ch2.size() && prev(ch2.end())->first > rx){
                    auto [x, y] = *prev(ch2.end());
                    ch2.erase({x, y});
                    ch1.erase({y, x});
                    cur++;
                }
            }
            if(i % 2) pb += cur;
            else pa += cur;
        }
        cout << pa << " " << pb << "\n";
    }
}
