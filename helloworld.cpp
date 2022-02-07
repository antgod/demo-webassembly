#include <iostream>

int factorial(int n) {
  // std::cout << n << std::endl;
  if (n == 0) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}

int main(int n, char *argv[]) {
  return factorial(n);
}
