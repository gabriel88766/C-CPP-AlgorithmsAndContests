#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;

//mp maps current position to original index, c is the class of the prefix

const int N = 3e5+3; 
int  n, c;

vector<int> suffix_array(string &s){
    s += "$";
    n = s.size(), c=-1;
    vector<int> mp(n), cnt(max(n+1, 256)), mp2(256), aux(n); 
    vector<pair<int,int>> cs(n); // class,class <int,int>

    for(int i=0;i<n;i++) cnt[s[i]]++;
    for(int i=0;i<256;i++){
        if(cnt[i]) mp2[i] = ++c;
        if(i) cnt[i] += cnt[i-1];
    } 
    for(int i=0;i<n;i++) mp[--cnt[s[i]]] = i; 
    for(int i=0;i<n;i++) cs[i].first = mp2[s[i]];

    for(int i=0;(1 << i) < n;i++){
        fill(cnt.begin(), cnt.begin() + c + 2, 0);
        int offset = 1 << i;
        for(int j=0;j<n;j++){
            int mindex = (j + offset) >= n ? j + offset - n : j + offset;
            cs[j].second = cs[mindex].first;
            cnt[cs[j].second + 1]++;
        }
        //begin raddix_sort of pair
        for(int j=2; j<=(c+1); j++) cnt[j] += cnt[j-1];
        for(int j=0; j<n; j++) aux[cnt[cs[j].second]++] = j;
        fill(cnt.begin(), cnt.begin() + c + 2, 0);
        for(int j=0; j<n; j++) cnt[cs[j].first+1]++; 
        for(int j=2; j<=(c+1); j++) cnt[j] += cnt[j-1];
        for(int j=0; j<n;j++) mp[cnt[cs[aux[j]].first]++] = aux[j]; 
        //end raddix_sort
        aux[mp[0]] = c = 0;
        for(int j=1;j<n;j++){
            if(cs[mp[j]] == cs[mp[j-1]]) aux[mp[j]] = c;
            else aux[mp[j]] = ++c;
        }
        for(int j=0;j<n;j++) cs[j].first = aux[j];
    }
    return mp;
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    string s;
    int q;
    cin >> s >> q;
    vector<int> ind = suffix_array(s);
    while(q--){
        string t;
        cin >> t;
        int ans = 0;
        //code
        if(t.size() > (n-1)){cout <<   "0\n"; continue;}
        int lower = 0, upper = n;
        for(int k = n/2; k >= 1; k /= 2){
            while((lower + k) < n){ //strcmp 
                int val = t.compare(s.substr(ind[lower+k], t.size()));
                if(val > 0) lower += k;
                else break;
            }
            while((upper - k) >= 0){
                int val = t.compare(s.substr(ind[upper-k], t.size()));
                if(val < 0) upper -= k;
                else break;
            }
        }
        lower++, upper--;
        int val;
        if(lower < n && ind[lower] < n) val = t.compare(s.substr(ind[lower], t.size())) ;
        else val = -1;
        if(!val) ans = upper - lower + 1;   
        cout << ans << "\n";
    }
    
}
