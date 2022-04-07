/*
 * dllgc.h
 *
 *  Created on: 2021¦~12¤ë13¤é
 *      Author: XU
 */

#ifndef DLLGC_H_
#define DLLGC_H_
#include <string>
#include "CJsonObject.hpp"
extern neb::CJsonObject modbus_device;
class AbilityTest {
public:
	class dReg025_1 {
	public:
		int time = 36;
		int run_feq = 30;
		double data[36] = { 60, 60.01, 60, 59.99, 60, 60.02, 60, 59.98, 60,
				60.07, 60, 59.93, 60, 60.14, 60, 59.86, 60, 60.20, 60, 59.80,
				60, 60.25, 60, 59.75, 60, 60.30, 60, 59.70, 60, 60.40, 60,
				59.60, 60, 60.50, 60, 59.50 };
		int total_time = 1079;
	};
	class dReg025_2 {
	public:
		int time = 60;
		int run_feq = 1;
		double data[61] = { 60.30, 60.29, 60.28, 60.27, 60.26, 60.25, 60.24,
				60.23, 60.22, 60.21, 60.20, 60.19, 60.18, 60.17, 60.16, 60.15,
				60.14, 60.13, 60.12, 60.11, 60.10, 60.09, 60.08, 60.07, 60.06,
				60.05, 60.04, 60.03, 60.02, 60.01, 60.00, 59.99, 59.98, 59.97,
				59.96, 59.95, 59.94, 59.93, 59.92, 59.91, 59.90, 59.89, 59.88,
				59.87, 59.86, 59.85, 59.84, 59.83, 59.82, 59.81, 59.80, 59.79,
				59.78, 59.77, 59.76, 59.75, 59.74, 59.73, 59.72, 59.71, 59.70 };
		int total_time = 60;
	};
	class dReg025_3 {
	public:
		int time = 60;
		int run_feq = 1;
		double data[61] = { 59.70, 59.71, 59.72, 59.73, 59.74, 59.75, 59.76,
				59.77, 59.78, 59.79, 59.80, 59.81, 59.82, 59.83, 59.84, 59.85,
				59.86, 59.87, 59.88, 59.89, 59.90, 59.91, 59.92, 59.93, 59.94,
				59.95, 59.96, 59.97, 59.98, 59.99, 60.00, 60.01, 60.02, 60.03,
				60.04, 60.05, 60.06, 60.07, 60.08, 60.09, 60.10, 60.11, 60.12,
				60.13, 60.14, 60.15, 60.16, 60.17, 60.18, 60.19, 60.20, 60.21,
				60.22, 60.23, 60.24, 60.25, 60.26, 60.27, 60.28, 60.29, 60.30 };
		int total_time = 60;
	};
	class dReg025_4 {
	public:
		int time[3] = { 0, 60, 1050 };
		double data[3] = { 60, 59.70, 60 };
		int total_time = 1059;
	};
	class dReg025_5 {
	public:
		int time[3] = { 0, 60, 1050 };
		double data[3] = { 60, 60.03, 60 };
		int total_time = 1059;
	};
	class dReg05_6 {
	public:
		int time = 36;
		int run_feq = 30;
		double data[36] = { 60, 60.01, 60, 59.99, 60, 60.02, 60, 59.98, 60,
				60.10, 60, 59.90, 60, 60.25, 60, 59.75, 60, 60.40, 60, 59.60,
				60, 60.50, 60, 59.50, 60, 60.60, 60, 59.40, 60, 60.70, 60,
				59.30, 60, 60.80, 60, 59.20 };
		int total_time = 1079;
	};
	class dReg05_7 {
	public:
		int time = 60;
		int run_feq = 1;
		double data[61] = { 60.60, 60.58, 60.56, 60.54, 60.52, 60.50, 60.48,
				60.46, 60.44, 60.42, 60.40, 60.38, 60.36, 60.34, 60.32, 60.30,
				60.28, 60.26, 60.24, 60.22, 60.20, 60.18, 60.16, 60.14, 60.12,
				60.10, 60.08, 60.06, 60.04, 60.02, 60.00, 59.98, 59.96, 59.94,
				59.92, 59.90, 59.88, 59.86, 59.84, 59.82, 59.80, 59.78, 59.76,
				59.74, 59.72, 59.70, 59.68, 59.66, 59.64, 59.62, 59.60, 59.58,
				59.56, 59.54, 59.52, 59.50, 59.48, 59.46, 59.44, 59.42, 59.40 };
		int total_time = 60;
	};
	class dReg05_8 {
	public:
		int time = 60;
		int run_feq = 1;
		double data[61] = { 59.40, 59.42, 59.44, 59.46, 59.48, 59.50, 59.52,
				59.54, 59.56, 59.58, 59.60, 59.62, 59.64, 59.66, 59.68, 59.70,
				59.72, 59.74, 59.76, 59.78, 59.80, 59.82, 59.84, 59.86, 59.88,
				59.90, 59.92, 59.94, 59.96, 59.98, 60.00, 60.02, 60.04, 60.06,
				60.08, 60.10, 60.12, 60.14, 60.16, 60.18, 60.20, 60.22, 60.24,
				60.26, 60.28, 60.30, 60.32, 60.34, 60.36, 60.38, 60.40, 60.42,
				60.44, 60.46, 60.48, 60.50, 60.52, 60.54, 60.56, 60.58, 60.60 };
		int total_time = 60;
	};
	class dReg05_9 {
	public:
		int time[3] = { 0, 60, 1050 };
		double data[3] = { 60, 59.40, 60 };
		int total_time = 1059;
	};
	class dReg05_10 {
	public:
		int time[3] = { 0, 60, 1050 };
		double data[3] = { 60, 60.70, 60 };
		int total_time = 1059;
	};
	class sReg_11 {
	public:
		int time = 20;
		int run_feq = 30;
		double data[20] = { 60.00, 59.96, 60.00, 59.92, 60.00, 59.88, 60.00,
				59.84, 59.92, 59.88, 59.96, 59.92, 59.98, 60.00, 59.80, 60.00,
				59.70, 60.00, 59.60, 59.98 };
		int total_time = 599;
	};
	class sReg_12 {
	public:
		int time = 60;
		int run_feq = 1;
		double data[61] = { 60.00, 59.99, 59.98, 59.97, 59.96, 59.95, 59.94,
				59.93, 59.92, 59.91, 59.90, 59.89, 59.88, 59.87, 59.86, 59.85,
				59.84, 59.83, 59.82, 59.81, 59.80, 59.79, 59.78, 59.77, 59.76,
				59.75, 59.74, 59.73, 59.72, 59.71, 59.70, 59.71, 59.72, 59.73,
				59.74, 59.75, 59.76, 59.77, 59.78, 59.79, 59.80, 59.81, 59.82,
				59.83, 59.84, 59.85, 59.86, 59.87, 59.88, 59.89, 59.90, 59.91,
				59.92, 59.93, 59.94, 59.95, 59.96, 59.97, 59.98, 59.99, 60.00 };
		int total_time = 60;
	};
	class sReg_13 {
	public:
		int time[3] = { 0, 59, 1050 };
		double data[3] = { 60, 59.88, 60 };
		int total_time = 1059;
	};
};
class dllgc {
public:
	dllgc();
	virtual ~dllgc();
	void print();
	std::string MBMS_eid;
	int EMSIP;
	std::string ems_redundant = "2";
	std::string IP1 = "127.0.0.1";
	std::string IP2 = "127.0.0.1";
	std::string user = "root";
	std::string pwd = "pc152";
	int mongo_port1 = 27017;
	int mongo_port2 = 27017;
	int AFC_run(bool &stopflag, int &error_code, std::string &ability_test,
			double &pcs_connect_local, double &pcs_reset_local,
			double &pcs_control_time_local, double *emsdata, double *mbmsdata,
			double *HMdata, double *pcsdata, int *LEDstate,
			std::string MBMS_eid, std::string HM_eid, std::string PCS_eid,
			std::string set_source, int &mode, double scale, double soc_max,
			double soc_min, double System_p_max, double System_p_min,
			double System_q_max, double System_q_min, double *f_arr,
			double *p_arr, double *v_arr, double *q_arr, double &PQ_p_ref,
			double &PQ_q_ref, int FP_type, double FP_soc_goal_percent,
			double FP_main_f_set, double FP_line_p_base,
			double FP_soc_dead_band, double FP_soc_adjust, int VC_type,
			double Vq_v_base, double Vq_q_base, double Vq_droop,
			double Vq_v_set, double PF_pf_ref, std::string pcs_ip, int pcs_port,
			int pcs_id, std::string HM_ip, int HM_port, int HM_id);

};
#endif /* DLLGC_H_ */
