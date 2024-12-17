
# **Get Next Line: Reading a File Descriptor Line by Line**

## **Project Description**
The objective of this project is to create a function `get_next_line` that reads a line from a file descriptor. This function is highly practical and will teach you about static variables, memory management, and efficient file reading.

---

## **Mandatory Part**

### **Function Name**:
```c
char *get_next_line(int fd);
```

### **Files to Submit**:
- `get_next_line.h`  
- `get_next_line.c`  
- `get_next_line_utils.c`  

### **Allowed Functions**:
- `read`, `malloc`, `free`

### **Requirements**:
1. **Successive Calls**:  
   Multiple calls to `get_next_line()` must return successive lines from the file descriptor.

2. **Return Behavior**:  
   - Return the line read, including the terminating newline character (`
`).  
   - Return `NULL` when there is nothing more to read or in case of an error.

3. **Buffer Management**:
   - Your function must use the `BUFFER_SIZE` macro, specified at compile time:
     ```bash
     cc -D BUFFER_SIZE=42 -Wall -Wextra -Werror <files>.c
     ```
   - Test the function with different values for `BUFFER_SIZE` (e.g., 1, 9999, etc.).

4. **Static Variables**:  
   The use of static variables is required for managing the file descriptor state.

5. **Behavior**:
   - The program must read **as little as possible** per call.  
   - Stop reading after encountering a newline character (`\n`) and return the previous line.

6. **Forbidden**:
   - Use of the `libft` library.  
   - The `lseek()` function.  
   - Global variables.

---

## **Bonus Part**

If the mandatory part is completed perfectly, you can implement the following bonus features:

1. **Single Static Variable**:  
   Implement `get_next_line()` using only one static variable.

2. **Multiple File Descriptors**:  
   Extend `get_next_line()` to handle multiple file descriptors simultaneously.  
   - Example: You can read alternately from `fd 3`, `fd 4`, and `fd 5` without losing track of their states.

### **Bonus Files**:
- `get_next_line_bonus.c`  
- `get_next_line_bonus.h`  
- `get_next_line_utils_bonus.c`  

---

## **How to Compile**

Use the following command to compile your program with a defined buffer size:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
```

---

## **Testing**

### Example Test Program:

```c
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    int fd;
    char *line;

    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        if (fd == -1)
            return (1);
        while ((line = get_next_line(fd)))
        {
            printf("%s", line);
            free(line);
        }
        close(fd);
    }
    return (0);
}
```

### Compile and Run:
```bash
cc -D BUFFER_SIZE=42 -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c -o gnl
./gnl file.txt
```

---
