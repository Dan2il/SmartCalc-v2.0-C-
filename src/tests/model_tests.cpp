#include "tests.h"

TEST(tests_model, test_convert_str_to_list_1) {
  s21::Model model;
  std::string expr = "2+2";
  model.ConvertStrExpressionToList(expression);
  model.PrintInfix();
}
