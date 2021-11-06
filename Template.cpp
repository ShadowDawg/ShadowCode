<snippet>
	<content><![CDATA[
#include<bits/stdc++.h>
#define ll long long int
#define pb(x) push_back(x)
#define MOD 1000000007
#define all(x) x.begin(),x.end()
#define mp(x,y) make_pair(x,y)
using namespace std;

ll gcd (ll a,ll b) {
	if (a == 0)
		return b;
	return gcd(b % a,a);
}

ll lcm (ll a,ll b) {
	return (a * b) / gcd(a,b);
}

ll digit_sum (ll n) {
	ll sum{};
	while (n > 0) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

bool is_prime (ll n) {
	bool p{true};
	for (ll i{2};i * i <= n;++i) {
		if (n % i == 0) {
			p = false;
			break;
		}
	}
	return p;
}

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


void shadow () {
	
	int tt{1};
	cin >> tt;
	while (tt--) {
        
		
        
        
	}

}



int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
#endif


	shadow();


	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
	return 0;	
}
]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	 <tabTrigger>basic</tabTrigger>
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<!-- <scope>source.python</scope> -->
</snippet>
