#include <iostream>
#include <list>
#include <string>
#include <string_view>

namespace s21 {

typedef enum {
  NO_ERRORS,
  NULL_POINTER,
  READ_INCORRECT_SYMBOL,
  INCORRECT_DATA,
  EMPTY_EXPRESSION,
  LONG_EXPRESSION,
  READ_EOF,
  COMPRASSION_ERROR,
  OTHER_ERROR
} ErrorsType;

class Model {
 public:
  Model() = default;

  ErrorsType ConvertStrExpressionToList(const std::string& expression);
  ErrorsType InfixExpressionToRPN();

  ErrorsType SetExpression(std::string& expression);

  ErrorsType CheckCorrectExpression(const std::string& expression);

  //   const std::string GetStringInfixExpresson();
  // const std::list<double>& GetInfixExpression();
  //   const std::list<double> GetRPNExpression();

  void PrintInfix() {
    for (auto lex : infix_expression) {
      std::cout << lex << std::endl;
    }
  }

  void Clear();

  ~Model() = default;

 private:
  std::string expression_;
  std::list<std::string_view> infix_expression;
  std::list<double> RPN_expression_;
  std::list<double> buffer_steck_;
  double result_expression_;
};
}  // namespace s21
