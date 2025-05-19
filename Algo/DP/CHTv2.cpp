//Using Li Chao Tree..
struct Line{
    ll a, b;//make int128 if needed ax+b;
    Line(){
        this->a = INF_INT; //inf to min, -inf to max 
        this->b = INF_INT; 
    }
    Line(ll a, ll b){
        this->a = a; 
        this->b = b; 
    }
    ll get(ll x){
        return a*x + b;
    }
};

const int N = 4e5+3; //must be greater than cds
//if compression of coordinates
vector<ll> cds;
int get_pos(ll value){
    return lower_bound(cds.begin(), cds.end(), value) - cds.begin();
}
int n; //n must be cds.size()
Line st[4*N];
//max or min...
void add(Line nl, int p = 1, int l = 0, int r = n-1){
    int m = (l + r)/2;
    bool lwl = nl.get(cds[l]) < st[p].get(cds[l]); //change to > if max
    bool lwm = nl.get(cds[m]) < st[p].get(cds[m]); //change to > if max
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


ll get(int pos, int p = 1, int l = 0, int r = n-1){
    int m = (l + r)/2;
    if(l == r) return st[p].get(cds[pos]);  
    else if(pos <= m) return min(st[p].get(cds[pos]), get(pos, 2*p, l, m)); //change to max
    else return min(st[p].get(cds[pos]), get(pos, 2*p+1, m+1, r)); //change to max
}

//RANGE UPDATES: O(log^2 n)

void add(Line nl, int i, int j, int p = 1, int l = 0, int r = n-1){
    int m = (l + r)/2;
    if(i > r || j < l) return;
    if(i <= l && r <= j){
        bool lwl = nl.get(cds[l]) < st[p].get(cds[l]); //change to > if max
        bool lwm = nl.get(cds[m]) < st[p].get(cds[m]); //change to > if max
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
