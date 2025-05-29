#include <stdio.h>

void linha(FILE *stream, int x1, int y1, int x2, int y2, const char *stroke, int stroke_width) {
  char buffer[256];
  snprintf(buffer, sizeof(buffer), "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"%s\" stroke-width=\"%d\" />\n", x1, y1, x2, y2, stroke, stroke_width);
  fputs(buffer, stream);
}

int main() {
  FILE *fp = fopen("desenho.svg", "w");
  if (fp == NULL) {
    perror("Erro ao abrir o arquivo");
    return 1;
  }

  int x1, y1, x2, y2, stroke_width;
  char stroke[100];

  puts("Digite o valor de x1:");
  scanf("%d", &x1);
  puts("Digite o valor de y1:");
  scanf("%d", &y1);
  puts("Digite o valor de x2:");
  scanf("%d", &x2);
  puts("Digite o valor de y2:");
  scanf("%d", &y2);
  puts("Digite a cor do traço (stroke):");
  scanf("%99s", stroke); // Corrected buffer size to prevent overflow
  puts("Digite a largura do traço (stroke-width):");
  scanf("%d", &stroke_width);

  linha(fp, x1, y1, x2, y2, stroke, stroke_width);
  fclose(fp);
  return 0;
}