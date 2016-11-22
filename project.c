#include "spimcore.h"


/* ALU */
/* 10 Points */
void ALU(unsigned A,unsigned B,char ALUControl,unsigned *ALUresult,char *Zero)
{
    switch(ALUControl){
        case '0':
            *ALUresult = A + B;
            break;
        case '1':
            *ALUresult = A - B;
            break;
        case '2': case '3':
            if(A < B)
                *ALUresult = 1;
            else
                *ALUresult = 0;
            break;
        case '4':
            *ALUresult = A & B;
            break;
        case '5':
            *ALUresult = A | B;
            break;
        case '6':
            *ALUresult = B << 16;
            break;
        case '7':
            *ALUresult = ~A;
            break;
    }

    if(*ALUresult == 0)
        *Zero = 1;
    else
        *Zero = 0;
}

/* instruction fetch */
/* 10 Points */
int instruction_fetch(unsigned PC,unsigned *Mem,unsigned *instruction)
{
    // Check if address is valid
    if(PC % 4 == 0 && PC < 65536){
        *instruction = Mem[PC >> 2];
        return 0;
    }

    return 1;
}


/* instruction partition */
/* 10 Points */
void instruction_partition(unsigned instruction, unsigned *op, unsigned *r1,unsigned *r2, unsigned *r3, unsigned *funct, unsigned *offset, unsigned *jsec)
{
    // Convert hex into binary

    // Section opcode (first 6 bits)
    *op = instruction >> 26;

    // Section r1     (next 5 bits)
    *r1 = (instruction >> 21) & 0x7c0;

    // Section r2     (next 5 bits)
    *r2 = (instruction >> 16) & 0xF800;

    // Section r3     (next 5 bits)
    *r2 = (instruction >> 11) & 0x1F0000;

    // Section funct  (last 5 bits)
    *funct = instruction & 0x1F;

    // Section offset (last 15 bits)
    *offset = instruction & 0x7FFF;

    // Section jsec (last 25 bits)
    *jsec = instruction & 0x1FFFFFF;
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
    *data1 = Reg[r1];
    // set data2 to Reg[r2]
    *data2 = Reg[r2];
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

