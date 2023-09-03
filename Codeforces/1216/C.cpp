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
    int x1, x2, y1, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2;
    pair<int,int> p[] = {{x1, y1}, {x1, y2}, {x2, y1}, {x2, y2}};
    vector<int> a, b;
    cin >> x1 >> y1 >> x2 >> y2;
    for(int i=0;i<4;i++){
        if(p[i].first >= x1 && p[i].first <= x2 && p[i].second >= y1 && p[i].second <= y2){
            a.push_back(i);
        }
    }
    cin >> x3 >> y3 >> x4 >> y4;
    for(int i=0;i<4;i++){
        if(p[i].first >= x3 && p[i].first <= x4 && p[i].second >= y3 && p[i].second <= y4){
            b.push_back(i);
        }
    }

    if(a.size() == 4 || b.size() == 4) cout << "NO\n";
    else if(a.size() != 2 || b.size() != 2) cout << "YES\n";
    else{
        set<int> st;
        for(auto x : a) st.insert(x);
        for(auto x : b) st.insert(x);
        if(st.size() != 4) cout << "YES\n";
        else{
            vector<int> aux1 = {0, 1}; //vertical
            vector<int> aux2 = {0, 2};
            if(a == aux1 || b == aux1){
                if(a == aux1){
                    if(x2 < x3) cout << "YES\n";
                    else cout << "NO\n";
                }else{
                    if(x4 < x1) cout << "YES\n";
                    else cout << "NO\n";
                }
            }else{ 
                if(a == aux2){
                    if(y2 < y3) cout << "YES\n";
                    else cout << "NO\n";
                }else{
                    if(y4 < y1) cout << "YES\n";
                    else cout << "NO\n";
                }
            }
        }
    }
}
