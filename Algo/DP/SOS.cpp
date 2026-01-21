//general: https://codeforces.com/blog/entry/119082
//g[a] = sum f[b] zeta(b, a);
//zeta(b, a) = 1 if b <= a, 0 otherwise.
template<typename T>
void SubsetZetaTransform(vector<T>& v) {
	const int n = v.size(); // n must be a power of 2
	for (int j = 1; j < n; j <<= 1) {
		for (int i = 0; i < n; i++)
			if (i & j) v[i] += v[i ^ j]; //invert if superset to v[i ^ j] += v[i];
	}
}
//f[a] = sum g[b] mi(b, a);
//mi(b, a) = (-1)^|a-b| (if b <= a)
template<typename T>
void SubsetMobiusTransform(vector<T>& v) {
	const int n = v.size(); // n must be a power of 2
	for (int j = 1; j < n; j <<= 1) {
		for (int i = 0; i < n; i++)
			if (i & j) v[i] -= v[i ^ j]; //invert if superset to v[i ^ j] -= v[i];
	}
}

template<typename T>
void SupersetZetaTransform(vector<T>& v) {
	const int n = v.size(); // n must be a power of 2
	for (int j = 1; j < n; j <<= 1) {
		for (int i = 0; i < n; i++)
			if (i & j) v[i ^ j] += v[i]; 
	}
}

template<typename T>
void SupersetMobiusTransform(vector<T>& v) {
	const int n = v.size(); // n must be a power of 2
	for (int j = 1; j < n; j <<= 1) {
		for (int i = 0; i < n; i++)
			if (i & j) v[i ^ j] -= v[i]; 
	}
}

//FOR DIVISORS, MULTIPLES
vector<ll> pr;
void sieve(int n){
    vector<bool> p(n+1, false);
    pr.clear();
    for(ll i=2; i<=n; i++){
        if(!p[i]){
            for(ll j = i*i; j <= n; j += i){
                p[j] = 1; //marking all multiples of i as not prime
            }
            pr.push_back(i);
        }
    }
}

//this is slighly different because any prime can appear multiple times
//then zeta must be in increasing and mobius in decreasing order.
template<typename T>
void DivisorZetaTransform(vector<T>& v) {
	const int n = (int)v.size() - 1;
    sieve(n);
	for (auto p : pr) {
		for (int i = 1; i * p <= n; i++)
			v[i * p] += v[i];
	}
}

template<typename T>
void DivisorMobiusTransform(vector<T>& v) {
	const int n = (int)v.size() - 1;
    sieve(n);
	for (auto p : pr) {
		for (int i = n / p; i; i--)
			v[i * p] -= v[i];
	}
}

//multiple is inverse and also invert order.
template<typename T>
void MultipleZetaTransform(vector<T>& v) {
	const int n = (int)v.size() - 1;
    sieve(n);
	for (auto p : pr) {
		for (int i = n / p; i; i--)
			v[i] += v[i * p];
	}
}

template<typename T>
void MultipleMobiusTransform(vector<T>& v) {
	const int n = (int)v.size() - 1;
    sieve(n);
	for (auto p : pr) {
		for (int i = 1; i * p <= n; i++)
			v[i] -= v[i * p];
	}
}

//CONVOLUTIONS:
template<typename T>
vector<T> AndConvolution(vector<T> A, vector<T> B) {
	SupersetZetaTransform(A);
	SupersetZetaTransform(B);
	for (int i = 0; i < A.size(); i++) A[i] *= B[i];
	SupersetMobiusTransform(A);
	return A;
}

template<typename T>
vector<T> OrConvolution(vector<T> A, vector<T> B) {
	SubsetZetaTransform(A);
	SubsetZetaTransform(B);
	for (int i = 0; i < A.size(); i++) A[i] *= B[i];
	SubsetMobiusTransform(A);
	return A;
}

template<typename T>
vector<T> GCDConvolution(vector<T> A, vector<T> B) {
    MultipleZetaTransform(A);
    MultipleZetaTransform(B);
    for (int i = 0; i < A.size(); i++) A[i] *= B[i];
    MultipleMobiusTransform(A);
    return A;
}

template<typename T>
vector<T> LCMConvolution(vector<T> A, vector<T> B) {
    DivisorZetaTransform(A);
    DivisorZetaTransform(B);
    for (int i = 0; i < A.size(); i++) A[i] *= B[i];
    DivisorMobiusTransform(A);
    return A;
}


//SUBSET CONV
const int N = 20
ll fhat[N+1][1 << N];
ll ghat[N+1][1 << N];
ll h[N+1][1 << N];
void SubsetConvolution(ll *f, ll *g){
	for(int mask = 0; mask < (1 << N); mask++) {
		fhat[__builtin_popcount(mask)][mask] = f[mask];
		ghat[__builtin_popcount(mask)][mask] = g[mask];
	}

	// Apply zeta transform on fhat[][] and ghat[][]
	for(int i = 0; i <= N; i++) {
		for(int j = 0; j < N; j++) {
			for(int mask = 0; mask < (1 << N); mask++) {
				if((mask & (1 << j)) != 0) {
					fhat[i][mask] += fhat[i][mask ^ (1 << j)];
					ghat[i][mask] += ghat[i][mask ^ (1 << j)];
				}
			}
		}
	}

	// Do the convolution and store into h[][] = {0}
	for(int mask = 0; mask < (1 << N); mask++) {
		for(int i = 0; i <= N; i++) {
			for(int j = 0; j <= i; j++) {
				h[i][mask] += fhat[j][mask] * ghat[i - j][mask];
			} 
		}
	}

	// Apply inverse SOS dp on h[][]
	for(int i = 0; i <= N; i++) {
		for(int j = 0; j < N; j++) {
			for(int mask = 0; mask < (1 << N); mask++) {
				if((mask & (1 << j)) != 0) {
					h[i][mask] -= h[i][mask ^ (1 << j)];
				}
			}
		}
	}
	for(int mask = 0; mask < (1 << N); mask++)  f[mask] = h[__builtin_popcount(mask)][mask];
}