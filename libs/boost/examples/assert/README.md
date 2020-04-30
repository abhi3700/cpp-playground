# Assert using Boost library
## Methods:
* `BOOST_ASSERT`:
	- gives 
		+ nothing if the expression is _true_.
		+ the error (without message) if the expression is _false_.
	- syntax: `BOOST_ASSERT(expr)`
	- [example](./assert.cpp)
* `BOOST_ASSERT_MSG`:
	- gives:
		+ nothing if the expression is _true_.
		+ the error (with custom message) if the expression is _false_.
	- syntax: `BOOST_ASSERT_MSG(expr, msg)`
	- [example](./assert_msg.cpp)
* `BOOST_VERIFY`:
	- gives:
		+ nothing if the expression is evaluated correctly.
		+ the error (without message) if the expression is NOT VALID.
	- syntax: `BOOST_VERIFY(expr)`
	- [example](./verify.cpp)
* `BOOST_ASSERT_MSG`:
	- gives:
		+ nothing if the expression is evaluated correctly.
		+ the error (with custom message) if the expression is NOT VALID.
	- syntax: `BOOST_ASSERT_MSG(expr, msg)`
	- [example](./verify_msg.cpp)

* Using macros: To disable, mention before `#include <boost/assert.hpp>` line in the source/header file. [example](./assert_enable_disable.cpp)
	- `#define BOOST_DISABLE_ASSERTS`: disable assert methods
	- `#define NDEBUG`: disable assert methods
	- `#define BOOST_ENABLE_ASSERTS`: enable assert methods. Enabled by default.

> It affects both the `assert` & `verify` (with/without msg) 

* `assert_custom_func`
	- gives:
		+ nothing if the expression is _true_.
		+ the error (with custom message) if the expression is _false_.
	- doesn't use any library
	- arg-1: bool expression
	- arg-2: lambda func

