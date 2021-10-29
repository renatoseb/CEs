#pragma once

#include <iostream>

#include "Enums.h"

class Token {
 public:
  std::string _lexema;
  Categoria _atributo;

  Token(std::string lexema, Categoria atributo)
      : _lexema(lexema), _atributo(atributo) {}

  Token() : _lexema(""), _atributo(END) {}

  bool operator==(const Token& in) const {
    return in._lexema == this->_lexema && in._atributo == this->_atributo;
  }
};

//Allows printing Tokens on the Google Test failing reports
std::ostream& operator<<(std::ostream& os, Token token) {
  if(token._atributo == Categoria::COM)
  {
    os << "";
    return os;
  }
  os << "<";
  switch (token._atributo) {
    case Categoria::IDENTIFICADOR:
      os << "Identificador";
      break;
    case Categoria::NUMERO:
      os << "Numero";
      break;
    case Categoria::OP_COMP:
      os << "OpComp";
      break;
    case Categoria::ASIGNAR:
      os << "Asignar";
      break;
    case Categoria::ERROR:
      os << "Error";
      break;
    case Categoria::OP_SUMA:
      os << "OpSuma";
      break;
    case Categoria::OP_RESTA:
      os << "OpResta";
      break;
    case Categoria::OP_MUL:
      os << "OpMul";
      break;
    case Categoria::OP_DIV:
      os << "OpDiv";
      break;
    case Categoria:COMA:
      os << "Coma";
      break;
    case Categoria::PAR_INICIO:
      os << "ParInicio";
      break;
    case Categoria::PAR_FINAL:
      os << "ParFinal";
      break;
    case Categoria::CORCH_INICIO:
      os << "CorchInicio";
      break;
    case Categoria::CORCH_FINAL:
      os << "CorchFinal";
      break;
    case Categoria::LLAVES_INICIO:
      os << "LLavesInicio";
      break;
    case Categoria::LAVES_FINAL:
      os << "LLavesFinal";
      break;
    case Categoria::PALABRA_RESERVADA:
      os << "PalabraReservada";
      break;

    default:
      os << "Sin Categoria";
      break;
  }
  os << ", " << token._lexema << ">";
  return os;
}
