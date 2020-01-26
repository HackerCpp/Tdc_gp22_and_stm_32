#include <stdint.h>


/*Sets number of pulses generated by fire pulse generator.
Additional 3 bits are set in register 6.
For values ANZ_FIRE > 15 the phase setting (PHFIRE) can not be used*/
enum Anz_fire{
	FIRE_DISABLE, FIRE_PULSE_1,FIRE_PULSE_2,FIRE_PULSE_3,FIRE_PULSE_4,FIRE_PULSE_5,FIRE_PULSE_6,FIRE_PULSE_7,
	FIRE_PULSE_8,FIRE_PULSE_9,FIRE_PULSE_10,FIRE_PULSE_11,FIRE_PULSE_12,FIRE_PULSE_13,FIRE_PULSE_14,FIRE_PULSE_15
};

enum Div_fire{
	DIVIDER_FIRE_NONE, 	DIVIDER_FIRE_2, 		DIVIDER_FIRE_3, 		DIVIDER_FIRE_4,
	DIVIDER_FIRE_5,     DIVIDER_FIRE_6,     DIVIDER_FIRE_7,     DIVIDER_FIRE_8,
	DIVIDER_FIRE_9,     DIVIDER_FIRE_10,    DIVIDER_FIRE_11,    DIVIDER_FIRE_12, 
	DIVIDER_FIRE_13,    DIVIDER_FIRE_14,    DIVIDER_FIRE_15,    DIVIDER_FIRE_16	
};

enum Azn_per_calres{
	CAL_2_PERIOD_61_035_mkS,
	CAL_4_PERIOD_122_07_mkS,
	CAL_8_PERIOD_244_14_mkS,
	CAL_16_PERIOD_488_281_mkS,
};

enum Div_clkhs{CLKHS_DIV_1,CLKHS_DIV_2,CLKHS_DIV_4,CLKHS_DIV_8};

/*The highest bit to adjust START_CLKS is loca-ted in register 6,
bit 20. This has to be set to 1 for settling times of 2.44 ms and 5.14 ms*/
enum Start_clkhs{
	CLKHS_DISABLE = 0x0,
	CLKHS_ALWAYS_ENABLE = 0x1,
	CLKHS_480_mkS = 0x2,
	CLKHS_1_46_mS = 0x3,
	//when bit 20 in register 6 equals 1
	CLKHS_2_44_mS = 0x0,
	CLKHS_5_14_mS = 0x1
};

enum Azn_port{QUANTITY_TEMP_PORTS_2,QUANTITY_TEMP_PORTS_4};
enum Tcycle{TEMP_CYCLE_128_mkS,TEMP_CYCLE_512_mkS};
enum Azn_fake{IDLE_CYCLES_2,IDLE_CYCLES_7};
enum Sel_eclk_tmp{ECLK_32_768,ECLK_128_CLKHS};
enum Calibrate{CALIB_DISABLE, CALIB_ENABLE};
enum No_cal_auto{AUTO_CALIB_AFTER_MEASUREMENT,AUTO_CALIB_DISABLE};
enum Messb2{MODE_1,MODE_2};
enum Neg_stop2{STOP2_RISING_EDGE,STOP2_FALLING_EDGE};
enum Neg_stop1{STOP1_RISING_EDGE,STOP1_FALLING_EDGE};
enum Neg_start{START_RISING_EDGE,SSTART_FALLING_EDGE};


	
__packed struct Tdcgp2_register_0{
	enum Anz_fire azn_fire 							: 0x4;
	enum Div_fire div_fire 							: 0x4;
	enum Azn_per_calres azn_per_calres 	: 0x2;
	enum Div_clkhs div_clkhs 						: 0x2;
	enum Start_clkhs start_clkhs				: 0x2;
	enum Azn_port azn_port							: 0x1;
	enum Tcycle	tcycle									: 0x1;
	enum Azn_fake azn_fake							: 0x1;
	enum Sel_eclk_tmp sel_eclk_tmp			: 0x1;
	enum Calibrate calibrate						: 0x1;
	enum No_cal_auto no_cal_auto				: 0x1;
	enum Messb2 messb2									: 0x1;
	enum Neg_stop2 neg_stop2						: 0x1;
	enum Neg_stop1 neg_stop1						: 0x1;
	enum Neg_start neg_start						: 0x1;
	uint8_t ID 													: 0x8;
};

enum Hit2{
	HIT2_MODE1_START = 0x0,
	HIT2_MODE1_1STOP_CH1 = 0x1,
	HIT2_MODE1_2STOPS_CH1 = 0x2,
	HIT2_MODE1_3STOPS_CH1 = 0x3,
	HIT2_MODE1_4STOPS_CH1 = 0x4,
	HIT2_MODE1_NO_ACTION = 0x5,
	HIT2_MODE1_CAL1_CH1 = 0x6,
	HIT2_MODE1_CAL2_CH1 = 0x7,
	HIT2_MODE1_1STOP_CH2 = 0x9,
	HIT2_MODE1_2STOPS_CH2 = 0xA,
	HIT2_MODE1_3STOPS_CH2 = 0xB,
	HIT2_MODE1_4STOPS_CH2 = 0xC,
	HIT2_MODE2_1STOP_CH1 = 0x02,
	HIT2_MODE2_2STOPS_CH1 = 0x03,
	HIT2_MODE2_3STOPS_CH1 = 0x04
};
enum Hit1{
	HIT1_MODE1_START = 0x0,
	HIT1_MODE1_1STOP_CH1 = 0x1,
	HIT1_MODE1_2STOPS_CH1 = 0x2,
	HIT1_MODE1_3STOPS_CH1 = 0x3,
	HIT1_MODE1_4STOPS_CH1 = 0x4,
	HIT1_MODE1_NO_ACTION = 0x5,
	HIT1_MODE1_CAL1_CH1 = 0x6,
	HIT1_MODE1_CAL2_CH1 = 0x7,
	HIT1_MODE1_1STOP_CH2 = 0x9,
	HIT1_MODE1_2STOPS_CH2 = 0xA,
	HIT1_MODE1_3STOPS_CH2 = 0xB,
	HIT1_MODE1_4STOPS_CH2 = 0xC,
	HIT1_MODE2_START = 0x01
};

enum En_fast_init{FAST_INIT_DISABLED,FAST_INIT_ENABLED};
enum Hitin2{CH2_DISABLED,IN2_1HIT,IN2_2HIT,IN2_3HIT,IN2_4HIT};
enum Hitin1{CH1_DISABLED,IN1_1HIT,IN1_2HIT,IN1_3HIT,IN1_4HIT};
enum Curr32k{LOW_CURRENT_RECOMMENDED,HIGH_CURENT};
enum Sel_start_fire{START_FIRE_TDCGP_MODE,FIRE_FOR_START};
enum Sel_tsto2{
	EN_START_ENABLE_START,
	EN_START_OUTPUT_START_TDC,
	EN_START_OUTPUT_STOP1_TDC,
	EN_START_OUTPUT_STOP2_TDC,
	EN_START_OUTPUT_STOP_TEMP,
	EN_START_TOF_UP,
	EN_START_RESERVE,
	EN_START_OUTPUT_FREQUENCY
};
enum Sel_tsto1{
	FIRE_IN,
	FIRE_IN_OUTPUT_START_TDC,
	FIRE_IN_OUTPUT_STOP1_TDC,
	FIRE_IN_OUTPUT_STOP2_TDC,
	FIRE_IN_OUTPUT_START_TEMP,
	FIRE_IN_TOF_UP,
	FIRE_IN_RUN_HA,
	FIRE_IN_OUTPUT_FREQUENCY
};
__packed struct Tdcgp2_register_1{
	enum Hit2 hit2 											: 0x4;
	enum Hit1 hit1 											: 0x4;
	enum En_fast_init en_fast_init 			: 0x1;
	uint8_t kd                      		: 0X1;
	enum Hitin2 hitin2 									: 0x3;
	enum Hitin1 hitin1									: 0x3;
	enum Curr32k curr32k								: 0x1;
	enum Sel_start_fire	sel_start_fire	: 0x1;
	enum Sel_tsto2 sel_tsto2						: 0x3;
	enum Sel_tsto1 sel_tsto1						: 0x3;
	uint8_t ID 													: 0x8;
};

enum En_int{
	INT_DISABLE,
	INT_ALU,
	INT_HIT,
	INT_ALU_HIT,
	INT_TIMEOUT,
	INT_TIMEOUT_ALU,
	INT_TIMEOUT_HIT,
	INT_TIMEOUT_ALU_HIT
};
enum Rfedge2{CH2_RISING_OR_FALLING,CH2_RISSING_AND_FALLING};
enum Rfedge1{CH1_RISING_OR_FALLING,CH1_RISSING_AND_FALLING};

__packed struct Tdcgp2_register_2{
	enum En_int en_int					: 0x3;
	enum Rfedge2	rfedge2				:	0x1;
	enum Rfedge1	rfedge1				: 0x1;
	uint16_t delay_stop_int     : 0xE;
	uint8_t delay_stop_frac     : 0x5;
	uint8_t ID 									: 0x8;
};

enum En_autocal_mb2{EN_AUTOCAL_DISABLE,EN_AUTOCAL_ENABLE};
enum En_err_val{TIMEOUT_NOT_ALU,TIMEOUT_WRITE_ALU};
enum En_first_wave{EN_FIRST_WAVE_DISABLE,EN_FIRST_WAVE_ENABLE};
enum Sel_timo_mb2{TIMOUT_64_mkS,TIMOUT_256_mkS,TIMOUT_1024_mkS,TIMOUT_4096_mkS}; // if 4MGz Clkhs
__packed struct General_register_3{
	enum En_autocal_mb2 en_autocal_mb2 	: 0x1;
	enum En_first_wave en_first_wawe 		: 0x1;
	enum En_err_val en_err_value 				: 0x1;
	enum Sel_timo_mb2 									: 0x02;
	uint8_t reserve											:	0x1;
};

__packed struct Tdcgp2_register_3_autowave0{
	struct General_register_3 gen_reg_3;
	uint16_t delay_stop_int     	: 0xE;
	uint8_t delay_stop_frac     	: 0x5;
	uint8_t ID 										: 0x8;
};
__packed struct Tdcgp2_register_3_autowave1{
	struct General_register_3 gen_reg_3;
	uint8_t delrel3								: 0x6;
	uint8_t delrel2								: 0x6;
	uint8_t delrel1								: 0x6;
	uint8_t ID 										: 0x8;
};






void tdcgp22_set_register0(struct Tdcgp2_register_0 tdcgp22_register_0);
void tdcgp22_set_register1(struct Tdcgp2_register_1 tdcgp22_register_1);
void tdcgp22_set_register2(struct Tdcgp2_register_2 tdcgp22_register_2);
void tdcgp22_set_register3_autowave0(struct Tdcgp2_register_3_autowave0 tdcgp2_register_3_autowave0);
void tdcgp22_set_register3_autowave1(struct Tdcgp2_register_3_autowave1 tdcgp2_register_3_autowave1);
