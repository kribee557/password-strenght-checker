# 🔐 Password Strength Checker in C

A command-line Password Strength Checker built using the C programming language. It analyzes password length, character types, and common-password matches to provide a basic strength estimate.

This project is designed to practice fundamental C concepts, including functions, arrays, pointers, strings, loops, conditional statements, and input handling.

## ✨ Features

- **Password Length Analysis:** Calculates the length of the entered password.
- **Character Type Detection:** Checks for uppercase letters, lowercase letters, digits, and special characters.
- **Common Password Detection:** Identifies passwords matching a built-in list of 10 commonly guessed passwords.
- **Case-Insensitive Matching:** Detects variations such as `password123` and `Password123`.
- **Strength Estimation:** Classifies passwords as Weak, Moderate, or Strong based on a simple scoring system.
- **Empty Input Validation:** Rejects empty passwords.
- **Terminal-Based Interface:** Displays the analysis and strength estimate in the terminal.

## 🛠️ Technologies Used

- **Language:** C
- **C Standard:** C11
- **Libraries:** `stdio.h`, `string.h`, `ctype.h`
- **Compiler:** GCC

## 📋 Requirements

- GCC or another compatible C compiler
- A terminal or command prompt
- Git (optional, for cloning the repository)

## 🚀 How to Run

### 1. Clone the repository

```bash
git clone https://github.com/YOUR-USERNAME/password-strength-checker.git
```

Replace `YOUR-USERNAME` with your GitHub username.

### 2. Open the project directory

```bash
cd password-strength-checker
```

### 3. Compile the program

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic password_checker.c -o password_checker
```

### 4. Run the program

**Windows PowerShell:**

```powershell
.\password_checker.exe
```

**Linux/macOS:**

```bash
./password_checker
```

## 💻 Example Output

```text
=== Password Strength Checker ===
Enter a test password: Password123

--- Analysis ---
Length: 11 characters
Uppercase letter: Yes
Lowercase letter: Yes
Numbers: Yes
Special characters: No
Common password detected: Yes - avoid this password

Strength: Weak

Note: This is a basic educational estimate.
It does not test against known leaked passwords.
```

## 🧪 Test Cases

| Test Input | Expected Result |
|---|---|
| `password` | Common password detected; Weak |
| `password123` | Common password detected; Weak |
| `Password123` | Common password detected; Weak |
| `qwerty` | Common password detected; Weak |
| `abc` | Not common; Weak due to length |
| `Tr0ub4dor!` | Not in the list; strength depends on the score |
| Empty input | Error message and program exits |
| `Password123!` | Not an exact match in the common-password list |

These are suggested manual tests, not an automated test suite.

## 🧠 C Concepts Practiced

- Functions and return values
- Arrays of strings and pointers
- `for` and `while` loops
- Conditional statements (`if`, `else if`, `else`)
- String functions: `strlen()` and `strcspn()`
- Character functions: `isupper()`, `islower()`, `isdigit()`, `ispunct()`, and `tolower()`
- `sizeof()` for calculating array element count
- Basic input validation
- Password scoring using conditional logic

## 📊 How the Scoring Works

The program adds one point for each condition met:

| Condition | Points |
|---|---:|
| Length is at least 8 characters | +1 |
| Length is at least 12 characters | +1 |
| Contains an uppercase letter | +1 |
| Contains a lowercase letter | +1 |
| Contains a digit | +1 |
| Contains a special character | +1 |

The maximum score is 6.

- **Weak:** A common password, fewer than 8 characters, or a score of 2 or less.
- **Strong:** At least 12 characters and a score of 5 or more, provided the password is not on the common-password list.
- **Moderate:** Other passwords that do not meet the Weak or Strong conditions.

A common password is always classified as Weak.

## ⚠️ Limitations

- The common-password list contains only 10 entries.
- Matching is case-insensitive but requires an exact match.
- The program does not check leaked-password databases.
- The scoring system is a basic educational estimate, not a reliable measure of real-world security.
- The current code rejects empty input but does not explicitly detect input that exceeds the 255-character buffer capacity.

**Security note:** Use sample passwords for testing. Never enter real account passwords into an educational program.

## 🔮 Future Improvements

- Expand the common-password list.
- Add automated unit tests using `assert()`.
- Detect repeated characters and predictable patterns.
- Improve input-length validation.
- Separate the program into source, header, and test files.
- Add more informative suggestions for improving password security.

