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
                                 Token("=", Categoria::ASSIGN),
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
                                 Token("=", Categoria::ASSIGN),
                                 Token("b", Categoria::IDENTIFICADOR),
                                 Token("c", Categoria::IDENTIFICADOR),
                                 Token("=", Categoria::ASSIGN),
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
                                 Token("=", Categoria::ASSIGN),
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

  std::vector<Token> expected = {Token("entero", Categoria::RESERV_WORD),
                                 Token("main", Categoria::RESERV_WORD),
                                 Token("(", Categoria::PAR_BEGIN),
                                 Token(")", Categoria::PAR_END),
                                 Token("{", Categoria::CUR_BRACKET_BEGIN),
                                 Token("entero", Categoria::RESERV_WORD),
                                 Token("a", Categoria::IDENTIFICADOR),
                                 Token("=", Categoria::ASSIGN),
                                 Token("b", Categoria::IDENTIFICADOR),
                                 Token("}", Categoria::CUR_BRACKET_END)
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
                                 Token("==", Categoria::RELOP),
                                 Token("b", Categoria::IDENTIFICADOR),
                                 Token("a", Categoria::IDENTIFICADOR),
                                 Token("!=", Categoria::RELOP),
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

  std::vector<Token> expected = {Token("entero", Categoria::RESERV_WORD),
                                 Token("a", Categoria::IDENTIFICADOR),
                                 Token("=", Categoria::ASSIGN),
                                 Token("5", Categoria::NUMERO),
                                 Token("+", Categoria::SUM_OP),
                                 Token("(", Categoria::PAR_BEGIN),
                                 Token("3", Categoria::NUMERO),
                                 Token("*", Categoria::MUL_OP),
                                 Token("2", Categoria::NUMERO),
                                 Token(")", Categoria::PAR_END)
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

  std::vector<Token> expected = {Token("entero", Categoria::RESERV_WORD),
                                 Token("a", Categoria::IDENTIFICADOR),
                                 Token("=", Categoria::ASSIGN),
                                 Token("5", Categoria::NUMERO),
                                 Token("/", Categoria::DIV_OP),
                                 Token("(", Categoria::PAR_BEGIN),
                                 Token("3", Categoria::NUMERO),
                                 Token("/", Categoria::DIV_OP),
                                 Token("2", Categoria::NUMERO),
                                 Token(")", Categoria::PAR_END)
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

  std::vector<Token> expected = {Token("entero", Categoria::RESERV_WORD),
                                 Token("a", Categoria::IDENTIFICADOR),
                                 Token("=", Categoria::ASSIGN),
                                 Token("5", Categoria::NUMERO),
                                 Token("/", Categoria::DIV_OP),
                                 Token("(", Categoria::PAR_BEGIN),
                                 Token("3", Categoria::NUMERO),
                                 Token("/", Categoria::DIV_OP),
                                 Token("2", Categoria::NUMERO),
                                 Token(")", Categoria::PAR_END),

                                 Token("entero", Categoria::RESERV_WORD),
                                 Token("b", Categoria::IDENTIFICADOR),
                                 Token("=", Categoria::ASSIGN),
                                 Token("20", Categoria::NUMERO),
                                 Token("/", Categoria::DIV_OP),
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
                                 Token("==", Categoria::RELOP),
                                 Token("b", Categoria::IDENTIFICADOR),
                                 Token("d", Categoria::IDENTIFICADOR),
                                 Token("<", Categoria::RELOP),
                                 Token("e", Categoria::IDENTIFICADOR),
                                 Token("(", Categoria::PAR_BEGIN),
                                 Token("d", Categoria::IDENTIFICADOR),
                                 Token(">=", Categoria::RELOP),
                                 Token("f", Categoria::IDENTIFICADOR),
                                 Token(")", Categoria::PAR_END)
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
                                 Token("si", Categoria::RESERV_WORD),
                                 Token("(", Categoria::PAR_BEGIN),
                                 Token("a", Categoria::IDENTIFICADOR),
                                 Token("==", Categoria::RELOP),
                                 Token("b", Categoria::IDENTIFICADOR),
                                 Token("d", Categoria::IDENTIFICADOR),
                                 Token("<", Categoria::RELOP),
                                 Token("e", Categoria::IDENTIFICADOR),
                                 Token("(", Categoria::PAR_BEGIN),
                                 Token("d", Categoria::IDENTIFICADOR),
                                 Token(">=", Categoria::RELOP),
                                 Token("f", Categoria::IDENTIFICADOR),
                                 Token(")", Categoria::PAR_END),
                                 Token(")", Categoria::PAR_END),
                                 Token("{", Categoria::CUR_BRACKET_BEGIN),
                                 Token("retorno", Categoria::RESERV_WORD),
                                 Token("1", Categoria::NUMERO),
                                 Token("}", Categoria::CUR_BRACKET_END)
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
                                 Token("sin_tipo", Categoria::RESERV_WORD),
                                 Token("fib", Categoria::IDENTIFICADOR),
                                 Token("(", Categoria::PAR_BEGIN),
                                 Token(")", Categoria::PAR_END),
                                 Token("{", Categoria::CUR_BRACKET_BEGIN),
                                 Token("si", Categoria::RESERV_WORD),
                                 Token("(", Categoria::PAR_BEGIN),
                                 Token("a", Categoria::IDENTIFICADOR),
                                 Token("==", Categoria::RELOP),
                                 Token("b", Categoria::IDENTIFICADOR),
                                 Token("d", Categoria::IDENTIFICADOR),
                                 Token("<", Categoria::RELOP),
                                 Token("e", Categoria::IDENTIFICADOR),
                                 Token("(", Categoria::PAR_BEGIN),
                                 Token("d", Categoria::IDENTIFICADOR),
                                 Token(">=", Categoria::RELOP),
                                 Token("f", Categoria::IDENTIFICADOR),
                                 Token(")", Categoria::PAR_END),
                                 Token(")", Categoria::PAR_END),
                                 Token("{", Categoria::CUR_BRACKET_BEGIN),
                                 Token("retorno", Categoria::RESERV_WORD),
                                 Token("1", Categoria::NUMERO),
                                 Token("}", Categoria::CUR_BRACKET_END),
                                 Token("}", Categoria::CUR_BRACKET_END)
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
                                 Token("sin_tipo", Categoria::RESERV_WORD),
                                 Token("fib", Categoria::IDENTIFICADOR),
                                 Token("(", Categoria::PAR_BEGIN),
                                 Token(")", Categoria::PAR_END),
                                 Token("{", Categoria::CUR_BRACKET_BEGIN),
                                 Token("retorno", Categoria::RESERV_WORD),
                                 Token("1", Categoria::NUMERO),
                                 Token("}", Categoria::CUR_BRACKET_END)
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
                                 Token("si", Categoria::RESERV_WORD),
                                 Token("(", Categoria::PAR_BEGIN),
                                 Token("a", Categoria::IDENTIFICADOR),
                                 Token(")", Categoria::PAR_END),
                                 Token("retorno", Categoria::RESERV_WORD),
                                 Token("1", Categoria::NUMERO),
                                 Token("sino", Categoria::RESERV_WORD),
                                 Token("(", Categoria::PAR_BEGIN),
                                 Token("b", Categoria::IDENTIFICADOR),
                                 Token(")", Categoria::PAR_END),
                                 Token("retorno", Categoria::RESERV_WORD),
                                 Token("0", Categoria::NUMERO)
                                 };
  EXPECT_EQ(tokens, expected);
}


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
                                 Token("entero", Categoria::RESERV_WORD),
                                 Token("numero", Categoria::IDENTIFICADOR),
                                 Token("=", Categoria::ASSIGN),
                                 Token("+20", Categoria::NUMERO),
                                 Token("entero", Categoria::RESERV_WORD),
                                 Token("numro", Categoria::IDENTIFICADOR),
                                 Token("=", Categoria::ASSIGN),
                                 Token("-20", Categoria::NUMERO)
                                 };
  EXPECT_EQ(tokens, expected);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
