# 📁 myls - Custom Unix Directory Lister

> A lightweight, POSIX-compliant implementation of the classic `ls` command written in C

## 🚀 Overview

This is a production-grade implementation of the Unix `ls` utility that demonstrates systems programming fundamentals through directory traversal and file metadata handling. The code showcases mastery of system calls, POSIX compliance, and C programming best practices.

## ✨ Features

### Core Functionality
- **Directory Traversal**: Recursively reads directory contents using `opendir()`/`readdir()`
- **Hidden File Control**: Toggle visibility of dotfiles with `-a` flag
- **Long Format Display**: Detailed file information with `-l` flag including:
  - File type and permissions (rwx format)
  - Number of hard links
  - Owner and group names
  - File size in bytes
  - Last modification timestamp

### Technical Highlights
- **POSIX Compliant**: Full adherence to Unix system standards
- **Cross-Platform**: Designed for all Unix-like systems (Linux, macOS, BSD)
- **Memory Safe**: Proper buffer management with bounds checking using `snprintf()`
- **Error Resilient**: Graceful handling of edge cases and invalid inputs
- **Clean Architecture**: Modular function design for easy maintenance

## 🛠️ Technical Implementation

### Key Components

#### Permission Handling
```c
void mode_string(mode_t mode, char *str)
```
Converts `st_mode` bitmask to rwx permission string with file type indicator. Supports all standard Unix file types:
- Regular files, directories, symbolic links
- Character/block devices, FIFOs, sockets

#### Long Format Printing
```c
void print_long(const char *dir, const char *name)
```
Retrieves and formats complete file metadata using:
- `lstat()` - File metadata (follows symlinks)
- `getpwuid()` / `getgrgid()` - User/group resolution with fallback
- `localtime()` / `strftime()` - Timestamp formatting

### System Calls Used
- `opendir()` / `readdir()` - Directory iteration
- `lstat()` - File metadata retrieval
- `getpwuid()` / `getgrgid()` - User/group name resolution
- `localtime()` / `strftime()` - Timestamp formatting
- `getopt()` - Command-line flag parsing

## 🔧 Building & Installation

```bash
# Compile with warnings and pedantic mode
gcc -Wall -Wextra -pedantic -o myls ls.c

# Run
./myls [-al] [path]
```

### Compilation Options
| Mode | Command |
|------|---------|
| Debug Build | `gcc -g -O0 -Wall -Wextra -pedantic -o myls ls.c` |
| Optimized Release | `gcc -O3 -D_FORTIFY_SOURCE=2 -o myls ls.c` |
| Static Analysis | `gcc -Wall -Wextra -pedantic -Wshadow -Wconversion -o myls ls.c` |

## 📋 Usage Examples

```bash
# List current directory (simple format)
./myls

# Show all files including hidden ones
./myls -a

# Detailed file information
./myls -l

# Combine flags - show all files with details
./myls -la

# Specify a different directory
./myls -l /etc
./myls -la /home/user/Documents
```

### Sample Output
```
-rw-r--r-- 1 user staff 4096 Jul  5 14:23 README.md
drwxr-xr-x 3 user staff  102 Jul  5 14:23 src/
-rwxr-xr-x 1 user staff 24576 Jul  5 14:22 myls
```

## 🧪 Testing Scenarios

```bash
# Test with various scenarios
./myls                     # Empty directory
./myls /nonexistent        # Error handling
./myls -la /tmp           # Mixed directory with special files
./myls -a .hidden_file    # Hidden file detection
./myls -l /dev/null       # Special file handling
./myls -la ~              # Home directory with all files
```

## 🔍 Edge Cases Handled

- ✅ Empty directories
- ✅ Hidden files (`.` and `..`)
- ✅ Symbolic links (using `lstat()` vs `stat()`)
- ✅ Invalid user/group IDs (falls back to `?`)
- ✅ Permission denied errors
- ✅ Path resolution failures
- ✅ Buffer overflow protection with `snprintf()`

## 🚀 Potential Enhancements

- [ ] Recursive directory traversal (`-R` flag)
- [ ] Human-readable file sizes (`-h` flag)
- [ ] Colorized output for file types
- [ ] Sorting options (by name, size, time)
- [ ] Reverse ordering (`-r` flag)
- [ ] File type indicators (`-F` flag)
- [ ] Custom output formatting

## 📚 Learning Resources

This project serves as an excellent educational tool for:
- Understanding the Unix VFS (Virtual File System)
- Learning `stat()` system call mechanics
- Exploring directory traversal patterns
- Studying permission management in Unix
- Understanding user/group resolution

## 📄 License

MIT License - feel free to use, modify, and distribute as needed.

---

## 👨‍💻 About the Developer

This project demonstrates proficiency in:
- **C Programming**: Memory management, pointer handling, low-level I/O
- **Systems Programming**: OS-level file operations, system calls
- **Unix Philosophy**: Clean, modular design following established patterns
- **Security Awareness**: Buffer safety, error handling, input validation

---

*"The best way to understand a system is to rebuild its tools."*

*Built with ❤️ and a deep appreciation for Unix philosophy*