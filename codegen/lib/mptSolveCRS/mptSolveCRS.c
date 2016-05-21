/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mptSolveCRS.c
 *
 * Code generation for function 'mptSolveCRS'
 *
 */

/* Include files */
#include "mptSolveCRS.h"
#include "petscksp.h"
#include "petscsys.h"

/* Custom Source Code */
#include "mpetsc.h"
#include "m2c.h"

/* Type Definitions */
#ifndef struct_emxArray__common
#define struct_emxArray__common

struct emxArray__common
{
  void *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray__common*/

#ifndef typedef_emxArray__common
#define typedef_emxArray__common

typedef struct emxArray__common emxArray__common;

#endif                                 /*typedef_emxArray__common*/

/* Function Declarations */
static void ab_m2c_error(int varargin_3);
static void b_m2c_error(int varargin_3);
static void b_m2c_printf(double varargin_2, int varargin_3);
static void bb_m2c_error(int varargin_3);
static void c_m2c_error(int varargin_3);
static void c_m2c_printf(double varargin_2, double varargin_3);
static void cb_m2c_error(int varargin_3);
static void d_m2c_error(int varargin_3);
static void d_m2c_printf(int varargin_2, double varargin_3);
static void db_m2c_error(int varargin_3);
static void e_m2c_error(int varargin_3);
static void e_m2c_printf(void);
static void eb_m2c_error(void);
static void emxInit_int32_T1(emxArray_int32_T **pEmxArray, int numDimensions);
static void f_m2c_error(int varargin_3);
static void fb_m2c_error(int varargin_3);
static void g_m2c_error(int varargin_3);
static void gb_m2c_error(int varargin_3);
static void h_m2c_error(int varargin_3);
static void hb_m2c_error(int varargin_3);
static void i_m2c_error(int varargin_3);
static void ib_m2c_error(int varargin_3);
static void j_m2c_error(int varargin_3);
static void jb_m2c_error(void);
static void k_m2c_error(int varargin_3);
static void kb_m2c_error(int varargin_3);
static void l_m2c_error(int varargin_3);
static void m2c_error(int varargin_3);
static void m2c_printf(KSPType varargin_2, PCType varargin_3, int varargin_4);
static void m_m2c_error(int varargin_3);
static void mptKSPSetup(Mat Amat, const emxArray_char_T *ksptype, const
  emxArray_char_T *pctype, const emxArray_char_T *solpack, KSP *ksp, double
  *time);
static void mptKSPSolve(KSP ksp, Vec b, Vec x, double rtol, int maxits, Vec x0,
  int *flag, double *relres, int *iter, double *time);
static Mat mptMatCreateAIJFromCRS(const emxArray_int32_T *row_ptr, const
  emxArray_int32_T *col_ind, const emxArray_real_T *val);
static void mptSolve(Mat A, Vec b, Vec x, const emxArray_char_T *solver, double
                     rtol, int maxit, Vec x0, int *flag, double *relres, int
                     *iter, double times[2]);
static Vec mptVecCreateFromArray(const emxArray_real_T *arr);
static void mptVecToArray(Vec vec, emxArray_real_T *arr);
static void n_m2c_error(int varargin_3);
static void o_m2c_error(int varargin_3);
static void p_m2c_error(int varargin_3);
static void q_m2c_error(int varargin_3);
static void r_m2c_error(int varargin_3);
static void s_m2c_error(int varargin_3);
static void t_m2c_error(int varargin_3);
static void u_m2c_error(int varargin_3);
static void v_m2c_error(int varargin_3);
static void w_m2c_error(int varargin_3);
static void x_m2c_error(int varargin_3);
static void y_m2c_error(int varargin_3);

/* Function Definitions */

/*
 * function m2c_error(varargin)
 */
static void ab_m2c_error(int varargin_3)
{
  /* m2c_error Issue a fatal error message. */
  /*   */
  /*  m2c_error(msg); */
  /*  m2c_error(fmt, null_terminated_char, number, ...); */
  /*  m2c_error(msg_id, fmt, null_terminated_char, number, ...); */
  /*  */
  /*  Note that the character strings associated with %s in the format must */
  /*  be null-terminated character strings. */
  /*  */
  /*  Example usage: */
  /*     m2c_error('Error message in a constant string does not need to be null-terminated.'); */
  /*     m2c_error('Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*     m2c_error('error:ID', 'Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*  */
  /*  SEE ALSO: m2c_print, m2c_warn */
  /* 'm2c_error:18' coder.inline('never'); */
  /* 'm2c_error:20' if isempty(coder.target) */
  /* 'm2c_error:22' else */
  /* 'm2c_error:23' if isequal(coder.target, 'mex') */
  /* 'm2c_error:25' else */
  /* 'm2c_error:26' cmd = 'M2C_error'; */
  /* 'm2c_error:29' if nargin==1 || ischar(varargin{1}) && ~ischar(varargin{2}) */
  /* 'm2c_error:35' else */
  /* 'm2c_error:36' msgid = coder.opaque('const char *', ['"' varargin{1} '"']); */
  /* 'm2c_error:38' fmt = coder.opaque('const char *', ['"' varargin{2} '"']); */
  /* 'm2c_error:39' coder.ceval(cmd, msgid, fmt, varargin{3:end}); */
  M2C_error("petsc:RuntimeError", "KSPDestroy returned error code %d\n",
            varargin_3);
}

/*
 * function m2c_error(varargin)
 */
static void b_m2c_error(int varargin_3)
{
  /* m2c_error Issue a fatal error message. */
  /*   */
  /*  m2c_error(msg); */
  /*  m2c_error(fmt, null_terminated_char, number, ...); */
  /*  m2c_error(msg_id, fmt, null_terminated_char, number, ...); */
  /*  */
  /*  Note that the character strings associated with %s in the format must */
  /*  be null-terminated character strings. */
  /*  */
  /*  Example usage: */
  /*     m2c_error('Error message in a constant string does not need to be null-terminated.'); */
  /*     m2c_error('Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*     m2c_error('error:ID', 'Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*  */
  /*  SEE ALSO: m2c_print, m2c_warn */
  /* 'm2c_error:18' coder.inline('never'); */
  /* 'm2c_error:20' if isempty(coder.target) */
  /* 'm2c_error:22' else */
  /* 'm2c_error:23' if isequal(coder.target, 'mex') */
  /* 'm2c_error:25' else */
  /* 'm2c_error:26' cmd = 'M2C_error'; */
  /* 'm2c_error:29' if nargin==1 || ischar(varargin{1}) && ~ischar(varargin{2}) */
  /* 'm2c_error:35' else */
  /* 'm2c_error:36' msgid = coder.opaque('const char *', ['"' varargin{1} '"']); */
  /* 'm2c_error:38' fmt = coder.opaque('const char *', ['"' varargin{2} '"']); */
  /* 'm2c_error:39' coder.ceval(cmd, msgid, fmt, varargin{3:end}); */
  M2C_error("petsc:RuntimeError", "MatSetValues returned error code %d\n",
            varargin_3);
}

/*
 * function m2c_printf(varargin)
 */
static void b_m2c_printf(double varargin_2, int varargin_3)
{
  /* m2c_printf Issue an informational message. */
  /*   */
  /*  m2c_printf(msg); */
  /*  m2c_printf(fmt, null_terminated_char, number, ...); */
  /*  */
  /*  Note that the character strings associated with %s in the format must */
  /*  be null-terminated character strings. */
  /*  */
  /*  Example usage: */
  /*     m2c_printf('Message in a constant string does not need to be null-terminated.'); */
  /*     m2c_printf('Msg ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*  */
  /*  SEE ALSO: m2c_error, m2c_warn */
  /* 'm2c_printf:17' coder.inline('never'); */
  /* 'm2c_printf:19' if isempty(coder.target) */
  /* 'm2c_printf:21' else */
  /* 'm2c_printf:22' if isequal(coder.target, 'mex') */
  /* 'm2c_printf:24' else */
  /* 'm2c_printf:25' cmd = 'M2C_printf'; */
  /* 'm2c_printf:27' assert(nargin>=1); */
  /* 'm2c_printf:28' fmt = coder.opaque('const char *', ['"' varargin{1} '"']); */
  /* 'm2c_printf:29' coder.ceval(cmd, fmt, varargin{2:end}); */
  M2C_printf("### The relative residual was %g after %d iterations.\n",
             varargin_2, varargin_3);
}

/*
 * function m2c_error(varargin)
 */
static void bb_m2c_error(int varargin_3)
{
  /* m2c_error Issue a fatal error message. */
  /*   */
  /*  m2c_error(msg); */
  /*  m2c_error(fmt, null_terminated_char, number, ...); */
  /*  m2c_error(msg_id, fmt, null_terminated_char, number, ...); */
  /*  */
  /*  Note that the character strings associated with %s in the format must */
  /*  be null-terminated character strings. */
  /*  */
  /*  Example usage: */
  /*     m2c_error('Error message in a constant string does not need to be null-terminated.'); */
  /*     m2c_error('Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*     m2c_error('error:ID', 'Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*  */
  /*  SEE ALSO: m2c_print, m2c_warn */
  /* 'm2c_error:18' coder.inline('never'); */
  /* 'm2c_error:20' if isempty(coder.target) */
  /* 'm2c_error:22' else */
  /* 'm2c_error:23' if isequal(coder.target, 'mex') */
  /* 'm2c_error:25' else */
  /* 'm2c_error:26' cmd = 'M2C_error'; */
  /* 'm2c_error:29' if nargin==1 || ischar(varargin{1}) && ~ischar(varargin{2}) */
  /* 'm2c_error:35' else */
  /* 'm2c_error:36' msgid = coder.opaque('const char *', ['"' varargin{1} '"']); */
  /* 'm2c_error:38' fmt = coder.opaque('const char *', ['"' varargin{2} '"']); */
  /* 'm2c_error:39' coder.ceval(cmd, msgid, fmt, varargin{3:end}); */
  M2C_error("petsc:RuntimeError", "MatDestroy returned error code %d\n",
            varargin_3);
}

/*
 * function m2c_error(varargin)
 */
static void c_m2c_error(int varargin_3)
{
  /* m2c_error Issue a fatal error message. */
  /*   */
  /*  m2c_error(msg); */
  /*  m2c_error(fmt, null_terminated_char, number, ...); */
  /*  m2c_error(msg_id, fmt, null_terminated_char, number, ...); */
  /*  */
  /*  Note that the character strings associated with %s in the format must */
  /*  be null-terminated character strings. */
  /*  */
  /*  Example usage: */
  /*     m2c_error('Error message in a constant string does not need to be null-terminated.'); */
  /*     m2c_error('Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*     m2c_error('error:ID', 'Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*  */
  /*  SEE ALSO: m2c_print, m2c_warn */
  /* 'm2c_error:18' coder.inline('never'); */
  /* 'm2c_error:20' if isempty(coder.target) */
  /* 'm2c_error:22' else */
  /* 'm2c_error:23' if isequal(coder.target, 'mex') */
  /* 'm2c_error:25' else */
  /* 'm2c_error:26' cmd = 'M2C_error'; */
  /* 'm2c_error:29' if nargin==1 || ischar(varargin{1}) && ~ischar(varargin{2}) */
  /* 'm2c_error:35' else */
  /* 'm2c_error:36' msgid = coder.opaque('const char *', ['"' varargin{1} '"']); */
  /* 'm2c_error:38' fmt = coder.opaque('const char *', ['"' varargin{2} '"']); */
  /* 'm2c_error:39' coder.ceval(cmd, msgid, fmt, varargin{3:end}); */
  M2C_error("petsc:RuntimeError", "MatAssemblyBegin returned error code %d\n",
            varargin_3);
}

/*
 * function m2c_printf(varargin)
 */
static void c_m2c_printf(double varargin_2, double varargin_3)
{
  /* m2c_printf Issue an informational message. */
  /*   */
  /*  m2c_printf(msg); */
  /*  m2c_printf(fmt, null_terminated_char, number, ...); */
  /*  */
  /*  Note that the character strings associated with %s in the format must */
  /*  be null-terminated character strings. */
  /*  */
  /*  Example usage: */
  /*     m2c_printf('Message in a constant string does not need to be null-terminated.'); */
  /*     m2c_printf('Msg ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*  */
  /*  SEE ALSO: m2c_error, m2c_warn */
  /* 'm2c_printf:17' coder.inline('never'); */
  /* 'm2c_printf:19' if isempty(coder.target) */
  /* 'm2c_printf:21' else */
  /* 'm2c_printf:22' if isequal(coder.target, 'mex') */
  /* 'm2c_printf:24' else */
  /* 'm2c_printf:25' cmd = 'M2C_printf'; */
  /* 'm2c_printf:27' assert(nargin>=1); */
  /* 'm2c_printf:28' fmt = coder.opaque('const char *', ['"' varargin{1} '"']); */
  /* 'm2c_printf:29' coder.ceval(cmd, fmt, varargin{2:end}); */
  M2C_printf("### The relative and absolute tolerances were %g and %g.\n",
             varargin_2, varargin_3);
}

/*
 * function m2c_error(varargin)
 */
static void cb_m2c_error(int varargin_3)
{
  /* m2c_error Issue a fatal error message. */
  /*   */
  /*  m2c_error(msg); */
  /*  m2c_error(fmt, null_terminated_char, number, ...); */
  /*  m2c_error(msg_id, fmt, null_terminated_char, number, ...); */
  /*  */
  /*  Note that the character strings associated with %s in the format must */
  /*  be null-terminated character strings. */
  /*  */
  /*  Example usage: */
  /*     m2c_error('Error message in a constant string does not need to be null-terminated.'); */
  /*     m2c_error('Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*     m2c_error('error:ID', 'Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*  */
  /*  SEE ALSO: m2c_print, m2c_warn */
  /* 'm2c_error:18' coder.inline('never'); */
  /* 'm2c_error:20' if isempty(coder.target) */
  /* 'm2c_error:22' else */
  /* 'm2c_error:23' if isequal(coder.target, 'mex') */
  /* 'm2c_error:25' else */
  /* 'm2c_error:26' cmd = 'M2C_error'; */
  /* 'm2c_error:29' if nargin==1 || ischar(varargin{1}) && ~ischar(varargin{2}) */
  /* 'm2c_error:35' else */
  /* 'm2c_error:36' msgid = coder.opaque('const char *', ['"' varargin{1} '"']); */
  /* 'm2c_error:38' fmt = coder.opaque('const char *', ['"' varargin{2} '"']); */
  /* 'm2c_error:39' coder.ceval(cmd, msgid, fmt, varargin{3:end}); */
  M2C_error("petsc:RuntimeError", "VecDestroy returned error code %d\n",
            varargin_3);
}

/*
 * function m2c_error(varargin)
 */
static void d_m2c_error(int varargin_3)
{
  /* m2c_error Issue a fatal error message. */
  /*   */
  /*  m2c_error(msg); */
  /*  m2c_error(fmt, null_terminated_char, number, ...); */
  /*  m2c_error(msg_id, fmt, null_terminated_char, number, ...); */
  /*  */
  /*  Note that the character strings associated with %s in the format must */
  /*  be null-terminated character strings. */
  /*  */
  /*  Example usage: */
  /*     m2c_error('Error message in a constant string does not need to be null-terminated.'); */
  /*     m2c_error('Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*     m2c_error('error:ID', 'Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*  */
  /*  SEE ALSO: m2c_print, m2c_warn */
  /* 'm2c_error:18' coder.inline('never'); */
  /* 'm2c_error:20' if isempty(coder.target) */
  /* 'm2c_error:22' else */
  /* 'm2c_error:23' if isequal(coder.target, 'mex') */
  /* 'm2c_error:25' else */
  /* 'm2c_error:26' cmd = 'M2C_error'; */
  /* 'm2c_error:29' if nargin==1 || ischar(varargin{1}) && ~ischar(varargin{2}) */
  /* 'm2c_error:35' else */
  /* 'm2c_error:36' msgid = coder.opaque('const char *', ['"' varargin{1} '"']); */
  /* 'm2c_error:38' fmt = coder.opaque('const char *', ['"' varargin{2} '"']); */
  /* 'm2c_error:39' coder.ceval(cmd, msgid, fmt, varargin{3:end}); */
  M2C_error("petsc:RuntimeError", "MatAssemblyEnd returned error code %d\n",
            varargin_3);
}

/*
 * function m2c_printf(varargin)
 */
static void d_m2c_printf(int varargin_2, double varargin_3)
{
  /* m2c_printf Issue an informational message. */
  /*   */
  /*  m2c_printf(msg); */
  /*  m2c_printf(fmt, null_terminated_char, number, ...); */
  /*  */
  /*  Note that the character strings associated with %s in the format must */
  /*  be null-terminated character strings. */
  /*  */
  /*  Example usage: */
  /*     m2c_printf('Message in a constant string does not need to be null-terminated.'); */
  /*     m2c_printf('Msg ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*  */
  /*  SEE ALSO: m2c_error, m2c_warn */
  /* 'm2c_printf:17' coder.inline('never'); */
  /* 'm2c_printf:19' if isempty(coder.target) */
  /* 'm2c_printf:21' else */
  /* 'm2c_printf:22' if isequal(coder.target, 'mex') */
  /* 'm2c_printf:24' else */
  /* 'm2c_printf:25' cmd = 'M2C_printf'; */
  /* 'm2c_printf:27' assert(nargin>=1); */
  /* 'm2c_printf:28' fmt = coder.opaque('const char *', ['"' varargin{1} '"']); */
  /* 'm2c_printf:29' coder.ceval(cmd, fmt, varargin{2:end}); */
  M2C_printf("### The divergence and max-iter tolerances were %d and %g.\n",
             varargin_2, varargin_3);
}

/*
 * function m2c_error(varargin)
 */
static void db_m2c_error(int varargin_3)
{
  /* m2c_error Issue a fatal error message. */
  /*   */
  /*  m2c_error(msg); */
  /*  m2c_error(fmt, null_terminated_char, number, ...); */
  /*  m2c_error(msg_id, fmt, null_terminated_char, number, ...); */
  /*  */
  /*  Note that the character strings associated with %s in the format must */
  /*  be null-terminated character strings. */
  /*  */
  /*  Example usage: */
  /*     m2c_error('Error message in a constant string does not need to be null-terminated.'); */
  /*     m2c_error('Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*     m2c_error('error:ID', 'Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*  */
  /*  SEE ALSO: m2c_print, m2c_warn */
  /* 'm2c_error:18' coder.inline('never'); */
  /* 'm2c_error:20' if isempty(coder.target) */
  /* 'm2c_error:22' else */
  /* 'm2c_error:23' if isequal(coder.target, 'mex') */
  /* 'm2c_error:25' else */
  /* 'm2c_error:26' cmd = 'M2C_error'; */
  /* 'm2c_error:29' if nargin==1 || ischar(varargin{1}) && ~ischar(varargin{2}) */
  /* 'm2c_error:35' else */
  /* 'm2c_error:36' msgid = coder.opaque('const char *', ['"' varargin{1} '"']); */
  /* 'm2c_error:38' fmt = coder.opaque('const char *', ['"' varargin{2} '"']); */
  /* 'm2c_error:39' coder.ceval(cmd, msgid, fmt, varargin{3:end}); */
  M2C_error("petsc:RuntimeError", "VecGetLocalSize returned error code %d\n",
            varargin_3);
}

/*
 * function m2c_error(varargin)
 */
static void e_m2c_error(int varargin_3)
{
  /* m2c_error Issue a fatal error message. */
  /*   */
  /*  m2c_error(msg); */
  /*  m2c_error(fmt, null_terminated_char, number, ...); */
  /*  m2c_error(msg_id, fmt, null_terminated_char, number, ...); */
  /*  */
  /*  Note that the character strings associated with %s in the format must */
  /*  be null-terminated character strings. */
  /*  */
  /*  Example usage: */
  /*     m2c_error('Error message in a constant string does not need to be null-terminated.'); */
  /*     m2c_error('Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*     m2c_error('error:ID', 'Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*  */
  /*  SEE ALSO: m2c_print, m2c_warn */
  /* 'm2c_error:18' coder.inline('never'); */
  /* 'm2c_error:20' if isempty(coder.target) */
  /* 'm2c_error:22' else */
  /* 'm2c_error:23' if isequal(coder.target, 'mex') */
  /* 'm2c_error:25' else */
  /* 'm2c_error:26' cmd = 'M2C_error'; */
  /* 'm2c_error:29' if nargin==1 || ischar(varargin{1}) && ~ischar(varargin{2}) */
  /* 'm2c_error:35' else */
  /* 'm2c_error:36' msgid = coder.opaque('const char *', ['"' varargin{1} '"']); */
  /* 'm2c_error:38' fmt = coder.opaque('const char *', ['"' varargin{2} '"']); */
  /* 'm2c_error:39' coder.ceval(cmd, msgid, fmt, varargin{3:end}); */
  M2C_error("petsc:RuntimeError", "VecCreateSeq returned error code %d\n",
            varargin_3);
}

/*
 * function m2c_printf(varargin)
 */
static void e_m2c_printf(void)
{
  /* m2c_printf Issue an informational message. */
  /*   */
  /*  m2c_printf(msg); */
  /*  m2c_printf(fmt, null_terminated_char, number, ...); */
  /*  */
  /*  Note that the character strings associated with %s in the format must */
  /*  be null-terminated character strings. */
  /*  */
  /*  Example usage: */
  /*     m2c_printf('Message in a constant string does not need to be null-terminated.'); */
  /*     m2c_printf('Msg ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*  */
  /*  SEE ALSO: m2c_error, m2c_warn */
  /* 'm2c_printf:17' coder.inline('never'); */
  /* 'm2c_printf:19' if isempty(coder.target) */
  /* 'm2c_printf:21' else */
  /* 'm2c_printf:22' if isequal(coder.target, 'mex') */
  /* 'm2c_printf:24' else */
  /* 'm2c_printf:25' cmd = 'M2C_printf'; */
  /* 'm2c_printf:27' assert(nargin>=1); */
  /* 'm2c_printf:28' fmt = coder.opaque('const char *', ['"' varargin{1} '"']); */
  /* 'm2c_printf:29' coder.ceval(cmd, fmt, varargin{2:end}); */
  M2C_printf("### For explanation of the flag, see http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPConvergedReason.html.\n");
}

/*
 * function m2c_error(varargin)
 */
static void eb_m2c_error(void)
{
  /* m2c_error Issue a fatal error message. */
  /*   */
  /*  m2c_error(msg); */
  /*  m2c_error(fmt, null_terminated_char, number, ...); */
  /*  m2c_error(msg_id, fmt, null_terminated_char, number, ...); */
  /*  */
  /*  Note that the character strings associated with %s in the format must */
  /*  be null-terminated character strings. */
  /*  */
  /*  Example usage: */
  /*     m2c_error('Error message in a constant string does not need to be null-terminated.'); */
  /*     m2c_error('Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*     m2c_error('error:ID', 'Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*  */
  /*  SEE ALSO: m2c_print, m2c_warn */
  /* 'm2c_error:18' coder.inline('never'); */
  /* 'm2c_error:20' if isempty(coder.target) */
  /* 'm2c_error:22' else */
  /* 'm2c_error:23' if isequal(coder.target, 'mex') */
  /* 'm2c_error:25' else */
  /* 'm2c_error:26' cmd = 'M2C_error'; */
  /* 'm2c_error:29' if nargin==1 || ischar(varargin{1}) && ~ischar(varargin{2}) */
  /* 'm2c_error:30' fmt = coder.opaque('const char *', ['"' varargin{1} '"']); */
  /* 'm2c_error:32' coder.ceval(cmd, ... */
  /* 'm2c_error:33'                     coder.opaque('const char *', '"runtime:Error"'), ... */
  /* 'm2c_error:34'                     fmt, varargin{2:end}); */
  M2C_error("runtime:Error", "Output array y is too small.");
}

static void emxInit_int32_T1(emxArray_int32_T **pEmxArray, int numDimensions)
{
  emxArray_int32_T *emxArray;
  int i;
  *pEmxArray = (emxArray_int32_T *)malloc(sizeof(emxArray_int32_T));
  emxArray = *pEmxArray;
  emxArray->data = (int *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc((unsigned int)(sizeof(int) * numDimensions));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * function m2c_error(varargin)
 */
static void f_m2c_error(int varargin_3)
{
  /* m2c_error Issue a fatal error message. */
  /*   */
  /*  m2c_error(msg); */
  /*  m2c_error(fmt, null_terminated_char, number, ...); */
  /*  m2c_error(msg_id, fmt, null_terminated_char, number, ...); */
  /*  */
  /*  Note that the character strings associated with %s in the format must */
  /*  be null-terminated character strings. */
  /*  */
  /*  Example usage: */
  /*     m2c_error('Error message in a constant string does not need to be null-terminated.'); */
  /*     m2c_error('Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*     m2c_error('error:ID', 'Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*  */
  /*  SEE ALSO: m2c_print, m2c_warn */
  /* 'm2c_error:18' coder.inline('never'); */
  /* 'm2c_error:20' if isempty(coder.target) */
  /* 'm2c_error:22' else */
  /* 'm2c_error:23' if isequal(coder.target, 'mex') */
  /* 'm2c_error:25' else */
  /* 'm2c_error:26' cmd = 'M2C_error'; */
  /* 'm2c_error:29' if nargin==1 || ischar(varargin{1}) && ~ischar(varargin{2}) */
  /* 'm2c_error:35' else */
  /* 'm2c_error:36' msgid = coder.opaque('const char *', ['"' varargin{1} '"']); */
  /* 'm2c_error:38' fmt = coder.opaque('const char *', ['"' varargin{2} '"']); */
  /* 'm2c_error:39' coder.ceval(cmd, msgid, fmt, varargin{3:end}); */
  M2C_error("petsc:RuntimeError", "VecSetValues returned error code %d\n",
            varargin_3);
}

/*
 * function m2c_error(varargin)
 */
static void fb_m2c_error(int varargin_3)
{
  /* m2c_error Issue a fatal error message. */
  /*   */
  /*  m2c_error(msg); */
  /*  m2c_error(fmt, null_terminated_char, number, ...); */
  /*  m2c_error(msg_id, fmt, null_terminated_char, number, ...); */
  /*  */
  /*  Note that the character strings associated with %s in the format must */
  /*  be null-terminated character strings. */
  /*  */
  /*  Example usage: */
  /*     m2c_error('Error message in a constant string does not need to be null-terminated.'); */
  /*     m2c_error('Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*     m2c_error('error:ID', 'Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*  */
  /*  SEE ALSO: m2c_print, m2c_warn */
  /* 'm2c_error:18' coder.inline('never'); */
  /* 'm2c_error:20' if isempty(coder.target) */
  /* 'm2c_error:22' else */
  /* 'm2c_error:23' if isequal(coder.target, 'mex') */
  /* 'm2c_error:25' else */
  /* 'm2c_error:26' cmd = 'M2C_error'; */
  /* 'm2c_error:29' if nargin==1 || ischar(varargin{1}) && ~ischar(varargin{2}) */
  /* 'm2c_error:35' else */
  /* 'm2c_error:36' msgid = coder.opaque('const char *', ['"' varargin{1} '"']); */
  /* 'm2c_error:38' fmt = coder.opaque('const char *', ['"' varargin{2} '"']); */
  /* 'm2c_error:39' coder.ceval(cmd, msgid, fmt, varargin{3:end}); */
  M2C_error("petsc:RuntimeError", "VecGetValues returned error code %d\n",
            varargin_3);
}

/*
 * function m2c_error(varargin)
 */
static void g_m2c_error(int varargin_3)
{
  /* m2c_error Issue a fatal error message. */
  /*   */
  /*  m2c_error(msg); */
  /*  m2c_error(fmt, null_terminated_char, number, ...); */
  /*  m2c_error(msg_id, fmt, null_terminated_char, number, ...); */
  /*  */
  /*  Note that the character strings associated with %s in the format must */
  /*  be null-terminated character strings. */
  /*  */
  /*  Example usage: */
  /*     m2c_error('Error message in a constant string does not need to be null-terminated.'); */
  /*     m2c_error('Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*     m2c_error('error:ID', 'Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*  */
  /*  SEE ALSO: m2c_print, m2c_warn */
  /* 'm2c_error:18' coder.inline('never'); */
  /* 'm2c_error:20' if isempty(coder.target) */
  /* 'm2c_error:22' else */
  /* 'm2c_error:23' if isequal(coder.target, 'mex') */
  /* 'm2c_error:25' else */
  /* 'm2c_error:26' cmd = 'M2C_error'; */
  /* 'm2c_error:29' if nargin==1 || ischar(varargin{1}) && ~ischar(varargin{2}) */
  /* 'm2c_error:35' else */
  /* 'm2c_error:36' msgid = coder.opaque('const char *', ['"' varargin{1} '"']); */
  /* 'm2c_error:38' fmt = coder.opaque('const char *', ['"' varargin{2} '"']); */
  /* 'm2c_error:39' coder.ceval(cmd, msgid, fmt, varargin{3:end}); */
  M2C_error("petsc:RuntimeError", "VecAssemblyBegin returned error code %d\n",
            varargin_3);
}

/*
 * function m2c_error(varargin)
 */
static void gb_m2c_error(int varargin_3)
{
  /* m2c_error Issue a fatal error message. */
  /*   */
  /*  m2c_error(msg); */
  /*  m2c_error(fmt, null_terminated_char, number, ...); */
  /*  m2c_error(msg_id, fmt, null_terminated_char, number, ...); */
  /*  */
  /*  Note that the character strings associated with %s in the format must */
  /*  be null-terminated character strings. */
  /*  */
  /*  Example usage: */
  /*     m2c_error('Error message in a constant string does not need to be null-terminated.'); */
  /*     m2c_error('Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*     m2c_error('error:ID', 'Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*  */
  /*  SEE ALSO: m2c_print, m2c_warn */
  /* 'm2c_error:18' coder.inline('never'); */
  /* 'm2c_error:20' if isempty(coder.target) */
  /* 'm2c_error:22' else */
  /* 'm2c_error:23' if isequal(coder.target, 'mex') */
  /* 'm2c_error:25' else */
  /* 'm2c_error:26' cmd = 'M2C_error'; */
  /* 'm2c_error:29' if nargin==1 || ischar(varargin{1}) && ~ischar(varargin{2}) */
  /* 'm2c_error:35' else */
  /* 'm2c_error:36' msgid = coder.opaque('const char *', ['"' varargin{1} '"']); */
  /* 'm2c_error:38' fmt = coder.opaque('const char *', ['"' varargin{2} '"']); */
  /* 'm2c_error:39' coder.ceval(cmd, msgid, fmt, varargin{3:end}); */
  M2C_error("petsc:RuntimeError", "KSPSetType returned error code %d\n",
            varargin_3);
}

/*
 * function m2c_error(varargin)
 */
static void h_m2c_error(int varargin_3)
{
  /* m2c_error Issue a fatal error message. */
  /*   */
  /*  m2c_error(msg); */
  /*  m2c_error(fmt, null_terminated_char, number, ...); */
  /*  m2c_error(msg_id, fmt, null_terminated_char, number, ...); */
  /*  */
  /*  Note that the character strings associated with %s in the format must */
  /*  be null-terminated character strings. */
  /*  */
  /*  Example usage: */
  /*     m2c_error('Error message in a constant string does not need to be null-terminated.'); */
  /*     m2c_error('Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*     m2c_error('error:ID', 'Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*  */
  /*  SEE ALSO: m2c_print, m2c_warn */
  /* 'm2c_error:18' coder.inline('never'); */
  /* 'm2c_error:20' if isempty(coder.target) */
  /* 'm2c_error:22' else */
  /* 'm2c_error:23' if isequal(coder.target, 'mex') */
  /* 'm2c_error:25' else */
  /* 'm2c_error:26' cmd = 'M2C_error'; */
  /* 'm2c_error:29' if nargin==1 || ischar(varargin{1}) && ~ischar(varargin{2}) */
  /* 'm2c_error:35' else */
  /* 'm2c_error:36' msgid = coder.opaque('const char *', ['"' varargin{1} '"']); */
  /* 'm2c_error:38' fmt = coder.opaque('const char *', ['"' varargin{2} '"']); */
  /* 'm2c_error:39' coder.ceval(cmd, msgid, fmt, varargin{3:end}); */
  M2C_error("petsc:RuntimeError", "VecAssemblyEnd returned error code %d\n",
            varargin_3);
}

/*
 * function m2c_error(varargin)
 */
static void hb_m2c_error(int varargin_3)
{
  /* m2c_error Issue a fatal error message. */
  /*   */
  /*  m2c_error(msg); */
  /*  m2c_error(fmt, null_terminated_char, number, ...); */
  /*  m2c_error(msg_id, fmt, null_terminated_char, number, ...); */
  /*  */
  /*  Note that the character strings associated with %s in the format must */
  /*  be null-terminated character strings. */
  /*  */
  /*  Example usage: */
  /*     m2c_error('Error message in a constant string does not need to be null-terminated.'); */
  /*     m2c_error('Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*     m2c_error('error:ID', 'Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*  */
  /*  SEE ALSO: m2c_print, m2c_warn */
  /* 'm2c_error:18' coder.inline('never'); */
  /* 'm2c_error:20' if isempty(coder.target) */
  /* 'm2c_error:22' else */
  /* 'm2c_error:23' if isequal(coder.target, 'mex') */
  /* 'm2c_error:25' else */
  /* 'm2c_error:26' cmd = 'M2C_error'; */
  /* 'm2c_error:29' if nargin==1 || ischar(varargin{1}) && ~ischar(varargin{2}) */
  /* 'm2c_error:35' else */
  /* 'm2c_error:36' msgid = coder.opaque('const char *', ['"' varargin{1} '"']); */
  /* 'm2c_error:38' fmt = coder.opaque('const char *', ['"' varargin{2} '"']); */
  /* 'm2c_error:39' coder.ceval(cmd, msgid, fmt, varargin{3:end}); */
  M2C_error("petsc:RuntimeError", "PCSetType returned error code %d\n",
            varargin_3);
}

/*
 * function m2c_error(varargin)
 */
static void i_m2c_error(int varargin_3)
{
  /* m2c_error Issue a fatal error message. */
  /*   */
  /*  m2c_error(msg); */
  /*  m2c_error(fmt, null_terminated_char, number, ...); */
  /*  m2c_error(msg_id, fmt, null_terminated_char, number, ...); */
  /*  */
  /*  Note that the character strings associated with %s in the format must */
  /*  be null-terminated character strings. */
  /*  */
  /*  Example usage: */
  /*     m2c_error('Error message in a constant string does not need to be null-terminated.'); */
  /*     m2c_error('Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*     m2c_error('error:ID', 'Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*  */
  /*  SEE ALSO: m2c_print, m2c_warn */
  /* 'm2c_error:18' coder.inline('never'); */
  /* 'm2c_error:20' if isempty(coder.target) */
  /* 'm2c_error:22' else */
  /* 'm2c_error:23' if isequal(coder.target, 'mex') */
  /* 'm2c_error:25' else */
  /* 'm2c_error:26' cmd = 'M2C_error'; */
  /* 'm2c_error:29' if nargin==1 || ischar(varargin{1}) && ~ischar(varargin{2}) */
  /* 'm2c_error:35' else */
  /* 'm2c_error:36' msgid = coder.opaque('const char *', ['"' varargin{1} '"']); */
  /* 'm2c_error:38' fmt = coder.opaque('const char *', ['"' varargin{2} '"']); */
  /* 'm2c_error:39' coder.ceval(cmd, msgid, fmt, varargin{3:end}); */
  M2C_error("petsc:RuntimeError", "VecDuplicate returned error code %d\n",
            varargin_3);
}

/*
 * function m2c_error(varargin)
 */
static void ib_m2c_error(int varargin_3)
{
  /* m2c_error Issue a fatal error message. */
  /*   */
  /*  m2c_error(msg); */
  /*  m2c_error(fmt, null_terminated_char, number, ...); */
  /*  m2c_error(msg_id, fmt, null_terminated_char, number, ...); */
  /*  */
  /*  Note that the character strings associated with %s in the format must */
  /*  be null-terminated character strings. */
  /*  */
  /*  Example usage: */
  /*     m2c_error('Error message in a constant string does not need to be null-terminated.'); */
  /*     m2c_error('Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*     m2c_error('error:ID', 'Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*  */
  /*  SEE ALSO: m2c_print, m2c_warn */
  /* 'm2c_error:18' coder.inline('never'); */
  /* 'm2c_error:20' if isempty(coder.target) */
  /* 'm2c_error:22' else */
  /* 'm2c_error:23' if isequal(coder.target, 'mex') */
  /* 'm2c_error:25' else */
  /* 'm2c_error:26' cmd = 'M2C_error'; */
  /* 'm2c_error:29' if nargin==1 || ischar(varargin{1}) && ~ischar(varargin{2}) */
  /* 'm2c_error:35' else */
  /* 'm2c_error:36' msgid = coder.opaque('const char *', ['"' varargin{1} '"']); */
  /* 'm2c_error:38' fmt = coder.opaque('const char *', ['"' varargin{2} '"']); */
  /* 'm2c_error:39' coder.ceval(cmd, msgid, fmt, varargin{3:end}); */
  M2C_error("petsc:RuntimeError",
            "petscPCFactorSetMatSolverPackage returned error code %d\n",
            varargin_3);
}

/*
 * function m2c_error(varargin)
 */
static void j_m2c_error(int varargin_3)
{
  /* m2c_error Issue a fatal error message. */
  /*   */
  /*  m2c_error(msg); */
  /*  m2c_error(fmt, null_terminated_char, number, ...); */
  /*  m2c_error(msg_id, fmt, null_terminated_char, number, ...); */
  /*  */
  /*  Note that the character strings associated with %s in the format must */
  /*  be null-terminated character strings. */
  /*  */
  /*  Example usage: */
  /*     m2c_error('Error message in a constant string does not need to be null-terminated.'); */
  /*     m2c_error('Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*     m2c_error('error:ID', 'Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*  */
  /*  SEE ALSO: m2c_print, m2c_warn */
  /* 'm2c_error:18' coder.inline('never'); */
  /* 'm2c_error:20' if isempty(coder.target) */
  /* 'm2c_error:22' else */
  /* 'm2c_error:23' if isequal(coder.target, 'mex') */
  /* 'm2c_error:25' else */
  /* 'm2c_error:26' cmd = 'M2C_error'; */
  /* 'm2c_error:29' if nargin==1 || ischar(varargin{1}) && ~ischar(varargin{2}) */
  /* 'm2c_error:35' else */
  /* 'm2c_error:36' msgid = coder.opaque('const char *', ['"' varargin{1} '"']); */
  /* 'm2c_error:38' fmt = coder.opaque('const char *', ['"' varargin{2} '"']); */
  /* 'm2c_error:39' coder.ceval(cmd, msgid, fmt, varargin{3:end}); */
  M2C_error("petsc:RuntimeError", "PetscObjectGetComm returned error code %d\n",
            varargin_3);
}

/*
 * function m2c_error(varargin)
 */
static void jb_m2c_error(void)
{
  /* m2c_error Issue a fatal error message. */
  /*   */
  /*  m2c_error(msg); */
  /*  m2c_error(fmt, null_terminated_char, number, ...); */
  /*  m2c_error(msg_id, fmt, null_terminated_char, number, ...); */
  /*  */
  /*  Note that the character strings associated with %s in the format must */
  /*  be null-terminated character strings. */
  /*  */
  /*  Example usage: */
  /*     m2c_error('Error message in a constant string does not need to be null-terminated.'); */
  /*     m2c_error('Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*     m2c_error('error:ID', 'Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*  */
  /*  SEE ALSO: m2c_print, m2c_warn */
  /* 'm2c_error:18' coder.inline('never'); */
  /* 'm2c_error:20' if isempty(coder.target) */
  /* 'm2c_error:22' else */
  /* 'm2c_error:23' if isequal(coder.target, 'mex') */
  /* 'm2c_error:25' else */
  /* 'm2c_error:26' cmd = 'M2C_error'; */
  /* 'm2c_error:29' if nargin==1 || ischar(varargin{1}) && ~ischar(varargin{2}) */
  /* 'm2c_error:35' else */
  /* 'm2c_error:36' msgid = coder.opaque('const char *', ['"' varargin{1} '"']); */
  /* 'm2c_error:38' fmt = coder.opaque('const char *', ['"' varargin{2} '"']); */
  /* 'm2c_error:39' coder.ceval(cmd, msgid, fmt, varargin{3:end}); */
  M2C_error("MPETSc:petscOptionsInsertString:InputError",
            "The argument must be a null-terminated string.");
}

/*
 * function m2c_error(varargin)
 */
static void k_m2c_error(int varargin_3)
{
  /* m2c_error Issue a fatal error message. */
  /*   */
  /*  m2c_error(msg); */
  /*  m2c_error(fmt, null_terminated_char, number, ...); */
  /*  m2c_error(msg_id, fmt, null_terminated_char, number, ...); */
  /*  */
  /*  Note that the character strings associated with %s in the format must */
  /*  be null-terminated character strings. */
  /*  */
  /*  Example usage: */
  /*     m2c_error('Error message in a constant string does not need to be null-terminated.'); */
  /*     m2c_error('Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*     m2c_error('error:ID', 'Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*  */
  /*  SEE ALSO: m2c_print, m2c_warn */
  /* 'm2c_error:18' coder.inline('never'); */
  /* 'm2c_error:20' if isempty(coder.target) */
  /* 'm2c_error:22' else */
  /* 'm2c_error:23' if isequal(coder.target, 'mex') */
  /* 'm2c_error:25' else */
  /* 'm2c_error:26' cmd = 'M2C_error'; */
  /* 'm2c_error:29' if nargin==1 || ischar(varargin{1}) && ~ischar(varargin{2}) */
  /* 'm2c_error:35' else */
  /* 'm2c_error:36' msgid = coder.opaque('const char *', ['"' varargin{1} '"']); */
  /* 'm2c_error:38' fmt = coder.opaque('const char *', ['"' varargin{2} '"']); */
  /* 'm2c_error:39' coder.ceval(cmd, msgid, fmt, varargin{3:end}); */
  M2C_error("petsc:RuntimeError", "KSPCreate returned error code %d\n",
            varargin_3);
}

/*
 * function m2c_error(varargin)
 */
static void kb_m2c_error(int varargin_3)
{
  /* m2c_error Issue a fatal error message. */
  /*   */
  /*  m2c_error(msg); */
  /*  m2c_error(fmt, null_terminated_char, number, ...); */
  /*  m2c_error(msg_id, fmt, null_terminated_char, number, ...); */
  /*  */
  /*  Note that the character strings associated with %s in the format must */
  /*  be null-terminated character strings. */
  /*  */
  /*  Example usage: */
  /*     m2c_error('Error message in a constant string does not need to be null-terminated.'); */
  /*     m2c_error('Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*     m2c_error('error:ID', 'Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*  */
  /*  SEE ALSO: m2c_print, m2c_warn */
  /* 'm2c_error:18' coder.inline('never'); */
  /* 'm2c_error:20' if isempty(coder.target) */
  /* 'm2c_error:22' else */
  /* 'm2c_error:23' if isequal(coder.target, 'mex') */
  /* 'm2c_error:25' else */
  /* 'm2c_error:26' cmd = 'M2C_error'; */
  /* 'm2c_error:29' if nargin==1 || ischar(varargin{1}) && ~ischar(varargin{2}) */
  /* 'm2c_error:35' else */
  /* 'm2c_error:36' msgid = coder.opaque('const char *', ['"' varargin{1} '"']); */
  /* 'm2c_error:38' fmt = coder.opaque('const char *', ['"' varargin{2} '"']); */
  /* 'm2c_error:39' coder.ceval(cmd, msgid, fmt, varargin{3:end}); */
  M2C_error("petsc:RuntimeError",
            "PetscOptionsInsertString returned error code %d\n", varargin_3);
}

/*
 * function m2c_error(varargin)
 */
static void l_m2c_error(int varargin_3)
{
  /* m2c_error Issue a fatal error message. */
  /*   */
  /*  m2c_error(msg); */
  /*  m2c_error(fmt, null_terminated_char, number, ...); */
  /*  m2c_error(msg_id, fmt, null_terminated_char, number, ...); */
  /*  */
  /*  Note that the character strings associated with %s in the format must */
  /*  be null-terminated character strings. */
  /*  */
  /*  Example usage: */
  /*     m2c_error('Error message in a constant string does not need to be null-terminated.'); */
  /*     m2c_error('Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*     m2c_error('error:ID', 'Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*  */
  /*  SEE ALSO: m2c_print, m2c_warn */
  /* 'm2c_error:18' coder.inline('never'); */
  /* 'm2c_error:20' if isempty(coder.target) */
  /* 'm2c_error:22' else */
  /* 'm2c_error:23' if isequal(coder.target, 'mex') */
  /* 'm2c_error:25' else */
  /* 'm2c_error:26' cmd = 'M2C_error'; */
  /* 'm2c_error:29' if nargin==1 || ischar(varargin{1}) && ~ischar(varargin{2}) */
  /* 'm2c_error:35' else */
  /* 'm2c_error:36' msgid = coder.opaque('const char *', ['"' varargin{1} '"']); */
  /* 'm2c_error:38' fmt = coder.opaque('const char *', ['"' varargin{2} '"']); */
  /* 'm2c_error:39' coder.ceval(cmd, msgid, fmt, varargin{3:end}); */
  M2C_error("petsc:RuntimeError", "KSPSetOperators returned error code %d\n",
            varargin_3);
}

/*
 * function m2c_error(varargin)
 */
static void m2c_error(int varargin_3)
{
  /* m2c_error Issue a fatal error message. */
  /*   */
  /*  m2c_error(msg); */
  /*  m2c_error(fmt, null_terminated_char, number, ...); */
  /*  m2c_error(msg_id, fmt, null_terminated_char, number, ...); */
  /*  */
  /*  Note that the character strings associated with %s in the format must */
  /*  be null-terminated character strings. */
  /*  */
  /*  Example usage: */
  /*     m2c_error('Error message in a constant string does not need to be null-terminated.'); */
  /*     m2c_error('Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*     m2c_error('error:ID', 'Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*  */
  /*  SEE ALSO: m2c_print, m2c_warn */
  /* 'm2c_error:18' coder.inline('never'); */
  /* 'm2c_error:20' if isempty(coder.target) */
  /* 'm2c_error:22' else */
  /* 'm2c_error:23' if isequal(coder.target, 'mex') */
  /* 'm2c_error:25' else */
  /* 'm2c_error:26' cmd = 'M2C_error'; */
  /* 'm2c_error:29' if nargin==1 || ischar(varargin{1}) && ~ischar(varargin{2}) */
  /* 'm2c_error:35' else */
  /* 'm2c_error:36' msgid = coder.opaque('const char *', ['"' varargin{1} '"']); */
  /* 'm2c_error:38' fmt = coder.opaque('const char *', ['"' varargin{2} '"']); */
  /* 'm2c_error:39' coder.ceval(cmd, msgid, fmt, varargin{3:end}); */
  M2C_error("petsc:RuntimeError", "MatCreateSeqAIJ returned error code %d\n",
            varargin_3);
}

/*
 * function m2c_printf(varargin)
 */
static void m2c_printf(KSPType varargin_2, PCType varargin_3, int varargin_4)
{
  /* m2c_printf Issue an informational message. */
  /*   */
  /*  m2c_printf(msg); */
  /*  m2c_printf(fmt, null_terminated_char, number, ...); */
  /*  */
  /*  Note that the character strings associated with %s in the format must */
  /*  be null-terminated character strings. */
  /*  */
  /*  Example usage: */
  /*     m2c_printf('Message in a constant string does not need to be null-terminated.'); */
  /*     m2c_printf('Msg ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*  */
  /*  SEE ALSO: m2c_error, m2c_warn */
  /* 'm2c_printf:17' coder.inline('never'); */
  /* 'm2c_printf:19' if isempty(coder.target) */
  /* 'm2c_printf:21' else */
  /* 'm2c_printf:22' if isequal(coder.target, 'mex') */
  /* 'm2c_printf:24' else */
  /* 'm2c_printf:25' cmd = 'M2C_printf'; */
  /* 'm2c_printf:27' assert(nargin>=1); */
  /* 'm2c_printf:28' fmt = coder.opaque('const char *', ['"' varargin{1} '"']); */
  /* 'm2c_printf:29' coder.ceval(cmd, fmt, varargin{2:end}); */
  M2C_printf("### %s with %s preconditioner stopped with flag %d.\n", varargin_2,
             varargin_3, varargin_4);
}

/*
 * function m2c_error(varargin)
 */
static void m_m2c_error(int varargin_3)
{
  /* m2c_error Issue a fatal error message. */
  /*   */
  /*  m2c_error(msg); */
  /*  m2c_error(fmt, null_terminated_char, number, ...); */
  /*  m2c_error(msg_id, fmt, null_terminated_char, number, ...); */
  /*  */
  /*  Note that the character strings associated with %s in the format must */
  /*  be null-terminated character strings. */
  /*  */
  /*  Example usage: */
  /*     m2c_error('Error message in a constant string does not need to be null-terminated.'); */
  /*     m2c_error('Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*     m2c_error('error:ID', 'Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*  */
  /*  SEE ALSO: m2c_print, m2c_warn */
  /* 'm2c_error:18' coder.inline('never'); */
  /* 'm2c_error:20' if isempty(coder.target) */
  /* 'm2c_error:22' else */
  /* 'm2c_error:23' if isequal(coder.target, 'mex') */
  /* 'm2c_error:25' else */
  /* 'm2c_error:26' cmd = 'M2C_error'; */
  /* 'm2c_error:29' if nargin==1 || ischar(varargin{1}) && ~ischar(varargin{2}) */
  /* 'm2c_error:35' else */
  /* 'm2c_error:36' msgid = coder.opaque('const char *', ['"' varargin{1} '"']); */
  /* 'm2c_error:38' fmt = coder.opaque('const char *', ['"' varargin{2} '"']); */
  /* 'm2c_error:39' coder.ceval(cmd, msgid, fmt, varargin{3:end}); */
  M2C_error("petsc:RuntimeError", "KSPSetFromOptions returned error code %d\n",
            varargin_3);
}

/*
 * function [ksp, time, toplevel] = mptKSPSetup(Amat, ksptype, pctype, solpack)
 */
static void mptKSPSetup(Mat Amat, const emxArray_char_T *ksptype, const
  emxArray_char_T *pctype, const emxArray_char_T *solpack, KSP *ksp, double
  *time)
{
  PetscObject t_obj;
  MPI_Comm t_comm;
  int errCode;
  int flag;
  KSP t_ksp;
  double t;
  boolean_T b1;
  boolean_T b2;
  emxArray_char_T *pctype0;
  int loop_ub;
  PC t_pc;
  double b_t;

  /*  Sets up KSP using the given matrix (matrices). */
  /*  */
  /*  Syntax: */
  /*   ksp = mptKSPSetup(A) */
  /*   ksp = mptKSPSetup(A, ksptype) */
  /*   ksp = mptKSPSetup(A, ksptype, pctype) */
  /*   ksp = mptKSPSetup(A, ksptype, pctype, solpack) */
  /*  */
  /*  Description: */
  /*   ksp = mptKSPSetup(A) sets up a KSP using matrix A. */
  /*  */
  /*   ksp = mptKSPSetup(A, ksptype) uses the specified type of the KSP. */
  /*  */
  /*   ksp = mptKSPSetup(A, ksptype, pctype) also sets the type of the KSP */
  /*     and the preconditioner. Note that pctype can be NULL. */
  /*  */
  /*   ksp = mptKSPSetup(A, ksptype, pctype, solpack) configures the KSP */
  /*     solver using the specified solver package. It is useful only when */
  /*     pctype is PCLU, PCILU, or PCICC. */
  /*  */
  /*  See Also: mptKSPSolve, mptKSPCleanup */
  /* 'mptKSPSetup:29' t_Amat = Amat; */
  /* 'mptKSPSetup:30' t_ksp = petscKSPCreate(petscObjectGetComm(t_Amat)); */
  /* Gets the MPI communicator for any PetscObject, regardless of the type.  */
  /*  */
  /*   [comm, errCode] = petscObjectGetComm(obj) */
  /*  */
  /*   obtains the MPI_Comm associated with the PetscObject. */
  /*  */
  /*   SEE ALSO: petscMatSetType, petscMatSetFromOptions */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode  PetscObjectGetComm(PetscObject obj,MPI_Comm *comm) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Sys/PetscObjectGetComm.html */
  /* 'petscObjectGetComm:16' errCode = int32(-1); */
  /* 'petscObjectGetComm:18' if ~isempty(coder.target) */
  /* 'petscObjectGetComm:19' t_obj = PetscObject(obj); */
  /* Map an opaque object into a PETSc PetscObject object */
  /*  */
  /*   obj = PetscObject() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   obj = PetscObject(arg) or obj = PetscObject(arg, false) converts arg */
  /*   into a PETSc Object object. */
  /*  */
  /*   obj = PetscObject(arg, true) wraps the arg into an opaque object. */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscObject:18' coder.inline('always'); */
  /* 'PetscObject:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscObject:25' if isstruct(arg) && ~isequal(arg.type, 'PetscObject') && ... */
  /* 'PetscObject:26'         ~isequal(arg.type, 'Mat') && ~isequal(arg.type, 'Vec') && ... */
  /* 'PetscObject:27'         ~isequal(arg.type, 'KSP') && ~isequal(arg.type, 'PC') */
  /* 'PetscObject:32' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscObject:33' if nargin==1 || ~opaque */
  /* 'PetscObject:34' obj = coder.opaque('PetscObject'); */
  /* 'PetscObject:35' obj = coder.ceval('(PetscObject)', arg); */
  t_obj = (PetscObject)(Amat);

  /* 'petscObjectGetComm:20' t_comm = coder.opaque('MPI_Comm'); */
  /* 'petscObjectGetComm:22' errCode = coder.ceval('PetscObjectGetComm', t_obj, coder.wref(t_comm)); */
  errCode = PetscObjectGetComm(t_obj, &t_comm);

  /* 'petscObjectGetComm:24' toplevel = nargout>2; */
  /* 'petscObjectGetComm:25' comm = MPI_Comm(t_comm, toplevel); */
  /* Map an opaque object into a PETSc MPI_Comm object */
  /*  */
  /*   comm = MPI_Comm() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   comm = MPI_Comm(arg) or comm = MPI_Comm(arg, false) converts arg */
  /*   into a PETSc Options object. */
  /*  */
  /*   comm = MPI_Comm(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'MPI_Comm:18' coder.inline('always'); */
  /* 'MPI_Comm:20' if nargin==0 && isempty(coder.target) */
  /* 'MPI_Comm:25' if isstruct(arg) && ~isequal(arg.type, 'MPI_Comm') */
  /* 'MPI_Comm:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'MPI_Comm:31' if nargin==1 || ~opaque */
  /* 'MPI_Comm:32' comm = arg; */
  /* 'petscObjectGetComm:27' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    flag = (M2C_DEBUG);
    if (flag != 0) {
      /* 'petscObjectGetComm:28' m2c_error('petsc:RuntimeError', 'PetscObjectGetComm returned error code %d\n', errCode) */
      j_m2c_error(errCode);
    }
  }

  /* Creates a preconditioner context. */
  /*  */
  /*   [ksp, errCode] = petscKSPCreate */
  /*       creates a PETSc KSP using PETSC_COMM_WORLD */
  /*  */
  /*   [ksp, errCode] = petscKSPCreate(comm) */
  /*       comm: MPI Communicator */
  /*  */
  /*   SEE ALSO: petscKSPSetUp, petscKSPSolve, petscKSPDestroy */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode  KSPCreate(MPI_Comm comm,KSP *ksp) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPCreate.html */
  /* 'petscKSPCreate:18' errCode = int32(-1); */
  /* 'petscKSPCreate:20' if ~isempty(coder.target) */
  /* 'petscKSPCreate:21' t_ksp = coder.opaque('KSP'); */
  /* 'petscKSPCreate:23' if nargin==0 */
  /* 'petscKSPCreate:25' else */
  /* 'petscKSPCreate:26' t_comm = MPI_Comm(comm); */
  /* Map an opaque object into a PETSc MPI_Comm object */
  /*  */
  /*   comm = MPI_Comm() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   comm = MPI_Comm(arg) or comm = MPI_Comm(arg, false) converts arg */
  /*   into a PETSc Options object. */
  /*  */
  /*   comm = MPI_Comm(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'MPI_Comm:18' coder.inline('always'); */
  /* 'MPI_Comm:20' if nargin==0 && isempty(coder.target) */
  /* 'MPI_Comm:25' if isstruct(arg) && ~isequal(arg.type, 'MPI_Comm') */
  /* 'MPI_Comm:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'MPI_Comm:31' if nargin==1 || ~opaque */
  /* 'MPI_Comm:32' comm = arg; */
  /* 'petscKSPCreate:29' errCode = coder.ceval('KSPCreate', t_comm, coder.wref(t_ksp)); */
  errCode = KSPCreate(t_comm, &t_ksp);

  /* 'petscKSPCreate:31' toplevel = nargout>2; */
  /* 'petscKSPCreate:32' ksp = PetscKSP(t_ksp, toplevel); */
  /* Map an opaque object into a PETSc KSP object */
  /*  */
  /*   ksp = PetscKSP() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   ksp = PetscKSP(arg) or ksp = PetscKSP(arg, false) converts arg */
  /*   into a PETSc KSP object. */
  /*  */
  /*   ksp = PetscKSP(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscPC */
  /* 'PetscKSP:18' coder.inline('always'); */
  /* 'PetscKSP:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscKSP:25' if isstruct(arg) && ~isequal(arg.type, 'KSP') */
  /* 'PetscKSP:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscKSP:31' if nargin==1 || ~opaque */
  /* 'PetscKSP:32' ksp = arg; */
  /* 'petscKSPCreate:34' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    flag = (M2C_DEBUG);
    if (flag != 0) {
      /* 'petscKSPCreate:35' m2c_error('petsc:RuntimeError', 'KSPCreate returned error code %d\n', errCode) */
      k_m2c_error(errCode);
    }
  }

  /* 'mptKSPSetup:32' time = 0; */
  /* 'mptKSPSetup:33' if nargout>1 */
  /* 'mptKSPSetup:33' t=m2c_wtime(); */
  /*  Return ellapsed time */
  /*    t = m2c_wtime */
  /* 'm2c_wtime:7' if isempty(coder.target) */
  /* 'm2c_wtime:10' else */
  /* 'm2c_wtime:11' coder.inline( 'always'); */
  /* 'm2c_wtime:13' t = 0; */
  /* 'm2c_wtime:13' t = coder.ceval( 'M2C_wtime'); */
  t = M2C_wtime();

  /*  Setup KSP */
  /* 'mptKSPSetup:36' petscKSPSetOperators(t_ksp, PetscMat(t_Amat)); */
  /* Map an opaque object into a PETSc Mat object */
  /*  */
  /*   mat = PetscMat() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   mat = PetscMat(arg) or mat = PetscMat(arg, false) converts arg */
  /*   into a PETSc Mat object. */
  /*  */
  /*   mat = PetscMat(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscMat:18' coder.inline('always'); */
  /* 'PetscMat:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscMat:25' if isstruct(arg) && ~isequal(arg.type, 'Mat') */
  /* 'PetscMat:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscMat:31' if nargin==1 || ~opaque */
  /* 'PetscMat:32' mat = arg; */
  /* Sets the matrix associated with the linear system and a (possibly) */
  /* different one associated with the preconditioner. */
  /*  */
  /*   errCode = petscKSPSetOperators(ksp, Amat) */
  /*  */
  /*   sets the matrix to be Amat and use the same matrix to construct the */
  /*   preconditioner. */
  /*      ksp - iterative context obtained from petscKSPCreate */
  /*      Amat	  - the right hand side vector */
  /*  */
  /*   errCode = petscKSPSetOperators(ksp, Amat, Pmat) */
  /*  */
  /*   uses the matrix Pmat to construct the preconditioner. */
  /*  */
  /*   SEE ALSO: petscKSPCreate, petscKSPSetUp, petscKSPSolve, petscKSPDestroy */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode  KSPSetOperators(KSP ksp,Mat Amat,Mat Pmat) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPSetOperators.html */
  /* 'petscKSPSetOperators:25' errCode = int32(-1); */
  /* 'petscKSPSetOperators:27' if ~isempty(coder.target) */
  /* 'petscKSPSetOperators:28' t_ksp = PetscKSP(ksp); */
  /* Map an opaque object into a PETSc KSP object */
  /*  */
  /*   ksp = PetscKSP() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   ksp = PetscKSP(arg) or ksp = PetscKSP(arg, false) converts arg */
  /*   into a PETSc KSP object. */
  /*  */
  /*   ksp = PetscKSP(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscPC */
  /* 'PetscKSP:18' coder.inline('always'); */
  /* 'PetscKSP:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscKSP:25' if isstruct(arg) && ~isequal(arg.type, 'KSP') */
  /* 'PetscKSP:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscKSP:31' if nargin==1 || ~opaque */
  /* 'PetscKSP:32' ksp = arg; */
  /* 'petscKSPSetOperators:29' t_Amat = PetscMat(Amat); */
  /* Map an opaque object into a PETSc Mat object */
  /*  */
  /*   mat = PetscMat() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   mat = PetscMat(arg) or mat = PetscMat(arg, false) converts arg */
  /*   into a PETSc Mat object. */
  /*  */
  /*   mat = PetscMat(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscMat:18' coder.inline('always'); */
  /* 'PetscMat:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscMat:25' if isstruct(arg) && ~isequal(arg.type, 'Mat') */
  /* 'PetscMat:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscMat:31' if nargin==1 || ~opaque */
  /* 'PetscMat:32' mat = arg; */
  /* 'petscKSPSetOperators:31' if nargin==2 */
  /* 'petscKSPSetOperators:32' t_Pmat = t_Amat; */
  /* 'petscKSPSetOperators:37' errCode = coder.ceval('KSPSetOperators', t_ksp, t_Amat, t_Pmat); */
  errCode = KSPSetOperators(t_ksp, Amat, Amat);

  /* 'petscKSPSetOperators:39' toplevel = nargout>1; */
  /* 'petscKSPSetOperators:40' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    flag = (M2C_DEBUG);
    if (flag != 0) {
      /* 'petscKSPSetOperators:41' m2c_error('petsc:RuntimeError', 'KSPSetOperators returned error code %d\n', errCode) */
      l_m2c_error(errCode);
    }
  }

  /* 'mptKSPSetup:38' if nargin>1 */
  /* 'mptKSPSetup:39' if nargin>2 */
  /* 'mptKSPSetup:40' hasPC = ~ischar(pctype) || ~isempty(pctype); */
  b1 = !(pctype->size[1] == 0);

  /* 'mptKSPSetup:41' hasSolver = nargin>3 && (~ischar(solpack) || ~isempty(solpack)); */
  b2 = !(solpack->size[1] == 0);

  /* 'mptKSPSetup:43' if hasPC || hasSolver */
  emxInit_char_T(&pctype0, 2);
  if (b1 || b2) {
    /* 'mptKSPSetup:44' t_pc = petscKSPGetPC(t_ksp); */
    /* Returns a pointer to the preconditioner context set with petscKSPSetPC. */
    /*  */
    /*   [pc, errCode] = petscKSPGetPC(ksp, pc) gets the PC of the KSP */
    /*  */
    /*   SEE ALSO:  petscKSPSetPC */
    /*  */
    /*  PETSc C interface: */
    /*    PetscErrorCode  KSPGetPC(KSP ksp,PC *pc) */
    /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPGetPC.html */
    /* 'petscKSPGetPC:14' errCode = int32(-1); */
    /* 'petscKSPGetPC:16' if ~isempty(coder.target) */
    /* 'petscKSPGetPC:17' t_pc = coder.opaque('PC'); */
    /* 'petscKSPGetPC:18' errCode = coder.ceval('KSPGetPC', PetscKSP(ksp), coder.wref(t_pc)); */
    /* Map an opaque object into a PETSc KSP object */
    /*  */
    /*   ksp = PetscKSP() simply returns a definition of the */
    /*   m2c_opaque_type definition, suitable in the argument */
    /*   specification for codegen. */
    /*  */
    /*   ksp = PetscKSP(arg) or ksp = PetscKSP(arg, false) converts arg */
    /*   into a PETSc KSP object. */
    /*  */
    /*   ksp = PetscKSP(arg, true) wraps the arg into an opaque object.  */
    /*   This should be used if the object needs to be returned to */
    /*   MATLAB. Note that the value of opaque must be determined at */
    /*   compile time. */
    /*  */
    /*  See also PetscPC */
    /* 'PetscKSP:18' coder.inline('always'); */
    /* 'PetscKSP:20' if nargin==0 && isempty(coder.target) */
    /* 'PetscKSP:25' if isstruct(arg) && ~isequal(arg.type, 'KSP') */
    /* 'PetscKSP:30' if ~isstruct(arg) || isempty(coder.target) */
    /* 'PetscKSP:31' if nargin==1 || ~opaque */
    /* 'PetscKSP:32' ksp = arg; */
    errCode = KSPGetPC(t_ksp, &t_pc);

    /* 'petscKSPGetPC:20' toplevel = nargout>2; */
    /* 'petscKSPGetPC:21' pc = PetscPC(t_pc, toplevel); */
    /* Map an opaque object into a PETSc PC object */
    /*  */
    /*   pc = PetscPC() simply returns a definition of the */
    /*   m2c_opaque_type definition, suitable in the argument */
    /*   specification for codegen. */
    /*  */
    /*   pc = PetscPC(arg) or pc = PetscPC(arg, false) converts arg */
    /*   into a PETSc PC object. */
    /*  */
    /*   pc = PetscPC(arg, true) wraps the arg into an opaque object.  */
    /*   This should be used if the object needs to be returned to */
    /*   MATLAB. Note that the value of opaque must be determined at */
    /*   compile time. */
    /*  */
    /*  See also PetscKSP */
    /* 'PetscPC:18' coder.inline('always'); */
    /* 'PetscPC:20' if nargin==0 && isempty(coder.target) */
    /* 'PetscPC:25' if isstruct(arg) && ~isequal(arg.type, 'PC') */
    /* 'PetscPC:30' if ~isstruct(arg) || isempty(coder.target) */
    /* 'PetscPC:31' if nargin==1 || ~opaque */
    /* 'PetscPC:32' pc = arg; */
    /* 'petscKSPGetPC:23' if errCode && (toplevel || m2c_debug) */
    if (errCode != 0) {
      /* Flag indicating whether m2c_debug is on. */
      /* It is always true within MATLAB. In the generated C code, it is */
      /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
      /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
      /* 'm2c_debug:7' coder.inline('always'); */
      /* 'm2c_debug:9' if isempty(coder.target) */
      /* 'm2c_debug:11' else */
      /* 'm2c_debug:12' flag = int32(1); */
      /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
      flag = (M2C_DEBUG);
      if (flag != 0) {
        /* 'petscKSPGetPC:24' m2c_error('petsc:RuntimeError', 'KSPGetPC returned error code %d\n', errCode) */
        w_m2c_error(errCode);
      }
    }

    /* 'mptKSPSetup:46' if hasPC */
    if (b1) {
      /* 'mptKSPSetup:47' if ischar(pctype) && pctype(end)~=char(0) */
      if (pctype->data[pctype->size[1] - 1] != '\x00') {
        /*  null-terminate the string if not terminated properly */
        /* 'mptKSPSetup:49' pctype0 = [pctype char(0)]; */
        flag = pctype0->size[0] * pctype0->size[1];
        pctype0->size[0] = 1;
        pctype0->size[1] = pctype->size[1] + 1;
        emxEnsureCapacity((emxArray__common *)pctype0, flag, (int)sizeof(char));
        loop_ub = pctype->size[1];
        for (flag = 0; flag < loop_ub; flag++) {
          pctype0->data[pctype0->size[0] * flag] = pctype->data[pctype->size[0] *
            flag];
        }

        pctype0->data[pctype0->size[0] * pctype->size[1]] = '\x00';
      } else {
        /* 'mptKSPSetup:50' else */
        /* 'mptKSPSetup:51' pctype0 = pctype; */
        flag = pctype0->size[0] * pctype0->size[1];
        pctype0->size[0] = 1;
        pctype0->size[1] = pctype->size[1];
        emxEnsureCapacity((emxArray__common *)pctype0, flag, (int)sizeof(char));
        loop_ub = pctype->size[0] * pctype->size[1];
        for (flag = 0; flag < loop_ub; flag++) {
          pctype0->data[flag] = pctype->data[flag];
        }
      }

      /* 'mptKSPSetup:53' petscPCSetType(t_pc, pctype0); */
      /* Builds PC for a particular solver. */
      /*  */
      /*   errCode = petscPCSetType(pc, type) sets the type of the PC */
      /*  */
      /*   SEE ALSO:  PetscPCSetType, petscPCCreate */
      /*  */
      /*  PETSc C interface: */
      /*    PetscErrorCode  PCSetType(PC pc, PCType type) */
      /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/PC/PCSetType.html */
      /* 'petscPCSetType:14' errCode = int32(-1); */
      /* 'petscPCSetType:16' if ~isempty(coder.target) */
      /* 'petscPCSetType:17' if ischar(type) */
      /* 'petscPCSetType:18' errCode = coder.ceval('PCSetType', PetscPC(pc), coder.rref(type)); */
      /* Map an opaque object into a PETSc PC object */
      /*  */
      /*   pc = PetscPC() simply returns a definition of the */
      /*   m2c_opaque_type definition, suitable in the argument */
      /*   specification for codegen. */
      /*  */
      /*   pc = PetscPC(arg) or pc = PetscPC(arg, false) converts arg */
      /*   into a PETSc PC object. */
      /*  */
      /*   pc = PetscPC(arg, true) wraps the arg into an opaque object.  */
      /*   This should be used if the object needs to be returned to */
      /*   MATLAB. Note that the value of opaque must be determined at */
      /*   compile time. */
      /*  */
      /*  See also PetscKSP */
      /* 'PetscPC:18' coder.inline('always'); */
      /* 'PetscPC:20' if nargin==0 && isempty(coder.target) */
      /* 'PetscPC:25' if isstruct(arg) && ~isequal(arg.type, 'PC') */
      /* 'PetscPC:30' if ~isstruct(arg) || isempty(coder.target) */
      /* 'PetscPC:31' if nargin==1 || ~opaque */
      /* 'PetscPC:32' pc = arg; */
      errCode = PCSetType(t_pc, &pctype0->data[0]);

      /* 'petscPCSetType:23' toplevel = nargout>1; */
      /* 'petscPCSetType:24' if errCode && (toplevel || m2c_debug) */
      if (errCode != 0) {
        /* Flag indicating whether m2c_debug is on. */
        /* It is always true within MATLAB. In the generated C code, it is */
        /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
        /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
        /* 'm2c_debug:7' coder.inline('always'); */
        /* 'm2c_debug:9' if isempty(coder.target) */
        /* 'm2c_debug:11' else */
        /* 'm2c_debug:12' flag = int32(1); */
        /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
        flag = (M2C_DEBUG);
        if (flag != 0) {
          /* 'petscPCSetType:25' m2c_error('petsc:RuntimeError', 'PCSetType returned error code %d\n', errCode) */
          hb_m2c_error(errCode);
        }
      }
    }

    /* 'mptKSPSetup:56' if hasSolver */
    if (b2) {
      /* 'mptKSPSetup:57' if ischar(solpack) && solpack(end)~=char(0) */
      if (solpack->data[solpack->size[1] - 1] != '\x00') {
        /*  null-terminate the string if not terminated properly */
        /* 'mptKSPSetup:59' solpack0 = [solpack char(0)]; */
        flag = pctype0->size[0] * pctype0->size[1];
        pctype0->size[0] = 1;
        pctype0->size[1] = solpack->size[1] + 1;
        emxEnsureCapacity((emxArray__common *)pctype0, flag, (int)sizeof(char));
        loop_ub = solpack->size[1];
        for (flag = 0; flag < loop_ub; flag++) {
          pctype0->data[pctype0->size[0] * flag] = solpack->data[solpack->size[0]
            * flag];
        }

        pctype0->data[pctype0->size[0] * solpack->size[1]] = '\x00';
      } else {
        /* 'mptKSPSetup:60' else */
        /* 'mptKSPSetup:61' solpack0 = solpack; */
        flag = pctype0->size[0] * pctype0->size[1];
        pctype0->size[0] = 1;
        pctype0->size[1] = solpack->size[1];
        emxEnsureCapacity((emxArray__common *)pctype0, flag, (int)sizeof(char));
        loop_ub = solpack->size[0] * solpack->size[1];
        for (flag = 0; flag < loop_ub; flag++) {
          pctype0->data[flag] = solpack->data[flag];
        }
      }

      /* 'mptKSPSetup:63' petscPCFactorSetMatSolverPackage(t_pc,solpack0); */
      /* Sets the software that is used to perform the factorization */
      /*  */
      /*   errCode = petscpetscPCFactorSetMatSolverPackage(pc, solver) sets the */
      /*        the solver to the given solver */
      /*  */
      /*   SEE ALSO:  PetscpetscPCFactorSetMatSolverPackage, petscPCCreate */
      /*  */
      /*  PETSc C interface: */
      /*    PetscErrorCode  PCFactorSetMatSolverPackage(PC pc,const MatSolverPackage ssolver) */
      /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/PC/petscPCFactorSetMatSolverPackage.html */
      /* 'petscPCFactorSetMatSolverPackage:15' errCode = int32(-1); */
      /* 'petscPCFactorSetMatSolverPackage:17' if ~isempty(coder.target) */
      /* 'petscPCFactorSetMatSolverPackage:18' if ischar(solver) */
      /* 'petscPCFactorSetMatSolverPackage:19' errCode = coder.ceval('PCFactorSetMatSolverPackage', ... */
      /* 'petscPCFactorSetMatSolverPackage:20'             PetscPC(pc), coder.rref(solver)); */
      /* Map an opaque object into a PETSc PC object */
      /*  */
      /*   pc = PetscPC() simply returns a definition of the */
      /*   m2c_opaque_type definition, suitable in the argument */
      /*   specification for codegen. */
      /*  */
      /*   pc = PetscPC(arg) or pc = PetscPC(arg, false) converts arg */
      /*   into a PETSc PC object. */
      /*  */
      /*   pc = PetscPC(arg, true) wraps the arg into an opaque object.  */
      /*   This should be used if the object needs to be returned to */
      /*   MATLAB. Note that the value of opaque must be determined at */
      /*   compile time. */
      /*  */
      /*  See also PetscKSP */
      /* 'PetscPC:18' coder.inline('always'); */
      /* 'PetscPC:20' if nargin==0 && isempty(coder.target) */
      /* 'PetscPC:25' if isstruct(arg) && ~isequal(arg.type, 'PC') */
      /* 'PetscPC:30' if ~isstruct(arg) || isempty(coder.target) */
      /* 'PetscPC:31' if nargin==1 || ~opaque */
      /* 'PetscPC:32' pc = arg; */
      errCode = PCFactorSetMatSolverPackage(t_pc, &pctype0->data[0]);

      /* 'petscPCFactorSetMatSolverPackage:27' toplevel = nargout>1; */
      /* 'petscPCFactorSetMatSolverPackage:28' if errCode && (toplevel || m2c_debug) */
      if (errCode != 0) {
        /* Flag indicating whether m2c_debug is on. */
        /* It is always true within MATLAB. In the generated C code, it is */
        /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
        /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
        /* 'm2c_debug:7' coder.inline('always'); */
        /* 'm2c_debug:9' if isempty(coder.target) */
        /* 'm2c_debug:11' else */
        /* 'm2c_debug:12' flag = int32(1); */
        /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
        flag = (M2C_DEBUG);
        if (flag != 0) {
          /* 'petscPCFactorSetMatSolverPackage:29' m2c_error('petsc:RuntimeError', 'petscPCFactorSetMatSolverPackage returned error code %d\n', errCode) */
          ib_m2c_error(errCode);
        }
      }
    }
  }

  /* 'mptKSPSetup:68' if ischar(ksptype) && ~isempty(ksptype) && ksptype(end)~=0 */
  if ((!(ksptype->size[1] == 0)) && ((unsigned char)ksptype->data[ksptype->size
       [1] - 1] != 0)) {
    /*  null-terminate the string if not terminated properly */
    /* 'mptKSPSetup:70' ksptype0 = [ksptype char(0)]; */
    flag = pctype0->size[0] * pctype0->size[1];
    pctype0->size[0] = 1;
    pctype0->size[1] = ksptype->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)pctype0, flag, (int)sizeof(char));
    loop_ub = ksptype->size[1];
    for (flag = 0; flag < loop_ub; flag++) {
      pctype0->data[pctype0->size[0] * flag] = ksptype->data[ksptype->size[0] *
        flag];
    }

    pctype0->data[pctype0->size[0] * ksptype->size[1]] = '\x00';
  } else {
    /* 'mptKSPSetup:71' else */
    /* 'mptKSPSetup:72' ksptype0 = ksptype; */
    flag = pctype0->size[0] * pctype0->size[1];
    pctype0->size[0] = 1;
    pctype0->size[1] = ksptype->size[1];
    emxEnsureCapacity((emxArray__common *)pctype0, flag, (int)sizeof(char));
    loop_ub = ksptype->size[0] * ksptype->size[1];
    for (flag = 0; flag < loop_ub; flag++) {
      pctype0->data[flag] = ksptype->data[flag];
    }
  }

  /* 'mptKSPSetup:74' if ischar(ksptype0) && ~isempty(ksptype0) || ~ischar(ksptype0) */
  if (!(pctype0->size[1] == 0)) {
    /*  Set KSP Types */
    /* 'mptKSPSetup:76' petscKSPSetType(t_ksp, ksptype0); */
    /* Builds KSP for a particular solver. */
    /*  */
    /*   errCode = petscKSPSetType(ksp, type) sets the type of the KSP */
    /*  */
    /*   SEE ALSO:  PetscPCSetType, petscKSPCreate */
    /*  */
    /*  PETSc C interface: */
    /*    PetscErrorCode  KSPSetType(KSP ksp, KSPType type) */
    /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPSetType.html */
    /* 'petscKSPSetType:14' errCode = int32(-1); */
    /* 'petscKSPSetType:16' if ~isempty(coder.target) */
    /* 'petscKSPSetType:17' if ischar(type) */
    /* 'petscKSPSetType:18' errCode = coder.ceval('KSPSetType', PetscKSP(ksp), coder.rref(type)); */
    /* Map an opaque object into a PETSc KSP object */
    /*  */
    /*   ksp = PetscKSP() simply returns a definition of the */
    /*   m2c_opaque_type definition, suitable in the argument */
    /*   specification for codegen. */
    /*  */
    /*   ksp = PetscKSP(arg) or ksp = PetscKSP(arg, false) converts arg */
    /*   into a PETSc KSP object. */
    /*  */
    /*   ksp = PetscKSP(arg, true) wraps the arg into an opaque object.  */
    /*   This should be used if the object needs to be returned to */
    /*   MATLAB. Note that the value of opaque must be determined at */
    /*   compile time. */
    /*  */
    /*  See also PetscPC */
    /* 'PetscKSP:18' coder.inline('always'); */
    /* 'PetscKSP:20' if nargin==0 && isempty(coder.target) */
    /* 'PetscKSP:25' if isstruct(arg) && ~isequal(arg.type, 'KSP') */
    /* 'PetscKSP:30' if ~isstruct(arg) || isempty(coder.target) */
    /* 'PetscKSP:31' if nargin==1 || ~opaque */
    /* 'PetscKSP:32' ksp = arg; */
    errCode = KSPSetType(t_ksp, &pctype0->data[0]);

    /* 'petscKSPSetType:23' toplevel = nargout>1; */
    /* 'petscKSPSetType:24' if errCode && (toplevel || m2c_debug) */
    if (errCode != 0) {
      /* Flag indicating whether m2c_debug is on. */
      /* It is always true within MATLAB. In the generated C code, it is */
      /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
      /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
      /* 'm2c_debug:7' coder.inline('always'); */
      /* 'm2c_debug:9' if isempty(coder.target) */
      /* 'm2c_debug:11' else */
      /* 'm2c_debug:12' flag = int32(1); */
      /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
      flag = (M2C_DEBUG);
      if (flag != 0) {
        /* 'petscKSPSetType:25' m2c_error('petsc:RuntimeError', 'KSPSetType returned error code %d\n', errCode) */
        gb_m2c_error(errCode);
      }
    }
  }

  emxFree_char_T(&pctype0);

  /* 'mptKSPSetup:80' petscKSPSetFromOptions(t_ksp); */
  /* Sets KSP options from the options database. This routine must be called */
  /* before KSPSetUp() if the user is to be allowed to set the Krylov type. */
  /*  */
  /*   errCode = petscKSPSetFromOptions(ksp) */
  /*  */
  /*   SEE ALSO: petscKSPCreate, petscKSPSetOperators, petscKSPSolve, petscKSPDestroy */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode KSPSetFromOptions(KSP ksp) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPSetFromOptions.html */
  /* 'petscKSPSetFromOptions:15' errCode = int32(-1); */
  /* 'petscKSPSetFromOptions:17' if ~isempty(coder.target) */
  /* 'petscKSPSetFromOptions:18' t_ksp = PetscKSP(ksp); */
  /* Map an opaque object into a PETSc KSP object */
  /*  */
  /*   ksp = PetscKSP() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   ksp = PetscKSP(arg) or ksp = PetscKSP(arg, false) converts arg */
  /*   into a PETSc KSP object. */
  /*  */
  /*   ksp = PetscKSP(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscPC */
  /* 'PetscKSP:18' coder.inline('always'); */
  /* 'PetscKSP:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscKSP:25' if isstruct(arg) && ~isequal(arg.type, 'KSP') */
  /* 'PetscKSP:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscKSP:31' if nargin==1 || ~opaque */
  /* 'PetscKSP:32' ksp = arg; */
  /* 'petscKSPSetFromOptions:20' errCode = coder.ceval('KSPSetFromOptions', t_ksp); */
  errCode = KSPSetFromOptions(t_ksp);

  /* 'petscKSPSetFromOptions:22' toplevel = nargout>1; */
  /* 'petscKSPSetFromOptions:23' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    flag = (M2C_DEBUG);
    if (flag != 0) {
      /* 'petscKSPSetFromOptions:24' m2c_error('petsc:RuntimeError', 'KSPSetFromOptions returned error code %d\n', errCode) */
      m_m2c_error(errCode);
    }
  }

  /* 'mptKSPSetup:82' petscKSPSetUp(t_ksp); */
  /* Sets up the internal data structures for the later use of an iterative solver. */
  /*  */
  /*   errCode = petscKSPSetUp(ksp) */
  /*  */
  /*   SEE ALSO: petscKSPCreate, petscKSPSetOperators, petscKSPSolve, petscKSPDestroy */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode KSPSetUp(KSP ksp) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPSetUp.html */
  /* 'petscKSPSetUp:14' errCode = int32(-1); */
  /* 'petscKSPSetUp:16' if ~isempty(coder.target) */
  /* 'petscKSPSetUp:17' t_ksp = PetscKSP(ksp); */
  /* Map an opaque object into a PETSc KSP object */
  /*  */
  /*   ksp = PetscKSP() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   ksp = PetscKSP(arg) or ksp = PetscKSP(arg, false) converts arg */
  /*   into a PETSc KSP object. */
  /*  */
  /*   ksp = PetscKSP(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscPC */
  /* 'PetscKSP:18' coder.inline('always'); */
  /* 'PetscKSP:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscKSP:25' if isstruct(arg) && ~isequal(arg.type, 'KSP') */
  /* 'PetscKSP:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscKSP:31' if nargin==1 || ~opaque */
  /* 'PetscKSP:32' ksp = arg; */
  /* 'petscKSPSetUp:19' errCode = coder.ceval('KSPSetUp', t_ksp); */
  errCode = KSPSetUp(t_ksp);

  /* 'petscKSPSetUp:21' toplevel = nargout>1; */
  /* 'petscKSPSetUp:22' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    flag = (M2C_DEBUG);
    if (flag != 0) {
      /* 'petscKSPSetUp:23' m2c_error('petsc:RuntimeError', 'KSPSetUp returned error code %d\n', errCode) */
      n_m2c_error(errCode);
    }
  }

  /* 'mptKSPSetup:83' if nargout>1 */
  /* 'mptKSPSetup:83' time=m2c_wtime()-t; */
  /*  Return ellapsed time */
  /*    t = m2c_wtime */
  /* 'm2c_wtime:7' if isempty(coder.target) */
  /* 'm2c_wtime:10' else */
  /* 'm2c_wtime:11' coder.inline( 'always'); */
  /* 'm2c_wtime:13' t = 0; */
  /* 'm2c_wtime:13' t = coder.ceval( 'M2C_wtime'); */
  b_t = M2C_wtime();
  *time = b_t - t;

  /* 'mptKSPSetup:85' toplevel = nargout>2; */
  /* 'mptKSPSetup:86' ksp = PetscKSP(t_ksp, toplevel); */
  /* Map an opaque object into a PETSc KSP object */
  /*  */
  /*   ksp = PetscKSP() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   ksp = PetscKSP(arg) or ksp = PetscKSP(arg, false) converts arg */
  /*   into a PETSc KSP object. */
  /*  */
  /*   ksp = PetscKSP(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscPC */
  /* 'PetscKSP:18' coder.inline('always'); */
  /* 'PetscKSP:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscKSP:25' if isstruct(arg) && ~isequal(arg.type, 'KSP') */
  /* 'PetscKSP:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscKSP:31' if nargin==1 || ~opaque */
  /* 'PetscKSP:32' ksp = arg; */
  *ksp = t_ksp;
}

/*
 * function [flag,relres,iter,time] = mptKSPSolve(ksp, b, x, rtol, maxits, x0)
 */
static void mptKSPSolve(KSP ksp, Vec b, Vec x, double rtol, int maxits, Vec x0,
  int *flag, double *relres, int *iter, double *time)
{
  double t;
  int val;
  int b_val;
  int errCode;
  double b_t;
  double b_rtol;
  double abstol;
  double dtol;
  int b_maxits;
  PC t_pc;
  KSPType t_type;
  PCType b_t_type;

  /*  Solves linear system. */
  /*  */
  /*  Syntax: */
  /*     mptKSPSolve(ksp, b) */
  /*     mptKSPSolve(ksp, b, x) */
  /*     mptKSPSolve(ksp, b, x, rtol) */
  /*     mptKSPSolve(ksp, b, x, rtol, maxits) */
  /*     mptKSPSolve(ksp, b, x, rtol, maxits, x0) */
  /*  */
  /*     [flag, reslres, iter, time] = mptKSPSolve(...) returns the flag  */
  /*        (PETSc KSPConvergedReason), relative residual, number of */
  /*        iterations, and the execution time spent in  */
  /*  */
  /*  Description: */
  /*     mptKSPSolve(ksp, b) solves the linear system using the tolerances */
  /*     that have been set previously by the user. The solution overwrites b. */
  /*  */
  /*     mptKSPSolve(ksp, b, x) solves the linear system and saves the solution */
  /*     into x. */
  /*  */
  /*     mptKSPSolve(ksp, b, x, rtol) solves with the given relative tolerance. */
  /*  */
  /*     mptKSPSolve(ksp, b, x, rtol, maxits) solves with the given relative */
  /*     tolerances and maximum iteration count. */
  /*  */
  /*     mptKSPSolve(ksp, b, rtol, maxits, x0) uses x0 as the initial guess */
  /*  */
  /*  See also mptKSPSetup, mptKSPCleanup */
  /* 'mptKSPSolve:37' time = 0; */
  /* 'mptKSPSolve:38' if nargout>3 */
  /* 'mptKSPSolve:38' t=m2c_wtime(); */
  /*  Return ellapsed time */
  /*    t = m2c_wtime */
  /* 'm2c_wtime:7' if isempty(coder.target) */
  /* 'm2c_wtime:10' else */
  /* 'm2c_wtime:11' coder.inline( 'always'); */
  /* 'm2c_wtime:13' t = 0; */
  /* 'm2c_wtime:13' t = coder.ceval( 'M2C_wtime'); */
  t = M2C_wtime();

  /* 'mptKSPSolve:40' t_ksp = PetscKSP(ksp); */
  /* Map an opaque object into a PETSc KSP object */
  /*  */
  /*   ksp = PetscKSP() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   ksp = PetscKSP(arg) or ksp = PetscKSP(arg, false) converts arg */
  /*   into a PETSc KSP object. */
  /*  */
  /*   ksp = PetscKSP(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscPC */
  /* 'PetscKSP:18' coder.inline('always'); */
  /* 'PetscKSP:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscKSP:25' if isstruct(arg) && ~isequal(arg.type, 'KSP') */
  /* 'PetscKSP:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscKSP:31' if nargin==1 || ~opaque */
  /* 'PetscKSP:32' ksp = arg; */
  /*  Solve the linear system */
  /* 'mptKSPSolve:43' if nargin==2 */
  /* 'mptKSPSolve:46' else */
  /*  Set tolerances */
  /* 'mptKSPSolve:48' if nargin>=4 */
  /* 'mptKSPSolve:49' if rtol==0 */
  if (rtol == 0.0) {
    /* 'mptKSPSolve:50' rtol = double(PETSC_DEFAULT); */
    /*  Obtain PETSC constant PETSC_DEFAULT */
    /* 'PETSC_DEFAULT:4' coder.inline('always'); */
    /* 'PETSC_DEFAULT:6' val = petscGetEnum('PETSC_DEFAULT'); */
    /* petscGetEnum Obtain an enumerate value in PETSC */
    /*  */
    /*     val = petscGetEnum(name) */
    /*  */
    /* The supported names include: */
    /*  */
    /*  PetscBool:  PETSC_TRUE, PETSC_FALSE */
    /*  */
    /*  VecOption: VEC_IGNORE_OFF_PROC_ENTRIES, VEC_IGNORE_NEGATIVE_INDICES, */
    /*       VEC_SUBSET_OFF_PROC_ENTRIES */
    /*  */
    /*  MatOption: MAT_ROW_ORIENTED, MAT_SYMMETRIC, MAT_STRUCTURALLY_SYMMETRIC, */
    /*       MAT_NEW_DIAGONALS, MAT_IGNORE_OFF_PROC_ENTRIES, */
    /*       MAT_USE_HASH_TABLE, MAT_KEEP_NONZERO_PATTERN, */
    /*       MAT_IGNORE_ZERO_ENTRIES, MAT_USE_INODES, MAT_HERMITIAN, */
    /*       MAT_SYMMETRY_ETERNAL, MAT_NEW_NONZERO_LOCATION_ERR, */
    /*       MAT_IGNORE_LOWER_TRIANGULAR, MAT_ERROR_LOWER_TRIANGULAR, */
    /*       MAT_GETROW_UPPERTRIANGULAR, MAT_SPD, */
    /*       MAT_NO_OFF_PROC_ZERO_ROWS, MAT_NO_OFF_PROC_ENTRIES, */
    /*       MAT_NEW_NONZERO_LOCATIONS, MAT_NEW_NONZERO_ALLOCATION_ERR, */
    /*       MAT_SUBSET_OFF_PROC_ENTRIES */
    /*  */
    /*  MatStructure: DIFFERENT_NONZERO_PATTERN, SUBSET_NONZERO_PATTERN, SAME_NONZERO_PATTERN */
    /*  */
    /*  MatDuplicateOption: MAT_DO_NOT_COPY_VALUES,MAT_COPY_VALUES,MAT_SHARE_NONZERO_PATTERN */
    /*  */
    /*  MatReuse: MAT_INITIAL_MATRIX,MAT_REUSE_MATRIX,MAT_IGNORE_MATRIX,MAT_INPLACE_MATRIX */
    /*  */
    /*  InsertMode: INSERT_VALUES, ADD_VALUES, MAX_VALUES, */
    /*       INSERT_ALL_VALUES, ADD_ALL_VALUES, INSERT_BC_VALUES, ADD_BC_VALUES */
    /*  */
    /*  MatAssemblyType: MAT_FINAL_ASSEMBLY, MAT_FLUSH_ASSEMBLY */
    /*  */
    /*  MatInfoType: MAT_LOCAL,MAT_GLOBAL_MAX,MAT_GLOBAL_SUM */
    /*  */
    /*  MatFactorType: MAT_FACTOR_NONE, MAT_FACTOR_LU, MAT_FACTOR_CHOLESKY,  */
    /*       MAT_FACTOR_ILU, MAT_FACTOR_ICC,MAT_FACTOR_ILUDT */
    /*  */
    /*  NormType: NORM_1, NORM_2, NORM_FROBENIUS, NORM_INFINITY, NORM_1_AND_2 */
    /*  */
    /*  Others:  PETSC_DETERMINE, PETSC_DECIDE, PETSC_DEFAULT */
    /* 'petscGetEnum:46' if isempty(coder.target) */
    /* 'petscGetEnum:50' coder.cinclude('petscsys.h'); */
    /* 'petscGetEnum:51' coder.cinclude('petscksp.h'); */
    /* % InsertMode */
    /* 'petscGetEnum:54' switch name */
    /* 'petscGetEnum:171' case 'PETSC_DEFAULT' */
    /* 'petscGetEnum:172' [val, toplevel] = get_val('PetscInt', 'PETSC_DEFAULT', nargin>1); */
    /* 'petscGetEnum:183' coder.inline('always'); */
    /* 'petscGetEnum:185' val = int32(intmin); */
    /* 'petscGetEnum:186' val = coder.ceval(' ', coder.opaque(type, name)); */
    val = (PETSC_DEFAULT);
    rtol = val;
  }

  /* 'mptKSPSolve:52' if nargin<5 || maxits==0 */
  if (maxits == 0) {
    /* 'mptKSPSolve:53' maxits = PETSC_DEFAULT; */
    /*  Obtain PETSC constant PETSC_DEFAULT */
    /* 'PETSC_DEFAULT:4' coder.inline('always'); */
    /* 'PETSC_DEFAULT:6' val = petscGetEnum('PETSC_DEFAULT'); */
    /* petscGetEnum Obtain an enumerate value in PETSC */
    /*  */
    /*     val = petscGetEnum(name) */
    /*  */
    /* The supported names include: */
    /*  */
    /*  PetscBool:  PETSC_TRUE, PETSC_FALSE */
    /*  */
    /*  VecOption: VEC_IGNORE_OFF_PROC_ENTRIES, VEC_IGNORE_NEGATIVE_INDICES, */
    /*       VEC_SUBSET_OFF_PROC_ENTRIES */
    /*  */
    /*  MatOption: MAT_ROW_ORIENTED, MAT_SYMMETRIC, MAT_STRUCTURALLY_SYMMETRIC, */
    /*       MAT_NEW_DIAGONALS, MAT_IGNORE_OFF_PROC_ENTRIES, */
    /*       MAT_USE_HASH_TABLE, MAT_KEEP_NONZERO_PATTERN, */
    /*       MAT_IGNORE_ZERO_ENTRIES, MAT_USE_INODES, MAT_HERMITIAN, */
    /*       MAT_SYMMETRY_ETERNAL, MAT_NEW_NONZERO_LOCATION_ERR, */
    /*       MAT_IGNORE_LOWER_TRIANGULAR, MAT_ERROR_LOWER_TRIANGULAR, */
    /*       MAT_GETROW_UPPERTRIANGULAR, MAT_SPD, */
    /*       MAT_NO_OFF_PROC_ZERO_ROWS, MAT_NO_OFF_PROC_ENTRIES, */
    /*       MAT_NEW_NONZERO_LOCATIONS, MAT_NEW_NONZERO_ALLOCATION_ERR, */
    /*       MAT_SUBSET_OFF_PROC_ENTRIES */
    /*  */
    /*  MatStructure: DIFFERENT_NONZERO_PATTERN, SUBSET_NONZERO_PATTERN, SAME_NONZERO_PATTERN */
    /*  */
    /*  MatDuplicateOption: MAT_DO_NOT_COPY_VALUES,MAT_COPY_VALUES,MAT_SHARE_NONZERO_PATTERN */
    /*  */
    /*  MatReuse: MAT_INITIAL_MATRIX,MAT_REUSE_MATRIX,MAT_IGNORE_MATRIX,MAT_INPLACE_MATRIX */
    /*  */
    /*  InsertMode: INSERT_VALUES, ADD_VALUES, MAX_VALUES, */
    /*       INSERT_ALL_VALUES, ADD_ALL_VALUES, INSERT_BC_VALUES, ADD_BC_VALUES */
    /*  */
    /*  MatAssemblyType: MAT_FINAL_ASSEMBLY, MAT_FLUSH_ASSEMBLY */
    /*  */
    /*  MatInfoType: MAT_LOCAL,MAT_GLOBAL_MAX,MAT_GLOBAL_SUM */
    /*  */
    /*  MatFactorType: MAT_FACTOR_NONE, MAT_FACTOR_LU, MAT_FACTOR_CHOLESKY,  */
    /*       MAT_FACTOR_ILU, MAT_FACTOR_ICC,MAT_FACTOR_ILUDT */
    /*  */
    /*  NormType: NORM_1, NORM_2, NORM_FROBENIUS, NORM_INFINITY, NORM_1_AND_2 */
    /*  */
    /*  Others:  PETSC_DETERMINE, PETSC_DECIDE, PETSC_DEFAULT */
    /* 'petscGetEnum:46' if isempty(coder.target) */
    /* 'petscGetEnum:50' coder.cinclude('petscsys.h'); */
    /* 'petscGetEnum:51' coder.cinclude('petscksp.h'); */
    /* % InsertMode */
    /* 'petscGetEnum:54' switch name */
    /* 'petscGetEnum:171' case 'PETSC_DEFAULT' */
    /* 'petscGetEnum:172' [val, toplevel] = get_val('PetscInt', 'PETSC_DEFAULT', nargin>1); */
    /* 'petscGetEnum:183' coder.inline('always'); */
    /* 'petscGetEnum:185' val = int32(intmin); */
    /* 'petscGetEnum:186' val = coder.ceval(' ', coder.opaque(type, name)); */
    maxits = (PETSC_DEFAULT);
  }

  /* 'mptKSPSolve:55' petscKSPSetTolerances(t_ksp, double(rtol), double(PETSC_DEFAULT), ... */
  /* 'mptKSPSolve:56'             double(PETSC_DEFAULT), int32(maxits)); */
  /*  Obtain PETSC constant PETSC_DEFAULT */
  /* 'PETSC_DEFAULT:4' coder.inline('always'); */
  /* 'PETSC_DEFAULT:6' val = petscGetEnum('PETSC_DEFAULT'); */
  /* petscGetEnum Obtain an enumerate value in PETSC */
  /*  */
  /*     val = petscGetEnum(name) */
  /*  */
  /* The supported names include: */
  /*  */
  /*  PetscBool:  PETSC_TRUE, PETSC_FALSE */
  /*  */
  /*  VecOption: VEC_IGNORE_OFF_PROC_ENTRIES, VEC_IGNORE_NEGATIVE_INDICES, */
  /*       VEC_SUBSET_OFF_PROC_ENTRIES */
  /*  */
  /*  MatOption: MAT_ROW_ORIENTED, MAT_SYMMETRIC, MAT_STRUCTURALLY_SYMMETRIC, */
  /*       MAT_NEW_DIAGONALS, MAT_IGNORE_OFF_PROC_ENTRIES, */
  /*       MAT_USE_HASH_TABLE, MAT_KEEP_NONZERO_PATTERN, */
  /*       MAT_IGNORE_ZERO_ENTRIES, MAT_USE_INODES, MAT_HERMITIAN, */
  /*       MAT_SYMMETRY_ETERNAL, MAT_NEW_NONZERO_LOCATION_ERR, */
  /*       MAT_IGNORE_LOWER_TRIANGULAR, MAT_ERROR_LOWER_TRIANGULAR, */
  /*       MAT_GETROW_UPPERTRIANGULAR, MAT_SPD, */
  /*       MAT_NO_OFF_PROC_ZERO_ROWS, MAT_NO_OFF_PROC_ENTRIES, */
  /*       MAT_NEW_NONZERO_LOCATIONS, MAT_NEW_NONZERO_ALLOCATION_ERR, */
  /*       MAT_SUBSET_OFF_PROC_ENTRIES */
  /*  */
  /*  MatStructure: DIFFERENT_NONZERO_PATTERN, SUBSET_NONZERO_PATTERN, SAME_NONZERO_PATTERN */
  /*  */
  /*  MatDuplicateOption: MAT_DO_NOT_COPY_VALUES,MAT_COPY_VALUES,MAT_SHARE_NONZERO_PATTERN */
  /*  */
  /*  MatReuse: MAT_INITIAL_MATRIX,MAT_REUSE_MATRIX,MAT_IGNORE_MATRIX,MAT_INPLACE_MATRIX */
  /*  */
  /*  InsertMode: INSERT_VALUES, ADD_VALUES, MAX_VALUES, */
  /*       INSERT_ALL_VALUES, ADD_ALL_VALUES, INSERT_BC_VALUES, ADD_BC_VALUES */
  /*  */
  /*  MatAssemblyType: MAT_FINAL_ASSEMBLY, MAT_FLUSH_ASSEMBLY */
  /*  */
  /*  MatInfoType: MAT_LOCAL,MAT_GLOBAL_MAX,MAT_GLOBAL_SUM */
  /*  */
  /*  MatFactorType: MAT_FACTOR_NONE, MAT_FACTOR_LU, MAT_FACTOR_CHOLESKY,  */
  /*       MAT_FACTOR_ILU, MAT_FACTOR_ICC,MAT_FACTOR_ILUDT */
  /*  */
  /*  NormType: NORM_1, NORM_2, NORM_FROBENIUS, NORM_INFINITY, NORM_1_AND_2 */
  /*  */
  /*  Others:  PETSC_DETERMINE, PETSC_DECIDE, PETSC_DEFAULT */
  /* 'petscGetEnum:46' if isempty(coder.target) */
  /* 'petscGetEnum:50' coder.cinclude('petscsys.h'); */
  /* 'petscGetEnum:51' coder.cinclude('petscksp.h'); */
  /* % InsertMode */
  /* 'petscGetEnum:54' switch name */
  /* 'petscGetEnum:171' case 'PETSC_DEFAULT' */
  /* 'petscGetEnum:172' [val, toplevel] = get_val('PetscInt', 'PETSC_DEFAULT', nargin>1); */
  /* 'petscGetEnum:183' coder.inline('always'); */
  /* 'petscGetEnum:185' val = int32(intmin); */
  /* 'petscGetEnum:186' val = coder.ceval(' ', coder.opaque(type, name)); */
  val = (PETSC_DEFAULT);

  /*  Obtain PETSC constant PETSC_DEFAULT */
  /* 'PETSC_DEFAULT:4' coder.inline('always'); */
  /* 'PETSC_DEFAULT:6' val = petscGetEnum('PETSC_DEFAULT'); */
  /* petscGetEnum Obtain an enumerate value in PETSC */
  /*  */
  /*     val = petscGetEnum(name) */
  /*  */
  /* The supported names include: */
  /*  */
  /*  PetscBool:  PETSC_TRUE, PETSC_FALSE */
  /*  */
  /*  VecOption: VEC_IGNORE_OFF_PROC_ENTRIES, VEC_IGNORE_NEGATIVE_INDICES, */
  /*       VEC_SUBSET_OFF_PROC_ENTRIES */
  /*  */
  /*  MatOption: MAT_ROW_ORIENTED, MAT_SYMMETRIC, MAT_STRUCTURALLY_SYMMETRIC, */
  /*       MAT_NEW_DIAGONALS, MAT_IGNORE_OFF_PROC_ENTRIES, */
  /*       MAT_USE_HASH_TABLE, MAT_KEEP_NONZERO_PATTERN, */
  /*       MAT_IGNORE_ZERO_ENTRIES, MAT_USE_INODES, MAT_HERMITIAN, */
  /*       MAT_SYMMETRY_ETERNAL, MAT_NEW_NONZERO_LOCATION_ERR, */
  /*       MAT_IGNORE_LOWER_TRIANGULAR, MAT_ERROR_LOWER_TRIANGULAR, */
  /*       MAT_GETROW_UPPERTRIANGULAR, MAT_SPD, */
  /*       MAT_NO_OFF_PROC_ZERO_ROWS, MAT_NO_OFF_PROC_ENTRIES, */
  /*       MAT_NEW_NONZERO_LOCATIONS, MAT_NEW_NONZERO_ALLOCATION_ERR, */
  /*       MAT_SUBSET_OFF_PROC_ENTRIES */
  /*  */
  /*  MatStructure: DIFFERENT_NONZERO_PATTERN, SUBSET_NONZERO_PATTERN, SAME_NONZERO_PATTERN */
  /*  */
  /*  MatDuplicateOption: MAT_DO_NOT_COPY_VALUES,MAT_COPY_VALUES,MAT_SHARE_NONZERO_PATTERN */
  /*  */
  /*  MatReuse: MAT_INITIAL_MATRIX,MAT_REUSE_MATRIX,MAT_IGNORE_MATRIX,MAT_INPLACE_MATRIX */
  /*  */
  /*  InsertMode: INSERT_VALUES, ADD_VALUES, MAX_VALUES, */
  /*       INSERT_ALL_VALUES, ADD_ALL_VALUES, INSERT_BC_VALUES, ADD_BC_VALUES */
  /*  */
  /*  MatAssemblyType: MAT_FINAL_ASSEMBLY, MAT_FLUSH_ASSEMBLY */
  /*  */
  /*  MatInfoType: MAT_LOCAL,MAT_GLOBAL_MAX,MAT_GLOBAL_SUM */
  /*  */
  /*  MatFactorType: MAT_FACTOR_NONE, MAT_FACTOR_LU, MAT_FACTOR_CHOLESKY,  */
  /*       MAT_FACTOR_ILU, MAT_FACTOR_ICC,MAT_FACTOR_ILUDT */
  /*  */
  /*  NormType: NORM_1, NORM_2, NORM_FROBENIUS, NORM_INFINITY, NORM_1_AND_2 */
  /*  */
  /*  Others:  PETSC_DETERMINE, PETSC_DECIDE, PETSC_DEFAULT */
  /* 'petscGetEnum:46' if isempty(coder.target) */
  /* 'petscGetEnum:50' coder.cinclude('petscsys.h'); */
  /* 'petscGetEnum:51' coder.cinclude('petscksp.h'); */
  /* % InsertMode */
  /* 'petscGetEnum:54' switch name */
  /* 'petscGetEnum:171' case 'PETSC_DEFAULT' */
  /* 'petscGetEnum:172' [val, toplevel] = get_val('PetscInt', 'PETSC_DEFAULT', nargin>1); */
  /* 'petscGetEnum:183' coder.inline('always'); */
  /* 'petscGetEnum:185' val = int32(intmin); */
  /* 'petscGetEnum:186' val = coder.ceval(' ', coder.opaque(type, name)); */
  b_val = (PETSC_DEFAULT);

  /* Sets the iteration tolerances used by the default KSP convergence testers. */
  /*  */
  /*  Syntax: */
  /*  */
  /*   [errCode, toplevel] = petscKSPSetTolerances(ksp, rtol) */
  /*   [errCode, toplevel] = petscKSPSetTolerances(ksp, rtol, abstol, dtol, maxits) */
  /*  */
  /*  Description */
  /*  */
  /*   errCode = petscKSPSetTolerances(ksp, rtol) sets the relative tolerance */
  /*        and let PETSc decides the rest. */
  /*  */
  /*   errCode = petscKSPSetTolerances(ksp, rtol, abstol, dtol, maxits) sets  */
  /*        the relative, absolute, divergence tolerances and the max-iteration count. */
  /*  */
  /*   uses the matrix Pmat to construct the preconditioner. */
  /*  */
  /*   SEE ALSO: petscKSPGetTolerances */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode  KSPSetTolerances(KSP ksp,PetscReal rtol,PetscReal abstol,PetscReal dtol,PetscInt maxits) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPSetTolerances.html */
  /* 'petscKSPSetTolerances:28' errCode = int32(-1); */
  /* 'petscKSPSetTolerances:30' if ~isempty(coder.target) */
  /* 'petscKSPSetTolerances:31' t_ksp = PetscKSP(ksp); */
  /* Map an opaque object into a PETSc KSP object */
  /*  */
  /*   ksp = PetscKSP() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   ksp = PetscKSP(arg) or ksp = PetscKSP(arg, false) converts arg */
  /*   into a PETSc KSP object. */
  /*  */
  /*   ksp = PetscKSP(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscPC */
  /* 'PetscKSP:18' coder.inline('always'); */
  /* 'PetscKSP:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscKSP:25' if isstruct(arg) && ~isequal(arg.type, 'KSP') */
  /* 'PetscKSP:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscKSP:31' if nargin==1 || ~opaque */
  /* 'PetscKSP:32' ksp = arg; */
  /* 'petscKSPSetTolerances:33' if nargin==2 */
  /* 'petscKSPSetTolerances:39' errCode = coder.ceval('KSPSetTolerances', t_ksp, rtol, abstol, dtol, maxits); */
  errCode = KSPSetTolerances(ksp, rtol, (double)val, (double)b_val, maxits);

  /* 'petscKSPSetTolerances:41' toplevel = nargout>1; */
  /* 'petscKSPSetTolerances:42' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    *flag = (M2C_DEBUG);
    if (*flag != 0) {
      /* 'petscKSPSetTolerances:43' m2c_error('petsc:RuntimeError', 'KSPSetTolerances returned error code %d\n', errCode) */
      o_m2c_error(errCode);
    }
  }

  /*  Process initial guess */
  /* 'mptKSPSolve:60' if nargin>=6 && ~petscIsNULL(x0) */
  /*  Determine whether a given object is a null opointer of a particular type. */
  /*  */
  /*     isn = petscIsNULL(obj) */
  /* 'petscIsNULL:6' if ischar(obj) */
  /* 'petscIsNULL:8' elseif ~isstruct(obj) */
  /* 'petscIsNULL:9' isn = int32(0); */
  /* 'petscIsNULL:10' isn = coder.ceval('!', obj); */
  val = !(x0);
  if (!(val != 0)) {
    /* 'mptKSPSolve:61' petscVecCopy(x0, x); */
    /* Creates a vector from x to y. */
    /*  */
    /*   errCode = petscVecCopy(x, y) copies the entries from x to y. Both */
    /*   x and y must be distributed in the same manner; local copies are done. */
    /*  */
    /*   SEE ALSO: petscVecDuplicate */
    /*  */
    /*  PETSc C interface: */
    /*    PetscErrorCode  VecCopy(Vec x, Vec y) */
    /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecCopy.html */
    /* 'petscVecCopy:15' errCode = int32(-1); */
    /* 'petscVecCopy:17' if ~isempty(coder.target) */
    /* 'petscVecCopy:18' errCode = coder.ceval('VecCopy', PetscVec(x), PetscVec(y)); */
    /* Map an opaque object into a PETSc Vec object */
    /*  */
    /*   vec = PetscVec() simply returns a definition of the */
    /*   m2c_opaque_type definition, suitable in the argument */
    /*   specification for codegen. */
    /*  */
    /*   vec = PetscVec(arg) or vec = PetscVec(arg, false) converts arg */
    /*   into a PETSc Vec object. */
    /*  */
    /*   vec = PetscVec(arg, true) wraps the arg into an opaque object.  */
    /*   This should be used if the object needs to be returned to */
    /*   MATLAB. Note that the value of opaque must be determined at */
    /*   compile time. */
    /*  */
    /*  See also PetscMat */
    /* 'PetscVec:18' coder.inline('always'); */
    /* 'PetscVec:20' if nargin==0 && isempty(coder.target) */
    /* 'PetscVec:25' if isstruct(arg) && ~isequal(arg.type, 'Vec') */
    /* 'PetscVec:30' if ~isstruct(arg) || isempty(coder.target) */
    /* 'PetscVec:31' if nargin==1 || ~opaque */
    /* 'PetscVec:32' vec = arg; */
    /* Map an opaque object into a PETSc Vec object */
    /*  */
    /*   vec = PetscVec() simply returns a definition of the */
    /*   m2c_opaque_type definition, suitable in the argument */
    /*   specification for codegen. */
    /*  */
    /*   vec = PetscVec(arg) or vec = PetscVec(arg, false) converts arg */
    /*   into a PETSc Vec object. */
    /*  */
    /*   vec = PetscVec(arg, true) wraps the arg into an opaque object.  */
    /*   This should be used if the object needs to be returned to */
    /*   MATLAB. Note that the value of opaque must be determined at */
    /*   compile time. */
    /*  */
    /*  See also PetscMat */
    /* 'PetscVec:18' coder.inline('always'); */
    /* 'PetscVec:20' if nargin==0 && isempty(coder.target) */
    /* 'PetscVec:25' if isstruct(arg) && ~isequal(arg.type, 'Vec') */
    /* 'PetscVec:30' if ~isstruct(arg) || isempty(coder.target) */
    /* 'PetscVec:31' if nargin==1 || ~opaque */
    /* 'PetscVec:32' vec = arg; */
    errCode = VecCopy(x0, x);

    /* 'petscVecCopy:20' toplevel = nargout>2; */
    /* 'petscVecCopy:21' if errCode && (toplevel || m2c_debug) */
    if (errCode != 0) {
      /* Flag indicating whether m2c_debug is on. */
      /* It is always true within MATLAB. In the generated C code, it is */
      /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
      /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
      /* 'm2c_debug:7' coder.inline('always'); */
      /* 'm2c_debug:9' if isempty(coder.target) */
      /* 'm2c_debug:11' else */
      /* 'm2c_debug:12' flag = int32(1); */
      /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
      *flag = (M2C_DEBUG);
      if (*flag != 0) {
        /* 'petscVecCopy:22' m2c_error('petsc:RuntimeError', 'VecCopy returned error code %d\n', errCode) */
        p_m2c_error(errCode);
      }
    }

    /* 'mptKSPSolve:62' petscKSPSetInitialGuessNonzero(t_ksp, PETSC_TRUE); */
    /*  Obtain PETSC constant PETSC_TRUE */
    /* 'PETSC_TRUE:4' coder.inline('always'); */
    /* 'PETSC_TRUE:6' val = petscGetEnum('PETSC_TRUE'); */
    /* petscGetEnum Obtain an enumerate value in PETSC */
    /*  */
    /*     val = petscGetEnum(name) */
    /*  */
    /* The supported names include: */
    /*  */
    /*  PetscBool:  PETSC_TRUE, PETSC_FALSE */
    /*  */
    /*  VecOption: VEC_IGNORE_OFF_PROC_ENTRIES, VEC_IGNORE_NEGATIVE_INDICES, */
    /*       VEC_SUBSET_OFF_PROC_ENTRIES */
    /*  */
    /*  MatOption: MAT_ROW_ORIENTED, MAT_SYMMETRIC, MAT_STRUCTURALLY_SYMMETRIC, */
    /*       MAT_NEW_DIAGONALS, MAT_IGNORE_OFF_PROC_ENTRIES, */
    /*       MAT_USE_HASH_TABLE, MAT_KEEP_NONZERO_PATTERN, */
    /*       MAT_IGNORE_ZERO_ENTRIES, MAT_USE_INODES, MAT_HERMITIAN, */
    /*       MAT_SYMMETRY_ETERNAL, MAT_NEW_NONZERO_LOCATION_ERR, */
    /*       MAT_IGNORE_LOWER_TRIANGULAR, MAT_ERROR_LOWER_TRIANGULAR, */
    /*       MAT_GETROW_UPPERTRIANGULAR, MAT_SPD, */
    /*       MAT_NO_OFF_PROC_ZERO_ROWS, MAT_NO_OFF_PROC_ENTRIES, */
    /*       MAT_NEW_NONZERO_LOCATIONS, MAT_NEW_NONZERO_ALLOCATION_ERR, */
    /*       MAT_SUBSET_OFF_PROC_ENTRIES */
    /*  */
    /*  MatStructure: DIFFERENT_NONZERO_PATTERN, SUBSET_NONZERO_PATTERN, SAME_NONZERO_PATTERN */
    /*  */
    /*  MatDuplicateOption: MAT_DO_NOT_COPY_VALUES,MAT_COPY_VALUES,MAT_SHARE_NONZERO_PATTERN */
    /*  */
    /*  MatReuse: MAT_INITIAL_MATRIX,MAT_REUSE_MATRIX,MAT_IGNORE_MATRIX,MAT_INPLACE_MATRIX */
    /*  */
    /*  InsertMode: INSERT_VALUES, ADD_VALUES, MAX_VALUES, */
    /*       INSERT_ALL_VALUES, ADD_ALL_VALUES, INSERT_BC_VALUES, ADD_BC_VALUES */
    /*  */
    /*  MatAssemblyType: MAT_FINAL_ASSEMBLY, MAT_FLUSH_ASSEMBLY */
    /*  */
    /*  MatInfoType: MAT_LOCAL,MAT_GLOBAL_MAX,MAT_GLOBAL_SUM */
    /*  */
    /*  MatFactorType: MAT_FACTOR_NONE, MAT_FACTOR_LU, MAT_FACTOR_CHOLESKY,  */
    /*       MAT_FACTOR_ILU, MAT_FACTOR_ICC,MAT_FACTOR_ILUDT */
    /*  */
    /*  NormType: NORM_1, NORM_2, NORM_FROBENIUS, NORM_INFINITY, NORM_1_AND_2 */
    /*  */
    /*  Others:  PETSC_DETERMINE, PETSC_DECIDE, PETSC_DEFAULT */
    /* 'petscGetEnum:46' if isempty(coder.target) */
    /* 'petscGetEnum:50' coder.cinclude('petscsys.h'); */
    /* 'petscGetEnum:51' coder.cinclude('petscksp.h'); */
    /* % InsertMode */
    /* 'petscGetEnum:54' switch name */
    /* 'petscGetEnum:55' case 'PETSC_TRUE' */
    /* 'petscGetEnum:56' [val, toplevel] = get_val('PetscBool', 'PETSC_TRUE', nargin>1); */
    /* 'petscGetEnum:183' coder.inline('always'); */
    /* 'petscGetEnum:185' val = int32(intmin); */
    /* 'petscGetEnum:186' val = coder.ceval(' ', coder.opaque(type, name)); */
    val = (PETSC_TRUE);

    /* Tells the iterative solver that the initial guess is nonzero; otherwise  */
    /* KSP assumes the initial guess is to be zero (and thus zeros it out before solving). */
    /*  */
    /*   errCode = petscKSPSetInitialGuessNonzero(ksp, flag) */
    /*   indicates the initial guess is non-zero if flag is PETSC_TRUE, and */
    /*   is zeo if flag is PETSC_FALSE (0). */
    /*  */
    /*   SEE ALSO: petscKSPGetInitialGuessNonzero */
    /*  */
    /*  PETSc C interface: */
    /*    PetscErrorCode  KSPSetInitialGuessNonzero(KSP ksp,PetscBool flg) */
    /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPSetInitialGuessNonzero.html */
    /* 'petscKSPSetInitialGuessNonzero:17' errCode = int32(-1); */
    /* 'petscKSPSetInitialGuessNonzero:19' if ~isempty(coder.target) */
    /* 'petscKSPSetInitialGuessNonzero:20' t_ksp = PetscKSP(ksp); */
    /* Map an opaque object into a PETSc KSP object */
    /*  */
    /*   ksp = PetscKSP() simply returns a definition of the */
    /*   m2c_opaque_type definition, suitable in the argument */
    /*   specification for codegen. */
    /*  */
    /*   ksp = PetscKSP(arg) or ksp = PetscKSP(arg, false) converts arg */
    /*   into a PETSc KSP object. */
    /*  */
    /*   ksp = PetscKSP(arg, true) wraps the arg into an opaque object.  */
    /*   This should be used if the object needs to be returned to */
    /*   MATLAB. Note that the value of opaque must be determined at */
    /*   compile time. */
    /*  */
    /*  See also PetscPC */
    /* 'PetscKSP:18' coder.inline('always'); */
    /* 'PetscKSP:20' if nargin==0 && isempty(coder.target) */
    /* 'PetscKSP:25' if isstruct(arg) && ~isequal(arg.type, 'KSP') */
    /* 'PetscKSP:30' if ~isstruct(arg) || isempty(coder.target) */
    /* 'PetscKSP:31' if nargin==1 || ~opaque */
    /* 'PetscKSP:32' ksp = arg; */
    /* 'petscKSPSetInitialGuessNonzero:22' errCode = coder.ceval('KSPSetInitialGuessNonzero', t_ksp, flag); */
    errCode = KSPSetInitialGuessNonzero(ksp, val);

    /* 'petscKSPSetInitialGuessNonzero:24' toplevel = nargout>1; */
    /* 'petscKSPSetInitialGuessNonzero:25' if errCode && (toplevel || m2c_debug) */
    if (errCode != 0) {
      /* Flag indicating whether m2c_debug is on. */
      /* It is always true within MATLAB. In the generated C code, it is */
      /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
      /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
      /* 'm2c_debug:7' coder.inline('always'); */
      /* 'm2c_debug:9' if isempty(coder.target) */
      /* 'm2c_debug:11' else */
      /* 'm2c_debug:12' flag = int32(1); */
      /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
      *flag = (M2C_DEBUG);
      if (*flag != 0) {
        /* 'petscKSPSetInitialGuessNonzero:26' m2c_error('petsc:RuntimeError', 'KSPSetInitialGuessNonzero returned error code %d\n', errCode) */
        q_m2c_error(errCode);
      }
    }
  } else {
    /* 'mptKSPSolve:63' else */
    /* 'mptKSPSolve:64' petscKSPSetInitialGuessNonzero(t_ksp, PETSC_FALSE); */
    /*  Obtain PETSC constant PETSC_FALSE */
    /* 'PETSC_FALSE:4' coder.inline('always'); */
    /* 'PETSC_FALSE:6' val = petscGetEnum('PETSC_FALSE'); */
    /* petscGetEnum Obtain an enumerate value in PETSC */
    /*  */
    /*     val = petscGetEnum(name) */
    /*  */
    /* The supported names include: */
    /*  */
    /*  PetscBool:  PETSC_TRUE, PETSC_FALSE */
    /*  */
    /*  VecOption: VEC_IGNORE_OFF_PROC_ENTRIES, VEC_IGNORE_NEGATIVE_INDICES, */
    /*       VEC_SUBSET_OFF_PROC_ENTRIES */
    /*  */
    /*  MatOption: MAT_ROW_ORIENTED, MAT_SYMMETRIC, MAT_STRUCTURALLY_SYMMETRIC, */
    /*       MAT_NEW_DIAGONALS, MAT_IGNORE_OFF_PROC_ENTRIES, */
    /*       MAT_USE_HASH_TABLE, MAT_KEEP_NONZERO_PATTERN, */
    /*       MAT_IGNORE_ZERO_ENTRIES, MAT_USE_INODES, MAT_HERMITIAN, */
    /*       MAT_SYMMETRY_ETERNAL, MAT_NEW_NONZERO_LOCATION_ERR, */
    /*       MAT_IGNORE_LOWER_TRIANGULAR, MAT_ERROR_LOWER_TRIANGULAR, */
    /*       MAT_GETROW_UPPERTRIANGULAR, MAT_SPD, */
    /*       MAT_NO_OFF_PROC_ZERO_ROWS, MAT_NO_OFF_PROC_ENTRIES, */
    /*       MAT_NEW_NONZERO_LOCATIONS, MAT_NEW_NONZERO_ALLOCATION_ERR, */
    /*       MAT_SUBSET_OFF_PROC_ENTRIES */
    /*  */
    /*  MatStructure: DIFFERENT_NONZERO_PATTERN, SUBSET_NONZERO_PATTERN, SAME_NONZERO_PATTERN */
    /*  */
    /*  MatDuplicateOption: MAT_DO_NOT_COPY_VALUES,MAT_COPY_VALUES,MAT_SHARE_NONZERO_PATTERN */
    /*  */
    /*  MatReuse: MAT_INITIAL_MATRIX,MAT_REUSE_MATRIX,MAT_IGNORE_MATRIX,MAT_INPLACE_MATRIX */
    /*  */
    /*  InsertMode: INSERT_VALUES, ADD_VALUES, MAX_VALUES, */
    /*       INSERT_ALL_VALUES, ADD_ALL_VALUES, INSERT_BC_VALUES, ADD_BC_VALUES */
    /*  */
    /*  MatAssemblyType: MAT_FINAL_ASSEMBLY, MAT_FLUSH_ASSEMBLY */
    /*  */
    /*  MatInfoType: MAT_LOCAL,MAT_GLOBAL_MAX,MAT_GLOBAL_SUM */
    /*  */
    /*  MatFactorType: MAT_FACTOR_NONE, MAT_FACTOR_LU, MAT_FACTOR_CHOLESKY,  */
    /*       MAT_FACTOR_ILU, MAT_FACTOR_ICC,MAT_FACTOR_ILUDT */
    /*  */
    /*  NormType: NORM_1, NORM_2, NORM_FROBENIUS, NORM_INFINITY, NORM_1_AND_2 */
    /*  */
    /*  Others:  PETSC_DETERMINE, PETSC_DECIDE, PETSC_DEFAULT */
    /* 'petscGetEnum:46' if isempty(coder.target) */
    /* 'petscGetEnum:50' coder.cinclude('petscsys.h'); */
    /* 'petscGetEnum:51' coder.cinclude('petscksp.h'); */
    /* % InsertMode */
    /* 'petscGetEnum:54' switch name */
    /* 'petscGetEnum:57' case 'PETSC_FALSE' */
    /* 'petscGetEnum:58' [val, toplevel] = get_val('PetscBool', 'PETSC_FALSE', nargin>1); */
    /* 'petscGetEnum:183' coder.inline('always'); */
    /* 'petscGetEnum:185' val = int32(intmin); */
    /* 'petscGetEnum:186' val = coder.ceval(' ', coder.opaque(type, name)); */
    val = (PETSC_FALSE);

    /* Tells the iterative solver that the initial guess is nonzero; otherwise  */
    /* KSP assumes the initial guess is to be zero (and thus zeros it out before solving). */
    /*  */
    /*   errCode = petscKSPSetInitialGuessNonzero(ksp, flag) */
    /*   indicates the initial guess is non-zero if flag is PETSC_TRUE, and */
    /*   is zeo if flag is PETSC_FALSE (0). */
    /*  */
    /*   SEE ALSO: petscKSPGetInitialGuessNonzero */
    /*  */
    /*  PETSc C interface: */
    /*    PetscErrorCode  KSPSetInitialGuessNonzero(KSP ksp,PetscBool flg) */
    /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPSetInitialGuessNonzero.html */
    /* 'petscKSPSetInitialGuessNonzero:17' errCode = int32(-1); */
    /* 'petscKSPSetInitialGuessNonzero:19' if ~isempty(coder.target) */
    /* 'petscKSPSetInitialGuessNonzero:20' t_ksp = PetscKSP(ksp); */
    /* Map an opaque object into a PETSc KSP object */
    /*  */
    /*   ksp = PetscKSP() simply returns a definition of the */
    /*   m2c_opaque_type definition, suitable in the argument */
    /*   specification for codegen. */
    /*  */
    /*   ksp = PetscKSP(arg) or ksp = PetscKSP(arg, false) converts arg */
    /*   into a PETSc KSP object. */
    /*  */
    /*   ksp = PetscKSP(arg, true) wraps the arg into an opaque object.  */
    /*   This should be used if the object needs to be returned to */
    /*   MATLAB. Note that the value of opaque must be determined at */
    /*   compile time. */
    /*  */
    /*  See also PetscPC */
    /* 'PetscKSP:18' coder.inline('always'); */
    /* 'PetscKSP:20' if nargin==0 && isempty(coder.target) */
    /* 'PetscKSP:25' if isstruct(arg) && ~isequal(arg.type, 'KSP') */
    /* 'PetscKSP:30' if ~isstruct(arg) || isempty(coder.target) */
    /* 'PetscKSP:31' if nargin==1 || ~opaque */
    /* 'PetscKSP:32' ksp = arg; */
    /* 'petscKSPSetInitialGuessNonzero:22' errCode = coder.ceval('KSPSetInitialGuessNonzero', t_ksp, flag); */
    errCode = KSPSetInitialGuessNonzero(ksp, val);

    /* 'petscKSPSetInitialGuessNonzero:24' toplevel = nargout>1; */
    /* 'petscKSPSetInitialGuessNonzero:25' if errCode && (toplevel || m2c_debug) */
    if (errCode != 0) {
      /* Flag indicating whether m2c_debug is on. */
      /* It is always true within MATLAB. In the generated C code, it is */
      /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
      /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
      /* 'm2c_debug:7' coder.inline('always'); */
      /* 'm2c_debug:9' if isempty(coder.target) */
      /* 'm2c_debug:11' else */
      /* 'm2c_debug:12' flag = int32(1); */
      /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
      *flag = (M2C_DEBUG);
      if (*flag != 0) {
        /* 'petscKSPSetInitialGuessNonzero:26' m2c_error('petsc:RuntimeError', 'KSPSetInitialGuessNonzero returned error code %d\n', errCode) */
        q_m2c_error(errCode);
      }
    }
  }

  /* 'mptKSPSolve:67' petscKSPSolve(t_ksp, b, x); */
  /* Solves linear system. */
  /*  */
  /*   errCode = petscKSPSolve(ksp, b) */
  /*  */
  /*   solves the linear system with b as the RHS and saves the solution into b. */
  /*      ksp - iterative context obtained from petscKSPCreate() */
  /*      b	  - the right hand side vector */
  /*  */
  /*   errCode = petscKSPSolve(ksp, b, x) */
  /*  */
  /*   solves the linear system and saves the solution into vector x. */
  /*  */
  /*   SEE ALSO: petscKSPCreate, petscKSPSetOperators, petscKSPSetUp, petscKSPDestroy */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode KSPSolve(KSP ksp,Vec b,Vec x) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPSolve.html */
  /* 'petscKSPSolve:23' errCode = int32(-1); */
  /* 'petscKSPSolve:25' if ~isempty(coder.target) */
  /* 'petscKSPSolve:26' t_ksp = PetscKSP(ksp); */
  /* Map an opaque object into a PETSc KSP object */
  /*  */
  /*   ksp = PetscKSP() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   ksp = PetscKSP(arg) or ksp = PetscKSP(arg, false) converts arg */
  /*   into a PETSc KSP object. */
  /*  */
  /*   ksp = PetscKSP(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscPC */
  /* 'PetscKSP:18' coder.inline('always'); */
  /* 'PetscKSP:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscKSP:25' if isstruct(arg) && ~isequal(arg.type, 'KSP') */
  /* 'PetscKSP:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscKSP:31' if nargin==1 || ~opaque */
  /* 'PetscKSP:32' ksp = arg; */
  /* 'petscKSPSolve:27' t_b = PetscVec(b); */
  /* Map an opaque object into a PETSc Vec object */
  /*  */
  /*   vec = PetscVec() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   vec = PetscVec(arg) or vec = PetscVec(arg, false) converts arg */
  /*   into a PETSc Vec object. */
  /*  */
  /*   vec = PetscVec(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscVec:18' coder.inline('always'); */
  /* 'PetscVec:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscVec:25' if isstruct(arg) && ~isequal(arg.type, 'Vec') */
  /* 'PetscVec:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscVec:31' if nargin==1 || ~opaque */
  /* 'PetscVec:32' vec = arg; */
  /* 'petscKSPSolve:29' if nargin==2 */
  /* 'petscKSPSolve:31' else */
  /* 'petscKSPSolve:32' t_x = PetscVec(x); */
  /* Map an opaque object into a PETSc Vec object */
  /*  */
  /*   vec = PetscVec() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   vec = PetscVec(arg) or vec = PetscVec(arg, false) converts arg */
  /*   into a PETSc Vec object. */
  /*  */
  /*   vec = PetscVec(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscVec:18' coder.inline('always'); */
  /* 'PetscVec:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscVec:25' if isstruct(arg) && ~isequal(arg.type, 'Vec') */
  /* 'PetscVec:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscVec:31' if nargin==1 || ~opaque */
  /* 'PetscVec:32' vec = arg; */
  /* 'petscKSPSolve:35' errCode = coder.ceval('KSPSolve', t_ksp, t_b, t_x); */
  errCode = KSPSolve(ksp, b, x);

  /* 'petscKSPSolve:37' toplevel = nargout>1; */
  /* 'petscKSPSolve:38' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    *flag = (M2C_DEBUG);
    if (*flag != 0) {
      /* 'petscKSPSolve:39' m2c_error('petsc:RuntimeError', 'KSPSolve returned error code %d\n', errCode) */
      r_m2c_error(errCode);
    }
  }

  /* 'mptKSPSolve:70' if nargout>3 */
  /* 'mptKSPSolve:70' time=m2c_wtime()-t; */
  /*  Return ellapsed time */
  /*    t = m2c_wtime */
  /* 'm2c_wtime:7' if isempty(coder.target) */
  /* 'm2c_wtime:10' else */
  /* 'm2c_wtime:11' coder.inline( 'always'); */
  /* 'm2c_wtime:13' t = 0; */
  /* 'm2c_wtime:13' t = coder.ceval( 'M2C_wtime'); */
  b_t = M2C_wtime();
  *time = b_t - t;

  /* 'mptKSPSolve:72' flag = petscKSPGetConvergedReason(t_ksp); */
  /* Gets the reason the KSP iteration was stopped. */
  /*  */
  /*   [flag, errCode] = petscKSPGetConvergedReason(ksp) */
  /*  */
  /*   SEE ALSO: KSPGetResidualNorm, petscKSPGetIterationNumber */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode  KSPGetConvergedReason(KSP ksp,KSPConvergedReason *reason) */
  /*  http://www.mcs.anl.gov/petsc/petsc-3.7/docs/manualpages/KSP/KSPGetConvergedReason.html */
  /* 'petscKSPGetConvergedReason:14' errCode = int32(-1); */
  /* 'petscKSPGetConvergedReason:16' if ~isempty(coder.target) */
  /* 'petscKSPGetConvergedReason:17' t_ksp = PetscKSP(ksp); */
  /* Map an opaque object into a PETSc KSP object */
  /*  */
  /*   ksp = PetscKSP() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   ksp = PetscKSP(arg) or ksp = PetscKSP(arg, false) converts arg */
  /*   into a PETSc KSP object. */
  /*  */
  /*   ksp = PetscKSP(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscPC */
  /* 'PetscKSP:18' coder.inline('always'); */
  /* 'PetscKSP:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscKSP:25' if isstruct(arg) && ~isequal(arg.type, 'KSP') */
  /* 'PetscKSP:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscKSP:31' if nargin==1 || ~opaque */
  /* 'PetscKSP:32' ksp = arg; */
  /* 'petscKSPGetConvergedReason:19' flag = int32(0); */
  /* 'petscKSPGetConvergedReason:20' errCode = coder.ceval('KSPGetConvergedReason', t_ksp, coder.wref(flag)); */
  errCode = KSPGetConvergedReason(ksp, flag);

  /* 'petscKSPGetConvergedReason:22' toplevel = nargout>2; */
  /* 'petscKSPGetConvergedReason:23' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    val = (M2C_DEBUG);
    if (val != 0) {
      /* 'petscKSPGetConvergedReason:24' m2c_error('petsc:RuntimeError', 'KSPGetConvergedReason returned error code %d\n', errCode) */
      s_m2c_error(errCode);
    }
  }

  /* 'mptKSPSolve:73' relres = petscKSPGetResidualNorm(t_ksp); */
  /* Gets the last (approximate preconditioned) residual norm that has been computed. */
  /*  */
  /*   [rnorm, errCode] = petscKSPGetResidualNorm(ksp) */
  /*  */
  /*   SEE ALSO: KSPGetResidualNorm, petscKSPGetIterationNumber */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode  KSPGetResidualNorm(KSP ksp,PetscInt *rnorm) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPGetResidualNorm.html */
  /* 'petscKSPGetResidualNorm:14' errCode = int32(-1); */
  /* 'petscKSPGetResidualNorm:16' if ~isempty(coder.target) */
  /* 'petscKSPGetResidualNorm:17' t_ksp = PetscKSP(ksp); */
  /* Map an opaque object into a PETSc KSP object */
  /*  */
  /*   ksp = PetscKSP() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   ksp = PetscKSP(arg) or ksp = PetscKSP(arg, false) converts arg */
  /*   into a PETSc KSP object. */
  /*  */
  /*   ksp = PetscKSP(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscPC */
  /* 'PetscKSP:18' coder.inline('always'); */
  /* 'PetscKSP:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscKSP:25' if isstruct(arg) && ~isequal(arg.type, 'KSP') */
  /* 'PetscKSP:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscKSP:31' if nargin==1 || ~opaque */
  /* 'PetscKSP:32' ksp = arg; */
  /* 'petscKSPGetResidualNorm:19' rnorm = 0; */
  /* 'petscKSPGetResidualNorm:20' errCode = coder.ceval('KSPGetResidualNorm', t_ksp, coder.wref(rnorm)); */
  errCode = KSPGetResidualNorm(ksp, relres);

  /* 'petscKSPGetResidualNorm:22' toplevel = nargout>2; */
  /* 'petscKSPGetResidualNorm:23' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    val = (M2C_DEBUG);
    if (val != 0) {
      /* 'petscKSPGetResidualNorm:24' m2c_error('petsc:RuntimeError', 'KSPGetResidualNorm returned error code %d\n', errCode) */
      t_m2c_error(errCode);
    }
  }

  /* 'mptKSPSolve:74' iter = petscKSPGetIterationNumber(t_ksp); */
  /* Gets the current iteration number. */
  /*  */
  /*   [its, errCode] = petscKSPGetIterationNumber(ksp) */
  /*  */
  /*   gets the current iteration number; if the KSPSolve() is complete,  */
  /*   returns the number of iterations used.  */
  /*  */
  /*   SEE ALSO: petscKSPGetConvergedReason, KSPGetResidualNorm, petscKSPGetTotalIterations */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode  KSPGetIterationNumber(KSP ksp,PetscInt *its) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPGetIterationNumber.html */
  /* 'petscKSPGetIterationNumber:17' errCode = int32(-1); */
  /* 'petscKSPGetIterationNumber:19' if ~isempty(coder.target) */
  /* 'petscKSPGetIterationNumber:20' t_ksp = PetscKSP(ksp); */
  /* Map an opaque object into a PETSc KSP object */
  /*  */
  /*   ksp = PetscKSP() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   ksp = PetscKSP(arg) or ksp = PetscKSP(arg, false) converts arg */
  /*   into a PETSc KSP object. */
  /*  */
  /*   ksp = PetscKSP(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscPC */
  /* 'PetscKSP:18' coder.inline('always'); */
  /* 'PetscKSP:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscKSP:25' if isstruct(arg) && ~isequal(arg.type, 'KSP') */
  /* 'PetscKSP:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscKSP:31' if nargin==1 || ~opaque */
  /* 'PetscKSP:32' ksp = arg; */
  /* 'petscKSPGetIterationNumber:22' its = int32(0); */
  /* 'petscKSPGetIterationNumber:23' errCode = coder.ceval('KSPGetIterationNumber', t_ksp, coder.wref(its)); */
  errCode = KSPGetIterationNumber(ksp, iter);

  /* 'petscKSPGetIterationNumber:25' toplevel = nargout>2; */
  /* 'petscKSPGetIterationNumber:26' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    val = (M2C_DEBUG);
    if (val != 0) {
      /* 'petscKSPGetIterationNumber:27' m2c_error('petsc:RuntimeError', 'KSPGetIterationNumber returned error code %d\n', errCode) */
      u_m2c_error(errCode);
    }
  }

  /* 'mptKSPSolve:75' [rtol, abstol, dtol, maxits] = petscKSPGetTolerances(t_ksp); */
  /* Gets the relative, absolute, divergence, and maximum iteration tolerances */
  /* used by the default KSP convergence tests. */
  /*  */
  /*  Syntax: */
  /*  */
  /*   [rtol, arg2, dtol, maxits, errCode, toplevel] = petscKSPGetTolerances(ksp) */
  /*   obtains the relative, absolute, divergence tolerances and the max-iteration count. */
  /*  */
  /*   SEE ALSO: petscKSPSetTolerances */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode  KSPGetTolerances(KSP ksp,PetscReal *rtol,PetscReal *abstol,PetscReal *dtol,PetscInt *maxits) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPGetTolerances.html */
  /* 'petscKSPGetTolerances:18' errCode = int32(-1); */
  /* 'petscKSPGetTolerances:20' if ~isempty(coder.target) */
  /* 'petscKSPGetTolerances:21' t_ksp = PetscKSP(ksp); */
  /* Map an opaque object into a PETSc KSP object */
  /*  */
  /*   ksp = PetscKSP() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   ksp = PetscKSP(arg) or ksp = PetscKSP(arg, false) converts arg */
  /*   into a PETSc KSP object. */
  /*  */
  /*   ksp = PetscKSP(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscPC */
  /* 'PetscKSP:18' coder.inline('always'); */
  /* 'PetscKSP:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscKSP:25' if isstruct(arg) && ~isequal(arg.type, 'KSP') */
  /* 'PetscKSP:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscKSP:31' if nargin==1 || ~opaque */
  /* 'PetscKSP:32' ksp = arg; */
  /* 'petscKSPGetTolerances:23' rtol = double(0); */
  /* 'petscKSPGetTolerances:24' abstol = double(0); */
  /* 'petscKSPGetTolerances:25' dtol = double(0); */
  /* 'petscKSPGetTolerances:26' maxits = int32(0); */
  /* 'petscKSPGetTolerances:28' errCode = coder.ceval('KSPGetTolerances', t_ksp, coder.wref(rtol), ... */
  /* 'petscKSPGetTolerances:29'         coder.wref(abstol), coder.wref(dtol), coder.wref(maxits)); */
  errCode = KSPGetTolerances(ksp, &b_rtol, &abstol, &dtol, &b_maxits);

  /* 'petscKSPGetTolerances:31' toplevel = nargout>5; */
  /* 'petscKSPGetTolerances:32' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    val = (M2C_DEBUG);
    if (val != 0) {
      /* 'petscKSPGetTolerances:33' m2c_error('petsc:RuntimeError', 'KSPGetTolerances returned error code %d\n', errCode) */
      v_m2c_error(errCode);
    }
  }

  /* 'mptKSPSolve:77' if flag < 0 || relres>rtol */
  if ((*flag < 0) || (*relres > b_rtol)) {
    /* 'mptKSPSolve:78' pc = petscKSPGetPC(t_ksp); */
    /* Returns a pointer to the preconditioner context set with petscKSPSetPC. */
    /*  */
    /*   [pc, errCode] = petscKSPGetPC(ksp, pc) gets the PC of the KSP */
    /*  */
    /*   SEE ALSO:  petscKSPSetPC */
    /*  */
    /*  PETSc C interface: */
    /*    PetscErrorCode  KSPGetPC(KSP ksp,PC *pc) */
    /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPGetPC.html */
    /* 'petscKSPGetPC:14' errCode = int32(-1); */
    /* 'petscKSPGetPC:16' if ~isempty(coder.target) */
    /* 'petscKSPGetPC:17' t_pc = coder.opaque('PC'); */
    /* 'petscKSPGetPC:18' errCode = coder.ceval('KSPGetPC', PetscKSP(ksp), coder.wref(t_pc)); */
    /* Map an opaque object into a PETSc KSP object */
    /*  */
    /*   ksp = PetscKSP() simply returns a definition of the */
    /*   m2c_opaque_type definition, suitable in the argument */
    /*   specification for codegen. */
    /*  */
    /*   ksp = PetscKSP(arg) or ksp = PetscKSP(arg, false) converts arg */
    /*   into a PETSc KSP object. */
    /*  */
    /*   ksp = PetscKSP(arg, true) wraps the arg into an opaque object.  */
    /*   This should be used if the object needs to be returned to */
    /*   MATLAB. Note that the value of opaque must be determined at */
    /*   compile time. */
    /*  */
    /*  See also PetscPC */
    /* 'PetscKSP:18' coder.inline('always'); */
    /* 'PetscKSP:20' if nargin==0 && isempty(coder.target) */
    /* 'PetscKSP:25' if isstruct(arg) && ~isequal(arg.type, 'KSP') */
    /* 'PetscKSP:30' if ~isstruct(arg) || isempty(coder.target) */
    /* 'PetscKSP:31' if nargin==1 || ~opaque */
    /* 'PetscKSP:32' ksp = arg; */
    errCode = KSPGetPC(ksp, &t_pc);

    /* 'petscKSPGetPC:20' toplevel = nargout>2; */
    /* 'petscKSPGetPC:21' pc = PetscPC(t_pc, toplevel); */
    /* Map an opaque object into a PETSc PC object */
    /*  */
    /*   pc = PetscPC() simply returns a definition of the */
    /*   m2c_opaque_type definition, suitable in the argument */
    /*   specification for codegen. */
    /*  */
    /*   pc = PetscPC(arg) or pc = PetscPC(arg, false) converts arg */
    /*   into a PETSc PC object. */
    /*  */
    /*   pc = PetscPC(arg, true) wraps the arg into an opaque object.  */
    /*   This should be used if the object needs to be returned to */
    /*   MATLAB. Note that the value of opaque must be determined at */
    /*   compile time. */
    /*  */
    /*  See also PetscKSP */
    /* 'PetscPC:18' coder.inline('always'); */
    /* 'PetscPC:20' if nargin==0 && isempty(coder.target) */
    /* 'PetscPC:25' if isstruct(arg) && ~isequal(arg.type, 'PC') */
    /* 'PetscPC:30' if ~isstruct(arg) || isempty(coder.target) */
    /* 'PetscPC:31' if nargin==1 || ~opaque */
    /* 'PetscPC:32' pc = arg; */
    /* 'petscKSPGetPC:23' if errCode && (toplevel || m2c_debug) */
    if (errCode != 0) {
      /* Flag indicating whether m2c_debug is on. */
      /* It is always true within MATLAB. In the generated C code, it is */
      /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
      /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
      /* 'm2c_debug:7' coder.inline('always'); */
      /* 'm2c_debug:9' if isempty(coder.target) */
      /* 'm2c_debug:11' else */
      /* 'm2c_debug:12' flag = int32(1); */
      /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
      val = (M2C_DEBUG);
      if (val != 0) {
        /* 'petscKSPGetPC:24' m2c_error('petsc:RuntimeError', 'KSPGetPC returned error code %d\n', errCode) */
        w_m2c_error(errCode);
      }
    }

    /* 'mptKSPSolve:80' m2c_printf('### %s with %s preconditioner stopped with flag %d.\n', petscKSPGetType(t_ksp), petscPCGetType(pc), flag); */
    /* Gets the KSP type as a KSPType object from the KSP object. */
    /*  */
    /*   [type, errCode] = petscKSPGetType(ksp) gets the type of the KSP */
    /*  */
    /*   SEE ALSO:  petscKSPSetType */
    /*  */
    /*  PETSc C interface: */
    /*    PetscErrorCode  KSPGetType(KSP ksp, KSPType *type) */
    /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPGetType.html */
    /* 'petscKSPGetType:14' errCode = int32(-1); */
    /* 'petscKSPGetType:16' if ~isempty(coder.target) */
    /* 'petscKSPGetType:17' t_type = coder.opaque('KSPType'); */
    /* 'petscKSPGetType:18' errCode = coder.ceval('KSPGetType', PetscKSP(ksp), coder.wref(t_type)); */
    /* Map an opaque object into a PETSc KSP object */
    /*  */
    /*   ksp = PetscKSP() simply returns a definition of the */
    /*   m2c_opaque_type definition, suitable in the argument */
    /*   specification for codegen. */
    /*  */
    /*   ksp = PetscKSP(arg) or ksp = PetscKSP(arg, false) converts arg */
    /*   into a PETSc KSP object. */
    /*  */
    /*   ksp = PetscKSP(arg, true) wraps the arg into an opaque object.  */
    /*   This should be used if the object needs to be returned to */
    /*   MATLAB. Note that the value of opaque must be determined at */
    /*   compile time. */
    /*  */
    /*  See also PetscPC */
    /* 'PetscKSP:18' coder.inline('always'); */
    /* 'PetscKSP:20' if nargin==0 && isempty(coder.target) */
    /* 'PetscKSP:25' if isstruct(arg) && ~isequal(arg.type, 'KSP') */
    /* 'PetscKSP:30' if ~isstruct(arg) || isempty(coder.target) */
    /* 'PetscKSP:31' if nargin==1 || ~opaque */
    /* 'PetscKSP:32' ksp = arg; */
    errCode = KSPGetType(ksp, &t_type);

    /* 'petscKSPGetType:20' toplevel = nargout>2; */
    /* 'petscKSPGetType:21' type = PetscKSPType(t_type, toplevel); */
    /* Map a null-terminated C string into a PETSc KSPType handle */
    /*  */
    /*   type = PetscKSPType() simply returns a definition of a string, */
    /*   suitable in the argument specification for codegen. */
    /*  */
    /*   type = PetscKSPType(arg) or type = PetscKSPType(arg, false) converts arg */
    /*   into a PETSc KSPType object. */
    /*  */
    /*   type = PetscKSPType(arg, true) copies the arg into a MATLAB string. */
    /*   This should be used if the object needs to be returned to MATLAB. */
    /*   Note that the value of opaque must be determined at compile time. */
    /*  */
    /*  See also PetscPCType, PETSC_KSP* */
    /* 'PetscKSPType:16' coder.inline('always'); */
    /* 'PetscKSPType:18' if nargin==0 && isempty(coder.target) */
    /* 'PetscKSPType:23' if isempty(coder.target) && ~ischar(arg) */
    /* 'PetscKSPType:28' if nargin==1 || ~opaque */
    /* 'PetscKSPType:29' type = arg; */
    /* 'petscKSPGetType:23' if errCode && (toplevel || m2c_debug) */
    if (errCode != 0) {
      /* Flag indicating whether m2c_debug is on. */
      /* It is always true within MATLAB. In the generated C code, it is */
      /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
      /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
      /* 'm2c_debug:7' coder.inline('always'); */
      /* 'm2c_debug:9' if isempty(coder.target) */
      /* 'm2c_debug:11' else */
      /* 'm2c_debug:12' flag = int32(1); */
      /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
      val = (M2C_DEBUG);
      if (val != 0) {
        /* 'petscKSPGetType:24' m2c_error('petsc:RuntimeError', 'KSPGetType returned error code %d\n', errCode) */
        x_m2c_error(errCode);
      }
    }

    /* Gets the PC type as a PCType object from the PC object. */
    /*  */
    /*   [type, errCode] = petscPCGetType(pc) gets the type of the PC */
    /*  */
    /*   SEE ALSO:  petscPCSetType */
    /*  */
    /*  PETSc C interface: */
    /*    PetscErrorCode  PCGetType(PC pc, PCType *type) */
    /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/PC/PCGetType.html */
    /* 'petscPCGetType:14' errCode = int32(-1); */
    /* 'petscPCGetType:16' if ~isempty(coder.target) */
    /* 'petscPCGetType:17' t_type = coder.opaque('PCType'); */
    /* 'petscPCGetType:18' errCode = coder.ceval('PCGetType', PetscPC(pc), coder.wref(t_type)); */
    /* Map an opaque object into a PETSc PC object */
    /*  */
    /*   pc = PetscPC() simply returns a definition of the */
    /*   m2c_opaque_type definition, suitable in the argument */
    /*   specification for codegen. */
    /*  */
    /*   pc = PetscPC(arg) or pc = PetscPC(arg, false) converts arg */
    /*   into a PETSc PC object. */
    /*  */
    /*   pc = PetscPC(arg, true) wraps the arg into an opaque object.  */
    /*   This should be used if the object needs to be returned to */
    /*   MATLAB. Note that the value of opaque must be determined at */
    /*   compile time. */
    /*  */
    /*  See also PetscKSP */
    /* 'PetscPC:18' coder.inline('always'); */
    /* 'PetscPC:20' if nargin==0 && isempty(coder.target) */
    /* 'PetscPC:25' if isstruct(arg) && ~isequal(arg.type, 'PC') */
    /* 'PetscPC:30' if ~isstruct(arg) || isempty(coder.target) */
    /* 'PetscPC:31' if nargin==1 || ~opaque */
    /* 'PetscPC:32' pc = arg; */
    errCode = PCGetType(t_pc, &b_t_type);

    /* 'petscPCGetType:20' toplevel = nargout>2; */
    /* 'petscPCGetType:21' type = PetscPCType(t_type, toplevel); */
    /* Map a null-terminated C string into a PETSc PCType handle */
    /*  */
    /*   type = PetscPCType() simply returns a definition of a string, */
    /*   suitable in the argument specification for codegen. */
    /*  */
    /*   type = PetscPCType(arg) or type = PetscPCType(arg, false) converts arg */
    /*   into a PETSc PCType object. */
    /*  */
    /*   type = PetscPCType(arg, true) copies the arg into a MATLAB string. */
    /*   This should be used if the object needs to be returned to MATLAB. */
    /*   Note that the value of opaque must be determined at compile time. */
    /*  */
    /*  See also PetscKSTType, PETSC_PC* */
    /* 'PetscPCType:16' coder.inline('always'); */
    /* 'PetscPCType:18' if nargin==0 && isempty(coder.target) */
    /* 'PetscPCType:23' if isempty(coder.target) && ~ischar(arg) */
    /* 'PetscPCType:28' if nargin==1 || ~opaque */
    /* 'PetscPCType:29' type = arg; */
    /* 'petscPCGetType:23' if errCode && (toplevel || m2c_debug) */
    if (errCode != 0) {
      /* Flag indicating whether m2c_debug is on. */
      /* It is always true within MATLAB. In the generated C code, it is */
      /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
      /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
      /* 'm2c_debug:7' coder.inline('always'); */
      /* 'm2c_debug:9' if isempty(coder.target) */
      /* 'm2c_debug:11' else */
      /* 'm2c_debug:12' flag = int32(1); */
      /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
      val = (M2C_DEBUG);
      if (val != 0) {
        /* 'petscPCGetType:24' m2c_error('petsc:RuntimeError', 'PCGetType returned error code %d\n', errCode) */
        y_m2c_error(errCode);
      }
    }

    m2c_printf(t_type, b_t_type, *flag);

    /* 'mptKSPSolve:81' m2c_printf('### The relative residual was %g after %d iterations.\n', relres, iter); */
    b_m2c_printf(*relres, *iter);

    /* 'mptKSPSolve:82' m2c_printf('### The relative and absolute tolerances were %g and %g.\n', rtol, abstol); */
    c_m2c_printf(b_rtol, abstol);

    /* 'mptKSPSolve:83' m2c_printf('### The divergence and max-iter tolerances were %d and %g.\n', maxits, dtol); */
    d_m2c_printf(b_maxits, dtol);

    /* 'mptKSPSolve:84' m2c_printf(['### For explanation of the flag, see http://www.mcs.anl.gov/petsc/' ... */
    /* 'mptKSPSolve:85'         'petsc-current/docs/manualpages/KSP/KSPConvergedReason.html.\n']); */
    e_m2c_printf();
  }
}

/*
 * function [mat_out, toplevel] = mptMatCreateAIJFromCRS(row_ptr, col_ind, val, varargin)
 */
static Mat mptMatCreateAIJFromCRS(const emxArray_int32_T *row_ptr, const
  emxArray_int32_T *col_ind, const emxArray_real_T *val)
{
  emxArray_int32_T *nnz;
  int n;
  int i0;
  int i;
  int b_val;
  Mat t_mat;
  int errCode;
  emxArray_int32_T *jidx;
  emxArray_real_T *rowval;
  int i1;
  int type;
  int iroa;
  emxInit_int32_T(&nnz, 1);

  /*  Creates a sparse matrix in PETSc using AIJ format from the CRS arrays format. */
  /*  */
  /*     mat = mptMatCreateAIJFromCRS(row_ptr, col_ind, val) */
  /*       creates a PETSc matrix using the default AIJ format. If there is only */
  /*       one processor, it uses the sequential AIJ format. If there are more */
  /*       than one processors, it uses the MPIAIJ format in PETSC_COMM_WORLD. */
  /*  */
  /*       row_ptr:   starting pointers for each row (1-based) */
  /*       col_ind:   column indices in each row (1-based) */
  /*       vals:      values in each row */
  /*  */
  /*     mat = mptMatCreateAIJFromCRS(row_ptr, col_ind, val, ncols, prefix) */
  /*       ncols:     the global number of columns */
  /*       prefix:    a character string specifics the prefix for the options. */
  /*            If specified and is nonempty, the function will call */
  /*            petscMatSetOptionsPrefix and then petscMatSetFromOptions */
  /*            to set the matrix type. This can be used to created a parallel */
  /*            matrix in PETSC_COMM_WORLD and set the local portion. */
  /*  */
  /*   The matrix must be deallocated by calling petscMatDestroy after use. */
  /*  */
  /*  SEE ALSO: petscMatDestroy, mptMatAIJToCRS, mptOptionsInsert */
  /* 'mptMatCreateAIJFromCRS:32' if nargin<3 */
  /* 'mptMatCreateAIJFromCRS:36' n = int32(length(row_ptr)-1); */
  n = row_ptr->size[0] - 1;

  /* 'mptMatCreateAIJFromCRS:38' if nargin<4 */
  /* 'mptMatCreateAIJFromCRS:39' ncols = n; */
  /*  Count the number of nonzeros per row */
  /* 'mptMatCreateAIJFromCRS:45' nnz = coder.nullcopy(zeros(n, 1, 'int32')); */
  i0 = nnz->size[0];
  nnz->size[0] = n;
  emxEnsureCapacity((emxArray__common *)nnz, i0, (int)sizeof(int));

  /* 'mptMatCreateAIJFromCRS:46' for i=1:n */
  for (i = 1; i <= n; i++) {
    /* 'mptMatCreateAIJFromCRS:47' nnz(i) = row_ptr(i+1)-row_ptr(i); */
    nnz->data[i - 1] = row_ptr->data[i] - row_ptr->data[i - 1];
  }

  /* 'mptMatCreateAIJFromCRS:50' if nargin<5 */
  /*  Create default matrix using petscMatCreateSeqAIJ */
  /* 'mptMatCreateAIJFromCRS:52' mat = petscMatCreateSeqAIJ(n, ncols, PETSC_DEFAULT, nnz); */
  /*  Obtain PETSC constant PETSC_DEFAULT */
  /* 'PETSC_DEFAULT:4' coder.inline('always'); */
  /* 'PETSC_DEFAULT:6' val = petscGetEnum('PETSC_DEFAULT'); */
  /* petscGetEnum Obtain an enumerate value in PETSC */
  /*  */
  /*     val = petscGetEnum(name) */
  /*  */
  /* The supported names include: */
  /*  */
  /*  PetscBool:  PETSC_TRUE, PETSC_FALSE */
  /*  */
  /*  VecOption: VEC_IGNORE_OFF_PROC_ENTRIES, VEC_IGNORE_NEGATIVE_INDICES, */
  /*       VEC_SUBSET_OFF_PROC_ENTRIES */
  /*  */
  /*  MatOption: MAT_ROW_ORIENTED, MAT_SYMMETRIC, MAT_STRUCTURALLY_SYMMETRIC, */
  /*       MAT_NEW_DIAGONALS, MAT_IGNORE_OFF_PROC_ENTRIES, */
  /*       MAT_USE_HASH_TABLE, MAT_KEEP_NONZERO_PATTERN, */
  /*       MAT_IGNORE_ZERO_ENTRIES, MAT_USE_INODES, MAT_HERMITIAN, */
  /*       MAT_SYMMETRY_ETERNAL, MAT_NEW_NONZERO_LOCATION_ERR, */
  /*       MAT_IGNORE_LOWER_TRIANGULAR, MAT_ERROR_LOWER_TRIANGULAR, */
  /*       MAT_GETROW_UPPERTRIANGULAR, MAT_SPD, */
  /*       MAT_NO_OFF_PROC_ZERO_ROWS, MAT_NO_OFF_PROC_ENTRIES, */
  /*       MAT_NEW_NONZERO_LOCATIONS, MAT_NEW_NONZERO_ALLOCATION_ERR, */
  /*       MAT_SUBSET_OFF_PROC_ENTRIES */
  /*  */
  /*  MatStructure: DIFFERENT_NONZERO_PATTERN, SUBSET_NONZERO_PATTERN, SAME_NONZERO_PATTERN */
  /*  */
  /*  MatDuplicateOption: MAT_DO_NOT_COPY_VALUES,MAT_COPY_VALUES,MAT_SHARE_NONZERO_PATTERN */
  /*  */
  /*  MatReuse: MAT_INITIAL_MATRIX,MAT_REUSE_MATRIX,MAT_IGNORE_MATRIX,MAT_INPLACE_MATRIX */
  /*  */
  /*  InsertMode: INSERT_VALUES, ADD_VALUES, MAX_VALUES, */
  /*       INSERT_ALL_VALUES, ADD_ALL_VALUES, INSERT_BC_VALUES, ADD_BC_VALUES */
  /*  */
  /*  MatAssemblyType: MAT_FINAL_ASSEMBLY, MAT_FLUSH_ASSEMBLY */
  /*  */
  /*  MatInfoType: MAT_LOCAL,MAT_GLOBAL_MAX,MAT_GLOBAL_SUM */
  /*  */
  /*  MatFactorType: MAT_FACTOR_NONE, MAT_FACTOR_LU, MAT_FACTOR_CHOLESKY,  */
  /*       MAT_FACTOR_ILU, MAT_FACTOR_ICC,MAT_FACTOR_ILUDT */
  /*  */
  /*  NormType: NORM_1, NORM_2, NORM_FROBENIUS, NORM_INFINITY, NORM_1_AND_2 */
  /*  */
  /*  Others:  PETSC_DETERMINE, PETSC_DECIDE, PETSC_DEFAULT */
  /* 'petscGetEnum:46' if isempty(coder.target) */
  /* 'petscGetEnum:50' coder.cinclude('petscsys.h'); */
  /* 'petscGetEnum:51' coder.cinclude('petscksp.h'); */
  /* % InsertMode */
  /* 'petscGetEnum:54' switch name */
  /* 'petscGetEnum:171' case 'PETSC_DEFAULT' */
  /* 'petscGetEnum:172' [val, toplevel] = get_val('PetscInt', 'PETSC_DEFAULT', nargin>1); */
  /* 'petscGetEnum:183' coder.inline('always'); */
  /* 'petscGetEnum:185' val = int32(intmin); */
  /* 'petscGetEnum:186' val = coder.ceval(' ', coder.opaque(type, name)); */
  b_val = (PETSC_DEFAULT);

  /* Creates a sparse matrix in AIJ (compressed row) format. */
  /*  */
  /*   [mat, errCode] = petscMatCreateSeqAIJ(m, n, nz) */
  /*  */
  /*    m   - number of rows */
  /*    n   - number of columns */
  /*    nz  - number of nonzeros per row (same for all rows) */
  /*  */
  /*   [Mat, errCode] = petscMatCreateSeqAIJ(m, n, ~, nnz) */
  /*  */
  /*    nnz - a column vector containing the number of nonzeros in the various  */
  /*          rows (possibly different for each row) */
  /*  */
  /*   [Mat, errCode] = petscMatCreateSeqAIJ(m, n, nz, [], ~) */
  /*   [Mat, errCode] = petscMatCreateSeqAIJ(m, n, ~, nnz, ~) */
  /*   This is an optimized version for returning an opaque PETSc Mat object */
  /*   instead of a MATLAB PetscMat object. It should be used when */
  /*   petscMatCreateSeqAIJ is not a top-level function for code generation. */
  /*  */
  /*   Note that for good matrix assembly performance, the user should preallocate the */
  /*   matrix storage by setting the parameter nz (or the array nnz). By setting */
  /*   these parameters accurately. Performance during matrix assembly can be */
  /*   increased by more than a factor of 50. */
  /*  */
  /*   SEE ALSO: petscAssembleMat, petscMatDestroy */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode  MatCreateSeqAIJ(comm,PetscInt m,PetscInt n,PetscInt nz,const PetscInt nnz[],Mat *A) */
  /*          where comm should always be PETSC_COMM_SELF. */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatCreateSeqAIJ.html */
  /* 'petscMatCreateSeqAIJ:36' errCode = int32(-1); */
  /* 'petscMatCreateSeqAIJ:38' if ~isempty(coder.target) */
  /* 'petscMatCreateSeqAIJ:39' t_mat = coder.opaque('Mat'); */
  /* 'petscMatCreateSeqAIJ:41' comm = MPI_Comm(PETSC_COMM_SELF); */
  /*  Obtain PETSC constant PETSC_COMM_SELF */
  /* 'PETSC_COMM_SELF:4' coder.inline('always'); */
  /* 'PETSC_COMM_SELF:6' val = petscGetObject('PETSC_COMM_SELF'); */
  /* petscGetObject Obtain an opaque object in PETSC */
  /*  */
  /*     obj = petscGetObject(name) */
  /*  */
  /* The supported names include: */
  /*  */
  /*  MPI_Comm: PETSC_COMM_SELF, PETSC_COMM_WORLD, MPI_COMM_SELF, MPI_COMM_WORLD */
  /*  */
  /*  Other: */
  /*      PETSC_IGNORE, PETSC_NULL_OPTION, PETSC_NULL_MAT, PETSC_NULL_VEC, */
  /*      PETSC_NULL_INT, PETSC_NULL_REAL */
  /* 'petscGetObject:16' if isempty(coder.target) */
  /* 'petscGetObject:20' switch name */
  /* 'petscGetObject:25' case 'PETSC_COMM_SELF' */
  /* 'petscGetObject:26' [obj, toplevel] = get_obj('MPI_Comm', 'PETSC_COMM_SELF', nargout>1); */
  /* Map an opaque object into a PETSc MPI_Comm object */
  /*  */
  /*   comm = MPI_Comm() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   comm = MPI_Comm(arg) or comm = MPI_Comm(arg, false) converts arg */
  /*   into a PETSc Options object. */
  /*  */
  /*   comm = MPI_Comm(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'MPI_Comm:18' coder.inline('always'); */
  /* 'MPI_Comm:20' if nargin==0 && isempty(coder.target) */
  /* 'MPI_Comm:25' if isstruct(arg) && ~isequal(arg.type, 'MPI_Comm') */
  /* 'MPI_Comm:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'MPI_Comm:31' if nargin==1 || ~opaque */
  /* 'MPI_Comm:32' comm = arg; */
  /* 'petscMatCreateSeqAIJ:42' if nargin==3 */
  /* 'petscMatCreateSeqAIJ:48' else */
  /* 'petscMatCreateSeqAIJ:49' errCode = coder.ceval('MatCreateSeqAIJ', comm, m, n, nz, coder.rref(nnz), coder.wref(t_mat)); */
  errCode = MatCreateSeqAIJ(PETSC_COMM_SELF, n, n, b_val, &nnz->data[0], &t_mat);

  /* 'petscMatCreateSeqAIJ:52' toplevel = nargout>2; */
  /* 'petscMatCreateSeqAIJ:53' mat = PetscMat(t_mat, toplevel); */
  /* Map an opaque object into a PETSc Mat object */
  /*  */
  /*   mat = PetscMat() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   mat = PetscMat(arg) or mat = PetscMat(arg, false) converts arg */
  /*   into a PETSc Mat object. */
  /*  */
  /*   mat = PetscMat(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscMat:18' coder.inline('always'); */
  /* 'PetscMat:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscMat:25' if isstruct(arg) && ~isequal(arg.type, 'Mat') */
  /* 'PetscMat:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscMat:31' if nargin==1 || ~opaque */
  /* 'PetscMat:32' mat = arg; */
  /* 'petscMatCreateSeqAIJ:55' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    b_val = (M2C_DEBUG);
    if (b_val != 0) {
      /* 'petscMatCreateSeqAIJ:56' m2c_error('petsc:RuntimeError', 'MatCreateSeqAIJ returned error code %d\n', errCode) */
      m2c_error(errCode);
    }
  }

  /* 'mptMatCreateAIJFromCRS:53' first_row = int32(0); */
  /*  Set values row by row */
  /* 'mptMatCreateAIJFromCRS:71' for i=1:n */
  i = 0;
  emxInit_int32_T(&jidx, 1);
  emxInit_real_T(&rowval, 1);
  while (i + 1 <= n) {
    /* 'mptMatCreateAIJFromCRS:72' jidx = col_ind(row_ptr(i):row_ptr(i+1)-1)-1; */
    i0 = row_ptr->data[i + 1] - 1;
    if (row_ptr->data[i] > i0) {
      i1 = 0;
      i0 = 0;
    } else {
      i1 = row_ptr->data[i] - 1;
    }

    b_val = jidx->size[0];
    jidx->size[0] = i0 - i1;
    emxEnsureCapacity((emxArray__common *)jidx, b_val, (int)sizeof(int));
    b_val = i0 - i1;
    for (i0 = 0; i0 < b_val; i0++) {
      jidx->data[i0] = col_ind->data[i1 + i0] - 1;
    }

    /* 'mptMatCreateAIJFromCRS:73' rowval = val(row_ptr(i):row_ptr(i+1)-1); */
    i0 = row_ptr->data[i + 1] - 1;
    if (row_ptr->data[i] > i0) {
      i1 = 0;
      i0 = 0;
    } else {
      i1 = row_ptr->data[i] - 1;
    }

    b_val = rowval->size[0];
    rowval->size[0] = i0 - i1;
    emxEnsureCapacity((emxArray__common *)rowval, b_val, (int)sizeof(double));
    b_val = i0 - i1;
    for (i0 = 0; i0 < b_val; i0++) {
      rowval->data[i0] = val->data[i1 + i0];
    }

    /* 'mptMatCreateAIJFromCRS:75' petscMatSetValues(mat, int32(1), i+first_row-1, nnz(i), jidx, rowval); */
    /* Inserts or adds a block of values into a matrix. These values may be cached, */
    /* so MatAssemblyBegin() and MatAssemblyEnd() must be called after all calls */
    /* to MatSetValues() have been completed. */
    /*  */
    /*   errCode = petscMatSetValues(mat, ni, ix, nj, jx, v) */
    /*   	mat   - the matrix to insert in */
    /*    ni,ix - the number of rows and their global (0-based) indices */
    /*    nj,jx - the number of columns and their global (0-based) indices */
    /*    v     - a logically two-dimensional array of values (by default it is */
    /*            row majored but can be changed by calling petscMatSetOption.) */
    /*  */
    /*   errCode = petscMatSetValues(mat, ni, ix, nj, jx, v, iora) */
    /*    iora  - either INSERT_VALUES or ADD_VALUES, where INSERT_VALUES */
    /*            replaces existing entries with new values and */
    /*            ADD_VALUES adds values to any existing entries. */
    /*  */
    /*   SEE ALSO: petscMatSetOption, petscMatAssemblyBegin, petscMatAssemblyEnd */
    /*  */
    /*  PETSc C interface: */
    /*    PetscErrorCode MatSetValues(Mat mat,PetscInt m,const PetscInt idxm[], */
    /*        PetscInt n,const PetscInt idxn[],const PetscScalar v[],InsertMode addv) */
    /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatSetValues.html */
    /* 'petscMatSetValues:30' errCode = int32(-1); */
    /* 'petscMatSetValues:31' if nargin<7 */
    /* 'petscMatSetValues:32' iroa = PETSC_INSERT_VALUES; */
    /*  Obtain PETSC constant INSERT_VALUES */
    /* 'PETSC_INSERT_VALUES:4' coder.inline('always'); */
    /* 'PETSC_INSERT_VALUES:6' val = petscGetEnum('INSERT_VALUES'); */
    /* petscGetEnum Obtain an enumerate value in PETSC */
    /*  */
    /*     val = petscGetEnum(name) */
    /*  */
    /* The supported names include: */
    /*  */
    /*  PetscBool:  PETSC_TRUE, PETSC_FALSE */
    /*  */
    /*  VecOption: VEC_IGNORE_OFF_PROC_ENTRIES, VEC_IGNORE_NEGATIVE_INDICES, */
    /*       VEC_SUBSET_OFF_PROC_ENTRIES */
    /*  */
    /*  MatOption: MAT_ROW_ORIENTED, MAT_SYMMETRIC, MAT_STRUCTURALLY_SYMMETRIC, */
    /*       MAT_NEW_DIAGONALS, MAT_IGNORE_OFF_PROC_ENTRIES, */
    /*       MAT_USE_HASH_TABLE, MAT_KEEP_NONZERO_PATTERN, */
    /*       MAT_IGNORE_ZERO_ENTRIES, MAT_USE_INODES, MAT_HERMITIAN, */
    /*       MAT_SYMMETRY_ETERNAL, MAT_NEW_NONZERO_LOCATION_ERR, */
    /*       MAT_IGNORE_LOWER_TRIANGULAR, MAT_ERROR_LOWER_TRIANGULAR, */
    /*       MAT_GETROW_UPPERTRIANGULAR, MAT_SPD, */
    /*       MAT_NO_OFF_PROC_ZERO_ROWS, MAT_NO_OFF_PROC_ENTRIES, */
    /*       MAT_NEW_NONZERO_LOCATIONS, MAT_NEW_NONZERO_ALLOCATION_ERR, */
    /*       MAT_SUBSET_OFF_PROC_ENTRIES */
    /*  */
    /*  MatStructure: DIFFERENT_NONZERO_PATTERN, SUBSET_NONZERO_PATTERN, SAME_NONZERO_PATTERN */
    /*  */
    /*  MatDuplicateOption: MAT_DO_NOT_COPY_VALUES,MAT_COPY_VALUES,MAT_SHARE_NONZERO_PATTERN */
    /*  */
    /*  MatReuse: MAT_INITIAL_MATRIX,MAT_REUSE_MATRIX,MAT_IGNORE_MATRIX,MAT_INPLACE_MATRIX */
    /*  */
    /*  InsertMode: INSERT_VALUES, ADD_VALUES, MAX_VALUES, */
    /*       INSERT_ALL_VALUES, ADD_ALL_VALUES, INSERT_BC_VALUES, ADD_BC_VALUES */
    /*  */
    /*  MatAssemblyType: MAT_FINAL_ASSEMBLY, MAT_FLUSH_ASSEMBLY */
    /*  */
    /*  MatInfoType: MAT_LOCAL,MAT_GLOBAL_MAX,MAT_GLOBAL_SUM */
    /*  */
    /*  MatFactorType: MAT_FACTOR_NONE, MAT_FACTOR_LU, MAT_FACTOR_CHOLESKY,  */
    /*       MAT_FACTOR_ILU, MAT_FACTOR_ICC,MAT_FACTOR_ILUDT */
    /*  */
    /*  NormType: NORM_1, NORM_2, NORM_FROBENIUS, NORM_INFINITY, NORM_1_AND_2 */
    /*  */
    /*  Others:  PETSC_DETERMINE, PETSC_DECIDE, PETSC_DEFAULT */
    /* 'petscGetEnum:46' if isempty(coder.target) */
    /* 'petscGetEnum:50' coder.cinclude('petscsys.h'); */
    /* 'petscGetEnum:51' coder.cinclude('petscksp.h'); */
    /* % InsertMode */
    /* 'petscGetEnum:54' switch name */
    /* 'petscGetEnum:81' case 'INSERT_VALUES' */
    /* 'petscGetEnum:82' [val, toplevel] = get_val('InsertMode', 'INSERT_VALUES', nargin>1); */
    /* 'petscGetEnum:183' coder.inline('always'); */
    /* 'petscGetEnum:185' val = int32(intmin); */
    /* 'petscGetEnum:186' val = coder.ceval(' ', coder.opaque(type, name)); */
    iroa = (INSERT_VALUES);

    /* 'petscMatSetValues:35' if ~isempty(coder.target) */
    /* 'petscMatSetValues:36' t_mat = PetscMat(mat); */
    /* Map an opaque object into a PETSc Mat object */
    /*  */
    /*   mat = PetscMat() simply returns a definition of the */
    /*   m2c_opaque_type definition, suitable in the argument */
    /*   specification for codegen. */
    /*  */
    /*   mat = PetscMat(arg) or mat = PetscMat(arg, false) converts arg */
    /*   into a PETSc Mat object. */
    /*  */
    /*   mat = PetscMat(arg, true) wraps the arg into an opaque object.  */
    /*   This should be used if the object needs to be returned to */
    /*   MATLAB. Note that the value of opaque must be determined at */
    /*   compile time. */
    /*  */
    /*  See also PetscMat */
    /* 'PetscMat:18' coder.inline('always'); */
    /* 'PetscMat:20' if nargin==0 && isempty(coder.target) */
    /* 'PetscMat:25' if isstruct(arg) && ~isequal(arg.type, 'Mat') */
    /* 'PetscMat:30' if ~isstruct(arg) || isempty(coder.target) */
    /* 'PetscMat:31' if nargin==1 || ~opaque */
    /* 'PetscMat:32' mat = arg; */
    /* 'petscMatSetValues:38' errCode = coder.ceval('MatSetValues', t_mat, ni, coder.rref(ix), ... */
    /* 'petscMatSetValues:39'         nj, coder.rref(jx), coder.rref(v), iroa); */
    errCode = MatSetValues(t_mat, 1, &i, nnz->data[i], &jidx->data[0],
      &rowval->data[0], iroa);

    /* 'petscMatSetValues:41' toplevel = nargout>1; */
    /* 'petscMatSetValues:42' if errCode && (toplevel || m2c_debug) */
    if (errCode != 0) {
      /* Flag indicating whether m2c_debug is on. */
      /* It is always true within MATLAB. In the generated C code, it is */
      /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
      /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
      /* 'm2c_debug:7' coder.inline('always'); */
      /* 'm2c_debug:9' if isempty(coder.target) */
      /* 'm2c_debug:11' else */
      /* 'm2c_debug:12' flag = int32(1); */
      /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
      b_val = (M2C_DEBUG);
      if (b_val != 0) {
        /* 'petscMatSetValues:43' m2c_error('petsc:RuntimeError', 'MatSetValues returned error code %d\n', errCode) */
        b_m2c_error(errCode);
      }
    }

    i++;
  }

  emxFree_real_T(&rowval);
  emxFree_int32_T(&jidx);
  emxFree_int32_T(&nnz);

  /*  Call assembly */
  /* 'mptMatCreateAIJFromCRS:79' petscMatAssemblyBegin(mat); */
  /* Begins assembling the matrix. This routine should be called after  */
  /* completing all calls to petscMatSetValues(). */
  /*  */
  /*   errCode = petscMatAssemblyBegin(mat, [type=petscMAT_FINAL_ASSEMBLY]) */
  /*  */
  /*   SEE ALSO: petscAssembleMat, petscMatAssemblyEnd, petscMatSetValues */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode MatAssemblyBegin(Mat mat,MatAssemblyType type) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatAssemblyBegin.html */
  /* 'petscMatAssemblyBegin:15' errCode = int32(-1); */
  /* 'petscMatAssemblyBegin:17' if ~isempty(coder.target) */
  /* 'petscMatAssemblyBegin:18' t_mat = PetscMat(mat); */
  /* Map an opaque object into a PETSc Mat object */
  /*  */
  /*   mat = PetscMat() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   mat = PetscMat(arg) or mat = PetscMat(arg, false) converts arg */
  /*   into a PETSc Mat object. */
  /*  */
  /*   mat = PetscMat(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscMat:18' coder.inline('always'); */
  /* 'PetscMat:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscMat:25' if isstruct(arg) && ~isequal(arg.type, 'Mat') */
  /* 'PetscMat:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscMat:31' if nargin==1 || ~opaque */
  /* 'PetscMat:32' mat = arg; */
  /* 'petscMatAssemblyBegin:20' if nargin<2 */
  /* 'petscMatAssemblyBegin:20' type = PETSC_MAT_FINAL_ASSEMBLY; */
  /*  Obtain PETSC constant MAT_FINAL_ASSEMBLY */
  /* 'PETSC_MAT_FINAL_ASSEMBLY:4' coder.inline('always'); */
  /* 'PETSC_MAT_FINAL_ASSEMBLY:6' val = petscGetEnum('MAT_FINAL_ASSEMBLY'); */
  /* petscGetEnum Obtain an enumerate value in PETSC */
  /*  */
  /*     val = petscGetEnum(name) */
  /*  */
  /* The supported names include: */
  /*  */
  /*  PetscBool:  PETSC_TRUE, PETSC_FALSE */
  /*  */
  /*  VecOption: VEC_IGNORE_OFF_PROC_ENTRIES, VEC_IGNORE_NEGATIVE_INDICES, */
  /*       VEC_SUBSET_OFF_PROC_ENTRIES */
  /*  */
  /*  MatOption: MAT_ROW_ORIENTED, MAT_SYMMETRIC, MAT_STRUCTURALLY_SYMMETRIC, */
  /*       MAT_NEW_DIAGONALS, MAT_IGNORE_OFF_PROC_ENTRIES, */
  /*       MAT_USE_HASH_TABLE, MAT_KEEP_NONZERO_PATTERN, */
  /*       MAT_IGNORE_ZERO_ENTRIES, MAT_USE_INODES, MAT_HERMITIAN, */
  /*       MAT_SYMMETRY_ETERNAL, MAT_NEW_NONZERO_LOCATION_ERR, */
  /*       MAT_IGNORE_LOWER_TRIANGULAR, MAT_ERROR_LOWER_TRIANGULAR, */
  /*       MAT_GETROW_UPPERTRIANGULAR, MAT_SPD, */
  /*       MAT_NO_OFF_PROC_ZERO_ROWS, MAT_NO_OFF_PROC_ENTRIES, */
  /*       MAT_NEW_NONZERO_LOCATIONS, MAT_NEW_NONZERO_ALLOCATION_ERR, */
  /*       MAT_SUBSET_OFF_PROC_ENTRIES */
  /*  */
  /*  MatStructure: DIFFERENT_NONZERO_PATTERN, SUBSET_NONZERO_PATTERN, SAME_NONZERO_PATTERN */
  /*  */
  /*  MatDuplicateOption: MAT_DO_NOT_COPY_VALUES,MAT_COPY_VALUES,MAT_SHARE_NONZERO_PATTERN */
  /*  */
  /*  MatReuse: MAT_INITIAL_MATRIX,MAT_REUSE_MATRIX,MAT_IGNORE_MATRIX,MAT_INPLACE_MATRIX */
  /*  */
  /*  InsertMode: INSERT_VALUES, ADD_VALUES, MAX_VALUES, */
  /*       INSERT_ALL_VALUES, ADD_ALL_VALUES, INSERT_BC_VALUES, ADD_BC_VALUES */
  /*  */
  /*  MatAssemblyType: MAT_FINAL_ASSEMBLY, MAT_FLUSH_ASSEMBLY */
  /*  */
  /*  MatInfoType: MAT_LOCAL,MAT_GLOBAL_MAX,MAT_GLOBAL_SUM */
  /*  */
  /*  MatFactorType: MAT_FACTOR_NONE, MAT_FACTOR_LU, MAT_FACTOR_CHOLESKY,  */
  /*       MAT_FACTOR_ILU, MAT_FACTOR_ICC,MAT_FACTOR_ILUDT */
  /*  */
  /*  NormType: NORM_1, NORM_2, NORM_FROBENIUS, NORM_INFINITY, NORM_1_AND_2 */
  /*  */
  /*  Others:  PETSC_DETERMINE, PETSC_DECIDE, PETSC_DEFAULT */
  /* 'petscGetEnum:46' if isempty(coder.target) */
  /* 'petscGetEnum:50' coder.cinclude('petscsys.h'); */
  /* 'petscGetEnum:51' coder.cinclude('petscksp.h'); */
  /* % InsertMode */
  /* 'petscGetEnum:54' switch name */
  /* 'petscGetEnum:95' case 'MAT_FINAL_ASSEMBLY' */
  /* 'petscGetEnum:96' [val, toplevel] = get_val('MatAssemblyType', 'MAT_FINAL_ASSEMBLY', nargin>1); */
  /* 'petscGetEnum:183' coder.inline('always'); */
  /* 'petscGetEnum:185' val = int32(intmin); */
  /* 'petscGetEnum:186' val = coder.ceval(' ', coder.opaque(type, name)); */
  type = (MAT_FINAL_ASSEMBLY);

  /* 'petscMatAssemblyBegin:22' errCode = coder.ceval('MatAssemblyBegin',t_mat,type); */
  errCode = MatAssemblyBegin(t_mat, type);

  /* 'petscMatAssemblyBegin:24' toplevel = nargout>1; */
  /* 'petscMatAssemblyBegin:25' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    b_val = (M2C_DEBUG);
    if (b_val != 0) {
      /* 'petscMatAssemblyBegin:26' m2c_error('petsc:RuntimeError', 'MatAssemblyBegin returned error code %d\n', errCode) */
      c_m2c_error(errCode);
    }
  }

  /* 'mptMatCreateAIJFromCRS:80' petscMatAssemblyEnd(mat); */
  /* Completes assembling the matrix. This routine should be called after  */
  /* petscMatAssemblyBegin(). */
  /*  */
  /*   errCode = petscMatAssemblyEnd(mat, [type=petscMAT_FINAL_ASSEMBLY]) */
  /*  */
  /*   SEE ALSO: petscAssembleMat, petscMatAssemblyBegin, petscMatSetValues */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode MatAssemblyEnd(Mat mat,MatAssemblyType type) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatAssemblyEnd.html */
  /* 'petscMatAssemblyEnd:15' errCode = int32(-1); */
  /* 'petscMatAssemblyEnd:17' if ~isempty(coder.target) */
  /* 'petscMatAssemblyEnd:18' t_mat = PetscMat(mat); */
  /* Map an opaque object into a PETSc Mat object */
  /*  */
  /*   mat = PetscMat() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   mat = PetscMat(arg) or mat = PetscMat(arg, false) converts arg */
  /*   into a PETSc Mat object. */
  /*  */
  /*   mat = PetscMat(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscMat:18' coder.inline('always'); */
  /* 'PetscMat:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscMat:25' if isstruct(arg) && ~isequal(arg.type, 'Mat') */
  /* 'PetscMat:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscMat:31' if nargin==1 || ~opaque */
  /* 'PetscMat:32' mat = arg; */
  /* 'petscMatAssemblyEnd:20' if nargin<2 */
  /* 'petscMatAssemblyEnd:20' type = PETSC_MAT_FINAL_ASSEMBLY; */
  /*  Obtain PETSC constant MAT_FINAL_ASSEMBLY */
  /* 'PETSC_MAT_FINAL_ASSEMBLY:4' coder.inline('always'); */
  /* 'PETSC_MAT_FINAL_ASSEMBLY:6' val = petscGetEnum('MAT_FINAL_ASSEMBLY'); */
  /* petscGetEnum Obtain an enumerate value in PETSC */
  /*  */
  /*     val = petscGetEnum(name) */
  /*  */
  /* The supported names include: */
  /*  */
  /*  PetscBool:  PETSC_TRUE, PETSC_FALSE */
  /*  */
  /*  VecOption: VEC_IGNORE_OFF_PROC_ENTRIES, VEC_IGNORE_NEGATIVE_INDICES, */
  /*       VEC_SUBSET_OFF_PROC_ENTRIES */
  /*  */
  /*  MatOption: MAT_ROW_ORIENTED, MAT_SYMMETRIC, MAT_STRUCTURALLY_SYMMETRIC, */
  /*       MAT_NEW_DIAGONALS, MAT_IGNORE_OFF_PROC_ENTRIES, */
  /*       MAT_USE_HASH_TABLE, MAT_KEEP_NONZERO_PATTERN, */
  /*       MAT_IGNORE_ZERO_ENTRIES, MAT_USE_INODES, MAT_HERMITIAN, */
  /*       MAT_SYMMETRY_ETERNAL, MAT_NEW_NONZERO_LOCATION_ERR, */
  /*       MAT_IGNORE_LOWER_TRIANGULAR, MAT_ERROR_LOWER_TRIANGULAR, */
  /*       MAT_GETROW_UPPERTRIANGULAR, MAT_SPD, */
  /*       MAT_NO_OFF_PROC_ZERO_ROWS, MAT_NO_OFF_PROC_ENTRIES, */
  /*       MAT_NEW_NONZERO_LOCATIONS, MAT_NEW_NONZERO_ALLOCATION_ERR, */
  /*       MAT_SUBSET_OFF_PROC_ENTRIES */
  /*  */
  /*  MatStructure: DIFFERENT_NONZERO_PATTERN, SUBSET_NONZERO_PATTERN, SAME_NONZERO_PATTERN */
  /*  */
  /*  MatDuplicateOption: MAT_DO_NOT_COPY_VALUES,MAT_COPY_VALUES,MAT_SHARE_NONZERO_PATTERN */
  /*  */
  /*  MatReuse: MAT_INITIAL_MATRIX,MAT_REUSE_MATRIX,MAT_IGNORE_MATRIX,MAT_INPLACE_MATRIX */
  /*  */
  /*  InsertMode: INSERT_VALUES, ADD_VALUES, MAX_VALUES, */
  /*       INSERT_ALL_VALUES, ADD_ALL_VALUES, INSERT_BC_VALUES, ADD_BC_VALUES */
  /*  */
  /*  MatAssemblyType: MAT_FINAL_ASSEMBLY, MAT_FLUSH_ASSEMBLY */
  /*  */
  /*  MatInfoType: MAT_LOCAL,MAT_GLOBAL_MAX,MAT_GLOBAL_SUM */
  /*  */
  /*  MatFactorType: MAT_FACTOR_NONE, MAT_FACTOR_LU, MAT_FACTOR_CHOLESKY,  */
  /*       MAT_FACTOR_ILU, MAT_FACTOR_ICC,MAT_FACTOR_ILUDT */
  /*  */
  /*  NormType: NORM_1, NORM_2, NORM_FROBENIUS, NORM_INFINITY, NORM_1_AND_2 */
  /*  */
  /*  Others:  PETSC_DETERMINE, PETSC_DECIDE, PETSC_DEFAULT */
  /* 'petscGetEnum:46' if isempty(coder.target) */
  /* 'petscGetEnum:50' coder.cinclude('petscsys.h'); */
  /* 'petscGetEnum:51' coder.cinclude('petscksp.h'); */
  /* % InsertMode */
  /* 'petscGetEnum:54' switch name */
  /* 'petscGetEnum:95' case 'MAT_FINAL_ASSEMBLY' */
  /* 'petscGetEnum:96' [val, toplevel] = get_val('MatAssemblyType', 'MAT_FINAL_ASSEMBLY', nargin>1); */
  /* 'petscGetEnum:183' coder.inline('always'); */
  /* 'petscGetEnum:185' val = int32(intmin); */
  /* 'petscGetEnum:186' val = coder.ceval(' ', coder.opaque(type, name)); */
  type = (MAT_FINAL_ASSEMBLY);

  /* 'petscMatAssemblyEnd:22' errCode = coder.ceval('MatAssemblyEnd', t_mat, type); */
  errCode = MatAssemblyEnd(t_mat, type);

  /* 'petscMatAssemblyEnd:24' toplevel = nargout>1; */
  /* 'petscMatAssemblyEnd:25' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    b_val = (M2C_DEBUG);
    if (b_val != 0) {
      /* 'petscMatAssemblyEnd:26' m2c_error('petsc:RuntimeError', 'MatAssemblyEnd returned error code %d\n', errCode) */
      d_m2c_error(errCode);
    }
  }

  /* 'mptMatCreateAIJFromCRS:82' toplevel = nargout>1; */
  /* 'mptMatCreateAIJFromCRS:83' mat_out = PetscMat(mat, toplevel); */
  /* Map an opaque object into a PETSc Mat object */
  /*  */
  /*   mat = PetscMat() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   mat = PetscMat(arg) or mat = PetscMat(arg, false) converts arg */
  /*   into a PETSc Mat object. */
  /*  */
  /*   mat = PetscMat(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscMat:18' coder.inline('always'); */
  /* 'PetscMat:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscMat:25' if isstruct(arg) && ~isequal(arg.type, 'Mat') */
  /* 'PetscMat:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscMat:31' if nargin==1 || ~opaque */
  /* 'PetscMat:32' mat = arg; */
  return t_mat;
}

/*
 * function [flag,relres,iter, times] = mptSolve(A, b, x, solver, rtol, maxit, ...
 *     pctype, solpack, x0, opts)
 */
static void mptSolve(Mat A, Vec b, Vec x, const emxArray_char_T *solver, double
                     rtol, int maxit, Vec x0, int *flag, double *relres, int
                     *iter, double times[2])
{
  PetscObject t_obj;
  MPI_Comm t_comm;
  int errCode;
  KSP t_ksp;
  double t;
  emxArray_char_T *ksptype0;
  int b_flag;
  int loop_ub;
  double b_t;
  double time_solve;

  /*  Solves a linear system using a given solver in PETSc. */
  /*  */
  /*  Syntax: */
  /*     mptSolve(A_hdl, b_hdl) */
  /*     mptSolve(A_hdl, b_hdl, x_hdl) */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver) */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol) */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit) */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype) */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype, solpack) */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype, solpack, x0_hdl) */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype, solpack, x0_hdl, opts) */
  /*  */
  /*     [flag, reslres, iter] = mptSolve(A_hdl, b_hdl, x_hdl, ...) */
  /*  */
  /*     The handles are PetscMat or PetscVec objects. */
  /*  */
  /*  Description: */
  /*     mptSolve(A_hdl, b_hdl) solves the linear system without preconditioners, */
  /*     using the default tolerances or those that have been set previously in */
  /*     the option databases. A_hdl is a PetscMat object, and b_hdl is a */
  /*     PetscVec object. The solution is stored into b. The QMRCGS can be */
  /*     controlled using the options database for KSPQMRCGS. */
  /*  */
  /*     mptSolve(A_hdl, b_hdl, x_hdl) solves the linear system and saves the */
  /*     result into x. */
  /*  */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver) uses the specified solver, where */
  /*     solver is one of PETSC_KSP*. */
  /*  */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol) uses the given relative tolerarance. */
  /*  */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit) solves with the given */
  /*      relative tolerances and maximum iteration count. */
  /*  */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype) uses the */
  /*     specified preconditioner (PETSC_PC*). The preconditioner can be */
  /*     controlled by the PETSc option database. */
  /*  */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype, solpack) */
  /*     specifies the solver packages for factorization (PETSC_MATSOLVER*). */
  /*  */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype, solpack, */
  /*     x0_handle) usee x0 for the initial guess. x0 can be the same as x or */
  /*     be PETSC_NULL_VEC. */
  /*  */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype, solpack, */
  /*     x0_handle, opts) can pass command-line options in a string to PETSc. */
  /*  */
  /*  SEE ALSO: mptSolveCRS, mptMatCreateAIJFromCRS, mptVecCreateFromArray, */
  /*            mptOptionsInsert, mptKSPSetup, mptKSPSolve, mptKSPCleanup */
  /* This function is codegen compatbile, but no need to a top-level function */
  /*  Setup KSP */
  /* 'mptSolve:59' if nargin<3 */
  /* 'mptSolve:60' if nargin<4 */
  /* 'mptSolve:61' if nargin<5 */
  /* 'mptSolve:62' if nargin<6 */
  /* 'mptSolve:63' if nargin<7 */
  /* 'mptSolve:64' if nargin<8 */
  /* 'mptSolve:65' if nargin<9 */
  /* 'mptSolve:67' if nargin==10 && ~isempty(opts) */
  /* 'mptSolve:71' [ksp, time_setup] = mptKSPSetup(A, solver, pctype, solpack); */
  /*  Sets up KSP using the given matrix (matrices). */
  /*  */
  /*  Syntax: */
  /*   ksp = mptKSPSetup(A) */
  /*   ksp = mptKSPSetup(A, ksptype) */
  /*   ksp = mptKSPSetup(A, ksptype, pctype) */
  /*   ksp = mptKSPSetup(A, ksptype, pctype, solpack) */
  /*  */
  /*  Description: */
  /*   ksp = mptKSPSetup(A) sets up a KSP using matrix A. */
  /*  */
  /*   ksp = mptKSPSetup(A, ksptype) uses the specified type of the KSP. */
  /*  */
  /*   ksp = mptKSPSetup(A, ksptype, pctype) also sets the type of the KSP */
  /*     and the preconditioner. Note that pctype can be NULL. */
  /*  */
  /*   ksp = mptKSPSetup(A, ksptype, pctype, solpack) configures the KSP */
  /*     solver using the specified solver package. It is useful only when */
  /*     pctype is PCLU, PCILU, or PCICC. */
  /*  */
  /*  See Also: mptKSPSolve, mptKSPCleanup */
  /* 'mptKSPSetup:29' t_Amat = Amat; */
  /* 'mptKSPSetup:30' t_ksp = petscKSPCreate(petscObjectGetComm(t_Amat)); */
  /* Gets the MPI communicator for any PetscObject, regardless of the type.  */
  /*  */
  /*   [comm, errCode] = petscObjectGetComm(obj) */
  /*  */
  /*   obtains the MPI_Comm associated with the PetscObject. */
  /*  */
  /*   SEE ALSO: petscMatSetType, petscMatSetFromOptions */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode  PetscObjectGetComm(PetscObject obj,MPI_Comm *comm) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Sys/PetscObjectGetComm.html */
  /* 'petscObjectGetComm:16' errCode = int32(-1); */
  /* 'petscObjectGetComm:18' if ~isempty(coder.target) */
  /* 'petscObjectGetComm:19' t_obj = PetscObject(obj); */
  /* Map an opaque object into a PETSc PetscObject object */
  /*  */
  /*   obj = PetscObject() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   obj = PetscObject(arg) or obj = PetscObject(arg, false) converts arg */
  /*   into a PETSc Object object. */
  /*  */
  /*   obj = PetscObject(arg, true) wraps the arg into an opaque object. */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscObject:18' coder.inline('always'); */
  /* 'PetscObject:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscObject:25' if isstruct(arg) && ~isequal(arg.type, 'PetscObject') && ... */
  /* 'PetscObject:26'         ~isequal(arg.type, 'Mat') && ~isequal(arg.type, 'Vec') && ... */
  /* 'PetscObject:27'         ~isequal(arg.type, 'KSP') && ~isequal(arg.type, 'PC') */
  /* 'PetscObject:32' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscObject:33' if nargin==1 || ~opaque */
  /* 'PetscObject:34' obj = coder.opaque('PetscObject'); */
  /* 'PetscObject:35' obj = coder.ceval('(PetscObject)', arg); */
  t_obj = (PetscObject)(A);

  /* 'petscObjectGetComm:20' t_comm = coder.opaque('MPI_Comm'); */
  /* 'petscObjectGetComm:22' errCode = coder.ceval('PetscObjectGetComm', t_obj, coder.wref(t_comm)); */
  errCode = PetscObjectGetComm(t_obj, &t_comm);

  /* 'petscObjectGetComm:24' toplevel = nargout>2; */
  /* 'petscObjectGetComm:25' comm = MPI_Comm(t_comm, toplevel); */
  /* Map an opaque object into a PETSc MPI_Comm object */
  /*  */
  /*   comm = MPI_Comm() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   comm = MPI_Comm(arg) or comm = MPI_Comm(arg, false) converts arg */
  /*   into a PETSc Options object. */
  /*  */
  /*   comm = MPI_Comm(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'MPI_Comm:18' coder.inline('always'); */
  /* 'MPI_Comm:20' if nargin==0 && isempty(coder.target) */
  /* 'MPI_Comm:25' if isstruct(arg) && ~isequal(arg.type, 'MPI_Comm') */
  /* 'MPI_Comm:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'MPI_Comm:31' if nargin==1 || ~opaque */
  /* 'MPI_Comm:32' comm = arg; */
  /* 'petscObjectGetComm:27' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    *flag = (M2C_DEBUG);
    if (*flag != 0) {
      /* 'petscObjectGetComm:28' m2c_error('petsc:RuntimeError', 'PetscObjectGetComm returned error code %d\n', errCode) */
      j_m2c_error(errCode);
    }
  }

  /* Creates a preconditioner context. */
  /*  */
  /*   [ksp, errCode] = petscKSPCreate */
  /*       creates a PETSc KSP using PETSC_COMM_WORLD */
  /*  */
  /*   [ksp, errCode] = petscKSPCreate(comm) */
  /*       comm: MPI Communicator */
  /*  */
  /*   SEE ALSO: petscKSPSetUp, petscKSPSolve, petscKSPDestroy */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode  KSPCreate(MPI_Comm comm,KSP *ksp) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPCreate.html */
  /* 'petscKSPCreate:18' errCode = int32(-1); */
  /* 'petscKSPCreate:20' if ~isempty(coder.target) */
  /* 'petscKSPCreate:21' t_ksp = coder.opaque('KSP'); */
  /* 'petscKSPCreate:23' if nargin==0 */
  /* 'petscKSPCreate:25' else */
  /* 'petscKSPCreate:26' t_comm = MPI_Comm(comm); */
  /* Map an opaque object into a PETSc MPI_Comm object */
  /*  */
  /*   comm = MPI_Comm() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   comm = MPI_Comm(arg) or comm = MPI_Comm(arg, false) converts arg */
  /*   into a PETSc Options object. */
  /*  */
  /*   comm = MPI_Comm(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'MPI_Comm:18' coder.inline('always'); */
  /* 'MPI_Comm:20' if nargin==0 && isempty(coder.target) */
  /* 'MPI_Comm:25' if isstruct(arg) && ~isequal(arg.type, 'MPI_Comm') */
  /* 'MPI_Comm:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'MPI_Comm:31' if nargin==1 || ~opaque */
  /* 'MPI_Comm:32' comm = arg; */
  /* 'petscKSPCreate:29' errCode = coder.ceval('KSPCreate', t_comm, coder.wref(t_ksp)); */
  errCode = KSPCreate(t_comm, &t_ksp);

  /* 'petscKSPCreate:31' toplevel = nargout>2; */
  /* 'petscKSPCreate:32' ksp = PetscKSP(t_ksp, toplevel); */
  /* Map an opaque object into a PETSc KSP object */
  /*  */
  /*   ksp = PetscKSP() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   ksp = PetscKSP(arg) or ksp = PetscKSP(arg, false) converts arg */
  /*   into a PETSc KSP object. */
  /*  */
  /*   ksp = PetscKSP(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscPC */
  /* 'PetscKSP:18' coder.inline('always'); */
  /* 'PetscKSP:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscKSP:25' if isstruct(arg) && ~isequal(arg.type, 'KSP') */
  /* 'PetscKSP:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscKSP:31' if nargin==1 || ~opaque */
  /* 'PetscKSP:32' ksp = arg; */
  /* 'petscKSPCreate:34' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    *flag = (M2C_DEBUG);
    if (*flag != 0) {
      /* 'petscKSPCreate:35' m2c_error('petsc:RuntimeError', 'KSPCreate returned error code %d\n', errCode) */
      k_m2c_error(errCode);
    }
  }

  /* 'mptKSPSetup:32' time = 0; */
  /* 'mptKSPSetup:33' if nargout>1 */
  /* 'mptKSPSetup:33' t=m2c_wtime(); */
  /*  Return ellapsed time */
  /*    t = m2c_wtime */
  /* 'm2c_wtime:7' if isempty(coder.target) */
  /* 'm2c_wtime:10' else */
  /* 'm2c_wtime:11' coder.inline( 'always'); */
  /* 'm2c_wtime:13' t = 0; */
  /* 'm2c_wtime:13' t = coder.ceval( 'M2C_wtime'); */
  t = M2C_wtime();

  /*  Setup KSP */
  /* 'mptKSPSetup:36' petscKSPSetOperators(t_ksp, PetscMat(t_Amat)); */
  /* Map an opaque object into a PETSc Mat object */
  /*  */
  /*   mat = PetscMat() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   mat = PetscMat(arg) or mat = PetscMat(arg, false) converts arg */
  /*   into a PETSc Mat object. */
  /*  */
  /*   mat = PetscMat(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscMat:18' coder.inline('always'); */
  /* 'PetscMat:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscMat:25' if isstruct(arg) && ~isequal(arg.type, 'Mat') */
  /* 'PetscMat:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscMat:31' if nargin==1 || ~opaque */
  /* 'PetscMat:32' mat = arg; */
  /* Sets the matrix associated with the linear system and a (possibly) */
  /* different one associated with the preconditioner. */
  /*  */
  /*   errCode = petscKSPSetOperators(ksp, Amat) */
  /*  */
  /*   sets the matrix to be Amat and use the same matrix to construct the */
  /*   preconditioner. */
  /*      ksp - iterative context obtained from petscKSPCreate */
  /*      Amat	  - the right hand side vector */
  /*  */
  /*   errCode = petscKSPSetOperators(ksp, Amat, Pmat) */
  /*  */
  /*   uses the matrix Pmat to construct the preconditioner. */
  /*  */
  /*   SEE ALSO: petscKSPCreate, petscKSPSetUp, petscKSPSolve, petscKSPDestroy */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode  KSPSetOperators(KSP ksp,Mat Amat,Mat Pmat) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPSetOperators.html */
  /* 'petscKSPSetOperators:25' errCode = int32(-1); */
  /* 'petscKSPSetOperators:27' if ~isempty(coder.target) */
  /* 'petscKSPSetOperators:28' t_ksp = PetscKSP(ksp); */
  /* Map an opaque object into a PETSc KSP object */
  /*  */
  /*   ksp = PetscKSP() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   ksp = PetscKSP(arg) or ksp = PetscKSP(arg, false) converts arg */
  /*   into a PETSc KSP object. */
  /*  */
  /*   ksp = PetscKSP(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscPC */
  /* 'PetscKSP:18' coder.inline('always'); */
  /* 'PetscKSP:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscKSP:25' if isstruct(arg) && ~isequal(arg.type, 'KSP') */
  /* 'PetscKSP:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscKSP:31' if nargin==1 || ~opaque */
  /* 'PetscKSP:32' ksp = arg; */
  /* 'petscKSPSetOperators:29' t_Amat = PetscMat(Amat); */
  /* Map an opaque object into a PETSc Mat object */
  /*  */
  /*   mat = PetscMat() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   mat = PetscMat(arg) or mat = PetscMat(arg, false) converts arg */
  /*   into a PETSc Mat object. */
  /*  */
  /*   mat = PetscMat(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscMat:18' coder.inline('always'); */
  /* 'PetscMat:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscMat:25' if isstruct(arg) && ~isequal(arg.type, 'Mat') */
  /* 'PetscMat:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscMat:31' if nargin==1 || ~opaque */
  /* 'PetscMat:32' mat = arg; */
  /* 'petscKSPSetOperators:31' if nargin==2 */
  /* 'petscKSPSetOperators:32' t_Pmat = t_Amat; */
  /* 'petscKSPSetOperators:37' errCode = coder.ceval('KSPSetOperators', t_ksp, t_Amat, t_Pmat); */
  errCode = KSPSetOperators(t_ksp, A, A);

  /* 'petscKSPSetOperators:39' toplevel = nargout>1; */
  /* 'petscKSPSetOperators:40' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    *flag = (M2C_DEBUG);
    if (*flag != 0) {
      /* 'petscKSPSetOperators:41' m2c_error('petsc:RuntimeError', 'KSPSetOperators returned error code %d\n', errCode) */
      l_m2c_error(errCode);
    }
  }

  /* 'mptKSPSetup:38' if nargin>1 */
  /* 'mptKSPSetup:39' if nargin>2 */
  /* 'mptKSPSetup:40' hasPC = ~ischar(pctype) || ~isempty(pctype); */
  /* 'mptKSPSetup:41' hasSolver = nargin>3 && (~ischar(solpack) || ~isempty(solpack)); */
  /* 'mptKSPSetup:43' if hasPC || hasSolver */
  /* 'mptKSPSetup:68' if ischar(ksptype) && ~isempty(ksptype) && ksptype(end)~=0 */
  emxInit_char_T(&ksptype0, 2);
  if ((!(solver->size[1] == 0)) && ((unsigned char)solver->data[solver->size[1]
       - 1] != 0)) {
    /*  null-terminate the string if not terminated properly */
    /* 'mptKSPSetup:70' ksptype0 = [ksptype char(0)]; */
    b_flag = ksptype0->size[0] * ksptype0->size[1];
    ksptype0->size[0] = 1;
    ksptype0->size[1] = solver->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)ksptype0, b_flag, (int)sizeof(char));
    loop_ub = solver->size[1];
    for (b_flag = 0; b_flag < loop_ub; b_flag++) {
      ksptype0->data[ksptype0->size[0] * b_flag] = solver->data[solver->size[0] *
        b_flag];
    }

    ksptype0->data[ksptype0->size[0] * solver->size[1]] = '\x00';
  } else {
    /* 'mptKSPSetup:71' else */
    /* 'mptKSPSetup:72' ksptype0 = ksptype; */
    b_flag = ksptype0->size[0] * ksptype0->size[1];
    ksptype0->size[0] = 1;
    ksptype0->size[1] = solver->size[1];
    emxEnsureCapacity((emxArray__common *)ksptype0, b_flag, (int)sizeof(char));
    loop_ub = solver->size[0] * solver->size[1];
    for (b_flag = 0; b_flag < loop_ub; b_flag++) {
      ksptype0->data[b_flag] = solver->data[b_flag];
    }
  }

  /* 'mptKSPSetup:74' if ischar(ksptype0) && ~isempty(ksptype0) || ~ischar(ksptype0) */
  if (!(ksptype0->size[1] == 0)) {
    /*  Set KSP Types */
    /* 'mptKSPSetup:76' petscKSPSetType(t_ksp, ksptype0); */
    /* Builds KSP for a particular solver. */
    /*  */
    /*   errCode = petscKSPSetType(ksp, type) sets the type of the KSP */
    /*  */
    /*   SEE ALSO:  PetscPCSetType, petscKSPCreate */
    /*  */
    /*  PETSc C interface: */
    /*    PetscErrorCode  KSPSetType(KSP ksp, KSPType type) */
    /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPSetType.html */
    /* 'petscKSPSetType:14' errCode = int32(-1); */
    /* 'petscKSPSetType:16' if ~isempty(coder.target) */
    /* 'petscKSPSetType:17' if ischar(type) */
    /* 'petscKSPSetType:18' errCode = coder.ceval('KSPSetType', PetscKSP(ksp), coder.rref(type)); */
    /* Map an opaque object into a PETSc KSP object */
    /*  */
    /*   ksp = PetscKSP() simply returns a definition of the */
    /*   m2c_opaque_type definition, suitable in the argument */
    /*   specification for codegen. */
    /*  */
    /*   ksp = PetscKSP(arg) or ksp = PetscKSP(arg, false) converts arg */
    /*   into a PETSc KSP object. */
    /*  */
    /*   ksp = PetscKSP(arg, true) wraps the arg into an opaque object.  */
    /*   This should be used if the object needs to be returned to */
    /*   MATLAB. Note that the value of opaque must be determined at */
    /*   compile time. */
    /*  */
    /*  See also PetscPC */
    /* 'PetscKSP:18' coder.inline('always'); */
    /* 'PetscKSP:20' if nargin==0 && isempty(coder.target) */
    /* 'PetscKSP:25' if isstruct(arg) && ~isequal(arg.type, 'KSP') */
    /* 'PetscKSP:30' if ~isstruct(arg) || isempty(coder.target) */
    /* 'PetscKSP:31' if nargin==1 || ~opaque */
    /* 'PetscKSP:32' ksp = arg; */
    errCode = KSPSetType(t_ksp, &ksptype0->data[0]);

    /* 'petscKSPSetType:23' toplevel = nargout>1; */
    /* 'petscKSPSetType:24' if errCode && (toplevel || m2c_debug) */
    if (errCode != 0) {
      /* Flag indicating whether m2c_debug is on. */
      /* It is always true within MATLAB. In the generated C code, it is */
      /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
      /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
      /* 'm2c_debug:7' coder.inline('always'); */
      /* 'm2c_debug:9' if isempty(coder.target) */
      /* 'm2c_debug:11' else */
      /* 'm2c_debug:12' flag = int32(1); */
      /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
      *flag = (M2C_DEBUG);
      if (*flag != 0) {
        /* 'petscKSPSetType:25' m2c_error('petsc:RuntimeError', 'KSPSetType returned error code %d\n', errCode) */
        gb_m2c_error(errCode);
      }
    }
  }

  emxFree_char_T(&ksptype0);

  /* 'mptKSPSetup:80' petscKSPSetFromOptions(t_ksp); */
  /* Sets KSP options from the options database. This routine must be called */
  /* before KSPSetUp() if the user is to be allowed to set the Krylov type. */
  /*  */
  /*   errCode = petscKSPSetFromOptions(ksp) */
  /*  */
  /*   SEE ALSO: petscKSPCreate, petscKSPSetOperators, petscKSPSolve, petscKSPDestroy */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode KSPSetFromOptions(KSP ksp) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPSetFromOptions.html */
  /* 'petscKSPSetFromOptions:15' errCode = int32(-1); */
  /* 'petscKSPSetFromOptions:17' if ~isempty(coder.target) */
  /* 'petscKSPSetFromOptions:18' t_ksp = PetscKSP(ksp); */
  /* Map an opaque object into a PETSc KSP object */
  /*  */
  /*   ksp = PetscKSP() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   ksp = PetscKSP(arg) or ksp = PetscKSP(arg, false) converts arg */
  /*   into a PETSc KSP object. */
  /*  */
  /*   ksp = PetscKSP(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscPC */
  /* 'PetscKSP:18' coder.inline('always'); */
  /* 'PetscKSP:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscKSP:25' if isstruct(arg) && ~isequal(arg.type, 'KSP') */
  /* 'PetscKSP:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscKSP:31' if nargin==1 || ~opaque */
  /* 'PetscKSP:32' ksp = arg; */
  /* 'petscKSPSetFromOptions:20' errCode = coder.ceval('KSPSetFromOptions', t_ksp); */
  errCode = KSPSetFromOptions(t_ksp);

  /* 'petscKSPSetFromOptions:22' toplevel = nargout>1; */
  /* 'petscKSPSetFromOptions:23' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    *flag = (M2C_DEBUG);
    if (*flag != 0) {
      /* 'petscKSPSetFromOptions:24' m2c_error('petsc:RuntimeError', 'KSPSetFromOptions returned error code %d\n', errCode) */
      m_m2c_error(errCode);
    }
  }

  /* 'mptKSPSetup:82' petscKSPSetUp(t_ksp); */
  /* Sets up the internal data structures for the later use of an iterative solver. */
  /*  */
  /*   errCode = petscKSPSetUp(ksp) */
  /*  */
  /*   SEE ALSO: petscKSPCreate, petscKSPSetOperators, petscKSPSolve, petscKSPDestroy */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode KSPSetUp(KSP ksp) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPSetUp.html */
  /* 'petscKSPSetUp:14' errCode = int32(-1); */
  /* 'petscKSPSetUp:16' if ~isempty(coder.target) */
  /* 'petscKSPSetUp:17' t_ksp = PetscKSP(ksp); */
  /* Map an opaque object into a PETSc KSP object */
  /*  */
  /*   ksp = PetscKSP() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   ksp = PetscKSP(arg) or ksp = PetscKSP(arg, false) converts arg */
  /*   into a PETSc KSP object. */
  /*  */
  /*   ksp = PetscKSP(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscPC */
  /* 'PetscKSP:18' coder.inline('always'); */
  /* 'PetscKSP:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscKSP:25' if isstruct(arg) && ~isequal(arg.type, 'KSP') */
  /* 'PetscKSP:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscKSP:31' if nargin==1 || ~opaque */
  /* 'PetscKSP:32' ksp = arg; */
  /* 'petscKSPSetUp:19' errCode = coder.ceval('KSPSetUp', t_ksp); */
  errCode = KSPSetUp(t_ksp);

  /* 'petscKSPSetUp:21' toplevel = nargout>1; */
  /* 'petscKSPSetUp:22' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    *flag = (M2C_DEBUG);
    if (*flag != 0) {
      /* 'petscKSPSetUp:23' m2c_error('petsc:RuntimeError', 'KSPSetUp returned error code %d\n', errCode) */
      n_m2c_error(errCode);
    }
  }

  /* 'mptKSPSetup:83' if nargout>1 */
  /* 'mptKSPSetup:83' time=m2c_wtime()-t; */
  /*  Return ellapsed time */
  /*    t = m2c_wtime */
  /* 'm2c_wtime:7' if isempty(coder.target) */
  /* 'm2c_wtime:10' else */
  /* 'm2c_wtime:11' coder.inline( 'always'); */
  /* 'm2c_wtime:13' t = 0; */
  /* 'm2c_wtime:13' t = coder.ceval( 'M2C_wtime'); */
  b_t = M2C_wtime();

  /* 'mptKSPSetup:85' toplevel = nargout>2; */
  /* 'mptKSPSetup:86' ksp = PetscKSP(t_ksp, toplevel); */
  /* Map an opaque object into a PETSc KSP object */
  /*  */
  /*   ksp = PetscKSP() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   ksp = PetscKSP(arg) or ksp = PetscKSP(arg, false) converts arg */
  /*   into a PETSc KSP object. */
  /*  */
  /*   ksp = PetscKSP(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscPC */
  /* 'PetscKSP:18' coder.inline('always'); */
  /* 'PetscKSP:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscKSP:25' if isstruct(arg) && ~isequal(arg.type, 'KSP') */
  /* 'PetscKSP:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscKSP:31' if nargin==1 || ~opaque */
  /* 'PetscKSP:32' ksp = arg; */
  /* 'mptSolve:73' [flag,relres,iter, time_solve] = mptKSPSolve(ksp, b, x, double(rtol), int32(maxit), x0); */
  mptKSPSolve(t_ksp, b, x, rtol, maxit, x0, flag, relres, iter, &time_solve);

  /* 'mptSolve:75' if nargout>3 */
  /* 'mptSolve:76' times = [time_setup; time_solve]; */
  times[0] = b_t - t;
  times[1] = time_solve;

  /* 'mptSolve:79' mptKSPCleanup(ksp); */
  /*  Cleans up the KSP. */
  /*  */
  /*    ksp = mptKSPCleanup(ksp) destropys the given KSP object. */
  /*    It should be called whtn the KSP object is no longer needed, and  */
  /*    no calls should be made to this KSP after this. */
  /*  */
  /*  See Also: mptKSPSetup, mptKSPSolve */
  /*  Destroy the KSP and solution vector */
  /* 'mptKSPCleanup:13' t_ksp = petscKSPDestroy(ksp); */
  /* Destroys KSP context. */
  /*  */
  /*   [ksp, errCode] = petscKSPDestroy(ksp) */
  /*  */
  /*   SEE ALSO: petscKSPCreate, petscKSPSetUp, petscKSPSolve */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode KSPDestroy(KSP *A) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPDestroy.html */
  /* 'petscKSPDestroy:14' errCode = int32(-1); */
  /* 'petscKSPDestroy:16' if ~isempty(coder.target) */
  /* 'petscKSPDestroy:17' t_ksp = PetscKSP(ksp); */
  /* Map an opaque object into a PETSc KSP object */
  /*  */
  /*   ksp = PetscKSP() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   ksp = PetscKSP(arg) or ksp = PetscKSP(arg, false) converts arg */
  /*   into a PETSc KSP object. */
  /*  */
  /*   ksp = PetscKSP(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscPC */
  /* 'PetscKSP:18' coder.inline('always'); */
  /* 'PetscKSP:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscKSP:25' if isstruct(arg) && ~isequal(arg.type, 'KSP') */
  /* 'PetscKSP:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscKSP:31' if nargin==1 || ~opaque */
  /* 'PetscKSP:32' ksp = arg; */
  /* 'petscKSPDestroy:19' errCode = coder.ceval('KSPDestroy', coder.ref(t_ksp)); */
  errCode = KSPDestroy(&t_ksp);

  /* 'petscKSPDestroy:21' toplevel = nargout>2; */
  /* 'petscKSPDestroy:22' ksp_out = PetscKSP(t_ksp, toplevel); */
  /* Map an opaque object into a PETSc KSP object */
  /*  */
  /*   ksp = PetscKSP() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   ksp = PetscKSP(arg) or ksp = PetscKSP(arg, false) converts arg */
  /*   into a PETSc KSP object. */
  /*  */
  /*   ksp = PetscKSP(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscPC */
  /* 'PetscKSP:18' coder.inline('always'); */
  /* 'PetscKSP:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscKSP:25' if isstruct(arg) && ~isequal(arg.type, 'KSP') */
  /* 'PetscKSP:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscKSP:31' if nargin==1 || ~opaque */
  /* 'PetscKSP:32' ksp = arg; */
  /* 'petscKSPDestroy:24' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      /* 'petscKSPDestroy:25' m2c_error('petsc:RuntimeError', 'KSPDestroy returned error code %d\n', errCode) */
      ab_m2c_error(errCode);
    }
  }

  /* 'mptKSPCleanup:15' toplevel = nargout>1; */
  /* 'mptKSPCleanup:16' ksp = PetscKSP(t_ksp, toplevel); */
}

/*
 * function [vec_out, toplevel] = mptVecCreateFromArray(arr, varargin)
 */
static Vec mptVecCreateFromArray(const emxArray_real_T *arr)
{
  int n;
  Vec t_vec;
  int errCode;
  int b_n;
  emxArray_int32_T *y;
  int k;
  int yk;
  emxArray_int32_T *idx;
  int iroa;

  /* Creates a vector in PETSc from a MATLAB column vector. */
  /*  */
  /*   vec = mptVecCreateFromArray(arr) */
  /*      arr:   A column vector in MATLAB */
  /*  */
  /*   vec = petscVecCreateFromArray(arr, prefix) */
  /*      prefix: if present, set options of the vector from the options database. */
  /*  */
  /*   The vector must be deallocated by calling petscVecDestroy after use. */
  /*  */
  /*   SEE ALSO: petscVecDestroy, mptVecToArray, mptOptionsInsert */
  /* 'mptVecCreateFromArray:17' if nargin<1 */
  /* 'mptVecCreateFromArray:21' n = int32(length(arr)); */
  n = arr->size[0];

  /* 'mptVecCreateFromArray:23' if nargin==1 */
  /* 'mptVecCreateFromArray:24' vec = petscVecCreateSeq(n); */
  /* Creates a standard, sequential array-style vector. */
  /*  */
  /*   [vec, errCode] = petscVecCreateSeq(n) */
  /*   n - the vector length */
  /*  */
  /*   SEE ALSO: petscAssembleVec, petscVecDestroy */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode  VecCreateSeq(MPI_Comm comm,PetscInt n,Vec *v) */
  /*          where comm should always be PETSC_COMM_SELF. */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecCreateSeq.html */
  /* 'petscVecCreateSeq:16' errCode = int32(-1); */
  /* 'petscVecCreateSeq:18' if ~isempty(coder.target) */
  /* 'petscVecCreateSeq:19' t_vec = coder.opaque('Vec'); */
  /* 'petscVecCreateSeq:21' comm = MPI_Comm(PETSC_COMM_SELF); */
  /*  Obtain PETSC constant PETSC_COMM_SELF */
  /* 'PETSC_COMM_SELF:4' coder.inline('always'); */
  /* 'PETSC_COMM_SELF:6' val = petscGetObject('PETSC_COMM_SELF'); */
  /* petscGetObject Obtain an opaque object in PETSC */
  /*  */
  /*     obj = petscGetObject(name) */
  /*  */
  /* The supported names include: */
  /*  */
  /*  MPI_Comm: PETSC_COMM_SELF, PETSC_COMM_WORLD, MPI_COMM_SELF, MPI_COMM_WORLD */
  /*  */
  /*  Other: */
  /*      PETSC_IGNORE, PETSC_NULL_OPTION, PETSC_NULL_MAT, PETSC_NULL_VEC, */
  /*      PETSC_NULL_INT, PETSC_NULL_REAL */
  /* 'petscGetObject:16' if isempty(coder.target) */
  /* 'petscGetObject:20' switch name */
  /* 'petscGetObject:25' case 'PETSC_COMM_SELF' */
  /* 'petscGetObject:26' [obj, toplevel] = get_obj('MPI_Comm', 'PETSC_COMM_SELF', nargout>1); */
  /* Map an opaque object into a PETSc MPI_Comm object */
  /*  */
  /*   comm = MPI_Comm() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   comm = MPI_Comm(arg) or comm = MPI_Comm(arg, false) converts arg */
  /*   into a PETSc Options object. */
  /*  */
  /*   comm = MPI_Comm(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'MPI_Comm:18' coder.inline('always'); */
  /* 'MPI_Comm:20' if nargin==0 && isempty(coder.target) */
  /* 'MPI_Comm:25' if isstruct(arg) && ~isequal(arg.type, 'MPI_Comm') */
  /* 'MPI_Comm:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'MPI_Comm:31' if nargin==1 || ~opaque */
  /* 'MPI_Comm:32' comm = arg; */
  /* 'petscVecCreateSeq:22' errCode = coder.ceval('VecCreateSeq', comm, n, coder.wref(t_vec)); */
  errCode = VecCreateSeq(PETSC_COMM_SELF, n, &t_vec);

  /* 'petscVecCreateSeq:24' toplevel = nargout>2; */
  /* 'petscVecCreateSeq:25' vec = PetscVec(t_vec, toplevel); */
  /* Map an opaque object into a PETSc Vec object */
  /*  */
  /*   vec = PetscVec() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   vec = PetscVec(arg) or vec = PetscVec(arg, false) converts arg */
  /*   into a PETSc Vec object. */
  /*  */
  /*   vec = PetscVec(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscVec:18' coder.inline('always'); */
  /* 'PetscVec:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscVec:25' if isstruct(arg) && ~isequal(arg.type, 'Vec') */
  /* 'PetscVec:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscVec:31' if nargin==1 || ~opaque */
  /* 'PetscVec:32' vec = arg; */
  /* 'petscVecCreateSeq:27' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    yk = (M2C_DEBUG);
    if (yk != 0) {
      /* 'petscVecCreateSeq:28' m2c_error('petsc:RuntimeError', 'VecCreateSeq returned error code %d\n', errCode) */
      e_m2c_error(errCode);
    }
  }

  /*  Set values */
  /* 'mptVecCreateFromArray:40' idx = (0:int32(n)-1)'; */
  if (n - 1 < 0) {
    b_n = 0;
  } else {
    b_n = n;
  }

  emxInit_int32_T1(&y, 2);
  k = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = b_n;
  emxEnsureCapacity((emxArray__common *)y, k, (int)sizeof(int));
  if (b_n > 0) {
    y->data[0] = 0;
    yk = 0;
    for (k = 2; k <= b_n; k++) {
      yk++;
      y->data[k - 1] = yk;
    }
  }

  emxInit_int32_T(&idx, 1);
  k = idx->size[0];
  idx->size[0] = y->size[1];
  emxEnsureCapacity((emxArray__common *)idx, k, (int)sizeof(int));
  yk = y->size[1];
  for (k = 0; k < yk; k++) {
    idx->data[k] = y->data[y->size[0] * k];
  }

  emxFree_int32_T(&y);

  /* 'mptVecCreateFromArray:41' petscVecSetValues(vec, n, idx, arr); */
  /* Inserts or adds values into certain locations of a vector. */
  /*  */
  /*   errCode = petscVecSetValues(vec, ni, ix, y) */
  /*   	vec  - vector to insert in */
  /*    ni   - number of elements to be inserted */
  /*    ix   - (0-based) indices where to insert */
  /*    y    - array of values */
  /*  */
  /*    errCode = petscVecSetValues(vec, ni, ix, y, iora) */
  /*    iora  - either INSERT_VALUES or ADD_VALUES, where INSERT_VALUES */
  /*            replaces existing entries with new values (as above) and */
  /*            ADD_VALUES adds values to any existing entries. */
  /*  */
  /*   SEE ALSO: petscAssembleVec, VecAssemblyBegin(), VecAssemblyEnd(), */
  /*             petscVecSet, petscVecCreate, petscVecDestroy */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode  VecSetValues(Vec x,PetscInt ni,const PetscInt ix[],const PetscScalar y[],InsertMode iora) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecSetValues.html */
  /* 'petscVecSetValues:25' errCode = int32(-1); */
  /* 'petscVecSetValues:27' if ~isempty(coder.target) */
  /* 'petscVecSetValues:28' if nargin<5 */
  /* 'petscVecSetValues:29' iroa = PETSC_INSERT_VALUES; */
  /*  Obtain PETSC constant INSERT_VALUES */
  /* 'PETSC_INSERT_VALUES:4' coder.inline('always'); */
  /* 'PETSC_INSERT_VALUES:6' val = petscGetEnum('INSERT_VALUES'); */
  /* petscGetEnum Obtain an enumerate value in PETSC */
  /*  */
  /*     val = petscGetEnum(name) */
  /*  */
  /* The supported names include: */
  /*  */
  /*  PetscBool:  PETSC_TRUE, PETSC_FALSE */
  /*  */
  /*  VecOption: VEC_IGNORE_OFF_PROC_ENTRIES, VEC_IGNORE_NEGATIVE_INDICES, */
  /*       VEC_SUBSET_OFF_PROC_ENTRIES */
  /*  */
  /*  MatOption: MAT_ROW_ORIENTED, MAT_SYMMETRIC, MAT_STRUCTURALLY_SYMMETRIC, */
  /*       MAT_NEW_DIAGONALS, MAT_IGNORE_OFF_PROC_ENTRIES, */
  /*       MAT_USE_HASH_TABLE, MAT_KEEP_NONZERO_PATTERN, */
  /*       MAT_IGNORE_ZERO_ENTRIES, MAT_USE_INODES, MAT_HERMITIAN, */
  /*       MAT_SYMMETRY_ETERNAL, MAT_NEW_NONZERO_LOCATION_ERR, */
  /*       MAT_IGNORE_LOWER_TRIANGULAR, MAT_ERROR_LOWER_TRIANGULAR, */
  /*       MAT_GETROW_UPPERTRIANGULAR, MAT_SPD, */
  /*       MAT_NO_OFF_PROC_ZERO_ROWS, MAT_NO_OFF_PROC_ENTRIES, */
  /*       MAT_NEW_NONZERO_LOCATIONS, MAT_NEW_NONZERO_ALLOCATION_ERR, */
  /*       MAT_SUBSET_OFF_PROC_ENTRIES */
  /*  */
  /*  MatStructure: DIFFERENT_NONZERO_PATTERN, SUBSET_NONZERO_PATTERN, SAME_NONZERO_PATTERN */
  /*  */
  /*  MatDuplicateOption: MAT_DO_NOT_COPY_VALUES,MAT_COPY_VALUES,MAT_SHARE_NONZERO_PATTERN */
  /*  */
  /*  MatReuse: MAT_INITIAL_MATRIX,MAT_REUSE_MATRIX,MAT_IGNORE_MATRIX,MAT_INPLACE_MATRIX */
  /*  */
  /*  InsertMode: INSERT_VALUES, ADD_VALUES, MAX_VALUES, */
  /*       INSERT_ALL_VALUES, ADD_ALL_VALUES, INSERT_BC_VALUES, ADD_BC_VALUES */
  /*  */
  /*  MatAssemblyType: MAT_FINAL_ASSEMBLY, MAT_FLUSH_ASSEMBLY */
  /*  */
  /*  MatInfoType: MAT_LOCAL,MAT_GLOBAL_MAX,MAT_GLOBAL_SUM */
  /*  */
  /*  MatFactorType: MAT_FACTOR_NONE, MAT_FACTOR_LU, MAT_FACTOR_CHOLESKY,  */
  /*       MAT_FACTOR_ILU, MAT_FACTOR_ICC,MAT_FACTOR_ILUDT */
  /*  */
  /*  NormType: NORM_1, NORM_2, NORM_FROBENIUS, NORM_INFINITY, NORM_1_AND_2 */
  /*  */
  /*  Others:  PETSC_DETERMINE, PETSC_DECIDE, PETSC_DEFAULT */
  /* 'petscGetEnum:46' if isempty(coder.target) */
  /* 'petscGetEnum:50' coder.cinclude('petscsys.h'); */
  /* 'petscGetEnum:51' coder.cinclude('petscksp.h'); */
  /* % InsertMode */
  /* 'petscGetEnum:54' switch name */
  /* 'petscGetEnum:81' case 'INSERT_VALUES' */
  /* 'petscGetEnum:82' [val, toplevel] = get_val('InsertMode', 'INSERT_VALUES', nargin>1); */
  /* 'petscGetEnum:183' coder.inline('always'); */
  /* 'petscGetEnum:185' val = int32(intmin); */
  /* 'petscGetEnum:186' val = coder.ceval(' ', coder.opaque(type, name)); */
  iroa = (INSERT_VALUES);

  /* 'petscVecSetValues:32' t_vec = PetscVec(vec); */
  /* Map an opaque object into a PETSc Vec object */
  /*  */
  /*   vec = PetscVec() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   vec = PetscVec(arg) or vec = PetscVec(arg, false) converts arg */
  /*   into a PETSc Vec object. */
  /*  */
  /*   vec = PetscVec(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscVec:18' coder.inline('always'); */
  /* 'PetscVec:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscVec:25' if isstruct(arg) && ~isequal(arg.type, 'Vec') */
  /* 'PetscVec:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscVec:31' if nargin==1 || ~opaque */
  /* 'PetscVec:32' vec = arg; */
  /* 'petscVecSetValues:34' errCode = coder.ceval('VecSetValues', t_vec, ni, coder.rref(ix), coder.rref(y), iroa); */
  errCode = VecSetValues(t_vec, n, &idx->data[0], &arr->data[0], iroa);

  /* 'petscVecSetValues:36' toplevel = nargout>1; */
  /* 'petscVecSetValues:37' if errCode && (toplevel || m2c_debug) */
  emxFree_int32_T(&idx);
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    yk = (M2C_DEBUG);
    if (yk != 0) {
      /* 'petscVecSetValues:38' m2c_error('petsc:RuntimeError', 'VecSetValues returned error code %d\n', errCode); */
      f_m2c_error(errCode);
    }
  }

  /*  Call assembly */
  /* 'mptVecCreateFromArray:44' petscVecAssemblyBegin(vec); */
  /* Frees space taken by a vector. */
  /*  */
  /*   errCode = petscVecAssemblyBegin(vec) */
  /*  */
  /*   SEE ALSO: petscAssembleVec, petscVecAssemblyEnd, petscVecSetValues */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode VecAssemblyBegin(Vec *A) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecAssemblyBegin.html */
  /* 'petscVecAssemblyBegin:14' errCode = int32(-1); */
  /* 'petscVecAssemblyBegin:16' if ~isempty(coder.target) */
  /* 'petscVecAssemblyBegin:17' t_vec = PetscVec(vec); */
  /* Map an opaque object into a PETSc Vec object */
  /*  */
  /*   vec = PetscVec() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   vec = PetscVec(arg) or vec = PetscVec(arg, false) converts arg */
  /*   into a PETSc Vec object. */
  /*  */
  /*   vec = PetscVec(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscVec:18' coder.inline('always'); */
  /* 'PetscVec:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscVec:25' if isstruct(arg) && ~isequal(arg.type, 'Vec') */
  /* 'PetscVec:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscVec:31' if nargin==1 || ~opaque */
  /* 'PetscVec:32' vec = arg; */
  /* 'petscVecAssemblyBegin:19' errCode = coder.ceval('VecAssemblyBegin', t_vec); */
  errCode = VecAssemblyBegin(t_vec);

  /* 'petscVecAssemblyBegin:21' toplevel = nargout>1; */
  /* 'petscVecAssemblyBegin:22' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    yk = (M2C_DEBUG);
    if (yk != 0) {
      /* 'petscVecAssemblyBegin:23' m2c_error('petsc:RuntimeError', 'VecAssemblyBegin returned error code %d\n', errCode) */
      g_m2c_error(errCode);
    }
  }

  /* 'mptVecCreateFromArray:45' petscVecAssemblyEnd(vec); */
  /* Frees space taken by a vector. */
  /*  */
  /*   errCode = petscVecAssemblyEnd(vec) */
  /*  */
  /*   SEE ALSO: petscAssembleVec, petscVecAssemblyBegin, petscVecSetValues */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode VecAssemblyEnd(Vec *A) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecAssemblyEnd.html */
  /* 'petscVecAssemblyEnd:14' errCode = int32(-1); */
  /* 'petscVecAssemblyEnd:16' if ~isempty(coder.target) */
  /* 'petscVecAssemblyEnd:17' t_vec = PetscVec(vec); */
  /* Map an opaque object into a PETSc Vec object */
  /*  */
  /*   vec = PetscVec() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   vec = PetscVec(arg) or vec = PetscVec(arg, false) converts arg */
  /*   into a PETSc Vec object. */
  /*  */
  /*   vec = PetscVec(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscVec:18' coder.inline('always'); */
  /* 'PetscVec:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscVec:25' if isstruct(arg) && ~isequal(arg.type, 'Vec') */
  /* 'PetscVec:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscVec:31' if nargin==1 || ~opaque */
  /* 'PetscVec:32' vec = arg; */
  /* 'petscVecAssemblyEnd:19' errCode = coder.ceval('VecAssemblyEnd', t_vec); */
  errCode = VecAssemblyEnd(t_vec);

  /* 'petscVecAssemblyEnd:21' toplevel = nargout>1; */
  /* 'petscVecAssemblyEnd:22' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    yk = (M2C_DEBUG);
    if (yk != 0) {
      /* 'petscVecAssemblyEnd:23' m2c_error('petsc:RuntimeError', 'VecAssemblyEnd returned error code %d\n', errCode) */
      h_m2c_error(errCode);
    }
  }

  /* 'mptVecCreateFromArray:47' toplevel = nargout>1; */
  /* 'mptVecCreateFromArray:48' vec_out = PetscVec(vec, toplevel); */
  /* Map an opaque object into a PETSc Vec object */
  /*  */
  /*   vec = PetscVec() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   vec = PetscVec(arg) or vec = PetscVec(arg, false) converts arg */
  /*   into a PETSc Vec object. */
  /*  */
  /*   vec = PetscVec(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscVec:18' coder.inline('always'); */
  /* 'PetscVec:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscVec:25' if isstruct(arg) && ~isequal(arg.type, 'Vec') */
  /* 'PetscVec:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscVec:31' if nargin==1 || ~opaque */
  /* 'PetscVec:32' vec = arg; */
  return t_vec;
}

/*
 * function arr = mptVecToArray(vec)
 */
static void mptVecToArray(Vec vec, emxArray_real_T *arr)
{
  int n;
  int errCode;
  int k;
  int b_n;
  int yk;
  emxArray_int32_T *y;
  emxArray_int32_T *idx;

  /* Export the local portion of a vector in PETSc to a MATLAB array. */
  /*  */
  /*   arr = mptVecToArray(vec) */
  /*      exports the PETSc vector vec into an array arr */
  /*  */
  /*   SEE ALSO: mptVecCreateFromArray */
  /* 'mptVecToArray:11' if nargin<1 */
  /* 'mptVecToArray:15' n = petscVecGetLocalSize(vec); */
  /* Returns the local number of elements of the vector. */
  /*  */
  /* [n, errCode] = petscVecGetLocalSize(vec) */
  /*   	vec   - the vector */
  /*    n     - the number of elements */
  /*  */
  /*   SEE ALSO: petscVecSetSizes, petscVecGetSize */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode VecGetLocalSize(Vec vec,PetscInt *n) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecGetLocalSize.html */
  /* 'petscVecGetLocalSize:16' errCode = int32(-1); */
  /* 'petscVecGetLocalSize:18' if ~isempty(coder.target) */
  /* 'petscVecGetLocalSize:19' t_vec = PetscVec(vec); */
  /* Map an opaque object into a PETSc Vec object */
  /*  */
  /*   vec = PetscVec() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   vec = PetscVec(arg) or vec = PetscVec(arg, false) converts arg */
  /*   into a PETSc Vec object. */
  /*  */
  /*   vec = PetscVec(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscVec:18' coder.inline('always'); */
  /* 'PetscVec:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscVec:25' if isstruct(arg) && ~isequal(arg.type, 'Vec') */
  /* 'PetscVec:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscVec:31' if nargin==1 || ~opaque */
  /* 'PetscVec:32' vec = arg; */
  /* 'petscVecGetLocalSize:21' n = int32(0); */
  /* 'petscVecGetLocalSize:22' errCode = coder.ceval('VecGetLocalSize', t_vec, coder.wref(n)); */
  errCode = VecGetLocalSize(vec, &n);

  /* 'petscVecGetLocalSize:24' toplevel = nargout>2; */
  /* 'petscVecGetLocalSize:25' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    yk = (M2C_DEBUG);
    if (yk != 0) {
      /* 'petscVecGetLocalSize:26' m2c_error('petsc:RuntimeError', 'VecGetLocalSize returned error code %d\n', errCode) */
      db_m2c_error(errCode);
    }
  }

  /* 'mptVecToArray:16' arr = coder.nullcopy(zeros(n, 1)); */
  k = arr->size[0];
  arr->size[0] = n;
  emxEnsureCapacity((emxArray__common *)arr, k, (int)sizeof(double));

  /*  Obtain values */
  /* 'mptVecToArray:19' idx = (0:int32(n)-1)'; */
  if (n - 1 < 0) {
    b_n = 0;
  } else {
    b_n = n;
  }

  emxInit_int32_T1(&y, 2);
  k = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = b_n;
  emxEnsureCapacity((emxArray__common *)y, k, (int)sizeof(int));
  if (b_n > 0) {
    y->data[0] = 0;
    yk = 0;
    for (k = 2; k <= b_n; k++) {
      yk++;
      y->data[k - 1] = yk;
    }
  }

  emxInit_int32_T(&idx, 1);
  k = idx->size[0];
  idx->size[0] = y->size[1];
  emxEnsureCapacity((emxArray__common *)idx, k, (int)sizeof(int));
  yk = y->size[1];
  for (k = 0; k < yk; k++) {
    idx->data[k] = y->data[y->size[0] * k];
  }

  emxFree_int32_T(&y);

  /* 'mptVecToArray:20' arr = petscVecGetValues(vec, n, idx, arr); */
  /* Gets values from certain locations of a vector.  */
  /* Currently can only get values on the same processor */
  /*  */
  /*   [y, errCode] = petscVecGetValues(vec, ni, ix) */
  /*   	  vec - vector to get values from */
  /*      ni  - number of elements to get */
  /*      ix  - indices where to get them from (0-based in global 1d numbering) */
  /*  */
  /*   [y, errCode] = petscVecGetValues(vec, ni, ix, y) */
  /*      Use preallocated storage in y */
  /*  */
  /*   SEE ALSO: petscVecAssemblyBegin, petscVecAssemblyEnd, petscVecSetValues */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode  VecGetValues(Vec x,PetscInt ni,const PetscInt ix[],PetscScalar y[]) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecGetValues.html */
  /* 'petscVecGetValues:22' errCode = int32(-1); */
  /* 'petscVecGetValues:24' if ~isempty(coder.target) */
  /* 'petscVecGetValues:25' if nargin<4 */
  if (arr->size[0] < n) {
    /* 'petscVecGetValues:27' elseif length(y) < ni */
    /* 'petscVecGetValues:28' m2c_error('Output array y is too small.'); */
    eb_m2c_error();
  }

  /* 'petscVecGetValues:31' t_vec = PetscVec(vec); */
  /* Map an opaque object into a PETSc Vec object */
  /*  */
  /*   vec = PetscVec() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   vec = PetscVec(arg) or vec = PetscVec(arg, false) converts arg */
  /*   into a PETSc Vec object. */
  /*  */
  /*   vec = PetscVec(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscVec:18' coder.inline('always'); */
  /* 'PetscVec:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscVec:25' if isstruct(arg) && ~isequal(arg.type, 'Vec') */
  /* 'PetscVec:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscVec:31' if nargin==1 || ~opaque */
  /* 'PetscVec:32' vec = arg; */
  /* 'petscVecGetValues:32' errCode = coder.ceval('VecGetValues', t_vec, ni, coder.rref(ix), coder.ref(y)); */
  errCode = VecGetValues(vec, n, &idx->data[0], &arr->data[0]);

  /* 'petscVecGetValues:34' toplevel = nargout>2; */
  /* 'petscVecGetValues:35' if errCode && (toplevel || m2c_debug) */
  emxFree_int32_T(&idx);
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    yk = (M2C_DEBUG);
    if (yk != 0) {
      /* 'petscVecGetValues:36' m2c_error('petsc:RuntimeError', 'VecGetValues returned error code %d\n', errCode) */
      fb_m2c_error(errCode);
    }
  }
}

/*
 * function m2c_error(varargin)
 */
static void n_m2c_error(int varargin_3)
{
  /* m2c_error Issue a fatal error message. */
  /*   */
  /*  m2c_error(msg); */
  /*  m2c_error(fmt, null_terminated_char, number, ...); */
  /*  m2c_error(msg_id, fmt, null_terminated_char, number, ...); */
  /*  */
  /*  Note that the character strings associated with %s in the format must */
  /*  be null-terminated character strings. */
  /*  */
  /*  Example usage: */
  /*     m2c_error('Error message in a constant string does not need to be null-terminated.'); */
  /*     m2c_error('Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*     m2c_error('error:ID', 'Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*  */
  /*  SEE ALSO: m2c_print, m2c_warn */
  /* 'm2c_error:18' coder.inline('never'); */
  /* 'm2c_error:20' if isempty(coder.target) */
  /* 'm2c_error:22' else */
  /* 'm2c_error:23' if isequal(coder.target, 'mex') */
  /* 'm2c_error:25' else */
  /* 'm2c_error:26' cmd = 'M2C_error'; */
  /* 'm2c_error:29' if nargin==1 || ischar(varargin{1}) && ~ischar(varargin{2}) */
  /* 'm2c_error:35' else */
  /* 'm2c_error:36' msgid = coder.opaque('const char *', ['"' varargin{1} '"']); */
  /* 'm2c_error:38' fmt = coder.opaque('const char *', ['"' varargin{2} '"']); */
  /* 'm2c_error:39' coder.ceval(cmd, msgid, fmt, varargin{3:end}); */
  M2C_error("petsc:RuntimeError", "KSPSetUp returned error code %d\n",
            varargin_3);
}

/*
 * function m2c_error(varargin)
 */
static void o_m2c_error(int varargin_3)
{
  /* m2c_error Issue a fatal error message. */
  /*   */
  /*  m2c_error(msg); */
  /*  m2c_error(fmt, null_terminated_char, number, ...); */
  /*  m2c_error(msg_id, fmt, null_terminated_char, number, ...); */
  /*  */
  /*  Note that the character strings associated with %s in the format must */
  /*  be null-terminated character strings. */
  /*  */
  /*  Example usage: */
  /*     m2c_error('Error message in a constant string does not need to be null-terminated.'); */
  /*     m2c_error('Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*     m2c_error('error:ID', 'Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*  */
  /*  SEE ALSO: m2c_print, m2c_warn */
  /* 'm2c_error:18' coder.inline('never'); */
  /* 'm2c_error:20' if isempty(coder.target) */
  /* 'm2c_error:22' else */
  /* 'm2c_error:23' if isequal(coder.target, 'mex') */
  /* 'm2c_error:25' else */
  /* 'm2c_error:26' cmd = 'M2C_error'; */
  /* 'm2c_error:29' if nargin==1 || ischar(varargin{1}) && ~ischar(varargin{2}) */
  /* 'm2c_error:35' else */
  /* 'm2c_error:36' msgid = coder.opaque('const char *', ['"' varargin{1} '"']); */
  /* 'm2c_error:38' fmt = coder.opaque('const char *', ['"' varargin{2} '"']); */
  /* 'm2c_error:39' coder.ceval(cmd, msgid, fmt, varargin{3:end}); */
  M2C_error("petsc:RuntimeError", "KSPSetTolerances returned error code %d\n",
            varargin_3);
}

/*
 * function m2c_error(varargin)
 */
static void p_m2c_error(int varargin_3)
{
  /* m2c_error Issue a fatal error message. */
  /*   */
  /*  m2c_error(msg); */
  /*  m2c_error(fmt, null_terminated_char, number, ...); */
  /*  m2c_error(msg_id, fmt, null_terminated_char, number, ...); */
  /*  */
  /*  Note that the character strings associated with %s in the format must */
  /*  be null-terminated character strings. */
  /*  */
  /*  Example usage: */
  /*     m2c_error('Error message in a constant string does not need to be null-terminated.'); */
  /*     m2c_error('Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*     m2c_error('error:ID', 'Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*  */
  /*  SEE ALSO: m2c_print, m2c_warn */
  /* 'm2c_error:18' coder.inline('never'); */
  /* 'm2c_error:20' if isempty(coder.target) */
  /* 'm2c_error:22' else */
  /* 'm2c_error:23' if isequal(coder.target, 'mex') */
  /* 'm2c_error:25' else */
  /* 'm2c_error:26' cmd = 'M2C_error'; */
  /* 'm2c_error:29' if nargin==1 || ischar(varargin{1}) && ~ischar(varargin{2}) */
  /* 'm2c_error:35' else */
  /* 'm2c_error:36' msgid = coder.opaque('const char *', ['"' varargin{1} '"']); */
  /* 'm2c_error:38' fmt = coder.opaque('const char *', ['"' varargin{2} '"']); */
  /* 'm2c_error:39' coder.ceval(cmd, msgid, fmt, varargin{3:end}); */
  M2C_error("petsc:RuntimeError", "VecCopy returned error code %d\n", varargin_3);
}

/*
 * function m2c_error(varargin)
 */
static void q_m2c_error(int varargin_3)
{
  /* m2c_error Issue a fatal error message. */
  /*   */
  /*  m2c_error(msg); */
  /*  m2c_error(fmt, null_terminated_char, number, ...); */
  /*  m2c_error(msg_id, fmt, null_terminated_char, number, ...); */
  /*  */
  /*  Note that the character strings associated with %s in the format must */
  /*  be null-terminated character strings. */
  /*  */
  /*  Example usage: */
  /*     m2c_error('Error message in a constant string does not need to be null-terminated.'); */
  /*     m2c_error('Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*     m2c_error('error:ID', 'Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*  */
  /*  SEE ALSO: m2c_print, m2c_warn */
  /* 'm2c_error:18' coder.inline('never'); */
  /* 'm2c_error:20' if isempty(coder.target) */
  /* 'm2c_error:22' else */
  /* 'm2c_error:23' if isequal(coder.target, 'mex') */
  /* 'm2c_error:25' else */
  /* 'm2c_error:26' cmd = 'M2C_error'; */
  /* 'm2c_error:29' if nargin==1 || ischar(varargin{1}) && ~ischar(varargin{2}) */
  /* 'm2c_error:35' else */
  /* 'm2c_error:36' msgid = coder.opaque('const char *', ['"' varargin{1} '"']); */
  /* 'm2c_error:38' fmt = coder.opaque('const char *', ['"' varargin{2} '"']); */
  /* 'm2c_error:39' coder.ceval(cmd, msgid, fmt, varargin{3:end}); */
  M2C_error("petsc:RuntimeError",
            "KSPSetInitialGuessNonzero returned error code %d\n", varargin_3);
}

/*
 * function m2c_error(varargin)
 */
static void r_m2c_error(int varargin_3)
{
  /* m2c_error Issue a fatal error message. */
  /*   */
  /*  m2c_error(msg); */
  /*  m2c_error(fmt, null_terminated_char, number, ...); */
  /*  m2c_error(msg_id, fmt, null_terminated_char, number, ...); */
  /*  */
  /*  Note that the character strings associated with %s in the format must */
  /*  be null-terminated character strings. */
  /*  */
  /*  Example usage: */
  /*     m2c_error('Error message in a constant string does not need to be null-terminated.'); */
  /*     m2c_error('Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*     m2c_error('error:ID', 'Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*  */
  /*  SEE ALSO: m2c_print, m2c_warn */
  /* 'm2c_error:18' coder.inline('never'); */
  /* 'm2c_error:20' if isempty(coder.target) */
  /* 'm2c_error:22' else */
  /* 'm2c_error:23' if isequal(coder.target, 'mex') */
  /* 'm2c_error:25' else */
  /* 'm2c_error:26' cmd = 'M2C_error'; */
  /* 'm2c_error:29' if nargin==1 || ischar(varargin{1}) && ~ischar(varargin{2}) */
  /* 'm2c_error:35' else */
  /* 'm2c_error:36' msgid = coder.opaque('const char *', ['"' varargin{1} '"']); */
  /* 'm2c_error:38' fmt = coder.opaque('const char *', ['"' varargin{2} '"']); */
  /* 'm2c_error:39' coder.ceval(cmd, msgid, fmt, varargin{3:end}); */
  M2C_error("petsc:RuntimeError", "KSPSolve returned error code %d\n",
            varargin_3);
}

/*
 * function m2c_error(varargin)
 */
static void s_m2c_error(int varargin_3)
{
  /* m2c_error Issue a fatal error message. */
  /*   */
  /*  m2c_error(msg); */
  /*  m2c_error(fmt, null_terminated_char, number, ...); */
  /*  m2c_error(msg_id, fmt, null_terminated_char, number, ...); */
  /*  */
  /*  Note that the character strings associated with %s in the format must */
  /*  be null-terminated character strings. */
  /*  */
  /*  Example usage: */
  /*     m2c_error('Error message in a constant string does not need to be null-terminated.'); */
  /*     m2c_error('Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*     m2c_error('error:ID', 'Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*  */
  /*  SEE ALSO: m2c_print, m2c_warn */
  /* 'm2c_error:18' coder.inline('never'); */
  /* 'm2c_error:20' if isempty(coder.target) */
  /* 'm2c_error:22' else */
  /* 'm2c_error:23' if isequal(coder.target, 'mex') */
  /* 'm2c_error:25' else */
  /* 'm2c_error:26' cmd = 'M2C_error'; */
  /* 'm2c_error:29' if nargin==1 || ischar(varargin{1}) && ~ischar(varargin{2}) */
  /* 'm2c_error:35' else */
  /* 'm2c_error:36' msgid = coder.opaque('const char *', ['"' varargin{1} '"']); */
  /* 'm2c_error:38' fmt = coder.opaque('const char *', ['"' varargin{2} '"']); */
  /* 'm2c_error:39' coder.ceval(cmd, msgid, fmt, varargin{3:end}); */
  M2C_error("petsc:RuntimeError",
            "KSPGetConvergedReason returned error code %d\n", varargin_3);
}

/*
 * function m2c_error(varargin)
 */
static void t_m2c_error(int varargin_3)
{
  /* m2c_error Issue a fatal error message. */
  /*   */
  /*  m2c_error(msg); */
  /*  m2c_error(fmt, null_terminated_char, number, ...); */
  /*  m2c_error(msg_id, fmt, null_terminated_char, number, ...); */
  /*  */
  /*  Note that the character strings associated with %s in the format must */
  /*  be null-terminated character strings. */
  /*  */
  /*  Example usage: */
  /*     m2c_error('Error message in a constant string does not need to be null-terminated.'); */
  /*     m2c_error('Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*     m2c_error('error:ID', 'Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*  */
  /*  SEE ALSO: m2c_print, m2c_warn */
  /* 'm2c_error:18' coder.inline('never'); */
  /* 'm2c_error:20' if isempty(coder.target) */
  /* 'm2c_error:22' else */
  /* 'm2c_error:23' if isequal(coder.target, 'mex') */
  /* 'm2c_error:25' else */
  /* 'm2c_error:26' cmd = 'M2C_error'; */
  /* 'm2c_error:29' if nargin==1 || ischar(varargin{1}) && ~ischar(varargin{2}) */
  /* 'm2c_error:35' else */
  /* 'm2c_error:36' msgid = coder.opaque('const char *', ['"' varargin{1} '"']); */
  /* 'm2c_error:38' fmt = coder.opaque('const char *', ['"' varargin{2} '"']); */
  /* 'm2c_error:39' coder.ceval(cmd, msgid, fmt, varargin{3:end}); */
  M2C_error("petsc:RuntimeError", "KSPGetResidualNorm returned error code %d\n",
            varargin_3);
}

/*
 * function m2c_error(varargin)
 */
static void u_m2c_error(int varargin_3)
{
  /* m2c_error Issue a fatal error message. */
  /*   */
  /*  m2c_error(msg); */
  /*  m2c_error(fmt, null_terminated_char, number, ...); */
  /*  m2c_error(msg_id, fmt, null_terminated_char, number, ...); */
  /*  */
  /*  Note that the character strings associated with %s in the format must */
  /*  be null-terminated character strings. */
  /*  */
  /*  Example usage: */
  /*     m2c_error('Error message in a constant string does not need to be null-terminated.'); */
  /*     m2c_error('Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*     m2c_error('error:ID', 'Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*  */
  /*  SEE ALSO: m2c_print, m2c_warn */
  /* 'm2c_error:18' coder.inline('never'); */
  /* 'm2c_error:20' if isempty(coder.target) */
  /* 'm2c_error:22' else */
  /* 'm2c_error:23' if isequal(coder.target, 'mex') */
  /* 'm2c_error:25' else */
  /* 'm2c_error:26' cmd = 'M2C_error'; */
  /* 'm2c_error:29' if nargin==1 || ischar(varargin{1}) && ~ischar(varargin{2}) */
  /* 'm2c_error:35' else */
  /* 'm2c_error:36' msgid = coder.opaque('const char *', ['"' varargin{1} '"']); */
  /* 'm2c_error:38' fmt = coder.opaque('const char *', ['"' varargin{2} '"']); */
  /* 'm2c_error:39' coder.ceval(cmd, msgid, fmt, varargin{3:end}); */
  M2C_error("petsc:RuntimeError",
            "KSPGetIterationNumber returned error code %d\n", varargin_3);
}

/*
 * function m2c_error(varargin)
 */
static void v_m2c_error(int varargin_3)
{
  /* m2c_error Issue a fatal error message. */
  /*   */
  /*  m2c_error(msg); */
  /*  m2c_error(fmt, null_terminated_char, number, ...); */
  /*  m2c_error(msg_id, fmt, null_terminated_char, number, ...); */
  /*  */
  /*  Note that the character strings associated with %s in the format must */
  /*  be null-terminated character strings. */
  /*  */
  /*  Example usage: */
  /*     m2c_error('Error message in a constant string does not need to be null-terminated.'); */
  /*     m2c_error('Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*     m2c_error('error:ID', 'Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*  */
  /*  SEE ALSO: m2c_print, m2c_warn */
  /* 'm2c_error:18' coder.inline('never'); */
  /* 'm2c_error:20' if isempty(coder.target) */
  /* 'm2c_error:22' else */
  /* 'm2c_error:23' if isequal(coder.target, 'mex') */
  /* 'm2c_error:25' else */
  /* 'm2c_error:26' cmd = 'M2C_error'; */
  /* 'm2c_error:29' if nargin==1 || ischar(varargin{1}) && ~ischar(varargin{2}) */
  /* 'm2c_error:35' else */
  /* 'm2c_error:36' msgid = coder.opaque('const char *', ['"' varargin{1} '"']); */
  /* 'm2c_error:38' fmt = coder.opaque('const char *', ['"' varargin{2} '"']); */
  /* 'm2c_error:39' coder.ceval(cmd, msgid, fmt, varargin{3:end}); */
  M2C_error("petsc:RuntimeError", "KSPGetTolerances returned error code %d\n",
            varargin_3);
}

/*
 * function m2c_error(varargin)
 */
static void w_m2c_error(int varargin_3)
{
  /* m2c_error Issue a fatal error message. */
  /*   */
  /*  m2c_error(msg); */
  /*  m2c_error(fmt, null_terminated_char, number, ...); */
  /*  m2c_error(msg_id, fmt, null_terminated_char, number, ...); */
  /*  */
  /*  Note that the character strings associated with %s in the format must */
  /*  be null-terminated character strings. */
  /*  */
  /*  Example usage: */
  /*     m2c_error('Error message in a constant string does not need to be null-terminated.'); */
  /*     m2c_error('Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*     m2c_error('error:ID', 'Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*  */
  /*  SEE ALSO: m2c_print, m2c_warn */
  /* 'm2c_error:18' coder.inline('never'); */
  /* 'm2c_error:20' if isempty(coder.target) */
  /* 'm2c_error:22' else */
  /* 'm2c_error:23' if isequal(coder.target, 'mex') */
  /* 'm2c_error:25' else */
  /* 'm2c_error:26' cmd = 'M2C_error'; */
  /* 'm2c_error:29' if nargin==1 || ischar(varargin{1}) && ~ischar(varargin{2}) */
  /* 'm2c_error:35' else */
  /* 'm2c_error:36' msgid = coder.opaque('const char *', ['"' varargin{1} '"']); */
  /* 'm2c_error:38' fmt = coder.opaque('const char *', ['"' varargin{2} '"']); */
  /* 'm2c_error:39' coder.ceval(cmd, msgid, fmt, varargin{3:end}); */
  M2C_error("petsc:RuntimeError", "KSPGetPC returned error code %d\n",
            varargin_3);
}

/*
 * function m2c_error(varargin)
 */
static void x_m2c_error(int varargin_3)
{
  /* m2c_error Issue a fatal error message. */
  /*   */
  /*  m2c_error(msg); */
  /*  m2c_error(fmt, null_terminated_char, number, ...); */
  /*  m2c_error(msg_id, fmt, null_terminated_char, number, ...); */
  /*  */
  /*  Note that the character strings associated with %s in the format must */
  /*  be null-terminated character strings. */
  /*  */
  /*  Example usage: */
  /*     m2c_error('Error message in a constant string does not need to be null-terminated.'); */
  /*     m2c_error('Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*     m2c_error('error:ID', 'Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*  */
  /*  SEE ALSO: m2c_print, m2c_warn */
  /* 'm2c_error:18' coder.inline('never'); */
  /* 'm2c_error:20' if isempty(coder.target) */
  /* 'm2c_error:22' else */
  /* 'm2c_error:23' if isequal(coder.target, 'mex') */
  /* 'm2c_error:25' else */
  /* 'm2c_error:26' cmd = 'M2C_error'; */
  /* 'm2c_error:29' if nargin==1 || ischar(varargin{1}) && ~ischar(varargin{2}) */
  /* 'm2c_error:35' else */
  /* 'm2c_error:36' msgid = coder.opaque('const char *', ['"' varargin{1} '"']); */
  /* 'm2c_error:38' fmt = coder.opaque('const char *', ['"' varargin{2} '"']); */
  /* 'm2c_error:39' coder.ceval(cmd, msgid, fmt, varargin{3:end}); */
  M2C_error("petsc:RuntimeError", "KSPGetType returned error code %d\n",
            varargin_3);
}

/*
 * function m2c_error(varargin)
 */
static void y_m2c_error(int varargin_3)
{
  /* m2c_error Issue a fatal error message. */
  /*   */
  /*  m2c_error(msg); */
  /*  m2c_error(fmt, null_terminated_char, number, ...); */
  /*  m2c_error(msg_id, fmt, null_terminated_char, number, ...); */
  /*  */
  /*  Note that the character strings associated with %s in the format must */
  /*  be null-terminated character strings. */
  /*  */
  /*  Example usage: */
  /*     m2c_error('Error message in a constant string does not need to be null-terminated.'); */
  /*     m2c_error('Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*     m2c_error('error:ID', 'Error ID %d - message %s.', int32(10), ['Need to be null-terminated' char(0)]); */
  /*  */
  /*  SEE ALSO: m2c_print, m2c_warn */
  /* 'm2c_error:18' coder.inline('never'); */
  /* 'm2c_error:20' if isempty(coder.target) */
  /* 'm2c_error:22' else */
  /* 'm2c_error:23' if isequal(coder.target, 'mex') */
  /* 'm2c_error:25' else */
  /* 'm2c_error:26' cmd = 'M2C_error'; */
  /* 'm2c_error:29' if nargin==1 || ischar(varargin{1}) && ~ischar(varargin{2}) */
  /* 'm2c_error:35' else */
  /* 'm2c_error:36' msgid = coder.opaque('const char *', ['"' varargin{1} '"']); */
  /* 'm2c_error:38' fmt = coder.opaque('const char *', ['"' varargin{2} '"']); */
  /* 'm2c_error:39' coder.ceval(cmd, msgid, fmt, varargin{3:end}); */
  M2C_error("petsc:RuntimeError", "PCGetType returned error code %d\n",
            varargin_3);
}

void emxInitArray_char_T(emxArray_char_T **pEmxArray, int numDimensions)
{
  emxInit_char_T(pEmxArray, numDimensions);
}

void emxInitArray_int32_T(emxArray_int32_T **pEmxArray, int numDimensions)
{
  emxInit_int32_T(pEmxArray, numDimensions);
}

void emxInitArray_real_T(emxArray_real_T **pEmxArray, int numDimensions)
{
  emxInit_real_T(pEmxArray, numDimensions);
}

/*
 * function [x, flag, relres, iter, times] = mptSolveCRS(varargin)
 */
void mptSolveCRS(int *flag, double *relres, int *iter, double times[2])
{
  int i;

  /*  Solves a linear system using any PETSc solver for matrix in CRS format. */
  /*  */
  /*  Syntax: */
  /*     mptSolveCRS(Arows, Acols, Avals, b) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, solpack) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, solpack, x0) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, solpack, x0, opts) */
  /*  */
  /*     [x, flag, reslres, iter, times] = mptSolveCRS(Arows, Acols, Avals, b, ...) */
  /*  */
  /*     A is a sparse matrix in CRS format. b, x and resvec are all regular */
  /*     vectors. Solver is a value of PETSC_KSP*. pctype is a value of */
  /*     PETSC_PC*, and solpack is a value of PETSC_MATSOLVER*. */
  /*  */
  /*     For rtol, maxit, use 0 to use default values. */
  /*     For solver, pctype, solpack and opts, use empty string ('') to use default. */
  /*     For x0, use zeros(0, 1) to disable initial guess. */
  /*  */
  /*     When times is given, it returns a 2-vector contaning the times spent */
  /*     in setup and in solve separately. */
  /*  */
  /*  Description: */
  /*     mptSolveCRS(Arows, Acols, Avals, b) solves the linear system without */
  /*     preconditioners, using the default tolerances or those that have been */
  /*     set previously in the option databases. */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver) specifies to use a */
  /*     specific solver, such as PETSC_KSPGMRES, PETSC_KSPBCGS, etc. */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol) uses the given number */
  /*         of solvers and the relative tolerarance. */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit) solves with */
  /*         the given relative tolerances and maximum iteration count. */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype) */
  /*     uses the specified preconditioner (those give by PETSC_PC*). */
  /*     The preconditioner can be controlled by the PETSc option database. */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, */
  /*     solpack) specifies the solver packages for factorization (those give */
  /*     by PETSC_MATSOLVER*). */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, */
  /*     solpack, x0) usee x0 for the initial guess. x0 can be the same as x. */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, */
  /*     solpack, x0, opts) can pass additional command-line options in a */
  /*     string to PETSc. */
  /*  */
  /*  SEE ALSO: mptSolve, mptMatCreateAIJFromCRS, mptVecCreateFromArray, */
  /*            mptVecToArray, mptKSPSetup, mptKSPSolve, mptKSPCleanup */
  /* 'mptSolveCRS:81' if nargin==0 */
  /* 'mptSolveCRS:82' x = zeros(0,1); */
  /* 'mptSolveCRS:82' flag=int32(-1); */
  *flag = -1;

  /* 'mptSolveCRS:82' relres=realmax; */
  *relres = 1.7976931348623157E+308;

  /* 'mptSolveCRS:82' iter=int32(0); */
  *iter = 0;

  /* 'mptSolveCRS:82' times=[0;0]; */
  for (i = 0; i < 2; i++) {
    times[i] = 0.0;
  }
}

/*
 * function [x,flag,relres,iter,times] = mptSolveCRS_10args(Arows, Acols, Avals, b, solver, rtol, maxiter, pctype, solpack, x0)
 */
void mptSolveCRS_10args(const emxArray_int32_T *Arows, const emxArray_int32_T
  *Acols, const emxArray_real_T *Avals, const emxArray_real_T *b, const
  emxArray_char_T *solver, double rtol, int maxiter, const emxArray_char_T
  *pctype, const emxArray_char_T *solpack, const emxArray_real_T *x0,
  emxArray_real_T *x, int *flag, double *relres, int *iter, double times[2])
{
  Mat AMat;
  Vec bVec;
  Vec x0Vec;
  Vec xVec;
  Vec t_vec_out;
  int errCode;
  KSP ksp;
  double time_setup;
  int b_flag;
  double b_relres;
  int b_iter;
  double time_solve;
  KSP t_ksp;
  int c_flag;
  Mat t_mat;
  Vec t_vec;

  /* 'mptSolveCRS_10args:2' [x,flag,relres,iter,times] = mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxiter, pctype, solpack, x0); */
  /*  Solves a linear system using any PETSc solver for matrix in CRS format. */
  /*  */
  /*  Syntax: */
  /*     mptSolveCRS(Arows, Acols, Avals, b) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, solpack) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, solpack, x0) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, solpack, x0, opts) */
  /*  */
  /*     [x, flag, reslres, iter, times] = mptSolveCRS(Arows, Acols, Avals, b, ...) */
  /*  */
  /*     A is a sparse matrix in CRS format. b, x and resvec are all regular */
  /*     vectors. Solver is a value of PETSC_KSP*. pctype is a value of */
  /*     PETSC_PC*, and solpack is a value of PETSC_MATSOLVER*. */
  /*  */
  /*     For rtol, maxit, use 0 to use default values. */
  /*     For solver, pctype, solpack and opts, use empty string ('') to use default. */
  /*     For x0, use zeros(0, 1) to disable initial guess. */
  /*  */
  /*     When times is given, it returns a 2-vector contaning the times spent */
  /*     in setup and in solve separately. */
  /*  */
  /*  Description: */
  /*     mptSolveCRS(Arows, Acols, Avals, b) solves the linear system without */
  /*     preconditioners, using the default tolerances or those that have been */
  /*     set previously in the option databases. */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver) specifies to use a */
  /*     specific solver, such as PETSC_KSPGMRES, PETSC_KSPBCGS, etc. */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol) uses the given number */
  /*         of solvers and the relative tolerarance. */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit) solves with */
  /*         the given relative tolerances and maximum iteration count. */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype) */
  /*     uses the specified preconditioner (those give by PETSC_PC*). */
  /*     The preconditioner can be controlled by the PETSc option database. */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, */
  /*     solpack) specifies the solver packages for factorization (those give */
  /*     by PETSC_MATSOLVER*). */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, */
  /*     solpack, x0) usee x0 for the initial guess. x0 can be the same as x. */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, */
  /*     solpack, x0, opts) can pass additional command-line options in a */
  /*     string to PETSc. */
  /*  */
  /*  SEE ALSO: mptSolve, mptMatCreateAIJFromCRS, mptVecCreateFromArray, */
  /*            mptVecToArray, mptKSPSetup, mptKSPSolve, mptKSPCleanup */
  /* 'mptSolveCRS:81' if nargin==0 */
  /* 'mptSolveCRS:86' if isempty(coder.target) && ~exist(['petscVecDuplicate.' mexext], 'file') && ... */
  /* 'mptSolveCRS:87'         exist('run_mptSolveCRS_exe', 'file') */
  /* 'mptSolveCRS:96' Arows = varargin{1}; */
  /* 'mptSolveCRS:97' Acols = varargin{2}; */
  /* 'mptSolveCRS:98' Avals = varargin{3}; */
  /* 'mptSolveCRS:99' b = varargin{4}; */
  /*  Setup KSP */
  /* 'mptSolveCRS:102' if nargin<5 */
  /* 'mptSolveCRS:102' else */
  /* 'mptSolveCRS:102' solver = varargin{5}; */
  /*  Use default */
  /* 'mptSolveCRS:103' if nargin<6 */
  /* 'mptSolveCRS:103' else */
  /* 'mptSolveCRS:103' rtol = varargin{6}; */
  /* 'mptSolveCRS:104' if nargin<7 */
  /* 'mptSolveCRS:104' else */
  /* 'mptSolveCRS:104' maxit = varargin{7}; */
  /* 'mptSolveCRS:105' if nargin<8 */
  /* 'mptSolveCRS:105' else */
  /* 'mptSolveCRS:105' pctype = varargin{8}; */
  /* 'mptSolveCRS:106' if nargin<9 */
  /* 'mptSolveCRS:106' else */
  /* 'mptSolveCRS:106' solpack = varargin{9}; */
  /* 'mptSolveCRS:108' AMat = mptMatCreateAIJFromCRS(Arows, Acols, Avals); */
  AMat = mptMatCreateAIJFromCRS(Arows, Acols, Avals);

  /* 'mptSolveCRS:109' bVec = mptVecCreateFromArray(b); */
  bVec = mptVecCreateFromArray(b);

  /* 'mptSolveCRS:111' if nargin<10 || isempty(varargin{10}) */
  if (x0->size[0] == 0) {
    /* 'mptSolveCRS:112' x0Vec = PETSC_NULL_VEC; */
    /*  Obtain PETSC constant NULL of type Vec */
    /* 'PETSC_NULL_VEC:4' coder.inline('always'); */
    /* 'PETSC_NULL_VEC:6' obj = petscGetObject('PETSC_NULL_VEC'); */
    /* petscGetObject Obtain an opaque object in PETSC */
    /*  */
    /*     obj = petscGetObject(name) */
    /*  */
    /* The supported names include: */
    /*  */
    /*  MPI_Comm: PETSC_COMM_SELF, PETSC_COMM_WORLD, MPI_COMM_SELF, MPI_COMM_WORLD */
    /*  */
    /*  Other: */
    /*      PETSC_IGNORE, PETSC_NULL_OPTION, PETSC_NULL_MAT, PETSC_NULL_VEC, */
    /*      PETSC_NULL_INT, PETSC_NULL_REAL */
    /* 'petscGetObject:16' if isempty(coder.target) */
    /* 'petscGetObject:20' switch name */
    /* 'petscGetObject:35' case 'PETSC_NULL_VEC' */
    /* 'petscGetObject:36' [obj, toplevel] = get_obj('Vec', 'NULL', nargout>1); */
    x0Vec = NULL;

    /* 'mptSolveCRS:113' xVec = petscVecDuplicate(bVec); */
    /* Creates a new vector of the same type as an existing vector. */
    /*  */
    /*   [vec_out, errCode] = petscVecDuplicate(vec_in) creates a new vector, but */
    /*      it does not copy the entries of the input vector. The user is */
    /*      responsible freeing the memory by calling petscVecDestroy. */
    /*  */
    /*   SEE ALSO: petscVecCopy, petscVecDestroy, petscVecCreate */
    /*  */
    /*  PETSc C interface: */
    /*    PetscErrorCode  VecDuplicate(Vec vec_in, Vec *vec_out) */
    /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecDuplicate.html */
    /* 'petscVecDuplicate:16' errCode = int32(-1); */
    /* 'petscVecDuplicate:18' if ~isempty(coder.target) */
    /* 'petscVecDuplicate:19' t_vec_out = coder.opaque('Vec'); */
    /* 'petscVecDuplicate:21' errCode = coder.ceval('VecDuplicate', PetscVec(vec_in), coder.wref(t_vec_out)); */
    /* Map an opaque object into a PETSc Vec object */
    /*  */
    /*   vec = PetscVec() simply returns a definition of the */
    /*   m2c_opaque_type definition, suitable in the argument */
    /*   specification for codegen. */
    /*  */
    /*   vec = PetscVec(arg) or vec = PetscVec(arg, false) converts arg */
    /*   into a PETSc Vec object. */
    /*  */
    /*   vec = PetscVec(arg, true) wraps the arg into an opaque object.  */
    /*   This should be used if the object needs to be returned to */
    /*   MATLAB. Note that the value of opaque must be determined at */
    /*   compile time. */
    /*  */
    /*  See also PetscMat */
    /* 'PetscVec:18' coder.inline('always'); */
    /* 'PetscVec:20' if nargin==0 && isempty(coder.target) */
    /* 'PetscVec:25' if isstruct(arg) && ~isequal(arg.type, 'Vec') */
    /* 'PetscVec:30' if ~isstruct(arg) || isempty(coder.target) */
    /* 'PetscVec:31' if nargin==1 || ~opaque */
    /* 'PetscVec:32' vec = arg; */
    errCode = VecDuplicate(bVec, &t_vec_out);

    /* 'petscVecDuplicate:23' toplevel = nargout>2; */
    /* 'petscVecDuplicate:24' vec_out = PetscVec(t_vec_out, toplevel); */
    /* Map an opaque object into a PETSc Vec object */
    /*  */
    /*   vec = PetscVec() simply returns a definition of the */
    /*   m2c_opaque_type definition, suitable in the argument */
    /*   specification for codegen. */
    /*  */
    /*   vec = PetscVec(arg) or vec = PetscVec(arg, false) converts arg */
    /*   into a PETSc Vec object. */
    /*  */
    /*   vec = PetscVec(arg, true) wraps the arg into an opaque object.  */
    /*   This should be used if the object needs to be returned to */
    /*   MATLAB. Note that the value of opaque must be determined at */
    /*   compile time. */
    /*  */
    /*  See also PetscMat */
    /* 'PetscVec:18' coder.inline('always'); */
    /* 'PetscVec:20' if nargin==0 && isempty(coder.target) */
    /* 'PetscVec:25' if isstruct(arg) && ~isequal(arg.type, 'Vec') */
    /* 'PetscVec:30' if ~isstruct(arg) || isempty(coder.target) */
    /* 'PetscVec:31' if nargin==1 || ~opaque */
    /* 'PetscVec:32' vec = arg; */
    xVec = t_vec_out;

    /* 'petscVecDuplicate:26' if errCode && (toplevel || m2c_debug) */
    if (errCode != 0) {
      /* Flag indicating whether m2c_debug is on. */
      /* It is always true within MATLAB. In the generated C code, it is */
      /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
      /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
      /* 'm2c_debug:7' coder.inline('always'); */
      /* 'm2c_debug:9' if isempty(coder.target) */
      /* 'm2c_debug:11' else */
      /* 'm2c_debug:12' flag = int32(1); */
      /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
      b_flag = (M2C_DEBUG);
      if (b_flag != 0) {
        /* 'petscVecDuplicate:27' m2c_error('petsc:RuntimeError', 'VecDuplicate returned error code %d\n', errCode) */
        i_m2c_error(errCode);
      }
    }
  } else {
    /* 'mptSolveCRS:114' else */
    /* 'mptSolveCRS:115' x0 = varargin{10}; */
    /* 'mptSolveCRS:116' x0Vec = mptVecCreateFromArray(x0); */
    x0Vec = mptVecCreateFromArray(x0);

    /* 'mptSolveCRS:117' xVec = x0Vec; */
    xVec = x0Vec;
  }

  /* 'mptSolveCRS:120' if nargin<11 */
  /* 'mptSolveCRS:120' opts = ''; */
  /* 'mptSolveCRS:122' [flag,relres,iter, times] = mptSolve(AMat, bVec, xVec, solver, ... */
  /* 'mptSolveCRS:123'     double(rtol), int32(maxit), pctype, solpack, x0Vec, opts); */
  /*  Solves a linear system using a given solver in PETSc. */
  /*  */
  /*  Syntax: */
  /*     mptSolve(A_hdl, b_hdl) */
  /*     mptSolve(A_hdl, b_hdl, x_hdl) */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver) */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol) */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit) */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype) */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype, solpack) */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype, solpack, x0_hdl) */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype, solpack, x0_hdl, opts) */
  /*  */
  /*     [flag, reslres, iter] = mptSolve(A_hdl, b_hdl, x_hdl, ...) */
  /*  */
  /*     The handles are PetscMat or PetscVec objects. */
  /*  */
  /*  Description: */
  /*     mptSolve(A_hdl, b_hdl) solves the linear system without preconditioners, */
  /*     using the default tolerances or those that have been set previously in */
  /*     the option databases. A_hdl is a PetscMat object, and b_hdl is a */
  /*     PetscVec object. The solution is stored into b. The QMRCGS can be */
  /*     controlled using the options database for KSPQMRCGS. */
  /*  */
  /*     mptSolve(A_hdl, b_hdl, x_hdl) solves the linear system and saves the */
  /*     result into x. */
  /*  */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver) uses the specified solver, where */
  /*     solver is one of PETSC_KSP*. */
  /*  */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol) uses the given relative tolerarance. */
  /*  */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit) solves with the given */
  /*      relative tolerances and maximum iteration count. */
  /*  */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype) uses the */
  /*     specified preconditioner (PETSC_PC*). The preconditioner can be */
  /*     controlled by the PETSc option database. */
  /*  */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype, solpack) */
  /*     specifies the solver packages for factorization (PETSC_MATSOLVER*). */
  /*  */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype, solpack, */
  /*     x0_handle) usee x0 for the initial guess. x0 can be the same as x or */
  /*     be PETSC_NULL_VEC. */
  /*  */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype, solpack, */
  /*     x0_handle, opts) can pass command-line options in a string to PETSc. */
  /*  */
  /*  SEE ALSO: mptSolveCRS, mptMatCreateAIJFromCRS, mptVecCreateFromArray, */
  /*            mptOptionsInsert, mptKSPSetup, mptKSPSolve, mptKSPCleanup */
  /* This function is codegen compatbile, but no need to a top-level function */
  /*  Setup KSP */
  /* 'mptSolve:59' if nargin<3 */
  /* 'mptSolve:60' if nargin<4 */
  /* 'mptSolve:61' if nargin<5 */
  /* 'mptSolve:62' if nargin<6 */
  /* 'mptSolve:63' if nargin<7 */
  /* 'mptSolve:64' if nargin<8 */
  /* 'mptSolve:65' if nargin<9 */
  /* 'mptSolve:67' if nargin==10 && ~isempty(opts) */
  /* 'mptSolve:71' [ksp, time_setup] = mptKSPSetup(A, solver, pctype, solpack); */
  mptKSPSetup(AMat, solver, pctype, solpack, &ksp, &time_setup);

  /* 'mptSolve:73' [flag,relres,iter, time_solve] = mptKSPSolve(ksp, b, x, double(rtol), int32(maxit), x0); */
  mptKSPSolve(ksp, bVec, xVec, rtol, maxiter, x0Vec, &b_flag, &b_relres, &b_iter,
              &time_solve);

  /* 'mptSolve:75' if nargout>3 */
  /* 'mptSolve:76' times = [time_setup; time_solve]; */
  /* 'mptSolve:79' mptKSPCleanup(ksp); */
  /*  Cleans up the KSP. */
  /*  */
  /*    ksp = mptKSPCleanup(ksp) destropys the given KSP object. */
  /*    It should be called whtn the KSP object is no longer needed, and  */
  /*    no calls should be made to this KSP after this. */
  /*  */
  /*  See Also: mptKSPSetup, mptKSPSolve */
  /*  Destroy the KSP and solution vector */
  /* 'mptKSPCleanup:13' t_ksp = petscKSPDestroy(ksp); */
  /* Destroys KSP context. */
  /*  */
  /*   [ksp, errCode] = petscKSPDestroy(ksp) */
  /*  */
  /*   SEE ALSO: petscKSPCreate, petscKSPSetUp, petscKSPSolve */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode KSPDestroy(KSP *A) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPDestroy.html */
  /* 'petscKSPDestroy:14' errCode = int32(-1); */
  /* 'petscKSPDestroy:16' if ~isempty(coder.target) */
  /* 'petscKSPDestroy:17' t_ksp = PetscKSP(ksp); */
  /* Map an opaque object into a PETSc KSP object */
  /*  */
  /*   ksp = PetscKSP() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   ksp = PetscKSP(arg) or ksp = PetscKSP(arg, false) converts arg */
  /*   into a PETSc KSP object. */
  /*  */
  /*   ksp = PetscKSP(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscPC */
  /* 'PetscKSP:18' coder.inline('always'); */
  /* 'PetscKSP:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscKSP:25' if isstruct(arg) && ~isequal(arg.type, 'KSP') */
  /* 'PetscKSP:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscKSP:31' if nargin==1 || ~opaque */
  /* 'PetscKSP:32' ksp = arg; */
  t_ksp = ksp;

  /* 'petscKSPDestroy:19' errCode = coder.ceval('KSPDestroy', coder.ref(t_ksp)); */
  errCode = KSPDestroy(&t_ksp);

  /* 'petscKSPDestroy:21' toplevel = nargout>2; */
  /* 'petscKSPDestroy:22' ksp_out = PetscKSP(t_ksp, toplevel); */
  /* Map an opaque object into a PETSc KSP object */
  /*  */
  /*   ksp = PetscKSP() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   ksp = PetscKSP(arg) or ksp = PetscKSP(arg, false) converts arg */
  /*   into a PETSc KSP object. */
  /*  */
  /*   ksp = PetscKSP(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscPC */
  /* 'PetscKSP:18' coder.inline('always'); */
  /* 'PetscKSP:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscKSP:25' if isstruct(arg) && ~isequal(arg.type, 'KSP') */
  /* 'PetscKSP:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscKSP:31' if nargin==1 || ~opaque */
  /* 'PetscKSP:32' ksp = arg; */
  /* 'petscKSPDestroy:24' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      /* 'petscKSPDestroy:25' m2c_error('petsc:RuntimeError', 'KSPDestroy returned error code %d\n', errCode) */
      ab_m2c_error(errCode);
    }
  }

  /* 'mptKSPCleanup:15' toplevel = nargout>1; */
  /* 'mptKSPCleanup:16' ksp = PetscKSP(t_ksp, toplevel); */
  /* 'mptSolveCRS:125' petscMatDestroy(AMat); */
  /* Frees space taken by a matrix. */
  /*  */
  /*   [mat, errCode] = petscMatDestroy(mat) */
  /*  */
  /*   SEE ALSO: petscVecCreateSeq, petscVecCreateMPI, petscAssembleMat, petscVecDestroy */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode MatDestroy(Mat *A) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatDestroy.html */
  /* 'petscMatDestroy:14' errCode = int32(-1); */
  /* 'petscMatDestroy:16' if ~isempty(coder.target) */
  /* 'petscMatDestroy:17' t_mat = PetscMat(mat); */
  /* Map an opaque object into a PETSc Mat object */
  /*  */
  /*   mat = PetscMat() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   mat = PetscMat(arg) or mat = PetscMat(arg, false) converts arg */
  /*   into a PETSc Mat object. */
  /*  */
  /*   mat = PetscMat(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscMat:18' coder.inline('always'); */
  /* 'PetscMat:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscMat:25' if isstruct(arg) && ~isequal(arg.type, 'Mat') */
  /* 'PetscMat:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscMat:31' if nargin==1 || ~opaque */
  /* 'PetscMat:32' mat = arg; */
  t_mat = AMat;

  /* 'petscMatDestroy:19' errCode = coder.ceval('MatDestroy', coder.ref(t_mat)); */
  errCode = MatDestroy(&t_mat);

  /* 'petscMatDestroy:21' toplevel = nargout>2; */
  /* 'petscMatDestroy:22' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      /* 'petscMatDestroy:23' m2c_error('petsc:RuntimeError', 'MatDestroy returned error code %d\n', errCode) */
      bb_m2c_error(errCode);
    }
  }

  /* 'petscMatDestroy:26' mat = PetscMat(t_mat, toplevel); */
  /* 'mptSolveCRS:126' petscVecDestroy(bVec); */
  /* Frees space taken by a vector. */
  /*  */
  /*   [vec, errCode] = petscVecDestroy(vec) */
  /*  */
  /*   SEE ALSO: petscVecCreateSeq, petscVecCreateMPI, petscAssembleVec, */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode VecDestroy(Vec *A) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecDestroy.html */
  /* 'petscVecDestroy:14' errCode = int32(-1); */
  /* 'petscVecDestroy:16' if ~isempty(coder.target) */
  /* 'petscVecDestroy:17' t_vec = PetscVec(vec); */
  /* Map an opaque object into a PETSc Vec object */
  /*  */
  /*   vec = PetscVec() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   vec = PetscVec(arg) or vec = PetscVec(arg, false) converts arg */
  /*   into a PETSc Vec object. */
  /*  */
  /*   vec = PetscVec(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscVec:18' coder.inline('always'); */
  /* 'PetscVec:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscVec:25' if isstruct(arg) && ~isequal(arg.type, 'Vec') */
  /* 'PetscVec:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscVec:31' if nargin==1 || ~opaque */
  /* 'PetscVec:32' vec = arg; */
  t_vec = bVec;

  /* 'petscVecDestroy:19' errCode = coder.ceval('VecDestroy', coder.ref(t_vec)); */
  errCode = VecDestroy(&t_vec);

  /* 'petscVecDestroy:21' toplevel = nargout>2; */
  /* 'petscVecDestroy:22' vec = PetscVec(t_vec, toplevel); */
  /* 'petscVecDestroy:24' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      /* 'petscVecDestroy:25' m2c_error('petsc:RuntimeError', 'VecDestroy returned error code %d\n', errCode) */
      cb_m2c_error(errCode);
    }
  }

  /* 'mptSolveCRS:128' x = mptVecToArray(xVec); */
  mptVecToArray(xVec, x);

  /* 'mptSolveCRS:129' petscVecDestroy(xVec); */
  /* Frees space taken by a vector. */
  /*  */
  /*   [vec, errCode] = petscVecDestroy(vec) */
  /*  */
  /*   SEE ALSO: petscVecCreateSeq, petscVecCreateMPI, petscAssembleVec, */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode VecDestroy(Vec *A) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecDestroy.html */
  /* 'petscVecDestroy:14' errCode = int32(-1); */
  /* 'petscVecDestroy:16' if ~isempty(coder.target) */
  /* 'petscVecDestroy:17' t_vec = PetscVec(vec); */
  /* Map an opaque object into a PETSc Vec object */
  /*  */
  /*   vec = PetscVec() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   vec = PetscVec(arg) or vec = PetscVec(arg, false) converts arg */
  /*   into a PETSc Vec object. */
  /*  */
  /*   vec = PetscVec(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscVec:18' coder.inline('always'); */
  /* 'PetscVec:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscVec:25' if isstruct(arg) && ~isequal(arg.type, 'Vec') */
  /* 'PetscVec:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscVec:31' if nargin==1 || ~opaque */
  /* 'PetscVec:32' vec = arg; */
  t_vec = xVec;

  /* 'petscVecDestroy:19' errCode = coder.ceval('VecDestroy', coder.ref(t_vec)); */
  errCode = VecDestroy(&t_vec);

  /* 'petscVecDestroy:21' toplevel = nargout>2; */
  /* 'petscVecDestroy:22' vec = PetscVec(t_vec, toplevel); */
  /* 'petscVecDestroy:24' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      /* 'petscVecDestroy:25' m2c_error('petsc:RuntimeError', 'VecDestroy returned error code %d\n', errCode) */
      cb_m2c_error(errCode);
    }
  }

  *flag = b_flag;
  *relres = b_relres;
  *iter = b_iter;
  times[0] = time_setup;
  times[1] = time_solve;
}

/*
 * function [x,flag,relres,iter,times] = mptSolveCRS_11args(Arows, Acols, Avals, b, solver, rtol, maxiter, pctype, solpack, x0, opts)
 */
void mptSolveCRS_11args(const emxArray_int32_T *Arows, const emxArray_int32_T
  *Acols, const emxArray_real_T *Avals, const emxArray_real_T *b, const
  emxArray_char_T *solver, double rtol, int maxiter, const emxArray_char_T
  *pctype, const emxArray_char_T *solpack, const emxArray_real_T *x0, const
  emxArray_char_T *opts, emxArray_real_T *x, int *flag, double *relres, int
  *iter, double times[2])
{
  Mat AMat;
  Vec bVec;
  Vec x0Vec;
  Vec xVec;
  Vec t_vec_out;
  int errCode;
  emxArray_char_T *b_opts;
  KSP ksp;
  double time_setup;
  int b_flag;
  double b_relres;
  int loop_ub;
  double time_solve;
  KSP t_ksp;
  int c_flag;
  Mat t_mat;
  Vec t_vec;

  /* 'mptSolveCRS_11args:2' [x,flag,relres,iter,times] = mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxiter, pctype, solpack, x0, opts); */
  /*  Solves a linear system using any PETSc solver for matrix in CRS format. */
  /*  */
  /*  Syntax: */
  /*     mptSolveCRS(Arows, Acols, Avals, b) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, solpack) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, solpack, x0) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, solpack, x0, opts) */
  /*  */
  /*     [x, flag, reslres, iter, times] = mptSolveCRS(Arows, Acols, Avals, b, ...) */
  /*  */
  /*     A is a sparse matrix in CRS format. b, x and resvec are all regular */
  /*     vectors. Solver is a value of PETSC_KSP*. pctype is a value of */
  /*     PETSC_PC*, and solpack is a value of PETSC_MATSOLVER*. */
  /*  */
  /*     For rtol, maxit, use 0 to use default values. */
  /*     For solver, pctype, solpack and opts, use empty string ('') to use default. */
  /*     For x0, use zeros(0, 1) to disable initial guess. */
  /*  */
  /*     When times is given, it returns a 2-vector contaning the times spent */
  /*     in setup and in solve separately. */
  /*  */
  /*  Description: */
  /*     mptSolveCRS(Arows, Acols, Avals, b) solves the linear system without */
  /*     preconditioners, using the default tolerances or those that have been */
  /*     set previously in the option databases. */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver) specifies to use a */
  /*     specific solver, such as PETSC_KSPGMRES, PETSC_KSPBCGS, etc. */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol) uses the given number */
  /*         of solvers and the relative tolerarance. */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit) solves with */
  /*         the given relative tolerances and maximum iteration count. */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype) */
  /*     uses the specified preconditioner (those give by PETSC_PC*). */
  /*     The preconditioner can be controlled by the PETSc option database. */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, */
  /*     solpack) specifies the solver packages for factorization (those give */
  /*     by PETSC_MATSOLVER*). */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, */
  /*     solpack, x0) usee x0 for the initial guess. x0 can be the same as x. */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, */
  /*     solpack, x0, opts) can pass additional command-line options in a */
  /*     string to PETSc. */
  /*  */
  /*  SEE ALSO: mptSolve, mptMatCreateAIJFromCRS, mptVecCreateFromArray, */
  /*            mptVecToArray, mptKSPSetup, mptKSPSolve, mptKSPCleanup */
  /* 'mptSolveCRS:81' if nargin==0 */
  /* 'mptSolveCRS:86' if isempty(coder.target) && ~exist(['petscVecDuplicate.' mexext], 'file') && ... */
  /* 'mptSolveCRS:87'         exist('run_mptSolveCRS_exe', 'file') */
  /* 'mptSolveCRS:96' Arows = varargin{1}; */
  /* 'mptSolveCRS:97' Acols = varargin{2}; */
  /* 'mptSolveCRS:98' Avals = varargin{3}; */
  /* 'mptSolveCRS:99' b = varargin{4}; */
  /*  Setup KSP */
  /* 'mptSolveCRS:102' if nargin<5 */
  /* 'mptSolveCRS:102' else */
  /* 'mptSolveCRS:102' solver = varargin{5}; */
  /*  Use default */
  /* 'mptSolveCRS:103' if nargin<6 */
  /* 'mptSolveCRS:103' else */
  /* 'mptSolveCRS:103' rtol = varargin{6}; */
  /* 'mptSolveCRS:104' if nargin<7 */
  /* 'mptSolveCRS:104' else */
  /* 'mptSolveCRS:104' maxit = varargin{7}; */
  /* 'mptSolveCRS:105' if nargin<8 */
  /* 'mptSolveCRS:105' else */
  /* 'mptSolveCRS:105' pctype = varargin{8}; */
  /* 'mptSolveCRS:106' if nargin<9 */
  /* 'mptSolveCRS:106' else */
  /* 'mptSolveCRS:106' solpack = varargin{9}; */
  /* 'mptSolveCRS:108' AMat = mptMatCreateAIJFromCRS(Arows, Acols, Avals); */
  AMat = mptMatCreateAIJFromCRS(Arows, Acols, Avals);

  /* 'mptSolveCRS:109' bVec = mptVecCreateFromArray(b); */
  bVec = mptVecCreateFromArray(b);

  /* 'mptSolveCRS:111' if nargin<10 || isempty(varargin{10}) */
  if (x0->size[0] == 0) {
    /* 'mptSolveCRS:112' x0Vec = PETSC_NULL_VEC; */
    /*  Obtain PETSC constant NULL of type Vec */
    /* 'PETSC_NULL_VEC:4' coder.inline('always'); */
    /* 'PETSC_NULL_VEC:6' obj = petscGetObject('PETSC_NULL_VEC'); */
    /* petscGetObject Obtain an opaque object in PETSC */
    /*  */
    /*     obj = petscGetObject(name) */
    /*  */
    /* The supported names include: */
    /*  */
    /*  MPI_Comm: PETSC_COMM_SELF, PETSC_COMM_WORLD, MPI_COMM_SELF, MPI_COMM_WORLD */
    /*  */
    /*  Other: */
    /*      PETSC_IGNORE, PETSC_NULL_OPTION, PETSC_NULL_MAT, PETSC_NULL_VEC, */
    /*      PETSC_NULL_INT, PETSC_NULL_REAL */
    /* 'petscGetObject:16' if isempty(coder.target) */
    /* 'petscGetObject:20' switch name */
    /* 'petscGetObject:35' case 'PETSC_NULL_VEC' */
    /* 'petscGetObject:36' [obj, toplevel] = get_obj('Vec', 'NULL', nargout>1); */
    x0Vec = NULL;

    /* 'mptSolveCRS:113' xVec = petscVecDuplicate(bVec); */
    /* Creates a new vector of the same type as an existing vector. */
    /*  */
    /*   [vec_out, errCode] = petscVecDuplicate(vec_in) creates a new vector, but */
    /*      it does not copy the entries of the input vector. The user is */
    /*      responsible freeing the memory by calling petscVecDestroy. */
    /*  */
    /*   SEE ALSO: petscVecCopy, petscVecDestroy, petscVecCreate */
    /*  */
    /*  PETSc C interface: */
    /*    PetscErrorCode  VecDuplicate(Vec vec_in, Vec *vec_out) */
    /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecDuplicate.html */
    /* 'petscVecDuplicate:16' errCode = int32(-1); */
    /* 'petscVecDuplicate:18' if ~isempty(coder.target) */
    /* 'petscVecDuplicate:19' t_vec_out = coder.opaque('Vec'); */
    /* 'petscVecDuplicate:21' errCode = coder.ceval('VecDuplicate', PetscVec(vec_in), coder.wref(t_vec_out)); */
    /* Map an opaque object into a PETSc Vec object */
    /*  */
    /*   vec = PetscVec() simply returns a definition of the */
    /*   m2c_opaque_type definition, suitable in the argument */
    /*   specification for codegen. */
    /*  */
    /*   vec = PetscVec(arg) or vec = PetscVec(arg, false) converts arg */
    /*   into a PETSc Vec object. */
    /*  */
    /*   vec = PetscVec(arg, true) wraps the arg into an opaque object.  */
    /*   This should be used if the object needs to be returned to */
    /*   MATLAB. Note that the value of opaque must be determined at */
    /*   compile time. */
    /*  */
    /*  See also PetscMat */
    /* 'PetscVec:18' coder.inline('always'); */
    /* 'PetscVec:20' if nargin==0 && isempty(coder.target) */
    /* 'PetscVec:25' if isstruct(arg) && ~isequal(arg.type, 'Vec') */
    /* 'PetscVec:30' if ~isstruct(arg) || isempty(coder.target) */
    /* 'PetscVec:31' if nargin==1 || ~opaque */
    /* 'PetscVec:32' vec = arg; */
    errCode = VecDuplicate(bVec, &t_vec_out);

    /* 'petscVecDuplicate:23' toplevel = nargout>2; */
    /* 'petscVecDuplicate:24' vec_out = PetscVec(t_vec_out, toplevel); */
    /* Map an opaque object into a PETSc Vec object */
    /*  */
    /*   vec = PetscVec() simply returns a definition of the */
    /*   m2c_opaque_type definition, suitable in the argument */
    /*   specification for codegen. */
    /*  */
    /*   vec = PetscVec(arg) or vec = PetscVec(arg, false) converts arg */
    /*   into a PETSc Vec object. */
    /*  */
    /*   vec = PetscVec(arg, true) wraps the arg into an opaque object.  */
    /*   This should be used if the object needs to be returned to */
    /*   MATLAB. Note that the value of opaque must be determined at */
    /*   compile time. */
    /*  */
    /*  See also PetscMat */
    /* 'PetscVec:18' coder.inline('always'); */
    /* 'PetscVec:20' if nargin==0 && isempty(coder.target) */
    /* 'PetscVec:25' if isstruct(arg) && ~isequal(arg.type, 'Vec') */
    /* 'PetscVec:30' if ~isstruct(arg) || isempty(coder.target) */
    /* 'PetscVec:31' if nargin==1 || ~opaque */
    /* 'PetscVec:32' vec = arg; */
    xVec = t_vec_out;

    /* 'petscVecDuplicate:26' if errCode && (toplevel || m2c_debug) */
    if (errCode != 0) {
      /* Flag indicating whether m2c_debug is on. */
      /* It is always true within MATLAB. In the generated C code, it is */
      /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
      /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
      /* 'm2c_debug:7' coder.inline('always'); */
      /* 'm2c_debug:9' if isempty(coder.target) */
      /* 'm2c_debug:11' else */
      /* 'm2c_debug:12' flag = int32(1); */
      /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
      b_flag = (M2C_DEBUG);
      if (b_flag != 0) {
        /* 'petscVecDuplicate:27' m2c_error('petsc:RuntimeError', 'VecDuplicate returned error code %d\n', errCode) */
        i_m2c_error(errCode);
      }
    }
  } else {
    /* 'mptSolveCRS:114' else */
    /* 'mptSolveCRS:115' x0 = varargin{10}; */
    /* 'mptSolveCRS:116' x0Vec = mptVecCreateFromArray(x0); */
    x0Vec = mptVecCreateFromArray(x0);

    /* 'mptSolveCRS:117' xVec = x0Vec; */
    xVec = x0Vec;
  }

  /* 'mptSolveCRS:120' if nargin<11 */
  /* 'mptSolveCRS:120' else */
  /* 'mptSolveCRS:120' opts = varargin{11}; */
  /* 'mptSolveCRS:122' [flag,relres,iter, times] = mptSolve(AMat, bVec, xVec, solver, ... */
  /* 'mptSolveCRS:123'     double(rtol), int32(maxit), pctype, solpack, x0Vec, opts); */
  /*  Solves a linear system using a given solver in PETSc. */
  /*  */
  /*  Syntax: */
  /*     mptSolve(A_hdl, b_hdl) */
  /*     mptSolve(A_hdl, b_hdl, x_hdl) */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver) */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol) */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit) */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype) */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype, solpack) */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype, solpack, x0_hdl) */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype, solpack, x0_hdl, opts) */
  /*  */
  /*     [flag, reslres, iter] = mptSolve(A_hdl, b_hdl, x_hdl, ...) */
  /*  */
  /*     The handles are PetscMat or PetscVec objects. */
  /*  */
  /*  Description: */
  /*     mptSolve(A_hdl, b_hdl) solves the linear system without preconditioners, */
  /*     using the default tolerances or those that have been set previously in */
  /*     the option databases. A_hdl is a PetscMat object, and b_hdl is a */
  /*     PetscVec object. The solution is stored into b. The QMRCGS can be */
  /*     controlled using the options database for KSPQMRCGS. */
  /*  */
  /*     mptSolve(A_hdl, b_hdl, x_hdl) solves the linear system and saves the */
  /*     result into x. */
  /*  */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver) uses the specified solver, where */
  /*     solver is one of PETSC_KSP*. */
  /*  */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol) uses the given relative tolerarance. */
  /*  */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit) solves with the given */
  /*      relative tolerances and maximum iteration count. */
  /*  */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype) uses the */
  /*     specified preconditioner (PETSC_PC*). The preconditioner can be */
  /*     controlled by the PETSc option database. */
  /*  */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype, solpack) */
  /*     specifies the solver packages for factorization (PETSC_MATSOLVER*). */
  /*  */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype, solpack, */
  /*     x0_handle) usee x0 for the initial guess. x0 can be the same as x or */
  /*     be PETSC_NULL_VEC. */
  /*  */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype, solpack, */
  /*     x0_handle, opts) can pass command-line options in a string to PETSc. */
  /*  */
  /*  SEE ALSO: mptSolveCRS, mptMatCreateAIJFromCRS, mptVecCreateFromArray, */
  /*            mptOptionsInsert, mptKSPSetup, mptKSPSolve, mptKSPCleanup */
  /* This function is codegen compatbile, but no need to a top-level function */
  /*  Setup KSP */
  /* 'mptSolve:59' if nargin<3 */
  /* 'mptSolve:60' if nargin<4 */
  /* 'mptSolve:61' if nargin<5 */
  /* 'mptSolve:62' if nargin<6 */
  /* 'mptSolve:63' if nargin<7 */
  /* 'mptSolve:64' if nargin<8 */
  /* 'mptSolve:65' if nargin<9 */
  /* 'mptSolve:67' if nargin==10 && ~isempty(opts) */
  if (!(opts->size[1] == 0)) {
    emxInit_char_T(&b_opts, 2);

    /* 'mptSolve:68' mptOptionsInsert(opts); */
    b_flag = b_opts->size[0] * b_opts->size[1];
    b_opts->size[0] = 1;
    b_opts->size[1] = opts->size[1];
    emxEnsureCapacity((emxArray__common *)b_opts, b_flag, (int)sizeof(char));
    loop_ub = opts->size[0] * opts->size[1];
    for (b_flag = 0; b_flag < loop_ub; b_flag++) {
      b_opts->data[b_flag] = opts->data[b_flag];
    }

    /* Inserts options into the PETSc optoins database from a string */
    /*    errCode = mptOptionsInsert(opts) */
    /*  */
    /*    opts - string that contains options separated by blanks */
    /*    errCode(int) return code (0 indicates OK) */
    /*  */
    /*  SEE ALSO: sys/petscOptionsInsertFile, sys/petscOptionsSetValue, */
    /*    sys/petscOptionsSetInt, sys/petscOptionsGetReal, */
    /*    sys/petscOptionsHasName, sys/petscOptionsGetInt, */
    /*    sys/petscOptionsSetReal, sys/petscOptionsGetBool, */
    /*    sys/petscOptionsGetString */
    /* This function is codegen compatbile, but no need to a top-level function */
    /* 'mptOptionsInsert:17' if ~isempty(opts) && opts(end)~=char(0) */
    if (opts->data[opts->size[1] - 1] != '\x00') {
      /* 'mptOptionsInsert:18' opts = [opts char(0)]; */
      b_flag = b_opts->size[0] * b_opts->size[1];
      b_opts->size[0] = 1;
      b_opts->size[1] = opts->size[1] + 1;
      emxEnsureCapacity((emxArray__common *)b_opts, b_flag, (int)sizeof(char));
      loop_ub = opts->size[1];
      for (b_flag = 0; b_flag < loop_ub; b_flag++) {
        b_opts->data[b_opts->size[0] * b_flag] = opts->data[opts->size[0] *
          b_flag];
      }

      b_opts->data[b_opts->size[0] * opts->size[1]] = '\x00';
    }

    /*  Insert into options database and enforce error checking */
    /* 'mptOptionsInsert:22' [errCode,~] = petscOptionsInsertString(opts); */
    /* Inserts options into the database from a string */
    /*    errCode = petscOptionsInsertString(in_str) */
    /*  */
    /*    in_str -string that contains options separated by blanks and */
    /*            must be null-terminated */
    /*    errCode(int) return code (0 indicates OK) */
    /*  */
    /*  SEE ALSO: petscOptionsInsertFile */
    /*  */
    /*  PETSc C interface: */
    /*    PetscErrorCode  PetscOptionsInsertString(PetscOptions options,const char in_str[]) */
    /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Sys/PetscOptionsInsertString.html */
    /* 'petscOptionsInsertString:17' errCode = int32(-1); */
    /* 'petscOptionsInsertString:19' if ~isempty(coder.target) */
    /* 'petscOptionsInsertString:20' toplevel = nargout>1; */
    /* 'petscOptionsInsertString:21' if ~isempty(in_str) && in_str(end) && (toplevel || m2c_debug) */
    if (b_opts->data[b_opts->size[1] - 1] != '\x00') {
      /* 'petscOptionsInsertString:22' m2c_error('MPETSc:petscOptionsInsertString:InputError', ... */
      /* 'petscOptionsInsertString:23'             'The argument must be a null-terminated string.') */
      jb_m2c_error();
    }

    /* 'petscOptionsInsertString:26' errCode = coder.ceval('PetscOptionsInsertString', PETSC_NULL_OPTIONS, coder.rref(in_str)); */
    /*  Obtain PETSC constant NULL of type PetscOptions */
    /* 'PETSC_NULL_OPTIONS:4' coder.inline('always'); */
    /* 'PETSC_NULL_OPTIONS:6' obj = petscGetObject('PETSC_NULL_OPTIONS'); */
    /* petscGetObject Obtain an opaque object in PETSC */
    /*  */
    /*     obj = petscGetObject(name) */
    /*  */
    /* The supported names include: */
    /*  */
    /*  MPI_Comm: PETSC_COMM_SELF, PETSC_COMM_WORLD, MPI_COMM_SELF, MPI_COMM_WORLD */
    /*  */
    /*  Other: */
    /*      PETSC_IGNORE, PETSC_NULL_OPTION, PETSC_NULL_MAT, PETSC_NULL_VEC, */
    /*      PETSC_NULL_INT, PETSC_NULL_REAL */
    /* 'petscGetObject:16' if isempty(coder.target) */
    /* 'petscGetObject:20' switch name */
    /* 'petscGetObject:31' case 'PETSC_NULL_OPTIONS' */
    /* 'petscGetObject:32' [obj, toplevel] = get_obj('PetscOptions', 'NULL', nargout>1); */
    errCode = PetscOptionsInsertString(NULL, &b_opts->data[0]);

    /* 'petscOptionsInsertString:28' if errCode && (toplevel || m2c_debug) */
    emxFree_char_T(&b_opts);
    if (errCode != 0) {
      /* 'petscOptionsInsertString:29' m2c_error('petsc:RuntimeError', 'PetscOptionsInsertString returned error code %d\n', errCode) */
      kb_m2c_error(errCode);
    }

    /* 'mptOptionsInsert:22' ~ */
  }

  /* 'mptSolve:71' [ksp, time_setup] = mptKSPSetup(A, solver, pctype, solpack); */
  mptKSPSetup(AMat, solver, pctype, solpack, &ksp, &time_setup);

  /* 'mptSolve:73' [flag,relres,iter, time_solve] = mptKSPSolve(ksp, b, x, double(rtol), int32(maxit), x0); */
  mptKSPSolve(ksp, bVec, xVec, rtol, maxiter, x0Vec, &b_flag, &b_relres,
              &loop_ub, &time_solve);

  /* 'mptSolve:75' if nargout>3 */
  /* 'mptSolve:76' times = [time_setup; time_solve]; */
  /* 'mptSolve:79' mptKSPCleanup(ksp); */
  /*  Cleans up the KSP. */
  /*  */
  /*    ksp = mptKSPCleanup(ksp) destropys the given KSP object. */
  /*    It should be called whtn the KSP object is no longer needed, and  */
  /*    no calls should be made to this KSP after this. */
  /*  */
  /*  See Also: mptKSPSetup, mptKSPSolve */
  /*  Destroy the KSP and solution vector */
  /* 'mptKSPCleanup:13' t_ksp = petscKSPDestroy(ksp); */
  /* Destroys KSP context. */
  /*  */
  /*   [ksp, errCode] = petscKSPDestroy(ksp) */
  /*  */
  /*   SEE ALSO: petscKSPCreate, petscKSPSetUp, petscKSPSolve */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode KSPDestroy(KSP *A) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPDestroy.html */
  /* 'petscKSPDestroy:14' errCode = int32(-1); */
  /* 'petscKSPDestroy:16' if ~isempty(coder.target) */
  /* 'petscKSPDestroy:17' t_ksp = PetscKSP(ksp); */
  /* Map an opaque object into a PETSc KSP object */
  /*  */
  /*   ksp = PetscKSP() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   ksp = PetscKSP(arg) or ksp = PetscKSP(arg, false) converts arg */
  /*   into a PETSc KSP object. */
  /*  */
  /*   ksp = PetscKSP(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscPC */
  /* 'PetscKSP:18' coder.inline('always'); */
  /* 'PetscKSP:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscKSP:25' if isstruct(arg) && ~isequal(arg.type, 'KSP') */
  /* 'PetscKSP:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscKSP:31' if nargin==1 || ~opaque */
  /* 'PetscKSP:32' ksp = arg; */
  t_ksp = ksp;

  /* 'petscKSPDestroy:19' errCode = coder.ceval('KSPDestroy', coder.ref(t_ksp)); */
  errCode = KSPDestroy(&t_ksp);

  /* 'petscKSPDestroy:21' toplevel = nargout>2; */
  /* 'petscKSPDestroy:22' ksp_out = PetscKSP(t_ksp, toplevel); */
  /* Map an opaque object into a PETSc KSP object */
  /*  */
  /*   ksp = PetscKSP() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   ksp = PetscKSP(arg) or ksp = PetscKSP(arg, false) converts arg */
  /*   into a PETSc KSP object. */
  /*  */
  /*   ksp = PetscKSP(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscPC */
  /* 'PetscKSP:18' coder.inline('always'); */
  /* 'PetscKSP:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscKSP:25' if isstruct(arg) && ~isequal(arg.type, 'KSP') */
  /* 'PetscKSP:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscKSP:31' if nargin==1 || ~opaque */
  /* 'PetscKSP:32' ksp = arg; */
  /* 'petscKSPDestroy:24' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      /* 'petscKSPDestroy:25' m2c_error('petsc:RuntimeError', 'KSPDestroy returned error code %d\n', errCode) */
      ab_m2c_error(errCode);
    }
  }

  /* 'mptKSPCleanup:15' toplevel = nargout>1; */
  /* 'mptKSPCleanup:16' ksp = PetscKSP(t_ksp, toplevel); */
  /* 'mptSolveCRS:125' petscMatDestroy(AMat); */
  /* Frees space taken by a matrix. */
  /*  */
  /*   [mat, errCode] = petscMatDestroy(mat) */
  /*  */
  /*   SEE ALSO: petscVecCreateSeq, petscVecCreateMPI, petscAssembleMat, petscVecDestroy */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode MatDestroy(Mat *A) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatDestroy.html */
  /* 'petscMatDestroy:14' errCode = int32(-1); */
  /* 'petscMatDestroy:16' if ~isempty(coder.target) */
  /* 'petscMatDestroy:17' t_mat = PetscMat(mat); */
  /* Map an opaque object into a PETSc Mat object */
  /*  */
  /*   mat = PetscMat() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   mat = PetscMat(arg) or mat = PetscMat(arg, false) converts arg */
  /*   into a PETSc Mat object. */
  /*  */
  /*   mat = PetscMat(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscMat:18' coder.inline('always'); */
  /* 'PetscMat:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscMat:25' if isstruct(arg) && ~isequal(arg.type, 'Mat') */
  /* 'PetscMat:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscMat:31' if nargin==1 || ~opaque */
  /* 'PetscMat:32' mat = arg; */
  t_mat = AMat;

  /* 'petscMatDestroy:19' errCode = coder.ceval('MatDestroy', coder.ref(t_mat)); */
  errCode = MatDestroy(&t_mat);

  /* 'petscMatDestroy:21' toplevel = nargout>2; */
  /* 'petscMatDestroy:22' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      /* 'petscMatDestroy:23' m2c_error('petsc:RuntimeError', 'MatDestroy returned error code %d\n', errCode) */
      bb_m2c_error(errCode);
    }
  }

  /* 'petscMatDestroy:26' mat = PetscMat(t_mat, toplevel); */
  /* 'mptSolveCRS:126' petscVecDestroy(bVec); */
  /* Frees space taken by a vector. */
  /*  */
  /*   [vec, errCode] = petscVecDestroy(vec) */
  /*  */
  /*   SEE ALSO: petscVecCreateSeq, petscVecCreateMPI, petscAssembleVec, */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode VecDestroy(Vec *A) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecDestroy.html */
  /* 'petscVecDestroy:14' errCode = int32(-1); */
  /* 'petscVecDestroy:16' if ~isempty(coder.target) */
  /* 'petscVecDestroy:17' t_vec = PetscVec(vec); */
  /* Map an opaque object into a PETSc Vec object */
  /*  */
  /*   vec = PetscVec() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   vec = PetscVec(arg) or vec = PetscVec(arg, false) converts arg */
  /*   into a PETSc Vec object. */
  /*  */
  /*   vec = PetscVec(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscVec:18' coder.inline('always'); */
  /* 'PetscVec:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscVec:25' if isstruct(arg) && ~isequal(arg.type, 'Vec') */
  /* 'PetscVec:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscVec:31' if nargin==1 || ~opaque */
  /* 'PetscVec:32' vec = arg; */
  t_vec = bVec;

  /* 'petscVecDestroy:19' errCode = coder.ceval('VecDestroy', coder.ref(t_vec)); */
  errCode = VecDestroy(&t_vec);

  /* 'petscVecDestroy:21' toplevel = nargout>2; */
  /* 'petscVecDestroy:22' vec = PetscVec(t_vec, toplevel); */
  /* 'petscVecDestroy:24' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      /* 'petscVecDestroy:25' m2c_error('petsc:RuntimeError', 'VecDestroy returned error code %d\n', errCode) */
      cb_m2c_error(errCode);
    }
  }

  /* 'mptSolveCRS:128' x = mptVecToArray(xVec); */
  mptVecToArray(xVec, x);

  /* 'mptSolveCRS:129' petscVecDestroy(xVec); */
  /* Frees space taken by a vector. */
  /*  */
  /*   [vec, errCode] = petscVecDestroy(vec) */
  /*  */
  /*   SEE ALSO: petscVecCreateSeq, petscVecCreateMPI, petscAssembleVec, */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode VecDestroy(Vec *A) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecDestroy.html */
  /* 'petscVecDestroy:14' errCode = int32(-1); */
  /* 'petscVecDestroy:16' if ~isempty(coder.target) */
  /* 'petscVecDestroy:17' t_vec = PetscVec(vec); */
  /* Map an opaque object into a PETSc Vec object */
  /*  */
  /*   vec = PetscVec() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   vec = PetscVec(arg) or vec = PetscVec(arg, false) converts arg */
  /*   into a PETSc Vec object. */
  /*  */
  /*   vec = PetscVec(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscVec:18' coder.inline('always'); */
  /* 'PetscVec:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscVec:25' if isstruct(arg) && ~isequal(arg.type, 'Vec') */
  /* 'PetscVec:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscVec:31' if nargin==1 || ~opaque */
  /* 'PetscVec:32' vec = arg; */
  t_vec = xVec;

  /* 'petscVecDestroy:19' errCode = coder.ceval('VecDestroy', coder.ref(t_vec)); */
  errCode = VecDestroy(&t_vec);

  /* 'petscVecDestroy:21' toplevel = nargout>2; */
  /* 'petscVecDestroy:22' vec = PetscVec(t_vec, toplevel); */
  /* 'petscVecDestroy:24' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      /* 'petscVecDestroy:25' m2c_error('petsc:RuntimeError', 'VecDestroy returned error code %d\n', errCode) */
      cb_m2c_error(errCode);
    }
  }

  *flag = b_flag;
  *relres = b_relres;
  *iter = loop_ub;
  times[0] = time_setup;
  times[1] = time_solve;
}

/*
 * function [x,flag,relres,iter,times] = mptSolveCRS_4args(Arows, Acols, Avals, b)
 */
void mptSolveCRS_4args(const emxArray_int32_T *Arows, const emxArray_int32_T
  *Acols, const emxArray_real_T *Avals, const emxArray_real_T *b,
  emxArray_real_T *x, int *flag, double *relres, int *iter, double times[2])
{
  Mat AMat;
  Vec bVec;
  Vec t_vec_out;
  int errCode;
  int b_flag;
  PetscObject t_obj;
  MPI_Comm t_comm;
  KSP t_ksp;
  double t;
  double b_t;
  double b_relres;
  int b_iter;
  double time_solve;
  int c_flag;
  Mat t_mat;
  Vec t_vec;

  /* 'mptSolveCRS_4args:2' [x,flag,relres,iter,times] = mptSolveCRS(Arows, Acols, Avals, b); */
  /*  Solves a linear system using any PETSc solver for matrix in CRS format. */
  /*  */
  /*  Syntax: */
  /*     mptSolveCRS(Arows, Acols, Avals, b) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, solpack) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, solpack, x0) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, solpack, x0, opts) */
  /*  */
  /*     [x, flag, reslres, iter, times] = mptSolveCRS(Arows, Acols, Avals, b, ...) */
  /*  */
  /*     A is a sparse matrix in CRS format. b, x and resvec are all regular */
  /*     vectors. Solver is a value of PETSC_KSP*. pctype is a value of */
  /*     PETSC_PC*, and solpack is a value of PETSC_MATSOLVER*. */
  /*  */
  /*     For rtol, maxit, use 0 to use default values. */
  /*     For solver, pctype, solpack and opts, use empty string ('') to use default. */
  /*     For x0, use zeros(0, 1) to disable initial guess. */
  /*  */
  /*     When times is given, it returns a 2-vector contaning the times spent */
  /*     in setup and in solve separately. */
  /*  */
  /*  Description: */
  /*     mptSolveCRS(Arows, Acols, Avals, b) solves the linear system without */
  /*     preconditioners, using the default tolerances or those that have been */
  /*     set previously in the option databases. */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver) specifies to use a */
  /*     specific solver, such as PETSC_KSPGMRES, PETSC_KSPBCGS, etc. */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol) uses the given number */
  /*         of solvers and the relative tolerarance. */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit) solves with */
  /*         the given relative tolerances and maximum iteration count. */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype) */
  /*     uses the specified preconditioner (those give by PETSC_PC*). */
  /*     The preconditioner can be controlled by the PETSc option database. */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, */
  /*     solpack) specifies the solver packages for factorization (those give */
  /*     by PETSC_MATSOLVER*). */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, */
  /*     solpack, x0) usee x0 for the initial guess. x0 can be the same as x. */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, */
  /*     solpack, x0, opts) can pass additional command-line options in a */
  /*     string to PETSc. */
  /*  */
  /*  SEE ALSO: mptSolve, mptMatCreateAIJFromCRS, mptVecCreateFromArray, */
  /*            mptVecToArray, mptKSPSetup, mptKSPSolve, mptKSPCleanup */
  /* 'mptSolveCRS:81' if nargin==0 */
  /* 'mptSolveCRS:86' if isempty(coder.target) && ~exist(['petscVecDuplicate.' mexext], 'file') && ... */
  /* 'mptSolveCRS:87'         exist('run_mptSolveCRS_exe', 'file') */
  /* 'mptSolveCRS:96' Arows = varargin{1}; */
  /* 'mptSolveCRS:97' Acols = varargin{2}; */
  /* 'mptSolveCRS:98' Avals = varargin{3}; */
  /* 'mptSolveCRS:99' b = varargin{4}; */
  /*  Setup KSP */
  /* 'mptSolveCRS:102' if nargin<5 */
  /* 'mptSolveCRS:102' solver = ''; */
  /*  Use default */
  /* 'mptSolveCRS:103' if nargin<6 */
  /* 'mptSolveCRS:103' rtol = 0; */
  /* 'mptSolveCRS:104' if nargin<7 */
  /* 'mptSolveCRS:104' maxit = int32(0); */
  /* 'mptSolveCRS:105' if nargin<8 */
  /* 'mptSolveCRS:105' pctype = ''; */
  /* 'mptSolveCRS:106' if nargin<9 */
  /* 'mptSolveCRS:106' solpack = ''; */
  /* 'mptSolveCRS:108' AMat = mptMatCreateAIJFromCRS(Arows, Acols, Avals); */
  AMat = mptMatCreateAIJFromCRS(Arows, Acols, Avals);

  /* 'mptSolveCRS:109' bVec = mptVecCreateFromArray(b); */
  bVec = mptVecCreateFromArray(b);

  /* 'mptSolveCRS:111' if nargin<10 || isempty(varargin{10}) */
  /* 'mptSolveCRS:112' x0Vec = PETSC_NULL_VEC; */
  /*  Obtain PETSC constant NULL of type Vec */
  /* 'PETSC_NULL_VEC:4' coder.inline('always'); */
  /* 'PETSC_NULL_VEC:6' obj = petscGetObject('PETSC_NULL_VEC'); */
  /* petscGetObject Obtain an opaque object in PETSC */
  /*  */
  /*     obj = petscGetObject(name) */
  /*  */
  /* The supported names include: */
  /*  */
  /*  MPI_Comm: PETSC_COMM_SELF, PETSC_COMM_WORLD, MPI_COMM_SELF, MPI_COMM_WORLD */
  /*  */
  /*  Other: */
  /*      PETSC_IGNORE, PETSC_NULL_OPTION, PETSC_NULL_MAT, PETSC_NULL_VEC, */
  /*      PETSC_NULL_INT, PETSC_NULL_REAL */
  /* 'petscGetObject:16' if isempty(coder.target) */
  /* 'petscGetObject:20' switch name */
  /* 'petscGetObject:35' case 'PETSC_NULL_VEC' */
  /* 'petscGetObject:36' [obj, toplevel] = get_obj('Vec', 'NULL', nargout>1); */
  /* 'mptSolveCRS:113' xVec = petscVecDuplicate(bVec); */
  /* Creates a new vector of the same type as an existing vector. */
  /*  */
  /*   [vec_out, errCode] = petscVecDuplicate(vec_in) creates a new vector, but */
  /*      it does not copy the entries of the input vector. The user is */
  /*      responsible freeing the memory by calling petscVecDestroy. */
  /*  */
  /*   SEE ALSO: petscVecCopy, petscVecDestroy, petscVecCreate */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode  VecDuplicate(Vec vec_in, Vec *vec_out) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecDuplicate.html */
  /* 'petscVecDuplicate:16' errCode = int32(-1); */
  /* 'petscVecDuplicate:18' if ~isempty(coder.target) */
  /* 'petscVecDuplicate:19' t_vec_out = coder.opaque('Vec'); */
  /* 'petscVecDuplicate:21' errCode = coder.ceval('VecDuplicate', PetscVec(vec_in), coder.wref(t_vec_out)); */
  /* Map an opaque object into a PETSc Vec object */
  /*  */
  /*   vec = PetscVec() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   vec = PetscVec(arg) or vec = PetscVec(arg, false) converts arg */
  /*   into a PETSc Vec object. */
  /*  */
  /*   vec = PetscVec(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscVec:18' coder.inline('always'); */
  /* 'PetscVec:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscVec:25' if isstruct(arg) && ~isequal(arg.type, 'Vec') */
  /* 'PetscVec:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscVec:31' if nargin==1 || ~opaque */
  /* 'PetscVec:32' vec = arg; */
  errCode = VecDuplicate(bVec, &t_vec_out);

  /* 'petscVecDuplicate:23' toplevel = nargout>2; */
  /* 'petscVecDuplicate:24' vec_out = PetscVec(t_vec_out, toplevel); */
  /* Map an opaque object into a PETSc Vec object */
  /*  */
  /*   vec = PetscVec() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   vec = PetscVec(arg) or vec = PetscVec(arg, false) converts arg */
  /*   into a PETSc Vec object. */
  /*  */
  /*   vec = PetscVec(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscVec:18' coder.inline('always'); */
  /* 'PetscVec:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscVec:25' if isstruct(arg) && ~isequal(arg.type, 'Vec') */
  /* 'PetscVec:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscVec:31' if nargin==1 || ~opaque */
  /* 'PetscVec:32' vec = arg; */
  /* 'petscVecDuplicate:26' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      /* 'petscVecDuplicate:27' m2c_error('petsc:RuntimeError', 'VecDuplicate returned error code %d\n', errCode) */
      i_m2c_error(errCode);
    }
  }

  /* 'mptSolveCRS:120' if nargin<11 */
  /* 'mptSolveCRS:120' opts = ''; */
  /* 'mptSolveCRS:122' [flag,relres,iter, times] = mptSolve(AMat, bVec, xVec, solver, ... */
  /* 'mptSolveCRS:123'     double(rtol), int32(maxit), pctype, solpack, x0Vec, opts); */
  /*  Solves a linear system using a given solver in PETSc. */
  /*  */
  /*  Syntax: */
  /*     mptSolve(A_hdl, b_hdl) */
  /*     mptSolve(A_hdl, b_hdl, x_hdl) */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver) */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol) */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit) */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype) */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype, solpack) */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype, solpack, x0_hdl) */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype, solpack, x0_hdl, opts) */
  /*  */
  /*     [flag, reslres, iter] = mptSolve(A_hdl, b_hdl, x_hdl, ...) */
  /*  */
  /*     The handles are PetscMat or PetscVec objects. */
  /*  */
  /*  Description: */
  /*     mptSolve(A_hdl, b_hdl) solves the linear system without preconditioners, */
  /*     using the default tolerances or those that have been set previously in */
  /*     the option databases. A_hdl is a PetscMat object, and b_hdl is a */
  /*     PetscVec object. The solution is stored into b. The QMRCGS can be */
  /*     controlled using the options database for KSPQMRCGS. */
  /*  */
  /*     mptSolve(A_hdl, b_hdl, x_hdl) solves the linear system and saves the */
  /*     result into x. */
  /*  */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver) uses the specified solver, where */
  /*     solver is one of PETSC_KSP*. */
  /*  */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol) uses the given relative tolerarance. */
  /*  */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit) solves with the given */
  /*      relative tolerances and maximum iteration count. */
  /*  */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype) uses the */
  /*     specified preconditioner (PETSC_PC*). The preconditioner can be */
  /*     controlled by the PETSc option database. */
  /*  */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype, solpack) */
  /*     specifies the solver packages for factorization (PETSC_MATSOLVER*). */
  /*  */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype, solpack, */
  /*     x0_handle) usee x0 for the initial guess. x0 can be the same as x or */
  /*     be PETSC_NULL_VEC. */
  /*  */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype, solpack, */
  /*     x0_handle, opts) can pass command-line options in a string to PETSc. */
  /*  */
  /*  SEE ALSO: mptSolveCRS, mptMatCreateAIJFromCRS, mptVecCreateFromArray, */
  /*            mptOptionsInsert, mptKSPSetup, mptKSPSolve, mptKSPCleanup */
  /* This function is codegen compatbile, but no need to a top-level function */
  /*  Setup KSP */
  /* 'mptSolve:59' if nargin<3 */
  /* 'mptSolve:60' if nargin<4 */
  /* 'mptSolve:61' if nargin<5 */
  /* 'mptSolve:62' if nargin<6 */
  /* 'mptSolve:63' if nargin<7 */
  /* 'mptSolve:64' if nargin<8 */
  /* 'mptSolve:65' if nargin<9 */
  /* 'mptSolve:67' if nargin==10 && ~isempty(opts) */
  /* 'mptSolve:71' [ksp, time_setup] = mptKSPSetup(A, solver, pctype, solpack); */
  /*  Sets up KSP using the given matrix (matrices). */
  /*  */
  /*  Syntax: */
  /*   ksp = mptKSPSetup(A) */
  /*   ksp = mptKSPSetup(A, ksptype) */
  /*   ksp = mptKSPSetup(A, ksptype, pctype) */
  /*   ksp = mptKSPSetup(A, ksptype, pctype, solpack) */
  /*  */
  /*  Description: */
  /*   ksp = mptKSPSetup(A) sets up a KSP using matrix A. */
  /*  */
  /*   ksp = mptKSPSetup(A, ksptype) uses the specified type of the KSP. */
  /*  */
  /*   ksp = mptKSPSetup(A, ksptype, pctype) also sets the type of the KSP */
  /*     and the preconditioner. Note that pctype can be NULL. */
  /*  */
  /*   ksp = mptKSPSetup(A, ksptype, pctype, solpack) configures the KSP */
  /*     solver using the specified solver package. It is useful only when */
  /*     pctype is PCLU, PCILU, or PCICC. */
  /*  */
  /*  See Also: mptKSPSolve, mptKSPCleanup */
  /* 'mptKSPSetup:29' t_Amat = Amat; */
  /* 'mptKSPSetup:30' t_ksp = petscKSPCreate(petscObjectGetComm(t_Amat)); */
  /* Gets the MPI communicator for any PetscObject, regardless of the type.  */
  /*  */
  /*   [comm, errCode] = petscObjectGetComm(obj) */
  /*  */
  /*   obtains the MPI_Comm associated with the PetscObject. */
  /*  */
  /*   SEE ALSO: petscMatSetType, petscMatSetFromOptions */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode  PetscObjectGetComm(PetscObject obj,MPI_Comm *comm) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Sys/PetscObjectGetComm.html */
  /* 'petscObjectGetComm:16' errCode = int32(-1); */
  /* 'petscObjectGetComm:18' if ~isempty(coder.target) */
  /* 'petscObjectGetComm:19' t_obj = PetscObject(obj); */
  /* Map an opaque object into a PETSc PetscObject object */
  /*  */
  /*   obj = PetscObject() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   obj = PetscObject(arg) or obj = PetscObject(arg, false) converts arg */
  /*   into a PETSc Object object. */
  /*  */
  /*   obj = PetscObject(arg, true) wraps the arg into an opaque object. */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscObject:18' coder.inline('always'); */
  /* 'PetscObject:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscObject:25' if isstruct(arg) && ~isequal(arg.type, 'PetscObject') && ... */
  /* 'PetscObject:26'         ~isequal(arg.type, 'Mat') && ~isequal(arg.type, 'Vec') && ... */
  /* 'PetscObject:27'         ~isequal(arg.type, 'KSP') && ~isequal(arg.type, 'PC') */
  /* 'PetscObject:32' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscObject:33' if nargin==1 || ~opaque */
  /* 'PetscObject:34' obj = coder.opaque('PetscObject'); */
  /* 'PetscObject:35' obj = coder.ceval('(PetscObject)', arg); */
  t_obj = (PetscObject)(AMat);

  /* 'petscObjectGetComm:20' t_comm = coder.opaque('MPI_Comm'); */
  /* 'petscObjectGetComm:22' errCode = coder.ceval('PetscObjectGetComm', t_obj, coder.wref(t_comm)); */
  errCode = PetscObjectGetComm(t_obj, &t_comm);

  /* 'petscObjectGetComm:24' toplevel = nargout>2; */
  /* 'petscObjectGetComm:25' comm = MPI_Comm(t_comm, toplevel); */
  /* Map an opaque object into a PETSc MPI_Comm object */
  /*  */
  /*   comm = MPI_Comm() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   comm = MPI_Comm(arg) or comm = MPI_Comm(arg, false) converts arg */
  /*   into a PETSc Options object. */
  /*  */
  /*   comm = MPI_Comm(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'MPI_Comm:18' coder.inline('always'); */
  /* 'MPI_Comm:20' if nargin==0 && isempty(coder.target) */
  /* 'MPI_Comm:25' if isstruct(arg) && ~isequal(arg.type, 'MPI_Comm') */
  /* 'MPI_Comm:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'MPI_Comm:31' if nargin==1 || ~opaque */
  /* 'MPI_Comm:32' comm = arg; */
  /* 'petscObjectGetComm:27' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      /* 'petscObjectGetComm:28' m2c_error('petsc:RuntimeError', 'PetscObjectGetComm returned error code %d\n', errCode) */
      j_m2c_error(errCode);
    }
  }

  /* Creates a preconditioner context. */
  /*  */
  /*   [ksp, errCode] = petscKSPCreate */
  /*       creates a PETSc KSP using PETSC_COMM_WORLD */
  /*  */
  /*   [ksp, errCode] = petscKSPCreate(comm) */
  /*       comm: MPI Communicator */
  /*  */
  /*   SEE ALSO: petscKSPSetUp, petscKSPSolve, petscKSPDestroy */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode  KSPCreate(MPI_Comm comm,KSP *ksp) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPCreate.html */
  /* 'petscKSPCreate:18' errCode = int32(-1); */
  /* 'petscKSPCreate:20' if ~isempty(coder.target) */
  /* 'petscKSPCreate:21' t_ksp = coder.opaque('KSP'); */
  /* 'petscKSPCreate:23' if nargin==0 */
  /* 'petscKSPCreate:25' else */
  /* 'petscKSPCreate:26' t_comm = MPI_Comm(comm); */
  /* Map an opaque object into a PETSc MPI_Comm object */
  /*  */
  /*   comm = MPI_Comm() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   comm = MPI_Comm(arg) or comm = MPI_Comm(arg, false) converts arg */
  /*   into a PETSc Options object. */
  /*  */
  /*   comm = MPI_Comm(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'MPI_Comm:18' coder.inline('always'); */
  /* 'MPI_Comm:20' if nargin==0 && isempty(coder.target) */
  /* 'MPI_Comm:25' if isstruct(arg) && ~isequal(arg.type, 'MPI_Comm') */
  /* 'MPI_Comm:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'MPI_Comm:31' if nargin==1 || ~opaque */
  /* 'MPI_Comm:32' comm = arg; */
  /* 'petscKSPCreate:29' errCode = coder.ceval('KSPCreate', t_comm, coder.wref(t_ksp)); */
  errCode = KSPCreate(t_comm, &t_ksp);

  /* 'petscKSPCreate:31' toplevel = nargout>2; */
  /* 'petscKSPCreate:32' ksp = PetscKSP(t_ksp, toplevel); */
  /* Map an opaque object into a PETSc KSP object */
  /*  */
  /*   ksp = PetscKSP() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   ksp = PetscKSP(arg) or ksp = PetscKSP(arg, false) converts arg */
  /*   into a PETSc KSP object. */
  /*  */
  /*   ksp = PetscKSP(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscPC */
  /* 'PetscKSP:18' coder.inline('always'); */
  /* 'PetscKSP:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscKSP:25' if isstruct(arg) && ~isequal(arg.type, 'KSP') */
  /* 'PetscKSP:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscKSP:31' if nargin==1 || ~opaque */
  /* 'PetscKSP:32' ksp = arg; */
  /* 'petscKSPCreate:34' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      /* 'petscKSPCreate:35' m2c_error('petsc:RuntimeError', 'KSPCreate returned error code %d\n', errCode) */
      k_m2c_error(errCode);
    }
  }

  /* 'mptKSPSetup:32' time = 0; */
  /* 'mptKSPSetup:33' if nargout>1 */
  /* 'mptKSPSetup:33' t=m2c_wtime(); */
  /*  Return ellapsed time */
  /*    t = m2c_wtime */
  /* 'm2c_wtime:7' if isempty(coder.target) */
  /* 'm2c_wtime:10' else */
  /* 'm2c_wtime:11' coder.inline( 'always'); */
  /* 'm2c_wtime:13' t = 0; */
  /* 'm2c_wtime:13' t = coder.ceval( 'M2C_wtime'); */
  t = M2C_wtime();

  /*  Setup KSP */
  /* 'mptKSPSetup:36' petscKSPSetOperators(t_ksp, PetscMat(t_Amat)); */
  /* Map an opaque object into a PETSc Mat object */
  /*  */
  /*   mat = PetscMat() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   mat = PetscMat(arg) or mat = PetscMat(arg, false) converts arg */
  /*   into a PETSc Mat object. */
  /*  */
  /*   mat = PetscMat(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscMat:18' coder.inline('always'); */
  /* 'PetscMat:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscMat:25' if isstruct(arg) && ~isequal(arg.type, 'Mat') */
  /* 'PetscMat:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscMat:31' if nargin==1 || ~opaque */
  /* 'PetscMat:32' mat = arg; */
  /* Sets the matrix associated with the linear system and a (possibly) */
  /* different one associated with the preconditioner. */
  /*  */
  /*   errCode = petscKSPSetOperators(ksp, Amat) */
  /*  */
  /*   sets the matrix to be Amat and use the same matrix to construct the */
  /*   preconditioner. */
  /*      ksp - iterative context obtained from petscKSPCreate */
  /*      Amat	  - the right hand side vector */
  /*  */
  /*   errCode = petscKSPSetOperators(ksp, Amat, Pmat) */
  /*  */
  /*   uses the matrix Pmat to construct the preconditioner. */
  /*  */
  /*   SEE ALSO: petscKSPCreate, petscKSPSetUp, petscKSPSolve, petscKSPDestroy */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode  KSPSetOperators(KSP ksp,Mat Amat,Mat Pmat) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPSetOperators.html */
  /* 'petscKSPSetOperators:25' errCode = int32(-1); */
  /* 'petscKSPSetOperators:27' if ~isempty(coder.target) */
  /* 'petscKSPSetOperators:28' t_ksp = PetscKSP(ksp); */
  /* Map an opaque object into a PETSc KSP object */
  /*  */
  /*   ksp = PetscKSP() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   ksp = PetscKSP(arg) or ksp = PetscKSP(arg, false) converts arg */
  /*   into a PETSc KSP object. */
  /*  */
  /*   ksp = PetscKSP(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscPC */
  /* 'PetscKSP:18' coder.inline('always'); */
  /* 'PetscKSP:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscKSP:25' if isstruct(arg) && ~isequal(arg.type, 'KSP') */
  /* 'PetscKSP:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscKSP:31' if nargin==1 || ~opaque */
  /* 'PetscKSP:32' ksp = arg; */
  /* 'petscKSPSetOperators:29' t_Amat = PetscMat(Amat); */
  /* Map an opaque object into a PETSc Mat object */
  /*  */
  /*   mat = PetscMat() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   mat = PetscMat(arg) or mat = PetscMat(arg, false) converts arg */
  /*   into a PETSc Mat object. */
  /*  */
  /*   mat = PetscMat(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscMat:18' coder.inline('always'); */
  /* 'PetscMat:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscMat:25' if isstruct(arg) && ~isequal(arg.type, 'Mat') */
  /* 'PetscMat:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscMat:31' if nargin==1 || ~opaque */
  /* 'PetscMat:32' mat = arg; */
  /* 'petscKSPSetOperators:31' if nargin==2 */
  /* 'petscKSPSetOperators:32' t_Pmat = t_Amat; */
  /* 'petscKSPSetOperators:37' errCode = coder.ceval('KSPSetOperators', t_ksp, t_Amat, t_Pmat); */
  errCode = KSPSetOperators(t_ksp, AMat, AMat);

  /* 'petscKSPSetOperators:39' toplevel = nargout>1; */
  /* 'petscKSPSetOperators:40' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      /* 'petscKSPSetOperators:41' m2c_error('petsc:RuntimeError', 'KSPSetOperators returned error code %d\n', errCode) */
      l_m2c_error(errCode);
    }
  }

  /* 'mptKSPSetup:38' if nargin>1 */
  /* 'mptKSPSetup:39' if nargin>2 */
  /* 'mptKSPSetup:40' hasPC = ~ischar(pctype) || ~isempty(pctype); */
  /* 'mptKSPSetup:41' hasSolver = nargin>3 && (~ischar(solpack) || ~isempty(solpack)); */
  /* 'mptKSPSetup:43' if hasPC || hasSolver */
  /* 'mptKSPSetup:68' if ischar(ksptype) && ~isempty(ksptype) && ksptype(end)~=0 */
  /* 'mptKSPSetup:71' else */
  /* 'mptKSPSetup:72' ksptype0 = ksptype; */
  /* 'mptKSPSetup:74' if ischar(ksptype0) && ~isempty(ksptype0) || ~ischar(ksptype0) */
  /* 'mptKSPSetup:80' petscKSPSetFromOptions(t_ksp); */
  /* Sets KSP options from the options database. This routine must be called */
  /* before KSPSetUp() if the user is to be allowed to set the Krylov type. */
  /*  */
  /*   errCode = petscKSPSetFromOptions(ksp) */
  /*  */
  /*   SEE ALSO: petscKSPCreate, petscKSPSetOperators, petscKSPSolve, petscKSPDestroy */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode KSPSetFromOptions(KSP ksp) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPSetFromOptions.html */
  /* 'petscKSPSetFromOptions:15' errCode = int32(-1); */
  /* 'petscKSPSetFromOptions:17' if ~isempty(coder.target) */
  /* 'petscKSPSetFromOptions:18' t_ksp = PetscKSP(ksp); */
  /* Map an opaque object into a PETSc KSP object */
  /*  */
  /*   ksp = PetscKSP() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   ksp = PetscKSP(arg) or ksp = PetscKSP(arg, false) converts arg */
  /*   into a PETSc KSP object. */
  /*  */
  /*   ksp = PetscKSP(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscPC */
  /* 'PetscKSP:18' coder.inline('always'); */
  /* 'PetscKSP:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscKSP:25' if isstruct(arg) && ~isequal(arg.type, 'KSP') */
  /* 'PetscKSP:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscKSP:31' if nargin==1 || ~opaque */
  /* 'PetscKSP:32' ksp = arg; */
  /* 'petscKSPSetFromOptions:20' errCode = coder.ceval('KSPSetFromOptions', t_ksp); */
  errCode = KSPSetFromOptions(t_ksp);

  /* 'petscKSPSetFromOptions:22' toplevel = nargout>1; */
  /* 'petscKSPSetFromOptions:23' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      /* 'petscKSPSetFromOptions:24' m2c_error('petsc:RuntimeError', 'KSPSetFromOptions returned error code %d\n', errCode) */
      m_m2c_error(errCode);
    }
  }

  /* 'mptKSPSetup:82' petscKSPSetUp(t_ksp); */
  /* Sets up the internal data structures for the later use of an iterative solver. */
  /*  */
  /*   errCode = petscKSPSetUp(ksp) */
  /*  */
  /*   SEE ALSO: petscKSPCreate, petscKSPSetOperators, petscKSPSolve, petscKSPDestroy */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode KSPSetUp(KSP ksp) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPSetUp.html */
  /* 'petscKSPSetUp:14' errCode = int32(-1); */
  /* 'petscKSPSetUp:16' if ~isempty(coder.target) */
  /* 'petscKSPSetUp:17' t_ksp = PetscKSP(ksp); */
  /* Map an opaque object into a PETSc KSP object */
  /*  */
  /*   ksp = PetscKSP() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   ksp = PetscKSP(arg) or ksp = PetscKSP(arg, false) converts arg */
  /*   into a PETSc KSP object. */
  /*  */
  /*   ksp = PetscKSP(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscPC */
  /* 'PetscKSP:18' coder.inline('always'); */
  /* 'PetscKSP:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscKSP:25' if isstruct(arg) && ~isequal(arg.type, 'KSP') */
  /* 'PetscKSP:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscKSP:31' if nargin==1 || ~opaque */
  /* 'PetscKSP:32' ksp = arg; */
  /* 'petscKSPSetUp:19' errCode = coder.ceval('KSPSetUp', t_ksp); */
  errCode = KSPSetUp(t_ksp);

  /* 'petscKSPSetUp:21' toplevel = nargout>1; */
  /* 'petscKSPSetUp:22' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      /* 'petscKSPSetUp:23' m2c_error('petsc:RuntimeError', 'KSPSetUp returned error code %d\n', errCode) */
      n_m2c_error(errCode);
    }
  }

  /* 'mptKSPSetup:83' if nargout>1 */
  /* 'mptKSPSetup:83' time=m2c_wtime()-t; */
  /*  Return ellapsed time */
  /*    t = m2c_wtime */
  /* 'm2c_wtime:7' if isempty(coder.target) */
  /* 'm2c_wtime:10' else */
  /* 'm2c_wtime:11' coder.inline( 'always'); */
  /* 'm2c_wtime:13' t = 0; */
  /* 'm2c_wtime:13' t = coder.ceval( 'M2C_wtime'); */
  b_t = M2C_wtime();

  /* 'mptKSPSetup:85' toplevel = nargout>2; */
  /* 'mptKSPSetup:86' ksp = PetscKSP(t_ksp, toplevel); */
  /* Map an opaque object into a PETSc KSP object */
  /*  */
  /*   ksp = PetscKSP() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   ksp = PetscKSP(arg) or ksp = PetscKSP(arg, false) converts arg */
  /*   into a PETSc KSP object. */
  /*  */
  /*   ksp = PetscKSP(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscPC */
  /* 'PetscKSP:18' coder.inline('always'); */
  /* 'PetscKSP:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscKSP:25' if isstruct(arg) && ~isequal(arg.type, 'KSP') */
  /* 'PetscKSP:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscKSP:31' if nargin==1 || ~opaque */
  /* 'PetscKSP:32' ksp = arg; */
  /* 'mptSolve:73' [flag,relres,iter, time_solve] = mptKSPSolve(ksp, b, x, double(rtol), int32(maxit), x0); */
  mptKSPSolve(t_ksp, bVec, t_vec_out, 0.0, 0, NULL, &b_flag, &b_relres, &b_iter,
              &time_solve);

  /* 'mptSolve:75' if nargout>3 */
  /* 'mptSolve:76' times = [time_setup; time_solve]; */
  /* 'mptSolve:79' mptKSPCleanup(ksp); */
  /*  Cleans up the KSP. */
  /*  */
  /*    ksp = mptKSPCleanup(ksp) destropys the given KSP object. */
  /*    It should be called whtn the KSP object is no longer needed, and  */
  /*    no calls should be made to this KSP after this. */
  /*  */
  /*  See Also: mptKSPSetup, mptKSPSolve */
  /*  Destroy the KSP and solution vector */
  /* 'mptKSPCleanup:13' t_ksp = petscKSPDestroy(ksp); */
  /* Destroys KSP context. */
  /*  */
  /*   [ksp, errCode] = petscKSPDestroy(ksp) */
  /*  */
  /*   SEE ALSO: petscKSPCreate, petscKSPSetUp, petscKSPSolve */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode KSPDestroy(KSP *A) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPDestroy.html */
  /* 'petscKSPDestroy:14' errCode = int32(-1); */
  /* 'petscKSPDestroy:16' if ~isempty(coder.target) */
  /* 'petscKSPDestroy:17' t_ksp = PetscKSP(ksp); */
  /* Map an opaque object into a PETSc KSP object */
  /*  */
  /*   ksp = PetscKSP() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   ksp = PetscKSP(arg) or ksp = PetscKSP(arg, false) converts arg */
  /*   into a PETSc KSP object. */
  /*  */
  /*   ksp = PetscKSP(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscPC */
  /* 'PetscKSP:18' coder.inline('always'); */
  /* 'PetscKSP:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscKSP:25' if isstruct(arg) && ~isequal(arg.type, 'KSP') */
  /* 'PetscKSP:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscKSP:31' if nargin==1 || ~opaque */
  /* 'PetscKSP:32' ksp = arg; */
  /* 'petscKSPDestroy:19' errCode = coder.ceval('KSPDestroy', coder.ref(t_ksp)); */
  errCode = KSPDestroy(&t_ksp);

  /* 'petscKSPDestroy:21' toplevel = nargout>2; */
  /* 'petscKSPDestroy:22' ksp_out = PetscKSP(t_ksp, toplevel); */
  /* Map an opaque object into a PETSc KSP object */
  /*  */
  /*   ksp = PetscKSP() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   ksp = PetscKSP(arg) or ksp = PetscKSP(arg, false) converts arg */
  /*   into a PETSc KSP object. */
  /*  */
  /*   ksp = PetscKSP(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscPC */
  /* 'PetscKSP:18' coder.inline('always'); */
  /* 'PetscKSP:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscKSP:25' if isstruct(arg) && ~isequal(arg.type, 'KSP') */
  /* 'PetscKSP:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscKSP:31' if nargin==1 || ~opaque */
  /* 'PetscKSP:32' ksp = arg; */
  /* 'petscKSPDestroy:24' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      /* 'petscKSPDestroy:25' m2c_error('petsc:RuntimeError', 'KSPDestroy returned error code %d\n', errCode) */
      ab_m2c_error(errCode);
    }
  }

  /* 'mptKSPCleanup:15' toplevel = nargout>1; */
  /* 'mptKSPCleanup:16' ksp = PetscKSP(t_ksp, toplevel); */
  /* 'mptSolveCRS:125' petscMatDestroy(AMat); */
  /* Frees space taken by a matrix. */
  /*  */
  /*   [mat, errCode] = petscMatDestroy(mat) */
  /*  */
  /*   SEE ALSO: petscVecCreateSeq, petscVecCreateMPI, petscAssembleMat, petscVecDestroy */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode MatDestroy(Mat *A) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatDestroy.html */
  /* 'petscMatDestroy:14' errCode = int32(-1); */
  /* 'petscMatDestroy:16' if ~isempty(coder.target) */
  /* 'petscMatDestroy:17' t_mat = PetscMat(mat); */
  /* Map an opaque object into a PETSc Mat object */
  /*  */
  /*   mat = PetscMat() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   mat = PetscMat(arg) or mat = PetscMat(arg, false) converts arg */
  /*   into a PETSc Mat object. */
  /*  */
  /*   mat = PetscMat(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscMat:18' coder.inline('always'); */
  /* 'PetscMat:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscMat:25' if isstruct(arg) && ~isequal(arg.type, 'Mat') */
  /* 'PetscMat:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscMat:31' if nargin==1 || ~opaque */
  /* 'PetscMat:32' mat = arg; */
  t_mat = AMat;

  /* 'petscMatDestroy:19' errCode = coder.ceval('MatDestroy', coder.ref(t_mat)); */
  errCode = MatDestroy(&t_mat);

  /* 'petscMatDestroy:21' toplevel = nargout>2; */
  /* 'petscMatDestroy:22' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      /* 'petscMatDestroy:23' m2c_error('petsc:RuntimeError', 'MatDestroy returned error code %d\n', errCode) */
      bb_m2c_error(errCode);
    }
  }

  /* 'petscMatDestroy:26' mat = PetscMat(t_mat, toplevel); */
  /* 'mptSolveCRS:126' petscVecDestroy(bVec); */
  /* Frees space taken by a vector. */
  /*  */
  /*   [vec, errCode] = petscVecDestroy(vec) */
  /*  */
  /*   SEE ALSO: petscVecCreateSeq, petscVecCreateMPI, petscAssembleVec, */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode VecDestroy(Vec *A) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecDestroy.html */
  /* 'petscVecDestroy:14' errCode = int32(-1); */
  /* 'petscVecDestroy:16' if ~isempty(coder.target) */
  /* 'petscVecDestroy:17' t_vec = PetscVec(vec); */
  /* Map an opaque object into a PETSc Vec object */
  /*  */
  /*   vec = PetscVec() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   vec = PetscVec(arg) or vec = PetscVec(arg, false) converts arg */
  /*   into a PETSc Vec object. */
  /*  */
  /*   vec = PetscVec(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscVec:18' coder.inline('always'); */
  /* 'PetscVec:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscVec:25' if isstruct(arg) && ~isequal(arg.type, 'Vec') */
  /* 'PetscVec:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscVec:31' if nargin==1 || ~opaque */
  /* 'PetscVec:32' vec = arg; */
  t_vec = bVec;

  /* 'petscVecDestroy:19' errCode = coder.ceval('VecDestroy', coder.ref(t_vec)); */
  errCode = VecDestroy(&t_vec);

  /* 'petscVecDestroy:21' toplevel = nargout>2; */
  /* 'petscVecDestroy:22' vec = PetscVec(t_vec, toplevel); */
  /* 'petscVecDestroy:24' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      /* 'petscVecDestroy:25' m2c_error('petsc:RuntimeError', 'VecDestroy returned error code %d\n', errCode) */
      cb_m2c_error(errCode);
    }
  }

  /* 'mptSolveCRS:128' x = mptVecToArray(xVec); */
  mptVecToArray(t_vec_out, x);

  /* 'mptSolveCRS:129' petscVecDestroy(xVec); */
  /* Frees space taken by a vector. */
  /*  */
  /*   [vec, errCode] = petscVecDestroy(vec) */
  /*  */
  /*   SEE ALSO: petscVecCreateSeq, petscVecCreateMPI, petscAssembleVec, */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode VecDestroy(Vec *A) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecDestroy.html */
  /* 'petscVecDestroy:14' errCode = int32(-1); */
  /* 'petscVecDestroy:16' if ~isempty(coder.target) */
  /* 'petscVecDestroy:17' t_vec = PetscVec(vec); */
  /* Map an opaque object into a PETSc Vec object */
  /*  */
  /*   vec = PetscVec() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   vec = PetscVec(arg) or vec = PetscVec(arg, false) converts arg */
  /*   into a PETSc Vec object. */
  /*  */
  /*   vec = PetscVec(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscVec:18' coder.inline('always'); */
  /* 'PetscVec:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscVec:25' if isstruct(arg) && ~isequal(arg.type, 'Vec') */
  /* 'PetscVec:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscVec:31' if nargin==1 || ~opaque */
  /* 'PetscVec:32' vec = arg; */
  t_vec = t_vec_out;

  /* 'petscVecDestroy:19' errCode = coder.ceval('VecDestroy', coder.ref(t_vec)); */
  errCode = VecDestroy(&t_vec);

  /* 'petscVecDestroy:21' toplevel = nargout>2; */
  /* 'petscVecDestroy:22' vec = PetscVec(t_vec, toplevel); */
  /* 'petscVecDestroy:24' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      /* 'petscVecDestroy:25' m2c_error('petsc:RuntimeError', 'VecDestroy returned error code %d\n', errCode) */
      cb_m2c_error(errCode);
    }
  }

  *flag = b_flag;
  *relres = b_relres;
  *iter = b_iter;
  times[0] = b_t - t;
  times[1] = time_solve;
}

/*
 * function [x,flag,relres,iter,times] = mptSolveCRS_5args(Arows, Acols, Avals, b, solver)
 */
void mptSolveCRS_5args(const emxArray_int32_T *Arows, const emxArray_int32_T
  *Acols, const emxArray_real_T *Avals, const emxArray_real_T *b, const
  emxArray_char_T *solver, emxArray_real_T *x, int *flag, double *relres, int
  *iter, double times[2])
{
  Mat AMat;
  Vec bVec;
  Vec t_vec_out;
  int errCode;
  int b_flag;
  double b_relres;
  int b_iter;
  Mat t_mat;
  int c_flag;
  Vec t_vec;

  /* 'mptSolveCRS_5args:2' [x,flag,relres,iter,times] = mptSolveCRS(Arows, Acols, Avals, b, solver); */
  /*  Solves a linear system using any PETSc solver for matrix in CRS format. */
  /*  */
  /*  Syntax: */
  /*     mptSolveCRS(Arows, Acols, Avals, b) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, solpack) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, solpack, x0) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, solpack, x0, opts) */
  /*  */
  /*     [x, flag, reslres, iter, times] = mptSolveCRS(Arows, Acols, Avals, b, ...) */
  /*  */
  /*     A is a sparse matrix in CRS format. b, x and resvec are all regular */
  /*     vectors. Solver is a value of PETSC_KSP*. pctype is a value of */
  /*     PETSC_PC*, and solpack is a value of PETSC_MATSOLVER*. */
  /*  */
  /*     For rtol, maxit, use 0 to use default values. */
  /*     For solver, pctype, solpack and opts, use empty string ('') to use default. */
  /*     For x0, use zeros(0, 1) to disable initial guess. */
  /*  */
  /*     When times is given, it returns a 2-vector contaning the times spent */
  /*     in setup and in solve separately. */
  /*  */
  /*  Description: */
  /*     mptSolveCRS(Arows, Acols, Avals, b) solves the linear system without */
  /*     preconditioners, using the default tolerances or those that have been */
  /*     set previously in the option databases. */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver) specifies to use a */
  /*     specific solver, such as PETSC_KSPGMRES, PETSC_KSPBCGS, etc. */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol) uses the given number */
  /*         of solvers and the relative tolerarance. */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit) solves with */
  /*         the given relative tolerances and maximum iteration count. */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype) */
  /*     uses the specified preconditioner (those give by PETSC_PC*). */
  /*     The preconditioner can be controlled by the PETSc option database. */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, */
  /*     solpack) specifies the solver packages for factorization (those give */
  /*     by PETSC_MATSOLVER*). */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, */
  /*     solpack, x0) usee x0 for the initial guess. x0 can be the same as x. */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, */
  /*     solpack, x0, opts) can pass additional command-line options in a */
  /*     string to PETSc. */
  /*  */
  /*  SEE ALSO: mptSolve, mptMatCreateAIJFromCRS, mptVecCreateFromArray, */
  /*            mptVecToArray, mptKSPSetup, mptKSPSolve, mptKSPCleanup */
  /* 'mptSolveCRS:81' if nargin==0 */
  /* 'mptSolveCRS:86' if isempty(coder.target) && ~exist(['petscVecDuplicate.' mexext], 'file') && ... */
  /* 'mptSolveCRS:87'         exist('run_mptSolveCRS_exe', 'file') */
  /* 'mptSolveCRS:96' Arows = varargin{1}; */
  /* 'mptSolveCRS:97' Acols = varargin{2}; */
  /* 'mptSolveCRS:98' Avals = varargin{3}; */
  /* 'mptSolveCRS:99' b = varargin{4}; */
  /*  Setup KSP */
  /* 'mptSolveCRS:102' if nargin<5 */
  /* 'mptSolveCRS:102' else */
  /* 'mptSolveCRS:102' solver = varargin{5}; */
  /*  Use default */
  /* 'mptSolveCRS:103' if nargin<6 */
  /* 'mptSolveCRS:103' rtol = 0; */
  /* 'mptSolveCRS:104' if nargin<7 */
  /* 'mptSolveCRS:104' maxit = int32(0); */
  /* 'mptSolveCRS:105' if nargin<8 */
  /* 'mptSolveCRS:105' pctype = ''; */
  /* 'mptSolveCRS:106' if nargin<9 */
  /* 'mptSolveCRS:106' solpack = ''; */
  /* 'mptSolveCRS:108' AMat = mptMatCreateAIJFromCRS(Arows, Acols, Avals); */
  AMat = mptMatCreateAIJFromCRS(Arows, Acols, Avals);

  /* 'mptSolveCRS:109' bVec = mptVecCreateFromArray(b); */
  bVec = mptVecCreateFromArray(b);

  /* 'mptSolveCRS:111' if nargin<10 || isempty(varargin{10}) */
  /* 'mptSolveCRS:112' x0Vec = PETSC_NULL_VEC; */
  /*  Obtain PETSC constant NULL of type Vec */
  /* 'PETSC_NULL_VEC:4' coder.inline('always'); */
  /* 'PETSC_NULL_VEC:6' obj = petscGetObject('PETSC_NULL_VEC'); */
  /* petscGetObject Obtain an opaque object in PETSC */
  /*  */
  /*     obj = petscGetObject(name) */
  /*  */
  /* The supported names include: */
  /*  */
  /*  MPI_Comm: PETSC_COMM_SELF, PETSC_COMM_WORLD, MPI_COMM_SELF, MPI_COMM_WORLD */
  /*  */
  /*  Other: */
  /*      PETSC_IGNORE, PETSC_NULL_OPTION, PETSC_NULL_MAT, PETSC_NULL_VEC, */
  /*      PETSC_NULL_INT, PETSC_NULL_REAL */
  /* 'petscGetObject:16' if isempty(coder.target) */
  /* 'petscGetObject:20' switch name */
  /* 'petscGetObject:35' case 'PETSC_NULL_VEC' */
  /* 'petscGetObject:36' [obj, toplevel] = get_obj('Vec', 'NULL', nargout>1); */
  /* 'mptSolveCRS:113' xVec = petscVecDuplicate(bVec); */
  /* Creates a new vector of the same type as an existing vector. */
  /*  */
  /*   [vec_out, errCode] = petscVecDuplicate(vec_in) creates a new vector, but */
  /*      it does not copy the entries of the input vector. The user is */
  /*      responsible freeing the memory by calling petscVecDestroy. */
  /*  */
  /*   SEE ALSO: petscVecCopy, petscVecDestroy, petscVecCreate */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode  VecDuplicate(Vec vec_in, Vec *vec_out) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecDuplicate.html */
  /* 'petscVecDuplicate:16' errCode = int32(-1); */
  /* 'petscVecDuplicate:18' if ~isempty(coder.target) */
  /* 'petscVecDuplicate:19' t_vec_out = coder.opaque('Vec'); */
  /* 'petscVecDuplicate:21' errCode = coder.ceval('VecDuplicate', PetscVec(vec_in), coder.wref(t_vec_out)); */
  /* Map an opaque object into a PETSc Vec object */
  /*  */
  /*   vec = PetscVec() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   vec = PetscVec(arg) or vec = PetscVec(arg, false) converts arg */
  /*   into a PETSc Vec object. */
  /*  */
  /*   vec = PetscVec(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscVec:18' coder.inline('always'); */
  /* 'PetscVec:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscVec:25' if isstruct(arg) && ~isequal(arg.type, 'Vec') */
  /* 'PetscVec:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscVec:31' if nargin==1 || ~opaque */
  /* 'PetscVec:32' vec = arg; */
  errCode = VecDuplicate(bVec, &t_vec_out);

  /* 'petscVecDuplicate:23' toplevel = nargout>2; */
  /* 'petscVecDuplicate:24' vec_out = PetscVec(t_vec_out, toplevel); */
  /* Map an opaque object into a PETSc Vec object */
  /*  */
  /*   vec = PetscVec() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   vec = PetscVec(arg) or vec = PetscVec(arg, false) converts arg */
  /*   into a PETSc Vec object. */
  /*  */
  /*   vec = PetscVec(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscVec:18' coder.inline('always'); */
  /* 'PetscVec:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscVec:25' if isstruct(arg) && ~isequal(arg.type, 'Vec') */
  /* 'PetscVec:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscVec:31' if nargin==1 || ~opaque */
  /* 'PetscVec:32' vec = arg; */
  /* 'petscVecDuplicate:26' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      /* 'petscVecDuplicate:27' m2c_error('petsc:RuntimeError', 'VecDuplicate returned error code %d\n', errCode) */
      i_m2c_error(errCode);
    }
  }

  /* 'mptSolveCRS:120' if nargin<11 */
  /* 'mptSolveCRS:120' opts = ''; */
  /* 'mptSolveCRS:122' [flag,relres,iter, times] = mptSolve(AMat, bVec, xVec, solver, ... */
  /* 'mptSolveCRS:123'     double(rtol), int32(maxit), pctype, solpack, x0Vec, opts); */
  mptSolve(AMat, bVec, t_vec_out, solver, 0.0, 0, NULL, &b_flag, &b_relres,
           &b_iter, times);

  /* 'mptSolveCRS:125' petscMatDestroy(AMat); */
  /* Frees space taken by a matrix. */
  /*  */
  /*   [mat, errCode] = petscMatDestroy(mat) */
  /*  */
  /*   SEE ALSO: petscVecCreateSeq, petscVecCreateMPI, petscAssembleMat, petscVecDestroy */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode MatDestroy(Mat *A) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatDestroy.html */
  /* 'petscMatDestroy:14' errCode = int32(-1); */
  /* 'petscMatDestroy:16' if ~isempty(coder.target) */
  /* 'petscMatDestroy:17' t_mat = PetscMat(mat); */
  /* Map an opaque object into a PETSc Mat object */
  /*  */
  /*   mat = PetscMat() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   mat = PetscMat(arg) or mat = PetscMat(arg, false) converts arg */
  /*   into a PETSc Mat object. */
  /*  */
  /*   mat = PetscMat(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscMat:18' coder.inline('always'); */
  /* 'PetscMat:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscMat:25' if isstruct(arg) && ~isequal(arg.type, 'Mat') */
  /* 'PetscMat:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscMat:31' if nargin==1 || ~opaque */
  /* 'PetscMat:32' mat = arg; */
  t_mat = AMat;

  /* 'petscMatDestroy:19' errCode = coder.ceval('MatDestroy', coder.ref(t_mat)); */
  errCode = MatDestroy(&t_mat);

  /* 'petscMatDestroy:21' toplevel = nargout>2; */
  /* 'petscMatDestroy:22' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      /* 'petscMatDestroy:23' m2c_error('petsc:RuntimeError', 'MatDestroy returned error code %d\n', errCode) */
      bb_m2c_error(errCode);
    }
  }

  /* 'petscMatDestroy:26' mat = PetscMat(t_mat, toplevel); */
  /* 'mptSolveCRS:126' petscVecDestroy(bVec); */
  /* Frees space taken by a vector. */
  /*  */
  /*   [vec, errCode] = petscVecDestroy(vec) */
  /*  */
  /*   SEE ALSO: petscVecCreateSeq, petscVecCreateMPI, petscAssembleVec, */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode VecDestroy(Vec *A) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecDestroy.html */
  /* 'petscVecDestroy:14' errCode = int32(-1); */
  /* 'petscVecDestroy:16' if ~isempty(coder.target) */
  /* 'petscVecDestroy:17' t_vec = PetscVec(vec); */
  /* Map an opaque object into a PETSc Vec object */
  /*  */
  /*   vec = PetscVec() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   vec = PetscVec(arg) or vec = PetscVec(arg, false) converts arg */
  /*   into a PETSc Vec object. */
  /*  */
  /*   vec = PetscVec(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscVec:18' coder.inline('always'); */
  /* 'PetscVec:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscVec:25' if isstruct(arg) && ~isequal(arg.type, 'Vec') */
  /* 'PetscVec:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscVec:31' if nargin==1 || ~opaque */
  /* 'PetscVec:32' vec = arg; */
  t_vec = bVec;

  /* 'petscVecDestroy:19' errCode = coder.ceval('VecDestroy', coder.ref(t_vec)); */
  errCode = VecDestroy(&t_vec);

  /* 'petscVecDestroy:21' toplevel = nargout>2; */
  /* 'petscVecDestroy:22' vec = PetscVec(t_vec, toplevel); */
  /* 'petscVecDestroy:24' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      /* 'petscVecDestroy:25' m2c_error('petsc:RuntimeError', 'VecDestroy returned error code %d\n', errCode) */
      cb_m2c_error(errCode);
    }
  }

  /* 'mptSolveCRS:128' x = mptVecToArray(xVec); */
  mptVecToArray(t_vec_out, x);

  /* 'mptSolveCRS:129' petscVecDestroy(xVec); */
  /* Frees space taken by a vector. */
  /*  */
  /*   [vec, errCode] = petscVecDestroy(vec) */
  /*  */
  /*   SEE ALSO: petscVecCreateSeq, petscVecCreateMPI, petscAssembleVec, */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode VecDestroy(Vec *A) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecDestroy.html */
  /* 'petscVecDestroy:14' errCode = int32(-1); */
  /* 'petscVecDestroy:16' if ~isempty(coder.target) */
  /* 'petscVecDestroy:17' t_vec = PetscVec(vec); */
  /* Map an opaque object into a PETSc Vec object */
  /*  */
  /*   vec = PetscVec() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   vec = PetscVec(arg) or vec = PetscVec(arg, false) converts arg */
  /*   into a PETSc Vec object. */
  /*  */
  /*   vec = PetscVec(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscVec:18' coder.inline('always'); */
  /* 'PetscVec:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscVec:25' if isstruct(arg) && ~isequal(arg.type, 'Vec') */
  /* 'PetscVec:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscVec:31' if nargin==1 || ~opaque */
  /* 'PetscVec:32' vec = arg; */
  t_vec = t_vec_out;

  /* 'petscVecDestroy:19' errCode = coder.ceval('VecDestroy', coder.ref(t_vec)); */
  errCode = VecDestroy(&t_vec);

  /* 'petscVecDestroy:21' toplevel = nargout>2; */
  /* 'petscVecDestroy:22' vec = PetscVec(t_vec, toplevel); */
  /* 'petscVecDestroy:24' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      /* 'petscVecDestroy:25' m2c_error('petsc:RuntimeError', 'VecDestroy returned error code %d\n', errCode) */
      cb_m2c_error(errCode);
    }
  }

  *flag = b_flag;
  *relres = b_relres;
  *iter = b_iter;
}

/*
 * function [x,flag,relres,iter,times] = mptSolveCRS_6args(Arows, Acols, Avals, b, solver, rtol)
 */
void mptSolveCRS_6args(const emxArray_int32_T *Arows, const emxArray_int32_T
  *Acols, const emxArray_real_T *Avals, const emxArray_real_T *b, const
  emxArray_char_T *solver, double rtol, emxArray_real_T *x, int *flag, double
  *relres, int *iter, double times[2])
{
  Mat AMat;
  Vec bVec;
  Vec t_vec_out;
  int errCode;
  int b_flag;
  double b_relres;
  int b_iter;
  Mat t_mat;
  int c_flag;
  Vec t_vec;

  /* 'mptSolveCRS_6args:2' [x,flag,relres,iter,times] = mptSolveCRS(Arows, Acols, Avals, b, solver, rtol); */
  /*  Solves a linear system using any PETSc solver for matrix in CRS format. */
  /*  */
  /*  Syntax: */
  /*     mptSolveCRS(Arows, Acols, Avals, b) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, solpack) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, solpack, x0) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, solpack, x0, opts) */
  /*  */
  /*     [x, flag, reslres, iter, times] = mptSolveCRS(Arows, Acols, Avals, b, ...) */
  /*  */
  /*     A is a sparse matrix in CRS format. b, x and resvec are all regular */
  /*     vectors. Solver is a value of PETSC_KSP*. pctype is a value of */
  /*     PETSC_PC*, and solpack is a value of PETSC_MATSOLVER*. */
  /*  */
  /*     For rtol, maxit, use 0 to use default values. */
  /*     For solver, pctype, solpack and opts, use empty string ('') to use default. */
  /*     For x0, use zeros(0, 1) to disable initial guess. */
  /*  */
  /*     When times is given, it returns a 2-vector contaning the times spent */
  /*     in setup and in solve separately. */
  /*  */
  /*  Description: */
  /*     mptSolveCRS(Arows, Acols, Avals, b) solves the linear system without */
  /*     preconditioners, using the default tolerances or those that have been */
  /*     set previously in the option databases. */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver) specifies to use a */
  /*     specific solver, such as PETSC_KSPGMRES, PETSC_KSPBCGS, etc. */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol) uses the given number */
  /*         of solvers and the relative tolerarance. */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit) solves with */
  /*         the given relative tolerances and maximum iteration count. */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype) */
  /*     uses the specified preconditioner (those give by PETSC_PC*). */
  /*     The preconditioner can be controlled by the PETSc option database. */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, */
  /*     solpack) specifies the solver packages for factorization (those give */
  /*     by PETSC_MATSOLVER*). */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, */
  /*     solpack, x0) usee x0 for the initial guess. x0 can be the same as x. */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, */
  /*     solpack, x0, opts) can pass additional command-line options in a */
  /*     string to PETSc. */
  /*  */
  /*  SEE ALSO: mptSolve, mptMatCreateAIJFromCRS, mptVecCreateFromArray, */
  /*            mptVecToArray, mptKSPSetup, mptKSPSolve, mptKSPCleanup */
  /* 'mptSolveCRS:81' if nargin==0 */
  /* 'mptSolveCRS:86' if isempty(coder.target) && ~exist(['petscVecDuplicate.' mexext], 'file') && ... */
  /* 'mptSolveCRS:87'         exist('run_mptSolveCRS_exe', 'file') */
  /* 'mptSolveCRS:96' Arows = varargin{1}; */
  /* 'mptSolveCRS:97' Acols = varargin{2}; */
  /* 'mptSolveCRS:98' Avals = varargin{3}; */
  /* 'mptSolveCRS:99' b = varargin{4}; */
  /*  Setup KSP */
  /* 'mptSolveCRS:102' if nargin<5 */
  /* 'mptSolveCRS:102' else */
  /* 'mptSolveCRS:102' solver = varargin{5}; */
  /*  Use default */
  /* 'mptSolveCRS:103' if nargin<6 */
  /* 'mptSolveCRS:103' else */
  /* 'mptSolveCRS:103' rtol = varargin{6}; */
  /* 'mptSolveCRS:104' if nargin<7 */
  /* 'mptSolveCRS:104' maxit = int32(0); */
  /* 'mptSolveCRS:105' if nargin<8 */
  /* 'mptSolveCRS:105' pctype = ''; */
  /* 'mptSolveCRS:106' if nargin<9 */
  /* 'mptSolveCRS:106' solpack = ''; */
  /* 'mptSolveCRS:108' AMat = mptMatCreateAIJFromCRS(Arows, Acols, Avals); */
  AMat = mptMatCreateAIJFromCRS(Arows, Acols, Avals);

  /* 'mptSolveCRS:109' bVec = mptVecCreateFromArray(b); */
  bVec = mptVecCreateFromArray(b);

  /* 'mptSolveCRS:111' if nargin<10 || isempty(varargin{10}) */
  /* 'mptSolveCRS:112' x0Vec = PETSC_NULL_VEC; */
  /*  Obtain PETSC constant NULL of type Vec */
  /* 'PETSC_NULL_VEC:4' coder.inline('always'); */
  /* 'PETSC_NULL_VEC:6' obj = petscGetObject('PETSC_NULL_VEC'); */
  /* petscGetObject Obtain an opaque object in PETSC */
  /*  */
  /*     obj = petscGetObject(name) */
  /*  */
  /* The supported names include: */
  /*  */
  /*  MPI_Comm: PETSC_COMM_SELF, PETSC_COMM_WORLD, MPI_COMM_SELF, MPI_COMM_WORLD */
  /*  */
  /*  Other: */
  /*      PETSC_IGNORE, PETSC_NULL_OPTION, PETSC_NULL_MAT, PETSC_NULL_VEC, */
  /*      PETSC_NULL_INT, PETSC_NULL_REAL */
  /* 'petscGetObject:16' if isempty(coder.target) */
  /* 'petscGetObject:20' switch name */
  /* 'petscGetObject:35' case 'PETSC_NULL_VEC' */
  /* 'petscGetObject:36' [obj, toplevel] = get_obj('Vec', 'NULL', nargout>1); */
  /* 'mptSolveCRS:113' xVec = petscVecDuplicate(bVec); */
  /* Creates a new vector of the same type as an existing vector. */
  /*  */
  /*   [vec_out, errCode] = petscVecDuplicate(vec_in) creates a new vector, but */
  /*      it does not copy the entries of the input vector. The user is */
  /*      responsible freeing the memory by calling petscVecDestroy. */
  /*  */
  /*   SEE ALSO: petscVecCopy, petscVecDestroy, petscVecCreate */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode  VecDuplicate(Vec vec_in, Vec *vec_out) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecDuplicate.html */
  /* 'petscVecDuplicate:16' errCode = int32(-1); */
  /* 'petscVecDuplicate:18' if ~isempty(coder.target) */
  /* 'petscVecDuplicate:19' t_vec_out = coder.opaque('Vec'); */
  /* 'petscVecDuplicate:21' errCode = coder.ceval('VecDuplicate', PetscVec(vec_in), coder.wref(t_vec_out)); */
  /* Map an opaque object into a PETSc Vec object */
  /*  */
  /*   vec = PetscVec() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   vec = PetscVec(arg) or vec = PetscVec(arg, false) converts arg */
  /*   into a PETSc Vec object. */
  /*  */
  /*   vec = PetscVec(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscVec:18' coder.inline('always'); */
  /* 'PetscVec:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscVec:25' if isstruct(arg) && ~isequal(arg.type, 'Vec') */
  /* 'PetscVec:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscVec:31' if nargin==1 || ~opaque */
  /* 'PetscVec:32' vec = arg; */
  errCode = VecDuplicate(bVec, &t_vec_out);

  /* 'petscVecDuplicate:23' toplevel = nargout>2; */
  /* 'petscVecDuplicate:24' vec_out = PetscVec(t_vec_out, toplevel); */
  /* Map an opaque object into a PETSc Vec object */
  /*  */
  /*   vec = PetscVec() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   vec = PetscVec(arg) or vec = PetscVec(arg, false) converts arg */
  /*   into a PETSc Vec object. */
  /*  */
  /*   vec = PetscVec(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscVec:18' coder.inline('always'); */
  /* 'PetscVec:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscVec:25' if isstruct(arg) && ~isequal(arg.type, 'Vec') */
  /* 'PetscVec:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscVec:31' if nargin==1 || ~opaque */
  /* 'PetscVec:32' vec = arg; */
  /* 'petscVecDuplicate:26' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      /* 'petscVecDuplicate:27' m2c_error('petsc:RuntimeError', 'VecDuplicate returned error code %d\n', errCode) */
      i_m2c_error(errCode);
    }
  }

  /* 'mptSolveCRS:120' if nargin<11 */
  /* 'mptSolveCRS:120' opts = ''; */
  /* 'mptSolveCRS:122' [flag,relres,iter, times] = mptSolve(AMat, bVec, xVec, solver, ... */
  /* 'mptSolveCRS:123'     double(rtol), int32(maxit), pctype, solpack, x0Vec, opts); */
  mptSolve(AMat, bVec, t_vec_out, solver, rtol, 0, NULL, &b_flag, &b_relres,
           &b_iter, times);

  /* 'mptSolveCRS:125' petscMatDestroy(AMat); */
  /* Frees space taken by a matrix. */
  /*  */
  /*   [mat, errCode] = petscMatDestroy(mat) */
  /*  */
  /*   SEE ALSO: petscVecCreateSeq, petscVecCreateMPI, petscAssembleMat, petscVecDestroy */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode MatDestroy(Mat *A) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatDestroy.html */
  /* 'petscMatDestroy:14' errCode = int32(-1); */
  /* 'petscMatDestroy:16' if ~isempty(coder.target) */
  /* 'petscMatDestroy:17' t_mat = PetscMat(mat); */
  /* Map an opaque object into a PETSc Mat object */
  /*  */
  /*   mat = PetscMat() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   mat = PetscMat(arg) or mat = PetscMat(arg, false) converts arg */
  /*   into a PETSc Mat object. */
  /*  */
  /*   mat = PetscMat(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscMat:18' coder.inline('always'); */
  /* 'PetscMat:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscMat:25' if isstruct(arg) && ~isequal(arg.type, 'Mat') */
  /* 'PetscMat:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscMat:31' if nargin==1 || ~opaque */
  /* 'PetscMat:32' mat = arg; */
  t_mat = AMat;

  /* 'petscMatDestroy:19' errCode = coder.ceval('MatDestroy', coder.ref(t_mat)); */
  errCode = MatDestroy(&t_mat);

  /* 'petscMatDestroy:21' toplevel = nargout>2; */
  /* 'petscMatDestroy:22' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      /* 'petscMatDestroy:23' m2c_error('petsc:RuntimeError', 'MatDestroy returned error code %d\n', errCode) */
      bb_m2c_error(errCode);
    }
  }

  /* 'petscMatDestroy:26' mat = PetscMat(t_mat, toplevel); */
  /* 'mptSolveCRS:126' petscVecDestroy(bVec); */
  /* Frees space taken by a vector. */
  /*  */
  /*   [vec, errCode] = petscVecDestroy(vec) */
  /*  */
  /*   SEE ALSO: petscVecCreateSeq, petscVecCreateMPI, petscAssembleVec, */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode VecDestroy(Vec *A) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecDestroy.html */
  /* 'petscVecDestroy:14' errCode = int32(-1); */
  /* 'petscVecDestroy:16' if ~isempty(coder.target) */
  /* 'petscVecDestroy:17' t_vec = PetscVec(vec); */
  /* Map an opaque object into a PETSc Vec object */
  /*  */
  /*   vec = PetscVec() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   vec = PetscVec(arg) or vec = PetscVec(arg, false) converts arg */
  /*   into a PETSc Vec object. */
  /*  */
  /*   vec = PetscVec(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscVec:18' coder.inline('always'); */
  /* 'PetscVec:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscVec:25' if isstruct(arg) && ~isequal(arg.type, 'Vec') */
  /* 'PetscVec:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscVec:31' if nargin==1 || ~opaque */
  /* 'PetscVec:32' vec = arg; */
  t_vec = bVec;

  /* 'petscVecDestroy:19' errCode = coder.ceval('VecDestroy', coder.ref(t_vec)); */
  errCode = VecDestroy(&t_vec);

  /* 'petscVecDestroy:21' toplevel = nargout>2; */
  /* 'petscVecDestroy:22' vec = PetscVec(t_vec, toplevel); */
  /* 'petscVecDestroy:24' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      /* 'petscVecDestroy:25' m2c_error('petsc:RuntimeError', 'VecDestroy returned error code %d\n', errCode) */
      cb_m2c_error(errCode);
    }
  }

  /* 'mptSolveCRS:128' x = mptVecToArray(xVec); */
  mptVecToArray(t_vec_out, x);

  /* 'mptSolveCRS:129' petscVecDestroy(xVec); */
  /* Frees space taken by a vector. */
  /*  */
  /*   [vec, errCode] = petscVecDestroy(vec) */
  /*  */
  /*   SEE ALSO: petscVecCreateSeq, petscVecCreateMPI, petscAssembleVec, */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode VecDestroy(Vec *A) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecDestroy.html */
  /* 'petscVecDestroy:14' errCode = int32(-1); */
  /* 'petscVecDestroy:16' if ~isempty(coder.target) */
  /* 'petscVecDestroy:17' t_vec = PetscVec(vec); */
  /* Map an opaque object into a PETSc Vec object */
  /*  */
  /*   vec = PetscVec() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   vec = PetscVec(arg) or vec = PetscVec(arg, false) converts arg */
  /*   into a PETSc Vec object. */
  /*  */
  /*   vec = PetscVec(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscVec:18' coder.inline('always'); */
  /* 'PetscVec:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscVec:25' if isstruct(arg) && ~isequal(arg.type, 'Vec') */
  /* 'PetscVec:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscVec:31' if nargin==1 || ~opaque */
  /* 'PetscVec:32' vec = arg; */
  t_vec = t_vec_out;

  /* 'petscVecDestroy:19' errCode = coder.ceval('VecDestroy', coder.ref(t_vec)); */
  errCode = VecDestroy(&t_vec);

  /* 'petscVecDestroy:21' toplevel = nargout>2; */
  /* 'petscVecDestroy:22' vec = PetscVec(t_vec, toplevel); */
  /* 'petscVecDestroy:24' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      /* 'petscVecDestroy:25' m2c_error('petsc:RuntimeError', 'VecDestroy returned error code %d\n', errCode) */
      cb_m2c_error(errCode);
    }
  }

  *flag = b_flag;
  *relres = b_relres;
  *iter = b_iter;
}

/*
 * function [x,flag,relres,iter,times] = mptSolveCRS_7args(Arows, Acols, Avals, b, solver, rtol, maxiter)
 */
void mptSolveCRS_7args(const emxArray_int32_T *Arows, const emxArray_int32_T
  *Acols, const emxArray_real_T *Avals, const emxArray_real_T *b, const
  emxArray_char_T *solver, double rtol, int maxiter, emxArray_real_T *x, int
  *flag, double *relres, int *iter, double times[2])
{
  Mat AMat;
  Vec bVec;
  Vec t_vec_out;
  int errCode;
  int b_flag;
  double b_relres;
  int b_iter;
  Mat t_mat;
  int c_flag;
  Vec t_vec;

  /* 'mptSolveCRS_7args:2' [x,flag,relres,iter,times] = mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxiter); */
  /*  Solves a linear system using any PETSc solver for matrix in CRS format. */
  /*  */
  /*  Syntax: */
  /*     mptSolveCRS(Arows, Acols, Avals, b) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, solpack) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, solpack, x0) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, solpack, x0, opts) */
  /*  */
  /*     [x, flag, reslres, iter, times] = mptSolveCRS(Arows, Acols, Avals, b, ...) */
  /*  */
  /*     A is a sparse matrix in CRS format. b, x and resvec are all regular */
  /*     vectors. Solver is a value of PETSC_KSP*. pctype is a value of */
  /*     PETSC_PC*, and solpack is a value of PETSC_MATSOLVER*. */
  /*  */
  /*     For rtol, maxit, use 0 to use default values. */
  /*     For solver, pctype, solpack and opts, use empty string ('') to use default. */
  /*     For x0, use zeros(0, 1) to disable initial guess. */
  /*  */
  /*     When times is given, it returns a 2-vector contaning the times spent */
  /*     in setup and in solve separately. */
  /*  */
  /*  Description: */
  /*     mptSolveCRS(Arows, Acols, Avals, b) solves the linear system without */
  /*     preconditioners, using the default tolerances or those that have been */
  /*     set previously in the option databases. */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver) specifies to use a */
  /*     specific solver, such as PETSC_KSPGMRES, PETSC_KSPBCGS, etc. */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol) uses the given number */
  /*         of solvers and the relative tolerarance. */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit) solves with */
  /*         the given relative tolerances and maximum iteration count. */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype) */
  /*     uses the specified preconditioner (those give by PETSC_PC*). */
  /*     The preconditioner can be controlled by the PETSc option database. */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, */
  /*     solpack) specifies the solver packages for factorization (those give */
  /*     by PETSC_MATSOLVER*). */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, */
  /*     solpack, x0) usee x0 for the initial guess. x0 can be the same as x. */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, */
  /*     solpack, x0, opts) can pass additional command-line options in a */
  /*     string to PETSc. */
  /*  */
  /*  SEE ALSO: mptSolve, mptMatCreateAIJFromCRS, mptVecCreateFromArray, */
  /*            mptVecToArray, mptKSPSetup, mptKSPSolve, mptKSPCleanup */
  /* 'mptSolveCRS:81' if nargin==0 */
  /* 'mptSolveCRS:86' if isempty(coder.target) && ~exist(['petscVecDuplicate.' mexext], 'file') && ... */
  /* 'mptSolveCRS:87'         exist('run_mptSolveCRS_exe', 'file') */
  /* 'mptSolveCRS:96' Arows = varargin{1}; */
  /* 'mptSolveCRS:97' Acols = varargin{2}; */
  /* 'mptSolveCRS:98' Avals = varargin{3}; */
  /* 'mptSolveCRS:99' b = varargin{4}; */
  /*  Setup KSP */
  /* 'mptSolveCRS:102' if nargin<5 */
  /* 'mptSolveCRS:102' else */
  /* 'mptSolveCRS:102' solver = varargin{5}; */
  /*  Use default */
  /* 'mptSolveCRS:103' if nargin<6 */
  /* 'mptSolveCRS:103' else */
  /* 'mptSolveCRS:103' rtol = varargin{6}; */
  /* 'mptSolveCRS:104' if nargin<7 */
  /* 'mptSolveCRS:104' else */
  /* 'mptSolveCRS:104' maxit = varargin{7}; */
  /* 'mptSolveCRS:105' if nargin<8 */
  /* 'mptSolveCRS:105' pctype = ''; */
  /* 'mptSolveCRS:106' if nargin<9 */
  /* 'mptSolveCRS:106' solpack = ''; */
  /* 'mptSolveCRS:108' AMat = mptMatCreateAIJFromCRS(Arows, Acols, Avals); */
  AMat = mptMatCreateAIJFromCRS(Arows, Acols, Avals);

  /* 'mptSolveCRS:109' bVec = mptVecCreateFromArray(b); */
  bVec = mptVecCreateFromArray(b);

  /* 'mptSolveCRS:111' if nargin<10 || isempty(varargin{10}) */
  /* 'mptSolveCRS:112' x0Vec = PETSC_NULL_VEC; */
  /*  Obtain PETSC constant NULL of type Vec */
  /* 'PETSC_NULL_VEC:4' coder.inline('always'); */
  /* 'PETSC_NULL_VEC:6' obj = petscGetObject('PETSC_NULL_VEC'); */
  /* petscGetObject Obtain an opaque object in PETSC */
  /*  */
  /*     obj = petscGetObject(name) */
  /*  */
  /* The supported names include: */
  /*  */
  /*  MPI_Comm: PETSC_COMM_SELF, PETSC_COMM_WORLD, MPI_COMM_SELF, MPI_COMM_WORLD */
  /*  */
  /*  Other: */
  /*      PETSC_IGNORE, PETSC_NULL_OPTION, PETSC_NULL_MAT, PETSC_NULL_VEC, */
  /*      PETSC_NULL_INT, PETSC_NULL_REAL */
  /* 'petscGetObject:16' if isempty(coder.target) */
  /* 'petscGetObject:20' switch name */
  /* 'petscGetObject:35' case 'PETSC_NULL_VEC' */
  /* 'petscGetObject:36' [obj, toplevel] = get_obj('Vec', 'NULL', nargout>1); */
  /* 'mptSolveCRS:113' xVec = petscVecDuplicate(bVec); */
  /* Creates a new vector of the same type as an existing vector. */
  /*  */
  /*   [vec_out, errCode] = petscVecDuplicate(vec_in) creates a new vector, but */
  /*      it does not copy the entries of the input vector. The user is */
  /*      responsible freeing the memory by calling petscVecDestroy. */
  /*  */
  /*   SEE ALSO: petscVecCopy, petscVecDestroy, petscVecCreate */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode  VecDuplicate(Vec vec_in, Vec *vec_out) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecDuplicate.html */
  /* 'petscVecDuplicate:16' errCode = int32(-1); */
  /* 'petscVecDuplicate:18' if ~isempty(coder.target) */
  /* 'petscVecDuplicate:19' t_vec_out = coder.opaque('Vec'); */
  /* 'petscVecDuplicate:21' errCode = coder.ceval('VecDuplicate', PetscVec(vec_in), coder.wref(t_vec_out)); */
  /* Map an opaque object into a PETSc Vec object */
  /*  */
  /*   vec = PetscVec() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   vec = PetscVec(arg) or vec = PetscVec(arg, false) converts arg */
  /*   into a PETSc Vec object. */
  /*  */
  /*   vec = PetscVec(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscVec:18' coder.inline('always'); */
  /* 'PetscVec:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscVec:25' if isstruct(arg) && ~isequal(arg.type, 'Vec') */
  /* 'PetscVec:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscVec:31' if nargin==1 || ~opaque */
  /* 'PetscVec:32' vec = arg; */
  errCode = VecDuplicate(bVec, &t_vec_out);

  /* 'petscVecDuplicate:23' toplevel = nargout>2; */
  /* 'petscVecDuplicate:24' vec_out = PetscVec(t_vec_out, toplevel); */
  /* Map an opaque object into a PETSc Vec object */
  /*  */
  /*   vec = PetscVec() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   vec = PetscVec(arg) or vec = PetscVec(arg, false) converts arg */
  /*   into a PETSc Vec object. */
  /*  */
  /*   vec = PetscVec(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscVec:18' coder.inline('always'); */
  /* 'PetscVec:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscVec:25' if isstruct(arg) && ~isequal(arg.type, 'Vec') */
  /* 'PetscVec:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscVec:31' if nargin==1 || ~opaque */
  /* 'PetscVec:32' vec = arg; */
  /* 'petscVecDuplicate:26' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      /* 'petscVecDuplicate:27' m2c_error('petsc:RuntimeError', 'VecDuplicate returned error code %d\n', errCode) */
      i_m2c_error(errCode);
    }
  }

  /* 'mptSolveCRS:120' if nargin<11 */
  /* 'mptSolveCRS:120' opts = ''; */
  /* 'mptSolveCRS:122' [flag,relres,iter, times] = mptSolve(AMat, bVec, xVec, solver, ... */
  /* 'mptSolveCRS:123'     double(rtol), int32(maxit), pctype, solpack, x0Vec, opts); */
  mptSolve(AMat, bVec, t_vec_out, solver, rtol, maxiter, NULL, &b_flag,
           &b_relres, &b_iter, times);

  /* 'mptSolveCRS:125' petscMatDestroy(AMat); */
  /* Frees space taken by a matrix. */
  /*  */
  /*   [mat, errCode] = petscMatDestroy(mat) */
  /*  */
  /*   SEE ALSO: petscVecCreateSeq, petscVecCreateMPI, petscAssembleMat, petscVecDestroy */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode MatDestroy(Mat *A) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatDestroy.html */
  /* 'petscMatDestroy:14' errCode = int32(-1); */
  /* 'petscMatDestroy:16' if ~isempty(coder.target) */
  /* 'petscMatDestroy:17' t_mat = PetscMat(mat); */
  /* Map an opaque object into a PETSc Mat object */
  /*  */
  /*   mat = PetscMat() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   mat = PetscMat(arg) or mat = PetscMat(arg, false) converts arg */
  /*   into a PETSc Mat object. */
  /*  */
  /*   mat = PetscMat(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscMat:18' coder.inline('always'); */
  /* 'PetscMat:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscMat:25' if isstruct(arg) && ~isequal(arg.type, 'Mat') */
  /* 'PetscMat:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscMat:31' if nargin==1 || ~opaque */
  /* 'PetscMat:32' mat = arg; */
  t_mat = AMat;

  /* 'petscMatDestroy:19' errCode = coder.ceval('MatDestroy', coder.ref(t_mat)); */
  errCode = MatDestroy(&t_mat);

  /* 'petscMatDestroy:21' toplevel = nargout>2; */
  /* 'petscMatDestroy:22' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      /* 'petscMatDestroy:23' m2c_error('petsc:RuntimeError', 'MatDestroy returned error code %d\n', errCode) */
      bb_m2c_error(errCode);
    }
  }

  /* 'petscMatDestroy:26' mat = PetscMat(t_mat, toplevel); */
  /* 'mptSolveCRS:126' petscVecDestroy(bVec); */
  /* Frees space taken by a vector. */
  /*  */
  /*   [vec, errCode] = petscVecDestroy(vec) */
  /*  */
  /*   SEE ALSO: petscVecCreateSeq, petscVecCreateMPI, petscAssembleVec, */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode VecDestroy(Vec *A) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecDestroy.html */
  /* 'petscVecDestroy:14' errCode = int32(-1); */
  /* 'petscVecDestroy:16' if ~isempty(coder.target) */
  /* 'petscVecDestroy:17' t_vec = PetscVec(vec); */
  /* Map an opaque object into a PETSc Vec object */
  /*  */
  /*   vec = PetscVec() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   vec = PetscVec(arg) or vec = PetscVec(arg, false) converts arg */
  /*   into a PETSc Vec object. */
  /*  */
  /*   vec = PetscVec(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscVec:18' coder.inline('always'); */
  /* 'PetscVec:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscVec:25' if isstruct(arg) && ~isequal(arg.type, 'Vec') */
  /* 'PetscVec:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscVec:31' if nargin==1 || ~opaque */
  /* 'PetscVec:32' vec = arg; */
  t_vec = bVec;

  /* 'petscVecDestroy:19' errCode = coder.ceval('VecDestroy', coder.ref(t_vec)); */
  errCode = VecDestroy(&t_vec);

  /* 'petscVecDestroy:21' toplevel = nargout>2; */
  /* 'petscVecDestroy:22' vec = PetscVec(t_vec, toplevel); */
  /* 'petscVecDestroy:24' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      /* 'petscVecDestroy:25' m2c_error('petsc:RuntimeError', 'VecDestroy returned error code %d\n', errCode) */
      cb_m2c_error(errCode);
    }
  }

  /* 'mptSolveCRS:128' x = mptVecToArray(xVec); */
  mptVecToArray(t_vec_out, x);

  /* 'mptSolveCRS:129' petscVecDestroy(xVec); */
  /* Frees space taken by a vector. */
  /*  */
  /*   [vec, errCode] = petscVecDestroy(vec) */
  /*  */
  /*   SEE ALSO: petscVecCreateSeq, petscVecCreateMPI, petscAssembleVec, */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode VecDestroy(Vec *A) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecDestroy.html */
  /* 'petscVecDestroy:14' errCode = int32(-1); */
  /* 'petscVecDestroy:16' if ~isempty(coder.target) */
  /* 'petscVecDestroy:17' t_vec = PetscVec(vec); */
  /* Map an opaque object into a PETSc Vec object */
  /*  */
  /*   vec = PetscVec() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   vec = PetscVec(arg) or vec = PetscVec(arg, false) converts arg */
  /*   into a PETSc Vec object. */
  /*  */
  /*   vec = PetscVec(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscVec:18' coder.inline('always'); */
  /* 'PetscVec:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscVec:25' if isstruct(arg) && ~isequal(arg.type, 'Vec') */
  /* 'PetscVec:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscVec:31' if nargin==1 || ~opaque */
  /* 'PetscVec:32' vec = arg; */
  t_vec = t_vec_out;

  /* 'petscVecDestroy:19' errCode = coder.ceval('VecDestroy', coder.ref(t_vec)); */
  errCode = VecDestroy(&t_vec);

  /* 'petscVecDestroy:21' toplevel = nargout>2; */
  /* 'petscVecDestroy:22' vec = PetscVec(t_vec, toplevel); */
  /* 'petscVecDestroy:24' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      /* 'petscVecDestroy:25' m2c_error('petsc:RuntimeError', 'VecDestroy returned error code %d\n', errCode) */
      cb_m2c_error(errCode);
    }
  }

  *flag = b_flag;
  *relres = b_relres;
  *iter = b_iter;
}

/*
 * function [x,flag,relres,iter,times] = mptSolveCRS_8args(Arows, Acols, Avals, b, solver, rtol, maxiter, pctype)
 */
void mptSolveCRS_8args(const emxArray_int32_T *Arows, const emxArray_int32_T
  *Acols, const emxArray_real_T *Avals, const emxArray_real_T *b, const
  emxArray_char_T *solver, double rtol, int maxiter, const emxArray_char_T
  *pctype, emxArray_real_T *x, int *flag, double *relres, int *iter, double
  times[2])
{
  Mat AMat;
  Vec bVec;
  Vec t_vec_out;
  int errCode;
  int b_flag;
  PetscObject t_obj;
  MPI_Comm t_comm;
  KSP t_ksp;
  double t;
  boolean_T b0;
  emxArray_char_T *pctype0;
  int loop_ub;
  PC t_pc;
  double b_t;
  double b_relres;
  double time_solve;
  int c_flag;
  Mat t_mat;
  Vec t_vec;

  /* 'mptSolveCRS_8args:2' [x,flag,relres,iter,times] = mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxiter, pctype); */
  /*  Solves a linear system using any PETSc solver for matrix in CRS format. */
  /*  */
  /*  Syntax: */
  /*     mptSolveCRS(Arows, Acols, Avals, b) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, solpack) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, solpack, x0) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, solpack, x0, opts) */
  /*  */
  /*     [x, flag, reslres, iter, times] = mptSolveCRS(Arows, Acols, Avals, b, ...) */
  /*  */
  /*     A is a sparse matrix in CRS format. b, x and resvec are all regular */
  /*     vectors. Solver is a value of PETSC_KSP*. pctype is a value of */
  /*     PETSC_PC*, and solpack is a value of PETSC_MATSOLVER*. */
  /*  */
  /*     For rtol, maxit, use 0 to use default values. */
  /*     For solver, pctype, solpack and opts, use empty string ('') to use default. */
  /*     For x0, use zeros(0, 1) to disable initial guess. */
  /*  */
  /*     When times is given, it returns a 2-vector contaning the times spent */
  /*     in setup and in solve separately. */
  /*  */
  /*  Description: */
  /*     mptSolveCRS(Arows, Acols, Avals, b) solves the linear system without */
  /*     preconditioners, using the default tolerances or those that have been */
  /*     set previously in the option databases. */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver) specifies to use a */
  /*     specific solver, such as PETSC_KSPGMRES, PETSC_KSPBCGS, etc. */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol) uses the given number */
  /*         of solvers and the relative tolerarance. */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit) solves with */
  /*         the given relative tolerances and maximum iteration count. */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype) */
  /*     uses the specified preconditioner (those give by PETSC_PC*). */
  /*     The preconditioner can be controlled by the PETSc option database. */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, */
  /*     solpack) specifies the solver packages for factorization (those give */
  /*     by PETSC_MATSOLVER*). */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, */
  /*     solpack, x0) usee x0 for the initial guess. x0 can be the same as x. */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, */
  /*     solpack, x0, opts) can pass additional command-line options in a */
  /*     string to PETSc. */
  /*  */
  /*  SEE ALSO: mptSolve, mptMatCreateAIJFromCRS, mptVecCreateFromArray, */
  /*            mptVecToArray, mptKSPSetup, mptKSPSolve, mptKSPCleanup */
  /* 'mptSolveCRS:81' if nargin==0 */
  /* 'mptSolveCRS:86' if isempty(coder.target) && ~exist(['petscVecDuplicate.' mexext], 'file') && ... */
  /* 'mptSolveCRS:87'         exist('run_mptSolveCRS_exe', 'file') */
  /* 'mptSolveCRS:96' Arows = varargin{1}; */
  /* 'mptSolveCRS:97' Acols = varargin{2}; */
  /* 'mptSolveCRS:98' Avals = varargin{3}; */
  /* 'mptSolveCRS:99' b = varargin{4}; */
  /*  Setup KSP */
  /* 'mptSolveCRS:102' if nargin<5 */
  /* 'mptSolveCRS:102' else */
  /* 'mptSolveCRS:102' solver = varargin{5}; */
  /*  Use default */
  /* 'mptSolveCRS:103' if nargin<6 */
  /* 'mptSolveCRS:103' else */
  /* 'mptSolveCRS:103' rtol = varargin{6}; */
  /* 'mptSolveCRS:104' if nargin<7 */
  /* 'mptSolveCRS:104' else */
  /* 'mptSolveCRS:104' maxit = varargin{7}; */
  /* 'mptSolveCRS:105' if nargin<8 */
  /* 'mptSolveCRS:105' else */
  /* 'mptSolveCRS:105' pctype = varargin{8}; */
  /* 'mptSolveCRS:106' if nargin<9 */
  /* 'mptSolveCRS:106' solpack = ''; */
  /* 'mptSolveCRS:108' AMat = mptMatCreateAIJFromCRS(Arows, Acols, Avals); */
  AMat = mptMatCreateAIJFromCRS(Arows, Acols, Avals);

  /* 'mptSolveCRS:109' bVec = mptVecCreateFromArray(b); */
  bVec = mptVecCreateFromArray(b);

  /* 'mptSolveCRS:111' if nargin<10 || isempty(varargin{10}) */
  /* 'mptSolveCRS:112' x0Vec = PETSC_NULL_VEC; */
  /*  Obtain PETSC constant NULL of type Vec */
  /* 'PETSC_NULL_VEC:4' coder.inline('always'); */
  /* 'PETSC_NULL_VEC:6' obj = petscGetObject('PETSC_NULL_VEC'); */
  /* petscGetObject Obtain an opaque object in PETSC */
  /*  */
  /*     obj = petscGetObject(name) */
  /*  */
  /* The supported names include: */
  /*  */
  /*  MPI_Comm: PETSC_COMM_SELF, PETSC_COMM_WORLD, MPI_COMM_SELF, MPI_COMM_WORLD */
  /*  */
  /*  Other: */
  /*      PETSC_IGNORE, PETSC_NULL_OPTION, PETSC_NULL_MAT, PETSC_NULL_VEC, */
  /*      PETSC_NULL_INT, PETSC_NULL_REAL */
  /* 'petscGetObject:16' if isempty(coder.target) */
  /* 'petscGetObject:20' switch name */
  /* 'petscGetObject:35' case 'PETSC_NULL_VEC' */
  /* 'petscGetObject:36' [obj, toplevel] = get_obj('Vec', 'NULL', nargout>1); */
  /* 'mptSolveCRS:113' xVec = petscVecDuplicate(bVec); */
  /* Creates a new vector of the same type as an existing vector. */
  /*  */
  /*   [vec_out, errCode] = petscVecDuplicate(vec_in) creates a new vector, but */
  /*      it does not copy the entries of the input vector. The user is */
  /*      responsible freeing the memory by calling petscVecDestroy. */
  /*  */
  /*   SEE ALSO: petscVecCopy, petscVecDestroy, petscVecCreate */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode  VecDuplicate(Vec vec_in, Vec *vec_out) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecDuplicate.html */
  /* 'petscVecDuplicate:16' errCode = int32(-1); */
  /* 'petscVecDuplicate:18' if ~isempty(coder.target) */
  /* 'petscVecDuplicate:19' t_vec_out = coder.opaque('Vec'); */
  /* 'petscVecDuplicate:21' errCode = coder.ceval('VecDuplicate', PetscVec(vec_in), coder.wref(t_vec_out)); */
  /* Map an opaque object into a PETSc Vec object */
  /*  */
  /*   vec = PetscVec() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   vec = PetscVec(arg) or vec = PetscVec(arg, false) converts arg */
  /*   into a PETSc Vec object. */
  /*  */
  /*   vec = PetscVec(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscVec:18' coder.inline('always'); */
  /* 'PetscVec:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscVec:25' if isstruct(arg) && ~isequal(arg.type, 'Vec') */
  /* 'PetscVec:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscVec:31' if nargin==1 || ~opaque */
  /* 'PetscVec:32' vec = arg; */
  errCode = VecDuplicate(bVec, &t_vec_out);

  /* 'petscVecDuplicate:23' toplevel = nargout>2; */
  /* 'petscVecDuplicate:24' vec_out = PetscVec(t_vec_out, toplevel); */
  /* Map an opaque object into a PETSc Vec object */
  /*  */
  /*   vec = PetscVec() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   vec = PetscVec(arg) or vec = PetscVec(arg, false) converts arg */
  /*   into a PETSc Vec object. */
  /*  */
  /*   vec = PetscVec(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscVec:18' coder.inline('always'); */
  /* 'PetscVec:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscVec:25' if isstruct(arg) && ~isequal(arg.type, 'Vec') */
  /* 'PetscVec:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscVec:31' if nargin==1 || ~opaque */
  /* 'PetscVec:32' vec = arg; */
  /* 'petscVecDuplicate:26' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      /* 'petscVecDuplicate:27' m2c_error('petsc:RuntimeError', 'VecDuplicate returned error code %d\n', errCode) */
      i_m2c_error(errCode);
    }
  }

  /* 'mptSolveCRS:120' if nargin<11 */
  /* 'mptSolveCRS:120' opts = ''; */
  /* 'mptSolveCRS:122' [flag,relres,iter, times] = mptSolve(AMat, bVec, xVec, solver, ... */
  /* 'mptSolveCRS:123'     double(rtol), int32(maxit), pctype, solpack, x0Vec, opts); */
  /*  Solves a linear system using a given solver in PETSc. */
  /*  */
  /*  Syntax: */
  /*     mptSolve(A_hdl, b_hdl) */
  /*     mptSolve(A_hdl, b_hdl, x_hdl) */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver) */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol) */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit) */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype) */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype, solpack) */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype, solpack, x0_hdl) */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype, solpack, x0_hdl, opts) */
  /*  */
  /*     [flag, reslres, iter] = mptSolve(A_hdl, b_hdl, x_hdl, ...) */
  /*  */
  /*     The handles are PetscMat or PetscVec objects. */
  /*  */
  /*  Description: */
  /*     mptSolve(A_hdl, b_hdl) solves the linear system without preconditioners, */
  /*     using the default tolerances or those that have been set previously in */
  /*     the option databases. A_hdl is a PetscMat object, and b_hdl is a */
  /*     PetscVec object. The solution is stored into b. The QMRCGS can be */
  /*     controlled using the options database for KSPQMRCGS. */
  /*  */
  /*     mptSolve(A_hdl, b_hdl, x_hdl) solves the linear system and saves the */
  /*     result into x. */
  /*  */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver) uses the specified solver, where */
  /*     solver is one of PETSC_KSP*. */
  /*  */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol) uses the given relative tolerarance. */
  /*  */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit) solves with the given */
  /*      relative tolerances and maximum iteration count. */
  /*  */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype) uses the */
  /*     specified preconditioner (PETSC_PC*). The preconditioner can be */
  /*     controlled by the PETSc option database. */
  /*  */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype, solpack) */
  /*     specifies the solver packages for factorization (PETSC_MATSOLVER*). */
  /*  */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype, solpack, */
  /*     x0_handle) usee x0 for the initial guess. x0 can be the same as x or */
  /*     be PETSC_NULL_VEC. */
  /*  */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype, solpack, */
  /*     x0_handle, opts) can pass command-line options in a string to PETSc. */
  /*  */
  /*  SEE ALSO: mptSolveCRS, mptMatCreateAIJFromCRS, mptVecCreateFromArray, */
  /*            mptOptionsInsert, mptKSPSetup, mptKSPSolve, mptKSPCleanup */
  /* This function is codegen compatbile, but no need to a top-level function */
  /*  Setup KSP */
  /* 'mptSolve:59' if nargin<3 */
  /* 'mptSolve:60' if nargin<4 */
  /* 'mptSolve:61' if nargin<5 */
  /* 'mptSolve:62' if nargin<6 */
  /* 'mptSolve:63' if nargin<7 */
  /* 'mptSolve:64' if nargin<8 */
  /* 'mptSolve:65' if nargin<9 */
  /* 'mptSolve:67' if nargin==10 && ~isempty(opts) */
  /* 'mptSolve:71' [ksp, time_setup] = mptKSPSetup(A, solver, pctype, solpack); */
  /*  Sets up KSP using the given matrix (matrices). */
  /*  */
  /*  Syntax: */
  /*   ksp = mptKSPSetup(A) */
  /*   ksp = mptKSPSetup(A, ksptype) */
  /*   ksp = mptKSPSetup(A, ksptype, pctype) */
  /*   ksp = mptKSPSetup(A, ksptype, pctype, solpack) */
  /*  */
  /*  Description: */
  /*   ksp = mptKSPSetup(A) sets up a KSP using matrix A. */
  /*  */
  /*   ksp = mptKSPSetup(A, ksptype) uses the specified type of the KSP. */
  /*  */
  /*   ksp = mptKSPSetup(A, ksptype, pctype) also sets the type of the KSP */
  /*     and the preconditioner. Note that pctype can be NULL. */
  /*  */
  /*   ksp = mptKSPSetup(A, ksptype, pctype, solpack) configures the KSP */
  /*     solver using the specified solver package. It is useful only when */
  /*     pctype is PCLU, PCILU, or PCICC. */
  /*  */
  /*  See Also: mptKSPSolve, mptKSPCleanup */
  /* 'mptKSPSetup:29' t_Amat = Amat; */
  /* 'mptKSPSetup:30' t_ksp = petscKSPCreate(petscObjectGetComm(t_Amat)); */
  /* Gets the MPI communicator for any PetscObject, regardless of the type.  */
  /*  */
  /*   [comm, errCode] = petscObjectGetComm(obj) */
  /*  */
  /*   obtains the MPI_Comm associated with the PetscObject. */
  /*  */
  /*   SEE ALSO: petscMatSetType, petscMatSetFromOptions */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode  PetscObjectGetComm(PetscObject obj,MPI_Comm *comm) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Sys/PetscObjectGetComm.html */
  /* 'petscObjectGetComm:16' errCode = int32(-1); */
  /* 'petscObjectGetComm:18' if ~isempty(coder.target) */
  /* 'petscObjectGetComm:19' t_obj = PetscObject(obj); */
  /* Map an opaque object into a PETSc PetscObject object */
  /*  */
  /*   obj = PetscObject() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   obj = PetscObject(arg) or obj = PetscObject(arg, false) converts arg */
  /*   into a PETSc Object object. */
  /*  */
  /*   obj = PetscObject(arg, true) wraps the arg into an opaque object. */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscObject:18' coder.inline('always'); */
  /* 'PetscObject:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscObject:25' if isstruct(arg) && ~isequal(arg.type, 'PetscObject') && ... */
  /* 'PetscObject:26'         ~isequal(arg.type, 'Mat') && ~isequal(arg.type, 'Vec') && ... */
  /* 'PetscObject:27'         ~isequal(arg.type, 'KSP') && ~isequal(arg.type, 'PC') */
  /* 'PetscObject:32' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscObject:33' if nargin==1 || ~opaque */
  /* 'PetscObject:34' obj = coder.opaque('PetscObject'); */
  /* 'PetscObject:35' obj = coder.ceval('(PetscObject)', arg); */
  t_obj = (PetscObject)(AMat);

  /* 'petscObjectGetComm:20' t_comm = coder.opaque('MPI_Comm'); */
  /* 'petscObjectGetComm:22' errCode = coder.ceval('PetscObjectGetComm', t_obj, coder.wref(t_comm)); */
  errCode = PetscObjectGetComm(t_obj, &t_comm);

  /* 'petscObjectGetComm:24' toplevel = nargout>2; */
  /* 'petscObjectGetComm:25' comm = MPI_Comm(t_comm, toplevel); */
  /* Map an opaque object into a PETSc MPI_Comm object */
  /*  */
  /*   comm = MPI_Comm() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   comm = MPI_Comm(arg) or comm = MPI_Comm(arg, false) converts arg */
  /*   into a PETSc Options object. */
  /*  */
  /*   comm = MPI_Comm(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'MPI_Comm:18' coder.inline('always'); */
  /* 'MPI_Comm:20' if nargin==0 && isempty(coder.target) */
  /* 'MPI_Comm:25' if isstruct(arg) && ~isequal(arg.type, 'MPI_Comm') */
  /* 'MPI_Comm:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'MPI_Comm:31' if nargin==1 || ~opaque */
  /* 'MPI_Comm:32' comm = arg; */
  /* 'petscObjectGetComm:27' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      /* 'petscObjectGetComm:28' m2c_error('petsc:RuntimeError', 'PetscObjectGetComm returned error code %d\n', errCode) */
      j_m2c_error(errCode);
    }
  }

  /* Creates a preconditioner context. */
  /*  */
  /*   [ksp, errCode] = petscKSPCreate */
  /*       creates a PETSc KSP using PETSC_COMM_WORLD */
  /*  */
  /*   [ksp, errCode] = petscKSPCreate(comm) */
  /*       comm: MPI Communicator */
  /*  */
  /*   SEE ALSO: petscKSPSetUp, petscKSPSolve, petscKSPDestroy */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode  KSPCreate(MPI_Comm comm,KSP *ksp) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPCreate.html */
  /* 'petscKSPCreate:18' errCode = int32(-1); */
  /* 'petscKSPCreate:20' if ~isempty(coder.target) */
  /* 'petscKSPCreate:21' t_ksp = coder.opaque('KSP'); */
  /* 'petscKSPCreate:23' if nargin==0 */
  /* 'petscKSPCreate:25' else */
  /* 'petscKSPCreate:26' t_comm = MPI_Comm(comm); */
  /* Map an opaque object into a PETSc MPI_Comm object */
  /*  */
  /*   comm = MPI_Comm() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   comm = MPI_Comm(arg) or comm = MPI_Comm(arg, false) converts arg */
  /*   into a PETSc Options object. */
  /*  */
  /*   comm = MPI_Comm(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'MPI_Comm:18' coder.inline('always'); */
  /* 'MPI_Comm:20' if nargin==0 && isempty(coder.target) */
  /* 'MPI_Comm:25' if isstruct(arg) && ~isequal(arg.type, 'MPI_Comm') */
  /* 'MPI_Comm:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'MPI_Comm:31' if nargin==1 || ~opaque */
  /* 'MPI_Comm:32' comm = arg; */
  /* 'petscKSPCreate:29' errCode = coder.ceval('KSPCreate', t_comm, coder.wref(t_ksp)); */
  errCode = KSPCreate(t_comm, &t_ksp);

  /* 'petscKSPCreate:31' toplevel = nargout>2; */
  /* 'petscKSPCreate:32' ksp = PetscKSP(t_ksp, toplevel); */
  /* Map an opaque object into a PETSc KSP object */
  /*  */
  /*   ksp = PetscKSP() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   ksp = PetscKSP(arg) or ksp = PetscKSP(arg, false) converts arg */
  /*   into a PETSc KSP object. */
  /*  */
  /*   ksp = PetscKSP(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscPC */
  /* 'PetscKSP:18' coder.inline('always'); */
  /* 'PetscKSP:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscKSP:25' if isstruct(arg) && ~isequal(arg.type, 'KSP') */
  /* 'PetscKSP:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscKSP:31' if nargin==1 || ~opaque */
  /* 'PetscKSP:32' ksp = arg; */
  /* 'petscKSPCreate:34' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      /* 'petscKSPCreate:35' m2c_error('petsc:RuntimeError', 'KSPCreate returned error code %d\n', errCode) */
      k_m2c_error(errCode);
    }
  }

  /* 'mptKSPSetup:32' time = 0; */
  /* 'mptKSPSetup:33' if nargout>1 */
  /* 'mptKSPSetup:33' t=m2c_wtime(); */
  /*  Return ellapsed time */
  /*    t = m2c_wtime */
  /* 'm2c_wtime:7' if isempty(coder.target) */
  /* 'm2c_wtime:10' else */
  /* 'm2c_wtime:11' coder.inline( 'always'); */
  /* 'm2c_wtime:13' t = 0; */
  /* 'm2c_wtime:13' t = coder.ceval( 'M2C_wtime'); */
  t = M2C_wtime();

  /*  Setup KSP */
  /* 'mptKSPSetup:36' petscKSPSetOperators(t_ksp, PetscMat(t_Amat)); */
  /* Map an opaque object into a PETSc Mat object */
  /*  */
  /*   mat = PetscMat() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   mat = PetscMat(arg) or mat = PetscMat(arg, false) converts arg */
  /*   into a PETSc Mat object. */
  /*  */
  /*   mat = PetscMat(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscMat:18' coder.inline('always'); */
  /* 'PetscMat:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscMat:25' if isstruct(arg) && ~isequal(arg.type, 'Mat') */
  /* 'PetscMat:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscMat:31' if nargin==1 || ~opaque */
  /* 'PetscMat:32' mat = arg; */
  /* Sets the matrix associated with the linear system and a (possibly) */
  /* different one associated with the preconditioner. */
  /*  */
  /*   errCode = petscKSPSetOperators(ksp, Amat) */
  /*  */
  /*   sets the matrix to be Amat and use the same matrix to construct the */
  /*   preconditioner. */
  /*      ksp - iterative context obtained from petscKSPCreate */
  /*      Amat	  - the right hand side vector */
  /*  */
  /*   errCode = petscKSPSetOperators(ksp, Amat, Pmat) */
  /*  */
  /*   uses the matrix Pmat to construct the preconditioner. */
  /*  */
  /*   SEE ALSO: petscKSPCreate, petscKSPSetUp, petscKSPSolve, petscKSPDestroy */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode  KSPSetOperators(KSP ksp,Mat Amat,Mat Pmat) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPSetOperators.html */
  /* 'petscKSPSetOperators:25' errCode = int32(-1); */
  /* 'petscKSPSetOperators:27' if ~isempty(coder.target) */
  /* 'petscKSPSetOperators:28' t_ksp = PetscKSP(ksp); */
  /* Map an opaque object into a PETSc KSP object */
  /*  */
  /*   ksp = PetscKSP() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   ksp = PetscKSP(arg) or ksp = PetscKSP(arg, false) converts arg */
  /*   into a PETSc KSP object. */
  /*  */
  /*   ksp = PetscKSP(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscPC */
  /* 'PetscKSP:18' coder.inline('always'); */
  /* 'PetscKSP:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscKSP:25' if isstruct(arg) && ~isequal(arg.type, 'KSP') */
  /* 'PetscKSP:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscKSP:31' if nargin==1 || ~opaque */
  /* 'PetscKSP:32' ksp = arg; */
  /* 'petscKSPSetOperators:29' t_Amat = PetscMat(Amat); */
  /* Map an opaque object into a PETSc Mat object */
  /*  */
  /*   mat = PetscMat() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   mat = PetscMat(arg) or mat = PetscMat(arg, false) converts arg */
  /*   into a PETSc Mat object. */
  /*  */
  /*   mat = PetscMat(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscMat:18' coder.inline('always'); */
  /* 'PetscMat:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscMat:25' if isstruct(arg) && ~isequal(arg.type, 'Mat') */
  /* 'PetscMat:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscMat:31' if nargin==1 || ~opaque */
  /* 'PetscMat:32' mat = arg; */
  /* 'petscKSPSetOperators:31' if nargin==2 */
  /* 'petscKSPSetOperators:32' t_Pmat = t_Amat; */
  /* 'petscKSPSetOperators:37' errCode = coder.ceval('KSPSetOperators', t_ksp, t_Amat, t_Pmat); */
  errCode = KSPSetOperators(t_ksp, AMat, AMat);

  /* 'petscKSPSetOperators:39' toplevel = nargout>1; */
  /* 'petscKSPSetOperators:40' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      /* 'petscKSPSetOperators:41' m2c_error('petsc:RuntimeError', 'KSPSetOperators returned error code %d\n', errCode) */
      l_m2c_error(errCode);
    }
  }

  /* 'mptKSPSetup:38' if nargin>1 */
  /* 'mptKSPSetup:39' if nargin>2 */
  /* 'mptKSPSetup:40' hasPC = ~ischar(pctype) || ~isempty(pctype); */
  b0 = !(pctype->size[1] == 0);

  /* 'mptKSPSetup:41' hasSolver = nargin>3 && (~ischar(solpack) || ~isempty(solpack)); */
  /* 'mptKSPSetup:43' if hasPC || hasSolver */
  emxInit_char_T(&pctype0, 2);
  if (b0) {
    /* 'mptKSPSetup:44' t_pc = petscKSPGetPC(t_ksp); */
    /* Returns a pointer to the preconditioner context set with petscKSPSetPC. */
    /*  */
    /*   [pc, errCode] = petscKSPGetPC(ksp, pc) gets the PC of the KSP */
    /*  */
    /*   SEE ALSO:  petscKSPSetPC */
    /*  */
    /*  PETSc C interface: */
    /*    PetscErrorCode  KSPGetPC(KSP ksp,PC *pc) */
    /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPGetPC.html */
    /* 'petscKSPGetPC:14' errCode = int32(-1); */
    /* 'petscKSPGetPC:16' if ~isempty(coder.target) */
    /* 'petscKSPGetPC:17' t_pc = coder.opaque('PC'); */
    /* 'petscKSPGetPC:18' errCode = coder.ceval('KSPGetPC', PetscKSP(ksp), coder.wref(t_pc)); */
    /* Map an opaque object into a PETSc KSP object */
    /*  */
    /*   ksp = PetscKSP() simply returns a definition of the */
    /*   m2c_opaque_type definition, suitable in the argument */
    /*   specification for codegen. */
    /*  */
    /*   ksp = PetscKSP(arg) or ksp = PetscKSP(arg, false) converts arg */
    /*   into a PETSc KSP object. */
    /*  */
    /*   ksp = PetscKSP(arg, true) wraps the arg into an opaque object.  */
    /*   This should be used if the object needs to be returned to */
    /*   MATLAB. Note that the value of opaque must be determined at */
    /*   compile time. */
    /*  */
    /*  See also PetscPC */
    /* 'PetscKSP:18' coder.inline('always'); */
    /* 'PetscKSP:20' if nargin==0 && isempty(coder.target) */
    /* 'PetscKSP:25' if isstruct(arg) && ~isequal(arg.type, 'KSP') */
    /* 'PetscKSP:30' if ~isstruct(arg) || isempty(coder.target) */
    /* 'PetscKSP:31' if nargin==1 || ~opaque */
    /* 'PetscKSP:32' ksp = arg; */
    errCode = KSPGetPC(t_ksp, &t_pc);

    /* 'petscKSPGetPC:20' toplevel = nargout>2; */
    /* 'petscKSPGetPC:21' pc = PetscPC(t_pc, toplevel); */
    /* Map an opaque object into a PETSc PC object */
    /*  */
    /*   pc = PetscPC() simply returns a definition of the */
    /*   m2c_opaque_type definition, suitable in the argument */
    /*   specification for codegen. */
    /*  */
    /*   pc = PetscPC(arg) or pc = PetscPC(arg, false) converts arg */
    /*   into a PETSc PC object. */
    /*  */
    /*   pc = PetscPC(arg, true) wraps the arg into an opaque object.  */
    /*   This should be used if the object needs to be returned to */
    /*   MATLAB. Note that the value of opaque must be determined at */
    /*   compile time. */
    /*  */
    /*  See also PetscKSP */
    /* 'PetscPC:18' coder.inline('always'); */
    /* 'PetscPC:20' if nargin==0 && isempty(coder.target) */
    /* 'PetscPC:25' if isstruct(arg) && ~isequal(arg.type, 'PC') */
    /* 'PetscPC:30' if ~isstruct(arg) || isempty(coder.target) */
    /* 'PetscPC:31' if nargin==1 || ~opaque */
    /* 'PetscPC:32' pc = arg; */
    /* 'petscKSPGetPC:23' if errCode && (toplevel || m2c_debug) */
    if (errCode != 0) {
      /* Flag indicating whether m2c_debug is on. */
      /* It is always true within MATLAB. In the generated C code, it is */
      /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
      /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
      /* 'm2c_debug:7' coder.inline('always'); */
      /* 'm2c_debug:9' if isempty(coder.target) */
      /* 'm2c_debug:11' else */
      /* 'm2c_debug:12' flag = int32(1); */
      /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
      b_flag = (M2C_DEBUG);
      if (b_flag != 0) {
        /* 'petscKSPGetPC:24' m2c_error('petsc:RuntimeError', 'KSPGetPC returned error code %d\n', errCode) */
        w_m2c_error(errCode);
      }
    }

    /* 'mptKSPSetup:46' if hasPC */
    /* 'mptKSPSetup:47' if ischar(pctype) && pctype(end)~=char(0) */
    if (pctype->data[pctype->size[1] - 1] != '\x00') {
      /*  null-terminate the string if not terminated properly */
      /* 'mptKSPSetup:49' pctype0 = [pctype char(0)]; */
      b_flag = pctype0->size[0] * pctype0->size[1];
      pctype0->size[0] = 1;
      pctype0->size[1] = pctype->size[1] + 1;
      emxEnsureCapacity((emxArray__common *)pctype0, b_flag, (int)sizeof(char));
      loop_ub = pctype->size[1];
      for (b_flag = 0; b_flag < loop_ub; b_flag++) {
        pctype0->data[pctype0->size[0] * b_flag] = pctype->data[pctype->size[0] *
          b_flag];
      }

      pctype0->data[pctype0->size[0] * pctype->size[1]] = '\x00';
    } else {
      /* 'mptKSPSetup:50' else */
      /* 'mptKSPSetup:51' pctype0 = pctype; */
      b_flag = pctype0->size[0] * pctype0->size[1];
      pctype0->size[0] = 1;
      pctype0->size[1] = pctype->size[1];
      emxEnsureCapacity((emxArray__common *)pctype0, b_flag, (int)sizeof(char));
      loop_ub = pctype->size[0] * pctype->size[1];
      for (b_flag = 0; b_flag < loop_ub; b_flag++) {
        pctype0->data[b_flag] = pctype->data[b_flag];
      }
    }

    /* 'mptKSPSetup:53' petscPCSetType(t_pc, pctype0); */
    /* Builds PC for a particular solver. */
    /*  */
    /*   errCode = petscPCSetType(pc, type) sets the type of the PC */
    /*  */
    /*   SEE ALSO:  PetscPCSetType, petscPCCreate */
    /*  */
    /*  PETSc C interface: */
    /*    PetscErrorCode  PCSetType(PC pc, PCType type) */
    /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/PC/PCSetType.html */
    /* 'petscPCSetType:14' errCode = int32(-1); */
    /* 'petscPCSetType:16' if ~isempty(coder.target) */
    /* 'petscPCSetType:17' if ischar(type) */
    /* 'petscPCSetType:18' errCode = coder.ceval('PCSetType', PetscPC(pc), coder.rref(type)); */
    /* Map an opaque object into a PETSc PC object */
    /*  */
    /*   pc = PetscPC() simply returns a definition of the */
    /*   m2c_opaque_type definition, suitable in the argument */
    /*   specification for codegen. */
    /*  */
    /*   pc = PetscPC(arg) or pc = PetscPC(arg, false) converts arg */
    /*   into a PETSc PC object. */
    /*  */
    /*   pc = PetscPC(arg, true) wraps the arg into an opaque object.  */
    /*   This should be used if the object needs to be returned to */
    /*   MATLAB. Note that the value of opaque must be determined at */
    /*   compile time. */
    /*  */
    /*  See also PetscKSP */
    /* 'PetscPC:18' coder.inline('always'); */
    /* 'PetscPC:20' if nargin==0 && isempty(coder.target) */
    /* 'PetscPC:25' if isstruct(arg) && ~isequal(arg.type, 'PC') */
    /* 'PetscPC:30' if ~isstruct(arg) || isempty(coder.target) */
    /* 'PetscPC:31' if nargin==1 || ~opaque */
    /* 'PetscPC:32' pc = arg; */
    errCode = PCSetType(t_pc, &pctype0->data[0]);

    /* 'petscPCSetType:23' toplevel = nargout>1; */
    /* 'petscPCSetType:24' if errCode && (toplevel || m2c_debug) */
    if (errCode != 0) {
      /* Flag indicating whether m2c_debug is on. */
      /* It is always true within MATLAB. In the generated C code, it is */
      /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
      /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
      /* 'm2c_debug:7' coder.inline('always'); */
      /* 'm2c_debug:9' if isempty(coder.target) */
      /* 'm2c_debug:11' else */
      /* 'm2c_debug:12' flag = int32(1); */
      /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
      b_flag = (M2C_DEBUG);
      if (b_flag != 0) {
        /* 'petscPCSetType:25' m2c_error('petsc:RuntimeError', 'PCSetType returned error code %d\n', errCode) */
        hb_m2c_error(errCode);
      }
    }

    /* 'mptKSPSetup:56' if hasSolver */
  }

  /* 'mptKSPSetup:68' if ischar(ksptype) && ~isempty(ksptype) && ksptype(end)~=0 */
  if ((!(solver->size[1] == 0)) && ((unsigned char)solver->data[solver->size[1]
       - 1] != 0)) {
    /*  null-terminate the string if not terminated properly */
    /* 'mptKSPSetup:70' ksptype0 = [ksptype char(0)]; */
    b_flag = pctype0->size[0] * pctype0->size[1];
    pctype0->size[0] = 1;
    pctype0->size[1] = solver->size[1] + 1;
    emxEnsureCapacity((emxArray__common *)pctype0, b_flag, (int)sizeof(char));
    loop_ub = solver->size[1];
    for (b_flag = 0; b_flag < loop_ub; b_flag++) {
      pctype0->data[pctype0->size[0] * b_flag] = solver->data[solver->size[0] *
        b_flag];
    }

    pctype0->data[pctype0->size[0] * solver->size[1]] = '\x00';
  } else {
    /* 'mptKSPSetup:71' else */
    /* 'mptKSPSetup:72' ksptype0 = ksptype; */
    b_flag = pctype0->size[0] * pctype0->size[1];
    pctype0->size[0] = 1;
    pctype0->size[1] = solver->size[1];
    emxEnsureCapacity((emxArray__common *)pctype0, b_flag, (int)sizeof(char));
    loop_ub = solver->size[0] * solver->size[1];
    for (b_flag = 0; b_flag < loop_ub; b_flag++) {
      pctype0->data[b_flag] = solver->data[b_flag];
    }
  }

  /* 'mptKSPSetup:74' if ischar(ksptype0) && ~isempty(ksptype0) || ~ischar(ksptype0) */
  if (!(pctype0->size[1] == 0)) {
    /*  Set KSP Types */
    /* 'mptKSPSetup:76' petscKSPSetType(t_ksp, ksptype0); */
    /* Builds KSP for a particular solver. */
    /*  */
    /*   errCode = petscKSPSetType(ksp, type) sets the type of the KSP */
    /*  */
    /*   SEE ALSO:  PetscPCSetType, petscKSPCreate */
    /*  */
    /*  PETSc C interface: */
    /*    PetscErrorCode  KSPSetType(KSP ksp, KSPType type) */
    /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPSetType.html */
    /* 'petscKSPSetType:14' errCode = int32(-1); */
    /* 'petscKSPSetType:16' if ~isempty(coder.target) */
    /* 'petscKSPSetType:17' if ischar(type) */
    /* 'petscKSPSetType:18' errCode = coder.ceval('KSPSetType', PetscKSP(ksp), coder.rref(type)); */
    /* Map an opaque object into a PETSc KSP object */
    /*  */
    /*   ksp = PetscKSP() simply returns a definition of the */
    /*   m2c_opaque_type definition, suitable in the argument */
    /*   specification for codegen. */
    /*  */
    /*   ksp = PetscKSP(arg) or ksp = PetscKSP(arg, false) converts arg */
    /*   into a PETSc KSP object. */
    /*  */
    /*   ksp = PetscKSP(arg, true) wraps the arg into an opaque object.  */
    /*   This should be used if the object needs to be returned to */
    /*   MATLAB. Note that the value of opaque must be determined at */
    /*   compile time. */
    /*  */
    /*  See also PetscPC */
    /* 'PetscKSP:18' coder.inline('always'); */
    /* 'PetscKSP:20' if nargin==0 && isempty(coder.target) */
    /* 'PetscKSP:25' if isstruct(arg) && ~isequal(arg.type, 'KSP') */
    /* 'PetscKSP:30' if ~isstruct(arg) || isempty(coder.target) */
    /* 'PetscKSP:31' if nargin==1 || ~opaque */
    /* 'PetscKSP:32' ksp = arg; */
    errCode = KSPSetType(t_ksp, &pctype0->data[0]);

    /* 'petscKSPSetType:23' toplevel = nargout>1; */
    /* 'petscKSPSetType:24' if errCode && (toplevel || m2c_debug) */
    if (errCode != 0) {
      /* Flag indicating whether m2c_debug is on. */
      /* It is always true within MATLAB. In the generated C code, it is */
      /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
      /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
      /* 'm2c_debug:7' coder.inline('always'); */
      /* 'm2c_debug:9' if isempty(coder.target) */
      /* 'm2c_debug:11' else */
      /* 'm2c_debug:12' flag = int32(1); */
      /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
      b_flag = (M2C_DEBUG);
      if (b_flag != 0) {
        /* 'petscKSPSetType:25' m2c_error('petsc:RuntimeError', 'KSPSetType returned error code %d\n', errCode) */
        gb_m2c_error(errCode);
      }
    }
  }

  emxFree_char_T(&pctype0);

  /* 'mptKSPSetup:80' petscKSPSetFromOptions(t_ksp); */
  /* Sets KSP options from the options database. This routine must be called */
  /* before KSPSetUp() if the user is to be allowed to set the Krylov type. */
  /*  */
  /*   errCode = petscKSPSetFromOptions(ksp) */
  /*  */
  /*   SEE ALSO: petscKSPCreate, petscKSPSetOperators, petscKSPSolve, petscKSPDestroy */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode KSPSetFromOptions(KSP ksp) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPSetFromOptions.html */
  /* 'petscKSPSetFromOptions:15' errCode = int32(-1); */
  /* 'petscKSPSetFromOptions:17' if ~isempty(coder.target) */
  /* 'petscKSPSetFromOptions:18' t_ksp = PetscKSP(ksp); */
  /* Map an opaque object into a PETSc KSP object */
  /*  */
  /*   ksp = PetscKSP() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   ksp = PetscKSP(arg) or ksp = PetscKSP(arg, false) converts arg */
  /*   into a PETSc KSP object. */
  /*  */
  /*   ksp = PetscKSP(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscPC */
  /* 'PetscKSP:18' coder.inline('always'); */
  /* 'PetscKSP:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscKSP:25' if isstruct(arg) && ~isequal(arg.type, 'KSP') */
  /* 'PetscKSP:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscKSP:31' if nargin==1 || ~opaque */
  /* 'PetscKSP:32' ksp = arg; */
  /* 'petscKSPSetFromOptions:20' errCode = coder.ceval('KSPSetFromOptions', t_ksp); */
  errCode = KSPSetFromOptions(t_ksp);

  /* 'petscKSPSetFromOptions:22' toplevel = nargout>1; */
  /* 'petscKSPSetFromOptions:23' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      /* 'petscKSPSetFromOptions:24' m2c_error('petsc:RuntimeError', 'KSPSetFromOptions returned error code %d\n', errCode) */
      m_m2c_error(errCode);
    }
  }

  /* 'mptKSPSetup:82' petscKSPSetUp(t_ksp); */
  /* Sets up the internal data structures for the later use of an iterative solver. */
  /*  */
  /*   errCode = petscKSPSetUp(ksp) */
  /*  */
  /*   SEE ALSO: petscKSPCreate, petscKSPSetOperators, petscKSPSolve, petscKSPDestroy */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode KSPSetUp(KSP ksp) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPSetUp.html */
  /* 'petscKSPSetUp:14' errCode = int32(-1); */
  /* 'petscKSPSetUp:16' if ~isempty(coder.target) */
  /* 'petscKSPSetUp:17' t_ksp = PetscKSP(ksp); */
  /* Map an opaque object into a PETSc KSP object */
  /*  */
  /*   ksp = PetscKSP() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   ksp = PetscKSP(arg) or ksp = PetscKSP(arg, false) converts arg */
  /*   into a PETSc KSP object. */
  /*  */
  /*   ksp = PetscKSP(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscPC */
  /* 'PetscKSP:18' coder.inline('always'); */
  /* 'PetscKSP:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscKSP:25' if isstruct(arg) && ~isequal(arg.type, 'KSP') */
  /* 'PetscKSP:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscKSP:31' if nargin==1 || ~opaque */
  /* 'PetscKSP:32' ksp = arg; */
  /* 'petscKSPSetUp:19' errCode = coder.ceval('KSPSetUp', t_ksp); */
  errCode = KSPSetUp(t_ksp);

  /* 'petscKSPSetUp:21' toplevel = nargout>1; */
  /* 'petscKSPSetUp:22' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      /* 'petscKSPSetUp:23' m2c_error('petsc:RuntimeError', 'KSPSetUp returned error code %d\n', errCode) */
      n_m2c_error(errCode);
    }
  }

  /* 'mptKSPSetup:83' if nargout>1 */
  /* 'mptKSPSetup:83' time=m2c_wtime()-t; */
  /*  Return ellapsed time */
  /*    t = m2c_wtime */
  /* 'm2c_wtime:7' if isempty(coder.target) */
  /* 'm2c_wtime:10' else */
  /* 'm2c_wtime:11' coder.inline( 'always'); */
  /* 'm2c_wtime:13' t = 0; */
  /* 'm2c_wtime:13' t = coder.ceval( 'M2C_wtime'); */
  b_t = M2C_wtime();

  /* 'mptKSPSetup:85' toplevel = nargout>2; */
  /* 'mptKSPSetup:86' ksp = PetscKSP(t_ksp, toplevel); */
  /* Map an opaque object into a PETSc KSP object */
  /*  */
  /*   ksp = PetscKSP() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   ksp = PetscKSP(arg) or ksp = PetscKSP(arg, false) converts arg */
  /*   into a PETSc KSP object. */
  /*  */
  /*   ksp = PetscKSP(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscPC */
  /* 'PetscKSP:18' coder.inline('always'); */
  /* 'PetscKSP:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscKSP:25' if isstruct(arg) && ~isequal(arg.type, 'KSP') */
  /* 'PetscKSP:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscKSP:31' if nargin==1 || ~opaque */
  /* 'PetscKSP:32' ksp = arg; */
  /* 'mptSolve:73' [flag,relres,iter, time_solve] = mptKSPSolve(ksp, b, x, double(rtol), int32(maxit), x0); */
  mptKSPSolve(t_ksp, bVec, t_vec_out, rtol, maxiter, NULL, &b_flag, &b_relres,
              &loop_ub, &time_solve);

  /* 'mptSolve:75' if nargout>3 */
  /* 'mptSolve:76' times = [time_setup; time_solve]; */
  /* 'mptSolve:79' mptKSPCleanup(ksp); */
  /*  Cleans up the KSP. */
  /*  */
  /*    ksp = mptKSPCleanup(ksp) destropys the given KSP object. */
  /*    It should be called whtn the KSP object is no longer needed, and  */
  /*    no calls should be made to this KSP after this. */
  /*  */
  /*  See Also: mptKSPSetup, mptKSPSolve */
  /*  Destroy the KSP and solution vector */
  /* 'mptKSPCleanup:13' t_ksp = petscKSPDestroy(ksp); */
  /* Destroys KSP context. */
  /*  */
  /*   [ksp, errCode] = petscKSPDestroy(ksp) */
  /*  */
  /*   SEE ALSO: petscKSPCreate, petscKSPSetUp, petscKSPSolve */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode KSPDestroy(KSP *A) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPDestroy.html */
  /* 'petscKSPDestroy:14' errCode = int32(-1); */
  /* 'petscKSPDestroy:16' if ~isempty(coder.target) */
  /* 'petscKSPDestroy:17' t_ksp = PetscKSP(ksp); */
  /* Map an opaque object into a PETSc KSP object */
  /*  */
  /*   ksp = PetscKSP() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   ksp = PetscKSP(arg) or ksp = PetscKSP(arg, false) converts arg */
  /*   into a PETSc KSP object. */
  /*  */
  /*   ksp = PetscKSP(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscPC */
  /* 'PetscKSP:18' coder.inline('always'); */
  /* 'PetscKSP:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscKSP:25' if isstruct(arg) && ~isequal(arg.type, 'KSP') */
  /* 'PetscKSP:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscKSP:31' if nargin==1 || ~opaque */
  /* 'PetscKSP:32' ksp = arg; */
  /* 'petscKSPDestroy:19' errCode = coder.ceval('KSPDestroy', coder.ref(t_ksp)); */
  errCode = KSPDestroy(&t_ksp);

  /* 'petscKSPDestroy:21' toplevel = nargout>2; */
  /* 'petscKSPDestroy:22' ksp_out = PetscKSP(t_ksp, toplevel); */
  /* Map an opaque object into a PETSc KSP object */
  /*  */
  /*   ksp = PetscKSP() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   ksp = PetscKSP(arg) or ksp = PetscKSP(arg, false) converts arg */
  /*   into a PETSc KSP object. */
  /*  */
  /*   ksp = PetscKSP(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscPC */
  /* 'PetscKSP:18' coder.inline('always'); */
  /* 'PetscKSP:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscKSP:25' if isstruct(arg) && ~isequal(arg.type, 'KSP') */
  /* 'PetscKSP:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscKSP:31' if nargin==1 || ~opaque */
  /* 'PetscKSP:32' ksp = arg; */
  /* 'petscKSPDestroy:24' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      /* 'petscKSPDestroy:25' m2c_error('petsc:RuntimeError', 'KSPDestroy returned error code %d\n', errCode) */
      ab_m2c_error(errCode);
    }
  }

  /* 'mptKSPCleanup:15' toplevel = nargout>1; */
  /* 'mptKSPCleanup:16' ksp = PetscKSP(t_ksp, toplevel); */
  /* 'mptSolveCRS:125' petscMatDestroy(AMat); */
  /* Frees space taken by a matrix. */
  /*  */
  /*   [mat, errCode] = petscMatDestroy(mat) */
  /*  */
  /*   SEE ALSO: petscVecCreateSeq, petscVecCreateMPI, petscAssembleMat, petscVecDestroy */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode MatDestroy(Mat *A) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatDestroy.html */
  /* 'petscMatDestroy:14' errCode = int32(-1); */
  /* 'petscMatDestroy:16' if ~isempty(coder.target) */
  /* 'petscMatDestroy:17' t_mat = PetscMat(mat); */
  /* Map an opaque object into a PETSc Mat object */
  /*  */
  /*   mat = PetscMat() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   mat = PetscMat(arg) or mat = PetscMat(arg, false) converts arg */
  /*   into a PETSc Mat object. */
  /*  */
  /*   mat = PetscMat(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscMat:18' coder.inline('always'); */
  /* 'PetscMat:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscMat:25' if isstruct(arg) && ~isequal(arg.type, 'Mat') */
  /* 'PetscMat:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscMat:31' if nargin==1 || ~opaque */
  /* 'PetscMat:32' mat = arg; */
  t_mat = AMat;

  /* 'petscMatDestroy:19' errCode = coder.ceval('MatDestroy', coder.ref(t_mat)); */
  errCode = MatDestroy(&t_mat);

  /* 'petscMatDestroy:21' toplevel = nargout>2; */
  /* 'petscMatDestroy:22' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      /* 'petscMatDestroy:23' m2c_error('petsc:RuntimeError', 'MatDestroy returned error code %d\n', errCode) */
      bb_m2c_error(errCode);
    }
  }

  /* 'petscMatDestroy:26' mat = PetscMat(t_mat, toplevel); */
  /* 'mptSolveCRS:126' petscVecDestroy(bVec); */
  /* Frees space taken by a vector. */
  /*  */
  /*   [vec, errCode] = petscVecDestroy(vec) */
  /*  */
  /*   SEE ALSO: petscVecCreateSeq, petscVecCreateMPI, petscAssembleVec, */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode VecDestroy(Vec *A) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecDestroy.html */
  /* 'petscVecDestroy:14' errCode = int32(-1); */
  /* 'petscVecDestroy:16' if ~isempty(coder.target) */
  /* 'petscVecDestroy:17' t_vec = PetscVec(vec); */
  /* Map an opaque object into a PETSc Vec object */
  /*  */
  /*   vec = PetscVec() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   vec = PetscVec(arg) or vec = PetscVec(arg, false) converts arg */
  /*   into a PETSc Vec object. */
  /*  */
  /*   vec = PetscVec(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscVec:18' coder.inline('always'); */
  /* 'PetscVec:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscVec:25' if isstruct(arg) && ~isequal(arg.type, 'Vec') */
  /* 'PetscVec:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscVec:31' if nargin==1 || ~opaque */
  /* 'PetscVec:32' vec = arg; */
  t_vec = bVec;

  /* 'petscVecDestroy:19' errCode = coder.ceval('VecDestroy', coder.ref(t_vec)); */
  errCode = VecDestroy(&t_vec);

  /* 'petscVecDestroy:21' toplevel = nargout>2; */
  /* 'petscVecDestroy:22' vec = PetscVec(t_vec, toplevel); */
  /* 'petscVecDestroy:24' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      /* 'petscVecDestroy:25' m2c_error('petsc:RuntimeError', 'VecDestroy returned error code %d\n', errCode) */
      cb_m2c_error(errCode);
    }
  }

  /* 'mptSolveCRS:128' x = mptVecToArray(xVec); */
  mptVecToArray(t_vec_out, x);

  /* 'mptSolveCRS:129' petscVecDestroy(xVec); */
  /* Frees space taken by a vector. */
  /*  */
  /*   [vec, errCode] = petscVecDestroy(vec) */
  /*  */
  /*   SEE ALSO: petscVecCreateSeq, petscVecCreateMPI, petscAssembleVec, */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode VecDestroy(Vec *A) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecDestroy.html */
  /* 'petscVecDestroy:14' errCode = int32(-1); */
  /* 'petscVecDestroy:16' if ~isempty(coder.target) */
  /* 'petscVecDestroy:17' t_vec = PetscVec(vec); */
  /* Map an opaque object into a PETSc Vec object */
  /*  */
  /*   vec = PetscVec() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   vec = PetscVec(arg) or vec = PetscVec(arg, false) converts arg */
  /*   into a PETSc Vec object. */
  /*  */
  /*   vec = PetscVec(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscVec:18' coder.inline('always'); */
  /* 'PetscVec:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscVec:25' if isstruct(arg) && ~isequal(arg.type, 'Vec') */
  /* 'PetscVec:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscVec:31' if nargin==1 || ~opaque */
  /* 'PetscVec:32' vec = arg; */
  t_vec = t_vec_out;

  /* 'petscVecDestroy:19' errCode = coder.ceval('VecDestroy', coder.ref(t_vec)); */
  errCode = VecDestroy(&t_vec);

  /* 'petscVecDestroy:21' toplevel = nargout>2; */
  /* 'petscVecDestroy:22' vec = PetscVec(t_vec, toplevel); */
  /* 'petscVecDestroy:24' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      /* 'petscVecDestroy:25' m2c_error('petsc:RuntimeError', 'VecDestroy returned error code %d\n', errCode) */
      cb_m2c_error(errCode);
    }
  }

  *flag = b_flag;
  *relres = b_relres;
  *iter = loop_ub;
  times[0] = b_t - t;
  times[1] = time_solve;
}

/*
 * function [x,flag,relres,iter,times] = mptSolveCRS_9args(Arows, Acols, Avals, b, solver, rtol, maxiter, pctype, solpack)
 */
void mptSolveCRS_9args(const emxArray_int32_T *Arows, const emxArray_int32_T
  *Acols, const emxArray_real_T *Avals, const emxArray_real_T *b, const
  emxArray_char_T *solver, double rtol, int maxiter, const emxArray_char_T
  *pctype, const emxArray_char_T *solpack, emxArray_real_T *x, int *flag, double
  *relres, int *iter, double times[2])
{
  Mat AMat;
  Vec bVec;
  Vec t_vec_out;
  int errCode;
  int b_flag;
  KSP ksp;
  double time_setup;
  double b_relres;
  int b_iter;
  double time_solve;
  KSP t_ksp;
  int c_flag;
  Mat t_mat;
  Vec t_vec;

  /* 'mptSolveCRS_9args:2' [x,flag,relres,iter,times] = mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxiter, pctype, solpack); */
  /*  Solves a linear system using any PETSc solver for matrix in CRS format. */
  /*  */
  /*  Syntax: */
  /*     mptSolveCRS(Arows, Acols, Avals, b) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, solpack) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, solpack, x0) */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, solpack, x0, opts) */
  /*  */
  /*     [x, flag, reslres, iter, times] = mptSolveCRS(Arows, Acols, Avals, b, ...) */
  /*  */
  /*     A is a sparse matrix in CRS format. b, x and resvec are all regular */
  /*     vectors. Solver is a value of PETSC_KSP*. pctype is a value of */
  /*     PETSC_PC*, and solpack is a value of PETSC_MATSOLVER*. */
  /*  */
  /*     For rtol, maxit, use 0 to use default values. */
  /*     For solver, pctype, solpack and opts, use empty string ('') to use default. */
  /*     For x0, use zeros(0, 1) to disable initial guess. */
  /*  */
  /*     When times is given, it returns a 2-vector contaning the times spent */
  /*     in setup and in solve separately. */
  /*  */
  /*  Description: */
  /*     mptSolveCRS(Arows, Acols, Avals, b) solves the linear system without */
  /*     preconditioners, using the default tolerances or those that have been */
  /*     set previously in the option databases. */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver) specifies to use a */
  /*     specific solver, such as PETSC_KSPGMRES, PETSC_KSPBCGS, etc. */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol) uses the given number */
  /*         of solvers and the relative tolerarance. */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit) solves with */
  /*         the given relative tolerances and maximum iteration count. */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype) */
  /*     uses the specified preconditioner (those give by PETSC_PC*). */
  /*     The preconditioner can be controlled by the PETSc option database. */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, */
  /*     solpack) specifies the solver packages for factorization (those give */
  /*     by PETSC_MATSOLVER*). */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, */
  /*     solpack, x0) usee x0 for the initial guess. x0 can be the same as x. */
  /*  */
  /*     mptSolveCRS(Arows, Acols, Avals, b, solver, rtol, maxit, pctype, */
  /*     solpack, x0, opts) can pass additional command-line options in a */
  /*     string to PETSc. */
  /*  */
  /*  SEE ALSO: mptSolve, mptMatCreateAIJFromCRS, mptVecCreateFromArray, */
  /*            mptVecToArray, mptKSPSetup, mptKSPSolve, mptKSPCleanup */
  /* 'mptSolveCRS:81' if nargin==0 */
  /* 'mptSolveCRS:86' if isempty(coder.target) && ~exist(['petscVecDuplicate.' mexext], 'file') && ... */
  /* 'mptSolveCRS:87'         exist('run_mptSolveCRS_exe', 'file') */
  /* 'mptSolveCRS:96' Arows = varargin{1}; */
  /* 'mptSolveCRS:97' Acols = varargin{2}; */
  /* 'mptSolveCRS:98' Avals = varargin{3}; */
  /* 'mptSolveCRS:99' b = varargin{4}; */
  /*  Setup KSP */
  /* 'mptSolveCRS:102' if nargin<5 */
  /* 'mptSolveCRS:102' else */
  /* 'mptSolveCRS:102' solver = varargin{5}; */
  /*  Use default */
  /* 'mptSolveCRS:103' if nargin<6 */
  /* 'mptSolveCRS:103' else */
  /* 'mptSolveCRS:103' rtol = varargin{6}; */
  /* 'mptSolveCRS:104' if nargin<7 */
  /* 'mptSolveCRS:104' else */
  /* 'mptSolveCRS:104' maxit = varargin{7}; */
  /* 'mptSolveCRS:105' if nargin<8 */
  /* 'mptSolveCRS:105' else */
  /* 'mptSolveCRS:105' pctype = varargin{8}; */
  /* 'mptSolveCRS:106' if nargin<9 */
  /* 'mptSolveCRS:106' else */
  /* 'mptSolveCRS:106' solpack = varargin{9}; */
  /* 'mptSolveCRS:108' AMat = mptMatCreateAIJFromCRS(Arows, Acols, Avals); */
  AMat = mptMatCreateAIJFromCRS(Arows, Acols, Avals);

  /* 'mptSolveCRS:109' bVec = mptVecCreateFromArray(b); */
  bVec = mptVecCreateFromArray(b);

  /* 'mptSolveCRS:111' if nargin<10 || isempty(varargin{10}) */
  /* 'mptSolveCRS:112' x0Vec = PETSC_NULL_VEC; */
  /*  Obtain PETSC constant NULL of type Vec */
  /* 'PETSC_NULL_VEC:4' coder.inline('always'); */
  /* 'PETSC_NULL_VEC:6' obj = petscGetObject('PETSC_NULL_VEC'); */
  /* petscGetObject Obtain an opaque object in PETSC */
  /*  */
  /*     obj = petscGetObject(name) */
  /*  */
  /* The supported names include: */
  /*  */
  /*  MPI_Comm: PETSC_COMM_SELF, PETSC_COMM_WORLD, MPI_COMM_SELF, MPI_COMM_WORLD */
  /*  */
  /*  Other: */
  /*      PETSC_IGNORE, PETSC_NULL_OPTION, PETSC_NULL_MAT, PETSC_NULL_VEC, */
  /*      PETSC_NULL_INT, PETSC_NULL_REAL */
  /* 'petscGetObject:16' if isempty(coder.target) */
  /* 'petscGetObject:20' switch name */
  /* 'petscGetObject:35' case 'PETSC_NULL_VEC' */
  /* 'petscGetObject:36' [obj, toplevel] = get_obj('Vec', 'NULL', nargout>1); */
  /* 'mptSolveCRS:113' xVec = petscVecDuplicate(bVec); */
  /* Creates a new vector of the same type as an existing vector. */
  /*  */
  /*   [vec_out, errCode] = petscVecDuplicate(vec_in) creates a new vector, but */
  /*      it does not copy the entries of the input vector. The user is */
  /*      responsible freeing the memory by calling petscVecDestroy. */
  /*  */
  /*   SEE ALSO: petscVecCopy, petscVecDestroy, petscVecCreate */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode  VecDuplicate(Vec vec_in, Vec *vec_out) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecDuplicate.html */
  /* 'petscVecDuplicate:16' errCode = int32(-1); */
  /* 'petscVecDuplicate:18' if ~isempty(coder.target) */
  /* 'petscVecDuplicate:19' t_vec_out = coder.opaque('Vec'); */
  /* 'petscVecDuplicate:21' errCode = coder.ceval('VecDuplicate', PetscVec(vec_in), coder.wref(t_vec_out)); */
  /* Map an opaque object into a PETSc Vec object */
  /*  */
  /*   vec = PetscVec() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   vec = PetscVec(arg) or vec = PetscVec(arg, false) converts arg */
  /*   into a PETSc Vec object. */
  /*  */
  /*   vec = PetscVec(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscVec:18' coder.inline('always'); */
  /* 'PetscVec:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscVec:25' if isstruct(arg) && ~isequal(arg.type, 'Vec') */
  /* 'PetscVec:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscVec:31' if nargin==1 || ~opaque */
  /* 'PetscVec:32' vec = arg; */
  errCode = VecDuplicate(bVec, &t_vec_out);

  /* 'petscVecDuplicate:23' toplevel = nargout>2; */
  /* 'petscVecDuplicate:24' vec_out = PetscVec(t_vec_out, toplevel); */
  /* Map an opaque object into a PETSc Vec object */
  /*  */
  /*   vec = PetscVec() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   vec = PetscVec(arg) or vec = PetscVec(arg, false) converts arg */
  /*   into a PETSc Vec object. */
  /*  */
  /*   vec = PetscVec(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscVec:18' coder.inline('always'); */
  /* 'PetscVec:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscVec:25' if isstruct(arg) && ~isequal(arg.type, 'Vec') */
  /* 'PetscVec:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscVec:31' if nargin==1 || ~opaque */
  /* 'PetscVec:32' vec = arg; */
  /* 'petscVecDuplicate:26' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    b_flag = (M2C_DEBUG);
    if (b_flag != 0) {
      /* 'petscVecDuplicate:27' m2c_error('petsc:RuntimeError', 'VecDuplicate returned error code %d\n', errCode) */
      i_m2c_error(errCode);
    }
  }

  /* 'mptSolveCRS:120' if nargin<11 */
  /* 'mptSolveCRS:120' opts = ''; */
  /* 'mptSolveCRS:122' [flag,relres,iter, times] = mptSolve(AMat, bVec, xVec, solver, ... */
  /* 'mptSolveCRS:123'     double(rtol), int32(maxit), pctype, solpack, x0Vec, opts); */
  /*  Solves a linear system using a given solver in PETSc. */
  /*  */
  /*  Syntax: */
  /*     mptSolve(A_hdl, b_hdl) */
  /*     mptSolve(A_hdl, b_hdl, x_hdl) */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver) */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol) */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit) */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype) */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype, solpack) */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype, solpack, x0_hdl) */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype, solpack, x0_hdl, opts) */
  /*  */
  /*     [flag, reslres, iter] = mptSolve(A_hdl, b_hdl, x_hdl, ...) */
  /*  */
  /*     The handles are PetscMat or PetscVec objects. */
  /*  */
  /*  Description: */
  /*     mptSolve(A_hdl, b_hdl) solves the linear system without preconditioners, */
  /*     using the default tolerances or those that have been set previously in */
  /*     the option databases. A_hdl is a PetscMat object, and b_hdl is a */
  /*     PetscVec object. The solution is stored into b. The QMRCGS can be */
  /*     controlled using the options database for KSPQMRCGS. */
  /*  */
  /*     mptSolve(A_hdl, b_hdl, x_hdl) solves the linear system and saves the */
  /*     result into x. */
  /*  */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver) uses the specified solver, where */
  /*     solver is one of PETSC_KSP*. */
  /*  */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol) uses the given relative tolerarance. */
  /*  */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit) solves with the given */
  /*      relative tolerances and maximum iteration count. */
  /*  */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype) uses the */
  /*     specified preconditioner (PETSC_PC*). The preconditioner can be */
  /*     controlled by the PETSc option database. */
  /*  */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype, solpack) */
  /*     specifies the solver packages for factorization (PETSC_MATSOLVER*). */
  /*  */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype, solpack, */
  /*     x0_handle) usee x0 for the initial guess. x0 can be the same as x or */
  /*     be PETSC_NULL_VEC. */
  /*  */
  /*     mptSolve(A_hdl, b_hdl, x_hdl, solver, rtol, maxit, pctype, solpack, */
  /*     x0_handle, opts) can pass command-line options in a string to PETSc. */
  /*  */
  /*  SEE ALSO: mptSolveCRS, mptMatCreateAIJFromCRS, mptVecCreateFromArray, */
  /*            mptOptionsInsert, mptKSPSetup, mptKSPSolve, mptKSPCleanup */
  /* This function is codegen compatbile, but no need to a top-level function */
  /*  Setup KSP */
  /* 'mptSolve:59' if nargin<3 */
  /* 'mptSolve:60' if nargin<4 */
  /* 'mptSolve:61' if nargin<5 */
  /* 'mptSolve:62' if nargin<6 */
  /* 'mptSolve:63' if nargin<7 */
  /* 'mptSolve:64' if nargin<8 */
  /* 'mptSolve:65' if nargin<9 */
  /* 'mptSolve:67' if nargin==10 && ~isempty(opts) */
  /* 'mptSolve:71' [ksp, time_setup] = mptKSPSetup(A, solver, pctype, solpack); */
  mptKSPSetup(AMat, solver, pctype, solpack, &ksp, &time_setup);

  /* 'mptSolve:73' [flag,relres,iter, time_solve] = mptKSPSolve(ksp, b, x, double(rtol), int32(maxit), x0); */
  mptKSPSolve(ksp, bVec, t_vec_out, rtol, maxiter, NULL, &b_flag, &b_relres,
              &b_iter, &time_solve);

  /* 'mptSolve:75' if nargout>3 */
  /* 'mptSolve:76' times = [time_setup; time_solve]; */
  /* 'mptSolve:79' mptKSPCleanup(ksp); */
  /*  Cleans up the KSP. */
  /*  */
  /*    ksp = mptKSPCleanup(ksp) destropys the given KSP object. */
  /*    It should be called whtn the KSP object is no longer needed, and  */
  /*    no calls should be made to this KSP after this. */
  /*  */
  /*  See Also: mptKSPSetup, mptKSPSolve */
  /*  Destroy the KSP and solution vector */
  /* 'mptKSPCleanup:13' t_ksp = petscKSPDestroy(ksp); */
  /* Destroys KSP context. */
  /*  */
  /*   [ksp, errCode] = petscKSPDestroy(ksp) */
  /*  */
  /*   SEE ALSO: petscKSPCreate, petscKSPSetUp, petscKSPSolve */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode KSPDestroy(KSP *A) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/KSP/KSPDestroy.html */
  /* 'petscKSPDestroy:14' errCode = int32(-1); */
  /* 'petscKSPDestroy:16' if ~isempty(coder.target) */
  /* 'petscKSPDestroy:17' t_ksp = PetscKSP(ksp); */
  /* Map an opaque object into a PETSc KSP object */
  /*  */
  /*   ksp = PetscKSP() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   ksp = PetscKSP(arg) or ksp = PetscKSP(arg, false) converts arg */
  /*   into a PETSc KSP object. */
  /*  */
  /*   ksp = PetscKSP(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscPC */
  /* 'PetscKSP:18' coder.inline('always'); */
  /* 'PetscKSP:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscKSP:25' if isstruct(arg) && ~isequal(arg.type, 'KSP') */
  /* 'PetscKSP:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscKSP:31' if nargin==1 || ~opaque */
  /* 'PetscKSP:32' ksp = arg; */
  t_ksp = ksp;

  /* 'petscKSPDestroy:19' errCode = coder.ceval('KSPDestroy', coder.ref(t_ksp)); */
  errCode = KSPDestroy(&t_ksp);

  /* 'petscKSPDestroy:21' toplevel = nargout>2; */
  /* 'petscKSPDestroy:22' ksp_out = PetscKSP(t_ksp, toplevel); */
  /* Map an opaque object into a PETSc KSP object */
  /*  */
  /*   ksp = PetscKSP() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   ksp = PetscKSP(arg) or ksp = PetscKSP(arg, false) converts arg */
  /*   into a PETSc KSP object. */
  /*  */
  /*   ksp = PetscKSP(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscPC */
  /* 'PetscKSP:18' coder.inline('always'); */
  /* 'PetscKSP:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscKSP:25' if isstruct(arg) && ~isequal(arg.type, 'KSP') */
  /* 'PetscKSP:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscKSP:31' if nargin==1 || ~opaque */
  /* 'PetscKSP:32' ksp = arg; */
  /* 'petscKSPDestroy:24' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      /* 'petscKSPDestroy:25' m2c_error('petsc:RuntimeError', 'KSPDestroy returned error code %d\n', errCode) */
      ab_m2c_error(errCode);
    }
  }

  /* 'mptKSPCleanup:15' toplevel = nargout>1; */
  /* 'mptKSPCleanup:16' ksp = PetscKSP(t_ksp, toplevel); */
  /* 'mptSolveCRS:125' petscMatDestroy(AMat); */
  /* Frees space taken by a matrix. */
  /*  */
  /*   [mat, errCode] = petscMatDestroy(mat) */
  /*  */
  /*   SEE ALSO: petscVecCreateSeq, petscVecCreateMPI, petscAssembleMat, petscVecDestroy */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode MatDestroy(Mat *A) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Mat/MatDestroy.html */
  /* 'petscMatDestroy:14' errCode = int32(-1); */
  /* 'petscMatDestroy:16' if ~isempty(coder.target) */
  /* 'petscMatDestroy:17' t_mat = PetscMat(mat); */
  /* Map an opaque object into a PETSc Mat object */
  /*  */
  /*   mat = PetscMat() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   mat = PetscMat(arg) or mat = PetscMat(arg, false) converts arg */
  /*   into a PETSc Mat object. */
  /*  */
  /*   mat = PetscMat(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscMat:18' coder.inline('always'); */
  /* 'PetscMat:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscMat:25' if isstruct(arg) && ~isequal(arg.type, 'Mat') */
  /* 'PetscMat:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscMat:31' if nargin==1 || ~opaque */
  /* 'PetscMat:32' mat = arg; */
  t_mat = AMat;

  /* 'petscMatDestroy:19' errCode = coder.ceval('MatDestroy', coder.ref(t_mat)); */
  errCode = MatDestroy(&t_mat);

  /* 'petscMatDestroy:21' toplevel = nargout>2; */
  /* 'petscMatDestroy:22' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      /* 'petscMatDestroy:23' m2c_error('petsc:RuntimeError', 'MatDestroy returned error code %d\n', errCode) */
      bb_m2c_error(errCode);
    }
  }

  /* 'petscMatDestroy:26' mat = PetscMat(t_mat, toplevel); */
  /* 'mptSolveCRS:126' petscVecDestroy(bVec); */
  /* Frees space taken by a vector. */
  /*  */
  /*   [vec, errCode] = petscVecDestroy(vec) */
  /*  */
  /*   SEE ALSO: petscVecCreateSeq, petscVecCreateMPI, petscAssembleVec, */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode VecDestroy(Vec *A) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecDestroy.html */
  /* 'petscVecDestroy:14' errCode = int32(-1); */
  /* 'petscVecDestroy:16' if ~isempty(coder.target) */
  /* 'petscVecDestroy:17' t_vec = PetscVec(vec); */
  /* Map an opaque object into a PETSc Vec object */
  /*  */
  /*   vec = PetscVec() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   vec = PetscVec(arg) or vec = PetscVec(arg, false) converts arg */
  /*   into a PETSc Vec object. */
  /*  */
  /*   vec = PetscVec(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscVec:18' coder.inline('always'); */
  /* 'PetscVec:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscVec:25' if isstruct(arg) && ~isequal(arg.type, 'Vec') */
  /* 'PetscVec:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscVec:31' if nargin==1 || ~opaque */
  /* 'PetscVec:32' vec = arg; */
  t_vec = bVec;

  /* 'petscVecDestroy:19' errCode = coder.ceval('VecDestroy', coder.ref(t_vec)); */
  errCode = VecDestroy(&t_vec);

  /* 'petscVecDestroy:21' toplevel = nargout>2; */
  /* 'petscVecDestroy:22' vec = PetscVec(t_vec, toplevel); */
  /* 'petscVecDestroy:24' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      /* 'petscVecDestroy:25' m2c_error('petsc:RuntimeError', 'VecDestroy returned error code %d\n', errCode) */
      cb_m2c_error(errCode);
    }
  }

  /* 'mptSolveCRS:128' x = mptVecToArray(xVec); */
  mptVecToArray(t_vec_out, x);

  /* 'mptSolveCRS:129' petscVecDestroy(xVec); */
  /* Frees space taken by a vector. */
  /*  */
  /*   [vec, errCode] = petscVecDestroy(vec) */
  /*  */
  /*   SEE ALSO: petscVecCreateSeq, petscVecCreateMPI, petscAssembleVec, */
  /*  */
  /*  PETSc C interface: */
  /*    PetscErrorCode VecDestroy(Vec *A) */
  /*  http://www.mcs.anl.gov/petsc/petsc-current/docs/manualpages/Vec/VecDestroy.html */
  /* 'petscVecDestroy:14' errCode = int32(-1); */
  /* 'petscVecDestroy:16' if ~isempty(coder.target) */
  /* 'petscVecDestroy:17' t_vec = PetscVec(vec); */
  /* Map an opaque object into a PETSc Vec object */
  /*  */
  /*   vec = PetscVec() simply returns a definition of the */
  /*   m2c_opaque_type definition, suitable in the argument */
  /*   specification for codegen. */
  /*  */
  /*   vec = PetscVec(arg) or vec = PetscVec(arg, false) converts arg */
  /*   into a PETSc Vec object. */
  /*  */
  /*   vec = PetscVec(arg, true) wraps the arg into an opaque object.  */
  /*   This should be used if the object needs to be returned to */
  /*   MATLAB. Note that the value of opaque must be determined at */
  /*   compile time. */
  /*  */
  /*  See also PetscMat */
  /* 'PetscVec:18' coder.inline('always'); */
  /* 'PetscVec:20' if nargin==0 && isempty(coder.target) */
  /* 'PetscVec:25' if isstruct(arg) && ~isequal(arg.type, 'Vec') */
  /* 'PetscVec:30' if ~isstruct(arg) || isempty(coder.target) */
  /* 'PetscVec:31' if nargin==1 || ~opaque */
  /* 'PetscVec:32' vec = arg; */
  t_vec = t_vec_out;

  /* 'petscVecDestroy:19' errCode = coder.ceval('VecDestroy', coder.ref(t_vec)); */
  errCode = VecDestroy(&t_vec);

  /* 'petscVecDestroy:21' toplevel = nargout>2; */
  /* 'petscVecDestroy:22' vec = PetscVec(t_vec, toplevel); */
  /* 'petscVecDestroy:24' if errCode && (toplevel || m2c_debug) */
  if (errCode != 0) {
    /* Flag indicating whether m2c_debug is on. */
    /* It is always true within MATLAB. In the generated C code, it is */
    /* turned off by the -DNDEBUG compiler option. It can also be turned on  */
    /* or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively. */
    /* 'm2c_debug:7' coder.inline('always'); */
    /* 'm2c_debug:9' if isempty(coder.target) */
    /* 'm2c_debug:11' else */
    /* 'm2c_debug:12' flag = int32(1); */
    /* 'm2c_debug:13' flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG')); */
    c_flag = (M2C_DEBUG);
    if (c_flag != 0) {
      /* 'petscVecDestroy:25' m2c_error('petsc:RuntimeError', 'VecDestroy returned error code %d\n', errCode) */
      cb_m2c_error(errCode);
    }
  }

  *flag = b_flag;
  *relres = b_relres;
  *iter = b_iter;
  times[0] = time_setup;
  times[1] = time_solve;
}

void mptSolveCRS_initialize(void)
{
}

void mptSolveCRS_terminate(void)
{
  /* (no terminate code required) */
}

/* End of code generation (mptSolveCRS.c) */
