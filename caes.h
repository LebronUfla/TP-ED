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
  caes();
  ~caes();
  void setId(caes* objeto);
  void setNome(caes* objeto);
  void setCaracteriticas(caes* objeto);
  void setAltura_media(caes* objeto);
  void setTempo_medio_de_vida(caes* objeto);
};

class lista{
private:
  caes* primeiro;
  caes* ultimo;
  int tamanho;
public:
  lista();
  ~lista();
  void insere(caes objeto);
  void imprime(caes objeto);
};

#endif
