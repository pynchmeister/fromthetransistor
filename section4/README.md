## Description

```
Section 4: Compiler: A “high” level language -- 3 weeks
Building a C compiler(Haskell, 2000) -- A bit more interesting, cover the basics of compiler design. Write in haskell. Write a parser. Break this into subchapters. Outputs ARM assembly.
Building a linker(Python, 300) -- If you are clever, this should take a day. Output elf files. Use for testing with QEMU, semihosting.
libc + malloc(C, 500) -- The gateway to more complicated programs. libc is only half here, things like memcpy and memset and printf, but no syscall wrappers.
Building an ethernet controller(Verilog, 200) -- Talk to a real PHY, consider carefully MMIO design.
Writing a bootloader(C, 300) -- Write ethernet program to boot kernel over UDP. First thing written in C. Maybe don’t redownload over serial each time and embed in FPGA image.
```
