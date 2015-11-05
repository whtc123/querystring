# querystring
> this is a tiny querystring parser lib for c,just one function,no memery alloc,easy to use.
##sample
```
char  name[32]="";
char  id[32]="";
char  date[32]="";
char *qs = "?name=whtc&id=123&date=2015";
if(query_get(qs,"name",name,32)==NULL){
	//parser error
}

query_get(qs,"id",id,32);
query_get(qs,"date",date,32);
```
