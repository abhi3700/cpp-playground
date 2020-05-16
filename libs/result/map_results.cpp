/*
        // Maps a Result<T, E> to Result<U, E> by
        // applying a function to a contained Ok value,
        // leaving an Err value untouched.
        //
        // This function can be used to compose the results of two functions.

*/

#include <iostream>
#include <result/include/result.hpp>

using result::Result;
using result::Err;
using result::Ok;

using std::string;

Result<int, string>
parse(const string& message) {
  try {
    return Ok(std::stoi(message));
  }
  catch(const std::exception& e) {
    return Err(string(e.what()));
  }
}


Result<int, string> 
multiply(const string& first_string, const string& second_string) {
  return parse(first_string).and_then([&](auto first) {
    return parse(second_string).map([&](auto second) {return first*second;});
  });
}

int main() {
  auto res1 = multiply("10", "20");
  std::cout << res1 << std::endl;

  auto res2 = multiply("ab", "20");
  std::cout << res2 << std::endl;

  return 0;
}