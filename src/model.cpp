#include "model.h"

// const std::list<double>& s21::Model::GetInfixExpression() {
//   return this->infix_expression;
// }

s21::ErrorsType s21::Model::ConvertStrExpressionToList(
    const std::string& expression) {
  this->expression_ = expression;
  // std::string_view buffer_lexems;
  // int counter_row = 0;

  for (int counter_row = 0; counter_row < this->expression_.length();
       ++counter_row) {
    if (this->expression_[counter_row] >= 48 &&
        this->expression_[counter_row] <= 57) {
      int start_counter = counter_row;
      while (this->expression_[counter_row] >= 48 &&
             this->expression_[counter_row] <= 57) {
        counter_row++;
      }
      std::string_view buffer{expression_[start_counter],
                              counter_row - start_counter};
      this->infix_expression.push_back(buffer);
    }
    // } else if (this->expression_[counter_row] == 40) {
    //   this->infix_expression.push_back(buffer_lexems);

    //   this->infix_expression.push_back(this->expression_[counter_row]);
    // } else if (this->expression_[counter_row] == 41) {
    //   this->infix_expression.push_back(buffer_lexems);
    //   buffer_lexems.clear();
    //   this->infix_expression.push_back(this->expression_[counter_row]);
    // } else if (this->expression_[counter_row] == 42 ||
    //            this->expression_[counter_row] == 43 ||
    //            this->expression_[counter_row] == 45 ||
    //            this->expression_[counter_row] == 47 ||
    //            this->expression_[counter_row] == 94) {
    //   this->infix_expression.push_back(buffer_lexems);
    //   buffer_lexems.clear();
    //   this->infix_expression.push_back(this->expression_[counter_row]);
    // } else if (this->expression_[counter_row] == 88 ||
    //            this->expression_[counter_row] == 120) {
    //   this->infix_expression.push_back(this->expression_[counter_row]);
    // } else {
    //   buffer_lexems.push_back(this->expression_[counter_row]);
    // }

    // std::string buffer_lexems;
    // for (const char& symbol : expression) {
    //   if (symbol >= 48 && symbol <= 57) {
    //     buffer_lexems.push_back(symbol);
    //   } else if (symbol == 40) {
    //     this->infix_expression.push_back(std::stod(buffer_lexems));
    //     buffer_lexems.clear();
    //     this->infix_expression.push_back(symbol);
    //   } else if (symbol == 41) {
    //     this->infix_expression.push_back(std::stod(buffer_lexems));
    //     buffer_lexems.clear();
    //     this->infix_expression.push_back(symbol);
    //   } else if (symbol == 42 || symbol == 43 || symbol == 45 || symbol ==
    //   47
    //   ||
    //              symbol == 94) {
    //     this->infix_expression.push_back(std::stod(buffer_lexems));
    //     buffer_lexems.clear();
    //     this->infix_expression.push_back(symbol);
    //   } else if (symbol == 88 || symbol == 120) {
    //     this->infix_expression.push_back(symbol);
    //   } else {
    //     buffer_lexems.push_back(symbol);
    //   }
  }
  // infix_expression.push_back(std::stod(buffer_lexems));
  return ErrorsType::NO_ERRORS;
};

// s21::ErrorsType s21::Model::SetExpression(std::string& new_expression) {
//   this->expression_ = std::move(new_expression);
//   ErrorsType check_error =
//   this->ConvertStrExpressionToList(this->expression_);
//   //   ErrorsType check_error = this->CheckCorrectExpression(expression);
//   //   if (check_error == ErrorsType::NO_ERRORS) {
//   //     return this->InfixExpressionToRPN();
//   //   }
//   return check_error;
// }
