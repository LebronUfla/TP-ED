#include <cstdlib>
#include <iostream>
#include "caes.h"

char menu(){
    char resp;

    cout << "***************MENU***************\n\n";
    cout << "1 - INSERIR CÃO \n";
    cout << "2 - LISTAR CAES\n";
    cout << "0 - SAIR\n";
    cout<<"opcao: ";
    cin >> resp;
    return resp;

}

int main() {

	  lista minhaLista;
    caes cao;
    char resp;

    while(true){
        resp = menu();
        if(resp == '1'){

            cao.setId(&cao);
            cao.setNome(&cao);
            cao.setCaracteriticas(&cao);
            cao.setAltura_media(&cao);
            cao.setTempo_medio_de_vida(&cao);

        }else if(resp == '2'){

            cao.imprime();

        }else if(resp == '0'){

            cout << "bye\n";
            break;

        }else{
            cout<<"opcao invalida";
        }
    }

return 0;
}
