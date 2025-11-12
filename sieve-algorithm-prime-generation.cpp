int mx = 1e7;
vector<bool> prime(mx+123);
void primeGeneration() {
  for (int i=3; i<=mx; i+=2) {
    prime[i] = true;
  }
  
  prime[2] = true;
  int sq = sqrt(mx);
  for (int i=3; i<=sq; i+=2) {
    if (prime[i]) {
      for (int j=i*i; j<=mx; j+=i) {
        prime[j] = false;
      }
    }
  }
}
