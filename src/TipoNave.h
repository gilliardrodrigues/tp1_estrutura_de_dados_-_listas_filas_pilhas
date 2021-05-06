#ifndef TIPONAVE_H
#define TIPONAVE_H

//Para definir o que seria um "TipoNave", me baseei no exemplo visto em aula chamado de "TipoItem"!

class TipoNave{
    public:
        TipoNave();
        TipoNave(int id);
        void SetNaveID(int id);
        int GetNaveID();
        void Imprime();
    private:
        int identificador_da_nave;
};
#endif // TIPONAVE_H
