* _New_ : A thread is in this state once it has been created. Until it is
 actually running, it will not take any CPU resources.
* _Runnable_ : In this state, a thread might actually be running or it might
 be ready to run at any instant of time. It is the responsibility of the thread
 scheduler to assign CPU time to the thread.
* _Blocked_ : A thread might be in this state, when it is waiting for I/O
 operations to complete. When blocked, a thread cannot continue its execution
 any further until it is moved to the runnable state again. It will not consume
 any CPU time in this state. The thread scheduler is responsible for reactivating
 the thread.
