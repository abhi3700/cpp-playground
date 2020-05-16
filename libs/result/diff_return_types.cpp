#include <iostream>
#include <result/include/result.hpp>

using result::Result;
using result::Ok;
using result::Err;
using std::string;


enum E1 
{
  bad,
};

enum E2
{
  horrible,
};

int main() {
  Result<Result<int, E1>, E2> res = Ok(Result<int, E1>{Err(E1::bad)});

  auto val = res.map([&] (Result<int, E1> r) {      // `map` will only call the closure for `Ok(Result<int, E1>)`
    // transform `Ok(Result<int, E1>)` into `Ok(Result<size_t, std::string>)`
    return r.map([] (int i) {
      return static_cast<size_t>(i);    // transforms from `int` to `size_t`
    }).map_err([] (E1 e1) {
      return string{"bad E1"};          // transforms from `E1` to `string`
    }); 
  }).map_err([] (E2 e2) {              // `map_err` will only call the closure for `Err(E2)
    return string{"horrible E2"};       // transforms from `E2` to `string`
  });

  // val now is of type ---> Result<Result<size_t, string>, string>


  std::cout << val.unwrap() << std::endl;

  return 0;
}