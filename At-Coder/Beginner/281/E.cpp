#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Set{
    multiset<int> s1, s2;
    ll sum = 0;
    int k;
    Set(int k){
        this->k = k;
    }
    int size(){return s1.size() + s2.size();}
    void balance(){
        while(s1.size() && s2.size() && *prev(s1.end()) > *s2.begin()){
            int num1 = *prev(s1.end());
            s1.erase(prev(s1.end()));
            sum -= num1;
            s2.insert(num1);
        }
        while(s1.size() < k && s2.size() > 0){
            int num = *s2.begin();
            sum += num;
            s2.erase(s2.begin());
            s1.insert(num);
        }
        while(s1.size() > k){
            int num = *prev(s1.end());
            sum -= num;
            s1.erase(prev(s1.end()));
            s2.insert(num);
        }
    }
    void insert(int num){
        s1.insert(num);
        sum += num;
        balance();
    }
    void erase(int num){
        if(s2.lower_bound(num) != s2.end() && *s2.lower_bound(num) == num) s2.erase(s2.find(num));
        else{
            s1.erase(s1.find(num));
            sum -= num;
        }
        balance();
    }
};

int v[200005];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m, k;
    cin >> n >> m >> k;
    Set s(k);
    for(int i=1;i<=n;i++){
        cin >> v[i];
        s.insert(v[i]);
        if(s.size() >= m){
            cout << s.sum << " ";
            s.erase(v[i-m+1]);
        }
    }
    cout << "\n";
}
