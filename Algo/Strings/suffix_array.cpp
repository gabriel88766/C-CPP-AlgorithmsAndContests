//lexicography order of all suffixes.
const int N = 2e5+3; 
int n, c;
// n log n
int cnt[N], aux[N], mp2[256];
pair<int, int> cs[N];
vector<int> suffix_array(string &s){
    s += "$";
    n = s.size(), c=-1;
    vector<int> mp(n);

    for(int i=0;i<n;i++) cnt[s[i]]++;
    for(int i=0;i<256;i++){
        if(cnt[i]) mp2[i] = ++c;
        if(i) cnt[i] += cnt[i-1];
    } 
    for(int i=0;i<n;i++) mp[--cnt[s[i]]] = i; 
    for(int i=0;i<n;i++) cs[i].first = mp2[s[i]];

    for(int i=0;(1 << i) < n;i++){
        fill(cnt, cnt + c + 2, 0);
        int offset = 1 << i;
        for(int j=0;j<n;j++){
            int mindex = (j + offset) >= n ? j + offset - n : j + offset;
            cs[j].second = cs[mindex].first;
            cnt[cs[j].second + 1]++;
        }
        //begin raddix_sort of pair O(n)
        for(int j=2; j<=(c+1); j++) cnt[j] += cnt[j-1];
        for(int j=0; j<n; j++) aux[cnt[cs[j].second]++] = j;
        fill(cnt, cnt + c + 2, 0);
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
//longest common prefix in O(n), between 2 consecutive indexes of suffix array
vector<int> lcp(string &s, vector<int> &sa){
    vector<int> ans(n - 1, 0);
    vector<int> invmp(n, 0);
    for(int i=0;i<n; i++) {invmp[sa[i]] = i;}
    int cnt = 0;
    for(int i=0;i < (n-1); i++){
        if(invmp[i] == (n-1)){
            cnt = 0;
            continue;
        }
        int j = sa[invmp[i] + 1];
        while (s[i+cnt] == s[j+cnt]) cnt++;
        ans[invmp[i]] = cnt;
        if (cnt) cnt--;
    }
    return ans;
}

//for suffix array, 1 => 2, 2 => 4 ...



//lcp, iterate in order of length.
//evaluate pos(i), j = pos(i) + 1  equals k => pos(i+1) and pos(j+1) equals k-1 
//and so between pos(i+1) and pos(i+1) + 1 at least k-1 
//so its not necessary to make k = 0