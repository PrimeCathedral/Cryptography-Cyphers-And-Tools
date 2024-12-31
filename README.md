# Modular Arithmetic and Extended GCD Library

This repository contains a C++ library for performing modular arithmetic operations, including modular exponentiation and calculating modular inverses, with an implementation of the Extended Euclidean Algorithm. The library leverages the Boost Multiprecision library for handling large integers.

---

## Features

- Modular arithmetic operations:
  - Modular addition, subtraction, multiplication, and exponentiation.
  - Modular inverse computation.
- Implementation of the Extended Euclidean Algorithm.
- Handles both positive and negative integers in modular arithmetic.
- Supports arbitrarily large integers using `boost::multiprecision::cpp_int`.
- Comprehensive unit tests written using Google Test.

---

## Project Structure

```plaintext
.
├── src/                 # Source code for the library
│   ├── Utilities.cpp    # Core modular arithmetic and GCD implementations
│   ├── Utilities.h      # Header file for the library
├── tests/               # Unit tests for the library
│   ├── UtilitiesTests.cpp # Google Test cases
├── CMakeLists.txt       # Build configuration using CMake
├── README.md            # This readme file
└── external/            # External dependencies (Boost)
```

---

## Dependencies

This project requires the following dependencies:
- **Boost Multiprecision**: For handling large integers.
- **Google Test**: For unit testing.

Install dependencies using your package manager, or ensure they are available in the `external/` directory.

---

## Build Instructions

To build the project, use **CMake**. Follow these steps:

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/your-repo-name.git
   cd your-repo-name
   ```

2. Create a build directory and configure the project:
   ```bash
   mkdir build && cd build
   cmake ..
   ```

3. Build the project:
   ```bash
   make
   ```

4. Run the unit tests:
   ```bash
   ctest
   ```

---

## Usage

### Example: Modular Exponentiation

```cpp
#include "Utilities.h"
#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

int main() {
    using namespace Crypto;
    namespace mp = boost::multiprecision;

    mp::cpp_int base = 3;
    mp::cpp_int power = 5;
    mp::cpp_int mod = 7;

    mp::cpp_int result = Utilities::modularExponentiation(base, power, mod);
    std::cout << "Result: " << result << std::endl; // Output: 5

    return 0;
}
```

---

## Testing

Unit tests are implemented using **Google Test**. To run the tests:
```bash
cd build
ctest
```

Ensure that the `GTest` dependency is correctly installed or included in the project.

---

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.

---

## Contributing

Contributions are welcome! If you'd like to contribute:
1. Fork the repository.
2. Create a feature branch.
3. Submit a pull request with a detailed description of your changes.
```

---

### **Next Steps**
1. Customize the placeholder URLs and paths in the README (e.g., GitHub repository URL, contributor information).
2. Add any project-specific details or features if I missed something important.

Let me know if you’d like me to refine this further or assist with anything else! 🚀
