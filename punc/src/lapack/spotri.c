/* ./src_f77/spotri.f -- translated by f2c (version 20030320).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include <punc/vf2c.h>

/* Subroutine */ int spotri_(char *uplo, integer *n, real *a, integer *lda, 
	integer *info, ftnlen uplo_len)
{
    /* System generated locals */
    integer a_dim1, a_offset, i__1;

    /* Local variables */
    extern logical lsame_(char *, char *, ftnlen, ftnlen);
    extern /* Subroutine */ int xerbla_(char *, integer *, ftnlen), slauum_(
	    char *, integer *, real *, integer *, integer *, ftnlen), strtri_(
	    char *, char *, integer *, real *, integer *, integer *, ftnlen, 
	    ftnlen);


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

/*  SPOTRI computes the inverse of a real symmetric positive definite */
/*  matrix A using the Cholesky factorization A = U**T*U or A = L*L**T */
/*  computed by SPOTRF. */

/*  Arguments */
/*  ========= */

/*  UPLO    (input) CHARACTER*1 */
/*          = 'U':  Upper triangle of A is stored; */
/*          = 'L':  Lower triangle of A is stored. */

/*  N       (input) INTEGER */
/*          The order of the matrix A.  N >= 0. */

/*  A       (input/output) REAL array, dimension (LDA,N) */
/*          On entry, the triangular factor U or L from the Cholesky */
/*          factorization A = U**T*U or A = L*L**T, as computed by */
/*          SPOTRF. */
/*          On exit, the upper or lower triangle of the (symmetric) */
/*          inverse of A, overwriting the input factor U or L. */

/*  LDA     (input) INTEGER */
/*          The leading dimension of the array A.  LDA >= max(1,N). */

/*  INFO    (output) INTEGER */
/*          = 0:  successful exit */
/*          < 0:  if INFO = -i, the i-th argument had an illegal value */
/*          > 0:  if INFO = i, the (i,i) element of the factor U or L is */
/*                zero, and the inverse could not be computed. */

/*  ===================================================================== */

/*     .. External Functions .. */
/*     .. */
/*     .. External Subroutines .. */
/*     .. */
/*     .. Intrinsic Functions .. */
/*     .. */
/*     .. Executable Statements .. */

/*     Test the input parameters. */

    /* Parameter adjustments */
    a_dim1 = *lda;
    a_offset = 1 + a_dim1;
    a -= a_offset;

    /* Function Body */
    *info = 0;
    if (! lsame_(uplo, "U", (ftnlen)1, (ftnlen)1) && ! lsame_(uplo, "L", (
	    ftnlen)1, (ftnlen)1)) {
	*info = -1;
    } else if (*n < 0) {
	*info = -2;
    } else if (*lda < max(1,*n)) {
	*info = -4;
    }
    if (*info != 0) {
	i__1 = -(*info);
	xerbla_("SPOTRI", &i__1, (ftnlen)6);
	return 0;
    }

/*     Quick return if possible */

    if (*n == 0) {
	return 0;
    }

/*     Invert the triangular Cholesky factor U or L. */

    strtri_(uplo, "Non-unit", n, &a[a_offset], lda, info, (ftnlen)1, (ftnlen)
	    8);
    if (*info > 0) {
	return 0;
    }

/*     Form inv(U)*inv(U)' or inv(L)'*inv(L). */

    slauum_(uplo, n, &a[a_offset], lda, info, (ftnlen)1);

    return 0;

/*     End of SPOTRI */

} /* spotri_ */

