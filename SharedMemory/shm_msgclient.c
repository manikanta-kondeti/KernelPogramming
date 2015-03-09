/*
 *  shm_msgclient.c
 *  
 *  Illustrates memory mapping and persistency, with POSIX objects.
 *  This process reads and displays a message left it in "memory segment
 *  image", a file been mapped from a memory segment.
 *
 *
 *  Created by Mij <mij@bitchx.it> on 27/08/05.
 *  Original source file available at http://mij.oltrelinux.com/devel/unixprg/
 *
 */

#include <stdio.h>
/* exit() etc */
#include <unistd.h>
/* shm_* stuff, and mmap() */
#include <sys/mman.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
/* for random() stuff */
#include <stdlib.h>
#include <time.h>


/* Posix IPC object name [system dependant] - see
http://mij.oltrelinux.com/devel/unixprg/index2.html#ipc__posix_objects */
#define SHMOBJ_PATH         "./tem17"      
/* maximum length of the content of the message */
#define MAX_MSG_LENGTH      50
/* how many types of messages we recognize (fantasy) */
#define TYPES               8

/* message structure for messages in the shared segment */
struct msg_s {
	int node1;
	int node2;
	int cost;
};


int main(int argc, char *argv[]) {
    int shmfd;
    int shared_seg_size = (5 * sizeof(struct msg_s));   /* want shared segment capable of storing 1 message */
    struct msg_s *shared_msg1;      /* the shared segment, and head of the messages list */
    struct msg_s *shared_msg2;      /* the shared segment, and head of the messages list */
    struct msg_s *shared_msg3;      /* the shared segment, and head of the messages list */
    struct msg_s *shared_msg4;      /* the shared segment, and head of the messages list */
    struct msg_s *shared_msg5;      /* the shared segment, and head of the messages list */
    

    /* creating the shared memory object    --  shm_open()  */
    shmfd = shm_open(SHMOBJ_PATH, O_RDWR, S_IRWXU | S_IRWXG);
    if (shmfd < 0) {
        perror("In shm_open()");
        exit(1);
    }
    printf("Created shared memory object %s\n", SHMOBJ_PATH);
    
    /* requesting the shared segment    --  mmap() */    
    shared_msg1 = (struct msg_s *)mmap(NULL, shared_seg_size/5, PROT_READ | PROT_WRITE, MAP_SHARED, shmfd, 0);
    shared_msg2 = (struct msg_s *)mmap(NULL, shared_seg_size/5, PROT_READ | PROT_WRITE, MAP_SHARED, shmfd, 0);
    shared_msg3 = (struct msg_s *)mmap(NULL, shared_seg_size/5, PROT_READ | PROT_WRITE, MAP_SHARED, shmfd, 0);
    shared_msg4 = (struct msg_s *)mmap(NULL, shared_seg_size/5, PROT_READ | PROT_WRITE, MAP_SHARED, shmfd, 0);
    shared_msg5 = (struct msg_s *)mmap(NULL, shared_seg_size/5, PROT_READ | PROT_WRITE, MAP_SHARED, shmfd, 0);
    if (shared_msg1 == NULL) {
        perror("In mmap()");
        exit(1);
    }
    printf("Shared memory segment allocated correctly (%d bytes).\n", shared_seg_size);


    printf("Message type is: node1 =  %d, node2 = %d  cost = %d\n", shared_msg1->node1, shared_msg1->node2, shared_msg1->cost);
    printf("Message type is: node1 =  %d, node2 = %d  cost = %d\n", shared_msg2->node1, shared_msg2->node2, shared_msg2->cost);
    printf("Message type is: node1 =  %d, node2 = %d  cost = %d\n", shared_msg3->node1, shared_msg3->node2, shared_msg3->cost);
    printf("Message type is: node1 =  %d, node2 = %d  cost = %d\n", shared_msg4->node1, shared_msg4->node2, shared_msg4->cost);
    printf("Message type is: node1 =  %d, node2 = %d  cost = %d\n", shared_msg5->node1, shared_msg5->node2, shared_msg5->cost);
    
    return 0;
}

