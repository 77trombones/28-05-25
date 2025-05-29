#include <stdio.h>

int abertura(FILE *arquivo) {
  if (arquivo == NULL) {
    return 0;
  }
  fprintf(arquivo, "<svg width=\"200\" height=\"200\">\n");
  return 1;
}

int fechamento(FILE *arquivo) {
  if (arquivo == NULL) {
    return 0;
  }
  fprintf(arquivo, "</svg>\n");
  return 1;
}

int main(void) {
  int resultado = 0;
  int x, y, width, height;

  FILE *pArquivo = NULL;

  pArquivo = fopen("desenho.svg", "w");

  if (pArquivo == NULL) {
    printf("O arquivo não foi aberto!\n");
    return 1;
  } else {
    puts("Digite a posição x do quadrado:");
    scanf("%d", &x);

    puts("Digite a posição y do quadrado:");
    scanf("%d", &y);

    puts("Digite a largura do quadrado:");
    scanf("%d", &width);

    puts("Digite a altura do quadrado:");
    scanf("%d", &height);

    resultado = abertura(pArquivo);
    if (resultado) {
      resultado = fprintf(pArquivo, "<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"red\" />\n", x, y, width, height);

      if (resultado > 0) {
        resultado = fechamento(pArquivo);
        if (!resultado) {
          printf("Erro ao fechar a tag SVG.\n");
        }
      } else {
        printf("Erro ao gravar o retângulo no arquivo.\n");
        resultado = 0;
      }
    } else {
      printf("Erro ao gravar no arquivo.\n");
    }
  }

  fclose(pArquivo);
  if (pArquivo != NULL && resultado) {
    printf("Arquivo 'desenho.svg' criado com sucesso.\n");
  }
  return 0;
}