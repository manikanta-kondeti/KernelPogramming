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

## Whats happening in this code:
* My aim is to create a shared memory object which takes a output file and gives access to other processes. 
* In this work I've created a 'route' file which has some numbers. Assume it as node1, node2 and cost from n1,n2 to keep it simple.
* In shm_msgserver.c I've created a shared memory object which takes all the information in route file and keep it in structs. 
* In shm_msgclient.c we can access the shared memory object and get the results. 
* There are few bugs in this code(bear with me). I just tried to test the concept. Hope it helped you understood something.  

## How to test it: 
* git clone https://github.com/manikanta-kondeti/KernelPogramming 
* cd SharedMemory 
* chmod +x run.sh
* ./run.sh 
* Open two tabs:
  * Tab1:  ./shm_msgserver.c 
  * Tab2:  ./shm_msgclient.c 

## Advanced Stuff :
* Semaphore needs to be implemented, which controls the write and read permission for processes on the created shared memory object.
* c++11 has a different ways of implementing it, need to figure it out.
