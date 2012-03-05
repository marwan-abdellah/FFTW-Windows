/*
 * Copyright (c) 2003, 2007-11 Matteo Frigo
 * Copyright (c) 2003, 2007-11 Massachusetts Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

/* This file was automatically generated --- DO NOT EDIT */
/* Generated on Tue Feb 21 19:01:46 EST 2012 */

#include "codelet-dft.h"

#ifdef HAVE_FMA

/* Generated by: ../../../genfft/gen_twiddle_c.native -fma -reorder-insns -schedule-for-pipeline -simd -compact -variables 4 -pipeline-latency 8 -twiddle-log3 -precompute-twiddles -no-generate-bytw -n 10 -name t3fv_10 -include t3f.h */

/*
 * This function contains 57 FP additions, 52 FP multiplications,
 * (or, 39 additions, 34 multiplications, 18 fused multiply/add),
 * 57 stack variables, 4 constants, and 20 memory accesses
 */
#include "t3f.h"

static void t3fv_10(R *ri, R *ii, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DVK(KP559016994, +0.559016994374947424102293417182819058860154590);
     DVK(KP250000000, +0.250000000000000000000000000000000000000000000);
     DVK(KP618033988, +0.618033988749894848204586834365638117720309180);
     DVK(KP951056516, +0.951056516295153572116439333379382143405698634);
     {
	  INT m;
	  R *x;
	  x = ri;
	  for (m = mb, W = W + (mb * ((TWVL / VL) * 6)); m < me; m = m + VL, x = x + (VL * ms), W = W + (TWVL * 6), MAKE_VOLATILE_STRIDE(rs)) {
	       V T1, T7, Th, Tx, Tr, Td, Tp, T6, Tv, Tc, Te, Ti, Tl, T2, T3;
	       V T5;
	       T2 = LDW(&(W[0]));
	       T3 = LDW(&(W[TWVL * 2]));
	       T5 = LDW(&(W[TWVL * 4]));
	       T1 = LD(&(x[0]), ms, &(x[0]));
	       T7 = LD(&(x[WS(rs, 5)]), ms, &(x[WS(rs, 1)]));
	       {
		    V To, Tw, Tq, Tu, Ta, T4, Tt, Tk, Tb;
		    To = LD(&(x[WS(rs, 4)]), ms, &(x[0]));
		    Tw = LD(&(x[WS(rs, 1)]), ms, &(x[WS(rs, 1)]));
		    Tq = LD(&(x[WS(rs, 9)]), ms, &(x[WS(rs, 1)]));
		    Tu = LD(&(x[WS(rs, 6)]), ms, &(x[0]));
		    Ta = VZMULJ(T2, T3);
		    T4 = VZMUL(T2, T3);
		    Th = VZMULJ(T2, T5);
		    Tt = VZMULJ(T3, T5);
		    Tb = LD(&(x[WS(rs, 2)]), ms, &(x[0]));
		    Tx = VZMULJ(T2, Tw);
		    Tr = VZMULJ(T5, Tq);
		    Tk = LD(&(x[WS(rs, 3)]), ms, &(x[WS(rs, 1)]));
		    Td = VZMULJ(Ta, T5);
		    Tp = VZMULJ(T4, To);
		    T6 = VZMULJ(T4, T5);
		    Tv = VZMULJ(Tt, Tu);
		    Tc = VZMULJ(Ta, Tb);
		    Te = LD(&(x[WS(rs, 7)]), ms, &(x[WS(rs, 1)]));
		    Ti = LD(&(x[WS(rs, 8)]), ms, &(x[0]));
		    Tl = VZMULJ(T3, Tk);
	       }
	       {
		    V TN, Ts, T8, Ty, TO, Tf, Tj;
		    TN = VADD(Tp, Tr);
		    Ts = VSUB(Tp, Tr);
		    T8 = VZMULJ(T6, T7);
		    Ty = VSUB(Tv, Tx);
		    TO = VADD(Tv, Tx);
		    Tf = VZMULJ(Td, Te);
		    Tj = VZMULJ(Th, Ti);
		    {
			 V T9, TJ, TP, TU, Tz, TF, Tg, TK, Tm, TL;
			 T9 = VSUB(T1, T8);
			 TJ = VADD(T1, T8);
			 TP = VADD(TN, TO);
			 TU = VSUB(TN, TO);
			 Tz = VADD(Ts, Ty);
			 TF = VSUB(Ts, Ty);
			 Tg = VSUB(Tc, Tf);
			 TK = VADD(Tc, Tf);
			 Tm = VSUB(Tj, Tl);
			 TL = VADD(Tj, Tl);
			 {
			      V TM, TV, Tn, TE;
			      TM = VADD(TK, TL);
			      TV = VSUB(TK, TL);
			      Tn = VADD(Tg, Tm);
			      TE = VSUB(Tg, Tm);
			      {
				   V TW, TY, TS, TQ, TG, TI, TC, TA, TR, TB;
				   TW = VMUL(LDK(KP951056516), VFNMS(LDK(KP618033988), TV, TU));
				   TY = VMUL(LDK(KP951056516), VFMA(LDK(KP618033988), TU, TV));
				   TS = VSUB(TM, TP);
				   TQ = VADD(TM, TP);
				   TG = VMUL(LDK(KP951056516), VFMA(LDK(KP618033988), TF, TE));
				   TI = VMUL(LDK(KP951056516), VFNMS(LDK(KP618033988), TE, TF));
				   TC = VSUB(Tn, Tz);
				   TA = VADD(Tn, Tz);
				   ST(&(x[0]), VADD(TJ, TQ), ms, &(x[0]));
				   TR = VFNMS(LDK(KP250000000), TQ, TJ);
				   ST(&(x[WS(rs, 5)]), VADD(T9, TA), ms, &(x[WS(rs, 1)]));
				   TB = VFNMS(LDK(KP250000000), TA, T9);
				   {
					V TX, TT, TH, TD;
					TX = VFMA(LDK(KP559016994), TS, TR);
					TT = VFNMS(LDK(KP559016994), TS, TR);
					TH = VFNMS(LDK(KP559016994), TC, TB);
					TD = VFMA(LDK(KP559016994), TC, TB);
					ST(&(x[WS(rs, 8)]), VFNMSI(TW, TT), ms, &(x[0]));
					ST(&(x[WS(rs, 2)]), VFMAI(TW, TT), ms, &(x[0]));
					ST(&(x[WS(rs, 6)]), VFNMSI(TY, TX), ms, &(x[0]));
					ST(&(x[WS(rs, 4)]), VFMAI(TY, TX), ms, &(x[0]));
					ST(&(x[WS(rs, 9)]), VFMAI(TG, TD), ms, &(x[WS(rs, 1)]));
					ST(&(x[WS(rs, 1)]), VFNMSI(TG, TD), ms, &(x[WS(rs, 1)]));
					ST(&(x[WS(rs, 7)]), VFMAI(TI, TH), ms, &(x[WS(rs, 1)]));
					ST(&(x[WS(rs, 3)]), VFNMSI(TI, TH), ms, &(x[WS(rs, 1)]));
				   }
			      }
			 }
		    }
	       }
	  }
     }
     VLEAVE();
}

static const tw_instr twinstr[] = {
     VTW(0, 1),
     VTW(0, 3),
     VTW(0, 9),
     {TW_NEXT, VL, 0}
};

static const ct_desc desc = { 10, XSIMD_STRING("t3fv_10"), twinstr, &GENUS, {39, 34, 18, 0}, 0, 0, 0 };

void XSIMD(codelet_t3fv_10) (planner *p) {
     X(kdft_dit_register) (p, t3fv_10, &desc);
}
#else				/* HAVE_FMA */

/* Generated by: ../../../genfft/gen_twiddle_c.native -simd -compact -variables 4 -pipeline-latency 8 -twiddle-log3 -precompute-twiddles -no-generate-bytw -n 10 -name t3fv_10 -include t3f.h */

/*
 * This function contains 57 FP additions, 42 FP multiplications,
 * (or, 51 additions, 36 multiplications, 6 fused multiply/add),
 * 41 stack variables, 4 constants, and 20 memory accesses
 */
#include "t3f.h"

static void t3fv_10(R *ri, R *ii, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DVK(KP587785252, +0.587785252292473129168705954639072768597652438);
     DVK(KP951056516, +0.951056516295153572116439333379382143405698634);
     DVK(KP250000000, +0.250000000000000000000000000000000000000000000);
     DVK(KP559016994, +0.559016994374947424102293417182819058860154590);
     {
	  INT m;
	  R *x;
	  x = ri;
	  for (m = mb, W = W + (mb * ((TWVL / VL) * 6)); m < me; m = m + VL, x = x + (VL * ms), W = W + (TWVL * 6), MAKE_VOLATILE_STRIDE(rs)) {
	       V T1, T2, T3, Ti, T6, T7, Tx, Tb, To;
	       T1 = LDW(&(W[0]));
	       T2 = LDW(&(W[TWVL * 2]));
	       T3 = VZMULJ(T1, T2);
	       Ti = VZMUL(T1, T2);
	       T6 = LDW(&(W[TWVL * 4]));
	       T7 = VZMULJ(T3, T6);
	       Tx = VZMULJ(Ti, T6);
	       Tb = VZMULJ(T1, T6);
	       To = VZMULJ(T2, T6);
	       {
		    V TA, TQ, Tn, Tt, Tu, TJ, TK, TS, Ta, Tg, Th, TM, TN, TR, Tw;
		    V Tz, Ty;
		    Tw = LD(&(x[0]), ms, &(x[0]));
		    Ty = LD(&(x[WS(rs, 5)]), ms, &(x[WS(rs, 1)]));
		    Tz = VZMULJ(Tx, Ty);
		    TA = VSUB(Tw, Tz);
		    TQ = VADD(Tw, Tz);
		    {
			 V Tk, Ts, Tm, Tq;
			 {
			      V Tj, Tr, Tl, Tp;
			      Tj = LD(&(x[WS(rs, 4)]), ms, &(x[0]));
			      Tk = VZMULJ(Ti, Tj);
			      Tr = LD(&(x[WS(rs, 1)]), ms, &(x[WS(rs, 1)]));
			      Ts = VZMULJ(T1, Tr);
			      Tl = LD(&(x[WS(rs, 9)]), ms, &(x[WS(rs, 1)]));
			      Tm = VZMULJ(T6, Tl);
			      Tp = LD(&(x[WS(rs, 6)]), ms, &(x[0]));
			      Tq = VZMULJ(To, Tp);
			 }
			 Tn = VSUB(Tk, Tm);
			 Tt = VSUB(Tq, Ts);
			 Tu = VADD(Tn, Tt);
			 TJ = VADD(Tk, Tm);
			 TK = VADD(Tq, Ts);
			 TS = VADD(TJ, TK);
		    }
		    {
			 V T5, Tf, T9, Td;
			 {
			      V T4, Te, T8, Tc;
			      T4 = LD(&(x[WS(rs, 2)]), ms, &(x[0]));
			      T5 = VZMULJ(T3, T4);
			      Te = LD(&(x[WS(rs, 3)]), ms, &(x[WS(rs, 1)]));
			      Tf = VZMULJ(T2, Te);
			      T8 = LD(&(x[WS(rs, 7)]), ms, &(x[WS(rs, 1)]));
			      T9 = VZMULJ(T7, T8);
			      Tc = LD(&(x[WS(rs, 8)]), ms, &(x[0]));
			      Td = VZMULJ(Tb, Tc);
			 }
			 Ta = VSUB(T5, T9);
			 Tg = VSUB(Td, Tf);
			 Th = VADD(Ta, Tg);
			 TM = VADD(T5, T9);
			 TN = VADD(Td, Tf);
			 TR = VADD(TM, TN);
		    }
		    {
			 V Tv, TB, TC, TG, TI, TE, TF, TH, TD;
			 Tv = VMUL(LDK(KP559016994), VSUB(Th, Tu));
			 TB = VADD(Th, Tu);
			 TC = VFNMS(LDK(KP250000000), TB, TA);
			 TE = VSUB(Ta, Tg);
			 TF = VSUB(Tn, Tt);
			 TG = VBYI(VFMA(LDK(KP951056516), TE, VMUL(LDK(KP587785252), TF)));
			 TI = VBYI(VFNMS(LDK(KP587785252), TE, VMUL(LDK(KP951056516), TF)));
			 ST(&(x[WS(rs, 5)]), VADD(TA, TB), ms, &(x[WS(rs, 1)]));
			 TH = VSUB(TC, Tv);
			 ST(&(x[WS(rs, 3)]), VSUB(TH, TI), ms, &(x[WS(rs, 1)]));
			 ST(&(x[WS(rs, 7)]), VADD(TI, TH), ms, &(x[WS(rs, 1)]));
			 TD = VADD(Tv, TC);
			 ST(&(x[WS(rs, 1)]), VSUB(TD, TG), ms, &(x[WS(rs, 1)]));
			 ST(&(x[WS(rs, 9)]), VADD(TG, TD), ms, &(x[WS(rs, 1)]));
		    }
		    {
			 V TV, TT, TU, TP, TX, TL, TO, TY, TW;
			 TV = VMUL(LDK(KP559016994), VSUB(TR, TS));
			 TT = VADD(TR, TS);
			 TU = VFNMS(LDK(KP250000000), TT, TQ);
			 TL = VSUB(TJ, TK);
			 TO = VSUB(TM, TN);
			 TP = VBYI(VFNMS(LDK(KP587785252), TO, VMUL(LDK(KP951056516), TL)));
			 TX = VBYI(VFMA(LDK(KP951056516), TO, VMUL(LDK(KP587785252), TL)));
			 ST(&(x[0]), VADD(TQ, TT), ms, &(x[0]));
			 TY = VADD(TV, TU);
			 ST(&(x[WS(rs, 4)]), VADD(TX, TY), ms, &(x[0]));
			 ST(&(x[WS(rs, 6)]), VSUB(TY, TX), ms, &(x[0]));
			 TW = VSUB(TU, TV);
			 ST(&(x[WS(rs, 2)]), VADD(TP, TW), ms, &(x[0]));
			 ST(&(x[WS(rs, 8)]), VSUB(TW, TP), ms, &(x[0]));
		    }
	       }
	  }
     }
     VLEAVE();
}

static const tw_instr twinstr[] = {
     VTW(0, 1),
     VTW(0, 3),
     VTW(0, 9),
     {TW_NEXT, VL, 0}
};

static const ct_desc desc = { 10, XSIMD_STRING("t3fv_10"), twinstr, &GENUS, {51, 36, 6, 0}, 0, 0, 0 };

void XSIMD(codelet_t3fv_10) (planner *p) {
     X(kdft_dit_register) (p, t3fv_10, &desc);
}
#endif				/* HAVE_FMA */
