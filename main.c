#include "common.h"
//#include "chunk.h"
#include "debug.h"

int main(int argc, const char* argv[]){
    Chunk chunk;
    initChunk(&chunk);

    // In this block of code we "hand compile" a constant instruction
    // in our test chunk, since we do not yet have a working compiler
    int constant = addConstant(&chunk, 1.2); // Create a constant in the chunk's constant pool and return its index within the pool(array)
    writeChunk(&chunk, OP_CONSTANT);
    writeChunk(&chunk, constant);

    writeChunk(&chunk, OP_RETURN);
    disassembleChunk(&chunk, "test chunk");
    freeChunk(&chunk);
    return 0;
}