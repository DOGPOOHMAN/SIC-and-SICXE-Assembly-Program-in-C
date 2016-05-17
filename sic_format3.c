
Format3 * p010_init_format3(unsigned value){
    
    Format3 * c =  NULL;
	
	c = (Format3 *)malloc( sizeof(Format3) ); 
    
	c->opCode    = 0x0;
	c->disp      = 0x0;
	c->xMask     = 0x8000;
	c->ojbCode   = value;
	c->xFlag     = FALSE;
	
	return c;
}//end p010_init_format3 function


void p011_delete_format3(Format3 * c){
    
    if(c != NULL){
        free(c);
    }
}//end of p011_delete_format3 function



void p012_calcu_format3(Format3 * c){
	
	//if use x-relative addressing
	if(c->xFlag == TRUE){
		
		//insert x-bit into disp
		c->disp = c->disp | c->xMask;
	}
	
	/*generate object code*/
	
	/*opCode = STCH = 0x54
	c->ojbCode 0000 0000  0000 0000  0101 0100
	
	left shift 16-bits
	c->ojbCode 0101 0100 0000 0000  0000 0000
	
	write disp into object code(OR as disp)
	c->ojbCode 0101 0100 0000 0000  0000 0000
	disp                  ^^^ ^^^^  ^^^^ ^^^^
	
	*/
	c->ojbCode   =   c->opCode;
	c->ojbCode   <<= 16;
	c->ojbCode   =   c->ojbCode | c->disp;
	
}//end p012_calcu_format3


