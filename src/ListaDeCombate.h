#ifndef LISTADECOMBATE_H
#define LISTADECOMBATE_H
#include "TipoNave.h"

//Para a estrutura de combate de naves, decidi usar uma implementação de lista usando arranjo, baseada naquela vista em aula;

class ListaDeCombate{
    public:
        ListaDeCombate(); //Construtor
        int GetTamanho(); //Retorna o tamanho da lista
        bool Vazia(); //Testa se a lista está vazia
        TipoNave GetNave(int pos); //Retorna o id da nave;
        void SetNave(TipoNave nave_id, int pos); //Seta um valor pro id da nave;
        void InsereInicio(TipoNave nave_id); //Insere uma nave no início da lista;
        void InsereFinal(TipoNave nave_id);  //Insere uma nave no final da lista;
        void InserePosicao(TipoNave nave_id, int pos); //Insere um elemento em uma posição conhecida;
        TipoNave RemoveInicio(); //Remove um elemento do início da lista
        TipoNave RemoveFinal(); //Remove um elemento do final da lista;
        TipoNave RemovePosicao(int pos); //Remove um elemento de uma posição conhecida;
        TipoNave Pesquisa(int id); //Verifica se um elemento está na lista;
        int RetornaPosicao(TipoNave nave_id); //Busca por um elemento e retorna a posição que ele ocupa na lista sequencial;
        void Imprime();
        void Limpa();
    private:
        static const int MAXTAM = 5000;
        TipoNave estrutura_de_combate[MAXTAM];
        int tamanho;
};

#endif //LISTADECOMBATE_H