#include "tests.h"

TEST(tests_model, test_convert_str_to_list_1) {
  s21::Model model;
  std::string expr =
      "(2+2)-1*3/xmod7-(5-5)-cos(1) + sin(3)*tan(111111111)/ log(X) - "
      "(acos(5)*asin(654321)    *      atan(-54) / sqrt(16 + ln(5)) ) * (2 ^ "
      "2)";
  model.ConvertStrExpressionToList(expr);
  std::list<std::string> answer = {
      "(",  "2",    "+",   "2",      ")", "-",         "1",    "*",   "3",
      "/",  "x",    "mod", "7",      "-", "(",         "5",    "-",   "5",
      ")",  "-",    "cos", "(",      "1", ")",         "+",    "sin", "(",
      "3",  ")",    "*",   "tan",    "(", "111111111", ")",    "/",   "log",
      "(",  "X",    ")",   "-",      "(", "acos",      "(",    "5",   ")",
      "*",  "asin", "(",   "654321", ")", "*",         "atan", "(",   "-",
      "54", ")",    "/",   "sqrt",   "(", "16",        "+",    "ln",  "(",
      "5",  ")",    ")",   ")",      "*", "(",         "2",    "^",   "2",
      ")"};
  auto it_infix = model.GetInfixExpression().begin();

  for (std::string lex : answer) {
    std::cout << "lex: " << lex << std::endl;
    std::cout << "it_infix: " << *it_infix << std::endl;
    bool check = false;
    if (lex == static_cast<std::string>(*it_infix)) {
      check = true;
    }
    EXPECT_TRUE(check);
    it_infix++;
    if (!check) {
      break;
    }
  }
}
