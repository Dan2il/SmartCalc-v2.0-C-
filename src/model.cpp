#include "model.h"

bool s21::Model::CheckNumber(const size_t counter_row) {
  if (this->expression_[counter_row] > 47 &&
      this->expression_[counter_row] < 58) {
    return true;
  }
  return false;
}

bool s21::Model::CheckBrackets(const size_t counter_row) {
  if (this->expression_[counter_row] == 40 ||
      this->expression_[counter_row] == 41) {
    return true;
  }
  return false;
}

bool s21::Model::CheckOperator(const size_t counter_row) {
  if (this->expression_[counter_row] == 42 ||
      this->expression_[counter_row] == 43 ||
      this->expression_[counter_row] == 45 ||
      this->expression_[counter_row] == 47 ||
      this->expression_[counter_row] == 94) {
    return true;
  }
  return false;
}

bool s21::Model::CheckMod(const size_t counter_row) {
  if (std::string_view(this->expression_).substr(counter_row, 3) == "mod") {
    return true;
  }
  return false;
}

bool s21::Model::CheckFunction(const size_t counter_row) {
  if (std::string_view(expression_).substr(counter_row, 3) == "cos" ||
      std::string_view(expression_).substr(counter_row, 3) == "sin" ||
      std::string_view(expression_).substr(counter_row, 3) == "tan" ||
      std::string_view(expression_).substr(counter_row, 3) == "log") {
    return true;
  }
  return false;
}

std::string_view s21::Model::GetNumber(size_t& counter_row) {
  int start_counter = counter_row;
  int counter_symbol = 0;
  while (this->expression_[counter_row] > 47 &&
         this->expression_[counter_row] < 58) {
    counter_row++;
    counter_symbol++;
  }
  return std::string_view(expression_).substr(start_counter, counter_symbol);
}

std::string_view s21::Model::GetBrackets(size_t& counter_row) {
  return std::string_view(expression_).substr(counter_row, 1);
}

s21::ErrorsType s21::Model::ConvertStrExpressionToList(
    const std::string& pars_expr) {
  this->expression_ = pars_expr;

  for (size_t counter_row = 0; counter_row < this->expression_.length();
       ++counter_row) {
    if (CheckNumber(counter_row)) {
      this->infix_expression.push_back(GetNumber(counter_row));
    } else if (CheckBrackets(counter_row)) {
      this->infix_expression.push_back(GetBrackets(counter_row));
    } else if (CheckOperator(counter_row)) {
      this->infix_expression.push_back(
          std::string_view(expression_).substr(counter_row, 1));
    } else if (this->expression_[counter_row] == 88 ||
               this->expression_[counter_row] == 120) {
      this->infix_expression.push_back(
          std::string_view(expression_).substr(counter_row, 1));
    } else if (CheckMod(counter_row) || CheckFunction(counter_row)) {
      this->infix_expression.push_back(
          std::string_view(expression_).substr(counter_row, 3));
      counter_row += 2;
    } else if (std::string_view(expression_).substr(counter_row, 4) == "acos" ||
               std::string_view(expression_).substr(counter_row, 4) == "asin" ||
               std::string_view(expression_).substr(counter_row, 4) == "atan" ||
               std::string_view(expression_).substr(counter_row, 4) == "sqrt") {
      this->infix_expression.push_back(
          std::string_view(expression_).substr(counter_row, 4));
      counter_row += 3;
    } else if (std::string_view(expression_).substr(counter_row, 2) == "ln") {
      this->infix_expression.push_back(
          std::string_view(expression_).substr(counter_row, 2));
      counter_row += 1;
    }
  }
  return ErrorsType::NO_ERRORS;
};
