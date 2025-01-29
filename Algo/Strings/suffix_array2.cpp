//BASED ON Linear Suffix Array Construction by Almost Pure Induced-Sorting 
//Ge Nong, Sen Zhang Wai, Hong Chan
//NEED TO IMPROVE TO REAL O(n), but this O(n log n) is fast, anyway.
const int N = 1e6+5; 
int n;
int hd[N], adv[N];

vector<int> induced_sort(vector<int> &v, vector<bool> &type){
    int n = v.size();
    vector<int> sc;
    for(int i=1;i<n;i++){
        if(type[i] == 1 && type[i-1] == 0){
            sc.push_back(i);
        }
    }
    int c = *max_element(v.begin(), v.end());
    assert(c < N);
    vector<int> gs;
    assert(sc.size() > 0);
    if(sc.size() != 1){
        vector<bool> ntp(sc.size());
        vector<int> nv(sc.size());

        vector<pair<vector<int>, int>> vx;
        for(int i=0;i<sc.size();i++){
            if(i == sc.size() - 1){
                vx.push_back({{0}, i});
            }else{
                vector<int> vn;
                for(int j=sc[i];j<=sc[i+1];j++) vn.push_back(v[j]);
                vn.push_back(c+1);
                vx.push_back({vn, i});
            }
        }
        sort(vx.begin(), vx.end());
        int p = -1;
        for(int i=0;i<sc.size();i++){
            if(i == 0 || vx[i].first != vx[i-1].first){
                nv[vx[i].second] = ++p;
            }else{
                nv[vx[i].second] = p;
            }
        }
        
        ntp.back() = 1;
        for(int i=nv.size()-1;i>=1;i--){
            if(nv[i-1] != nv[i]){
                if(nv[i-1] < nv[i]) ntp[i-1] = 1;
                else ntp[i-1] = 0;
            }else ntp[i-1] = ntp[i];
        }

        /*vector<int> val(c+1, 0);
        for(auto &x : sc) val[v[x]] = 1;
        int p = 0;
        for(int i=0;i<=c;i++){
            if(val[i]) val[i] = p++;
        }
        for(int i=sc.size() - 1;i>=0;i--){
            if(i == sc.size() - 1) ntp[i] = 1;
            else{
                int p1 = sc[i], p2 = sc[i+1];
                while(true){
                    assert(p1 < v.size() && p2 < v.size());
                    if(v[p1] != v[p2]){
                        if(v[p1] < v[p2]) ntp[i] = 1;
                        else ntp[i] = 0;
                        break;
                    }else if(type[p1] != type[p2]){
                        
                        if(type[p1] == 1) ntp[i] = 0;
                        else ntp[i] = 1;
                        break;
                    }else{
                        assert(i+2 < sc.size());
                        if(p1 == sc[i+1] || p2 == sc[i+2]){
                            assert(p1 == sc[i+1] && p2 == sc[i+2]);
                            ntp[i] = ntp[i+1];
                            break;
                        }else p1++, p2++;
                    }
                }
            }
            nv[i] = val[v[sc[i]]];
        }*/
        gs = induced_sort(nv, ntp);
    }else{
        gs.push_back(0);
    }
    // gs = {3, 2, 1, 0};
    vector<int> sa(v.size(), -1);
    
    fill(hd, hd + c + 2, 0);
    fill(adv, adv + c + 2, 0); //advance of head
    for(int i=0;i<n;i++){
        hd[v[i] + 1]++;
    }
    for(int i=1;i<=(c+1);i++) hd[i] += hd[i-1];
    assert(hd[c+1] == v.size());
    vector<int> ax(gs.size());
    for(int i=0;i<gs.size();i++) ax[gs[i]] = i;
    for(auto &x : sc){
        adv[v[x]]++;
    }
    // priority_queue<int> pq;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0;i<gs.size();i++){
        auto &y = sc[gs[i]];
        int pl = hd[v[y] + 1] - adv[v[y]]--;
        pq.push(pl);
        sa[pl] = y;
    }
    while(pq.size()){
        auto i = pq.top();
        pq.pop();
        if(sa[i] > 0){
            if(type[sa[i]-1] == 0){
                int pl = hd[v[sa[i] - 1]] + adv[v[sa[i] - 1]]++;
                sa[pl] = sa[i] - 1;
                pq.push(pl);
            }
        }
    }
    // for(int i=0;i<sa.size();i++){
        // if(sa[i] > 0){
            // if(type[sa[i]-1] == 0){
                // sa[hd[v[sa[i] - 1]] + adv[v[sa[i] - 1]]++] = sa[i] - 1;
            // }
        // }
    // }
    fill(adv, adv + c + 2, 0);
    priority_queue<int> pqq;
    for(int i=0;i<n;i++){
        int j = sa[i];
        if(j > 0 && type[j] == 0) {pqq.push(i);}
    }
    while(pqq.size()){
        auto i = pqq.top();
        pqq.pop();
        if(sa[i] == 0) continue;
        if(type[sa[i] - 1] != 1) continue;
        int pl = hd[v[sa[i] - 1] + 1] - 1 - adv[v[sa[i] - 1]]++;
        sa[pl] = sa[i] - 1;
        pqq.push(pl);
    }
    // for(int i=sa.size()-1;i>=0;i--){
        // if(type[sa[i] - 1] == 1){
            // sa[hd[v[sa[i] - 1] + 1] - 1 - adv[v[sa[i] - 1]]++] = sa[i] - 1;
        // }
    // }
    return sa;
}

vector<int> suffix_array(vector<int> &v){
    n = v.size();
    vector<bool> type(n);
    type[n-1] = 1;
    for(int i=n-2;i>=0;i--){
        if(v[i] > v[i+1]) type[i] = 0;//large
        else if(v[i] < v[i+1]) type[i] = 1;//small
        else type[i] = type[i+1]; //?!
    }
    return induced_sort(v, type);
}
vector<int> suffix_array(string &s){
    int n = s.size();
    vector<int> cv(n);
    vector<bool> is(26, false); // what is the alphabet? lowercase latin letters?
    for(int i=0;i<n;i++) is[s[i]-'a'] = true;
    vector<int> val(26, -1);
    int p = 0;
    for(int i=0;i<26;i++){
        if(is[i]) val[i] = ++p;
    }
    for(int i=0;i<n;i++) cv[i] = val[s[i]-'a'];
    cv.push_back(0); //lower than anything?!
    return suffix_array(cv);
}