import struct 

# Assume that the header of our binary format is 16 bytes 
# with the last 4 bytes being a little-endian integer
# that should contain the size of the data sectoion.

def get_size(filename):
  with open(filename, "rb") as f:
    f.seek(12)  # skip the first 12 bytes of the header
    size, = struct.unpack("<I", f.read(4))
  return size

def set_size(filename, size):
  with open(filename, "r+b") as f:
      f.seek(12)
      f.write(struct.pack("<I", size))

def link(file1, file2, output):
  # Read the data sections of file1 and file2
    with open(file1, "rb") as f1, open (file2, "rb") as f2:
      f1.seek(16)
      f2.seek(16)
      data1 = f1.read()
      data2 = f2.read()

    # Concatenate the data section
    data = data1 + data2

    # Read the header from file1 (assuming the headers of file1 and file2 are identical
    with open(file1, "rb") as f:
        header = f.read(16)

    # Write the output file
    with open(output, "wb") as f:
        f.write(header)
        f.write(data)

    # Update the size field in the header
    set_size(output, len(data))

link("file1.bin", "file2.bin", "output.bin")
