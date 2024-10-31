# Compiler Lab Programs

This repository is a collection of programs developed for compiler construction, covering essential phases from lexical analysis to code optimization. Each program demonstrates a fundamental component of the compilation process, using tools like **Lex** for lexical analysis.

## Table of Contents
- [About](#about)
- [Programs Included](#programs-included)
- [Installation](#installation)
  - [Installing Lex](#installing-lex)
- [Usage](#usage)

## About

Compiler construction is crucial for translating high-level programming languages into machine-level code. This repository includes various programs to illustrate the phases of compilation, from lexical analysis through code generation and optimization. 

## Programs Included

1. **Lexical Analyzer** - Performs lexical analysis on input source code.
2. **Syntax Analyzer** - Parses tokens into syntactical structures (implemented with recursive descent parsing).
3. **DFA (Deterministic Finite Automaton)** - Recognizes patterns for tokens.
4. **Recursive Descent Parser** - Implements a top-down parsing technique for syntax analysis.
5. **Operator Precedence Parser** - Analyzes operator precedence in expressions.
6. **Intermediate Code Generator** - Transforms syntax trees into intermediate code representations.
7. **Code Generator** - Produces target code from intermediate code.
8. **Code Optimizer** - Refines the code for improved performance.
9. **Lex Program Examples** - Various Lex-based programs to demonstrate lexical analysis.

## Installation

### Installing Lex

Lex (via Flex) is required for running lexical analysis programs. Follow these steps to install Lex on various platforms.

#### Windows

1. **Using Cygwin**:
   - Install [Cygwin](https://www.cygwin.com/) and select the `flex` package during setup.
   - Open Cygwin and verify installation by running `flex --version`.

2. **Using WSL (Windows Subsystem for Linux)**:
   - Enable WSL and install a Linux distribution from the Microsoft Store.
   - Open the Linux terminal in WSL and follow the Linux instructions below.

#### Linux

Most Linux distributions include Flex in their repositories. For example, on Debian/Ubuntu:

```bash
sudo apt-get update         # For Debian/Ubuntu-based distributions
sudo apt-get install flex
