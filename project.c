#include "spimcore.h"


/* ALU */
/* 10 Points */
void ALU(unsigned A,unsigned B,char ALUControl,unsigned *ALUresult,char *Zero)
{

}

/* instruction fetch */
/* 10 Points */
int instruction_fetch(unsigned PC,unsigned *Mem,unsigned *instruction)
{
    // Read hex in Mem[PC] to instruction

    // Check if hex is valid

    // Return 1 if invalid instruction, 0 otherwise
}


/* instruction partition */
/* 10 Points */
void instruction_partition(unsigned instruction, unsigned *op, unsigned *r1,unsigned *r2, unsigned *r3, unsigned *funct, unsigned *offset, unsigned *jsec)
{
    // Convert hex into binary

    // Section opcode (first 6 bits)

    // Section r1     (next 5 bits)
    // Section r2     (next 5 bits)
    // Section r3     (next 5 bits)
    // Section funct  (last 5 bits)

    // Section offset (last 15 bits)

    // Section jsec (last 25 bits)
}

/* instruction decode */
/* 15 Points */
int instruction_decode(unsigned op,struct_controls *controls)
{
    // Switch for opcode, http://alumni.cs.ucr.edu/~vladimir/cs161/mips.html for table
    // ALUOp uses its own switch, table on the PDF

    // Return 1 if invalid instruction, 0 otherwise
}

/* Read Register */
/* 5 Points */
void read_register(unsigned r1,unsigned r2,unsigned *Reg,unsigned *data1,unsigned *data2)
{
    // set data1 to Reg[r1]
    // set data2 to Reg[r2]
}


/* Sign Extend */
/* 10 Points */
void sign_extend(unsigned offset,unsigned *extended_value)
{
    // copy left most bit to all bits on the left
    // store in extended value
}

/* ALU operations */
/* 10 Points */
int ALU_operations(unsigned data1,unsigned data2,unsigned extended_value,unsigned funct,char ALUOp,char ALUSrc,unsigned *ALUresult,char *Zero)
{
    // switch function based on ALUOp and funct
        // use data1 and (data2 if ALUSrc is 0 or extend_value if ALUSrc is 1) to do operations
        // using ALU()
    // Return 1 if invalid operation, 0 otherwise
}

/* Read / Write Memory */
/* 10 Points */
int rw_memory(unsigned ALUresult,unsigned data2,char MemWrite,char MemRead,unsigned *memdata,unsigned *Mem)
{
    // If MemWrite/MemRead is 2, do nothing
    // If MemWrite is 1, store ALUResult in memdata
    //
}


/* Write Register */
/* 10 Points */
void write_register(unsigned r2,unsigned r3,unsigned memdata,unsigned ALUresult,char RegWrite,char RegDst,char MemtoReg,unsigned *Reg)
{

}

/* PC update */
/* 10 Points */
void PC_update(unsigned jsec,unsigned extended_value,char Branch,char Jump,char Zero,unsigned *PC)
{

}

