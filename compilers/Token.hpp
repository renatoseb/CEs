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
    case Categoria::RELOP:
      os << "RelOp";
      break;
    case Categoria::ASSIGN:
      os << "Assign";
      break;
    case Categoria::ERROR:
      os << "Error";
      break;
    case Categoria::SUM_OP:
      os << "SumOp";
      break;
    case Categoria::MINUS_OP:
      os << "MinOp";
      break;
    case Categoria::MUL_OP:
      os << "MulOp";
      break;
    case Categoria::DIV_OP:
      os << "DivOp";
      break;
    case Categoria::COLON:
      os << "Colon";
      break;
    case Categoria::PAR_BEGIN:
      os << "ParBegin";
      break;
    case Categoria::PAR_END:
      os << "ParEnd";
      break;
    case Categoria::SQR_BRACKET_BEGIN:
      os << "SqrBrcktBegin";
      break;
    case Categoria::SQR_BRACKET_END:
      os << "SqrBrcktEnd";
      break;
    case Categoria::CUR_BRACKET_BEGIN:
      os << "CurBrcktBegin";
      break;
    case Categoria::CUR_BRACKET_END:
      os << "CurBrcktEnd";
      break;
    case Categoria::RESERV_WORD:
      os << "ReservWord";
      break;

    default:
      os << "Sin Categoria";
      break;
  }
  os << ", " << token._lexema << ">";
  return os;
}
