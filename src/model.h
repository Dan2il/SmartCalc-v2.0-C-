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
  ErrorsType ConvertStrExpressionToRPN(const std::string& pars_expr);

  ErrorsType InfixExpressionToRPN();

  ErrorsType SetExpression(std::string& expression);

  ErrorsType CheckCorrectExpression(const std::string& expression);

  //   const std::string GetStringInfixExpresson();
  // const std::list<double>& GetInfixExpression();
  //   const std::list<double> GetRPNExpression();

  void PrintInfix() {
    std::cout << "PrintInfix" << std::endl;
    for (auto lex : infix_expression) {
      std::cout << lex << std::endl;
    }
  }

  const std::list<std::string_view>& GetInfixExpression();
  void Clear();

  ~Model() = default;

 private:
  std::string expression_;
  std::list<std::string_view> infix_expression;
  std::list<std::string_view> RPN_expression_;
  std::list<std::string_view> buffer_steck_;
  double result_expression_;

  bool CheckNumber(const size_t counter_row);
  bool CheckBrackets(const size_t counter_row);
  bool CheckOperator(const size_t counter_row);
  bool CheckMod(const size_t counter_row);
  bool CheckFunction(const size_t counter_row);
  bool CheckLongFunction(const size_t counter_row);
  bool CheckX(const size_t counter_row);

  std::string_view GetNumber(size_t& counter_row);
  std::string_view GetLexems(size_t& counter_row, const size_t size_lexems);
};
}  // namespace s21
