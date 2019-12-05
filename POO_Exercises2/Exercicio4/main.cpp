#include <iostream>
#include "FuncionarioNaoExisteException.h"
#include "OrcamentoEstouradoException.h"
#include "Funcionario.h"
#include "Assalariado.h"
#include "Comissionado.h"
#include "Horista.h"
#include "Gerencia.h"
#include <locale>
using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    Gerencia g1 = Gerencia(4000);

    //SETTING EMPLOYEE EMPLOYEE
    Assalariado a1 = Assalariado(1200);
    a1.set_name("Andre");
    a1.set_mat(123);
    g1.set_funcionario(&a1);

    //SETTING HORIST EMPLOYEE
    Horista h1 = Horista(40, 50);
    h1.set_name("Gustavo");
    h1.set_mat(567);
    g1.set_funcionario(&h1);

    //SETTING COMISSIONED EMPLOYEE
    Comissionado c1 = Comissionado(1200, 30);
    c1.set_name("Lucas");
    c1.set_mat(245);
    g1.set_funcionario(&c1);

    //PRINTS
   cout << "--- FUNCION�RIO 1 -- [ASSALARIADO] ----\n";
   cout << "Nome: " << a1.get_name() << "\nMatr�cula: " << a1.get_mat() << "\nSal�rio: " << a1.calcula_salario() << endl << endl;

   cout << "--- FUNCION�RIO 2 -- [HORISTA] ----\n";
   cout << "Nome: " << h1.get_name() << "\nMatr�cula: " << h1.get_mat() << "\nSal�rio: " << h1.calcula_salario() << endl << endl;

   cout << "--- FUNCION�RIO 3 -- [COMISSIONADO] ---- \n";
   cout << "Nome: " << c1.get_name() << "\nMatr�cula: " << c1.get_mat() << "\nSal�rio: " << c1.calcula_salario() << endl << endl;

   cout << "\n" << "Or�amento total: " << g1.getOrcamento() << "\n" << endl;
   //METHODS OF GERENCIA
   try{
        cout << "Valor total da folha: " << g1.calcular_valor_total() << endl;
   }catch(OrcamentoEstouradoException s){
        cout << s.what() << endl;
   }


   try{
        cout << "Sal�rio do funcion�rio pesquisado: " << g1.consulta_salario_func("Dida") << endl;
   }catch(FuncionarioNaoExisteException t){
        cout << t.what() << endl;
   }



    return 0;
}
