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
    freopen("input.txt", "r", stdin); //test input
    freopen("output.txt", "w", stdout); //test input
    int n;
    cin >> n;
    vector<tuple<int, int, int, int>> vt;
    for(int i=1;i<=n;i++){
        int a, b;
        cin >> a >> b;
        
        vt.push_back({a, b, i, 1});
        vt.push_back({-a, b, i, 2});
        vt.push_back({a, -b, i, 3});
        vt.push_back({-a, -b, i, 4});
        
    }
    sort(vt.begin(), vt.end());
    //sweep line closest points
    int dist2 = INF_INT;
    tuple<int, int, int, int> ans = {-1, -1, -1, -1};
    auto [a, b, c, d] = vt[0];
    set<tuple<int, int, int, int>> st;
    st.insert({b,a,c,d});
    int cp = 0;
    for(int i=1;i<vt.size();i++){
        auto [e,f,g,h] = vt[i];
        int sqt = sqrt(dist2) + 1;
        auto it = st.lower_bound({f - sqt, -INF_INT, -INF_INT, - INF_INT});
        while(it != st.end() && get<0>(*it) - f <= sqt){
            if(get<2>(*it) == g){
                ++it;
                continue;
            }
            int dx = get<1>(*it) - e;
            int dy = get<0>(*it) - f;
            if(dx*dx+dy*dy < dist2){
                dist2 = dx*dx + dy*dy;
                ans = {g, h, get<2>(*it), get<3>(*it)};
            }
            ++it;
        }
        st.insert({f,e,g,h});
        while((e - get<0>(vt[cp])) * (e - get<0>(vt[cp])) > dist2){
            st.erase({get<1>(vt[cp]), get<0>(vt[cp]), get<2>(vt[cp]), get<3>(vt[cp])});
            cp++;
        }
    }
    auto [e,f,g,h] = ans;
    cout << e << " " << f << " " << g << " " << (5-h) << "\n";

}