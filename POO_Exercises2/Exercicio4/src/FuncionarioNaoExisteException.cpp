#include "FuncionarioNaoExisteException.h"

const char* FuncionarioNaoExisteException::what()
{
    return "Funcion�rio pesquisado n�o existe";
}
