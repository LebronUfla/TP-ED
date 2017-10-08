#include "caes.h"
#include <cstdlib>
#include <iostream>
using namespace std;

noh::noh(){
  id = 0;
}

lista::lista(){
  primeiro = NULL;
  ultimo = NULL;
  tamanho = 0;
}

lista::~lista(){
  noh* aux = primeiro;
  noh* temp;

  while(aux != NULL){
    temp = aux;
    aux = aux->proximo;
    delete temp;
  }
  primeiro = NULL;
  ultimo = NULL;
}
//MENU
char lista::menu(){
    char resp;

    cout << "***************MENU***************\n\n";
    cout << "1 - INSERIR CÃO \n";
    cout << "2 - LISTAR CAES\n";
    cout << "0 - SAIR\n";
    cout<<"opcao: ";
    cin >> resp;
    return resp;

}

// SET VALORES PARA O OBJETO
void noh::setId(noh* objeto){
    cout<<"\nEntre com o ID:  ";
    cin>>objeto->id;
}
void noh::setNome(noh* objeto){
    cout<<"\nEntre com o Nome do cão: ";
    cin>>objeto->nome;
}
void noh::setCaracteriticas(noh* objeto){
    cout<<"\nEntre com a caracteristica: ";
    cin>>objeto->caracteriticas;
}
void noh::setAltura_media(noh* objeto){
    cout<<"\nEntre com a altura: ";
    cin>>objeto->altura_media;
}
void noh::setTempo_medio_de_vida(noh* objeto){
    cout<<"\nEntre com tempo medio de vida: ";
    cin>>objeto->tempo_medio_de_vida;
}

//INSERE ORDENADO
void lista::insere(noh objeto){
    noh* novo = new noh(objeto);
    noh* aux = primeiro;
    novo->proximo = NULL;

    if(primeiro == NULL){//lista vazia
        primeiro = novo;
        ultimo = novo;
    }else{
        while(aux != NULL){
            if( (aux == primeiro) and (novo->id < aux->id) ){
                novo->proximo = aux;
                primeiro = novo;
            }
            else if( (aux == ultimo) and (novo->id > ultimo->id) ){
                ultimo->proximo = novo;
                ultimo = novo;
            }
            else if( (novo->id > aux->id) and (novo->id < aux->proximo->id) ){
                novo->proximo = aux->proximo;
                aux->proximo = novo;
            }
            aux = aux->proximo;
        }
    }
    tamanho++;
}

void lista::imprime(){
    noh* aux = primeiro;

    while(aux != NULL){
        cout << " ID: " << aux->id << endl;
        cout << "NOME: " << aux->nome << " " << endl;
        cout << "CARACTERISTICAS: " <<aux->caracteriticas << " " << endl;
        cout << "ALTURA MEDIA: " <<aux->altura_media << " " << endl;
        cout << "TEMPO MEDIO DE VIDA: " <<aux->tempo_medio_de_vida << " " << endl;

        aux = aux->proximo;
    }
}
