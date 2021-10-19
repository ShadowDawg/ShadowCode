ll pow_mod(ll x, ll y, ll p) {
    ll res = 1;     
    x = x % p; 
    if (x == 0) return 0; 
    while (y > 0) {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

ll mod_inverse (ll a,ll m) {   // m must be prime
	return pow_mod(a,m - 2,m);
}

ll factorial_mod (int n,ll m) { // O(n) time
	ll cur = 1;
	for (int i = 1;i <= n;++i) {
		cur = ((cur % m) * (i * 1LL % m)) % m;
	}
	return cur;
}

ll ncr (int n,int r,ll m) {
	// NOTE: precompute factorials & inverses for multiple testcases / iterations
	if (r < 0 || r > n)
		return 0;
	return (((factorial_mod(n,m) * mod_inverse(factorial_mod(n - r,m),m)) % MOD)
			* mod_inverse(factorial_mod(r,m),m)) % MOD;
}

ll npr (int n,int r,ll m) {
	// NOTE: precompute factorials & inverses for multiple testcases / iterations
	if (r < 0 || r > n)
		return 0;
	return (factorial_mod(n,m) * mod_inverse(factorial_mod(n - r,m),m)) % MOD;
}
