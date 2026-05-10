*This project has been created as part of the 42 curriculum by tsadamor.*

## Description
The goal of this project is to code the function that returns a line read from a file descriptor. Repeated calls (e.g., using a loop) to your get_next_line() function lets you read the text file pointed to by the file descriptor, **one line at a time**.

## Instructions
### Compilation	
Because you will have to read files in get_next_line(), add this option to your compiler call: 

**-D BUFFER_SIZE=n**

It will define the buffer size for read().

## Algorithm Explanation & Justification
**The Core Logic: "Read, Append, and Split"**

The selected algorithm follows a three-step cycle to ensure memory efficiency and compliance with the "one line per call" requirement:

1. Read & Append (read_until_include_newline()): The function reads from the file descriptor into a temporary buffer of BUFFER_SIZE. It then appends this to a static variable using a join function. This continues until a newline (\n) is found or the end of the file (EOF) is reached.

2. Extract (cut_at_newline()): Once a newline is detected in the static string, the function identifies its position and "cuts" the string from the beginning up to the newline. This extracted portion is returned to the user.

3. Update (update_str()): The static variable is then updated to contain only the "leftover" characters that appeared after the newline, preserving them for the next function call.

## Resources
- [Static variable(Wikipedia)](https://en.wikipedia.org/wiki/Static_variable)
- [gnlTester(Tripouille)](https://github.com/Tripouille/gnlTester)
### AI Usage
In compliance with the project requirements, AI (Gemini 3 Flash) was used as follows:
- Documentation Support
- Test Code Generation
