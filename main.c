#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX 100  // Tamanho máximo da lista

typedef struct {
    int dados[MAX];
    int tamanho;
} Lista;

//Criação da lista vazia
void criarLista(Lista *l) {
    l->tamanho = 0;
}

//Verificar se a lista está vazia
int listaVazia(Lista *l) {
    return l->tamanho == 0;
}

//Verificar se a lista está cheia
int listaCheia(Lista *l) {
    return l->tamanho == MAX;
}

//Obter o tamanho da lista
int obterTamanho(Lista *l) {
    return l->tamanho;
}

//Obter o valor de um elemento
int obterElemento(Lista *l, int pos) {
    if (pos < 1 || pos > l->tamanho) {
        return -1;
    }
    return l->dados[pos - 1];
}

//Modificar um elemento
void modificarElemento(Lista *l, int pos, int valor) {
    if (pos < 1 || pos > l->tamanho) {
        return;
    }
    l->dados[pos - 1] = valor;
}

//Inserir um elemento em uma determinada posição
void inserirElemento(Lista *l, int pos, int valor) {
    if (listaCheia(l) || pos < 1 || pos > l->tamanho + 1) {
        return;
    }
    for (int i = l->tamanho; i >= pos; i--) {
        l->dados[i] = l->dados[i - 1];
    }
    l->dados[pos - 1] = valor;
    l->tamanho++;
}

//Retirar um elemento de uma determinada posição
void removerElemento(Lista *l, int pos) {
    if (listaVazia(l) || pos < 1 || pos > l->tamanho) {
        return;
    }
    for (int i = pos - 1; i < l->tamanho - 1; i++) {
        l->dados[i] = l->dados[i + 1];
    }
    l->tamanho--;
}

//Função para exibir a lista
void exibirLista(Lista *l) {
    for (int i = 0; i < l->tamanho; i++) {
        printf("%d ", l->dados[i]);
    }
    printf("\n");
}

//Função de teste
void testes() {
    Lista lista;
    criarLista(&lista);
    assert(listaVazia(&lista) == 1);
    inserirElemento(&lista, 1, 10);
    assert(obterElemento(&lista, 1) == 10);
    inserirElemento(&lista, 2, 20);
    inserirElemento(&lista, 3, 30);
    assert(obterTamanho(&lista) == 3);
    modificarElemento(&lista, 2, 25);
    assert(obterElemento(&lista, 2) == 25);
    removerElemento(&lista, 2);
    assert(obterElemento(&lista, 2) == 30);
    printf("Todos os testes passaram!\n");
}

int main() {
    testes();
    return 0;
}