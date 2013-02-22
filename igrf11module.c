#include <python2.7/Python.h>
#include "f2c.h"

int MAIN__() { return 0; }

static PyObject *igrf11syn(PyObject *self, PyObject *args) {
	double date, colat, elong, alt;
	integer isv, itype;
	double fx, fy, fz, ff;
	if (!PyArg_ParseTuple(args, "ididdd", &isv, &date, &itype, &alt, &colat, &elong)) {
		return NULL;
	}
	igrf11syn_(&isv, &date, &itype, &alt, &colat, &elong, &fx, &fy, &fz, &ff);
	return Py_BuildValue("dddd", fx, fy, fz, ff);
}





static PyMethodDef IgrfMethods[] = {
  { "igrf11syn", igrf11syn, METH_VARARGS,
"igrf.igrf11syn(isv, date, itype, alt, colat, elong)\n\n\
This is a synthesis routine for the 11th generation IGRF as agreed in December \n\
2009 by IAGA Working Group V-MOD. It is valid 1900.0 to 2015.0 inclusive.\n\
   INPUT\n\
     isv   = 0 if main-field values are required\n\
     isv   = 1 if secular variation values are required\n\
     date  = year A.D. Must be greater than or equal to 1900.0 and\n\
             less than or equal to 2020.0. Warning message is given\n\
             for dates greater than 2015.0. Must be double precision.\n\
     itype = 1 if geodetic (spheroid)\n\
     itype = 2 if geocentric (sphere)\n\
     alt   = height in km above sea level if itype = 1\n\
           = distance from centre of Earth in km if itype = 2 (>3485 km)\n\
     colat = colatitude (0-180)\n\
     elong = east-longitude (0-360)\n\
     alt, colat and elong must be double precision.\n\
   OUTPUT\n\
     x     = north component (nT) if isv = 0, nT/year if isv = 1\n\
     y     = east component (nT) if isv = 0, nT/year if isv = 1\n\
     z     = vertical component (nT) if isv = 0, nT/year if isv = 1\n\
     f     = total intensity (nT) if isv = 0, rubbish if isv = 1" },
  { NULL, NULL, 0, NULL }
};

PyMODINIT_FUNC initigrf(void) {
  (void) Py_InitModule("igrf", IgrfMethods);
}
