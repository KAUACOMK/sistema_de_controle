#include <stdio.h>
#include <string.h>
#include "produto.h"


int master_principal (){
    printf("Sistema de estoque iniciado.\n");
}

void adicionar_produto(Estoque *estoque) {
    if (estoque->total_produtos >= MAX_PRODUTOS) {
        printf("Estoque cheio!\n");
        return;
    }

    Produto *p = &estoque->lista[estoque->total_produtos];

    printf("ID: ");
    scanf("%d", &p->id);

    // Verificação se o ID já existe
    int id_existe = 0;
    for (int i = 0; i < estoque->total_produtos; i++) {
        if (estoque->lista[i].id == &p->id) {
            id_existe = 1;
            break;
        }
    }

    if (id_existe != 0) {
        printf("Erro: Já existe um produto com este ID.\n");
    } else {
        limpar_entrada();
        printf("Nome: ");
        ler_texto(p->nome, 50);

        printf("Quantidade: ");
        scanf("%d", &p->quantidade);

        printf("Preço: ");
        scanf("%lf", &p->preco);

        estoque->total_produtos++;
    }
}
void lista_produtos(Estoque estoque) {
    if (estoque.total_produtos == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    printf("\nProdutos cadastrados:\n");

    for(int i = 0; i < estoque.total_produtos; i++) {
        Produto p = estoque.lista[i];
        printf("ID: %d, Nome: %s, Quantidade: %d, Preço: %.2lf\n", p.id, p.nome, p.quantidade, p.preco);
    }

}
void buscar_produtos_id (Estoque estoque) {
    int id_scanner = 0, encontrado = 0;
    printf("\nDigite uma ID:\n");
    scanf("%d", &id_scanner);
    for (int i = 0; i < estoque.total_produtos; i++) {
        Produto p = estoque.lista[i];
        if (p.id == id_scanner) {
            printf("ID: %d, Nome: %s, Quantidade: %d, Preço: %.2lf\n", p.id, p.nome, p.quantidade, p.preco);
            encontrado = 1;
            break;
        }
    }
    if (encontrado == 0) {
        printf("Produto nao encontrado");
    }
}
void atualizar_quantidade (Estoque *estoque) {
    int id_scanner = 0, encontrado = 0;
    printf("\nDigite uma ID:\n");
    scanf("%d", &id_scanner);
    int resposta = 0, nova_quantidade = 0, atualizado = 0;
    int aumentar = 1, reduzir = 2, posicao = -1;

    for (int i = 0; i < estoque->total_produtos; i++) {
        Produto p = estoque->lista[i];
        if (p.id == id_scanner) {
            printf("ID: %d, Nome: %s, Quantidade: %d, Preço: %.2lf\n", p.id, p.nome, p.quantidade, p.preco);
            encontrado = 1;
            posicao = i;
            break;
        }
    }
    if (!encontrado) {
        printf("Produto nao encontrado\n");
        return;
    }
    printf("Voce gostaria de aumentar ou reduzir a quantidade?\n");
    printf("(1)AUMENTAR   (2)REDUZIR:");
    scanf("%d", &resposta);

    if (resposta == 1) {
        printf("Quantidade a aumentar?\n");
        scanf("%d", &nova_quantidade);
        estoque->lista[posicao].quantidade += nova_quantidade;
        atualizado = 1;
        return;
    }

    else if (resposta == 2) {
        printf("Quantidade a reduzir?\n");
        scanf("%d", &nova_quantidade);
        if (estoque->lista[posicao].quantidade >= nova_quantidade) {
            estoque->lista[posicao].quantidade -= nova_quantidade;
            atualizado = 1;
        } else {
            printf("Erro: quantidade insuficiente para reduzir.\n");
        }
    }
    if (atualizado == 1) {
        printf("Produto atualizado!\n");
        return;
    }
}
void remover_produto (Estoque *estoque) {
    int id_scanner = 0, encontrado = 0, posicao = -1;
    printf("\nDigite uma ID:\n");
    scanf("%d", &id_scanner);

    for (int i = 0; i < estoque->total_produtos; i++) {
        Produto p = estoque->lista[i];
        if (p.id == id_scanner) {
            printf("ID: %d, Nome: %s, Quantidade: %d, Preço: %.2lf\n", p.id, p.nome, p.quantidade, p.preco);
            encontrado = 1;
            posicao = i;
            break;
        }
    }
    if (!encontrado) {
        printf("Produto nao encontrado\n");
        return;
    }
    for (int i = posicao; i < estoque->total_produtos - 1; i++) {
        estoque->lista[i] = estoque->lista[i + 1];

    }
    (estoque->total_produtos) --;
}
void valor_total_do_estoque (Estoque estoque) {

    double soma_total = 0;
    for(int i = 0; i < estoque.total_produtos; i++) {
        Produto p = estoque.lista[i];
        soma_total += p.preco * p.quantidade;
    }
    printf("Valor total do estoque : %.2f \n ", soma_total);

    return;
}
void listar_produtos_baixo_estoque(Estoque estoque) {
    int contador_de_estoque_baixo = 0;
    for (int i = 0; i < estoque.total_produtos; i++) {
        Produto p = estoque.lista[i];
        if (p.quantidade <= 5) {
            printf("ID: %d, Nome: %s, Quantidade: %d, Preço: %.2lf\n", p.id, p.nome, p.quantidade, p.preco);
            contador_de_estoque_baixo += 1;
        }
    }
        if (contador_de_estoque_baixo == 0) {
            printf("Nenhum produto com estoque baixo\n");
        }
}

