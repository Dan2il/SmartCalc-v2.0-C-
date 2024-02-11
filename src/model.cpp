#include "model.h"

s21::ErrorsType s21::Model::ConvertStrExpressionToList(
    const std::string& expression) {
  std::string buffer_lexems;
  for (const char& symbol : expression) {
    if (symbol >= 48 && symbol <= 57) {
      buffer_lexems.push_back(symbol);
    } else if (symbol == 40) {
      this->infix_expression.push_back(std::stod(buffer_lexems));
      buffer_lexems.clear();
      this->infix_expression.push_back(symbol);
    }
  }
}

s21::ErrorsType s21::Model::SetExpression(std::string& new_expression) {
  this->expression_ = std::move(new_expression);
  ErrorsType check_error = this->ConvertStrExpressionToList(this->expression_);
  //   ErrorsType check_error = this->CheckCorrectExpression(expression);
  //   if (check_error == ErrorsType::NO_ERRORS) {
  //     return this->InfixExpressionToRPN();
  //   }
  return check_error;
}
