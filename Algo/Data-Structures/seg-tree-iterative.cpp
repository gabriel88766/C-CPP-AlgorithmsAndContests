
const int N = 2e5+3;
ll st[2*N];
ll v[N];
int n; //set n

void build(){
    for(int i=n;i<2*n;i++) st[i] = v[i-n];
    for(int i=n-1;i>=1;i--) st[i] = st[2*i] + st[2*i+1]; //merge op
}

ll query(int l, int r){
    ll ans = 0; //null element
    l += n, r += n;
    while(l <= r){
        int no = l, c = 1;
        while(!(no & 1) && (r-l+1) >= (c << 1)){
            c <<= 1;
            no >>= 1;
        }
        ans += st[no]; //merge op
        l += c;
    }
    return ans;
}
void update(int l, ll val){
    l += n;
    st[l] = val;
    while(l > 1){
        l >>= 1;
        st[l] = st[2*l] + st[2*l+1]; //merge op
    }
}

