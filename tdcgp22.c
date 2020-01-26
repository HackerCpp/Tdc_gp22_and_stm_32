#include "tdcgp22.h"


__packed union Register_0{
	uint32_t register0_u32;
	__packed struct Tdcgp2_register_0 register0_struct;
}register_0;

void tdcgp22_set_register0(struct Tdcgp2_register_0 tdcgp22_register_0){
	register_0.register0_struct = tdcgp22_register_0;
}

__packed union Register_1{
	uint32_t register1_u32;
	__packed struct Tdcgp2_register_1 register1_struct;
}register_1;

void tdcgp22_set_register1(struct Tdcgp2_register_1 tdcgp22_register_1){
	register_1.register1_struct = tdcgp22_register_1;
}

__packed union Register_2{
	uint32_t register2_u32;
	__packed struct Tdcgp2_register_2 register2_struct;
}register_2;

void tdcgp22_set_register2(struct Tdcgp2_register_2 tdcgp22_register_2){
	register_2.register2_struct = tdcgp22_register_2;
}
