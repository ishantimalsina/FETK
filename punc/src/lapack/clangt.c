/* ./src_f77/clangt.f -- translated by f2c (version 20030320).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include <punc/vf2c.h>

/* Table of constant values */

static integer c__1 = 1;

doublereal clangt_(char *norm, integer *n, complex *dl, complex *d__, complex 
	*du, ftnlen norm_len)
{
    /* System generated locals */
    integer i__1;
    real ret_val, r__1, r__2;

    /* Builtin functions */
    double c_abs(complex *), sqrt(doublereal);

    /* Local variables */
    static integer i__;
    static real sum, scale;
    extern logical lsame_(char *, char *, ftnlen, ftnlen);
    static real anorm;
    extern /* Subroutine */ int classq_(integer *, complex *, integer *, real 
	    *, real *);


/*  -- LAPACK auxiliary routine (version 3.0) -- */
/*     Univ. of Tennessee, Univ. of California Berkeley, NAG Ltd., */
/*     Courant Institute, Argonne National Lab, and Rice University */
/*     February 29, 1992 */

/*     .. Scalar Arguments .. */
/*     .. */
/*     .. Array Arguments .. */
/*     .. */

/*  Purpose */
/*  ======= */

/*  CLANGT  returns the value of the one norm,  or the Frobenius norm, or */
/*  the  infinity norm,  or the  element of  largest absolute value  of a */
/*  complex tridiagonal matrix A. */

/*  Description */
/*  =========== */

/*  CLANGT returns the value */

/*     CLANGT = ( max(abs(A(i,j))), NORM = 'M' or 'm' */
/*              ( */
/*              ( norm1(A),         NORM = '1', 'O' or 'o' */
/*              ( */
/*              ( normI(A),         NORM = 'I' or 'i' */
/*              ( */
/*              ( normF(A),         NORM = 'F', 'f', 'E' or 'e' */

/*  where  norm1  denotes the  one norm of a matrix (maximum column sum), */
/*  normI  denotes the  infinity norm  of a matrix  (maximum row sum) and */
/*  normF  denotes the  Frobenius norm of a matrix (square root of sum of */
/*  squares).  Note that  max(abs(A(i,j)))  is not a  matrix norm. */

/*  Arguments */
/*  ========= */

/*  NORM    (input) CHARACTER*1 */
/*          Specifies the value to be returned in CLANGT as described */
/*          above. */

/*  N       (input) INTEGER */
/*          The order of the matrix A.  N >= 0.  When N = 0, CLANGT is */
/*          set to zero. */

/*  DL      (input) COMPLEX array, dimension (N-1) */
/*          The (n-1) sub-diagonal elements of A. */

/*  D       (input) COMPLEX array, dimension (N) */
/*          The diagonal elements of A. */

/*  DU      (input) COMPLEX array, dimension (N-1) */
/*          The (n-1) super-diagonal elements of A. */

/*  ===================================================================== */

/*     .. Parameters .. */
/*     .. */
/*     .. Local Scalars .. */
/*     .. */
/*     .. External Functions .. */
/*     .. */
/*     .. External Subroutines .. */
/*     .. */
/*     .. Intrinsic Functions .. */
/*     .. */
/*     .. Executable Statements .. */

    /* Parameter adjustments */
    --du;
    --d__;
    --dl;

    /* Function Body */
    if (*n <= 0) {
	anorm = 0.f;
    } else if (lsame_(norm, "M", (ftnlen)1, (ftnlen)1)) {

/*        Find max(abs(A(i,j))). */

	anorm = c_abs(&d__[*n]);
	i__1 = *n - 1;
	for (i__ = 1; i__ <= i__1; ++i__) {
/* Computing MAX */
	    r__1 = anorm, r__2 = c_abs(&dl[i__]);
	    anorm = dmax(r__1,r__2);
/* Computing MAX */
	    r__1 = anorm, r__2 = c_abs(&d__[i__]);
	    anorm = dmax(r__1,r__2);
/* Computing MAX */
	    r__1 = anorm, r__2 = c_abs(&du[i__]);
	    anorm = dmax(r__1,r__2);
/* L10: */
	}
    } else if (lsame_(norm, "O", (ftnlen)1, (ftnlen)1) || *(unsigned char *)
	    norm == '1') {

/*        Find norm1(A). */

	if (*n == 1) {
	    anorm = c_abs(&d__[1]);
	} else {
/* Computing MAX */
	    r__1 = c_abs(&d__[1]) + c_abs(&dl[1]), r__2 = c_abs(&d__[*n]) + 
		    c_abs(&du[*n - 1]);
	    anorm = dmax(r__1,r__2);
	    i__1 = *n - 1;
	    for (i__ = 2; i__ <= i__1; ++i__) {
/* Computing MAX */
		r__1 = anorm, r__2 = c_abs(&d__[i__]) + c_abs(&dl[i__]) + 
			c_abs(&du[i__ - 1]);
		anorm = dmax(r__1,r__2);
/* L20: */
	    }
	}
    } else if (lsame_(norm, "I", (ftnlen)1, (ftnlen)1)) {

/*        Find normI(A). */

	if (*n == 1) {
	    anorm = c_abs(&d__[1]);
	} else {
/* Computing MAX */
	    r__1 = c_abs(&d__[1]) + c_abs(&du[1]), r__2 = c_abs(&d__[*n]) + 
		    c_abs(&dl[*n - 1]);
	    anorm = dmax(r__1,r__2);
	    i__1 = *n - 1;
	    for (i__ = 2; i__ <= i__1; ++i__) {
/* Computing MAX */
		r__1 = anorm, r__2 = c_abs(&d__[i__]) + c_abs(&du[i__]) + 
			c_abs(&dl[i__ - 1]);
		anorm = dmax(r__1,r__2);
/* L30: */
	    }
	}
    } else if (lsame_(norm, "F", (ftnlen)1, (ftnlen)1) || lsame_(norm, "E", (
	    ftnlen)1, (ftnlen)1)) {

/*        Find normF(A). */

	scale = 0.f;
	sum = 1.f;
	classq_(n, &d__[1], &c__1, &scale, &sum);
	if (*n > 1) {
	    i__1 = *n - 1;
	    classq_(&i__1, &dl[1], &c__1, &scale, &sum);
	    i__1 = *n - 1;
	    classq_(&i__1, &du[1], &c__1, &scale, &sum);
	}
	anorm = scale * sqrt(sum);
    }

    ret_val = anorm;
    return ret_val;

/*     End of CLANGT */

} /* clangt_ */

