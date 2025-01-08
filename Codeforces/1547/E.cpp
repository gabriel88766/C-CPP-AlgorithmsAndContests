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
        int n, k;
        cin >> n >> k;
        vector<pair<int,int>> a(k);
        for(int i=0;i<k;i++){
            cin >> a[i].first;
        }
        for(int i=0;i<k;i++){
            cin >> a[i].second;
        }
        sort(a.begin(), a.end());
        //for i = 1;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        multiset<int> s1, s2;
        for(int i=0;i<k;i++){
            int ct = a[i].second + a[i].first - 1;
            s1.insert(ct);
            pq.push({a[i].first, ct});
        }
        for(int i=1;i<=n;i++){
            int b1 = s1.size() ? *s1.begin() - i + 1 : INF_INT;
            int b2 = s2.size() ? *s2.begin() + i - 1 : INF_INT;
            // cout << b1 << " " << b2 << "\n";
            cout << min(b1, b2) << " ";
            while(pq.size() && pq.top().first == i){
                s1.erase(s1.find(pq.top().second));
                int ct = pq.top().second - 2*pq.top().first + 2;
                s2.insert(ct);
                pq.pop();
            }
        }
        cout << "\n";
    }
}
