#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct MySet{
    multiset<int> m1, m2;
    ll S1 = 0;
    int g1 = 0;
    void balance(){
        assert(m1.size() + m2.size() >= g1);//while using this structure, this must be asserted
        while(m1.size() > g1){
            int lw = *m1.begin();
            m1.erase(m1.begin());
            m2.insert(lw);
            S1 -= lw; 
        }
        while(m1.size() < g1){
            int gr = *prev(m2.end());
            m2.erase(prev(m2.end()));
            m1.insert(gr);
            S1 += gr;
        }
    }
    void insert(int num){
        m2.insert(num);
    }
    void erase(int num){
        if(m1.count(num)){
            m1.erase(m1.find(num));
            S1 -= num;
        }else{
            assert(m2.count(num)); //assert num is in set
            m2.erase(m2.find(num));
        }
    }
};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int a, b, n;
    cin >> a >> b >> n;
    vector<pair<int, int>> v;
    for(int i=0;i<n;i++){
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end(), greater<pair<int, int>>());
    MySet s1, s2;
    ll ans = 0, cur = 0;
    for(int i=a-1;i<a+b;i++){
        if(i == a - 1){
            //It's time to make both sets
            for(int j=0;j<a;j++){
                cur += v[j].first;
                s1.insert(v[j].second - v[j].first);
            }
            for(int j=a;j<n;j++){
                s2.insert(v[j].second);
            }
        }else{
            cur += v[i].first;
            s2.erase(v[i].second);
            s1.insert(v[i].second - v[i].first);
        }
        s1.g1 = i - a + 1;
        s2.g1 = a+b - i - 1;
        s1.balance();
        s2.balance();
        ans = max(ans, cur + s1.S1 + s2.S1);
    }
    cout << ans << "\n";
}
