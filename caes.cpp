#include "caes.h"
#include <cstdlib>
#include <iostream>

caes::caes(){
  id = 0;
}

lista::lista(){
  primeiro = NULL;
  ultimo = NULL;
  tamanho = 0;
}

lista::~lista(){
  caes* aux = primeiro;
  caes* temp;

  while(aux != NULL){
    temp = aux;
    aux = aux->proximo;
    delete temp;
  }
  primeiro = NULL;
  ultimo = NULL;
}
// SET VALORES PARA O OBJETO
void caes::setId(caes* objeto){
    cout<<"\nEntre com o ID:  ";
    cin>>objeto->id;
}
void caes::setNome(caes* objeto){
    cout<<"\nEntre com o Nome do cão: ";
    cin>>objeto->nome;
}
void caes::setCaracteriticas(caes* objeto){
    cout<<"\nEntre com a caracteristica: ";
    cin>>objeto->caracteriticas;
}
void caes::setAltura_media(caes* objeto){
    cout<<"\nEntre com a altura: ";
    cin>>objeto->altura_media;
}
void caes::setTempo_medio_de_vida(caes* objeto){
    cout<<"\nEntre com a altura: ";
    cin>>objeto->tempo_medio_de_vida;
}
//INSERE ORDENADO
void Lista::insere(caes objeto){
    caes* novo = new caes(objeto);
    caes *aux = primeiro;
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

void Lista::imprime(){
    caes *aux = primeiro;

    while(aux != NULL){
        cout << " ID: " << aux->id << endl;
        cout << "NOME: " << aux->nome << " " << endl;
        cout << "CARACTERISTICAS: " <<aux->caracteriticas << " " << endl;
        cout << "ALTURA MEDIA: " <<aux->altura_media << " " << endl;
        cout << "TEMPO MEDIO DE VIDA: " <<aux->tempo_medio_de_vida << " " << endl;

        aux = aux->proximo;
    }
}
