#ifndef CAES_H
#define CAES_H

class noh{
  friend class lista;
private:
  int id;
  char nome[50];
  char caracteriticas[200];
  float altura_media;
  int tempo_medio_de_vida;
  noh* proximo;
public:
  noh();
  void setId(noh* objeto);
  void setNome(noh* objeto);
  void setCaracteriticas(noh* objeto);
  void setAltura_media(noh* objeto);
  void setTempo_medio_de_vida(noh* objeto);
};

class lista{
private:
  noh* primeiro;
  noh* ultimo;
  int tamanho;
public:
  lista();
  ~lista();
  void insere(noh objeto);
  void imprime();
  char menu();
  void insereArquivo(lista listaCao);
  void lerArquivo(lista listacao);
};

#endif
