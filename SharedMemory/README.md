# Shared Memory Implementation - A few definitions 

##Introduction: 
A process creates a shared memory segment using shmget()|. The original owner of a shared memory segment can assign ownership to another user with shmctl(). It can also revoke this assignment. Other processes with proper permission can perform various control functions on the shared memory segment using shmctl(). Once created, a shared segment can be attached to a process address space using shmat(). It can be detached using shmdt() (see shmop()). The attaching process must have the appropriate permissions for shmat(). Once attached, the process can read or write to the segment, as allowed by the permission requested in the attach operation. A shared segment can be attached multiple times by the same process. A shared memory segment is described by a control structure with a unique ID that points to an area of physical memory. The identifier of the segment is called the shmid. The structure definition for the shared memory segment control structures and prototypews can be found in <sys/shm.h>.
##Basics:
* shmget() 
  * It is used to obtain access to a shared memory segment. 
  * Protoype:  int shmget(key_t key, size_t size, int shmflg);

* shmctl()
  * It is used to alter permissions and other characteristics of a shared memory segment. 
  * int shmctl(int shmid, int cmd, struct_ds \*buf )

* shmat()
  * It is used to attach shared memory segments.
  * void \*shmat(int shmid, const void \*shmaddr, int shmflg)


* shmdt()
  * It is used to detach shared memory segments.
  * int shmdt(const void \*shmaddr)


## Advance Stuff :
* Semaphore needs to be implemented, which controls the write and read permission for processes on the created shared memory object.
* c++11 has a different ways of implementing it.
