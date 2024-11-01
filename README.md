# Get Next Line: Mastering File Reading Line by Line 📄

Welcome to **Get Next Line** (GNL), a 42 project where you’ll build a function that reads lines from a file descriptor, one at a time. This project introduces you to key concepts like file descriptors, static variables, and efficient memory management, all of which are essential skills for any programmer working with data files.

**Grade**: 125/100 ✅

## 💡 Project Overview

The goal of **Get Next Line** is to create a function that reads a single line from a given file descriptor. When called in a loop, it returns the entire contents of a file, line by line, until it reaches the end. Using a static buffer, the function efficiently handles partial reads and maintains state across calls without re-reading previously processed data.

### Key Concepts
- **Static Buffer**: A persistent memory keeper that remembers data between function calls, allowing us to continue reading from where we left off.
- **File Descriptors**: File handles used to open, read, and close files, which GNL uses to interact with files in a structured way.
- **Memory Management**: GNL uses dynamic memory allocation and freeing efficiently to avoid memory leaks, while keeping unused data accessible for future reads.

## 🚀 How It Works

### Static Buffer: The Persistent Helper

In `get_next_line`, a **static buffer** keeps track of data read from the file but not yet returned as a line. Here’s how it works:

1. **First Call**: Reads from the file, fills the buffer, and returns the first line. Any leftover data remains in the buffer.
2. **Subsequent Calls**: The function checks the buffer for a complete line. If none, it reads more data from the file and continues.
3. **End of File**: Returns any remaining data in the buffer, then frees it and sets it to `NULL`.

### Function Breakdown

#### Main Function: `get_next_line`

This function is the core of GNL. It reads lines from the file descriptor, updates the buffer, and returns each line.

```c
char *get_next_line(int fd)
{
    static char *buffer;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
        return (NULL);
    buffer = read_file(fd, buffer);
    if (!buffer)
        return (NULL);
    line = ft_line(buffer);
    buffer = ft_next(buffer);
    return (line);
}
```

1. **Error Handling**: Checks for valid file descriptors and buffer size.
2. **File Reading**: Reads data into a static buffer, appending new reads to existing data.
3. **Line Extraction**: Extracts a line and updates the buffer for the next call.

#### Helper Functions

1. **Reading from the File (`read_file`)**: Reads data in chunks into the buffer, appending new data until a newline or EOF is found.
   
2. **Extracting a Line (`ft_line`)**: Copies a single line from the buffer, stopping at the newline.

3. **Updating the Buffer (`ft_next`)**: After a line is read, updates the buffer to remove the read line and retain any leftover data.

## 🛠️ Usage

To use `get_next_line`, include it in your project files and compile with a specified buffer size.

```c
#include "get_next_line.h"
```

Compile your code like so, replacing `<size>` with the desired buffer size:

```bash
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=<size> get_next_line.c get_next_line_utils.c && ./a.out
```

## 📋 Testing

You can use third-party testers like:
- [Tripouille’s gnlTester](https://github.com/Tripouille/gnlTester)
  
Or, create a test file (`test.txt`) and use the example main function within `get_next_line.c` to test different scenarios.

## 🌟 Resources
- [Understanding Static Variables](https://www.codequoi.com/en/local-global-static-variables-in-c/)
- [How to Read Data from a File in C](https://www.educative.io/answers/how-to-read-data-from-a-file-using-the-fread-function-in-c)
  
With **Get Next Line**, you now have a powerful tool for reading files efficiently. Enjoy coding, and happy line reading! 📘
