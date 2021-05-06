#include "TipoNave.h"
#include "PilhaDePreparacao.h"
#include <cstdio>

//Para a estrutura de preparação de naves, decidi usar uma implementação de pilha usando arranjo, baseada naquela vista em aula;

PilhaDePreparacao::PilhaDePreparacao(){ //Construtor
    tamanho = 0;
    topo = -1;
}
int PilhaDePreparacao::GetTamanho(){
    return tamanho;
}
bool PilhaDePreparacao::Vazia(){
    if(tamanho == 0) //Caso a pilha esteja vazia;
        return true;
    return false;
}
void PilhaDePreparacao::Empilha(TipoNave nave_id){
    if(tamanho == MAXTAM) //Caso a pilha esteja cheia;
        throw "ERRO: Pilha cheia!"; //Exceção;
    topo++; //Aumenta o topo
    estrutura_de_preparacao[topo] = nave_id; //Acrescenta uma nave;
    tamanho++; //Aumenta o tamanho;
}
TipoNave PilhaDePreparacao::Desempilha(){
    TipoNave nave_retirada;

    if(tamanho == 0) //Caso a pilha esteja vazia;
        throw "ERRO: Pilha vazia!"; //Exceção;
    nave_retirada = estrutura_de_preparacao[topo]; //Armazena a nave a ser removida;
    topo--; //Drecresce o topo;
    tamanho--; //Decresce o tamanho;
    return nave_retirada; //Retorna a nave removida;
}
void PilhaDePreparacao::Limpa(){
    tamanho = 0;
    topo = -1;
}
void PilhaDePreparacao::ImprimeDoFimAoInicio(){
    if(tamanho == 0) //Caso a pilha esteja vazia;
        throw "ERRO: Pilha vazia!"; //Exceção;
    int i;
    for(i = (tamanho-1); i >= 0; i--){ //Percorre da última posição preenchida até a primeira;
        estrutura_de_preparacao[i].Imprime(); //Imprime as naves aguardando para entrar em combate;
        printf("\n");
    }
}
