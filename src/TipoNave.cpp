#include "TipoNave.h"
#include <cstdio>

using namespace std;

TipoNave::TipoNave(){
    identificador_da_nave = -5; //indica um id vazio, utilizarei "-5" ao invés de "-1" pois como especificado no TP, não existe id igual a 0,-1,-2 ou -3;
}
TipoNave::TipoNave(int id){
    identificador_da_nave = id;
}
void TipoNave::SetNaveID(int id){
    identificador_da_nave = id;
}
int TipoNave::GetNaveID(){
    return identificador_da_nave;
}
void TipoNave::Imprime(){
    printf("%d", identificador_da_nave);
}