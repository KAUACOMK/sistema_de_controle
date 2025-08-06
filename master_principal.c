#include <stdio.h>
#include <stdlib.h>
#include "produto/produto.h"


int main()
{
    Estoque estoque;
    estoque.total_produtos = 0;

    printf("Sistema de estoque iniciado.\n");

    int opcao = -1;
    while (opcao != 0) {
        printf("\n========== MENU ==========\n");
        printf("1 - Adicionar produto\n");
        printf("2 - Listar produtos\n");
        printf("3 - Buscar produto por ID\n");
        printf("4 - Atualizar quantidade\n");
        printf("5 - Remover produto\n");
        printf("6 - Mostrar valor total do estoque\n");
        printf("7 - Listar produtos com estoque baixo\n");
        printf("0 - Sair\n");
        printf("==========================\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
    switch (opcao){
    case 1:
        adicionar_produto(&estoque);
        break;
    case 2:
        lista_produtos(estoque);
        break;
    case 3:
        buscar_produtos_id(estoque);
        break;
    case 4:
        atualizar_quantidade(&estoque);
        break;
    case 5:
       remover_produto(&estoque);
       break;
    case 6:
        valor_total_do_estoque(estoque);
        break;
    case 7:
        listar_produtos_baixo_estoque(estoque);
        break;
    case 0:
        printf("Saiu");
        break;
    default:
        printf ("Encerrando o sistema...\n");
        break;
    }
}
    return 0;
}
