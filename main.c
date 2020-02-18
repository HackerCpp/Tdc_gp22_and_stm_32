#include "tdcgp22.h"


int main(void){
	uint8_t id = 0x77;
	uint16_t delay_stop_mS;
	
	struct Tdcgp2_register_0 reg_0 = {
		.azn_fire = FIRE_DISABLE,
		.div_fire = DIVIDER_FIRE_NONE,
		.azn_per_calres = CAL_2_PERIOD_61_035_mkS,
		.div_clkhs = CLKHS_DIV_1,
		.start_clkhs = CLKHS_ALWAYS_ENABLE,
		.azn_port = QUANTITY_TEMP_PORTS_2,
		.tcycle = TEMP_CYCLE_128_mkS,
		.azn_fake = IDLE_CYCLES_2,
		.sel_eclk_tmp = ECLK_32_768,
		.calibrate = CALIB_ENABLE,
		.no_cal_auto = AUTO_CALIB_AFTER_MEASUREMENT,
		.messb2 = MODE_2,
		.neg_stop2 = STOP2_RISING_EDGE,
		.neg_stop1 = STOP1_FALLING_EDGE,
		.neg_start = START_RISING_EDGE,
		.ID  = id
	};
	
	struct Tdcgp2_register_1 reg_1 = {
		.hit2 = HIT2_MODE2_1STOP_CH1,
		.hit1= HIT1_MODE2_START,
		.en_fast_init = FAST_INIT_DISABLED,
		.kd = 1,
		.hitin2 = CH2_DISABLED,
		.hitin1= IN1_2HIT,
		.curr32k = LOW_CURRENT_RECOMMENDED,
		.sel_start_fire = FIRE_FOR_START,
		.sel_tsto2 = EN_START_ENABLE_START,
		.sel_tsto1 = FIRE_IN,
		.ID  = id
	};
	
	struct Tdcgp2_register_2 reg_2 = {
	.en_int = INT_ALU,
	.rfedge2 = CH2_RISING_OR_FALLING,
	.rfedge1 = CH1_RISING_OR_FALLING,
	.delay_stop_int_sh1 = (float)(delay_stop_mS * 7.8125f),//Freq 4MGz CLKHS_DIV_1
	.delay_stop_frac_sh1  = 0,
	.ID = id
};
	
	tdcgp22_set_register0(reg_0);
	tdcgp22_set_register1(reg_1);
	tdcgp22_set_register2(reg_2);
	
	while(1){
	}
}
