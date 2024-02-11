#include "model.h"

int main() {
  s21::Model model;
  std::string expression = "2 + 2";
  model.ConvertStrExpressionToList(expression);
  model.PrintInfix();
};
