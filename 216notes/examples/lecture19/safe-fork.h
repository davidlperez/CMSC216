#if !defined(SAFE_FORK_H)
#define SAFE_FORK_H

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* If you want to make any CHANGES to any of the lecture process control
 * examples and run them, first add #include "safe-fork.h" at the top, then
 * CHANGE them to call safe_fork() INSTEAD of fork(), to avoid the
 * possibilities of bad fork() bombs.  (Of course compile the modified
 * example together with safe-fork.o.)
 *
 * But DO NOT TRY TO CREATE AN INTENTIONAL FORK BOMB EVEN USING safe_fork()-
 * IT WILL STILL AFFECT THE MACHINE AND MAY REQUIRE INTERVENTION BY THE
 * SYSTEM ADMINISTRATORS TO FIX.
 */

int safe_fork(void);

#endif
