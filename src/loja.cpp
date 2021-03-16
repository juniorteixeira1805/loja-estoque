#include <iostream>
#include <string>
#include "loja.h"
#include <limits>
#include <fstream>

using namespace std;


// ==================== FUNÇÕES DA CLASSE PRODUTO ======================= //

bool Produto::ler(istream &I){
  getline(I, nome);
  getline(I, preco);
 }
  void Produto::salvar(ostream &O) const {
    O << nome;
    O << " ;$";
    O << preco;
  }
  void Produto::digitar(){
    cout << "informe o nome do produto: " << endl;
    getline(cin, nome);

    cout << "Informe o preço do produto: " << endl;
    cin >> preco;
  }

string Produto::get_nome(){
  return nome;
}
// =======================================================================//


// ===================== FUNÇÕES DA CLASSE LIVRO =========================//
void Livro::salvar(std::ostream &O) const
  {
    O << "L: ";
    salvar(O);
    O << " ;";
    O << autor;
  }

void Livro::digitar(){
  Produto::digitar();
  
  cout << "Informe o autor: " << endl;
  getline(cin, autor);

}
// ====================================================================//

// ===================== FUNÇÕES DA CLASSE CD =========================//

void CD::salvar(std::ostream &O) const
  {
    O << "C: ";
    salvar(O);
    O << " ;";
    O << faixas;
  }

void CD::digitar(){
  Produto::digitar();
  
  cout << "Informe a quantidade de faixas: " << endl;
  cin >> faixas;

}

// =====================================================================//

// ===================== FUNÇÕES DA CLASSE DVD =========================//

void DVD::salvar(std::ostream &O) const
  {
    O << "D: ";
    salvar(O);
    O << " ;";
    O << duracao;
  }

void DVD::digitar(){
  Produto::digitar();
  
  cout << "Informe a duração: " << endl;
  cin >> duracao;

}

// ======================================================================= //

void ListaLivro::incluir(const Livro &L)
{
  Livro *prov = new Livro[N+1];

  for (unsigned i=0; i<N; i++) prov[i]=x[i];
  prov[N] = L;
  if (N>0) delete[] x;
  N++;
  x = prov;
}

ListaLivro::~ListaLivro(void){
  if(N>0) delete[] x;
}

bool ListaLivro::excluir(unsigned id){
  Livro *prov = new Livro[N-1];
  
  for(unsigned i = 0; i < N; i++){
    if(x[i].get_nome() != x[id].get_nome()){
      prov[i] = x[i];
    }
  }
  ListaLivro::~ListaLivro();

  for(unsigned i=0; i < N-1; i++){
    incluir(prov[i]);
  }
  N--;

  if(id > N){
    return false;
  }
  else{
    return true;
  }
}

// ======================================================================= //

void ListaCD::incluir(const CD &C)
{
  CD *prov = new CD[N+1];

  for (unsigned i=0; i<N; i++) prov[i] = x[i];
  prov[N] = C;
  if (N>0) delete[] x;
  N++;
  x = prov;
}

ListaCD::~ListaCD(void){
  if(N>0) delete[] x;
}

bool ListaCD::excluir(unsigned id){
  CD *prov = new CD[N-1];
  
  for(unsigned i = 0; i < N; i++){
    if(x[i].get_nome() != x[id].get_nome()){
      prov[i] = x[i];
    }
  }
  ListaCD::~ListaCD();

  for(unsigned i=0; i < N-1; i++){
    incluir(prov[i]);
  }
  N--;

  if(id > N){
    return false;
  }
  else{
    return true;
  }
}


// ======================================================================= //

void ListaDVD::incluir(const DVD &D)
{
  DVD *prov = new DVD[N+1];

  for (unsigned i=0; i<N; i++) prov[i] = x[i];
  prov[N] = D;
  if (N>0) delete[] x;
  N++;
  x = prov;
}

ListaDVD::~ListaDVD(void){
  if(N>0) delete[] x;
}

bool ListaDVD::excluir(unsigned id){
  DVD *prov = new DVD[N-1];
  
  for(unsigned i = 0; i < N; i++){
    if(x[i].get_nome() != x[id].get_nome()){
      prov[i] = x[i];
    }
  }
  ListaDVD::~ListaDVD();

  for(unsigned i=0; i < N-1; i++){
    incluir(prov[i]);
  }
  N--;

  if(id > N){
    return false;
  }
  else{
    return true;
  }
}