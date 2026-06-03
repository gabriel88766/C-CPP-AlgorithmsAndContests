struct Line{
    ll a, b;
    Line() : a(0), b(0) {}
    Line(ll a, ll b){
        this->a = a; 
        this->b = b; 
    }
    ll get(ll x){
        return a*x + b;
    }
};

template<bool isMax>
struct LiChaoTree{
    vector<ll> dom;
    vector<Line> st;
    int n;
    bool cpx(ll a, ll b){
        if constexpr(isMax){
            return a > b;
        }else{
            return a < b;
        }
    }
    ll gx(ll a, ll b){
        if constexpr(isMax){
            return std::max(a, b);
        }else{
            return std::min(a, b);
        }
    }
    LiChaoTree(vector<ll> domain){
        Line lx(0,0);
        if(isMax){
            lx = Line(0, -INF_LL);
        }else{
            lx = Line(0, INF_LL);
        }
        dom = domain;
        sort(dom.begin(), dom.end());
        dom.resize(unique(dom.begin(), dom.end()) - dom.begin());
        n = dom.size();
        st.assign(4 * n, lx);
    }
    void add(Line nl, int p, int l, int r){
        int m = (l + r)/2;
        bool lwl = cpx(nl.get(dom[l]), st[p].get(dom[l])); 
        bool lwm = cpx(nl.get(dom[m]), st[p].get(dom[m])); 
        if(lwm){
            swap(nl, st[p]); //nl is better
        }
        if(l == r) return;
        if(lwl == lwm){
            add(nl, 2*p+1, m+1, r);
        }else{
            add(nl, 2*p, l, m);
        }
    }
    void add(Line nl){
        add(nl, 1, 0, n-1);
    }
    ll get(int pos, int p, int l, int r){
        int m = (l + r)/2;
        if(l == r) return st[p].get(dom[pos]);  
        else if(pos <= m) return gx(st[p].get(dom[pos]), get(pos, 2*p, l, m)); 
        else return gx(st[p].get(dom[pos]), get(pos, 2*p+1, m+1, r));
    }
    ll get(int pos){
        return get(pos, 1, 0, n-1);
    }
    //RANGE UPDATES: O(log^2 n)
    void add(Line nl, int i, int j, int p, int l, int r){
        int m = (l + r)/2;
        if(i > r || j < l) return;
        if(i <= l && r <= j){
            bool lwl = cpx(nl.get(dom[l]), st[p].get(dom[l])); 
            bool lwm = cpx(nl.get(dom[m]), st[p].get(dom[m])); 
            if(lwm){
                swap(nl, st[p]); //nl is better
            }
            if(l == r) return;
            if(lwl == lwm){
                add(nl, i, j, 2*p+1, m+1, r);
            }else{
                add(nl, i, j, 2*p, l, m);
            }
        }else{
            add(nl, i, j, 2*p+1, m+1, r);
            add(nl, i, j, 2*p, l, m);
        }
    }
    void addrange(Line nl, int i, int j){
        add(nl, i, j, 1, 0, n-1);
    }
    Line getLine(int pos, int p, int l, int r){
        int m = (l + r)/2;
        if(l == r) return st[p];  
        else if(pos <= m){
            Line l1 = getLine(pos, 2*p, l, m);
            Line l2 = st[p];
            return cpx(l1.get(dom[pos]), l2.get(dom[pos])) ? l1 : l2;
        }else{
            Line l1 = getLine(pos, 2*p+1, m+1, r);
            Line l2 = st[p];
            return cpx(l1.get(dom[pos]), l2.get(dom[pos])) ? l1 : l2;
        }
    }
    Line getLine(int pos){
        return getLine(pos, 1, 0, n-1);
    }
};