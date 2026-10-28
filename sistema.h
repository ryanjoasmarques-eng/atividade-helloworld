#include <stdio.h>
#define MAX 10

char nomes[MAX][50];
float precos[MAX];
int quantidades[MAX], total = 0;

float faturamento(float p, int q) {
    return p * q;
}

float valorEstoque() {
    float soma = 0;
    for (int i = 0; i < total; i++)
        soma += precos[i] * quantidades[i];
    return soma;
}

void cadastrar() {
    int qtd;
    printf("Quantos produtos? ");
    scanf("%d", &qtd);

    if (qtd <= 0 || qtd > MAX - total) {
        printf("Quantidade invalida!\n");
        return;
    }

    for (int i = 0; i < qtd; i++) {
        printf("Nome: ");
        scanf("%49s", nomes[total]);
        printf("Preco: ");
        scanf("%f", &precos[total]);
        printf("Estoque: ");
        scanf("%d", &quantidades[total]);

        if (precos[total] < 0 || quantidades[total] < 0) {
            printf("Dados invalidos!\n");
            i--;
        } else total++;
    }
}

void consultar() {
    for (int i = 0; i < total; i++)
        printf("%d - %s | R$ %.2f | %d unidades\n",
        i + 1, nomes[i], precos[i], quantidades[i]);

    printf("Valor total do estoque: R$ %.2f\n", valorEstoque());
}

void vender() {
    int c, q;
    printf("Codigo e quantidade: ");
    scanf("%d%d", &c, &q);

    if (c < 1 || c > total || q <= 0)
        printf("Dados invalidos!\n");
    else if (q > quantidades[c - 1])
        printf("Estoque insuficiente!\n");
    else {
        quantidades[c - 1] -= q;
        printf("Faturamento: R$ %.2f\n",
               faturamento(precos[c - 1], q));
    }
}

void reposicao() {
    for (int i = 0; i < total; i++)
        if (quantidades[i] < 5)
            printf("%s: %d unidades\n", nomes[i], quantidades[i]);
}

void entrada() {
    int c, q;
    printf("Codigo e quantidade recebida: ");
    scanf("%d%d", &c, &q);

    if (c >= 1 && c <= total && q > 0)
        quantidades[c - 1] += q;
    else printf("Dados invalidos!\n");
}

int main() {
    int op;
    do {
        printf("\n1-Cadastrar  2-Consultar  3-Vender\n");
        printf("4-Reposicao  5-Entrada  6-Sair\n");
        printf("7-Valor do estoque\nOpcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1: cadastrar(); break;
            case 2: consultar(); break;
            case 3: vender(); break;
            case 4: reposicao(); break;
            case 5: entrada(); break;
            case 6: printf("Encerrando...\n"); break;
            case 7:
                printf("Valor: R$ %.2f\n", valorEstoque());
                break;
            default: printf("Opcao invalida!\n");
        }
    } while (op != 6);

    return 0;
}