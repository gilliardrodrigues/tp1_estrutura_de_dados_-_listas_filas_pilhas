#include "TipoNave.h"
#include "ListaDeCombate.h"
#include <cstdio>

//Para a estrutura de combate de naves, decidi usar uma implementação de lista usando arranjo, baseada naquela vista em aula;

ListaDeCombate::ListaDeCombate(){
    tamanho = 0; //Construtor
}
int ListaDeCombate::GetTamanho(){
    return tamanho; 
}
bool ListaDeCombate::Vazia(){
    if(tamanho == 0) //Se a lista estiver vazia;
        return true;
    return false;
}
TipoNave ListaDeCombate::GetNave(int pos){
    if((pos <= 0)||(pos > tamanho))
        throw "ERRO: Posicao Invalida!"; //Exceção;
    return estrutura_de_combate[pos-1]; //Retorna o id da nave;
}
void ListaDeCombate::SetNave(TipoNave nave_id, int pos){
    if((pos <= 0)||(pos > tamanho))
        throw "ERRO: Posicao Invalida!"; //Exceção;
    estrutura_de_combate[pos-1] = nave_id; //Define um id para a nave;
}
void ListaDeCombate::InsereInicio(TipoNave nave_id){
    if(tamanho == MAXTAM)
        throw "ERRO: Lista cheia!"; //Exceção;
    tamanho++;
    int i;
    for(i = tamanho; i > 0; i--){
        estrutura_de_combate[i] = estrutura_de_combate[i-1];
        estrutura_de_combate[0] = nave_id; //Insere uma nave no início da lista;
    }
}
void ListaDeCombate::InsereFinal(TipoNave nave_id){
    if(tamanho == MAXTAM)
        throw "ERRO: Lista cheia!"; //Exceção;
    estrutura_de_combate[tamanho] = nave_id; //Insere uma nave no final da lista;
    tamanho++;
}
void ListaDeCombate::InserePosicao(TipoNave nave_id, int pos){
    if(tamanho == MAXTAM)
        throw "ERRO: Lista cheia!"; //Exceção;
    if((pos <= 0)||(pos > tamanho))
        throw "ERRO: Posicao Invalida!"; //Exceção;
    pos--; //posição no vetor: pos-1 (vetor começa em 0);
    tamanho++;
    int i;
    for(i = tamanho; i > pos; i--)
        estrutura_de_combate[i] = estrutura_de_combate[i-1];
    estrutura_de_combate[pos] = nave_id; //Insere um elemento em uma posição conhecida;
}
TipoNave ListaDeCombate::RemoveInicio(){
    TipoNave nave_removida;
    if(tamanho == 0)
        throw "ERRO: Lista vazia!"; //Exceção;
    nave_removida = estrutura_de_combate[0]; //Armazena o elemento a ser removido;
    int i;
    for(i = 0; i < tamanho; i++)
        estrutura_de_combate[i] = estrutura_de_combate[i+1]; ////Remove um elemento do início da lista
    tamanho--;
    return nave_removida;
}
TipoNave ListaDeCombate::RemoveFinal(){
    if(tamanho == 0)
        throw "ERRO: Lista vazia!"; //Exceção;
    TipoNave nave_removida;
    tamanho--;
    nave_removida = estrutura_de_combate[tamanho];  //Remove um elemento do final da lista;
    return nave_removida;
}
TipoNave ListaDeCombate::RemovePosicao(int pos){
    TipoNave nave_removida;
    if((pos <= 0)||(pos > tamanho))
        throw "ERRO: Posicao Invalida!"; //Exceção;
    if(tamanho == 0)
        throw "ERRO: Lista vazia!"; //Exceção;
    pos--; //posição no vetor: pos-1 (vetor começa em 0);
    nave_removida = estrutura_de_combate[pos];
    int i;
    for(i = pos; i < tamanho; i++)
        estrutura_de_combate[i] = estrutura_de_combate[i+1]; ////Remove um elemento de uma posição conhecida;
    tamanho--;
    return nave_removida;
}
TipoNave ListaDeCombate::Pesquisa(int id){
    TipoNave nave_encontrada;
    if(tamanho == 0)
        throw "ERRO: Lista vazia!"; //Exceção;
    nave_encontrada.SetNaveID(-5); //Indica pesquisa sem sucesso;
    int i;
    for(i = 0; i < tamanho; i++)
        if(estrutura_de_combate[i].GetNaveID() == id){ //Verifica se um elemento está na lista;
            nave_encontrada = estrutura_de_combate[i];
            break;
        }
    return nave_encontrada;
}
void ListaDeCombate::Imprime(){
    int i;
    for(i = 0; i < tamanho; i++){
        estrutura_de_combate[i].Imprime();
        printf("\n");
    }
}
void ListaDeCombate::Limpa(){
    tamanho = 0;
}
int ListaDeCombate::RetornaPosicao(TipoNave nave_id){
    if(tamanho == 0)
        throw "ERRO: Lista vazia!"; //Exceção;
    int posicaoNaLista = -5; //Indica pesquisa sem sucesso;
    int contador = 0;
    int i; 
    for(i = 0;  i < tamanho; i++){
        if(estrutura_de_combate[i].GetNaveID() == nave_id.GetNaveID()) //Busca por um elemento e retorna a posição que ele ocupa na lista sequencial;
            posicaoNaLista = contador; //Se o id procurado está na lista, armazena a posição na qual ele está;
        contador++;
    }
    return posicaoNaLista;
}