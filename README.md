# Simple Assembler

This is a simple assembler program written in C++ that reads assembly code from an input file, processes the instructions, and performs assembly tasks.

## Features

- Parses assembly instructions and data declarations.
- Generates machine code corresponding to each instruction.
- Supports various instructions such as load, store, arithmetic, branching, and input/output operations.

## Getting Started

### Prerequisites

- C++ compiler (supporting C++11 or later)
- Git (optional, for cloning the repository)

### Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/AhmedSehly20/Simple-Assembler.git
Compile the source code:
g++ -o assembler main.cpp

## Usage

1. Prepare your assembly code in a file named `input.txt`. An example input file is provided [here](example_input.txt).
2. Define instruction opcodes in a file named `instructions.txt`. An example instructions file is provided [here](example_instructions.txt).
3. Run the assembler:

   ```bash
   ./assembler
## Input Format

The input file should contain assembly code with instructions and data declarations. Each instruction should be on a separate line.

**Example input:**

```assembly
ORG 209
LDA X /ASFASF
STA Y /ASFA
CMA
ADD MIN
HLT
X, DEC 83
Y, DEC -23
MIN, HEX 0
END
## Instructions File

The instructions file should define opcode mappings for each instruction.

**Example instructions file:**

```plaintext
AND 0 OR 8
ADD 1 OR 9
LDA 2 OR A
STA 3 OR B
BUN 4 OR C
BSA 5 OR D
ISZ 6 OR E
CLA 7800
...

## Contributing

Contributions are welcome! If you find any bugs or have suggestions for improvements, please open an issue or submit a pull request.
