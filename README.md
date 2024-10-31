# Compiler Lab Programs

This repository contains a collection of programs for a compiler lab course. Each program is designed to demonstrate various compiler construction techniques, such as lexical analysis and parsing, using tools like **Lex**.

## Table of Contents
- [About](#about)
- [Programs](#programs)
- [Installation](#installation)
  - [Installing Lex](#installing-lex)
    - [Windows](#windows)
    - [Linux](#linux)
    - [macOS](#macos)
- [Usage](#usage)

## About

Lex is a tool used to generate lexical analyzers, also known as "scanners" or "tokenizers." It reads a file containing lexical rules and generates C code that can identify tokens based on those rules. This repository includes several programs that use Lex to analyze and process input files as part of a compiler construction workflow.

## Programs

1. **Lexical Analyzer for Arithmetic Expressions**  
   This program reads an expression and breaks it down into operators, identifiers, and constants.

2. **Identifier Validation**  
   A lexical analyzer program that checks if a given input string is a valid identifier in C.

3. **Preprocessor Directive Recognizer**  
   Recognizes C preprocessor directives (e.g., `#include`, `#define`) in a file.

... (Include other programs as relevant to your repository)

## Installation

### Installing Lex

Lex is widely used on Unix-like systems, and can be installed as follows on different platforms:

#### Windows

Lex isn't natively supported on Windows, but you can use **Cygwin** or **WSL (Windows Subsystem for Linux)** to run Lex.

1. **Using Cygwin**:
   - Install [Cygwin](https://www.cygwin.com/) and select `flex` (a Lex-compatible tool) during setup.
   - Open Cygwin and confirm installation by running `flex --version`.

2. **Using WSL**:
   - Enable WSL and install a Linux distribution from the Microsoft Store.
   - Open the Linux terminal and install Flex using the Linux installation commands below.

#### Linux

Most Linux distributions offer `flex` as the standard tool for Lex.

```bash
sudo apt-get update      # For Debian/Ubuntu-based distributions
sudo apt-get install flex
