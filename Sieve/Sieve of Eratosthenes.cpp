#include <bits/stdc++.h>
#define ll long long
#define sz(s) s.size()
#define nl '\n'
using namespace std;
template <typename T = int>
istream &operator>>(istream &in, vector<T> &v)
{
    for (auto &x : v)
        in >> x;
    return in;
}

template <typename T = int>
ostream &operator<<(ostream &out, const vector<T> &v)
{
    for (const T &x : v)
        out << x << " ";
    return out;
}


// time complexity n log(log(n))

template <typename T = int>
struct sieve
{
   vector<bool> is_prime;
   vector<T> primes;
   int n;

   sieve(int n)
   {
      this->n = n;
      is_prime.assign(n + 5, 1);
      is_prime[0] = is_prime[1] = false;

      for (int i = 2; i * i <= n; ++i)
      {
         if (is_prime[i])
         {
            for (int l = i * i; l <= n; l += i)
            {
               is_prime[l] = false;
            }
         }
      }
   }

   vector<bool> GetBooleanArray()
   {
      return is_prime;
   }

   vector<T> get_primes()
   {
      for (int i = 1; i <= n; ++i)
         if (is_prime[i])
            primes.push_back(i);

      return primes;
   }
};

void solve()
{
}

int main()
{
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
