#ifndef FILADEAVARIA_H
#define FILADEAVARIA_H
#include "TipoNave.h"

//Para a estrutura de naves avariadas, decidi usar uma implementação de fila usando arranjo, baseada naquela vista em aula;

class FilaDeAvaria{
    public:
        FilaDeAvaria();
        int GetTamanho();
        bool Vazia();
        void Enfileira(TipoNave item);
        TipoNave Desenfileira();
        void Limpa();
        void Imprime();
    private:
        int tamanho;
        int frente;
        int tras;
        static const int MAXTAM = 5000;
        TipoNave estrutura_de_avaria[MAXTAM];
};

#endif //FILADEAVARIA_H