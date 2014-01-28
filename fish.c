#include <stdio.h>

struct fish {
  const char *name;
  const char *species;
  int teeth;
  int age;
};

void catalog(struct fish f) {
  printf("%sは%sであり、歯は%i本あります。年齢は%i才です。\n",
      f.name, f.species, f.teeth, f.age);
}

void label(struct fish f) {
  printf("名前:%s\n種類:%s\n%i本の歯,%i才\n",
      f.name, f.species, f.teeth, f.age);
}

int main() {

  struct fish snappy = {"スナッピー", "ピラニア", 69, 4};
  catalog(snappy);
  label(snappy);
  return 0;
}

