

#include <stdio.h>
/* shm_* stuff, and mmap() */
#include <sys/mman.h>
#include <sys/types.h>
/* exit() etc */
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
/* for random() stuff */
#include <stdlib.h>
#include <string.h>
#include <time.h>


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

int routesLength=0;
int main(int argc, char *argv[]) {

	FILE * fp;
	char * line = NULL;
	size_t len = 0;
	ssize_t read;

	fp = fopen("./route", "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);


    int shmfd;
    int shared_seg_size = (5 * sizeof(struct msg_s));   /* want shared segment capable of storing 1 message */
    

    /* creating the shared memory object    --  shm_open()  */
    shmfd = shm_open(SHMOBJ_PATH, O_CREAT | O_EXCL | O_RDWR, S_IRWXU | S_IRWXG);
    if (shmfd < 0) {
        perror("In shm_open()");
        exit(1);
    }
    fprintf(stderr, "Created shared memory object %s\n", SHMOBJ_PATH);
    
    /* adjusting mapped file size (make room for the whole segment to map)      --  ftruncate() */
    ftruncate(shmfd, shared_seg_size);

    struct msg_s shared_msg[6];      /* the shared segment, and head of the messages list */
    struct msg_s *shared_msg1;     
    struct msg_s *shared_msg2;     
    struct msg_s *shared_msg3;     
    struct msg_s *shared_msg4;     
    struct msg_s *shared_msg5;     
    /* requesting the shared segment    --  mmap() */    
    shared_msg1 = (struct msg_s*)mmap(NULL, shared_seg_size/5, PROT_READ | PROT_WRITE, MAP_SHARED, shmfd, 0);
    shared_msg2 = (struct msg_s*)mmap(NULL, shared_seg_size/5, PROT_READ | PROT_WRITE, MAP_SHARED, shmfd, 0);
    shared_msg3 = (struct msg_s*)mmap(NULL, shared_seg_size/5, PROT_READ | PROT_WRITE, MAP_SHARED, shmfd, 0);
    shared_msg4 = (struct msg_s*)mmap(NULL, shared_seg_size/5, PROT_READ | PROT_WRITE, MAP_SHARED, shmfd, 0);
    shared_msg5 = (struct msg_s*)mmap(NULL, shared_seg_size/5, PROT_READ | PROT_WRITE, MAP_SHARED, shmfd, 0);
    fprintf(stderr, "Shared memory segment allocated correctly (%d bytes).\n", shared_seg_size);

	int count  = 0;
	while ((read = getline(&line, &len, fp)) != -1) {
		if(count==0)
			routesLength = atoi(line);
		else{
					shared_msg[count-1].node1 = line[0]-48;
					shared_msg[count-1].node2 = line[2]-48;
					shared_msg[count-1].cost = line[4]-48;
		}
		count++;
	}


	shared_msg1->node1 = shared_msg[0].node1;
	shared_msg1->node2 = shared_msg[0].node2;
	shared_msg1->cost = shared_msg[0].cost;

	shared_msg2->node1 = shared_msg[1].node1;
	shared_msg2->node2 = shared_msg[1].node2;
	shared_msg2->cost = shared_msg[1].cost;
	
	shared_msg3->node1 = shared_msg[2].node1;
	shared_msg3->node2 = shared_msg[2].node2;
	shared_msg3->cost = shared_msg[2].cost;
	
	shared_msg4->node1 = shared_msg[3].node1;
	shared_msg4->node2 = shared_msg[3].node2;
	shared_msg4->cost = shared_msg[3].cost;
	
	shared_msg5->node1 = shared_msg[4].node1;
	shared_msg5->node2 = shared_msg[4].node2;
	shared_msg5->cost = shared_msg[4].cost;

	printf("For 1:  node1=%d node2=%d  cost=%d\n", shared_msg1->node1, shared_msg1->node2, shared_msg1->cost);
	printf("For 2:  node1=%d node2=%d  cost=%d\n", shared_msg2->node1, shared_msg2->node2, shared_msg2->cost);
	printf("For 3:  node1=%d node2=%d  cost=%d\n", shared_msg3->node1, shared_msg3->node2, shared_msg3->cost);
	printf("For 4:  node1=%d node2=%d  cost=%d\n", shared_msg4->node1, shared_msg4->node2, shared_msg4->cost);
	printf("For 5:  node1=%d node2=%d  cost=%d\n", shared_msg5->node1, shared_msg5->node2, shared_msg5->cost);
	fclose(fp);
    srandom(time(NULL));
    /* producing a message on the shared segment */

   

    return 0;
}


