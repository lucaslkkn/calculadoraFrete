#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

// Variáveis globais
float pesoProduto;
int local;
float valorTotal;
float valorFrete;
int Produto;
float valorProduto;
char nomeProduto[100];
char localNome[50];
long long produtoSerial;

// ===================== PROCEDIMENTO 1 =====================
// Define o nome do local baseado no número
void nomeLocal(int local, char localNome[]) {
    if(local == 1) {
        strcpy(localNome, "Sul");
    }
    if(local == 2) {
        strcpy(localNome, "Sudeste");
    }
    if(local == 3) {
        strcpy(localNome, "Norte");
    }
    if(local == 4) {
        strcpy(localNome, "Nordeste");
    }
}

// ===================== PROCEDIMENTO 2 =====================
// Calcula o valor do frete baseado no peso e local
void calcularValorFrete(float pesoProduto, int local) {
    if (local == 1) {
        if (pesoProduto > 2) {
            valorFrete = 50;
        } else {
            valorFrete = 30;
        }
    } else if (local == 2) {
        if (pesoProduto > 2) {
            valorFrete = 45;
        } else {
            valorFrete = 25;
        }
    } else if (local == 3) {
        if (pesoProduto > 2) {
            valorFrete = 55;
        } else {
            valorFrete = 35;
        }
    } else if (local == 4) {
        if (pesoProduto > 2) {
            valorFrete = 60;
        } else {
            valorFrete = 40;
        }
    }
}

// ===================== PROCEDIMENTO 3 =====================
// Define os dados do produto selecionado
void definirProduto(int produto) {
    if (produto == 1) {
        produtoSerial = 20251234161;
        valorProduto = 5000;
        pesoProduto = 0.8;
        strcpy(nomeProduto, "Iphone 16");
    } else if (produto == 2) {
        produtoSerial = 20251234162;
        valorProduto = 7700;
        pesoProduto = 2;
        strcpy(nomeProduto, "Iphone 16 Pro");
    } else if (produto == 3) {
        produtoSerial = 20251234163;
        valorProduto = 8500;
        pesoProduto = 3;
        strcpy(nomeProduto, "Iphone 16 Pro Max");
    } else if (produto == 4) {
        produtoSerial = 2025987611;
        valorProduto = 120;
        pesoProduto = 4;
        strcpy(nomeProduto, "Fonte de Alimentação 18W USB-C");
    }
    
}

// ===================== PROCEDIMENTO 4 =====================
// Lê a seleção do produto do usuário
void selecionarProduto() {
    printf("\nDigite o número do produto:\n");
    printf("1 - Iphone 16\n");
    printf("2 - Iphone 16 Pro\n");
    printf("3 - Iphone 16 Pro Max\n");
    printf("4 - Fonte de Alimentação 18W USB-C\n");
    printf("Opção: ");
    scanf("%d", &Produto);
    definirProduto(Produto);
}

// ===================== PROCEDIMENTO 5 =====================
// Lê a seleção do local do usuário
void selecionarLocal() {
    printf("\nDigite o número do local de destino:\n");
    printf("1 - Sul\n");
    printf("2 - Sudeste\n");
    printf("3 - Norte\n");
    printf("4 - Nordeste\n");
    printf("Opção: ");
    scanf("%d", &local);
}

// ===================== PROCEDIMENTO 6 =====================
// Calcula o valor total da compra
void calcularValorTotal() {
    valorTotal = valorProduto + valorFrete;
}

// ===================== PROCEDIMENTO 7 =====================
// Exibe o resumo final da venda
void finalizarVenda() {
    nomeLocal(local, localNome);
    printf("\n====================================\n");
    printf("Código do produto: %lld\n", produtoSerial);
    printf("Nome do produto: %s\n", nomeProduto);
    printf("Peso do Produto: %.2f kg\n", pesoProduto);
    printf("====================================\n");
    printf("Seu local de destino é: %s\n", localNome);
    printf("Preço do Frete: R$ %.2f\n", valorFrete);
    printf("Preço do Produto: R$ %.2f\n", valorProduto);
    printf("Preço Total: R$ %.2f\n", valorTotal);
    printf("====================================\n");
}

// ===================== FUNÇÃO PRINCIPAL =====================
int main(void) {
    setlocale(LC_ALL, "Portuguese");
    
    printf("================================\n")
    printf("=== BEM-VINDO A LKKN STORE ===\n");
    
    // Seleciona o produto
    selecionarProduto();
    
    // Seleciona o local de destino
    selecionarLocal();
    
    // Calcula o frete
    calcularValorFrete(pesoProduto, local);
    
    // Calcula o valor total
    calcularValorTotal();
    
    // Exibe o resumo
    finalizarVenda();
    
    return 0;
}
