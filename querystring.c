
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STATE_BEGIN 0
#define STATE_KEY 1
#define STATE_EQ 2
#define STATE_VALUE 3
#define STATE_SEGMENT 4
#define STATE_END 5



char *query_get(char *query_string,char *key,char *val,size_t len){
	int i=0;
	int ik=0;
	int iv=0;
	int state=0;
	char *p = query_string;
	memset(val,0,len);
	state = STATE_KEY;
	for(i=0;i<strlen(query_string);i++){
		switch(state){
			case STATE_BEGIN:
				ik=0;
				if(i==0 || p[i]=='='|| p[i]=='&'){
					state = STATE_KEY;
				}			
				break;
			case STATE_KEY:
				if(p[i]=='='|| p[i]=='&'){
					ik=0;
					continue;
				}
				
				if(p[i] != key[ik]){
					state = STATE_BEGIN;
					continue;
				}
				ik++;
				if(ik==strlen(key)){
					state = STATE_EQ;
					continue;
				}
				break;
			case STATE_EQ:
				if(p[i]=='='){
					state = STATE_VALUE;
				}else{
					state = STATE_BEGIN;
				}
				break;
			case STATE_VALUE:
				if(iv>=len||p[i]=='&'){
					return val;
				}
				val[iv++]=p[i];
				break;
			case STATE_SEGMENT:
				break;
			case STATE_END:
				break;
		}

	}
	
	if(state == STATE_VALUE && iv>0){
		return val;
	}
	return NULL;
}
