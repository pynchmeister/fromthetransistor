#include <stdio.h>

// Struct for a FAT entry
typedef struct {
  // Add fields for each part of a FAT entry
  // ...
} FAT_Entry;

// Struct for a directory entry 
typedef struct {
  // Add fields for each part of a directory entry
  // ...
} Directory_Entry;

// Open a file
FILE* open_file(const char* path) {
    FILE* file = fopen(path, "rb");
    if (!file) {
        printf("Failed to open file\n");
        return NULL;
    }

  return file;
}


// Read the boot sector
void read_boot_sector(FILE* file) {
    // Seek to the start of the file
  fseek(file, 0, SEEK_SET);

  // Read the boot sector
  // ...
}

// READ the FAT
void read_fat(FILE* file) {
  // Seek to the start of the FAT
  // ...

  // READ each FAT entry
  // ...
}

// Read a directory
void read_directory(FILE* file, FAT_Entry first_cluster) {
    // Seek to the start of the directory 
    // ...

  // Read each directory entry 
  // ...
}

// Main function
int main() {
    // Open the FAT volume
  FILE* file = open_file("path/to/your/file");
  if (!file) {
      return 1;
  }

  // Read the boot sector
  read_boot_sector(file);

  // Read the FAT
  read_fat(file);

  // Read the root directory 
  FAT_Entry root_dir_first_cluster = {/* Initialize with the first cluster of the root directory */}
  read_directory(file, root_dir_first_cluster);

  // Close the file
  fclose(file);

  return 0;
}
