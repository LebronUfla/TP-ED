#ifndef CAES_H
#define CAES_H

class caes{
  friend class lista;
private:
  int id;
  char nome[50];
  char caracteriticas[200];
  float altura_media;
  int tempo_medio_de_vida;
  caes* proximo;
public:
  //metodos
};

class lista{
private:
  caes* primeiro;
  caes* ultimo;
  int tamanho;
public:
  //metodos
};

#endif
