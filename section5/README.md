## Description

```
Section 5: Operating System: Software we take for granted -- 3 weeks
Building an MMU(Verilog, 1000) -- ARM9ish, explain TLBs and other fun things. Maybe also a memory controller, depending on how the FPGA is, then add the init code to your bootloader.
Building an operating system(C, 2500) -- UNIXish, only user space threads. (open, read, write, close), (fork, execve, wait, sleep, exit), (mmap, munmap, mprotect). Consider the debug interface you are using, ranging from printf to perhaps a gdbremote stub into kernel. Break into subchapters.
Talking to an SD card(Verilog, 150) -- The last hardware you have to do. And a driver
FAT(C, 300) -- A real filesystem, I think fat is the simplest
init, shell, download, cat, ls, rm(C, 250) -- Your first user space programs.
```
