#ifndef _LOJA_H_
#define _LOJA_H_

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Produto
{
private:
  string nome;
  unsigned preco;
public:
  Produto(): nome(""), preco(0) {}

  bool ler(istream &I);
  void salvar(ostream &O) const;
  void digitar();
  string get_nome();
  // Define a funcao imprimir como sendo salvar em cout
  inline void imprimir() const {salvar(cout);}
};

inline istream& operator>>(istream &I, Produto &P) {P.digitar(); return I;}
inline ostream& operator<<(ostream &O, const Produto &P) {P.salvar(O); return O;}

// =========================================
// Inclua aqui as classes Livro, CD e DVD

class Livro: public Produto
{
  private:
  string autor;

  public:
  Livro(): autor("")  {}
  void salvar(ostream &O) const;
  void digitar();
  inline void imprimir() const {salvar(cout);}
};

class CD: public Produto
{
  private:
  int faixas;

  public:
  CD(): faixas(0) {}

  void salvar(ostream &O) const;
  void digitar();
  inline void imprimir() const {salvar(cout);}
};

class DVD: public Produto
{
  private:
  int duracao;

  public:
  DVD(): duracao(0) {}
  void salvar(ostream &O) const;
  void digitar();
  inline void imprimir() const {salvar(cout);}
};
// =========================================

class ListaLivro
{
private:
  Livro *x;
  unsigned N;
public:
  // Inclua os construtores, destrutor e operadores necessarios
  ListaLivro(): x(NULL), N(0) {}
  ~ListaLivro(void);
  void incluir(const Livro &L);
  bool excluir(unsigned id);

  bool ler(istream &I);
  void salvar(ostream &O) const;
  void imprimir() const;
};

class ListaCD
{
private:
  CD *x;
  unsigned N;
public:
  // Inclua os construtores, destrutor e operadores necessarios
  ListaCD(): x(NULL), N(0) {}
  ~ListaCD(void);
  void incluir(const CD &C);
  bool excluir(unsigned id);

  bool ler(istream &I);
  void salvar(ostream &O) const;
  void imprimir() const;
};

class ListaDVD
{
private:
  DVD *x;
  unsigned N;
public:
  // Inclua os construtores, destrutor e operadores necessarios
  ListaDVD(): x(NULL), N(0) {}
  ~ListaDVD(void);
  void incluir(const DVD &D);
  bool excluir(unsigned id);

  bool ler(istream &I);
  void salvar(ostream &O) const;
  void imprimir() const;
};

class Loja
{
private:
  ListaLivro LL;
  ListaCD LC;
  ListaDVD LD;
public:
  inline Loja(): LL(), LC(), LD() {}

  inline void incluirLivro(const Livro &X) {LL.incluir(X);}
  inline bool excluirLivro(unsigned id) {return LL.excluir(id);}
  inline void incluirDVD(const DVD &X) {LD.incluir(X);}
  inline bool excluirDVD(unsigned id) {return LD.excluir(id);}
  inline void incluirCD(const CD &X) {LC.incluir(X);}
  inline bool excluirCD(unsigned id) {return LC.excluir(id);}

  bool ler(const string& arq);
  bool salvar(const string& arq) const;
  void imprimir() const;
};
#endif // _LOJA_H_