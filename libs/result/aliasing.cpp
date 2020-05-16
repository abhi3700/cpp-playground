/*
      Use case
      - many mathematical function at a time
      E.g. log(sqrt(x/y)) in this case

*/

#include <iostream>
#include <cmath>
#include <result/include/result.hpp>

enum MathError
{
  division_by_zero,
  negative_zero_log,
  non_negative_sqrt
};

// using namespace result;
using result::Result;
using result::Ok;
using result::Err;

using math_result = Result<double, MathError>;

auto Div(double x, double y) -> math_result {
  if(y == 0) {
    return Err(MathError::division_by_zero);
  }
  else {
    return Ok(x / y);
  }
}

auto Sqrt(double x) -> math_result {
  if(x < 0) {
    return Err(MathError::non_negative_sqrt);
  }
  else {
    return Ok(sqrt(x));
  }
}

auto Log(double x) -> math_result {
  if(x <= 0) {
    return Err(MathError::negative_zero_log);
  }
  else {
    return Ok(log(x));
  }
}

auto Op(double x, double y) -> double {
  return Div(x, y)
  .and_then(Sqrt)
  .and_then(Log)
  .unwrap();
}

int main() {
  std::cout << Op(4.0, 3.0) << std::endl;
  std::cout << Op(4.0, 0.0) << std::endl;
  std::cout << Op(4.0, -3.0) << std::endl;

  return 0;
}
