#include <stdio.h>
#include <string.h>

void retangulo(FILE *stream, int x, int y, int width, int height, const char *fill) {
    fprintf(stream, "<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"%s\" />\n", x, y, width, height, fill);
}

void circulo(FILE *stream, int cx, int cy, int r, const char *fill) {
    fprintf(stream, "<circle cx=\"%d\" cy=\"%d\" r=\"%d\" fill=\"%s\" />\n", cx, cy, r, fill);
}

void linha(FILE *stream, int x1, int y1, int x2, int y2, const char *stroke, int stroke_width) {
    fprintf(stream, "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"%s\" stroke-width=\"%d\" />\n", x1, y1, x2, y2, stroke, stroke_width);
}

void texto(FILE *stream, int x, int y, const char *conteudo, const char *fill, int font_size) {
    fprintf(stream, "<text x=\"%d\" y=\"%d\" fill=\"%s\" font-size=\"%d\">%s</text>\n", x, y, fill, font_size, conteudo);
}

int main() {
    char nome_arquivo[100];
    FILE *fp;
    char escolha;

    printf("Digite o nome do arquivo SVG: ");
    scanf("%s", nome_arquivo);

    fp = fopen(nome_arquivo, "w");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    fprintf(fp, "<svg width=\"500\" height=\"500\">\n");

    do {
        printf("\nEscolha uma figura para adicionar:\n");
        printf("  R - Retângulo\n");
        printf("  C - Círculo\n");
        printf("  L - Linha\n");
        printf("  T - Texto\n");
        printf("  F - Finalizar\n");
        printf("Escolha: ");
        scanf(" %c", &escolha);

        switch (escolha) {
            case 'R': {
                int x, y, width, height;
                char fill[20];
                printf("Digite x, y, largura, altura e cor (ex: 10 20 50 30 blue): ");
                scanf("%d %d %d %d %s", &x, &y, &width, &height, fill);
                retangulo(fp, x, y, width, height, fill);
                break;
            }
            case 'C': {
                int cx, cy, r;
                char fill[20];
                printf("Digite cx, cy, raio e cor (ex: 50 50 20 red): ");
                scanf("%d %d %d %s", &cx, &cy, &r, fill);
                circulo(fp, cx, cy, r, fill);
                break;
            }
            case 'L': {
                int x1, y1, x2, y2, stroke_width;
                char stroke[20];
                printf("Digite x1, y1, x2, y2, cor da linha e largura da linha (ex: 10 10 100 50 black 2): ");
                scanf("%d %d %d %d %s %d", &x1, &y1, &x2, &y2, stroke, &stroke_width);
                linha(fp, x1, y1, x2, y2, stroke, stroke_width);
                break;
            }
            case 'T': {
                int x, y, font_size;
                char conteudo[100], fill[20];
                printf("Digite x, y, texto, cor e tamanho da fonte (ex: 20 80 Hello green 16): ");
                scanf("%d %d %[^\n]s %s %d", &x, &y, conteudo, fill, &font_size);
                texto(fp, x, y, conteudo, fill, font_size);
                break;
            }
            case 'F':
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (escolha != 'F');

    fprintf(fp, "</svg>\n");
    fclose(fp);

    printf("Arquivo SVG '%s' criado com sucesso.\n", nome_arquivo);

    return 0;
}