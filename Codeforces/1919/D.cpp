    #include <bits/stdc++.h>
    typedef long long int ll;
    typedef unsigned long long int ull;
    const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
    const int INF_INT = 0x3f3f3f3f;
    const long double PI = acosl(-1.), EPS = 1e-9; 
    using namespace std;

    struct LinkedList{
        int next, prev;
        int val;
    };
    //cout << fixed << setprecision(6)
    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        //freopen("in", "r", stdin); //test input
        int t;
        cin >> t;
        while(t--){
            int n;
            cin >> n;
            vector<LinkedList> v(n);
            set<pair<int,int>> st;
            int cnt0 = 0;
            for(int i=0;i<n;i++){
                cin >> v[i].val;
                if(v[i].val == 0) cnt0++;
                if(i != 0) v[i].prev = i-1;
                else v[i].prev = -1;
                if(i != (n-1)) v[i].next = i+1;
                else v[i].next = -1;
                st.insert({v[i].val, i});
            }
            if(cnt0 != 1){
                cout << "NO\n";
                continue;
            }
            while(st.size() != 1){
                int gr = prev(st.end())->second;
                bool ok = false;
                if(v[gr].prev != -1 && abs(v[v[gr].prev].val - v[gr].val) <= 1) ok = true;
                if(v[gr].next != -1 && abs(v[v[gr].next].val - v[gr].val) <= 1) ok = true;
                if(!ok) break;
                int x1 = v[gr].next;
                int x2 = v[gr].prev;
                if(x1 != -1){
                    v[x1].prev = x2;
                }
                if(x2 != -1){
                    v[x2].next = x1;
                }
                st.erase(prev(st.end()));
            }
            if(st.size() == 1) cout << "YES\n";
            else cout << "NO\n";
        }
    }
