/*
 * dllgc.cpp
 *
 *  Created on: 2021年12月13日
 *      Author: XU
 */

#include "dllgc.h"
#include "timercpp.h"
#include "CJsonObject.hpp"
#include <stdio.h>
#include <modbus/modbus.h>
#include <iostream>
#include <string>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>
#include <mongocxx/pool.hpp>
#include <mongocxx/cursor.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/builder/basic/array.hpp>
#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/json.hpp>
#include <bsoncxx/types/value.hpp>
#include <cmath>
#include <iomanip>
#include <vector>
using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::make_array;
using bsoncxx::builder::basic::make_document;
using bsoncxx::builder::basic::sub_array;
neb::CJsonObject modbus_device("{"
"\"PCS\":{"
	"\"delta\":{"
		"\"Order\":2,"
		"\"Fc\":[4, 3],"
		"\"Address\":[0, 0],"
		"\"Length\":[80, 20],"
		"\"Bit_Length\":26,"
		"\"Point\":{"
			"\"v1_grid\":{"
				"\"order\":0,"
				"\"address\":2,"
				"\"length\":1,"
				"\"type\":\"int\","
				"\"scale\":1.0"
			"},"
			"\"v2_grid\":{"
				"\"order\":0,"
				"\"address\":3,"
				"\"length\":1,"
				"\"type\":\"int\","
				"\"scale\":1.0"
			"},"
			"\"v3_grid\":{"
				"\"order\":0,"
				"\"address\":4,"
				"\"length\":1,"
				"\"type\":\"int\","
				"\"scale\":1.0"
			"},"
			"\"i1_grid\":{"
				"\"order\":0,"
				"\"address\":5,"
				"\"length\":1,"
				"\"type\":\"int\","
				"\"scale\":10.0"
			"},"
			"\"i2_grid\":{"
				"\"order\":0,"
				"\"address\":6,"
				"\"length\":1,"
				"\"type\":\"int\","
				"\"scale\":10.0"
			"},"
			"\"i3_grid\":{"
				"\"order\":0,"
				"\"address\":7,"
				"\"length\":1,"
				"\"type\":\"int\","
				"\"scale\":10.0"
			"},"
			"\"p_grid\":{"
				"\"order\":0,"
				"\"address\":8,"
				"\"length\":1,"
				"\"type\":\"int\","
				"\"scale\":10.0"
			"},"
			"\"q_grid\":{"
				"\"order\":0,"
				"\"address\":9,"
				"\"length\":1,"
				"\"type\":\"int\","
				"\"scale\":10.0"
			"},"
			"\"pf_grid\":{"
				"\"order\":0,"
				"\"address\":10,"
				"\"length\":1,"
				"\"type\":\"int\","
				"\"scale\":10000.0"
			"},"
			"\"f_grid\":{"
				"\"order\":0,"
				"\"address\":11,"
				"\"length\":1,"
				"\"type\":\"uint\","
				"\"scale\":100.0"
			"},"
			"\"v1_pcs\":{"
				"\"order\":0,"
				"\"address\":12,"
				"\"length\":1,"
				"\"type\":\"int\","
				"\"scale\":10.0"
			"},"
			"\"v2_pcs\":{"
				"\"order\":0,"
				"\"address\":13,"
				"\"length\":1,"
				"\"type\":\"int\","
				"\"scale\":10.0"
			"},"
			"\"v3_pcs\":{"
				"\"order\":0,"
				"\"address\":14,"
				"\"length\":1,"
				"\"type\":\"int\","
				"\"scale\":10.0"
			"},"
			"\"i1_pcs\":{"
				"\"order\":0,"
				"\"address\":15,"
				"\"length\":1,"
				"\"type\":\"int\","
				"\"scale\":100.0"
			"},"
			"\"i2_pcs\":{"
				"\"order\":0,"
				"\"address\":16,"
				"\"length\":1,"
				"\"type\":\"int\","
				"\"scale\":100.0"
			"},"
			"\"i3_pcs\":{"
				"\"order\":0,"
				"\"address\":17,"
				"\"length\":1,"
				"\"type\":\"int\","
				"\"scale\":100.0"
			"},"
			"\"p_sum\":{"
				"\"order\":0,"
				"\"address\":18,"
				"\"length\":1,"
				"\"type\":\"int\","
				"\"scale\":10.0"
			"},"
			"\"q_sum\":{"
				"\"order\":0,"
				"\"address\":19,"
				"\"length\":1,"
				"\"type\":\"int\","
				"\"scale\":10.0"
			"},"
			"\"pf\":{"
				"\"order\":0,"
				"\"address\":20,"
				"\"length\":1,"
				"\"type\":\"int\","
				"\"scale\":10000.0"
			"},"
			"\"f_pcs_low\":{"
				"\"order\":0,"
				"\"address\":21,"
				"\"length\":1,"
				"\"type\":\"uint\","
				"\"scale\":100.0"
			"},"
			"\"p_dc\":{"
				"\"order\":0,"
				"\"address\":26,"
				"\"length\":1,"
				"\"type\":\"int\","
				"\"scale\":10.0"
			"},"
			"\"status_pcs_1\":{"
				"\"order\":0,"
				"\"address\":52,"
				"\"length\":1,"
				"\"type\":\"bit\","
				"\"scale\":1.0"
			"},"
			"\"status_pcs_2\":{"
				"\"order\":0,"
				"\"address\":53,"
				"\"length\":1,"
				"\"type\":\"bit\","
				"\"scale\":1.0"
			"},"
			"\"status_system\":{"
				"\"order\":0,"
				"\"address\":54,"
				"\"length\":1,"
				"\"type\":\"bit\","
				"\"scale\":1.0"
			"},"
			"\"mode_pcs\":{"
				"\"order\":0,"
				"\"address\":55,"
				"\"length\":1,"
				"\"type\":\"bit\","
				"\"scale\":1.0"
			"},"
			"\"module1_fault1\":{"
				"\"order\":0,"
				"\"address\":56,"
				"\"length\":1,"
				"\"type\":\"bit\","
				"\"scale\":1.0"
			"},"
			"\"module1_fault2\":{"
				"\"order\":0,"
				"\"address\":57,"
				"\"length\":1,"
				"\"type\":\"bit\","
				"\"scale\":1.0"
			"},"
			"\"module1_fault3\":{"
				"\"order\":0,"
				"\"address\":58,"
				"\"length\":1,"
				"\"type\":\"bit\","
				"\"scale\":1.0"
			"},"
			"\"module2_fault1\":{"
				"\"order\":0,"
				"\"address\":59,"
				"\"length\":1,"
				"\"type\":\"bit\","
				"\"scale\":1.0"
			"},"
			"\"module2_fault2\":{"
				"\"order\":0,"
				"\"address\":60,"
				"\"length\":1,"
				"\"type\":\"bit\","
				"\"scale\":1.0"
			"},"
			"\"module2_fault3\":{"
				"\"order\":0,"
				"\"address\":61,"
				"\"length\":1,"
				"\"type\":\"bit\","
				"\"scale\":1.0"
			"},"
			"\"module3_fault1\":{"
				"\"order\":0,"
				"\"address\":62,"
				"\"length\":1,"
				"\"type\":\"bit\","
				"\"scale\":1.0"
			"},"
			"\"module3_fault2\":{"
				"\"order\":0,"
				"\"address\":63,"
				"\"length\":1,"
				"\"type\":\"bit\","
				"\"scale\":1.0"
			"},"
			"\"module3_fault3\":{"
				"\"order\":0,"
				"\"address\":64,"
				"\"length\":1,"
				"\"type\":\"bit\","
				"\"scale\":1.0"
			"},"
			"\"module4_fault1\":{"
				"\"order\":0,"
				"\"address\":65,"
				"\"length\":1,"
				"\"type\":\"bit\","
				"\"scale\":1.0"
			"},"
			"\"module4_fault2\":{"
				"\"order\":0,"
				"\"address\":66,"
				"\"length\":1,"
				"\"type\":\"bit\","
				"\"scale\":1.0"
			"},"
			"\"module4_fault3\":{"
				"\"order\":0,"
				"\"address\":67,"
				"\"length\":1,"
				"\"type\":\"bit\","
				"\"scale\":1.0"
			"},"
			"\"system_fault1\":{"
				"\"order\":0,"
				"\"address\":68,"
				"\"length\":1,"
				"\"type\":\"bit\","
				"\"scale\":1.0"
			"},"
			"\"system_fault2\":{"
				"\"order\":0,"
				"\"address\":69,"
				"\"length\":1,"
				"\"type\":\"bit\","
				"\"scale\":1.0"
			"},"
			"\"system_fault3\":{"
				"\"order\":0,"
				"\"address\":70,"
				"\"length\":1,"
				"\"type\":\"bit\","
				"\"scale\":1.0"
			"},"
			"\"cooling_fault\":{"
				"\"order\":0,"
				"\"address\":71,"
				"\"length\":1,"
				"\"type\":\"bit\","
				"\"scale\":1.0"
			"},"
			"\"fan_fault\":{"
				"\"order\":0,"
				"\"address\":72,"
				"\"length\":1,"
				"\"type\":\"bit\","
				"\"scale\":1.0"
			"},"
			"\"system_warning\":{"
				"\"order\":0,"
				"\"address\":73,"
				"\"length\":1,"
				"\"type\":\"bit\","
				"\"scale\":1.0"
			"},"
			"\"control_word1\":{"
				"\"order\":1,"
				"\"address\":0,"
				"\"length\":1,"
				"\"type\":\"bit\","
				"\"scale\":1.0"
			"},"
			"\"control_word2\":{"
				"\"order\":1,"
				"\"address\":1,"
				"\"length\":1,"
				"\"type\":\"bit\","
				"\"scale\":1.0"
			"},"
			"\"control_word3\":{"
				"\"order\":1,"
				"\"address\":2,"
				"\"length\":1,"
				"\"type\":\"bit\","
				"\"scale\":1.0"
			"},"
			"\"rst_word\":{"
				"\"order\":1,"
				"\"address\":3,"
				"\"length\":1,"
				"\"type\":\"bit\","
				"\"scale\":1.0"
			"},"
			"\"PQ_p_out\":{"
				"\"order\":1,"
				"\"address\":10,"
				"\"length\":1,"
				"\"type\":\"int\","
				"\"scale\":10.0"
			"},"
			"\"PQ_q_out\":{"
				"\"order\":1,"
				"\"address\":11,"
				"\"length\":1,"
				"\"type\":\"int\","
				"\"scale\":10.0"
			"}"
		"}"
	"}"
"},"
"\"meter\":{"
	"\"ION9000\":{"
		"\"Order\":2,"
		"\"Fc\":[3, 3],"
		"\"Address\":[20999, 2699],"
		"\"Length\":[72, 24],"
		"\"Point\":{"
			"\"i_a\":{"
				"\"order\":0,"
				"\"address\":20999,"
				"\"length\":2,"
				"\"type\":\"float\","
				"\"scale\":1.0"
			"},"
			"\"i_b\":{"
				"\"order\":0,"
				"\"address\":21001,"
				"\"length\":2,"
				"\"type\":\"float\","
				"\"scale\":1.0"
			"},"
			"\"i_c\":{"
				"\"order\":0,"
				"\"address\":21003,"
				"\"length\":2,"
				"\"type\":\"float\","
				"\"scale\":1.0"
			"},"
			"\"i\":{"
				"\"order\":0,"
				"\"address\":21009,"
				"\"length\":2,"
				"\"type\":\"float\","
				"\"scale\":1.0"
			"},"
			"\"f\":{"
				"\"order\":0,"
				"\"address\":21015,"
				"\"length\":2,"
				"\"type\":\"float\","
				"\"scale\":1.0"
			"},"
			"\"vl_ab\":{"
				"\"order\":0,"
				"\"address\":21017,"
				"\"length\":2,"
				"\"type\":\"float\","
				"\"scale\":1.0"
			"},"
			"\"vl_bc\":{"
				"\"order\":0,"
				"\"address\":21019,"
				"\"length\":2,"
				"\"type\":\"float\","
				"\"scale\":1.0"
			"},"
			"\"vl_ca\":{"
				"\"order\":0,"
				"\"address\":21021,"
				"\"length\":2,"
				"\"type\":\"float\","
				"\"scale\":1.0"
			"},"
			"\"vl\":{"
				"\"order\":0,"
				"\"address\":21023,"
				"\"length\":2,"
				"\"type\":\"float\","
				"\"scale\":1.0"
			"},"
			"\"v_a\":{"
				"\"order\":0,"
				"\"address\":21025,"
				"\"length\":2,"
				"\"type\":\"float\","
				"\"scale\":1.0"
			"},"
			"\"v_b\":{"
				"\"order\":0,"
				"\"address\":21027,"
				"\"length\":2,"
				"\"type\":\"float\","
				"\"scale\":1.0"
			"},"
			"\"v_c\":{"
				"\"order\":0,"
				"\"address\":21029,"
				"\"length\":2,"
				"\"type\":\"float\","
				"\"scale\":1.0"
			"},"
			"\"v\":{"
				"\"order\":0,"
				"\"address\":21033,"
				"\"length\":2,"
				"\"type\":\"float\","
				"\"scale\":1.0"
			"},"
			"\"p_a\":{"
				"\"order\":0,"
				"\"address\":21039,"
				"\"length\":2,"
				"\"type\":\"float\","
				"\"scale\":1000.0"
			"},"
			"\"p_b\":{"
				"\"order\":0,"
				"\"address\":21041,"
				"\"length\":2,"
				"\"type\":\"float\","
				"\"scale\":1000.0"
			"},"
			"\"p_c\":{"
				"\"order\":0,"
				"\"address\":21043,"
				"\"length\":2,"
				"\"type\":\"float\","
				"\"scale\":1000.0"
			"},"
			"\"p\":{"
				"\"order\":0,"
				"\"address\":21045,"
				"\"length\":2,"
				"\"type\":\"float\","
				"\"scale\":1000.0"
			"},"
			"\"q_a\":{"
				"\"order\":0,"
				"\"address\":21047,"
				"\"length\":2,"
				"\"type\":\"float\","
				"\"scale\":1000.0"
			"},"
			"\"q_b\":{"
				"\"order\":0,"
				"\"address\":21049,"
				"\"length\":2,"
				"\"type\":\"float\","
				"\"scale\":1000.0"
			"},"
			"\"q_c\":{"
				"\"order\":0,"
				"\"address\":21051,"
				"\"length\":2,"
				"\"type\":\"float\","
				"\"scale\":1000.0"
			"},"
			"\"q\":{"
				"\"order\":0,"
				"\"address\":21053,"
				"\"length\":2,"
				"\"type\":\"float\","
				"\"scale\":1000.0"
			"},"
			"\"s_a\":{"
				"\"order\":0,"
				"\"address\":21055,"
				"\"length\":2,"
				"\"type\":\"float\","
				"\"scale\":1000.0"
			"},"
			"\"s_b\":{"
				"\"order\":0,"
				"\"address\":21057,"
				"\"length\":2,"
				"\"type\":\"float\","
				"\"scale\":1000.0"
			"},"
			"\"s_c\":{"
				"\"order\":0,"
				"\"address\":21059,"
				"\"length\":2,"
				"\"type\":\"float\","
				"\"scale\":1000.0"
			"},"
			"\"s\":{"
				"\"order\":0,"
				"\"address\":21061,"
				"\"length\":2,"
				"\"type\":\"float\","
				"\"scale\":1000.0"
			"},"
			"\"pf_a\":{"
				"\"order\":0,"
				"\"address\":21063,"
				"\"length\":2,"
				"\"type\":\"float\","
				"\"scale\":1.0"
			"},"
			"\"pf_b\":{"
				"\"order\":0,"
				"\"address\":21065,"
				"\"length\":2,"
				"\"type\":\"float\","
				"\"scale\":1.0"
			"},"
			"\"pf_c\":{"
				"\"order\":0,"
				"\"address\":21067,"
				"\"length\":2,"
				"\"type\":\"float\","
				"\"scale\":1.0"
			"},"
			"\"pf\":{"
				"\"order\":0,"
				"\"address\":21069,"
				"\"length\":2,"
				"\"type\":\"float\","
				"\"scale\":1.0"
			"},"
			"\"imp_kwh\":{"
				"\"order\":1,"
				"\"address\":2699,"
				"\"length\":2,"
				"\"type\":\"float\","
				"\"scale\":1.0"
			"},"
			"\"exp_kwh\":{"
				"\"order\":1,"
				"\"address\":2701,"
				"\"length\":2,"
				"\"type\":\"float\","
				"\"scale\":1.0"
			"},"
			"\"tot_kwh\":{"
				"\"order\":1,"
				"\"address\":2703,"
				"\"length\":2,"
				"\"type\":\"float\","
				"\"scale\":1.0"
			"},"
			"\"net_kwh\":{"
				"\"order\":1,"
				"\"address\":2705,"
				"\"length\":2,"
				"\"type\":\"float\","
				"\"scale\":1.0"
			"},"
			"\"imp_kvarh\":{"
				"\"order\":1,"
				"\"address\":2707,"
				"\"length\":2,"
				"\"type\":\"float\","
				"\"scale\":1.0"
			"},"
			"\"exp_kvarh\":{"
				"\"order\":1,"
				"\"address\":2709,"
				"\"length\":2,"
				"\"type\":\"float\","
				"\"scale\":1.0"
			"},"
			"\"tot_kvarh\":{"
				"\"order\":1,"
				"\"address\":2711,"
				"\"length\":2,"
				"\"type\":\"float\","
				"\"scale\":1.0"
			"},"
			"\"net_kvarh\":{"
				"\"order\":1,"
				"\"address\":2713,"
				"\"length\":2,"
				"\"type\":\"float\","
				"\"scale\":1.0"
			"},"
			"\"imp_kvah\":{"
				"\"order\":1,"
				"\"address\":2715,"
				"\"length\":2,"
				"\"type\":\"float\","
				"\"scale\":1.0"
			"},"
			"\"exp_kvah\":{"
				"\"order\":1,"
				"\"address\":2717,"
				"\"length\":2,"
				"\"type\":\"float\","
				"\"scale\":1.0"
			"},"
			"\"tot_kvah\":{"
				"\"order\":1,"
				"\"address\":2719,"
				"\"length\":2,"
				"\"type\":\"float\","
				"\"scale\":1.0"
			"},"
			"\"net_kvah\":{"
				"\"order\":1,"
				"\"address\":2721,"
				"\"length\":2,"
				"\"type\":\"float\","
				"\"scale\":1.0"
			"}"

		"}"
	"}"
"}"
"}");
dllgc::dllgc() {
	mongocxx::instance::current();
}
dllgc::~dllgc() {
}
void dllgc::print() {
	printf("AFC_GC.dll1\n");
}
typedef struct CPUPACKED {
	char name[20];
	unsigned int user;
	unsigned int nice;
	unsigned int system;
	unsigned int idle;
	unsigned int lowait;
	unsigned int irq;
	unsigned int softirq;
} CPU_OCCUPY;
double GetTotalPhysicalMemoryUsed() {
	/*memory GB*/
	MEMORYSTATUSEX memInfo;
	memInfo.dwLength = sizeof(MEMORYSTATUSEX);
	GlobalMemoryStatusEx(&memInfo);
	double physMemUsed = (((memInfo.ullTotalPhys - memInfo.ullAvailPhys) / 1024
			/ 1024) * 100) / 1024;
	double fTemMemUsed = physMemUsed / 100.0;
	return fTemMemUsed;
}
double GetPhysicalMemoryUsage() {
	/*memory %*/
	MEMORYSTATUSEX memInfo;
	memInfo.dwLength = sizeof(MEMORYSTATUSEX);
	GlobalMemoryStatusEx(&memInfo);
	double MemUsage = memInfo.dwMemoryLoad;
	return MemUsage;
}
__int64 CompareFileTime(FILETIME time1, FILETIME time2) {
	__int64 a = time1.dwHighDateTime << 32 | time1.dwLowDateTime;
	__int64 b = time2.dwHighDateTime << 32 | time2.dwLowDateTime;

	return (b - a);
}
double getWin_CpuUsage() {
	HANDLE hEvent;
	BOOL res;
	FILETIME preidleTime;
	FILETIME prekernelTime;
	FILETIME preuserTime;
	FILETIME idleTime;
	FILETIME kernelTime;
	FILETIME userTime;

	res = GetSystemTimes(&idleTime, &kernelTime, &userTime);
	preidleTime = idleTime;
	prekernelTime = kernelTime;
	preuserTime = userTime;

	hEvent = CreateEventA(NULL, FALSE, FALSE, NULL);
	WaitForSingleObject(hEvent, 300);
	res = GetSystemTimes(&idleTime, &kernelTime, &userTime);

	__int64 idle = CompareFileTime(preidleTime, idleTime);
	__int64 kernel = CompareFileTime(prekernelTime, kernelTime);
	__int64 user = CompareFileTime(preuserTime, userTime);

	__int64 cpu = (kernel + user - idle) * 100 / (kernel + user);
//	__int64 cpuidle = (idle) * 100 / (kernel + user);
//	cout << "CPU_user:" << cpu << "%" << " CPU_space:" << cpuidle << "%" << endl;
	preidleTime = idleTime;
	prekernelTime = kernelTime;
	preuserTime = userTime;
	if (cpu > 100) {
		cpu = 100;
	}
	if (cpu < 0) {
		cpu = 0;
	}
	return cpu;
}
void modbus_find(modbus_t *ctx, neb::CJsonObject mode, int &ret, bool &read_ok, int **arr) {
	int device_order;
	mode.Get("Order", device_order);
	std::string point_type;
	for (int y = 0; y < device_order; y++) {
		int device_Fc;
		mode["Fc"].Get(y, device_Fc);
		int device_Address;
		mode["Address"].Get(y, device_Address);
		int device_Length;
		mode["Length"].Get(y, device_Length);
		if (device_Fc == 3) {
			uint16_t table_16[device_Length];
			ret = modbus_read_registers(ctx, device_Address, device_Length,
					table_16);
			if (ret > 0) {
				for (int x = 0; x < ret; x++) {
					arr[y][x] = table_16[x];
//					printf("reg[%d]=%d (0x%X)\n", x, table_16[x], table_16[x]);
//					fflush(stdout);
				}
				read_ok = true;
			} else {
//				std::cout << "read_start[y] :" << read_start[y]
//						<< " read_length[y] :" << read_length[y] << std::endl;
//				std::cout << "modbus dont find data" << std::endl;
//				fflush(stdout);
				read_ok = false;
			}
		}
		else if (device_Fc == 4) {
			uint16_t table_16[device_Length];
			ret = modbus_read_input_registers(ctx, device_Address, device_Length,
					table_16);
			if (ret > 0) {
				for (int x = 0; x < ret; x++) {
					arr[y][x] = table_16[x];
//					printf("reg[%d]=%d (0x%X)\n", x, table_16[x], table_16[x]);
//					fflush(stdout);
				}
				read_ok = true;
			} else {
//				std::cout << "read_start[y] :" << read_start[y]
//						<< " read_length[y] :" << read_length[y] << std::endl;
//				std::cout << "modbus dont find data" << std::endl;
//				fflush(stdout);
				read_ok = false;
			}
		}
	}
}
void dReg_mode(std::string &control_point, char &path_dReg, double &pcs_out_p,
		double soc, double FP_soc_goal_percent, double FP_soc_dead_band,
		int FP_type, double HM_f, double *f_arr, double *p_arr, double a1,
		double b1, double a21, double b21, double a22, double b22, double a23,
		double b23, double b3, double a41, double b41, double a42, double b42,
		double a43, double b43, double a5, double b5) {
	try {
		/*dReg計算*/
//		std::cout <<"dReg start"<< std::endl;
//		std::cout <<"HM_f :" <<HM_f<< std::endl;
		if (HM_f <= f_arr[0]) {
			pcs_out_p = p_arr[0];
//			std::cout <<"a0 HM_f :" <<HM_f<< std::endl;
//			std::cout << "p_arr[0] :" << p_arr[0]<< std::endl;
			control_point = "d0";
		} else if (HM_f > f_arr[0] and HM_f <= f_arr[1]) {
			pcs_out_p = HM_f * a1 + b1;
//			std::cout <<"a1 :"<< std::to_string(a1) <<" b1 :" << std::to_string(b1) << " HM_f :" <<std::to_string(HM_f)<< std::endl;
			control_point = "d1";
		} else if (HM_f > f_arr[1] and HM_f <= f_arr[2]) {
			if (path_dReg == 'H') {
				pcs_out_p = HM_f * a21 + b21;
//				std::cout <<"a21 :"<< std::to_string(a21) <<" b21 :" << std::to_string(b21) << " HM_f :" <<std::to_string(HM_f)<< std::endl;
				control_point = "d21";
			} else if (path_dReg == 'N') {
				pcs_out_p = HM_f * a22 + b22;
//				std::cout <<"a22 :"<< std::to_string(a22) <<" b22 :" << std::to_string(b22) << " HM_f :" <<std::to_string(HM_f)<< std::endl;
				control_point = "d22";
			} else if (path_dReg == 'L') {
				pcs_out_p = HM_f * a23 + b23;
//				std::cout <<"a23 :"<< std::to_string(a23) <<" b23 :" << std::to_string(b23) << " HM_f :" <<std::to_string(HM_f)<< std::endl;
				control_point = "d23";
			} else {
			}
		} else if (HM_f > f_arr[2] and HM_f < f_arr[3]) {
			/*換線*/
			if (soc > (FP_soc_goal_percent + FP_soc_dead_band)) {
				path_dReg = 'H';
			} else if ((soc <= (FP_soc_goal_percent + FP_soc_dead_band))
					and (soc >= (FP_soc_goal_percent - FP_soc_dead_band))) {
				if (path_dReg == 'H' and (soc <= FP_soc_goal_percent)) {
					path_dReg = 'N';
				} else if (path_dReg == 'L' and (soc >= FP_soc_goal_percent)) {
					path_dReg = 'N';
				} else {
				}
			} else if (soc < (FP_soc_goal_percent - FP_soc_dead_band)) {
				path_dReg = 'L';
			}
			if (path_dReg == 'H') {
				pcs_out_p = b3;
//				std::cout <<" b31 :" << std::to_string(b3) << " HM_f :" <<std::to_string(HM_f)<< std::endl;
				control_point = "d31";
			} else if (path_dReg == 'N') {
				pcs_out_p = 0;
//				std::cout <<" b32 : 0"  << " HM_f :" <<std::to_string(HM_f)<< std::endl;
				control_point = "d32";
			} else if (path_dReg == 'L') {
				pcs_out_p = -b3;
//				std::cout <<" b33 :" << std::to_string(-b3) << " HM_f :" <<std::to_string(HM_f)<< std::endl;
				control_point = "d33";
			} else {
			}
		} else if (HM_f >= f_arr[3] and HM_f < f_arr[4]) {
			if (path_dReg == 'H') {
				pcs_out_p = HM_f * a41 + b41;
//				std::cout <<"a41 :"<< std::to_string(a41) <<" b41 :" << std::to_string(b41) << " HM_f :" <<std::to_string(HM_f)<< std::endl;
				control_point = "d41";
			} else if (path_dReg == 'N') {
				pcs_out_p = HM_f * a42 + b42;
//				std::cout <<"a42 :"<< std::to_string(a42) <<" b42 :" << std::to_string(b42) << " HM_f :" <<std::to_string(HM_f)<< std::endl;
				control_point = "d42";
			} else if (path_dReg == 'L') {
				pcs_out_p = HM_f * a43 + b43;
//				std::cout <<"a43 :"<< std::to_string(a43) <<" b43 :" << std::to_string(b43) << " HM_f :" <<std::to_string(HM_f)<< std::endl;
				control_point = "d43";
			} else {
			}
		} else if (HM_f >= f_arr[4] and HM_f < f_arr[5]) {
			pcs_out_p = HM_f * a5 + b5;
//			std::cout <<"a5 :"<< std::to_string(a5) <<" b5 :" << std::to_string(b5) << " HM_f :" <<std::to_string(HM_f)<< std::endl;
			control_point = "d5";

		} else if (HM_f >= f_arr[5]) {
			pcs_out_p = p_arr[5];
//			std::cout <<"a6 HM_f :" <<HM_f<< std::endl;
			control_point = "d6";
		} else {
		}
//		std::cout <<"pcs_out_p :" <<pcs_out_p<< std::endl;
	} catch (...) {
	}
}
void sReg_mode(std::string &control_point, char &path_sReg, double &pcs_out_p,
		double soc, double FP_soc_goal_percent, double FP_soc_dead_band,
		double HM_f, double *f_arr, double *p_arr, bool &sReg_flag,
		double a_sReg, double b_sReg) {
	if (HM_f <= f_arr[0]) {
		sReg_flag = true;
	} else if (HM_f >= f_arr[1]) {
		sReg_flag = false;
	}
	/*換線*/
	if (soc >= (FP_soc_goal_percent)) {
		path_sReg = 'N';
	} else if (soc < (FP_soc_goal_percent - FP_soc_dead_band)) {
		path_sReg = 'L';
	} else {
	}
	if (HM_f <= f_arr[0]) {
		pcs_out_p = p_arr[0];
	} else if (HM_f > f_arr[0] and HM_f <= f_arr[1]) {
		if (sReg_flag == false) { /*false*/
			pcs_out_p = 0;
		} else { /*true*/
			pcs_out_p = p_arr[0];
		}
	} else if (HM_f > f_arr[1] and HM_f <= f_arr[2]) {
		pcs_out_p = 0;
	} else if (HM_f > f_arr[2] and HM_f <= f_arr[3]) {
		if (path_sReg == 'N') {
			pcs_out_p = 0;
		} else if (path_sReg == 'L') {
			pcs_out_p = a_sReg * HM_f + b_sReg;
		} else {
		}
	} else if (HM_f >= f_arr[3]) {
		if (path_sReg == 'N') {
			pcs_out_p = 0;
		} else if (path_sReg == 'L') {
			pcs_out_p = p_arr[3];
		}

	} else {
	}
}
void VQ_mode(int VC_type, double &pcs_out_q, double pcs_out_p,
		bool &VQ_Hys_line, double &HM_v_last, double HM_v, double *v_arr,
		double *q_arr, double PQ_q_ref, double PF_pf_ref, double Vq_v_base,
		double Vq_q_base, double Vq_droop, double Vq_v_set) {
	try {
		if (VC_type == 0) {
			pcs_out_q = 0;
		} else if (VC_type == 1) {
			pcs_out_q = (-Vq_droop) * HM_v
					+ (-((-Vq_droop) * Vq_v_base * Vq_v_set));
		} else if (VC_type == 2) {
			pcs_out_q = PQ_q_ref;
		} else if (VC_type == 3) {
			PQ_q_ref = pow(
					(pow((pcs_out_p * 1.0 / PF_pf_ref), 2)
							- pow((pcs_out_p * 1.0), 2)), 0.5);
		} else if (VC_type == 4) {
			HM_v = HM_v * 100 / Vq_v_base;/*HM_v轉%表示*/
			/*遲滯區外 由左至右*/
			if (HM_v <= v_arr[0]) {
				pcs_out_q = q_arr[0];
				HM_v_last = HM_v;
			} else if (HM_v > v_arr[0] and HM_v <= v_arr[5]) {
				pcs_out_q = (HM_v - v_arr[0]) * (q_arr[5] - q_arr[0])
						/ (v_arr[5] - v_arr[0]) + q_arr[0];
				HM_v_last = HM_v;
			} else if (HM_v >= v_arr[2] and HM_v < v_arr[3]) {
				pcs_out_q = (HM_v - v_arr[2]) * (q_arr[3] - q_arr[2])
						/ (v_arr[3] - v_arr[2]) + q_arr[2];
				HM_v_last = HM_v;
			} else if (HM_v >= v_arr[3]) {
				pcs_out_q = q_arr[3];
				HM_v_last = HM_v;
			}
			/*遲滯區內*/
			else if (HM_v > v_arr[5] and HM_v < v_arr[2]) {
				if (HM_v > HM_v_last) {/*電壓增加*/
					if (VQ_Hys_line == 1) {/*藍曲線*/
						if (HM_v < v_arr[1]) {/*上邊界*/
							pcs_out_q = q_arr[1];
						} else {/*右邊界*/
							pcs_out_q = (HM_v - v_arr[1])
									* (q_arr[2] - q_arr[1])
									/ (v_arr[2] - v_arr[1]) + q_arr[1];
							HM_v_last = HM_v;
						}
					} else if (VQ_Hys_line == 0) {/*橘曲線*/
						if (HM_v
								<= ((pcs_out_q - q_arr[1])
										* (v_arr[2] - v_arr[1])
										/ (q_arr[2] - q_arr[1]) + v_arr[1])) {/*遲滯保持不變*/
						} else {/*到達藍曲線*/
							pcs_out_q = (HM_v - v_arr[1])
									* (q_arr[2] - q_arr[1])
									/ (v_arr[2] - v_arr[1]) + q_arr[1];
							VQ_Hys_line = true;
						}
					}
				} else if (HM_v < HM_v_last) {/*電壓漸少*/
					if (VQ_Hys_line == 0) {/*橘曲線*/
						if (HM_v >= v_arr[4]) {/*上邊界*/
							pcs_out_q = q_arr[4];
						} else {/*左邊界*/
							pcs_out_q = (HM_v - v_arr[5])
									* (q_arr[4] - q_arr[5])
									/ (v_arr[4] - v_arr[5]) + q_arr[5];
							HM_v_last = HM_v;
						}
					} else if (VQ_Hys_line == 1) {/*藍曲線*/
						if (HM_v
								>= ((pcs_out_q - q_arr[4])
										* (v_arr[5] - v_arr[4])
										/ (q_arr[5] - q_arr[4]) + v_arr[4])) {/*遲滯保持不變*/
						} else {/*到達藍曲線*/
							pcs_out_q = (HM_v - v_arr[5])
									* (q_arr[4] - q_arr[5])
									/ (v_arr[4] - v_arr[5]) + q_arr[5];
							VQ_Hys_line = false;
						}
					}
				}
			}
		}
	} catch (...) {
	}
}
void mongo_time(bsoncxx::v_noabi::document::view doc, std::string point_name,
		double &return_data) {
	try {
		bsoncxx::document::element bson_data = doc[point_name];
		if (bson_data.type() == bsoncxx::type::k_date) {
//			std::cout << bsoncxx::to_json(doc) << std::endl;
			return_data = bson_data.get_date();
//			std::cout<<"return_data :"<<point_name<<" = "<< std::to_string(return_data) <<std::endl;
		} else {
			/* Error*/
		}
	} catch (...) {
	}
}
void mongo_data(bsoncxx::v_noabi::document::view doc, std::string point_name,
		double &return_data) {
	try {
		bsoncxx::document::element bson_data = doc[point_name];
		if (bson_data.type() == bsoncxx::type::k_double) {
			return_data = bson_data.get_double().value;
//			std::cout <<"get_double return_data :"<< return_data << std::endl;
		} else if (bson_data.type() == bsoncxx::type::k_int32) {
			return_data = bson_data.get_int32().value;
//			std::cout <<"get_int32 return_data :"<< return_data << std::endl;
		} else {
			/* Error*/
			return_data = -1;
			std::cout << "point_name: <<" << point_name << std::endl;
			std::cout << "else return_data :" << return_data << std::endl;
		}
	} catch (...) {
		return_data = -1;
	}
}
void mongo_dic(bsoncxx::v_noabi::document::view doc, std::string point_name,
		std::string *name, double *data, int &scale_len) {
	try {
		bsoncxx::document::element bson_data = doc[point_name];
		if (bson_data.type() == bsoncxx::type::k_document) {
			bsoncxx::document::view subdoc = bson_data.get_document().value;
			for (int x = 0; x < scale_len; x++) {
				bsoncxx::document::element data_buffer = subdoc[name[x]];
				data[x] = data_buffer.get_double().value;
			}
		} else {
			for (int x = 0; x < scale_len; x++) {
				data[x] = -1;
			}
		}
	} catch (...) {
		for (int x = 0; x < scale_len; x++) {
			data[x] = -1;
		}
	}
}
double Read_upload(neb::CJsonObject mode, neb::CJsonObject mode_point, int **modbus_data) {
	double return_data = 0;
	try {
		int point_order;
		mode_point.Get("order", point_order);
		int point_Address;
		mode_point.Get("address", point_Address);
		int point_length;
		mode_point.Get("length", point_length);
		std::string point_type;
		mode_point.Get("type", point_type);
		double point_scale;
		mode_point.Get("scale", point_scale);
		int device_Address;
		mode["Address"].Get(point_order, device_Address);
		if (point_type == "int") {

			for (int x = 0; x < point_length; x++) {
				return_data = ((uint32_t) return_data << 16)
						+ modbus_data[point_order][point_Address - device_Address + x];
			}
			if (point_length == 1) {
				uint16_t xorbit = 65535; /*256**2 -1*/
				uint16_t xorbit_test = 32768;/*(256**2)>>1*/
				if ((uint16_t) return_data
						> ((uint16_t) return_data ^ xorbit_test)) {
					return_data = -(((uint16_t) return_data ^ xorbit) + 1);
				}

			} else if (point_length == 2) {
				uint32_t xorbit = 4294967295; /*256**^4 -1*/
				uint32_t xorbit_test = 2147483648;/*(256^4)>>1*/
				if ((uint32_t) return_data
						> ((uint32_t) return_data ^ xorbit_test)) {
					return_data = -(((uint32_t) return_data ^ xorbit) + 1);
				}
			}
		} else if (point_type == "uint") {
			for (int x = 0; x < point_length; x++) {
				return_data = ((uint32_t) return_data << 16)
						+ modbus_data[point_order][point_Address - device_Address + x];
			}
		} else if (point_type == "bit") {/*顯示用*/
			for (int x = 0; x < point_length; x++) {
				return_data = ((uint32_t) return_data << 16)
						+ modbus_data[point_order][point_Address - device_Address + x];
			}
		} else if (point_type  == "float") {
			float temp;
			char *Modbus_HoldReg[4];
			Modbus_HoldReg[0] = ((char*) (&temp)) + 3;
			Modbus_HoldReg[1] = ((char*) (&temp)) + 2;
			Modbus_HoldReg[2] = ((char*) (&temp)) + 1;
			Modbus_HoldReg[3] = ((char*) (&temp)) + 0;
			*Modbus_HoldReg[0] = (modbus_data[point_order][point_Address - device_Address] >> 8)
					& 0xff;
			*Modbus_HoldReg[1] = modbus_data[point_order][point_Address - device_Address] & 0xff;
			*Modbus_HoldReg[2] = (modbus_data[point_order][point_Address - device_Address + 1]
					>> 8) & 0xff;
			*Modbus_HoldReg[3] = modbus_data[point_order][point_Address - device_Address + 1]
					& 0xff;
			return_data = (double) (temp * 10000) / 10000;
		} else {
		}
		if (return_data != 0 and point_scale != 0) {
			return_data = return_data / point_scale;
		}
	} catch (...) {
	}
	return return_data;
}
void HM_link_thread(bool &thread_end, int &thread_count, modbus_t *HM_ctx,
		int &HM_ret, bool &modbus_link_HM_flag, mongocxx::database db_local,
		bool &error_flag) {
	int lock_buffer_1s = int(currentTime_start_new.wSecond);
	int lock_buffer_100ms = int(currentTime_start_new.wMilliseconds / 100);
	std::string fc_name = "HM_link_thread";
	while (true) {
		while (lock_buffer_100ms
				== int(currentTime_start_new.wMilliseconds / 100)) {
			if (thread_end == true)
				return;
			GetSystemTime(&currentTime_start_new);
			Sleep(100);
		}
		lock_buffer_100ms = int(currentTime_start_new.wMilliseconds / 100);
		if (thread_end == true)
			return;
		if (lock_buffer_1s != int(currentTime_start_new.wSecond)) {
			lock_buffer_1s = int(currentTime_start_new.wSecond);
			thread_count++;
			try {
				if (modbus_link_HM_flag == false and HM_ret == -1) {
					modbus_close(HM_ctx);
					HM_ret = modbus_connect(HM_ctx);
				}
				error_flag = false;
			} catch (...) {
				std::cout << "unknow error : " << fc_name << std::endl;
				if (error_flag == false) {
					std::vector<bsoncxx::document::value> error_docs;
					time_t now = time(0);
					now += 28800;
					error_docs.push_back(
							make_document(kvp("ID", "GC"),
									kvp("time",
											bsoncxx::types::b_date {
													std::chrono::system_clock::from_time_t(
															now) }),
									kvp("event", "unknow error " + fc_name),
									kvp("group", fc_name), kvp("level", 1),
									kvp("show", 1)));
					try {
						db_local["alarm"].insert_many(error_docs);
					} catch (...) {
					}
					error_flag = true;
				}
			}
			thread_count--;
		}
	}
}
void error_thread(bool &thread_end, int &thread_count,
		int &pcs_read_error_count, int &HM_error_count, std::string HM_eid,
		std::string PCS_eid, mongocxx::database db, mongocxx::database db_local,
		bool &error_flag) {
	int lock_buffer_1s = int(currentTime_start_new.wSecond);
	int lock_buffer_100ms = int(currentTime_start_new.wMilliseconds / 100);
	std::string fc_name = "error_thread";
	bool pcs_error = false;
	bool HM_error = false;
	while (true) {
		while (lock_buffer_100ms
				== int(currentTime_start_new.wMilliseconds / 100)) {
			if (thread_end == true)
				return;
			GetSystemTime(&currentTime_start_new);
			Sleep(100);
		}
		lock_buffer_100ms = int(currentTime_start_new.wMilliseconds / 100);
		if (thread_end == true)
			return;
		if (lock_buffer_1s != int(currentTime_start_new.wSecond)) {
			lock_buffer_1s = int(currentTime_start_new.wSecond);
			thread_count++;
			try {
				if (lock_buffer_1s % 10 == 0 or lock_buffer_1s % 10 == 5) {
					int iRunTime = GetTickCount();
					time_t nowtime = time(0);
					nowtime += 28800;
					time_t DateTime = nowtime - (iRunTime / 1000);
					CHAR cUserNameBuffer[256];
					DWORD dwUserNameSize = 256;
					if (GetUserName(cUserNameBuffer, &dwUserNameSize)) {
					} else {
					}
					double memory_data = GetTotalPhysicalMemoryUsed();
					double memory_per = GetPhysicalMemoryUsage();
					double cpu = getWin_CpuUsage();
					std::vector<bsoncxx::document::value> Status;
					Status.push_back(
							make_document(kvp("ID", cUserNameBuffer),
									kvp("time",
											bsoncxx::types::b_date {
													std::chrono::system_clock::from_time_t(
															nowtime) }),
									kvp("boot_time",
											bsoncxx::types::b_date {
													std::chrono::system_clock::from_time_t(
															DateTime) }),
									kvp("cpu", cpu),
									kvp("memory",
											make_document(
													kvp("total", memory_data),
													kvp("mem_per",
															memory_per)))));
					try {
						db["pc_info"].insert_many(Status);
					} catch (...) {
					}
				}
//				std::cout<<"pcs_read_error_count :"<<pcs_read_error_count<<std::endl;
				if (pcs_read_error_count < 1) {/*1s(1s)*/
					try {
						db["equipment"].update_one(
								make_document(
										kvp("_id", bsoncxx::oid(PCS_eid))),
								make_document(
										kvp("$set",
												make_document(
														kvp("count", 0)))));
					} catch (...) {
					}
					pcs_error = false;
				} else {
					if (pcs_error == false) {
						std::vector<bsoncxx::document::value> error_docs;
						time_t now = time(0);
						now += 28800;
						error_docs.push_back(
								make_document(kvp("ID", "GC"),
										kvp("time",
												bsoncxx::types::b_date {
														std::chrono::system_clock::from_time_t(
																now) }),
										kvp("event",
												"PCS meter dont read data"),
										kvp("group", fc_name), kvp("level", 1),
										kvp("show", 1)));
						try {
							db_local["alarm"].insert_many(error_docs);
						} catch (...) {
						}
						pcs_error = true;
					}
				}
				if (HM_error_count < 10) {/*1s(0.1s)*/
					try {
						db["equipment"].update_one(
								make_document(kvp("_id", bsoncxx::oid(HM_eid))),
								make_document(
										kvp("$set",
												make_document(
														kvp("count", 0)))));
					} catch (...) {
					}
					HM_error = false;
				} else {
					if (HM_error == false) {
						std::vector<bsoncxx::document::value> error_docs;
						time_t now = time(0);
						now += 28800;
						error_docs.push_back(
								make_document(kvp("ID", "GC"),
										kvp("time",
												bsoncxx::types::b_date {
														std::chrono::system_clock::from_time_t(
																now) }),
										kvp("event", "HV meter dont read data"),
										kvp("group", fc_name), kvp("level", 1),
										kvp("show", 1)));
						try {
							db_local["alarm"].insert_many(error_docs);
						} catch (...) {
						}
						HM_error = true;
					}
				}
				error_flag = false;
			} catch (...) {
				std::cout << "unknow error : " << fc_name << std::endl;
				if (error_flag == false) {
					std::vector<bsoncxx::document::value> error_docs;
					time_t now = time(0);
					now += 28800;
					error_docs.push_back(
							make_document(kvp("ID", "GC"),
									kvp("time",
											bsoncxx::types::b_date {
													std::chrono::system_clock::from_time_t(
															now) }),
									kvp("event", "unknow error " + fc_name),
									kvp("group", fc_name), kvp("level", 1),
									kvp("show", 1)));
					try {
						db_local["alarm"].insert_many(error_docs);
					} catch (...) {
					}
					error_flag = true;
				}
			}
			thread_count--;
		}
	}
}
void PCS_ReadData_thread(double *pcsdata, int *LEDstate, std::string set_source,
		double &pcs_control_local, double &pcs_reset_local, double &pcs_reset,
		double &pcs_control, double &control_flag,
		double &pcs_control_time_local, double &pcs_control_time_remote,
		double &pcs_control_time, int &pcs_read_error_count, int **pcs_read_arr,
		std::string pcs_ip, int pcs_port, int pcs_id, modbus_t *pcs_read_ctx,
		int &pcs_read_ret, bool &modbus_link_pcs_read_flag, std::string PCS_eid,
		mongocxx::database db, mongocxx::database db_local) {
	try {
		bool function_run2 = false;
		if (function_run2 == false) {
			function_run2 = true;
			/*modbus 讀取PCS資訊*/
//			std::cout << "modbus read PCS start" << std::endl;
			time_t now = time(0);
			now += 28800;
			std::string PCS_mode = "delta";
			try {
				if (modbus_link_pcs_read_flag == false and pcs_read_ret != 0) {
					modbus_close(pcs_read_ctx);
					pcs_read_ret = modbus_connect(pcs_read_ctx);
				}
				if (pcs_read_ret == -1) {
					modbus_close(pcs_read_ctx);
					pcs_read_ret = modbus_connect(pcs_read_ctx);
				}

			} catch (...) {
			}
			double per_time;
			if (set_source == "Remote") {
				per_time = pcs_control_time_remote;
			} else if (set_source == "Local") {
				per_time = pcs_control_time_local;
			}
			if (pcs_control_time != per_time) {
				double control_buffer;
				double reset_buffer;
				if (set_source == "Remote") {
					if (pcs_control == 0){
						control_buffer = 2;
					}else if(pcs_control == 1){
						control_buffer = 1;
					}
					reset_buffer = pcs_reset;
				} else if (set_source == "Local") {
					control_buffer = pcs_control_local;
					reset_buffer = pcs_reset_local;
				}
				/*pcs reset*/
				if (reset_buffer != 0 and pcs_read_ret != -1) {
					bool pcs_read_ok = false;
					uint16_t table_16[1];
					modbus_read_registers(pcs_read_ctx, 0, 1, table_16);
					int control_bit_1 = 0b0000000000000001;/*控制目標1(改1的bit為1)*/
					int control_bit_0 = 0b0000000000000000;/*控制目標0(改0的bit為1)*/
					int write_data = (table_16[0]
							& ((control_bit_1 | control_bit_0)
									xor 0b1111111111111111)) | control_bit_1;
					if (modbus_write_register(pcs_read_ctx, 0, write_data)
							!= -1) {
						/*p寫入成功*/
						/*上傳啟動資訊*/
//						std::cout << "PCS reset success" << std::endl;
						std::vector<bsoncxx::document::value> status_docs;
						time_t now = time(0);
						now += 28800;
						status_docs.push_back(
								make_document(kvp("ID", "GC"),
										kvp("time",
												bsoncxx::types::b_date {
														std::chrono::system_clock::from_time_t(
																now) }),
										kvp("event", "PCS reset success"),
										kvp("group", "PCS_ReadData_thread"),
										kvp("level", 1), kvp("show", 1)));
						db_local["status"].insert_many(status_docs);
					} else {
						/*p寫入失敗*/
//						std::cout << "PCS reset error" << std::endl;
						std::vector<bsoncxx::document::value> status_docs;
						time_t now = time(0);
						now += 28800;
						status_docs.push_back(
								make_document(kvp("ID", "GC"),
										kvp("time",
												bsoncxx::types::b_date {
														std::chrono::system_clock::from_time_t(
																now) }),
										kvp("event", "PCS reset fail"),
										kvp("group", "PCS_ReadData_thread"),
										kvp("level", 1), kvp("show", 1)));
						try {
							db_local["status"].insert_many(status_docs);
						} catch (...) {
						}
					}
				}
				/*pcs control*/
				if (control_buffer != 0 and pcs_read_ret != -1) {
					if (control_buffer == 1) {
						uint16_t table_16[1];
						modbus_read_registers(pcs_read_ctx, 0, 1, table_16);
						int control_bit_1 = 0b0000000000001000;/*控制目標1(改1的bit為1)*/
						int control_bit_0 = 0b0000000000000000;/*控制目標0(改0的bit為1)*/
						int write_data = (table_16[0]
								& ((control_bit_1 | control_bit_0)
										xor 0b1111111111111111))
								| control_bit_1;
						if (modbus_write_register(pcs_read_ctx, 0, write_data)
								!= -1) {
						}
					} else if (control_buffer == 2) {
						uint16_t table_16[1];
						modbus_read_registers(pcs_read_ctx, 0, 1, table_16);
						int control_bit_1 = 0b0000000000000000;/*控制目標1(改1的bit為1)*/
						int control_bit_0 = 0b0000000000001000;/*控制目標0(改0的bit為1)*/
						int write_data = (table_16[0]
								& ((control_bit_1 | control_bit_0)
										xor 0b1111111111111111))
								| control_bit_1;
						if (modbus_write_register(pcs_read_ctx, 0, write_data)
								!= -1) {
						}
					}
				}
				pcs_control_time = per_time;
			}
			/*大小要看有多少bit*/
			int device_bit_Length;
			modbus_device["PCS"][PCS_mode].Get("Bit_Length", device_bit_Length);
			int pcs_bit_length_1[device_bit_Length][16];
			int *pcs_bit_length[device_bit_Length];
			for (int x = 0; x < device_bit_Length; x++) {
				pcs_bit_length[x] = &pcs_bit_length_1[x][0];
			}
			try {
				if (pcs_read_ret == -1) {
					modbus_link_pcs_read_flag = false;
				} else {
				}
				bool pcs_read_ok = false;
				std::vector<bsoncxx::document::value> PCS_docs;
				if (modbus_link_pcs_read_flag == true
						or (modbus_link_pcs_read_flag == false
								and pcs_read_error_count < 3)) {
					if (modbus_link_pcs_read_flag == true) {
						pcs_read_error_count = 0;
						modbus_find(pcs_read_ctx, modbus_device["PCS"][PCS_mode], pcs_read_ret,
							pcs_read_ok, pcs_read_arr);
						if (pcs_read_ok == true) {/*高壓錶讀取成功*/
							LEDstate[1] = 2;
						} else {/*高壓錶讀失敗*/
							LEDstate[1] = 0;
						}
					} else if (modbus_link_pcs_read_flag == false
							and pcs_read_error_count < 3) {
						pcs_read_error_count++;
						LEDstate[1] = 0;
					}
					if (pcs_read_ok == true) {/*PCS讀取成功*/
						/*正常上傳data*/
						std::string keya;
						int count_point = 0;
						/*上傳資料整理*/
						bsoncxx::builder::basic::document doc_one;
						doc_one.append(kvp("ID", PCS_eid));
						doc_one.append(kvp("time", bsoncxx::types::b_date {
									std::chrono::system_clock::from_time_t(
											now)
						}));
						count_point = 0;
						while (modbus_device["PCS"][PCS_mode]["Point"].GetKey(keya)){
							pcsdata[count_point] = Read_upload(modbus_device["PCS"][PCS_mode], modbus_device["PCS"][PCS_mode]["Point"][keya], pcs_read_arr);
							if (modbus_device["PCS"][PCS_mode]["Point"][keya]("type") == "bit"){
								int bin16[16];
								int point_order;
								modbus_device["PCS"][PCS_mode]["Point"][keya].Get("order", point_order);
								int point_address;
								modbus_device["PCS"][PCS_mode]["Point"][keya].Get("address", point_address);
								int device_Address;
								modbus_device["PCS"][PCS_mode]["Address"].Get(point_order, device_Address);
								int return_data = pcs_read_arr[point_order][point_address - device_Address];
								for (int x = 0; x < 16; x++) {
									if (return_data != 1) {
										bin16[x] = return_data % 2;
										return_data = return_data / 2;
									} else {
										bin16[x] = 0;
									}
								}
								doc_one.append(kvp(keya, [&bin16](
										sub_array child) {
										for (const int &element : bin16) {
											child.append(element);
										}
									}));
							}else{
								doc_one.append(kvp(keya, pcsdata[count_point]));
							}
							count_point++;
						}
						PCS_docs.push_back(doc_one.extract());
					}
					else{
						/*null上傳data*/
						std::string keya;
						int count_point = 0;
						/*上傳資料整理*/
						bsoncxx::builder::basic::document doc_one;
						doc_one.append(kvp("ID", PCS_eid));
						doc_one.append(kvp("time", bsoncxx::types::b_date {
									std::chrono::system_clock::from_time_t(
											now)
						}));
						while (modbus_device["PCS"][PCS_mode]["Point"].GetKey(keya)){
							if (modbus_device["PCS"][PCS_mode]["Point"][keya]("type") == "bit"){
								int bin16[16];
								doc_one.append(kvp(keya, [&bin16](
									sub_array child) {
									for (const int &element : bin16) {
										child.append(bsoncxx::types::b_null {});
									}
								}));
							}else{
								doc_one.append(kvp(keya, bsoncxx::types::b_null {}));
							}
						}
					}
				} else {
					LEDstate[1] = 0;
					pcs_read_error_count++;
					for (int x = 0; x < 48; x++) {
						pcsdata[x] = -1;
					}
					/*null上傳data*/
					std::string keya;
					int count_point = 0;
					/*上傳資料整理*/
					bsoncxx::builder::basic::document doc_one;
					doc_one.append(kvp("ID", PCS_eid));
					doc_one.append(kvp("time", bsoncxx::types::b_date {
								std::chrono::system_clock::from_time_t(
										now)
					}));
					while (modbus_device["PCS"][PCS_mode]["Point"].GetKey(keya)){
						if (modbus_device["PCS"][PCS_mode]["Point"][keya]("type") == "bit"){
							int bin16[16];
							doc_one.append(kvp(keya, [&bin16](
								sub_array child) {
								for (const int &element : bin16) {
									child.append(bsoncxx::types::b_null {});
								}
							}));
						}else{
							doc_one.append(kvp(keya, bsoncxx::types::b_null {}));
						}
					}
				}
				try {
					db["pcs"].insert_many(PCS_docs);
				} catch (...) {
				}
				try {
					db_local["pcs"].insert_many(PCS_docs);
				} catch (...) {
				}
				if (pcs_read_ret == 0) {/*連線成功*/
					modbus_link_pcs_read_flag = true;
				} else {
				}
			} catch (...) {
			}

			function_run2 = false;
		}
	} catch (...) {
	}
}
void EMS_ReadData_thread(bool &thread_end, int &thread_count, double *emsdata,
		double *mbmsdata, int *LEDstate, bool &remote_first_run,
		std::string set_source, std::string *scale_name, double *scale_data,
		int &scale_len, int &mode, double &soc_max, double &soc_min,
		double &System_p_max, double &System_p_min, double &System_q_max,
		double &System_q_min, double *f_arr, double *p_arr, double *v_arr,
		double *q_arr, double &PQ_p_ref, double &PQ_q_ref, int &FP_type,
		double &FP_soc_goal_percent, double &FP_main_f_set,
		double &FP_line_p_base, double &FP_soc_dead_band, double &FP_soc_adjust,
		int &VC_type, double &Vq_v_base, double &Vq_q_base, double &Vq_droop,
		double &Vq_v_set, double &PF_pf_ref, double *control_ab_data,
		double &soc, int &ems_count, double &mbms_time, int &mbms_count,
		int &pcs_write_error_count, double &pcs_reset, double &pcs_control,
		double &pcs_control_time_remote, modbus_t *pcs_read_ctx,
		int pcs_read_ret, std::string MBMS_id, std::string PCS_id,
		mongocxx::database db, mongocxx::database db_local, bool &error_flag) {
	int lock_buffer_1s = int(currentTime_start_new.wSecond);
	int lock_buffer_100ms = int(currentTime_start_new.wMilliseconds / 100);
	std::string fc_name = "EMS_ReadData_thread";
	while (true) {
		while (lock_buffer_100ms
				== int(currentTime_start_new.wMilliseconds / 100)) {
			if (thread_end == true)
				return;
			GetSystemTime(&currentTime_start_new);
			Sleep(100);
		}
		lock_buffer_100ms = int(currentTime_start_new.wMilliseconds / 100);
		if (thread_end == true)
			return;
		if (lock_buffer_1s != int(currentTime_start_new.wSecond)) {
			lock_buffer_1s = int(currentTime_start_new.wSecond);
			thread_count++;
			try {
				mongocxx::options::find opts; /*限制搜尋數量*/
				auto order = bsoncxx::builder::stream::document { } << "time"
						<< -1 << bsoncxx::builder::stream::finalize;
				opts.sort(order.view());
				opts.limit(1);
				//			std::cout<<"set_source :"<<set_source<<std::endl;
				if (set_source == "Remote") {
					int count = 0;
					try {
						mongocxx::collection coll_site = db["site_control"];
						mongocxx::cursor cursor_site = coll_site.find(
								make_document(kvp("ID", "site_control")), opts);
						for (bsoncxx::v_noabi::document::view doc : cursor_site) {
							count++;
							try {
								double modeb;
								double FP_typeb;
								double VC_typeb;
//								std::cout<< bsoncxx::to_json(doc)<<std::endl;
								mongo_dic(doc, "scale", scale_name, scale_data,
										scale_len);
//								std::cout <<"scale_name[0] :"<< scale_name[0] <<" scale_data[0] :"<<scale_data[0]<<" scale_len :"<<scale_len<< std::endl;
								mongo_data(doc, "mode", modeb);
								mode = (int) modeb;
//								std::cout <<"mode :"<< mode << std::endl;
								mongo_data(doc, "soc_max", soc_max);
								mongo_data(doc, "soc_min", soc_min);
								mongo_data(doc, "System_p_max", System_p_max);
								mongo_data(doc, "System_p_min", System_p_min);
								mongo_data(doc, "System_q_max", System_q_max);
								mongo_data(doc, "System_q_min", System_q_min);
								mongo_data(doc, "PQ_p_ref", PQ_p_ref);
								mongo_data(doc, "PQ_q_ref", PQ_q_ref);
								mongo_data(doc, "FP_type", FP_typeb);
								FP_type = (int) FP_typeb;
								mongo_data(doc, "FP_soc_goal_percent",
										FP_soc_goal_percent);
								mongo_data(doc, "FP_main_f_set", FP_main_f_set);
								mongo_data(doc, "f1_line_set", f_arr[0]);
								mongo_data(doc, "f2_line_set", f_arr[1]);
								mongo_data(doc, "f3_line_set", f_arr[2]);
								mongo_data(doc, "f4_line_set", f_arr[3]);
								mongo_data(doc, "f5_line_set", f_arr[4]);
								mongo_data(doc, "f6_line_set", f_arr[5]);
								double p_arrc[6];
								mongo_data(doc, "p1_line_set", p_arrc[0]);
								mongo_data(doc, "p2_line_set", p_arrc[1]);
								mongo_data(doc, "p3_line_set", p_arrc[2]);
								mongo_data(doc, "p4_line_set", p_arrc[3]);
								mongo_data(doc, "p5_line_set", p_arrc[4]);
								mongo_data(doc, "p6_line_set", p_arrc[5]);
								mongo_data(doc, "FP_line_p_base",
										FP_line_p_base);
								mongo_data(doc, "FP_soc_dead_band",
										FP_soc_dead_band);
								mongo_data(doc, "FP_soc_adjust", FP_soc_adjust);
								mongo_data(doc, "VC_type", VC_typeb);
								VC_type = (int) VC_typeb;
								mongo_data(doc, "Vq_v_base", Vq_v_base);
								mongo_data(doc, "Vq_q_base", Vq_q_base);
								mongo_data(doc, "Vq_droop", Vq_droop);
								mongo_data(doc, "Vq_v_set", Vq_v_set);
								mongo_data(doc, "Vq_v1_set", v_arr[0]);
								mongo_data(doc, "Vq_v2_set", v_arr[1]);
								mongo_data(doc, "Vq_v3_set", v_arr[2]);
								mongo_data(doc, "Vq_v4_set", v_arr[3]);
								mongo_data(doc, "Vq_v5_set", v_arr[4]);
								mongo_data(doc, "Vq_v6_set", v_arr[5]);
								mongo_data(doc, "Vq_v7_set", v_arr[6]);
								mongo_data(doc, "Vq_q1_set", q_arr[0]);
								mongo_data(doc, "Vq_q2_set", q_arr[1]);
								mongo_data(doc, "Vq_q3_set", q_arr[2]);
								mongo_data(doc, "Vq_q4_set", q_arr[3]);
								mongo_data(doc, "Vq_q5_set", q_arr[4]);
								mongo_data(doc, "Vq_q6_set", q_arr[5]);
								mongo_data(doc, "Vq_q7_set", q_arr[6]);
								mongo_data(doc, "PF_pf_ref", PF_pf_ref);
								/*更新控制規則*/
								/*dReg 計算*/
								FP_soc_adjust = FP_soc_adjust / 100.0;
								p_arr[0] = p_arrc[0] * FP_line_p_base / 100;
								p_arr[1] = p_arrc[1] * FP_line_p_base / 100;
								p_arr[2] = p_arrc[2] * FP_line_p_base / 100;
								p_arr[3] = p_arrc[3] * FP_line_p_base / 100;
								p_arr[4] = p_arrc[4] * FP_line_p_base / 100;
								p_arr[5] = p_arrc[5] * FP_line_p_base / 100;

								double a1, a21, a22, a23, a41, a42, a43, a5, b1,
										b21, b22, b23, b3, b41, b42, b43, b5,
										a_sReg, b_sReg, a_qAuto, b_qAuto;
								a1 = (p_arr[1] - p_arr[0])
										/ (f_arr[1] - f_arr[0]) * 1.000;
								a21 = ((p_arr[2]
										+ (FP_soc_adjust * FP_line_p_base))
										- p_arr[1]) / (f_arr[2] - f_arr[1])
										* 1.000;
								a22 = (p_arr[2] - p_arr[1])
										/ (f_arr[2] - f_arr[1]) * 1.000;
								a23 = ((p_arr[2]
										- (FP_soc_adjust * FP_line_p_base))
										- p_arr[1]) / (f_arr[2] - f_arr[1])
										* 1.000;
//								a3 = 0; /*中間值自由調整為0無須斜率*/
								a41 = (p_arr[4]
										- (p_arr[3]
												+ (FP_soc_adjust
														* FP_line_p_base)))
										/ (f_arr[4] - f_arr[3]) * 1.000;
								a42 = (p_arr[4] - p_arr[3])
										/ (f_arr[4] - f_arr[3]) * 1.000;
								a43 = (p_arr[4]
										- (p_arr[3]
												- (FP_soc_adjust
														* FP_line_p_base)))
										/ (f_arr[4] - f_arr[3]) * 1.000;
								a5 = (p_arr[5] - p_arr[4])
										/ (f_arr[5] - f_arr[4]) * 1.000;

								b1 = p_arr[0] - a1 * f_arr[0] * 1.000;
								b21 = p_arr[1] - a21 * f_arr[1] * 1.000;
								b22 = p_arr[1] - a22 * f_arr[1] * 1.000;
								b23 = p_arr[1] - a23 * f_arr[1] * 1.000;
								b3 = FP_soc_adjust * FP_line_p_base;
								b41 = p_arr[4] - a41 * f_arr[4] * 1.000;
								b42 = p_arr[4] - a42 * f_arr[4] * 1.000;
								b43 = p_arr[4] - a43 * f_arr[4] * 1.000;
								b5 = p_arr[5] - a5 * f_arr[5] * 1.000;
								/*sReg計算*/
								a_sReg = (p_arr[3] - p_arr[2])
										/ (f_arr[3] - f_arr[2]) * 1.000;
								;
								b_sReg = p_arr[3] - a_sReg * f_arr[3] * 1.000;
								/*VQ計算*/
								a_qAuto = Vq_droop;
								b_qAuto = Vq_q_base - (Vq_droop * Vq_v_base);
								control_ab_data[0] = a1;
								control_ab_data[1] = a21;
								control_ab_data[2] = a22;
								control_ab_data[3] = a23;
								control_ab_data[4] = a41;
								control_ab_data[5] = a42;
								control_ab_data[6] = a43;
								control_ab_data[7] = a5;
								control_ab_data[8] = b1;
								control_ab_data[9] = b21;
								control_ab_data[10] = b22;
								control_ab_data[11] = b23;
								control_ab_data[12] = b3;
								control_ab_data[13] = b41;
								control_ab_data[14] = b42;
								control_ab_data[15] = b43;
								control_ab_data[16] = b5;
								control_ab_data[17] = a_sReg;
								control_ab_data[18] = b_sReg;
								control_ab_data[19] = a_qAuto;
								control_ab_data[20] = b_qAuto;
							} catch (...) {
								std::cout << "error" << std::endl;
							}
						}

					} catch (...) {
					}
					if (count == 0) {
						/*沒讀到*/
						ems_count++;
						/*回傳ui*/
						for (int x = 0; x < 48; x++) {
							emsdata[x] = -1;
						}
						//
						LEDstate[0] = 0;
					} else {
						LEDstate[0] = 2;
						/*有讀到資料*/
						ems_count = 0;
						remote_first_run = false;
						/*回傳ui*/
						emsdata[0] = mode;
						//					emsdata[1] = mode;
						emsdata[2] = soc_max;
						emsdata[3] = soc_min;
						emsdata[4] = System_p_max;
						emsdata[5] = System_p_min;
						emsdata[6] = System_q_max;
						emsdata[7] = System_q_min;
						emsdata[8] = PQ_p_ref;
						emsdata[9] = PQ_q_ref;
						emsdata[10] = FP_type;
						emsdata[11] = FP_soc_goal_percent;
						emsdata[12] = FP_main_f_set;
						emsdata[13] = f_arr[0];
						emsdata[14] = f_arr[1];
						emsdata[15] = f_arr[2];
						emsdata[16] = f_arr[3];
						emsdata[17] = f_arr[4];
						emsdata[18] = f_arr[5];
						emsdata[19] = p_arr[0];
						emsdata[20] = p_arr[1];
						emsdata[21] = p_arr[2];
						emsdata[22] = p_arr[3];
						emsdata[23] = p_arr[4];
						emsdata[24] = p_arr[5];
						emsdata[25] = FP_line_p_base;
						emsdata[26] = FP_soc_dead_band;
						emsdata[27] = FP_soc_adjust;
						emsdata[28] = VC_type;
						emsdata[29] = Vq_v_base;
						emsdata[30] = Vq_q_base;
						emsdata[31] = Vq_droop;
						emsdata[32] = Vq_v_set;
						emsdata[33] = v_arr[0];
						emsdata[34] = v_arr[1];
						emsdata[35] = v_arr[2];
						emsdata[36] = v_arr[3];
						emsdata[37] = v_arr[4];
						emsdata[38] = v_arr[5];
						emsdata[39] = v_arr[6];
						emsdata[40] = q_arr[0];
						emsdata[41] = q_arr[1];
						emsdata[42] = q_arr[2];
						emsdata[43] = q_arr[3];
						emsdata[44] = q_arr[4];
						emsdata[45] = q_arr[5];
						emsdata[46] = q_arr[6];
						emsdata[47] = PF_pf_ref;
					}
					try {
						mongocxx::collection coll_pcs = db["pcs_control"];
						mongocxx::cursor cursor_pcs = coll_pcs.find(
								make_document(kvp("ID", PCS_id)), opts);
						for (bsoncxx::v_noabi::document::view doc : cursor_pcs) {
							std::cout<< bsoncxx::to_json(doc)<<std::endl;
							try {
								mongo_time(doc, "time",
										pcs_control_time_remote);
								mongo_data(doc, "control", pcs_control);
								mongo_data(doc, "reset", pcs_reset);
							} catch (...) {
							}
						}
					} catch (...) {
					}

				} else if (set_source == "Local") {

				}
				try {
					mongocxx::collection coll_mbms = db["mbms"];
					mongocxx::cursor cursor_mbms = coll_mbms.find(
							make_document(kvp("ID", MBMS_id)), opts);
					for (bsoncxx::v_noabi::document::view doc : cursor_mbms) {
//						std::cout<< bsoncxx::to_json(doc)<<std::endl;
						try {
							double mbms_time_next;
							mongo_data(doc, "soc_sys", soc);
							mongo_time(doc, "time", mbms_time_next);
							if (mbms_time != mbms_time_next) {
								mbms_time = mbms_time_next;
								mbms_count = 0;
//								std::cout <<"mbms_time != :"<<std::to_string(mbms_time)<< std::endl;
							} else {
								mbms_count++;
//								std::cout <<"mbms_time == :"<<std::to_string(mbms_time)<< std::endl;
							}
						} catch (...) {
						}
					}

				} catch (...) {
				}
				if (mbms_count < 10) {
					LEDstate[2] = 2;
				} else if (mbms_count <= 60) {
					LEDstate[2] = 3;
				} else {
					LEDstate[2] = 0;
				}
				mbmsdata[0] = soc;
				error_flag = false;
			} catch (...) {
				if (error_flag == false) {
					std::vector<bsoncxx::document::value> error_docs;
					time_t now = time(0);
					now += 28800;
					error_docs.push_back(
							make_document(kvp("ID", "GC"),
									kvp("time",
											bsoncxx::types::b_date {
													std::chrono::system_clock::from_time_t(
															now) }),
									kvp("event", "unknow error " + fc_name),
									kvp("group", fc_name), kvp("level", 1),
									kvp("show", 1)));
					try {
						db_local["alarm"].insert_many(error_docs);
					} catch (...) {
					}
					error_flag = true;
				}
			}
			thread_count--;
		}
	}
}
void control_thread(bool &function_run, int &thread_count,
		bool remote_first_run, std::string set_source, double pcs_control_local,
		double pcs_reset_local, double pcs_control_time_local, double *HMdata,
		int *LEDstate, bool &next_sec, std::string &ability_test,
		int &ability_test_count, int &lock_buffer_100ms, int &HM_error_count,
		bool &first_run, char &path_dReg, char &path_sReg, bool &sReg_flag,
		double &pcs_out_pre_p, double &pcs_out_pre_q, double *HM_time,
		double **HM_data, int ems_count, int mbms_count, double soc,
		modbus_t *HM_ctx, int &HM_ret, bool &modbus_link_HM_flag, double HM_f,
		double HM_p, double HM_v, double HM_q, double &pcs_out_p,
		double PQ_p_ref, double &pcs_out_q, double PQ_q_ref, int mode,
		double soc_max, double soc_min, double System_p_max,
		double System_p_min, double System_q_max, double System_q_min,
		double *f_arr, double *p_arr, double *v_arr, double *q_arr, int FP_type,
		int VC_type, double FP_soc_goal_percent, double FP_soc_dead_band,
		double PF_pf_ref, double Vq_v_base, double Vq_q_base, double Vq_droop,
		double Vq_v_set, double *control_ab_data, bool &VQ_Hys_line,
		double &HM_v_last, std::string &control_point, std::string HM_eid,
		mongocxx::database db, mongocxx::database db_local, bool &error_flag,
		double *pcsdata, double &pcs_reset, double &pcs_control,
		double &control_flag, double &pcs_control_time_remote,
		double &pcs_control_time, int &pcs_read_error_count, int **pcs_read_arr,
		std::string pcs_ip, int pcs_port, int pcs_id, modbus_t *pcs_read_ctx,
		int &pcs_read_ret, bool &modbus_link_pcs_read_flag,
		std::string PCS_eid) {
	thread_count++;
	std::string fc_name = "control_thread";
	try {
		if (function_run == false) { /*是否已有線呈進入*/
			function_run = true;
//			std::cout <<"control_thread runing"<< std::endl;
			/*1*/
			int xorbit = 65535; /*256的2次方 - 1*/
			/*2
			int xorbit=4294967295; *//*256的4次方 - 1*/

			time_t now = time(0);
			now += 28800;
			std::string Meter_mode = "ION9000";
			/*modbus 讀取高壓表*/
//			std::cout << "modbus read HM start" << std::endl;
			try {
				if (HM_ret == -1) {
//					std::cout << "HM_ret change" << std::endl;
					modbus_link_HM_flag = false;
				}
				bool HM_read_ok = false;
				int order_len;
				modbus_device["meter"][Meter_mode].Get("Order", order_len);
				int HM_arr_1[order_len][80];
				int *HM_arr[order_len];
				for (int x = 0; x < order_len; x++) {
					HM_arr[x] = &HM_arr_1[x][0];
				}
				HM_time[lock_buffer_100ms] = now;
				if (modbus_link_HM_flag == true) {
					modbus_find(HM_ctx, modbus_device["meter"][Meter_mode], HM_ret, HM_read_ok,
							HM_arr);
					if (HM_read_ok == true) {/*高壓錶讀取成功*/
						HM_error_count = 0;
						LEDstate[3] = 2;
					} else {/*高壓錶讀失敗*/
						HM_error_count++;
						LEDstate[3] = 0;
					}
					/*資料更新*/
					std::string keya;
					int count_point = 0;
					while (modbus_device["meter"][Meter_mode]["Point"].GetKey(keya)){
						HM_data[count_point][lock_buffer_100ms] = Read_upload(modbus_device["meter"][Meter_mode], modbus_device["meter"][Meter_mode]["Point"][keya], HM_arr);
						count_point++;
					}
				} else if (modbus_link_HM_flag == false) {/*無法連線等待另一個 線呈連線成功*/
					if (HM_ret == 0) {/*連線成功*/
						modbus_link_HM_flag = true;
						LEDstate[3] = 2;
					} else {
						HM_error_count++;
						LEDstate[3] = 0;
					}
				}
				if (HM_read_ok == true) {/*高壓錶讀取成功*/
					HM_f = Read_upload(modbus_device["meter"][Meter_mode], modbus_device["meter"][Meter_mode]["Point"]["f"], HM_arr);
					HM_p = Read_upload(modbus_device["meter"][Meter_mode], modbus_device["meter"][Meter_mode]["Point"]["p"], HM_arr);
					HM_v = Read_upload(modbus_device["meter"][Meter_mode], modbus_device["meter"][Meter_mode]["Point"]["v"], HM_arr);
					HM_q = Read_upload(modbus_device["meter"][Meter_mode], modbus_device["meter"][Meter_mode]["Point"]["q"], HM_arr);
					/*回傳ui*/
					for (int x = 0; x < 41; x++) {
						HMdata[x] = HM_data[x][lock_buffer_100ms];
					}
				} else if (HM_read_ok == false and HM_error_count < 30) {/*高壓錶讀失敗 <30*/
					int pro_order;
					if (lock_buffer_100ms == 0) {
						pro_order = 9;
					} else {
						pro_order = lock_buffer_100ms - 1;
					}
					for (int x = 0; x < 41; x++) {
						HM_data[x][lock_buffer_100ms] = HM_data[x][pro_order];
					}
					HM_f = HM_data[4][pro_order];
					HM_p = HM_data[16][pro_order];
					HM_v = HM_data[12][pro_order];
					HM_q = HM_data[20][pro_order];
					/*回傳ui*/
					for (int x = 0; x < 41; x++) {
						HMdata[x] = HM_data[x][lock_buffer_100ms];
					}
				} else {
					for (int x = 0; x < 41; x++) {
						HM_data[x][lock_buffer_100ms] = -1;
					}
					/*回傳ui*/
					for (int x = 0; x < 41; x++) {
						HMdata[x] = -1;
					}
					HM_f = -1;
					HM_p = -1;
					HM_v = -1;
					HM_q = -1;
				}
			} catch (...) {
			}
			double pcs_out_p_now;/*此次P 0.1s*/
			double pcs_out_q_now;/*此次Q 0.1s*/
			if (next_sec == true) { /*換秒*/
				/*能力測試*/
//				std::cout << "ability_test :" << ability_test << std::endl;
				if (ability_test != "None") {
					if (ability_test == "1") {
						AbilityTest::dReg025_1 dReg025_1;
						HM_f = dReg025_1.data[ability_test_count
								/ dReg025_1.run_feq];
					} else if (ability_test == "2") {
						AbilityTest::dReg025_2 dReg025_2;
						HM_f = dReg025_2.data[ability_test_count
								/ dReg025_2.run_feq];
					} else if (ability_test == "3") {
						AbilityTest::dReg025_3 dReg025_3;
						HM_f = dReg025_3.data[ability_test_count
								/ dReg025_3.run_feq];
					} else if (ability_test == "4") {
						AbilityTest::dReg025_4 dReg025_4;
						if (ability_test_count >= dReg025_4.time[0]
								and ability_test_count < dReg025_4.time[1]) {
							HM_f = dReg025_4.data[0];
						} else if (ability_test_count >= dReg025_4.time[1]
								and ability_test_count < dReg025_4.time[2]) {
							HM_f = dReg025_4.data[1];
						} else if (ability_test_count >= dReg025_4.time[2]) {
							HM_f = dReg025_4.data[2];
						}
					} else if (ability_test == "5") {
						AbilityTest::dReg025_5 dReg025_5;
						if (ability_test_count >= dReg025_5.time[0]
								and ability_test_count < dReg025_5.time[1]) {
							HM_f = dReg025_5.data[0];
						} else if (ability_test_count >= dReg025_5.time[1]
								and ability_test_count < dReg025_5.time[2]) {
							HM_f = dReg025_5.data[1];
						} else if (ability_test_count >= dReg025_5.time[2]) {
							HM_f = dReg025_5.data[2];
						}
					} else if (ability_test == "6") {
						AbilityTest::dReg05_6 dReg05_6;
						HM_f = dReg05_6.data[ability_test_count
								/ dReg05_6.run_feq];
					} else if (ability_test == "7") {
						AbilityTest::dReg05_7 dReg05_7;
						HM_f = dReg05_7.data[ability_test_count
								/ dReg05_7.run_feq];
					} else if (ability_test == "8") {
						AbilityTest::dReg05_8 dReg05_8;
						HM_f = dReg05_8.data[ability_test_count
								/ dReg05_8.run_feq];
					} else if (ability_test == "9") {
						AbilityTest::dReg05_9 dReg05_9;
						if (ability_test_count >= dReg05_9.time[0]
								and ability_test_count < dReg05_9.time[1]) {
							HM_f = dReg05_9.data[0];
						} else if (ability_test_count >= dReg05_9.time[1]
								and ability_test_count < dReg05_9.time[2]) {
							HM_f = dReg05_9.data[1];
						} else if (ability_test_count >= dReg05_9.time[2]) {
							HM_f = dReg05_9.data[2];
						}
					} else if (ability_test == "10") {
						AbilityTest::dReg05_10 dReg05_10;
						if (ability_test_count >= dReg05_10.time[0]
								and ability_test_count < dReg05_10.time[1]) {
							HM_f = dReg05_10.data[0];
						} else if (ability_test_count >= dReg05_10.time[1]
								and ability_test_count < dReg05_10.time[2]) {
							HM_f = dReg05_10.data[1];
						} else if (ability_test_count >= dReg05_10.time[2]) {
							HM_f = dReg05_10.data[2];
						}
					} else if (ability_test == "11") {
						AbilityTest::sReg_11 sReg_11;
						HM_f =
								sReg_11.data[ability_test_count
										/ sReg_11.run_feq];
					} else if (ability_test == "12") {
						AbilityTest::sReg_12 sReg_12;
						HM_f =
								sReg_12.data[ability_test_count
										/ sReg_12.run_feq];
					} else if (ability_test == "13") {
						AbilityTest::sReg_13 sReg_13;
						if (ability_test_count >= sReg_13.time[0]
								and ability_test_count < sReg_13.time[1]) {
							HM_f = sReg_13.data[0];
						} else if (ability_test_count >= sReg_13.time[1]
								and ability_test_count < sReg_13.time[2]) {
							HM_f = sReg_13.data[1];
						} else if (ability_test_count >= sReg_13.time[2]) {
							HM_f = sReg_13.data[2];
						}
					}
					HM_data[4][lock_buffer_100ms] = HM_f;
					ability_test_count++;
				} else {
					ability_test_count = 0;
				}
				/*HM有讀到值*/
				/*沒讀到值30次 (又不是第一次)*/
				if ((HM_ret > 0
						or (HM_ret < 0 and HM_error_count < 30
								and first_run == false))
						and (ems_count < 60 and mbms_count < 60)) { /*3秒內讀不到還是會進*/
					/*模式控制*/
					double a1 = control_ab_data[0];
					double a21 = control_ab_data[1];
					double a22 = control_ab_data[2];
					double a23 = control_ab_data[3];
					double a41 = control_ab_data[4];
					double a42 = control_ab_data[5];
					double a43 = control_ab_data[6];
					double a5 = control_ab_data[7];
					double b1 = control_ab_data[8];
					double b21 = control_ab_data[9];
					double b22 = control_ab_data[10];
					double b23 = control_ab_data[11];
					double b3 = control_ab_data[12];
					double b41 = control_ab_data[13];
					double b42 = control_ab_data[14];
					double b43 = control_ab_data[15];
					double b5 = control_ab_data[16];
					double a_sReg = control_ab_data[17];
					double b_sReg = control_ab_data[18];
					double a_qAuto = control_ab_data[19];
					double b_qAuto = control_ab_data[20];
					if (mode == 0) {
						pcs_out_p = 0;
						pcs_out_q = 0;
					} else if (mode == 2) {
						VQ_mode(VC_type, pcs_out_q, pcs_out_p, VQ_Hys_line,
								HM_v_last, HM_v, v_arr, q_arr, PQ_q_ref,
								PF_pf_ref, Vq_v_base, Vq_q_base, Vq_droop,
								Vq_v_set);
					} else if ((mode == 5 or mode == 11)
							and (FP_type == 0 or FP_type == 1 or FP_type == 2
									or FP_type == 4)) { //dReg
						dReg_mode(control_point, path_dReg, pcs_out_p, soc,
								FP_soc_goal_percent, FP_soc_dead_band, FP_type,
								HM_f, f_arr, p_arr, a1, b1, a21, b21, a22, b22,
								a23, b23, b3, a41, b41, a42, b42, a43, b43, a5,
								b5);

						if (FP_type == 4) {/*EdReg*/
							pcs_out_p = pcs_out_p + PQ_p_ref;
						}
						if (mode == 5) {
							PQ_q_ref = 0;
						}
						if (mode == 11) {
							VQ_mode(VC_type, pcs_out_q, pcs_out_p, VQ_Hys_line,
									HM_v_last, HM_v, v_arr, q_arr, PQ_q_ref,
									PF_pf_ref, Vq_v_base, Vq_q_base, Vq_droop,
									Vq_v_set);
						}
					} else if ((mode == 5 or mode == 11) and (FP_type == 3)) { /*sReg*/
						sReg_mode(control_point, path_sReg, pcs_out_p, soc,
								FP_soc_goal_percent, FP_soc_dead_band, HM_f,
								f_arr, p_arr, sReg_flag, a_sReg, b_sReg);
						if (mode == 5) {
							PQ_q_ref = 0;
						}
						if (mode == 11) {
							VQ_mode(VC_type, pcs_out_q, pcs_out_p, VQ_Hys_line,
									HM_v_last, HM_v, v_arr, q_arr, PQ_q_ref,
									PF_pf_ref, Vq_v_base, Vq_q_base, Vq_droop,
									Vq_v_set);
						}
					} else if (mode == 6) { /*PQ*/
						pcs_out_p = PQ_p_ref;
						pcs_out_q = PQ_q_ref;
					} else {

					}
//					std::cout << "pcs_out_p :"<<pcs_out_p<< "  pcs_out_q :"<<pcs_out_q<<"  soc :"<<soc<< std::endl;
					/*極限值計算*/
					if (pcs_out_p > System_p_max) {
						pcs_out_p = System_p_max;
					} else if (pcs_out_p < System_p_min) {
						pcs_out_p = System_p_min;
					}
					if (pcs_out_q > System_q_max) {
						pcs_out_q = System_q_max;
					} else if (pcs_out_q < System_q_min) {
						pcs_out_q = System_q_min;
					}
					if ((soc > soc_max and pcs_out_p < 0)
							or (soc < soc_min and pcs_out_p > 0)) {
						pcs_out_p = 0;
					}
//					std::cout << "pcs_out_p :" << pcs_out_p << "  pcs_out_q :"
//							<< pcs_out_q << std::endl;

					if (first_run == true) {
						first_run = false;
						std::cout << "first_run read HM OK" << std::endl;
					}
				}
				/*沒讀到值(EMS發告警)(應對PCS下指令停止)*/
				else {
//					std::cout << "dont read High meter" << std::endl;
					pcs_out_p = 0;
					HM_f = 0;
					if (first_run == true) {
						std::cout << "first_run dont read High meter"
								<< std::endl;
					}
				}
				pcs_out_p_now = pcs_out_p;
				pcs_out_q_now = pcs_out_q;
				next_sec = false;
			} else { /*沒換秒 修正讀取值和前一次控制值差值(損失補償)*/
				if (mode == 5 or mode == 11) {
					pcs_out_p_now = pcs_out_pre_p + (pcs_out_p - HM_p);
					pcs_out_q_now = pcs_out_pre_q + (pcs_out_q - HM_q);
				} else {
					pcs_out_p_now = pcs_out_pre_p;
					pcs_out_q_now = pcs_out_pre_q;
				}
				/*先做只有一台的*/
			}
			/*控制PCS輸出*/
			if (set_source == "Local"
					or (set_source == "Remote" and remote_first_run == false)) {/*要讀到才能控制*/
				/*vvvvvvvvvvvvvvvvv暫時寫死資料vvvvvvvvvvvvvvvvvvv*/
				int pcs_start_p = 10; /*P寫入*/
				int pcs_len_p = 1;
				int pcs_start_q = 11; /*Q寫入*/
				int pcs_len_q = 1;

				double pcs_scale_p = 10.0;
				double pcs_scale_q = 10.0;
				/*^^^^^^^^^^^^^^^^^^^暫時寫死資料^^^^^^^^^^^^^^^^^^^*/
				uint16_t *pcs_write_arr_p = new uint16_t[pcs_len_p];
				uint16_t *pcs_write_arr_q = new uint16_t[pcs_len_q];

				/*modbus PCS 控制    P(pcs_out_p_now)*/
				int pcs_write_buffer = int(pcs_out_p_now * pcs_scale_p);
				if (pcs_out_p_now >= 0) {
				} else {
					pcs_write_buffer = (abs(pcs_write_buffer) ^ xorbit) + 1;
				}
				/*1*/
				pcs_write_arr_p[0] = pcs_write_buffer;
				/*2*//*
				 pcs_write_arr_p[0] = pcs_write_buffer>>16;
				 pcs_write_arr_p[1] = pcs_write_buffer - ((pcs_write_buffer>>16)<<16);*/

				/*modbus PCS 控制    Q(pcs_out_q_now)*/
				pcs_write_buffer = int(pcs_out_q_now * pcs_scale_q);
				if (pcs_out_q_now >= 0) {
				} else {
					pcs_write_buffer = (abs(pcs_write_buffer) ^ xorbit) + 1;
				}
				/*1*/
				pcs_write_arr_q[0] = pcs_write_buffer;
				/*2*//*
				 pcs_write_arr_q[0] = pcs_write_buffer>>16;
				 pcs_write_arr_q[1] = pcs_write_buffer - ((pcs_write_buffer>>16)<<16);*/

//				if (modbus_write_register(pcs_write_ctx, pcs_start_p,
//						pcs_len_p, pcs_write_arr_p) != -1) {
				if (modbus_write_register(pcs_read_ctx, pcs_start_p,
						pcs_write_arr_p[0]) == 1) {
					/*p寫入成功*/
//					std::cout<<"OKKKKKKK"<<std::endl;
					pcs_out_pre_p = pcs_out_p_now;/*有寫入成功才能代表有輸出*/

				} else {
					/*p寫入失敗*/
//					std::cout<<"errorrrrr"<<std::endl;
					pcs_read_ret = -1;
				}
//				if (modbus_write_register(pcs_write_ctx, pcs_start_q,
//						pcs_len_q, pcs_write_arr_q) != -1) {
				if (modbus_write_register(pcs_read_ctx, pcs_start_q,
						pcs_write_arr_q[0]) == 1) {
					/*q寫入成功*/
					pcs_out_pre_q = pcs_out_q_now;/*有寫入成功才能代表有輸出*/
				} else {/*q寫入失敗*/
					pcs_read_ret = -1;
				}
				delete pcs_write_arr_p;
				delete pcs_write_arr_q;
			}

			if (lock_buffer_100ms == 9) {
//				std::cout << "insert HM data to mongo" << std::endl;
				std::vector<bsoncxx::document::value> HM_docs;
				std::vector<bsoncxx::document::value> HM_docs_one;
				double HM_time_array[10];
				double HM_TPC_array[10][10];
				std::string point_name[10] = {"v_a","v_b","v_c","i_a","i_b",
				"i_c","f","p","q","pf"};
				for (int y = 0; y < 10; y++) {
					HM_time_array[y] = HM_time[y];
					HM_TPC_array[0][y] = HM_data[9][y];/*v_a*/
					HM_TPC_array[1][y] = HM_data[10][y];/*v_b*/
					HM_TPC_array[2][y] = HM_data[11][y];/*v_c*/
					HM_TPC_array[3][y] = HM_data[0][y];/*i_a*/
					HM_TPC_array[4][y] = HM_data[1][y];/*i_b*/
					HM_TPC_array[5][y] = HM_data[2][y];/*i_c*/
					if (ability_test != "None") {
						HM_data[4][y] = HM_data[4][0];
					}
					HM_TPC_array[6][y] = HM_data[4][y];/*f*/
					HM_TPC_array[7][y] = HM_data[16][y];/*p*/
					HM_TPC_array[8][y] = HM_data[20][y];/*q*/
					HM_TPC_array[9][y] = HM_data[28][y];/*pf*/
				}
				for (int y = 0; y < 10; y++) {
					if ((HM_data[0][y] != -1 or HM_data[3][y] != -1
							or HM_data[4][y] != -1) and (first_run == false)) {
						bsoncxx::builder::basic::document doc_one;
						std::string keya;
						doc_one.append(kvp("ID", HM_eid));
						doc_one.append(kvp("time", bsoncxx::types::b_date {
									std::chrono::system_clock::from_time_t(
											HM_time[y])
											+ std::chrono::milliseconds(
													y * 100) }));
						int count_point = 0;
						while (modbus_device["meter"][Meter_mode]["Point"].GetKey(keya)){
							doc_one.append(kvp(keya, HM_data[count_point][y]));
							count_point++;
						}
						HM_docs.push_back(doc_one.extract());
					} else {
//						std::cout << std::to_string(HM_time[y]) << std::endl;
						bsoncxx::builder::basic::document doc_one;
						std::string keya;
						doc_one.append(kvp("ID", HM_eid));
						doc_one.append(kvp("time", bsoncxx::types::b_date {
									std::chrono::system_clock::from_time_t(
											HM_time[y])
											+ std::chrono::milliseconds(
													y * 100) }));
						int count_point = 0;
						while (modbus_device["meter"][Meter_mode]["Point"].GetKey(keya)){
							doc_one.append(kvp(keya, bsoncxx::types::b_null {}));
							count_point++;
						}
					}
				}
				try {
					db["acm"].insert_many(HM_docs);
				} catch (...) {
				}
				try {
					db_local["acm"].insert_many(HM_docs);
				} catch (...) {
				}
				bool check_arr[10];
				for (int y = 0; y < 10; y++) {
					if (HM_data[0][y] != -1 or HM_data[3][y] != -1
							or HM_data[4][y] != -1) {
						check_arr[y] = true;
					} else {
						check_arr[y] = false;
					}
				}
				if ((HM_data[0][0] != -1 or HM_data[3][0] != -1
						or HM_data[4][0] != -1) and (first_run == false)) {

					bsoncxx::builder::basic::document doc_one;
					std::string keya;
					doc_one.append(kvp("ID", HM_eid));
					for (int y = 0; y < 10; y++) {
						doc_one.append(kvp("time", bsoncxx::types::b_date {
									std::chrono::system_clock::from_time_t(
											HM_time[y])
											+ std::chrono::milliseconds(
													y * 100) }));
					}
					for (int x = 0; x < 10; x++){/*point數*/
						double point_array[10];
						for (int y = 0;y <10 ;y++){/*每0.1s整理*/
							point_array[y] = HM_TPC_array[x][y];
						}
						doc_one.append(kvp(point_name[x],
								[&point_array](sub_array child) {
								for (const double &element : point_array) {
									child.append(element);
								}
						}));
					}
					HM_docs_one.push_back(doc_one.extract());
				} else {
					bsoncxx::builder::basic::document doc_one;
					std::string keya;
					doc_one.append(kvp("ID", HM_eid));
					for (int y = 0; y < 10; y++) {
						doc_one.append(kvp("time", bsoncxx::types::b_date {
									std::chrono::system_clock::from_time_t(
											HM_time[y])
											+ std::chrono::milliseconds(
													y * 100) }));
					}
					for (int x = 0; x < 10; x++){/*point數*/
						double point_array[10];
						for (int y = 0;y <10 ;y++){/*每0.1s整理*/
							point_array[y] = HM_TPC_array[x][y];
						}
						doc_one.append(kvp(point_name[x],
								[&point_array](sub_array child) {
								for (const double &element : point_array) {
									bsoncxx::types::b_null { };
								}
						}));
					}
					HM_docs_one.push_back(doc_one.extract());
				}
				try {
					db["TPC"].insert_many(HM_docs_one);
				} catch (...) {
				}
				try {
					db_local["TPC"].insert_many(HM_docs_one);
				} catch (...) {
				}
				if (ability_test != "None") {
					if (ability_test == "1") {
						AbilityTest::dReg025_1 dReg025_1;
						if (ability_test_count == dReg025_1.total_time) {
							ability_test = "None";
						}
					} else if (ability_test == "2") {
						AbilityTest::dReg025_2 dReg025_2;
						if (ability_test_count == dReg025_2.total_time) {
							ability_test = "None";
						}
					} else if (ability_test == "3") {
						AbilityTest::dReg025_3 dReg025_3;
						if (ability_test_count == dReg025_3.total_time) {
							ability_test = "None";
						}
					} else if (ability_test == "4") {
						AbilityTest::dReg025_4 dReg025_4;
						if (ability_test_count == dReg025_4.total_time) {
							ability_test = "None";
						}
					} else if (ability_test == "5") {
						AbilityTest::dReg025_5 dReg025_5;
						if (ability_test_count == dReg025_5.total_time) {
							ability_test = "None";
						}
					} else if (ability_test == "6") {
						AbilityTest::dReg05_6 dReg05_6;
						if (ability_test_count == dReg05_6.total_time) {
							ability_test = "None";
						}
					} else if (ability_test == "7") {
						AbilityTest::dReg05_7 dReg05_7;
						if (ability_test_count == dReg05_7.total_time) {
							ability_test = "None";
						}
					} else if (ability_test == "8") {
						AbilityTest::dReg05_8 dReg05_8;
						if (ability_test_count == dReg05_8.total_time) {
							ability_test = "None";
						}
					} else if (ability_test == "9") {
						AbilityTest::dReg05_9 dReg05_9;
						if (ability_test_count == dReg05_9.total_time) {
							ability_test = "None";
						}
					} else if (ability_test == "10") {
						AbilityTest::dReg05_10 dReg05_10;
						if (ability_test_count == dReg05_10.total_time) {
							ability_test = "None";
						}
					} else if (ability_test == "11") {
						AbilityTest::sReg_11 sReg_11;
						if (ability_test_count == sReg_11.total_time) {
							ability_test = "None";
						}
					} else if (ability_test == "12") {
						AbilityTest::sReg_12 sReg_12;
						if (ability_test_count == sReg_12.total_time) {
							ability_test = "None";
						}
					} else if (ability_test == "13") {
						AbilityTest::sReg_13 sReg_13;
						if (ability_test_count == sReg_13.total_time) {
							ability_test = "None";
						}
					}
				}
			}
			if (lock_buffer_100ms == 0) {/*每 1s*/
//			if (true) {/*每 0.1s*/
				PCS_ReadData_thread(pcsdata, LEDstate, set_source,
						pcs_control_local, pcs_reset_local, pcs_reset,
						pcs_control, control_flag, pcs_control_time_local,
						pcs_control_time_remote, pcs_control_time,
						pcs_read_error_count, pcs_read_arr, pcs_ip, pcs_port,
						pcs_id, pcs_read_ctx, pcs_read_ret,
						modbus_link_pcs_read_flag, PCS_eid, db, db_local);
			}
			function_run = false;
		} else { /*已經有程式在運行(上次超過0.1s)*/
			std::cout << " control_thread over 0.1s " << std::endl;
			for (int x = 0; x < 41; x++) {
				HM_data[x][lock_buffer_100ms] = -1;
			}
		}
		error_flag = false;
	} catch (...) {
		if (error_flag == false) {
			std::vector<bsoncxx::document::value> error_docs;
			time_t now = time(0);
			now += 28800;
			error_docs.push_back(
					make_document(kvp("ID", "GC"),
							kvp("time",
									bsoncxx::types::b_date {
											std::chrono::system_clock::from_time_t(
													now) }),
							kvp("event", "unknow error " + fc_name),
							kvp("group", fc_name), kvp("level", 1),
							kvp("show", 1)));
			try {
				db_local["alarm"].insert_many(error_docs);
			} catch (...) {
			}
			error_flag = true;
		}
		function_run = false;
	}
	thread_count--;
}
int dllgc::AFC_run(bool &stopflag, int &error_code, std::string &ability_test,
		double &pcs_control_local, double &pcs_reset_local,
		double &pcs_control_time_local, double *emsdata, double *mbmsdata,
		double *HMdata, double *pcsdata, int *LEDstate, std::string MBMS_eid,
		std::string HM_eid, std::string PCS_eid, std::string set_source,
		int &mode, double scale, double soc_max, double soc_min,
		double System_p_max, double System_p_min, double System_q_max,
		double System_q_min, double *f_arr, double *p_arr, double *v_arr,
		double *q_arr, double &PQ_p_ref, double &PQ_q_ref, int FP_type,
		double FP_soc_goal_percent, double FP_main_f_set, double FP_line_p_base,
		double FP_soc_dead_band, double FP_soc_adjust, int VC_type,
		double Vq_v_base, double Vq_q_base, double Vq_droop, double Vq_v_set,
		double PF_pf_ref, std::string pcs_ip, int pcs_port, int pcs_id,
		std::string HM_ip, int HM_port, int HM_id) {
	try {
//		std::cout << " AFC_run start " << std::endl;
//		std::cout << "pcs_ip :" << pcs_ip << " pcs_port :" << pcs_port
//				<< std::endl;
//		std::cout << "HM_ip :" << HM_ip << " HM_port :" << HM_port << std::endl;
		/*搜尋Mongo 初始化*/
		mongocxx::database db; /*定義資料庫*/
		mongocxx::database db2; /*定義資料庫*/
//		mongocxx::database db3; /*定義資料庫*/
		mongocxx::database db4; /*定義資料庫*/
//		std::cout << "ems_redundant :" << ems_redundant << std::endl;
		std::string url_data;
		if (ems_redundant == "0") {
			url_data = "mongodb://" + user + ":" + pwd + "@" + IP1 + ":"
					+ std::to_string(mongo_port1)
					+ "/admin?authSource=admin&serverSelectionTimeoutMS=100";
		} else if (ems_redundant == "2") {
			url_data =
					"mongodb://" + user + ":" + pwd + "@" + IP1 + ":"
							+ std::to_string(mongo_port1) + "," + IP2 + ":"
							+ std::to_string(mongo_port2)
							+ "/admin?authSource=admin&serverSelectionTimeoutMS=100&replicaSet=rs0";
		}
		std::cout << url_data << std::endl;
		mongocxx::uri uri(url_data);
		mongocxx::client client(uri);
		mongocxx::client client2(uri);
//		mongocxx::client client3(uri);
		mongocxx::client client4(uri);
		db = client["AFC"];
		db2 = client2["AFC"];
//		db3 = client3["AFC"];
		db4 = client4["AFC"];
		mongocxx::database db_local; /*定義資料庫*/
		mongocxx::database db2_local; /*定義資料庫*/
//		mongocxx::database db3_local; /*定義資料庫*/
		mongocxx::database db4_local; /*定義資料庫*/
		mongocxx::database db5_local; /*定義資料庫*/
		std::string url_data_local =
				"mongodb://root:pc152@127.0.0.1:27017/admin?authSource=admin&serverSelectionTimeoutMS=100";
		std::cout << url_data_local << std::endl;
		mongocxx::uri uri_local(url_data_local);
		mongocxx::client client_local(uri_local);
		mongocxx::client client2_local(uri_local);
//		mongocxx::client client3_local(uri_local);
		mongocxx::client client4_local(uri_local);
		mongocxx::client client5_local(uri_local);
		db_local = client_local["AFC_local"];
		db2_local = client2_local["AFC_local"];
//		db3_local = client3_local["AFC_local"];
		db4_local = client4_local["AFC_local"];
		db5_local = client5_local["AFC_local"];
		/*PCS modbus TCP 宣告*/
		modbus_t *pcs_read_ctx = modbus_new_tcp(pcs_ip.c_str(), pcs_port);
//		modbus_t *pcs_write_ctx = modbus_new_tcp(pcs_ip.c_str(), pcs_port);
		if (pcs_read_ctx == NULL) {
			printf("Unable to create the libmodbus PCS read context\n");
			std::cout << "pcs_ip : " << pcs_ip << "pcs_port : " << pcs_port
					<< std::endl;
			fflush(stdout);
		}
//		if (pcs_write_ctx == NULL) {
//			printf("Unable to create the libmodbus PCS write context\n");
//			std::cout << "pcs_ip : " << pcs_ip << "pcs_port : " << pcs_port
//					<< std::endl;
//			fflush(stdout);
//		}
		int pcs_read_ret;
//		int pcs_write_ret;
//		std::cout  << "pcs_id : " << pcs_id<< std::endl;
		modbus_set_slave(pcs_read_ctx, pcs_id);
//		modbus_set_slave(pcs_write_ctx, pcs_id);
		modbus_set_response_timeout(pcs_read_ctx, 0, 300000);
		pcs_read_ret = modbus_connect(pcs_read_ctx);
//		pcs_write_ret = modbus_connect(pcs_write_ctx);
		/*High Meter modbus TCP 宣告*/
		modbus_t *HM_ctx = modbus_new_tcp(HM_ip.c_str(), HM_port);
		if (HM_ctx == NULL) {
			printf("Unable to create the libmodbus context HM_ctx\n");
			std::cout << "HM_ip : " << HM_ip << "HM_port : " << HM_port
					<< std::endl;
			fflush(stdout);
		}
		int HM_ret;

		modbus_set_slave(HM_ctx, HM_id);
		modbus_set_response_timeout(HM_ctx, 0, 30000);
		HM_ret = modbus_connect(HM_ctx);
		/*參數宣告*/
		double HM_f = 0;
		double HM_p = 0;
		double HM_v = 0;
		double HM_q = 0;

		/*dReg 計算*/
		FP_soc_adjust = FP_soc_adjust / 100.0;
		p_arr[0] = p_arr[0] * FP_line_p_base / 100;
		p_arr[1] = p_arr[1] * FP_line_p_base / 100;
		p_arr[2] = p_arr[2] * FP_line_p_base / 100;
		p_arr[3] = p_arr[3] * FP_line_p_base / 100;
		p_arr[4] = p_arr[4] * FP_line_p_base / 100;
		p_arr[5] = p_arr[5] * FP_line_p_base / 100;
		double a1 = (p_arr[1] - p_arr[0]) / (f_arr[1] - f_arr[0]) * 1.000;
		double a21 = ((p_arr[2] + (FP_soc_adjust * FP_line_p_base)) - p_arr[1])
				/ (f_arr[2] - f_arr[1]) * 1.000;
		double a22 = (p_arr[2] - p_arr[1]) / (f_arr[2] - f_arr[1]) * 1.000;
		double a23 = ((p_arr[2] - (FP_soc_adjust * FP_line_p_base)) - p_arr[1])
				/ (f_arr[2] - f_arr[1]) * 1.000;
//		double a3 = 0; /*中間值自由調整為0無須斜率*/
		double a41 = (p_arr[4] - (p_arr[3] + (FP_soc_adjust * FP_line_p_base)))
				/ (f_arr[4] - f_arr[3]) * 1.000;
		double a42 = (p_arr[4] - p_arr[3]) / (f_arr[4] - f_arr[3]) * 1.000;
		double a43 = (p_arr[4] - (p_arr[3] - (FP_soc_adjust * FP_line_p_base)))
				/ (f_arr[4] - f_arr[3]) * 1.000;
		double a5 = (p_arr[5] - p_arr[4]) / (f_arr[5] - f_arr[4]) * 1.000;

		double b1 = p_arr[0] - a1 * f_arr[0] * 1.000;
		double b21 = p_arr[1] - a21 * f_arr[1] * 1.000;
		double b22 = p_arr[1] - a22 * f_arr[1] * 1.000;
		double b23 = p_arr[1] - a23 * f_arr[1] * 1.000;
		double b3 = FP_soc_adjust * FP_line_p_base;
		double b41 = p_arr[4] - a41 * f_arr[4] * 1.000;
		double b42 = p_arr[4] - a42 * f_arr[4] * 1.000;
		double b43 = p_arr[4] - a43 * f_arr[4] * 1.000;
		double b5 = p_arr[5] - a5 * f_arr[5] * 1.000;
		/*sReg計算*/
		double a_sReg = (p_arr[3] - p_arr[2]) / (f_arr[3] - f_arr[2]) * 1.000;
		;
		double b_sReg = p_arr[3] - a_sReg * f_arr[3] * 1.000;
		/*VQ計算*/
		double a_qAuto = Vq_droop;
		double b_qAuto = Vq_q_base - (Vq_droop * Vq_v_base);

		double control_ab_data[21] = { a1, a21, a22, a23, a41, a42, a43, a5, b1,
				b21, b22, b23, b3, b41, b42, b43, b5, a_sReg, b_sReg, a_qAuto,
				b_qAuto };
		/*上傳啟動資訊*/
		std::cout << "AFC start" << std::endl;
		std::vector<bsoncxx::document::value> status_docs;
		time_t now = time(0);
		now += 28800;
		status_docs.push_back(
				make_document(kvp("ID", "GC"),
						kvp("time", bsoncxx::types::b_date {
								std::chrono::system_clock::from_time_t(now) }),
						kvp("event", "AFC start"), kvp("group", "AFC_run"),
						kvp("level", 1), kvp("show", 1)));
		try {
			db_local["status"].insert_many(status_docs);
		} catch (...) {
		}
		/*其餘參數設定*/
		Timer *t = new Timer();
//		std::cout << " AFC_run setFixedTime_AFG start " << std::endl;
		std::string ability_test_buffer = ability_test;
		double pcs_control_local_buffer = 0;
		double pcs_reset_local_buffer = 0;
		double pcs_control_time_local_buffer = 0;
		double PQ_p_ref_buffer = PQ_p_ref;
		double PQ_q_ref_buffer = PQ_q_ref;
		double mode_buffer = mode;
		t->ability_test = "None";
		t->pcs_control_local = 0;
		t->pcs_reset_local = 0;
		t->pcs_control_time_local = 0;
		t->PQ_p_ref = PQ_p_ref;
		t->PQ_q_ref = PQ_q_ref;
		t->mode = mode;
		t->setFixedTime_AFG(control_thread, HM_link_thread, error_thread,
				PCS_ReadData_thread, EMS_ReadData_thread, set_source, emsdata,
				mbmsdata, HMdata, pcsdata, LEDstate, scale, soc_max, soc_min,
				System_p_max, System_p_min, System_q_max, System_q_min, f_arr,
				p_arr, v_arr, q_arr, FP_type, FP_soc_goal_percent,
				FP_main_f_set, FP_line_p_base, FP_soc_dead_band, FP_soc_adjust,
				VC_type, Vq_v_base, Vq_q_base, Vq_droop, Vq_v_set, PF_pf_ref,
				HM_ctx, HM_ret, HM_f, HM_p, HM_v, HM_q, pcs_read_ctx,
				pcs_read_ret, control_ab_data, MBMS_eid, HM_eid, PCS_eid,
				pcs_ip, pcs_port, pcs_id, HM_ip, HM_port, HM_id, db, db2, db4,
				db_local, db2_local, db4_local, db5_local);
		while (true) {
			if (set_source == "Local") {
				if (ability_test_buffer != ability_test) {
					std::cout << ability_test_buffer << std::endl;
					std::cout << ability_test << std::endl;
					t->ability_test = ability_test;
					ability_test_buffer = ability_test;
					std::cout << "ability_test ui change" << std::endl;
				}
				if (pcs_control_local_buffer != pcs_control_local) {
					t->pcs_control_local = pcs_control_local;
					pcs_control_local_buffer = pcs_control_local;
					std::cout << "pcs_connect_local change" << std::endl;
				}
				if (pcs_reset_local_buffer != pcs_reset_local) {
					t->pcs_reset_local = pcs_reset_local;
					pcs_reset_local_buffer = pcs_reset_local;
					std::cout << "pcs_reset_local change" << std::endl;
				}
				if (pcs_control_time_local_buffer != pcs_control_time_local) {
					t->pcs_control_time_local = pcs_control_time_local;
					pcs_control_time_local_buffer = pcs_control_time_local;
					std::cout << "pcs_control_time_local change" << std::endl;
				}
				if (PQ_p_ref_buffer != PQ_p_ref) {
					t->PQ_p_ref = PQ_p_ref;
					PQ_p_ref_buffer = PQ_p_ref;
				}
				if (PQ_q_ref_buffer != PQ_q_ref) {
					t->PQ_q_ref = PQ_q_ref;
					PQ_q_ref_buffer = PQ_q_ref;
				}
				if (mode_buffer != mode) {
					t->mode = mode;
					mode_buffer = mode;
				}
			}
			if (stopflag == true) {
				t->stop();
				Sleep(1000);
				break;
			}
//			time_print_m("main running",1);
			Sleep(100);
		}
		/*上傳結束資訊*/
		std::cout << "AFC end" << std::endl;
		now = time(0);
		now += 28800;
		status_docs.push_back(
				make_document(kvp("ID", "GC"),
						kvp("time", bsoncxx::types::b_date {
								std::chrono::system_clock::from_time_t(now) }),
						kvp("event", "AFC end"), kvp("group", "AFC_run"),
						kvp("level", 1), kvp("show", 1)));
		try {
			db_local["status"].insert_many(status_docs);
		} catch (...) {
		}
		delete t;

		modbus_close(pcs_read_ctx);
		modbus_free(pcs_read_ctx);
//		modbus_close(pcs_write_ctx);
//		modbus_free(pcs_write_ctx);
		modbus_close(HM_ctx);
		modbus_free(HM_ctx);

	} catch (...) {
		time_print_m("main error", 1);
	}
	return 0;
}

