## Morse Code Converter

This program converts text or files into Morse code and plays the corresponding sounds for each Morse code symbol.

### Compilation

To compile the program, use the `make` command.

### Usage

The program supports the following command-line options:

- If no command-line arguments are provided, it takes input from the console until '.' is given.
- If the `--file` option is provided followed by a filename, it reads from the specified file.
- If the `--text` option is provided followed by one or more strings, it converts each string to Morse code.
- If the `--help` option is provided, it displays help information.
- For any other invalid option, it displays an error message.

### Functions

The program includes the following functions:

```cpp
charToMorse(char currentChar)
```

This function converts a character to its corresponding Morse code representation.

Parameters:
- `currentChar`: The character to convert.

Returns:
- The Morse code representation of the character as a string.
- If the character is not a valid alphanumeric character or a space, an empty string is returned.

```cpp
playSound(char* morse)
```

This function plays the sound corresponding to the Morse code.

Parameters:
- `morse`: The Morse code to play as a string.

```cpp
main(int argc, char *argv[])
```

The main function controls the program's execution.

If no command-line arguments are provided, the program takes input from the console until '.' is given. It converts each character to Morse code and plays the corresponding sounds.

If the `--file` option is used followed by a filename, the program reads from the specified file. It converts each character to Morse code and plays the corresponding sounds.

If the `--text` option is used followed by one or more strings, the program converts each string to Morse code and plays the corresponding sounds.

If the `--help` option is used, the program displays help information.

For any other invalid option, the program displays an error message.

Note: The program uses external sound files (`dottest.wav` and `linetest.wav`) to play the Morse code sounds.
