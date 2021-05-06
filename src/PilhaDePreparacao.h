#ifndef PILHADEPREPARACAO_H
#define PILHADEPREPARACAO_H
#include "TipoNave.h"

//Para a estrutura de preparação de naves, decidi usar uma implementação de pilha usando arranjo, baseada naquela vista em aula;

class PilhaDePreparacao{
    public:
        PilhaDePreparacao();
        int GetTamanho();
        bool Vazia();
        void Empilha(TipoNave nave_id);
        TipoNave Desempilha();
        void Limpa();
        void ImprimeDoFimAoInicio(); //Imprime da nave mais apta até a menos apta;
    private:
        int topo;
        static const int MAXTAM = 5000; //Limite superior para o nº de naves;
        TipoNave estrutura_de_preparacao[MAXTAM];
        int tamanho;
};





#endif //PILHADEPREPARACAO_H