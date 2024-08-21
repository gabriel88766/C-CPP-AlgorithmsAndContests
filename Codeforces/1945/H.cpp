#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int M = 18;
const int N = 4e5+1;
vector<int> divs[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    for(int i=1;i<N;i++){
        for(int j=i;j<N;j+=i){
            divs[j].push_back(i);
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        vector<vector<int>> nb(M+1);
        vector<bool> out(n, true), in(n);
        for(int i=0;i<n;i++){
            cin >> a[i];
            for(int j=0;j<=M;j++){
                if(!(a[i] & (1 << j))){
                    if(nb[j].size() <= 2) nb[j].push_back(i);
                }
            }
        }
        int ma = *max_element(a.begin(), a.end());

        vector<bool> chk(M+1, false);
        for(int i=0;i<=M;i++){
            if(nb[i].size() == 0) x += 1 << i; //AND has this bit
            else if(nb[i].size() <= 2){//1 or 2 hasn't this bit, check if they are in and
                chk[i] = true; 
                for(auto el : nb[i]){
                    out[el] = false;
                    in[el] = true;
                }
            }
            //else 3 or more hasn't this bit, thus it is not in and;
        }
        //out = has all bits chk[i] = true set.
        //in = has some bits chk[i] = true not set. (at most 40 members)
        //possibilities for A and B:
        //A out B  out == smart (x is already updated. AND = 0, gcd two members greater than x)
        //A in B out == brute force ok
        //A in B in  == brute force ok
        vector<int> cnt(ma + 1, 0);
        for(int i=0;i<n;i++){
            if(!out[i]) continue;
            for(auto d : divs[a[i]]) cnt[d]++;
        }
        int md = -1;
        for(int i=1;i<=ma;i++) if(cnt[i] >= 2) md = i;
        if(md > x){
            //ok
            vector<int> a1, a2;
            for(int i=0;i<n;i++){
                if(!out[i]) a2.push_back(a[i]);
                else if(a[i] % md || a1.size() == 2) a2.push_back(a[i]);
                else a1.push_back(a[i]);
            }
            cout << "YES\n";
            cout << a1.size() << " ";
            for(auto x : a1) cout << x << " ";
            cout << "\n";
            cout << a2.size() << " ";
            for(auto x : a2) cout << x << " ";
            cout << "\n";
        }else{
            //try with in
            pair<int,int> ans = {-1, -1};
            for(int i=0;i<n;i++){
                if(ans != make_pair(-1, -1)) break;
                if(in[i]){
                    for(int j=0;j<n;j++){
                        if(i == j) continue;
                        int g = gcd(a[i], a[j]);
                        int cur = x;
                        if(g <= cur) continue;
                        int p1 = min(i, j), p2 = max(i, j);
                        for(int b=0;b<=M;b++){
                            if(chk[b]){
                                if(nb[b].size() == 1){
                                    if(nb[b][0] == p1 || nb[b][0] == p2) cur += (1 << b);
                                }else{
                                    if(nb[b][0] == p1 && nb[b][1] == p2) cur += (1 << b);
                                }
                            }
                        }
                        if(g > cur){
                            ans = {i, j};
                            break;
                        }
                    }
                }
            }
            if(ans == make_pair(-1, -1)) cout << "NO\n";
            else{
                cout << "YES\n";
                cout << 2 << " " << a[ans.first] << " " << a[ans.second] << "\n";
                cout << n-2 << " ";
                for(int i=0;i<n;i++){
                    if(ans.first != i && ans.second != i) cout << a[i] << " ";
                }
                cout << "\n";
            }
        }
    }
}
