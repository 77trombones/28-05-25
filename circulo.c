#include <stdio.h>

void circulo(FILE *stream, int cx, int cy, int r, const char *fill) {
  char buffer[256];
  snprintf(buffer, sizeof(buffer), "<circle cx=\"%d\" cy=\"%d\" r=\"%d\" fill=\"%s\" />\n", cx, cy, r, fill);
  fputs(buffer, stream);
}
int main() {
  FILE *fp = fopen("desenho.svg", "w");
  if (fp == NULL) {
    perror("Erro ao abrir o arquivo");
    return 1;
  }

  int cx, cy, r;
  char fill[100];

  puts("Digite o valor de cx:");
  scanf("%d", &cx);
  puts("Digite o valor de cy:");
  scanf("%d", &cy);
  puts("Digite o valor de r:");
  scanf("%d", &r);
  puts("Digite a cor de preenchimento (fill):");
  scanf("%49s", fill);
  circulo(fp, cx, cy, r, fill);
  fclose(fp);
  return 0;
}
