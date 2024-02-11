#include <gtest/gtest.h>

#include <list>
#include <string>
#include <vector>

#include "../model.h"

// bool CheckCorrectParsExpression(std::string expression,
//                                 const std::vector<double>& correct_data) {
//   s21::Model model;
//   model.ConvertStrExpressionToList(expression);
//   const std::list<double> inf_expr = model.GetInfixExpression();
//   auto it = inf_expr.begin();

//   for (const double& correct_lex : correct_data) {
//     if (correct_lex != *it++) {
//       return false;
//     }
//   }
//   return true;
// }