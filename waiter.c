#include <stdio.h>

float total = 0.0;
short count = 0;
short tax_percent = 6;

float add_with_tax(float f) {
  float tax_rate = 1 * tax_percent / 100.0;
  total = total + (f * tax_rate);
  count = count + 1;
  return total;
}

int main() {
  float val;
  printf("品物の値段: ");
  while (scanf("%f", &val) == 1) {
    printf("ここまでの合計: %.2f\n", add_with_tax(val));
    printf("品物の値段: ");
  }

  printf("\n最終合計: %.2f\n", total);
  printf("品物数: %hi\n", count);
  return 0;
}
