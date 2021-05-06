#include <cstdio>
#include "TipoNave.h"
#include "PilhaDePreparacao.h"
#include "ListaDeCombate.h"
#include "FilaDeAvaria.h"

int main() {
  PilhaDePreparacao naves_em_preparacao; //Estrutura de preparação das naves;
  ListaDeCombate naves_em_combate; //Estrutura de combate;
  FilaDeAvaria naves_avariadas; //Estrutura de naves avariadas;
  TipoNave nave_id;
  int num_naves;
  scanf("%d", &num_naves);
  int i;
  for(i=0; i < num_naves; i++){
    int x;
    scanf("%d", &x);
    nave_id.SetNaveID(x); //Atribui o valor inserido pelo usuário à identificação da nave;
    naves_em_preparacao.Empilha(nave_id); //Empilha as naves na estrutura de preparação;
  }
  int operacao;
  while(scanf("%d", &operacao) != EOF) {
    switch(operacao){
      case 0: //Quando o imperador quer enviar a nave mais apta da estrutura de preparação para a estrutura de combate;
        nave_id = naves_em_preparacao.Desempilha(); //Tira a nave mais apta da estrutura de preparação (pilha) e armazena em nave_id;
        naves_em_combate.InsereFinal(nave_id); //Coloca a nave mais apta na estrutura de combate (lista);
        printf("nave %d em combate\n", nave_id.GetNaveID());
        break;
      case -1: //Reporta que a nave do início da fila de naves avariadas foi consertada;
        nave_id = naves_avariadas.Desenfileira(); //Remove a nave da estrutura de naves avariadas;
        naves_em_preparacao.Empilha(nave_id); //Devolve a nave à estrutura de preparação;
        printf("nave %d consertada\n", nave_id.GetNaveID());
        break;
      case -2: //Quando o imperador quer imprimir os identificadores das naves aguardando p/ entrar em combate (da mais apta para a menos apta);
        naves_em_preparacao.ImprimeDoFimAoInicio();
        break;
      case -3: //Quando o imperador quer imprimir os identificadores das naves avariadas aguardando p/ serem consertadas;
        naves_avariadas.Imprime();
        break;
      default:
        nave_id.SetNaveID(operacao); //Atribui o id inserido pelo usuário a uma variável do tipo TipoNave;
        int posicao = naves_em_combate.RetornaPosicao(nave_id); //Armazena a posição da lista que contém a nave que foi avariada;
        nave_id = naves_em_combate.RemovePosicao(posicao+1); //Remove nave avariada da estrutura de combate;
        naves_avariadas.Enfileira(nave_id); //Coloca a nave na estrutura de naves avariadas;
        printf("nave %d avariada\n", nave_id.GetNaveID());
        break;
    }
  }
  return 0;
}
