#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int n;
vector<int> deck;
vector<vector<int>> ans;
bool checkrev(vector<int> &d = deck){
    for(int i=0;i<n;i++){
        if(d[i] != n-i) return false;
    }
    return true;
}
bool checkok(){
    auto v = deck;
    reverse(v.begin(), v.end());
    return checkrev(v);
}

void change(vector<int> &v){
    vector<vector<int>> aux(v.size());
    int p = 0;
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i];j++){
            aux[i].push_back(deck[p++]);
        }
    }
    reverse(aux.begin(), aux.end());
    p = 0;
    for(int i=0;i<v.size();i++){
        for(int j=0;j<aux[i].size();j++){
            deck[p++] = aux[i][j];
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> n;
    deck.resize(n);
    for(int i=0;i<n;i++) cin >> deck[i];
    while(!checkok()){
        vector<int> v;
        if(deck[0] == n || deck.back() == n){
            //opt1
            bool rev = false;
            if(deck.back() == n){
                reverse(deck.begin(), deck.end());
                rev = true;
            }
            if(checkrev()){
                for(int i=1;i<=n;i++) v.push_back(1);
            }else{
                int p = 0, ind;
                while(deck[p] == n-p) p++;
                for(int i=0;i<p;i++) v.push_back(1);
                for(int i=p;i<n;i++) if(deck[i] == (n-p)) ind = i;
                v.push_back(ind - p + 1);
                if(n-ind-1) v.push_back(n-ind-1);
            }
            if(rev){ 
                reverse(deck.begin(), deck.end());
                reverse(v.begin(), v.end());
            }
        }else{
            //init
            int ind;
            for(int i=0;i<n;i++) if(deck[i] == n) ind = i;
            v.push_back(ind);
            v.push_back(n-ind);
        }
        change(v);
        ans.push_back(v);
    }
    cout << ans.size() << "\n";
    for(int i=0;i<ans.size();i++){
        cout << ans[i].size() << " ";
        for(auto x : ans[i] ) cout << x << " ";
        cout << "\n";
    }
}
