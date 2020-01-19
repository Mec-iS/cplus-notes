
* _Ready_ : After its creation, a process enters the ready state and is loaded
 into main memory. The process now is ready to run and is waiting for CPU time
 to be executed. Processes that are ready for execution by the CPU are stored
 in a queue managed by the OS.
* _Running_ : The operating system has selected the process for execution and the
 instructions within the process are executed on one or more of the available CPU cores.
* _Blocked_ : A process that is blocked is one that is waiting for an event (such
 as a system resource becoming available) or the completion of an I/O operation.
* _Terminated_ : When a process completes its execution or when it is being
 explicitly killed, it changes to the "terminated" state. The underlying program
 is no longer executing, but the process remains in the process table as a
 "zombie process". When it is finally removed from the process table, its
 lifetime ends.
* _Ready suspended_ : A process that was initially in ready state but has been
 swapped out of main memory and placed onto external storage is said to be in
 suspend ready state. The process will transition back to ready state whenever
 it is moved to main memory again.
* _Blocked suspended_ : A process that is blocked may also be swapped out of
 main memory. It may be swapped back in again under the same conditions as a
 "ready suspended" process. In such a case, the process will move to the blocked
 state, and may still be waiting for a resource to become available.
