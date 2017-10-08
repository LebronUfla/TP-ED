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
    cout << "3 - GRAVAR ARQUIVO\n";
    cout << "4 - LER ARQUIVO\n";
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
void lista::insereArquivo(lista listaCao){
    FILE *arq;
    int result;
    noh* aux = primeiro;

    arq = fopen("ArqTeste.dat", "wb"); // Cria um arquivo binário para gravação

    if (arq == NULL){ // Se não conseguiu criar
        cout<< "Problemas na CRIACAO do arquivo"<< endl;
        return;
    }
    while(aux != NULL){
        result = fwrite (aux, sizeof(noh), listaCao.tamanho, arq);
        aux = aux->proximo;
    }
    cout<<"nro de elementos gravados: " << result;
    fclose(arq);
}

void lista::lerArquivo(lista listacao){
    FILE *arq;
    int result;
    int i = 0;
    noh* aux = primeiro;
    noh vetor[listacao.tamanho];

  // Abre um arquivo BINÁRIO para LEITURA
    arq = fopen("ArqTeste.dat", "rb");
    if (arq == NULL){  // Se houve erro na abertura
        printf("Problemas na abertura do arquivo\n");
        return;
    }

    result = fread (&vetor, sizeof(noh), listacao.tamanho, arq);
    printf("Nro de elementos lidos: %d\n", result);

    for (i=0; i<result; i++){
      cout << "ID: " << vetor[i].id << endl;
      cout<< "NOME: " << vetor[i].nome << endl;
    }

    fclose(arq);
}
