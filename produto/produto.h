#ifndef PRODUTO_H_INCLUDED
#define PRODUTO_H_INCLUDED


#define MAX_PRODUTOS 100

typedef struct{

int id;
char name[50];
int quantidade;
double preco;


} Produto;
typedef struct {
    Produto lista[MAX_PRODUTOS];
    int total_produtos;
}Estoque;

void adicionar_produto(Estoque *estoque);
void listar_produtos(Estoque estoque);
void buscar_produtos_id (Estoque Estoque);

#endif
