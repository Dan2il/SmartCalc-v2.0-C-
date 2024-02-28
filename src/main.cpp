#include "model.h"

int main() {
  s21::Model model;
  std::string expression =
      "(2+2)-1*3/xmod7-(5-5)-cos(1) + sin(3)*tan(111111111)/ log(X) - "
      "(acos(5)*asin(654321)    *      atan(-54) / sqrt(16 + ln(5)) ) * (2 ^ "
      "2)";
  model.ConvertStrExpressionToList(expression);
  expression.clear();
  model.PrintInfix();
};
