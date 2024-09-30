const int N = 1e5+3;   
int p[N], sz[N];
stack<pair<int,int>> rb;

void init(){
    for(int i=1;i<N;i++) {p[i] = i; sz[i] = 1;}
}

int get(int a){ //log n
    return p[a] == a ? a : get(p[a]);
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a,b);
    p[b] = a;
    sz[a] += sz[b];
    rb.push({b, a});
}

void rollback(){
    if(rb.size() == 0){
        assert(false); //?? this may be a mistake.
        return;
    }
    auto [b, a] = rb.top();
    rb.pop();
    p[b] = b;
    sz[a] -= sz[b];
}