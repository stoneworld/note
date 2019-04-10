#include <stdio.h>

int main(void) {
  int n;
  char c;
  n = 15;
  c = '-';
  if (n <= 0 || !(n % 2)) printf("error");
  int middle,cnt;
  middle = n / 2 + 1;
  for (int i = 1; i <= n; i++) {
    cnt = (i - 1) * 2 + 1;
    if (i > middle) {
      cnt = (n - i) * 2 + 1;
    }
    for(int j = 0; j < (n-cnt)/2; j++) {
      printf("\t");
    }
    for (int m = 0; m < cnt; m++ ) {
      printf("%c\t", c);
    }
    printf("\n");
  }
  return 0;
}
