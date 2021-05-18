/**************************************************************************
 * Rhythm constants (French notation of course.)
 *
 * R. Beaubois
 *
 * Comments :
 * 	Here it's ok to define everything from multiplications and divisions
 *	since after pre-processor's work all operations are gonna be carried
 *	out at compilation to generate the table of rhythm as constants.
 *	Long story short, no operation it's gonna be carried out while running
 *	program, everything is going to be initialized at compilation and stored
 *	in memory.
 *************************************************************************/

#ifndef __RHYTHM_H__
 
// To ease calculation of duration I assumed that 1 noire = 1 second so reference tempo has to be 60 BPM
#define NOIRE           60            
#define CROCHE          (NOIRE/2)
#define NOIRE_P         (CROCHE*3)
#define DBL_CROCHE      (CROCHE/2)
#define CROCHE_P        (3*DBL_CROCHE)
#define BLANCHE         (2*NOIRE)
#define BLANCHE_P       (3*NOIRE)
#define RONDE           (2*BLANCHE)
#define RONDE_P         (3*BLANCHE)

#endif
