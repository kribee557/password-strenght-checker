# Password Strength Checker

A beginner-friendly password strength checker built using C.

## Features

- Checks password length
- Detects uppercase and lowercase letters
- Detects digits and special characters
- Calculates a basic strength score
- Displays a simple strength rating

## Technologies Used

- C programming language
- Standard C libraries: `stdio.h`, `string.h`, `ctype.h`

## How to Compile and Run

Compile using GCC:

```bash
gcc password_checker.c -o password_checker
```

Run on Windows:

```powershell
.\password_checker.exe
```

Run on Linux:

```bash
./password_checker
```

## Limitations

This project uses simple educational rules to estimate password strength. It does not check password databases, detect all predictable patterns, or guarantee password security.

## Future Improvements

- Detect common passwords
- Improve password-strength scoring
- Handle input-length limits
- Add automated tests

## Author

Created as a C programming and cybersecurity learning project.
