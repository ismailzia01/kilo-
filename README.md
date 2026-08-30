# 🛠️ C Projects — Kilo & CCWC

A collection of systems programming projects built from scratch in C, focusing on low-level POSIX APIs, terminal I/O, and Unix tool design.

| Project | Description | Lines |
|---|---|---|
| [**Kilo**](#-kilo--terminal-text-editor) | A fully featured terminal text editor | ~800 |
| [**CCWC**](#-ccwc--word-count-tool) | A Unix `wc` clone — count lines, words, bytes, and characters | — |

---

# ⌨️ Kilo — Terminal Text Editor

A lightweight, fully functional terminal text editor written in **~800 lines of C** with **zero dependencies** beyond the standard library. Inspired by [antirez/kilo](https://github.com/antirez/kilo) and the [Build Your Own Text Editor](https://viewsourcecode.org/snaptoken/kilo/) tutorial.

## ✨ Features

| Feature | Description |
|---|---|
| **Raw Mode Terminal** | Full control over terminal input — bypasses canonical mode entirely |
| **File Open & Save** | Open any text file from the command line, save with `Ctrl-S` |
| **Incremental Search** | Forward & backward search with live highlighting (`Ctrl-F`) |
| **Cursor Navigation** | Arrow keys, `Home`, `End`, `Page Up`, `Page Down` |
| **Line Editing** | Insert/delete characters, newline handling, backspace across lines |
| **Tab Rendering** | Configurable tab stop width (default: 8 spaces) |
| **Status Bar** | Shows filename, line count, modified indicator, and cursor position |
| **Message Bar** | Contextual help messages and save/error notifications |
| **Dirty Flag** | Tracks unsaved changes — warns before quitting with `Ctrl-Q` |
| **Number Highlighting** | Digits are highlighted in red for visual distinction |
| **Vertical & Horizontal Scrolling** | Seamless scrolling for files larger than the terminal window |
| **Save As Prompt** | Prompts for filename when saving a new (unnamed) file |

## 🚀 Build & Run

```bash
# Compile
gcc -o kilo kilo.c -Wall -Wextra -std=c99

# Open an existing file
./kilo myfile.txt

# Start with an empty buffer
./kilo
```

## ⌘ Keyboard Shortcuts

| Shortcut | Action |
|---|---|
| `Ctrl-S` | Save file |
| `Ctrl-Q` | Quit (press 3× to force-quit with unsaved changes) |
| `Ctrl-F` | Find / Search |
| `Arrow Keys` | Move cursor |
| `Home` / `End` | Jump to beginning / end of line |
| `Page Up` / `Page Down` | Scroll one page |
| `Backspace` / `Delete` | Delete character |
| `Enter` | Insert new line |
| `Esc` | Cancel current prompt |

### Search Mode

| Key | Action |
|---|---|
| `→` / `↓` | Next match |
| `←` / `↑` | Previous match |
| `Enter` | Confirm and jump to match |
| `Esc` | Cancel search, restore cursor |

## 🏗️ Architecture

```
kilo.c
├── Terminal      — Raw mode, key reading, window size detection
├── Row Ops       — Line buffer management, tab expansion, insert/delete
├── Editor Ops    — High-level editing (insert char, newline, delete)
├── File I/O      — Open, save, rows-to-string serialization
├── Find          — Incremental search with bidirectional navigation
├── Append Buffer — Efficient batched screen writes (flicker-free)
├── Output        — Screen refresh, status bar, message bar, scrolling
├── Input         — Keypress processing, prompt system
└── Init          — Editor state initialization
```

---

# 📊 CCWC — Word Count Tool

A custom implementation of the classic Unix `wc` (word count) utility, built in C. This project was completed as a [Coding Challenges](https://codingchallenges.fyi/challenges/challenge-wc) exercise.

> **Note:** The full implementation was previously built but the source is not in this repository yet. The current `ccwc.c` is a placeholder — the complete version will be added soon.

## What It Does

CCWC counts the number of **lines**, **words**, **bytes**, and **characters** in a given file or from standard input — just like the Unix `wc` command.

### Expected Usage

```bash
# Compile
gcc -o ccwc ccwc.c -Wall -Wextra -std=c99

# Count lines, words, and bytes
./ccwc filename.txt

# Individual flags
./ccwc -l filename.txt    # Line count
./ccwc -w filename.txt    # Word count
./ccwc -c filename.txt    # Byte count
./ccwc -m filename.txt    # Character count (multibyte)

# Read from stdin
cat filename.txt | ./ccwc -l
```

### Planned Features

- [x] Count bytes (`-c`)
- [x] Count lines (`-l`)
- [x] Count words (`-w`)
- [x] Count characters (`-m`, multibyte support)
- [x] Default output (lines + words + bytes)
- [x] Read from stdin when no file is provided

---

# 📁 Project Structure

```
kilo-/
├── kilo.c       # Terminal text editor (~800 lines)
├── ccwc.c       # Word count tool (wc clone)
└── README.md
```

---

# 🛠️ Prerequisites

- **GCC** (or any C99-compatible compiler)
- A **POSIX-compliant terminal** (Linux / macOS / WSL)
- No external libraries required

---

# 📚 References

| Resource | Link |
|---|---|
| Build Your Own Text Editor | [snaptoken tutorial](https://viewsourcecode.org/snaptoken/kilo/) |
| Original Kilo | [antirez/kilo](https://github.com/antirez/kilo) |
| Build Your Own wc | [Coding Challenges — wc](https://codingchallenges.fyi/challenges/challenge-wc) |
| VT100 Escape Codes | [vt100.net](https://vt100.net/docs/vt100-ug/chapter3.html) |
| termios(3) Man Page | [man7.org](https://man7.org/linux/man-pages/man3/termios.3.html) |

---

# 👤 Author

**Mohammad Ismail Zia**

[![GitHub](https://img.shields.io/badge/GitHub-ismailzia01-181717?logo=github)](https://github.com/ismailzia01)
[![LinkedIn](https://img.shields.io/badge/LinkedIn-ismailzia01-0A66C2?logo=linkedin)](https://linkedin.com/in/ismailzia01)

---

# 📄 License

This project is open source and available for learning purposes.
