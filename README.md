# HTML Validator

A C++ program that validates basic HTML files by checking tag structure using a stack data structure implemented with a linked list.

## What It Does

- Parses an HTML file and extracts all tags
- Validates opening, closing, and self-closing (empty) tags against a set of allowed HTML elements
- Uses a stack to ensure tags are properly nested (no crossing tags)
- Reports whether the HTML file is valid or identifies the specific error

## Supported HTML Tags

`html`, `head`, `body`, `p`, `br`, `li`, `h1`, `h2`, `ul`, `ol`

## Tech Stack

- **Language:** C++ (C++14)
- **Data Structures:** Singly Linked List, Stack (built on linked list)
- **Build System:** Make
- **Concepts:** File I/O, templates, exception handling, stack-based validation

## Project Structure

```
HTML-Validator/
├── validator.cpp     # Main program with tag validation logic and file parsing
├── SLLStack.h        # Singly Linked List template class (used as stack backend)
├── LinkedStack.h     # Stack ADT built on top of SLL
├── testfile.txt      # Sample HTML file for testing
└── Makefile          # Build configuration
```

## Getting Started

### Prerequisites

- C++ compiler with C++14 support (g++ or clang++)
- `make` (optional, or compile manually)

### Build & Run

Using Make:

```bash
git clone https://github.com/Aaryan018/HTML-Validator.git
cd HTML-Validator
make
./test
```

Manual compilation:

```bash
g++ -std=c++14 -pedantic -Wall -Wextra validator.cpp -o test
./test
```

### Using Your Own HTML File

Replace `testfile.txt` with your own HTML file, or update the filename in `validator.cpp` (line 149).

## How It Works

1. Opens and reads `testfile.txt` character by character
2. Extracts content between `<` and `>` as tags
3. Classifies each tag as:
   - **Opening tag** (e.g., `<html>`) — pushed onto the stack
   - **Closing tag** (e.g., `</html>`) — compared with the top of the stack; if matching, popped; otherwise, "Tags are Crossing" error
   - **Empty/self-closing tag** (e.g., `<br />`) — ignored (no stack operation)
4. If all tags match and the file is fully processed, reports "File is Valid"

## Error Cases

- **Invalid Tag:** A tag name not in the supported list
- **Tags are Crossing:** Closing tag does not match the most recent opening tag (improper nesting)

## Example

**Input (`testfile.txt`):**
```html
<html>
<head />
<body>
<p /> <h2>hello world!</h2>
<ol><li>1</li>
</ol>
</body>
</html>
```

**Output:**
```
File is Valid
```
