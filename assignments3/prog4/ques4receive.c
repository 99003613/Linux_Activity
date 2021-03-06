#include<mqueue.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int ret,m_bytes;
	struct mq_attr attr;
	attr.mq_msgsize=256;
	attr.mq_maxmsg=20;
	mqd_t mqid;
	mqid=mq_open("/mque",O_RDONLY|O_CREAT,0666,&attr);
	if(mqid<0)
	{
		perror("mq_open");
		exit(1);
	}
	char buffer[8192];
	int maxlen=256,prio;
	m_bytes=mq_receive(mqid,buffer,maxlen,&prio);
	if(m_bytes<0)
	{
		perror("mq_recv");
		exit(2);
	}
	buffer[m_bytes]='\0';
	printf("receive msg from sender:%s,nbytes=%d,prio=%d\n",buffer,m_bytes,prio);
	mqd_t mqid2;
	struct mq_attr attr2;
	attr2.mq_msgsize=256;
	attr2.mq_maxmsg=20;
	mqid2=mq_open("/mque2",O_WRONLY|O_CREAT,0666,&attr2);
	for(int counter=0;buffer[counter]!=NULL;counter++)
    {
        if(buffer[counter]>='A' && buffer[counter]<='Z')
            buffer[counter]=buffer[counter]+32;
        else if(buffer[counter]>='a' && buffer[counter]<='z')
            buffer[counter]=buffer[counter]-32;
    }
	ret=mq_send(mqid2,buffer,m_bytes+1,2);
	if(ret<0)
	{
		perror("mq_send");
		exit(2);
	}
	mq_close(mqid);
	mq_close(mqid2);
	return 0;
}
