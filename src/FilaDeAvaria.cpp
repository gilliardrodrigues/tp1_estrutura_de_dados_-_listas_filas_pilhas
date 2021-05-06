#include "TipoNave.h"
#include "FilaDeAvaria.h"
#include <cstdio>

//Para a estrutura de naves avariadas, decidi usar uma implementação de fila usando arranjo, baseada naquela vista em aula;

FilaDeAvaria::FilaDeAvaria(){ //Construtor
    tamanho = 0;
    frente = 0;
    tras = 0;
}
int FilaDeAvaria::GetTamanho(){
    return tamanho;
}
bool FilaDeAvaria::Vazia(){
    if(tamanho == 0)
        return true;
    return false;
}
void FilaDeAvaria::Enfileira(TipoNave nave_id){
    if(tamanho == MAXTAM)
        throw "ERRO: Fila cheia!"; //Exceção;
    estrutura_de_avaria[tras] = nave_id; //Insere um elemento no final da fila (tras);
    tras = (tras + 1) % MAXTAM; //Aritmética modular para tornar a fila uma fila circular;
    tamanho++; //Aumenta o tamanho da fila;
}
TipoNave FilaDeAvaria::Desenfileira(){
    TipoNave nave_removida;
    if(tamanho == 0)
        throw "ERRO: Fila vazia!";  //Exceção;
    nave_removida = estrutura_de_avaria[frente]; //Remove um elemento da frente da fila;
    frente = (frente + 1) % MAXTAM; //Aritmética modular para tornar a fila uma fila circular;
    tamanho--; //Decresce o tamanho;
    return nave_removida; //Retornta o elemento removido;
}
void FilaDeAvaria::Limpa(){
    tamanho = 0;
    frente = 0;
    tras = 0;
}
void FilaDeAvaria::Imprime(){
    if(tamanho == 0)
        throw "ERRO: Fila vazia!";  //Exceção;
    int i;
    for(i = frente; i < tras; i++){ //Percorre a fila do início ao fim;
        estrutura_de_avaria[i].Imprime(); //Imprime os elementos da fila;
        printf("\n");
    }
}