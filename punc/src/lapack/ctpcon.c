/* ./src_f77/ctpcon.f -- translated by f2c (version 20030320).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include <punc/vf2c.h>

/* Table of constant values */

static integer c__1 = 1;

/* Subroutine */ int ctpcon_(char *norm, char *uplo, char *diag, integer *n, 
	complex *ap, real *rcond, complex *work, real *rwork, integer *info, 
	ftnlen norm_len, ftnlen uplo_len, ftnlen diag_len)
{
    /* System generated locals */
    integer i__1;
    real r__1, r__2;

    /* Builtin functions */
    double r_imag(complex *);

    /* Local variables */
    static integer ix, kase, kase1;
    static real scale;
    extern logical lsame_(char *, char *, ftnlen, ftnlen);
    static real anorm;
    static logical upper;
    static real xnorm;
    extern /* Subroutine */ int clacon_(integer *, complex *, complex *, real 
	    *, integer *);
    extern integer icamax_(integer *, complex *, integer *);
    extern doublereal slamch_(char *, ftnlen);
    extern /* Subroutine */ int xerbla_(char *, integer *, ftnlen);
    extern doublereal clantp_(char *, char *, char *, integer *, complex *, 
	    real *, ftnlen, ftnlen, ftnlen);
    extern /* Subroutine */ int clatps_(char *, char *, char *, char *, 
	    integer *, complex *, complex *, real *, real *, integer *, 
	    ftnlen, ftnlen, ftnlen, ftnlen);
    static real ainvnm;
    extern /* Subroutine */ int csrscl_(integer *, real *, complex *, integer 
	    *);
    static logical onenrm;
    static char normin[1];
    static real smlnum;
    static logical nounit;


/*  -- LAPACK routine (version 3.0) -- */
/*     Univ. of Tennessee, Univ. of California Berkeley, NAG Ltd., */
/*     Courant Institute, Argonne National Lab, and Rice University */
/*     March 31, 1993 */

/*     .. Scalar Arguments .. */
/*     .. */
/*     .. Array Arguments .. */
/*     .. */

/*  Purpose */
/*  ======= */

/*  CTPCON estimates the reciprocal of the condition number of a packed */
/*  triangular matrix A, in either the 1-norm or the infinity-norm. */

/*  The norm of A is computed and an estimate is obtained for */
/*  norm(inv(A)), then the reciprocal of the condition number is */
/*  computed as */
/*     RCOND = 1 / ( norm(A) * norm(inv(A)) ). */

/*  Arguments */
/*  ========= */

/*  NORM    (input) CHARACTER*1 */
/*          Specifies whether the 1-norm condition number or the */
/*          infinity-norm condition number is required: */
/*          = '1' or 'O':  1-norm; */
/*          = 'I':         Infinity-norm. */

/*  UPLO    (input) CHARACTER*1 */
/*          = 'U':  A is upper triangular; */
/*          = 'L':  A is lower triangular. */

/*  DIAG    (input) CHARACTER*1 */
/*          = 'N':  A is non-unit triangular; */
/*          = 'U':  A is unit triangular. */

/*  N       (input) INTEGER */
/*          The order of the matrix A.  N >= 0. */

/*  AP      (input) COMPLEX array, dimension (N*(N+1)/2) */
/*          The upper or lower triangular matrix A, packed columnwise in */
/*          a linear array.  The j-th column of A is stored in the array */
/*          AP as follows: */
/*          if UPLO = 'U', AP(i + (j-1)*j/2) = A(i,j) for 1<=i<=j; */
/*          if UPLO = 'L', AP(i + (j-1)*(2n-j)/2) = A(i,j) for j<=i<=n. */
/*          If DIAG = 'U', the diagonal elements of A are not referenced */
/*          and are assumed to be 1. */

/*  RCOND   (output) REAL */
/*          The reciprocal of the condition number of the matrix A, */
/*          computed as RCOND = 1/(norm(A) * norm(inv(A))). */

/*  WORK    (workspace) COMPLEX array, dimension (2*N) */

/*  RWORK   (workspace) REAL array, dimension (N) */

/*  INFO    (output) INTEGER */
/*          = 0:  successful exit */
/*          < 0:  if INFO = -i, the i-th argument had an illegal value */

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
/*     .. Statement Functions .. */
/*     .. */
/*     .. Statement Function definitions .. */
/*     .. */
/*     .. Executable Statements .. */

/*     Test the input parameters. */

    /* Parameter adjustments */
    --rwork;
    --work;
    --ap;

    /* Function Body */
    *info = 0;
    upper = lsame_(uplo, "U", (ftnlen)1, (ftnlen)1);
    onenrm = *(unsigned char *)norm == '1' || lsame_(norm, "O", (ftnlen)1, (
	    ftnlen)1);
    nounit = lsame_(diag, "N", (ftnlen)1, (ftnlen)1);

    if (! onenrm && ! lsame_(norm, "I", (ftnlen)1, (ftnlen)1)) {
	*info = -1;
    } else if (! upper && ! lsame_(uplo, "L", (ftnlen)1, (ftnlen)1)) {
	*info = -2;
    } else if (! nounit && ! lsame_(diag, "U", (ftnlen)1, (ftnlen)1)) {
	*info = -3;
    } else if (*n < 0) {
	*info = -4;
    }
    if (*info != 0) {
	i__1 = -(*info);
	xerbla_("CTPCON", &i__1, (ftnlen)6);
	return 0;
    }

/*     Quick return if possible */

    if (*n == 0) {
	*rcond = 1.f;
	return 0;
    }

    *rcond = 0.f;
    smlnum = slamch_("Safe minimum", (ftnlen)12) * (real) max(1,*n);

/*     Compute the norm of the triangular matrix A. */

    anorm = clantp_(norm, uplo, diag, n, &ap[1], &rwork[1], (ftnlen)1, (
	    ftnlen)1, (ftnlen)1);

/*     Continue only if ANORM > 0. */

    if (anorm > 0.f) {

/*        Estimate the norm of the inverse of A. */

	ainvnm = 0.f;
	*(unsigned char *)normin = 'N';
	if (onenrm) {
	    kase1 = 1;
	} else {
	    kase1 = 2;
	}
	kase = 0;
L10:
	clacon_(n, &work[*n + 1], &work[1], &ainvnm, &kase);
	if (kase != 0) {
	    if (kase == kase1) {

/*              Multiply by inv(A). */

		clatps_(uplo, "No transpose", diag, normin, n, &ap[1], &work[
			1], &scale, &rwork[1], info, (ftnlen)1, (ftnlen)12, (
			ftnlen)1, (ftnlen)1);
	    } else {

/*              Multiply by inv(A'). */

		clatps_(uplo, "Conjugate transpose", diag, normin, n, &ap[1], 
			&work[1], &scale, &rwork[1], info, (ftnlen)1, (ftnlen)
			19, (ftnlen)1, (ftnlen)1);
	    }
	    *(unsigned char *)normin = 'Y';

/*           Multiply by 1/SCALE if doing so will not cause overflow. */

	    if (scale != 1.f) {
		ix = icamax_(n, &work[1], &c__1);
		i__1 = ix;
		xnorm = (r__1 = work[i__1].r, dabs(r__1)) + (r__2 = r_imag(&
			work[ix]), dabs(r__2));
		if (scale < xnorm * smlnum || scale == 0.f) {
		    goto L20;
		}
		csrscl_(n, &scale, &work[1], &c__1);
	    }
	    goto L10;
	}

/*        Compute the estimate of the reciprocal condition number. */

	if (ainvnm != 0.f) {
	    *rcond = 1.f / anorm / ainvnm;
	}
    }

L20:
    return 0;

/*     End of CTPCON */

} /* ctpcon_ */

