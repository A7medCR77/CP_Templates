struct math
{
private:
   bool check_prime(ll a, ll d, ll s, ll n)
   {
      ll x = modular_exponential(a, d, n);
      if (x == 1 || x == n - 1)
         return true;

      for (int i = 1; i < s; ++i)
      {
         x = get_mul(x, x, n);
         if (x == n - 1)
            return true;
      }

      return false;
   }

public:
   math() {}
   // cmp double
   int dcmp(double x, double y)
   {
      return (fabs(x - y) <= EPS ? 0 : (x < y ? -1 : 1));
   }

   ll summation(ll first, ll last)
   {
      ll x = last - first + 1;
      return ((first + last) * x) / 2;
   }

   // get kth element in sequence increase by multiple of constant
   // 1 4 16...
   // 1 3 9...
   ll kth(ll first, ll ratio, ll k)
   {
      // ratio->the constant number
      return first * pow(ratio, k - 1);
   }

   // get ow many number between A & B Divisible by M
   ll CountDivisibles(ll A, ll B, ll M)
   {
      if (A % M == 0)
         return (B / M) - (A / M) + 1;

      return (B / M) - (A / M);
   }

   // get summation of geometry sequence increase by multiple of constant
   // 1 4 16...
   // 1 3 9...
   ll geometry_summation(ll first, ll ratio, int number_of_element)
   {
      return ((first * (1 - pow(ratio, number_of_element))) / (1 - ratio));
   }

   // get num of odd numbers between l & r
   ll num_of_odd(ll l, ll r)
   {
      return (r - l + 1) - (r / 2 - (l - 1) / 2);
   }

   ll get_mul(ll a, ll b, ll mod = 1000000007)
   {
      ll res = 0;

      while (b)
      {
         if (b & 1)
            res = ((res % mod) + (a % mod)) % mod;
         a = ((a % mod) * 2) % mod;
         b /= 2;
      }

      return res % mod;
   }

   ll binary_exponential(ll a, ll b)
   {
      ll res = 1;

      while (b)
      {
         if (b & 1)
            res *= a;
         a *= a;
         b /= 2;
      }

      return res;
   }

   ll modular_exponential(ll a, ll b, ll mod = 1000000007)
   {
      ll res = 1;

      while (b)
      {
         if (b & 1)
            res = get_mul(res, a, mod);
         a = get_mul(a, a, mod);
         b /= 2;
      }

      return res % mod;
   }

   ll mod_inv(ll x)
   {
      return modular_exponential(x, MOD - 2);
   }

   vector<ll> divisors(ll n)
   {
      vector<ll> ans;

      for (int i = 1; i * i <= n; ++i)
      {
         if (n % i == 0)
         {
            ans.eb(i);
            if (i != n / i)
               ans.eb(n / i);
         }
      }

      sort(all(ans));

      return ans;
   }

   vector<pair<ll, ll>> prime_factorization(ll n)
   {
      vector<pair<ll, ll>> ans;

      ll cnt = 0;

      while (n % 2 == 0)
         cnt++, n /= 2;

      if (cnt > 0)
         ans.pb({2, cnt});

      for (int i = 3; i * i <= n; i += 2)
      {
         cnt = 0;
         if (n % i == 0)
         {
            while (n % i == 0)
               cnt++, n /= i;

            ans.pb({i, cnt});
         }
      }

      if (n != 1)
         ans.pb({n, 1});

      return ans;
   }

   ll GCD(ll a, ll b)
   {
      return (!b ? a : GCD(b, a % b));
   }

   ll LCM(ll a, ll b)
   {
      return a / GCD(a, b) * b;
   }

   int Extended_Euclidean(int a, int b, int &x, int &y)
   {
      if (b == 0)
      {
         x = 1;
         y = 0;
         return a;
      }

      int x1, y1;
      int d = Extended_Euclidean(b, a % b, x1, y1);
      x = y1;
      y = x1 - y1 * (a / b);
      return d;
   }

   int reverse_summation(ll n)
   {
      ll a = (-1 + (ll)sqrtl(1 + 8 * n)) / 2;
      ll z = summation(1, a);
      return (n == z ? a : -1);
   }

   // if p is prime number then (a^(p-1))%p==1
   // a is a random number in range 0<a<p

   bool Fermat_Primality_Testing(ll p, ll k) // will take k random number to check
   {
      if (p <= 4)
         return (p == 2 || p == 3);
      for (int i = 0; i < k; ++i)
      {
         ll y = (rand() % ((p - 2) - 2 + 1)) + 2; // will make rand function get random value in range 2 to p-2
         ll x = modular_exponential(y, p - 1, p);
         if (x != 1)
            return false;
      }
      return true;
   }

   // check if n is prime (even n is a big number)
   // rand^d%n==1
   // rand^((2^s)*d)%n==1
   bool Miller_Rabin(ll n, ll step = 1000)
   {
      if (n <= 4)
         return n == 2 || n == 3;

      ll d = n - 1;
      ll s = 0;
      while (!(d & 1))
      {
         d >>= 1;
         s++;
      }

      for (int i = 1; i <= step; ++i)
      {
         ll a = (rand() % ((n - 2) - 2 + 1)) + 2;
         if (!check_prime(a, d, s, n))
            return false;
      }

      return true;
   }

   // Euler Totient = phi(a)
   // get how many numbers less than n with gcd =1 with n
   // a = p1^a * p2^b * p3^c * .... -> prime factorization
   // phi(a) = phi(p1^a) * phi(p2^b) * phi(p3^c) * ....
   // phi(p^a)= p^a - p^(a-1)
   // phi(a) = (p1^a - p1^(a-1)) * (p2^b - p2^(b-1)) * (p3^c - p3^(c-1)) * ....
   // phi(a) = p1^a * (1 - p1^(-1)) * p2^b * (1 - p2^(-1)) * p3^c * (1 - p3^(-1)) * ....
   // phi(a) = p1^a * p2^b * p3^c * ..... * (1 - p1^(-1)) * (1 - p2^(-1)) * (1 - p3^(-1)) * ....
   // phi(a) = a * (1 - p1^(-1)) * (1 - p2^(-1)) * (1 - p3^(-1)) * ....

   // Time Complexity O(sqrt(n))

   ll phi(ll a)
   {
      vector<pair<ll, ll>> vec = prime_factorization(a);
      double ans = a;
      for (auto &[l, r] : vec)
         ans *= (1.0 - (1.0 / double(l)));

      return (ll)ans;
   }

   // Time Complexity O(n*log(log(n)))

   vector<int> phi_0_to_n(int n)
   {
      vector<int> phi(n + 1);
      for (int i = 0; i <= n; i++)
         phi[i] = i;

      for (int i = 2; i <= n; i++)
      {
         if (phi[i] == i)
         {
            for (int j = i; j <= n; j += i)
               phi[j] -= phi[j] / i;
         }
      }

      return phi;
   }
   // get summation for sequence that increases in a constant number
   // 2 4 6 ....
   // 1 4 7 ....
   ll arithmetic_progression(ll n, ll a, ll d)
   {
      // n->is the number of terms in the series
      // a->is the first term of the series
      // d->is the common difference between the terms
      int last = last_term_in_arithmetic_progression(n, a, d);
      return n * (a + last) / 2;
   }

   ll last_term_in_arithmetic_progression(ll n, ll a, ll d)
   {
      return a + (n - 1) * d;
   }

   // get double distance between two points
   double Euclidean_Distance(int x1, int y1, int x2, int y2)
   {
      double x = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
      return x;
   }

   ll num_of_divisors(ll n)
   {
      ll div = 0;

      for (int i = 1; i * i <= n; ++i)
      {
         if (n % i == 0)
         {
            div++;
            if (i != n / i)
               div++;
         }
      }

      return div;
   }

   double slope(double x1, double y1, double x2, double y2)
   {
      if (x1 - x2 == 0)
         return -OO;

      return (y2 - y1) / (x2 - x1);
   }
};
