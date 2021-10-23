const int N = 10000001;
vector <bool> is_prime(N,true);
int spf[N] = {0};   // smallest prime factor
vector <int> primes;

void sieve () {
	is_prime[0] = is_prime[1] = false;
	spf[1] = 1;
	for (int i = 2;i < N;++i) {
		if (is_prime[i]) {
			spf[i] = i;
			primes.pb(i);
		}
		for (int j = 0;j < (int)primes.size() && primes[j] <= spf[i] && i * primes[j] < N;++j) {
			is_prime[ i * primes[j] ] = false;
			spf[ i * primes[j] ] = primes[j];
		}
	}
}
