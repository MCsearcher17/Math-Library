# CALCULATER

A C-based mathematical library and calculator menu project with custom implementations of common arithmetic, trigonometric, logarithmic, and combinatorial functions.

## Features

- Basic arithmetic operations
- Powers, roots, absolute values, averages, and modulo
- Factorials, permutations, and combinations
- Exponential and logarithmic functions
- Pythagorean hypotenuse calculation
- Trigonometric and inverse-trigonometric functions
- Degree/radian conversion
- Newton-Raphson and Taylor-series approximations
- Console menu display

## Project Structure

```text
CALCULATER/
├── mathtry.c                # Mathematical function implementations
├── mathtry.h                # Mathematical function declarations
├── menu.c                   # Console menu implementation
├── menu.h                   # Menu declarations
├── arcsin_function_attemp.c # Standalone inverse-trigonometric demonstration
└── arcsin_function_attemp.exe
```

## Requirements

- A C compiler such as GCC or Clang
- A Windows or Unix-like terminal
- The C standard library

## Building

Compile the library and menu from the repository root:

```bash
gcc -Wall -Wextra -std=c99 \
    CALCULATER/mathtry.c \
    CALCULATER/menu.c \
    -o calculator
```

To compile the standalone trigonometric demonstration:

```bash
gcc -Wall -Wextra -std=c99 \
    CALCULATER/arcsin_function_attemp.c \
    -o arcsin-demo
```

Run it with:

```bash
./arcsin-demo
```

On Windows:

```text
arcsin-demo.exe
```

## Usage

Include `mathtry.h` to use the library functions:

```c
#include <stdio.h>
#include "CALCULATER/mathtry.h"

int main(void) {
    printf("Square root: %lf\n", sqrt(16.0));
    printf("Sine: %lf\n", sinus(0.5));
    printf("Combination: %llu\n", combination(5, 2));

    return 0;
}
```

Compile with:

```bash
gcc example.c CALCULATER/mathtry.c -I CALCULATER -o example
```

## Available Functions

### Arithmetic

- `sum`
- `subtract`
- `multiply`
- `divide`
- `mod`
- `inverse`

### Powers and Roots

- `squared`
- `cubed`
- `power`
- `sqrt`
- `exp_e`

### Other Mathematics

- `absolute`
- `abs_diff`
- `average`
- `factorial`
- `ln`
- `log`
- `hypo`

### Trigonometry

- `degree_to_radian`
- `radian_to_degree`
- `sinus`
- `cosinus`
- `tangent`
- `cotangent`
- `secant`
- `cosecant`
- `arcsinus`
- `arccosinus`
- `arctangent`
- `arccotangent`
- `arcsecant`
- `arccosecant`

### Combinatorics

- `permutation`
- `combination`

## Notes

- Trigonometric functions generally operate with angles in radians.
- Several functions use iterative approximations rather than standard math-library implementations.
- Invalid operations print math errors to the terminal.
- This project is experimental and may contain typo-based identifiers or approximation edge cases.
- A function named `sqrt` is implemented locally instead of relying on `math.h`.

## Potential Improvements

- Integrate functions into a complete interactive calculator program
- Add input validation and consistent error return values
- Reduce floating-point approximation errors
- Use C standard-library math functions where appropriate
- Fix spelling and naming inconsistencies
- Add unit tests
- Remove compiled `.exe` files from source control
- Add a build system such as Make or CMake

## License

No license is currently specified for this repository.
