#include <iostream>
#include <result/include/result.hpp>


using result::Result;
using result::Ok;
using result::Err;

using std::string;

auto Div(double x, double y) -> Result<double, string> {
  if(y == 0.0) {
    return Err(string{"Division by zero."});
  } else {
    return Ok(x/y);
  }
}

int main() {
  auto result1 = Div(100.0, 40.0);
  if(result1.is_ok()) {
    std::cout << result1.unwrap() << std::endl;
  }

  auto result2 = Div(100.0, 0.0);
  if(result2.is_err()) {
    std::cout << result2.unwrap_err() << std::endl;
  }

  return 0;
}