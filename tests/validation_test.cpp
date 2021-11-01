#include <gtest/gtest.h>

#include <strstream>

#include "FlexScanner.hpp"

using namespace utec::compilers;

TEST(SimpleTest, basicTest) {
  std::istrstream str("a=-2.7E4");

  FlexScanner scanner(str, std::cout);
  std::vector<Token> tokens;

  while (1) {
    auto token = scanner.get_token();
    if (token._atributo == END) break;
    tokens.push_back(token);
  }

  std::vector<Token> expected = {Token("a", Categoria::IDENTIFICADOR),
                                 Token("=", Categoria::ASIGNAR),
                                 Token("-2.7E4", Categoria::NUMERO)};
  EXPECT_EQ(tokens, expected);
}

TEST(CommentTest, hasComments) {
  std::istrstream str("a = b /* shouldn't be printed */ c = d");

  FlexScanner scanner(str, std::cout);
  std::vector<Token> tokens;

  while (1) {
    auto token = scanner.get_token();
    if (token._atributo == END) break;
    tokens.push_back(token);
  }

  std::vector<Token> expected = {Token("a", Categoria::IDENTIFICADOR),
                                 Token("=", Categoria::ASIGNAR),
                                 Token("b", Categoria::IDENTIFICADOR),
                                 Token("c", Categoria::IDENTIFICADOR),
                                 Token("=", Categoria::ASIGNAR),
                                 Token("d", Categoria::IDENTIFICADOR)};
  EXPECT_EQ(tokens, expected);
}

TEST(ErrorTest, basicTest) {
  std::istrstream str("a = b\n@");

  FlexScanner scanner(str, std::cout);
  std::vector<Token> tokens;

  while (1) {
    auto token = scanner.get_token();
    if (token._atributo == END) break;
    tokens.push_back(token);
  }

  std::vector<Token> expected = {Token("a", Categoria::IDENTIFICADOR),
                                 Token("=", Categoria::ASIGNAR),
                                 Token("b", Categoria::IDENTIFICADOR),
                                 Token("@", Categoria::ERROR),
                                 };
  EXPECT_EQ(tokens, expected);
}

TEST(MainTest, basicTest) {
  std::istrstream str("entero main(){ entero a = b; }");

  FlexScanner scanner(str, std::cout);
  std::vector<Token> tokens;

  while (1) {
    auto token = scanner.get_token();
    if (token._atributo == END) break;
    tokens.push_back(token);
  }

  std::vector<Token> expected = {Token("entero", Categoria::PALABRA_RESERVADA),
                                 Token("main", Categoria::PALABRA_RESERVADA),
                                 Token("(", Categoria::PAR_INICIO),
                                 Token(")", Categoria::PAR_FINAL),
                                 Token("{", Categoria::LLAVES_INICIO),
                                 Token("entero", Categoria::PALABRA_RESERVADA),
                                 Token("a", Categoria::IDENTIFICADOR),
                                 Token("=", Categoria::ASIGNAR),
                                 Token("b", Categoria::IDENTIFICADOR),
                                 Token("}", Categoria::LLAVES_FINAL)
                                 };
  EXPECT_EQ(tokens, expected);
}

TEST(boolExp, basicTest) {
  std::istrstream str("a == b || a != c");

  FlexScanner scanner(str, std::cout);
  std::vector<Token> tokens;

  while (1) {
    auto token = scanner.get_token();
    if (token._atributo == END) break;
    tokens.push_back(token);
  }

  std::vector<Token> expected = {
                                 Token("a", Categoria::IDENTIFICADOR),
                                 Token("==", Categoria::OP_COMP),
                                 Token("b", Categoria::IDENTIFICADOR),
                                 Token("a", Categoria::IDENTIFICADOR),
                                 Token("!=", Categoria::OP_COMP),
                                 Token("c", Categoria::IDENTIFICADOR)
                                 };
  EXPECT_EQ(tokens, expected);
}

TEST(OpTest, basicTest) {
  std::istrstream str("entero a = 5 + (3 * 2);");

  FlexScanner scanner(str, std::cout);
  std::vector<Token> tokens;

  while (1) {
    auto token = scanner.get_token();
    if (token._atributo == END) break;
    tokens.push_back(token);
  }

  std::vector<Token> expected = {Token("entero", Categoria::PALABRA_RESERVADA),
                                 Token("a", Categoria::IDENTIFICADOR),
                                 Token("=", Categoria::ASIGNAR),
                                 Token("5", Categoria::NUMERO),
                                 Token("+", Categoria::OP_SUMA),
                                 Token("(", Categoria::PAR_INICIO),
                                 Token("3", Categoria::NUMERO),
                                 Token("*", Categoria::OP_MUL),
                                 Token("2", Categoria::NUMERO),
                                 Token(")", Categoria::PAR_FINAL)
                                 };
  EXPECT_EQ(tokens, expected);
}

TEST(OpTest1, basicTest) {
  std::istrstream str("entero a = 5 / (3 / 2);");

  FlexScanner scanner(str, std::cout);
  std::vector<Token> tokens;

  while (1) {
    auto token = scanner.get_token();
    if (token._atributo == END) break;
    tokens.push_back(token);
  }

  std::vector<Token> expected = {Token("entero", Categoria::PALABRA_RESERVADA),
                                 Token("a", Categoria::IDENTIFICADOR),
                                 Token("=", Categoria::ASIGNAR),
                                 Token("5", Categoria::NUMERO),
                                 Token("/", Categoria::OP_DIV),
                                 Token("(", Categoria::PAR_INICIO),
                                 Token("3", Categoria::NUMERO),
                                 Token("/", Categoria::OP_DIV),
                                 Token("2", Categoria::NUMERO),
                                 Token(")", Categoria::PAR_FINAL)
                                 };
  EXPECT_EQ(tokens, expected);
}

TEST(OpTestwComents, basicTest) {
  std::istrstream str("entero a = 5 / (3 / 2); /* esta es una operacion */ entero b = 20 /30; ");

  FlexScanner scanner(str, std::cout);
  std::vector<Token> tokens;

  while (1) {
    auto token = scanner.get_token();
    if (token._atributo == END) break;
    tokens.push_back(token);
  }

  std::vector<Token> expected = {Token("entero", Categoria::PALABRA_RESERVADA),
                                 Token("a", Categoria::IDENTIFICADOR),
                                 Token("=", Categoria::ASIGNAR),
                                 Token("5", Categoria::NUMERO),
                                 Token("/", Categoria::OP_DIV),
                                 Token("(", Categoria::PAR_INICIO),
                                 Token("3", Categoria::NUMERO),
                                 Token("/", Categoria::OP_DIV),
                                 Token("2", Categoria::NUMERO),
                                 Token(")", Categoria::PAR_FINAL),

                                 Token("entero", Categoria::PALABRA_RESERVADA),
                                 Token("b", Categoria::IDENTIFICADOR),
                                 Token("=", Categoria::ASIGNAR),
                                 Token("20", Categoria::NUMERO),
                                 Token("/", Categoria::OP_DIV),
                                 Token("30", Categoria::NUMERO)
                                 };
  EXPECT_EQ(tokens, expected);
}

TEST(boolExp1, basicTest) {
  std::istrstream str("a == b && d < e || ( d >= f )");

  FlexScanner scanner(str, std::cout);
  std::vector<Token> tokens;

  while (1) {
    auto token = scanner.get_token();
    if (token._atributo == END) break;
    tokens.push_back(token);
  }

  std::vector<Token> expected = {
                                 Token("a", Categoria::IDENTIFICADOR),
                                 Token("==", Categoria::OP_COMP),
                                 Token("b", Categoria::IDENTIFICADOR),
                                 Token("d", Categoria::IDENTIFICADOR),
                                 Token("<", Categoria::OP_COMP),
                                 Token("e", Categoria::IDENTIFICADOR),
                                 Token("(", Categoria::PAR_INICIO),
                                 Token("d", Categoria::IDENTIFICADOR),
                                 Token(">=", Categoria::OP_COMP),
                                 Token("f", Categoria::IDENTIFICADOR),
                                 Token(")", Categoria::PAR_FINAL)
                                 };
  EXPECT_EQ(tokens, expected);
}

TEST(boolExp2, basicTest) {
  std::istrstream str("si(a == b && d < e || ( d >= f )){ retorno 1; }");

  FlexScanner scanner(str, std::cout);
  std::vector<Token> tokens;

  while (1) {
    auto token = scanner.get_token();
    if (token._atributo == END) break;
    tokens.push_back(token);
  }

  std::vector<Token> expected = {
                                 Token("si", Categoria::PALABRA_RESERVADA),
                                 Token("(", Categoria::PAR_INICIO),
                                 Token("a", Categoria::IDENTIFICADOR),
                                 Token("==", Categoria::OP_COMP),
                                 Token("b", Categoria::IDENTIFICADOR),
                                 Token("d", Categoria::IDENTIFICADOR),
                                 Token("<", Categoria::OP_COMP),
                                 Token("e", Categoria::IDENTIFICADOR),
                                 Token("(", Categoria::PAR_INICIO),
                                 Token("d", Categoria::IDENTIFICADOR),
                                 Token(">=", Categoria::OP_COMP),
                                 Token("f", Categoria::IDENTIFICADOR),
                                 Token(")", Categoria::PAR_FINAL),
                                 Token(")", Categoria::PAR_FINAL),
                                 Token("{", Categoria::LLAVES_INICIO),
                                 Token("retorno", Categoria::PALABRA_RESERVADA),
                                 Token("1", Categoria::NUMERO),
                                 Token("}", Categoria::LLAVES_FINAL)
                                 };
  EXPECT_EQ(tokens, expected);
}

TEST(funcTest, basicTest) {
  std::istrstream str("sin_tipo fib(){ si(a == b && d < e || ( d >= f )){ retorno 1; } }");

  FlexScanner scanner(str, std::cout);
  std::vector<Token> tokens;

  while (1) {
    auto token = scanner.get_token();
    if (token._atributo == END) break;
    tokens.push_back(token);
  }

  std::vector<Token> expected = {
                                 Token("sin_tipo", Categoria::PALABRA_RESERVADA),
                                 Token("fib", Categoria::IDENTIFICADOR),
                                 Token("(", Categoria::PAR_INICIO),
                                 Token(")", Categoria::PAR_FINAL),
                                 Token("{", Categoria::LLAVES_INICIO),
                                 Token("si", Categoria::PALABRA_RESERVADA),
                                 Token("(", Categoria::PAR_INICIO),
                                 Token("a", Categoria::IDENTIFICADOR),
                                 Token("==", Categoria::OP_COMP),
                                 Token("b", Categoria::IDENTIFICADOR),
                                 Token("d", Categoria::IDENTIFICADOR),
                                 Token("<", Categoria::OP_COMP),
                                 Token("e", Categoria::IDENTIFICADOR),
                                 Token("(", Categoria::PAR_INICIO),
                                 Token("d", Categoria::IDENTIFICADOR),
                                 Token(">=", Categoria::OP_COMP),
                                 Token("f", Categoria::IDENTIFICADOR),
                                 Token(")", Categoria::PAR_FINAL),
                                 Token(")", Categoria::PAR_FINAL),
                                 Token("{", Categoria::LLAVES_INICIO),
                                 Token("retorno", Categoria::PALABRA_RESERVADA),
                                 Token("1", Categoria::NUMERO),
                                 Token("}", Categoria::LLAVES_FINAL),
                                 Token("}", Categoria::LLAVES_FINAL)
                                 };
  EXPECT_EQ(tokens, expected);
}

TEST(funcTest1, basicTest) {
  std::istrstream str("sin_tipo fib(){ retorno 1; }");

  FlexScanner scanner(str, std::cout);
  std::vector<Token> tokens;

  while (1) {
    auto token = scanner.get_token();
    if (token._atributo == END) break;
    tokens.push_back(token);
  }

  std::vector<Token> expected = {
                                 Token("sin_tipo", Categoria::PALABRA_RESERVADA),
                                 Token("fib", Categoria::IDENTIFICADOR),
                                 Token("(", Categoria::PAR_INICIO),
                                 Token(")", Categoria::PAR_FINAL),
                                 Token("{", Categoria::LLAVES_INICIO),
                                 Token("retorno", Categoria::PALABRA_RESERVADA),
                                 Token("1", Categoria::NUMERO),
                                 Token("}", Categoria::LLAVES_FINAL)
                                 };
  EXPECT_EQ(tokens, expected);
}

TEST(ifelse, basicTest) {
  std::istrstream str("si(a) retorno 1; sino(b) retorno 0;");

  FlexScanner scanner(str, std::cout);
  std::vector<Token> tokens;

  while (1) {
    auto token = scanner.get_token();
    if (token._atributo == END) break;
    tokens.push_back(token);
  }

  std::vector<Token> expected = {
                                 Token("si", Categoria::PALABRA_RESERVADA),
                                 Token("(", Categoria::PAR_INICIO),
                                 Token("a", Categoria::IDENTIFICADOR),
                                 Token(")", Categoria::PAR_FINAL),
                                 Token("retorno", Categoria::PALABRA_RESERVADA),
                                 Token("1", Categoria::NUMERO),
                                 Token("sino", Categoria::PALABRA_RESERVADA),
                                 Token("(", Categoria::PAR_INICIO),
                                 Token("b", Categoria::IDENTIFICADOR),
                                 Token(")", Categoria::PAR_FINAL),
                                 Token("retorno", Categoria::PALABRA_RESERVADA),
                                 Token("0", Categoria::NUMERO)
                                 };
  EXPECT_EQ(tokens, expected);
}

// TODO: este test falla
TEST(lexicographicError, basicTest) {
  std::istrstream str("entero numero = +20; entero numro = -20;");

  FlexScanner scanner(str, std::cout);
  std::vector<Token> tokens;

  while (1) {
    auto token = scanner.get_token();
    if (token._atributo == END) break;
    tokens.push_back(token);
  }

  std::vector<Token> expected = {
                                 Token("entero", Categoria::PALABRA_RESERVADA),
                                 Token("numero", Categoria::IDENTIFICADOR),
                                 Token("=", Categoria::ASIGNAR),
                                 Token("+20", Categoria::NUMERO),
                                 Token("entero", Categoria::PALABRA_RESERVADA),
                                 Token("numro", Categoria::IDENTIFICADOR),
                                 Token("=", Categoria::ASIGNAR),
                                 Token("-20", Categoria::NUMERO)
                                 };
  EXPECT_EQ(tokens, expected);
}

// TODO: este test falla
TEST(lexicographicError1, basicTest) {
  std::istrstream str("entero numero = +20; entero num3ro = -20;");

  FlexScanner scanner(str, std::cout);
  std::vector<Token> tokens;

  while (1) {
    auto token = scanner.get_token();
    if (token._atributo == END) break;
    tokens.push_back(token);
  }

  std::vector<Token> expected = {
                                 Token("entero", Categoria::PALABRA_RESERVADA),
                                 Token("numero", Categoria::IDENTIFICADOR),
                                 Token("=", Categoria::ASIGNAR),
                                 Token("+20", Categoria::NUMERO),
                                 Token("entero", Categoria::PALABRA_RESERVADA),
                                 Token("num3ro", Categoria::ERROR),
                                 Token("=", Categoria::ASIGNAR),
                                 Token("-20", Categoria::NUMERO)
                                 };
  EXPECT_EQ(tokens, expected);
}

// TODO: este test falla
TEST(lexicographicError2, basicTest) {
  std::istrstream str("entero % = +20; entero ? = -20;");

  FlexScanner scanner(str, std::cout);
  std::vector<Token> tokens;

  while (1) {
    auto token = scanner.get_token();
    if (token._atributo == END) break;
    tokens.push_back(token);
  }

  std::vector<Token> expected = {
                                 Token("entero", Categoria::PALABRA_RESERVADA),
                                 Token("%", Categoria::ERROR),
                                 Token("=", Categoria::ASIGNAR),
                                 Token("+20", Categoria::NUMERO),
                                 Token("entero", Categoria::PALABRA_RESERVADA),
                                 Token("?", Categoria::ERROR),
                                 Token("=", Categoria::ASIGNAR),
                                 Token("-20", Categoria::NUMERO)
                                 };
  EXPECT_EQ(tokens, expected);
}


int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
