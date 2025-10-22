

# Log Files Merger Demo

**A simple C program to merge and sort two log files by timestamp.**

This project demonstrates reading, parsing, and merging multiple log files in C. It is intended as a **learning/demo project**, not production-ready code.

## Features

* Reads two log files (`server1.log` and `server2.log`) line by line.
* Each log entry is expected in the format:

```
<timestamp>  <message>
```

* Merges and sorts all log entries **chronologically** by timestamp.
* Prints the merged logs to the console.
* Writes the merged logs to `sorted.log` with **two spaces** between timestamp and message.

## Example

**Input:**

`server1.log`

```
2025-10-22T10:00:00 Server1 started
2025-10-22T10:05:00 Cache cleared
```

`server2.log`

```
2025-10-22T10:02:00 Server2 started
2025-10-22T10:06:00 Session refreshed
```

**Output (console & sorted.log):**

```
[2025-10-22T10:00:00] Server1 started
[2025-10-22T10:02:00] Server2 started
[2025-10-22T10:05:00] Cache cleared
[2025-10-22T10:06:00] Session refreshed
```





## Code Overview

* **`Log` struct**: Stores a timestamp and message.
* **Functions**:

  * `get_lines_count(FILE *f)`: Counts the number of lines in a file.
  * `get_logs(FILE *f, Log *logs)`: Reads logs from a file into an array.
  * `mergeSorted(...)`: Merges two sorted log arrays into one.
  * `print_logs(...)`: Prints logs to the console.
  * `write_to_file(...)`: Saves merged logs to a file.

---

## Notes

* Timestamps are compared using `strcmp` — works if logs are formatted as ISO-8601 (`YYYY-MM-DDTHH:MM:SS`).
* Fixed-size arrays are used for simplicity (`timestamp[100]`, `message[100]`). For larger files, dynamic allocation is recommended.
* This is a **demo project** for educational purposes; not optimized for performance or error handling.


