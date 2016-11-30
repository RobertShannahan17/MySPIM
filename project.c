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
    *r1 = (instruction >> 21) & 0x1F;

    // Section r2     (next 5 bits)
    *r2 = (instruction >> 16) & 0x1F;

    // Section r3     (next 5 bits)
    *r2 = (instruction >> 11) & 0x1F;

    // Section funct  (last 5 bits)
    *funct = instruction & 0x1F;

    // Section offset (last 16 bits)
    *offset = instruction & 0x0000FFFF;

    // Section jsec (last 26 bits)
    *jsec = instruction & 0x03FFFFFF;
}

/* instruction decode */
/* 15 Points */
int instruction_decode(unsigned op,struct_controls *controls)
{
    /*
    char RegDst;
	char Jump;
	char Branch;
	char MemRead;
	char MemtoReg;
	char ALUOp;
	char MemWrite;
	char ALUSrc;
	char RegWrite;
	*/

    // Switch for opcode
    switch(op){
        case 0:
            //R-type
            controls->RegDst = '1';
            controls->Jump = '0';
            controls->Branch = '0';
            controls->MemRead = '0';
            controls->MemtoReg = '0';
            controls->ALUOp = '7'; //ALU add
            controls->MemWrite = '0';
            controls->ALUSrc = '0';
            controls->RegWrite = '1';
            break;
        case 8:
            // Addi
            controls->RegDst = '0';
            controls->Jump = '0';
            controls->Branch = '0';
            controls->MemRead = '0';
            controls->MemtoReg = ;
            controls->ALUOp = '0';
            controls->MemWrite = ;
            controls->ALUSrc = '1';
            controls->RegWrite = ;
            break;
        case 35:
            // lw
            controls->RegDst = '0';
            controls->Jump = '0';
            controls->Branch = '0';
            controls->MemRead = '1';
            controls->MemtoReg = '1';
            controls->ALUOp = '0';
            controls->MemWrite = '0';
            controls->ALUSrc = '1';
            controls->RegWrite = '1';
            break;
        case 43:
            // sw
            controls->RegDst = '2';
            controls->Jump = '0';
            controls->Branch = '0';
            controls->MemRead = '0';
            controls->MemtoReg = '2';
            controls->ALUOp = '0';
            controls->MemWrite = '1';
            controls->ALUSrc = '1';
            controls->RegWrite = '0';
            break;
        case 4:
            // Beq
            controls->RegDst = '2';
            controls->Jump = '0';
            controls->Branch = '1';
            controls->MemRead = '0';
            controls->MemtoReg = '2';
            controls->ALUOp =  '1';
            controls->MemWrite = '0';
            controls->ALUSrc = '0';
            controls->RegWrite = '0';
            break;
        case 2:
            // jump
            controls->RegDst = '2';
            controls->Jump = '1';
            controls->Branch = '0';
            controls->MemRead = '0';
            controls->MemtoReg = '2';
            controls->ALUOp = '0';
            controls->MemWrite = '0';
            controls->ALUSrc = '0';
            controls->RegWrite = '0';
            break;

    }

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
    //change my opinion on this.
*extended_value = offset;
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
	//case memwrite or memread are 1 and aluresult % 4 is in effect.
	if ((MemWrite == 1 || MemRead == 1) && ALUresult % 4 != 0) //Halts
	{
		//this will halt
		return 1;
	}
	//case that memwrite and memread are two, will halt
	if(MemWrite==2 || MemRead==2){
		//this will halt
		return 1
	}
	
	//case that MemWrite is 1. If it is, it sets memory of ALUresult to data2
	if (MemWrite == 1)
	{
		Mem[ALUresult >> 2] = data2;
	}
	//checks if MemRead is 1. If it is, it sets the memory data to memory of ALUresult shifted 2-bits
	if (MemRead == 1)
	{
		*memdata = Mem[ALUresult >> 2];	
	}
    	
	return 0;
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

