#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include "caes.h"

using namespace std;

int main() {

    lista listaCao;
    noh cao;
    char resp;

    while(true){
        resp = listaCao.menu();
        if(resp == '1'){

            cao.setId(&cao);
            cao.setNome(&cao);
            cao.setCaracteriticas(&cao);
            cao.setAltura_media(&cao);
            cao.setTempo_medio_de_vida(&cao);
            listaCao.insere(cao);

        }else if(resp == '2'){

            listaCao.imprime();

        }else if(resp == '0'){

            cout << "bye\n";
            break;

        }else if(resp == '3'){
            listaCao.insereArquivoCpp(listaCao);
        }else if(resp == '4'){
            listaCao.lerArquivoCpp(listaCao);
        }else{
            cout<<"opcao invalida";
        }
    }

return 0;
}
