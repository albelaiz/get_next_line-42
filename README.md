# 42 Get Next line
## static variable
- static variables and other variables with static storage duration are stored in special segments outside the stack. Generally, the C standard doesn't mention how this is done other than that static storage duration variables are initialized before main() is called. However, the vast majority of real-world computers work as described below:

- If you initialize a static storage duration variable with a value, then most systems store it in a segment called .DATA. If you don't initialize it, or explicitly initialize it to zero, it gets stored in another segment called .BSS where everything is zero-initialized.
-
  - Then the line containing the initialization is not executed the first time the function is entered (as often taught in beginner classes)- it is not executed inside the function at all and it is always ignored during function execution.

  - Before main() is even called, the "C run-time libraries" (often called CRT) run various start-up code. This includes copying down values into .data and .bss. So the above line is actually executed before your program even starts.

  - So by the time func() is called for the first time, foo is already initialized. Any other changes to foo inside the function will happen in run-time, as with any other variable.
- The data and bss sections:

  - is where variables with static storage duration go. All variables that must persist throughout the execution of the whole program end up in these sections, such as for example "global variables". All such variables that are explicitly initialized by the programmer to a value end up in the data section, and those who aren't explicitly initialized or initialized to zero end up in the bss section, where every variable is zero-initialized during program start-up.
<div align="center">
  <img src="https://mirzafahad.github.io/img/text/memory.png" alt="Test Image 4">
</div>

## File Descriptor

### 1.table of file descriptor:
A table of file descriptors per process. Each process has its own table containing a series of indexes, each one referring to an entry in the open file table.

### 2.open file table:
An open file table, shared between all processes. Each entry in this table contains, among other things, the access mode, an offset describing the current location within the file, and a pointer to the corresponding entry in the inode table. This table also keeps count of the number references there are to this file in all of the file descriptor tables of all processes. When a process closes the file, this reference count is decremented and if it gets to 0, the entry is deleted from the table.

1.Reference Count:
- The reference count is the number of file descriptors that are currently referencing the same open file description. When a file is opened, the reference count is set to 1. If another file descriptor is duplicated (via dup or fork), the reference count is incremented. When a file is closed, the reference count is decremented, and the resources associated with the file are released when the count reaches zero.
O'

2.offset:
- The offset represents the current position in the file where the next read or write operation will occur. It's essentially the byte offset from the beginning of the file. When you read or write data, the offset is automatically updated by the system.

3.Access Mode(File Status Flags):

- The access mode refers to the permissions with which the file was opened. There are three main access modes in C when using the fopen function:
  - "r": Read mode (file must exist).
  - "w": Write mode (creates a new file or truncates an existing file).
  - "a": Append mode (writes to the end of the file, creating the file if it doesn't exist).

<p><img align="center" src="https://substackcdn.com/image/fetch/w_1456,c_limit,f_webp,q_auto:good,fl_progressive:steep/https%3A%2F%2Fbucketeer-e05bbc84-baa3-437e-9518-adb32be77984.s3.amazonaws.com%2Fpublic%2Fimages%2F87f55e76-5850-4d8c-a11e-4191fc30833c_2883x3273.png" alt="flutterde" /></p>

## System Call

https://www.geeksforgeeks.org/introduction-of-system-call/

ttt
>gg
