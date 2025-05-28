#include <stdio.h>
#include <string.h>

int main() {
    char filename[100];
    int x, y, width, height;

    printf("Digite o nome do arquivo (sem a extensão .svg): ");
    scanf("%99s", filename);
    strcat(filename, ".svg");

    printf("Digite a posição x do quadrado: ");
    scanf("%d", &x);

    printf("Digite a posição y do quadrado: ");
    scanf("%d", &y);

    printf("Digite a largura do quadrado: ");
    scanf("%d", &width);

    printf("Digite a altura do quadrado: ");
    scanf("%d", &height);

    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Erro ao criar o arquivo");
        return 1;
    }

    fprintf(fp, "<svg version=\"1.1\"\n");
    fprintf(fp, "width=\"%d\" height=\"%d\"\n", width + x + 50, height + y + 50); 
    fprintf(fp, "xmlns=\"http://www.w3.org/2000/svg\">\n");
    fprintf(fp, "<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"red\" />\n", x, y, width, height);
    fprintf(fp, "</svg>\n");

    fclose(fp);
    printf("Arquivo %s criado com sucesso.\n", filename);
    return 0;
}