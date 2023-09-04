#include<iostream>
#include<cmath>

#define isqrt5 1.0 / sqrtl(5)  
#define phi (1 + sqrtl(5)) / 2.0

int fibArray(int n) {
  int values[n + 1];

  values[0] = 0;
  values[1] = 1;

  for (int i = 2; i <= n; ++i)
    values[i] = values[i-1] + values[i-2];

  return values[n];
}

long long fib(int n) {
  return round(pow(phi, n) * isqrt5);
}

int main (int argc, char *argv[]) {
  int n;
  std::cout << "n: ";
  std::cin >> n;

  std::cout << fib(n) << std::endl;
  return 0;
}
